# sendcode

sendcode is a utility for sending commands to remote switched power outlets via RF transmitter module (such as the 433 Mhz FS1000A).  Common parameters are set through command line options, default parameters work on a Raspberry Pi with Etekcity wireless electrical outlets.

## Instllation

From your Raspberry Pi, install wiringpi then clone and build this project:

1. Install [wiringpi](https://projects.drogon.net/raspberry-pi/wiringpi/download-and-install/) library.
2. ```git clone --recursive https://github.com/idlegravity/sendcode.git``` (recursive ensures that the rc-switch submodule is downloaded)
3. ```cd sendcode```
4. ```make```

## Usage

```sendcode [-p <pin>] [-r <protocol>] [-l <pulse length>] code ...```

## References

* Inspired by <https://github.com/ninjablocks/433Utils>.
* Use <https://github.com/sui77/rc-switch/tree/master/examples/ReceiveDemo_Simple> to view codes used by your switches.
* See <https://hackaday.io/project/4298-autoflower/log/14215-reverse-reverse> for a desription of the protocol (to set a custom code on a switch that's not available on the remote).
* See <https://projects.drogon.net/raspberry-pi/wiringpi/pins/> for the pinout used by wiringPi (It's different than the RPi header labels and the GPIO pin numbers!).
