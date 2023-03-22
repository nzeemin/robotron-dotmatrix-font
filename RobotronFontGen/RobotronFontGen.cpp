#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <fstream>


//////////////////////////////////////////////////////////////////////
// Globals

extern unsigned short RobotronFont[];



//////////////////////////////////////////////////////////////////////

struct GlyphDescStruct
{
    const char * name;
    const char * unicode;
}
static GlyphDescs[] =
{
    { "space", " " },
    { "exclamation", "&#33;" },
    { "dquote", "&#34;" },
    { "hash", "&#35;" },
    { "$", "$" },
    { "percent", "&#37;" },
    { "ampersand", "&#38;" },
    { "quote", "&#39;" },
    { "(", "&#40;" },
    { ")", "&#41;" },
    { "*", "&#42;" },
    { "+", "&#43;" },
    { ",", "&#44;" },
    { "-", "&#45;" },
    { ".", "&#46;" },
    { "/", "&#47;" },
    { "0", "0" },
    { "1", "1" },
    { "2", "2" },
    { "3", "3" },
    { "4", "4" },
    { "5", "5" },
    { "6", "6" },
    { "7", "7" },
    { "8", "8" },
    { "9", "9" },
    { ":", ":" },
    { ";", ";" },
    { "lt", "&lt;" },
    { "eq", "=" },
    { "gt", "&gt;" },
    { "?", "?" },
    { "@", "@" },
    { "A", "A" },
    { "B", "B" },
    { "C", "C" },
    { "D", "D" },
    { "E", "E" },
    { "F", "F" },
    { "G", "G" },
    { "H", "H" },
    { "I", "I" },
    { "J", "J" },
    { "K", "K" },
    { "L", "L" },
    { "M", "M" },
    { "N", "N" },
    { "O", "O" },
    { "P", "P" },
    { "Q", "Q" },
    { "R", "R" },
    { "S", "S" },
    { "T", "T" },
    { "U", "U" },
    { "V", "V" },
    { "W", "W" },
    { "X", "X" },
    { "Y", "Y" },
    { "Z", "Z" },
    { "[", "[" },
    { "\\", "\\" },
    { "]", "]" },
    { "^", "^" },
    { "_", "_" },
    { "grave accent", "&#96;" },
    { "a", "a" },
    { "b", "b" },
    { "c", "c" },
    { "d", "d" },
    { "e", "e" },
    { "f", "f" },
    { "g", "g" },
    { "h", "h" },
    { "i", "i" },
    { "j", "j" },
    { "k", "k" },
    { "l", "l" },
    { "m", "m" },
    { "n", "n" },
    { "o", "o" },
    { "p", "p" },
    { "q", "q" },
    { "r", "r" },
    { "s", "s" },
    { "t", "t" },
    { "u", "u" },
    { "v", "v" },
    { "w", "w" },
    { "x", "x" },
    { "y", "y" },
    { "z", "z" },
    { "{", "{" },
    { "|", "|" },
    { "}", "}" },
    { "~", "~" },
    { nullptr, "" },  // 127
    { nullptr, "" },  // 128
    { "ie cyrillic", "&#x0450;" },
    { "yo cyrillic", "&#x0451;" },
    { "Yo cyrillic", "&#x0401;" },  //TODO: dots
    { "Hard sign cyrillic", "&#x042A;" },
    { "yu cyrillic", "&#x044E;" },
    { "a cyrillic", "&#x0430;" },
    { "be cyrillic", "&#x0431;" },
    { "tse cyrillic", "&#x0446;" },
    { "de cyrillic", "&#x0434;" },
    { "ye cyrillic", "&#x0435;" },
    { "ef cyrillic", "&#x0444;" },
    { "ge cyrillic", "&#x0433;" },
    { "kha cyrillic", "&#x0445;" },
    { "i cyrillic", "&#x0438;" },
    { "short i cyrillic", "&#x0439;" },
    { "ka cyrillic", "&#x043A;" },
    { "el cyrillic", "&#x043B;" },
    { "em cyrillic", "&#x043C;" },
    { "en cyrillic", "&#x043D;" },
    { "o cyrillic", "&#x043E;" },
    { "pe cyrillic", "&#x043F;" },
    { "ya cyrillic", "&#x044F;" },
    { "er cyrillic", "&#x0440;" },
    { "es cyrillic", "&#x0441;" },
    { "te cyrillic", "&#x0442;" },
    { "u cyrillic", "&#x0443;" },
    { "zhe cyrillic", "&#x0436;" },
    { "ve cyrillic", "&#x0432;" },
    { "soft sign cyrillic", "&#x044C;" },
    { "yery cyrillic", "&#x044B;" },
    { "ze cyrillic", "&#x0437;" },
    { "sha cyrillic", "&#x0448;" },
    { "e cyrillic", "&#x044D;" },
    { "shcha cyrillic", "&#x0449;" },
    { "che cyrillic", "&#x0447;" },
    { "hard sign cyrillic", "&#x044A;" },
    { "Yu cyrillic", "&#x042E;" },
    { "A cyrillic", "&#x0410;" },
    { "Be cyrillic", "&#x0411;" },
    { "Tse cyrillic", "&#x0426;" },
    { "De cyrillic", "&#x0414;" },
    { "Ye cyrillic", "&#x0415;" },
    { "Ef cyrillic", "&#x0424;" },
    { "Ge cyrillic", "&#x0413;" },
    { "Kha cyrillic", "&#x0425;" },
    { "I cyrillic", "&#x0418;" },
    { "Short i cyrillic", "&#x0419;" },
    { "Ka cyrillic", "&#x041A;" },
    { "El cyrillic", "&#x041B;" },
    { "Em cyrillic", "&#x041C;" },
    { "En cyrillic", "&#x041D;" },
    { "O cyrillic", "&#x041E;" },
    { "Pe cyrillic", "&#x041F;" },
    { "Ya cyrillic", "&#x042F;" },
    { "Er cyrillic", "&#x0420;" },
    { "Es cyrillic", "&#x0421;" },
    { "Te cyrillic", "&#x0422;" },
    { "U cyrillic", "&#x0423;" },
    { "Zhe cyrillic", "&#x0416;" },
    { "Ve cyrillic", "&#x0412;" },
    { "Soft sign cyrillic", "&#x042C;" },
    { "Yery cyrillic", "&#x042B;" },
    { "Ze cyrillic", "&#x0417;" },
    { "Sha cyrillic", "&#x0428;" },
    { "E cyrillic", "&#x042D;" },
    { "Shcha cyrillic", "&#x0429;" },
    { "Che cyrillic", "&#x0427;" },
    { "inverted !", "&#161;" },
    { "cent sign", "&#162;" },
    { "pound sign", "&#163;" },
    { "currency sign", "&#164;" },
    { "yen sign", "&#165;" },
    { "broken bar", "&#166;" },
    { "section", "&#167;" },
    { "umlaut", "&#168;" },
    { "copyright", "&#169;" },
    { "super a", "&#170;" },
    { "left guillemet", "&#171;" },
    { "is not", "&#172;" },
    { "hyphen", "&#173;" },
    { "regmark", "&#174;" },
    { "macron", "&#175;" },
    { "degree", "&#176;" },
    { "plus-minus", "&#177;" },
    { "super 2", "&#178;" },
    { "super 3", "&#179;" },
    { "acute accent", "&#180;" },
    { "micro", "&#181;" },
    { "paragraph", "&#182;" },
    { "interpunkt", "&#183;" },
    { "cedilla", "&#184;" },
    { "super 1", "&#185;" },
    { "super 0", "&#186;" },
    { "right guillemet", "&#187;" },
    { "quarter", "&#188;" },
    { "half", "&#189;" },
    { "three quarter", "&#190;" },
    { "inverted ?", "&#191;" },
    { "A-grave", "&#192;" },
    { "A-acute", "&#193;" },
    { "A-circ", "&#194;" },
    { "A-tilde", "&#195;" },
    { "A-umlaut", "&#196;" },
    { "A-ring", "&#197;" },
    { "AElig", "&#198;" },
    { "C-cedilla", "&#199;" },
    { "E-grave", "&#200;" },
    { "E-acute", "&#201;" },
    { "E-circ", "&#202;" },
    { "E-umlaut", "&#203;" },
    { "I-grave", "&#204;" },
    { "I-acute", "&#205;" },
    { "I-circ", "&#206;" },
    { "I-umlaut", "&#207;" },
    { "Eth", "&#208;" },
    { "N-tilde", "&#209;" },
    { "O-grave", "&#210;" },
    { "O-acute", "&#211;" },
    { "O-circ", "&#212;" },
    { "O-tilde", "&#213;" },
    { "O-umlaut", "&#214;" },
    { "multiplication", "&#215;" },
    { "O with stroke", "&#216;" },
    { "U-grave", "&#217;" },
    { "U-acute", "&#218;" },
    { "U-circ", "&#219;" },
    { "U-umlaut", "&#220;" },
    { "Y-acute", "&#221;" },
    { "Thorn", "&#222;" },
    { "eszett", "&#223;" },
    { "a-grave", "&#224;" },
    { "a-acute", "&#225;" },
    { "a-circ", "&#226;" },
    { "a-tilde", "&#227;" },
    { "a-umlaut", "&#228;" },
    { "a-ring", "&#229;" },
    { "aelig", "&#230;" },
    { "c-cedilla", "&#231;" },
    { "e-grave", "&#232;" },
    { "e-acute", "&#233;" },
    { "e-circ", "&#234;" },
    { "e-umlaut", "&#235;" },
    { "i-grave", "&#236;" },
    { "i-acute", "&#237;" },
    { "i-circ", "&#238;" },
    { "i-umlaut", "&#239;" },
    { "eth", "&#240;" },
    { "n-tilde", "&#241;" },
    { "o-grave", "&#242;" },
    { "o-acute", "&#243;" },
    { "o-circ", "&#244;" },
    { "o-tilde", "&#245;" },
    { "o-umlaut", "&#246;" },
    { "obelus", "&#247;" },
    { "o with stroke", "&#248;" },
    { "u-grave", "&#249;" },
    { "u-acute", "&#250;" },
    { "u-circ", "&#251;" },
    { "u-umlaut", "&#252;" },
    { "y-acute", "&#253;" },
    { "thorn", "&#254;" },
    { "y-umlaut", "&#255;" },
    { "Sum", "&#x2211;" },
    { "pi", "&#960;" },
    { "n-dash", "&#x2013;" },
    { "m-dash", "&#x2014;" },
    { "lowbar", "&#x2015;" },
    { "dvert", "&#x2016;" },
    { "dlowbar", "&#x2017;" },
    { "open sq", "&#x2018;" },
    { "close sq", "&#x2019;" },
    { "close lsq", "&#x201A;" },
    { "open hsq", "&#x201B;" },
    { "open dq", "&#x201C;" },
    { "close dq", "&#x201D;" },
    { "close ldq", "&#x201E;" },
    { "close hdq", "&#x201F;" },
    { "dagger", "&#x2020;" },
    { "ddagger", "&#x2021;" },
    { "bullet", "&#x2022;" },
    { "triangle", "&#x2023;" },
    { "1 point", "&#x2024;" },
    { "2 point", "&#x2025;" },
    { "ellipsis", "&#x2026;" },
    { "lsaquo", "&#x2039;" },
    { "rsaquo", "&#x203A;" },
    { "Euro", "&#x20AC;" },
    { "OE", "&#x0152;" },
    { "oe", "&#x0153;" },
    { "S-caron", "&#x0160;" },
    { "s-caron", "&#x0161;" },
    { "Y-umlaut", "&#x0178;" },
    { "Z-caron", "&#x017D;" },
    { "z-caron", "&#x017E;" },
    { "florins", "&#x0192;" },
    { "trademark", "&#x2122;" },
};

