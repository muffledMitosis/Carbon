#include "Serial.hpp"

#include <stdio.h>
#include <string.h>

#ifdef PLATFORM_LINUX

#include <fcntl.h> // Contains file controls like O_RDWR
#include <errno.h> // Error integer and strerror() function
#include <termios.h> // Contains POSIX terminal control definitions
#include <unistd.h> // write(), read(), close()

#elif PLATFORM_WINDOWS
#elif PLATFORM_OSX
#endif

#include <iostream>

namespace Carbon {

Serial::Serial(const SerialInfo& info)
{
  std::cout<<info.Baud<<":"<<info.port<<std::endl;

#ifdef PLATFORM_LINUX

  this->port_nix = open(info.port.c_str(), O_RDWR);

  if(port_nix < 0)
  {
    printf("Error %i from open: %s\n", errno, strerror(errno));
  }

  termios tty;

  if(tcgetattr(port_nix, &tty) != 0)
  {
    printf("Error %i from tcgetattr: %s\n", errno, strerror(errno));
  }

  tty.c_cflag &= ~PARENB; // Clear parity bit, disabling parity
  tty.c_cflag &= ~CSTOPB; // Clear stop field, only one stop bit used in communication
  tty.c_cflag |= CS8; // 8 bits per byte
  tty.c_cflag &= ~CRTSCTS; // Disable RTS/CTS hardware flow control
  tty.c_cflag |= CREAD | CLOCAL; // Turn on READ & ignore ctrl lines
  tty.c_lflag |= ICANON; // Enable Canonical Mode
  tty.c_lflag &= ~ECHO; // Disable echo
  tty.c_lflag &= ~ECHOE; // Disable erasure
  tty.c_lflag &= ~ECHONL; // Disable new-line echo
  tty.c_lflag &= ~ISIG; // Disable interpretation of INTR, QUIT and SUSP
  tty.c_iflag &= ~(IXON | IXOFF | IXANY); // Turn off s/w flow ctrl
  tty.c_iflag &= ~(IGNBRK|BRKINT|PARMRK|ISTRIP|INLCR|IGNCR|ICRNL); // Disable any special handling of received bytes
  tty.c_oflag &= ~OPOST; // Prevent special interpretation of output bytes (e.g. newline chars)
  tty.c_oflag &= ~ONLCR; // Prevent conversion of newline to carriage return/line feed
  // tty.c_oflag &= ~OXTABS; // Prevent conversion of tabs to spaces (NOT PRESENT IN LINUX)
  // tty.c_oflag &= ~ONOEOT; // Prevent removal of C-d chars (0x004) in output (NOT PRESENT IN LINUX)
  tty.c_cc[VTIME] = 0;    // Wait for up to 1s (10 deciseconds), returning as soon as any data is received.
  tty.c_cc[VMIN] = 0;

  cfsetispeed(&tty, info.Baud);
  cfsetospeed(&tty, info.Baud);

  if (tcsetattr(port_nix, TCSANOW, &tty) != 0) {
    printf("Error %i from tcsetattr: %s\n", errno, strerror(errno));
  }

#elif PLATFORM_WINDOWS
#elif PLATFORM_OSX
#endif

}

void Serial::readBytes()
{
  char read_buff[256];
  memset(&read_buff, '\0', sizeof(read_buff));
  int n = read(port_nix, &read_buff, sizeof(read_buff));
  printf("%s", read_buff);
}

Serial::~Serial()
{
}

}
