# Retr3dRT
RAMPS 1.4 self-test board designed for used in conjunction with Retr3d.

## Images
<img src="https://raw.githubusercontent.com/masterperson40/Retr3dRT/master/images/brd.png" style="width:40%" />
<img src="https://raw.githubusercontent.com/masterperson40/Retr3dRT/master/images/sch.png" style="width:40%" />

#### OSHPark Renderings
<img src="https://raw.githubusercontent.com/masterperson40/Retr3dRT/master/images/osh-top.png" style="width:40%" />
<img src="https://raw.githubusercontent.com/masterperson40/Retr3dRT/master/images/osh-bottom.png" style="width:40%" />
# Make Retr3dRT

## Parts

Check your parts! The easiest way to make an functional Retr3dRT and not know why it's not working to use the wrong parts.

Part            | Picture                                                                                                   | Description                                                | Quantity |                                                                              Distributer
--------------- | --------------------------------------------------------------------------------------------------------- | ---------------------------------------------------------- | :------: | ---------------------------------------------------------------------------------------:
Retr3dRT        | ![Board](https://raw.githubusercontent.com/masterperson40/Retr3dRT/master/images/osh-top.png)             | Circuit board, see "PCB Fabrication" for more info         |    1     |                                                                    OSH Park, SeeedStudio
4610X-101-502LF | ![4601X SERIES](https://raw.githubusercontent.com/masterperson40/Retr3dRT/master/images/4610X SERIES.png) | Nine 5K Ohm Resistor Array, 10SIP                          |    2     |                                           [DigiKey](http://www.digikey.com/short/3p0zrv)
4610X-101-153LF | ![4601X SERIES](https://raw.githubusercontent.com/masterperson40/Retr3dRT/master/images/4610X SERIES.png) | Five 15k Ohm Resistor Array, 10SIP                         |    4     |                                           [DigiKey](http://www.digikey.com/short/3p0zw4)
LED-3MM         | ![3MM LED](https://raw.githubusercontent.com/masterperson40/Retr3dRT/master/images/3mmLED.png)            | 3mm LED (Preferably Green)                                 |    1     |                                    [DigiKey](http://www.digikey.com/short/3p0z0f), Other
R1, R2          | ![4601X SERIES](https://raw.githubusercontent.com/masterperson40/Retr3dRT/master/images/5kohm.png)        | 5k Ohm Resistor                                            |    2     |                                    [DigiKey](http://www.digikey.com/short/3p0z1c), Other
R3              | ![4601X SERIES](https://raw.githubusercontent.com/masterperson40/Retr3dRT/master/images/500ohm.png)       | LED Current Limiting Resistor (520 Ohm is a safe estimate) |    1     |                                    [DigiKey](http://www.digikey.com/short/3p0z1r), Other
3461260P1       | ![4601X SERIES](https://raw.githubusercontent.com/masterperson40/Retr3dRT/master/images/headers.png)      | DIP Long Blue Female Header                                |    7     | [Pending](http://www.seeedstudio.com/wiki/File:1X6P-2.54-8.5%2B2.5-12.3-BLUE-FEMALE.zip)

## Soldering

Now that you have your parts, let's get assembling! If you are just getting started in Electronics, check out [Lady Ada's Guide to Excellent Soldering](https://learn.adafruit.com/adafruit-guide-excellent-soldering/) to brush up on your soldering skills.

Start by soldering R1, R2, and R3 into place. Follow by soldering the LED paying special attention to the polarity annotated on the board. Next, solder the 4610X-101-153LFs and 4610X-101-502LFs by placing them in their holes and securing them with sticky tape. The stick tape prevents them from falling out as you turn the board upside down to solder.

Now, you should have all of the components except for the header soldered. To start the headers, get your diagonal cutters out. Use the diagonal cutters to cut the twelve long headers into eight four long headers, two five long header, one six long header, one eight long header and one complete twelve long header. Now that all of your headers have been prepared, plug them into your RAMPS control board that has its **stepper drivers installed**. Now, carefully lower your Retr3dRT onto the pins and solder it in place.

## Using

Download [Retr3dRT.ino](https://raw.githubusercontent.com/biosafetylvl5/Retr3dRT/master/Retr3dRT.ino) from the [Retr3dRT repository](https://github.com/biosafetylvl5/Retr3dRT) and upload it to your Arduino MEGA with both RAMPS and Retr3dRT installed on top. To view the diagnosis, open your serial terminal and bask in the glow of the information.

## Keeping in touch

To keep in touch to watch for updates and improvements you have a few options:

- [Star the Retr3dRT repository](https://github.com/biosafetylvl5/Retr3dRT/stargazers) to be kept up to date
- Follow the [#Retr3dRT hashtag](https://twitter.com/hashtag/Retr3dRT?f=tweets&src=hash) on twitter to know the moment things happen
- Check out [techfortrade](techfortrade.org) to see what else we're doing

## PCB Fabrication
We're lucky enough to live in the era of cheap and abundant PCB fabrication options. However, this abundance of choices does make choosing a formidable task. However, too make the choosing easier for you, we've narrowed down
the choices to two for you. You're free to choose any fabrication vendor, but we will only be offering (unless asked for others) gerber files (PCB blueprints) for SeeedStudio and OSHPark.

### OSHPark
OSHPark is fantastic. Their boards look great and arrive quickly. However, at 5$ per square inch for three boards, they can be costly for larger runs. Other than that, they have produced good results. This is probably the choice for you if you need
three boards or less.

### SeeedStudio
While SeeedStudio is the budget choice, this isn't a statement about their quality. They feature vanilla PCBs that are very functional, but aren't the most aesthetically pleasing. They deliver quickly, but slower than OSHPark (in the USA) given that they're based in china. This is probably the choice for you if you need more than three boards.

### Final Notes

This board assumes that PCB traces are not faulty. Although this is a possibility, the board was not designed explicitly to test poor traces, it is highly probable that the results from tests meant to test intra-board connections will also flag trace problems.
