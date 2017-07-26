# Working Information

In order to log the data received on the SD card, I moved the card to a 2nd 
Arduino, using a the serial port to log the data. This appears to work.  
Current setup on Receive side:  
1st Arduino used for the LoRa Shield  
2nd Arduino used for SD shield  
  
On the Transmit side only one Arduino is used with a GPS unit attached to pin 7 and 8.  
  
See pictures of setup.  
Sketches used:  
LoRaReceiver  
LoRaSender_with_GPS  
SerialEvent_logged_to_SD_card  
  

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
