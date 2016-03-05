while [ 1 ] ; do sudo avrdude -p atmega32u4 -c avr109 -U flash:w:atreus_astar.hex -P /dev/ttyACM0 ; done