void DrawStrike(std::ofstream & output, float x, float y, float r)
{
    output << "M" << x - r << "," << y << " ";
    output << "a" << r << "," << r << " 0 0 0 " << r << "," << r << " ";
    output << "a" << r << "," << r << " 0 1 0 " << -r << "," << -r << " ";
    output << "z ";
}

void PrepareSvgFont(const char * filename, const char * fontfacesuffix, int shiftx, bool fontsp)
{
    std::cerr << "Preparing font " << filename << std::endl;
    std::ofstream output(filename);

    const float scale = 10.0f;
    float fontHorizAdvX = shiftx * scale;  // The default horizontal advance after rendering a glyph in horizontal orientation
    float fontUnitsPerEm = 9 * 12 * scale;
    float fontCapHeight = 7 * 12 * scale;  // Height of uppercase glyphs
    float fontXHeight = 5 * 12 * scale;  // Height of lowercase glyphs
    float fontAscent = 7 * 12 * scale;  // Maximum unaccented height
    float fontDescent = 2 * 12 * scale;  // Maximum unaccented depth

    float xstep = (float(shiftx) / 11.0f) * scale;
    float ystep = 12.0f * scale;
    float r = 6.0f * scale;  // dot radius

    output << "<svg xmlns=\"http://www.w3.org/2000/svg\" version=\"1.1\">" << std::endl;
    output << "<metadata>" << std::endl
        << "Created using RobotronFontGen utility by Nikita Zimin" << std::endl
        << "https://github.com/nzeemin/robotron-dotmatrix-font" << std::endl
        << "</metadata>" << std::endl;
    output << "<defs>" << std::endl;

    output << "<font id=\"RobotronFont\" horiz-adv-x=\"" << fontHorizAdvX << "\">" << std::endl;

    output << "<font-face font-family=\"Robotron Dot Matrix\" font-weight=\"normal\" font-style=\"normal\" " << std::endl
        << "    units-per-em=\"" << fontUnitsPerEm << "\" cap-height=\"" << fontCapHeight << "\" "
        << "x-height=\"" << fontXHeight << "\" ascent=\"" << fontAscent << "\" descent=\"" << fontDescent << "\" "
        << "widths=\"" << fontUnitsPerEm << "\">" << std::endl;
    output << "<font-face-src><font-face-name name=\"Robotron Dot Matrix "<< fontfacesuffix << "\"/></font-face-src>" << std::endl;
    output << "</font-face>" << std::endl;

    output << "<missing-glyph><path d=\"M0,0h200v200h-200z\"/></missing-glyph>" << std::endl;

    output << "<glyph glyph-name=\"space\" unicode=\" \" horiz-adv-x=\"" << fontHorizAdvX << "\"/>" << std::endl;

    int glyphcount = 1;
    for (int symbol = 1; symbol < sizeof(GlyphDescs) / sizeof(GlyphDescStruct); symbol++)
    {
        const GlyphDescStruct* pGlyph = GlyphDescs + symbol;
        const unsigned short* pchardata = RobotronFont + symbol * 9;
        if (pGlyph->name == nullptr)
            continue; // skip this symbol

        float y = 7 * 12 * scale;

        output << "<glyph glyph-name=\"" << pGlyph->name << "\" unicode=\"" << pGlyph->unicode << "\" ";
        output << "d=\"";
        for (int line = 0; line < 9; line++)
        {
            unsigned short data = pchardata[line];
            for (int col = 0; col < 9; col++)
            {
                float x = 120.0f + col * xstep;
                unsigned short bit = (data >> col) & 1;
                if (!bit) continue;

                DrawStrike(output, x, y, r);
                if (fontsp)
                    DrawStrike(output, x + xstep, y, r);
            }
            y -= ystep;
        }
        output << "\"/>" << std::endl;
        glyphcount++;
    }

    output << "</font>" << std::endl;

    output << "</defs>" << std::endl;

    output << "</svg>" << std::endl;

    output.close();

    std::cerr << "Total glyph count: " << glyphcount << std::endl;
}

int main(int argc, char* argv[])
{
    std::cerr << "RobotronFontGen utility  by Nikita Zimin  " << __DATE__ << " " << __TIME__ << std::endl;

    PrepareSvgFont("..\\robotronfontpica.svg", "PICA", 720 / 10, false);

    PrepareSvgFont("..\\robotronfontelit.svg", "ELITE", 720 / 12, false);

    PrepareSvgFont("..\\robotronfontsper.svg", "SPER", 720 / 5, true);
}


//////////////////////////////////////////////////////////////////////
