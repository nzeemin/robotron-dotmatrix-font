# robotron-dotmatrix-font - Robotron dot matrix printer font

The font characters was restored from the real Robotron 9-pin printer ROMs.
Most of the symbols are from Robotron СМ6329.01М printer ROM (ASCII and Cyrillic).
Some symbols are from Robotron K6313 printer ROM (Latin1 symbols).

Currently the font contains 209 glyphs:
 - ASCII
 - Cyrillic letters to cover Russian alphabet (but capital Ё has no dots)
 - some Latin1 symbols

I used a simple C++ program to decode symbols, and another program (see RobotronFontGen folder) to produce an SVG font. Online converter used to convert the SVG font to WOFF.
So the result files are:
 - robotronfontelit.svg, robotronfontelit.woff - ELITE font face
 - robotronfontpica.svg, robotronfontpica.woff - PICA font face
 - robotronfontsper.svg, robotronfontsper.woff - Sperrschrift font face

The license for both the font and the source code is [PUBLIC DOMAIN](https://creativecommons.org/publicdomain/mark/1.0/).

![](https://github.com/nzeemin/robotron-dotmatrix-font/blob/master/test-woff.png)

### See Also
* [ESCParser](https://github.com/nzeemin/ukncbtl-utils/wiki/ESCParser) — ESC/P parser/interpreter with PostScript/SVG/PDF output.
