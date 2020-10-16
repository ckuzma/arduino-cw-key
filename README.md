# arduino-cw-key

## Description

Automatic CW keying via an Arduino-compatible device attached to a relay (attached to a transceiver).

## Work log

![Screenshot of first transmission](media/first_transmission.png)
> _Above_: The first successful morse code transmission.

- **10/1/2020** – Code written to completion and ready for distance testing.  First transmission (pictured above) was done using a dummy load on the S-Pixie QRP transceiver.  (Was picked up within a couple of feet using a USB RTL-SDR dongle, accompanying media can be found here: [media](media/))
- **10/15/2020** – Modified / ported code to be used on NodeMCU but was unable to power the relay board from the _VIN_ pin, rendering this work useless except to serve as a (silent) morse code trainer device with the onboard LED.  Probably won't bother to work through this issue any further.

## How to use (MacOS)

Utilize the _miniterm_ utility which comes bundled with [pyserial](https://pypi.org/project/pyserial/) to interact with the Arduino keyer (connected via USB serial).  Syntax:

```
miniterm.py /dev/tty.usbserial-XXXXXX 9600
```
> Replace XXXXXX with whatever the device comes up on your system as.

## License

[GPT-3](LICENSE.md)
