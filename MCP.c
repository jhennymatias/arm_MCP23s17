#include <stdio.h>
#include <stdint.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include <fcntl.h>
#include <sys/epoll.h>
#include <sys/types.h>
#include <sys/ioctl.h>
#include <linux/spi/spidev.h>
#include "MCP.h"


static const uint8_t spi_mode = 0;
static const uint8_t spi_bpw = 8; // bits per word
static const uint32_t spi_speed = 10000000; // 10MHz
static const uint16_t spi_delay = 0;
static const char * spidev[2][2] = {
    {"/dev/spidev0.0", "/dev/spidev0.1"},
    {"/dev/spidev1.0", "/dev/spidev1.1"},
};

// epoll related vars
// static int epoll_is_initialised = 0;
static int gpio_pin_fd = -1;
static int epoll_fd = -1;
static struct epoll_event epoll_ctl_events;
static struct epoll_event mcp23s17_epoll_events;


// prototypes
static uint8_t get_spi_control_byte(uint8_t rw_cmd, uint8_t hw_addr);
static int init_epoll(void);


int mcp23s17_init(int bus, int chip_select)
{
    int fd;
    // open
    if ((fd = open(spidev[bus][chip_select], O_RDWR)) < 0) {
        fprintf(stderr,
                "mcp23s17_open: ERROR Could not open SPI device (%s).\n",
                spidev[bus][chip_select]);
        return -1;
    }

    // initialise
    if (ioctl(fd, SPI_IOC_WR_MODE, &spi_mode) < 0) {
        fprintf(stderr, "mcp23s17_open: ERROR Could not set SPI mode.\n");
	close(fd);
        return -1;
    }
    if (ioctl(fd, SPI_IOC_WR_BITS_PER_WORD, &spi_bpw) < 0) {
        fprintf(stderr,
                "mcp23s17_open: ERROR Could not set SPI bits per word.\n");
	close(fd);
        return -1;
    }
    if (ioctl(fd, SPI_IOC_WR_MAX_SPEED_HZ, &spi_speed) < 0) {
        fprintf(stderr, "mcp23s17_open: ERROR Could not set SPI speed.\n");
	close(fd);
        return -1;
    }

    return fd;
}

uint8_t mcp23s17_read_bit(uint8_t bit_num,
                          uint8_t reg,
                          uint8_t hw_addr,
                          int fd)
{
    return (mcp23s17_read_reg(reg, hw_addr, fd) >> bit_num) & 1;
}

void mcp23s17_write_bit(uint8_t data,
                        uint8_t bit_num,
                        uint8_t reg,
                        uint8_t hw_addr,
                        int fd)
{
    uint8_t reg_data = mcp23s17_read_reg(reg, hw_addr, fd);
    if (data) {
        reg_data |= 1 << bit_num; // set
    } else {
        reg_data &= 0xff ^ (1 << bit_num); // clear
    }
    return mcp23s17_write_reg(reg_data, reg, hw_addr, fd);
}




static int init_epoll(void)
{
    // calculate the GPIO pin's path
    char gpio_pin_filename[33];
    snprintf(gpio_pin_filename,
             sizeof(gpio_pin_filename),
             "/sys/class/gpio/gpio%d/value",
             GPIO_INTERRUPT_PIN);

    // if we haven't already, create the epoll and the GPIO pin fd's
    if(epoll_fd <= 0) {
        epoll_fd = epoll_create(1);
        if (epoll_fd <= 0) {
            fprintf(stderr,
                    "mcp23s17_wait_for_interrupt: There was a error during "
                    "the epoll_create.\n"
                    "Error is %s (errno=%d)\n",
                    strerror(errno),
                    errno);
            return -1;
        }
        gpio_pin_fd = open(gpio_pin_filename, O_RDONLY | O_NONBLOCK);
    }

    if(gpio_pin_fd <= 0) {
        // we haven't successfully opened the GPIO pin fd
        fprintf(stderr,
                "mcp23s17_wait_for_interrupt: Can't open fd <%s> <%d>.\n"
                "Error is %s (errno=%d)\n",
                gpio_pin_filename,
                gpio_pin_fd,
                strerror(errno),
                errno);
        return -1;
    } else {
        epoll_ctl_events.events = EPOLLIN | EPOLLET;
        epoll_ctl_events.data.fd = gpio_pin_fd;

        if(epoll_ctl(epoll_fd, EPOLL_CTL_ADD, gpio_pin_fd, &epoll_ctl_events) != 0) {
            fprintf(stderr,
                    "mcp23s17_wait_for_interrupt: There was a error "
                    "during the epoll_ctl EPOLL_CTL_ADD.\n");
            fprintf(stderr,
                    "Error is %s (errno=%d)\n",
                    strerror(errno),
                    errno);
        }
        // Ignore GPIO Initial Event
        epoll_wait(epoll_fd, &mcp23s17_epoll_events, 1, 10);
        return 0;
    }
}


/**
 * Returns an SPI control byte.
 *
 * The MCP23S17 is a slave SPI device. The slave address contains four
 * fixed bits (0b0100) and three user-defined hardware address bits
 * (if enabled via IOCON.HAEN; pins A2, A1 and A0) with the
 * read/write command bit filling out the rest of the control byte::
 *
 *     +--------------------+
 *     |0|1|0|0|A2|A1|A0|R/W|
 *     +--------------------+
 *     |fixed  |hw_addr |R/W|
 *     +--------------------+
 *     |7|6|5|4|3 |2 |1 | 0 |
 *     +--------------------+
 *
 */
static uint8_t get_spi_control_byte(uint8_t rw_cmd, uint8_t hw_addr)
{
    hw_addr = (hw_addr << 1) & 0xE;
    rw_cmd &= 1; // just 1 bit long
    return 0x40 | hw_addr | rw_cmd;
}