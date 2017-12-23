/**
 * Simple application for sending control signals to remote switched outlets with
 * a 433 Mhz transmitter module (e.g. FS1000A) on an arbitrary Raspberry Pi pin.
 * 
 * Hacked together from https://github.com/ninjablocks/433Utils.
 * 
 * Use https://github.com/sui77/rc-switch/tree/master/examples/ReceiveDemo_Simple 
 * to view codes used by your switches.
 * 
 * See https://hackaday.io/project/4298-autoflower/log/14215-reverse-reverse for
 * a desription of the protocol (to set a custom code on a switch that's not 
 * available on the remote).
 * 
 * See: https://projects.drogon.net/raspberry-pi/wiringpi/pins/ for the pinout as
 * used by wiringPi (It's different than the RPi header labels and the GPIO pin
 * numbers!).
 **/

#include "rc-switch/RCSwitch.h"
#include <stdlib.h>
#include <stdio.h>
#include <getopt.h>

void usage()
{
  printf("Usage: sendcode [-p <pin>] [-r <protocol>] [-l <pulse length>] code ...\n");
  printf("\tpin:\t\twiringPi pin to send on (Default 15).\n");
  printf("\t\t\tSee https://projects.drogon.net/raspberry-pi/wiringpi/pins/\n");
  printf("\tprotocol:\trc-switch procotol (default 1).\n");
  printf("\tpulse length:\tPulse length in microseconds (default 185).\n");
  printf("\tcode:\t\tCodes, in decimal, to transmit.\n");
}

int main(int argc, char * * argv) {
  int pin = 15;
  int protocol = 1;
  int pulseLength = 185;
  int bitLength = 24;

  int option;
  extern char * optarg;
  extern int optind, optopt;
  while ((option = getopt(argc, argv, "hp:r:l:")) != -1) {
    switch (option) {
    case '?':
      usage();
      exit(1);
    case 'h':
      usage();
      exit(0);
    case 'p':
      pin = atoi(optarg);
      break;
    case 'r':
      protocol = atoi(optarg);
      break;
    case 'l':
      pulseLength = atoi(optarg);
      break;
    }
  }
  if (argc <= optind) {
    usage();
    exit(1);
  }

  if (wiringPiSetup() == -1) {
    printf("wiringPi is not configured.\n");
    printf("See http://wiringpi.com/download-and-install/ for more information.\n");
    exit(1);
  }

  RCSwitch mySwitch = RCSwitch();
  mySwitch.setProtocol(protocol);
  mySwitch.setPulseLength(pulseLength);
  mySwitch.enableTransmit(pin);
  for (; optind < argc; optind++) {
    int code = atoi(argv[optind]);
    printf("Sending code: %i\n", code);
    mySwitch.send(code, bitLength);
  }

  exit(0);
}
