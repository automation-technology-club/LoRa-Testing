# Sketches for testing LoRa 

Information on the Linksprite LoRa boards can be found here:
https://github.com/YaoQ/pcduino-lora-AP
http://linksprite.com/wiki/index.php5?title=DIY_low-cost_LoRa_gateway_based_on_pcDuino#2._Program_Arduino_Uno

I was unable to get Linksprites sketch to compile (??).

## Installation

libraries required:
arduino-LoRa https://github.com/sandeepmistry/arduino-LoRa
TinyGPSPlus https://github.com/mikalhart/TinyGPSPlus
SD card library
DS1307 library

## General Information

It is possiable (unlikely) that I did get a package from about 8 miles away. I've tried to duplicated the results and couldn't - so it is most likely a error in the data.

Arduino directory - contains some test sketches for the Arduino.
Data - contains some of the test collected data (not much)
Processing directory - contains the processing code.
videos - contains some videos of my testing and maybe what LoRa sounds like (?)
pictures - contains some pictures of my setup.

Testing Videos & Pictures - https://photos.app.goo.gl/4dYW1h3T82mpc8192

## Usage

At least 2 LoRa shields are needed.  One is setup as a receiver, the other as
a sender.
 I used LoRaReceiver_with_sd_logger_hmmmm and LoRaSender_with_gps for most of my early testing.  However I never got any data to log to the SD card (hence the name *_hmmmm)
The processing sketch "serial_logging" was used to monitor the serial port and create a file. (This worked mostly)

## Contributing

1. Fork it!
2. Create your feature branch: `git checkout -b my-new-feature`
3. Commit your changes: `git commit -am 'Add some feature'`
4. Push to the branch: `git push origin my-new-feature`
5. Submit a pull request

## Support Me

If you find this or any of my projects useful or enjoyable please support me.
Anything I do get goes to buy more parts and make more/better projects.
https://www.patreon.com/kd8bxp
https://ko-fi.com/lfmiller

## Other Projects

https://www.youtube.com/channel/UCP6Vh4hfyJF288MTaRAF36w
https://kd8bxp.blogspot.com/

## Automation Technology Club

WHAT ARE WE ABOUT?
- Provide sharing opportunities for everyone.
Microprocessor Technology
Op Amp Technology
Basic Electricity
Electronics
- Share technical information. 
- Improve the productivity and value of our technical resources (you).
- All Volunteer. All participants volunteer their time.
- Cost: Free

MEETINGS:
- We currently meet Thursdays from 5:00 to 7:00 PM at the West Chester Library, West Chester Ohio

Meetup - https://www.meetup.com/Automation-Technology-Club/
Google Community - https://plus.google.com/communities/101659244920289753698
YouTube Meeting Channel - https://www.youtube.com/channel/UCNtBoACTGP85GEUWz-XgCnw

## Credits

Copyright (c) 2017 LeRoy Miller

## License

This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses>
