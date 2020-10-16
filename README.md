# arduino-cw-key

## Description

Automatic CW keying via an Arduino-compatible device attached to a relay (attached to a transceiver).

## Current status

![Screenshot of first transmission](media/first_transmission.png)

- 10/1/2020 – Code written to completion and ready for distance testing.  First transmission (pictured above) was done using a dummy load on the S-Pixie QRP transceiver.  (Was picked up within a couple of feet using a USB RTL-SDR dongle, accompanying media can be found here: [media](media/))

## How to use (MacOS)

Utilize the _miniterm_ utility which comes bundled with [pyserial](https://pypi.org/project/pyserial/) to interact with the Arduino keyer (connected via USB serial).  Syntax:

```
miniterm.py /dev/tty.usbserial-XXXXXX 115200
```
> Replace XXXXXX with whatever the device comes up on your system as.

## License

[GPT-3](LICENSE.md)