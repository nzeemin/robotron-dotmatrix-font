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
    { "currency sign", "&#164;" },
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
    { "grave accent", "&#140;" },
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
    { "slashed zero", "0&#x0338;" },
    { nullptr, "&lt;" },
    { nullptr, "=" },
    { nullptr, "&gt;" },
    { nullptr, "?" },
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
    { nullptr, "!" },  // 195
    { nullptr, "&#34;" },  // 196
    { nullptr, "#" },  // 197
    { nullptr, "&#164;" },  // 198
    { nullptr, "&#37;" },  // 199
    { nullptr, "&#38;" },  // 200
    { nullptr, "&#39;" },  // 201
    { nullptr, "&#40;" },  // 202
    { nullptr, "&#41;" },  // 203
    { nullptr, "&#42;" },  // 204
};

int main(int argc, char* argv[])
{
    std::cerr << "RobotronFontGen utility  by Nikita Zimin  " << __DATE__ << " " << __TIME__ << std::endl;

    std::ofstream m_output("robotronfont.svg");

    float scale = 10.0f;
    float fontHorizAdvX = 72 * scale;  // The default horizontal advance after rendering a glyph in horizontal orientation
    float fontUnitsPerEm = 9 * 12 * scale;
    float fontCapHeight = 7 * 12 * scale;  // Height of uppercase glyphs
    float fontXHeight = 5 * 12 * scale;  // Height of lowercase glyphs
    float fontAscent = 7 * 12 * scale;  // Maximum unaccented height
    float fontDescent = 2 * 12 * scale;  // Maximum unaccented depth

    float xstep = (float(720 / 10) / 11.0f) * scale;
    float ystep = 12.0f * scale;
    float r = 6.0f * scale;

    m_output << "<svg xmlns=\"http://www.w3.org/2000/svg\" version=\"1.1\">" << std::endl;
    m_output << "<defs>" << std::endl;

    m_output << "<font id=\"RobotronFont\" horiz-adv-x=\"" << fontHorizAdvX << "\">" << std::endl;

    m_output << "<font-face font-family=\"Robotron Dot Matrix\" font-weight=\"normal\" font-style=\"normal\" "
        << "units-per-em=\"" << fontUnitsPerEm << "\" cap-height=\"" << fontCapHeight << "\" "
        << "x-height=\"" << fontXHeight << "\" ascent=\"" << fontAscent << "\" descent=\"" << fontDescent << "\""
        << ">" << std::endl;
    m_output << "<font-face-src><font-face-name name=\"Robotron Dot Matrix PICA\"/></font-face-src>" << std::endl;
    m_output << "</font-face>" << std::endl;

    m_output << "<missing-glyph><path d=\"M0,0h200v200h-200z\"/></missing-glyph>" << std::endl;

    for (int symbol = 0; symbol < sizeof(GlyphDescs) / sizeof(GlyphDescStruct); symbol++)
    {
        const GlyphDescStruct* pGlyph = GlyphDescs + symbol;
        const unsigned short* pchardata = RobotronFont + symbol * 9;
        if (pGlyph->name == nullptr)
            continue; // skip this symbol

        float y = 7 * 12 * scale;

        m_output << "<glyph glyph-name=\"" << pGlyph->name << "\" unicode=\"" << pGlyph->unicode << "\" ";
        m_output << "d=\"";
        for (int line = 0; line < 9; line++)
        {
            unsigned short data = pchardata[line];
            for (int col = 0; col < 9; col++)
            {
                float x = 120.0f + col * xstep;
                unsigned short bit = (data >> col) & 1;
                if (!bit) continue;

                m_output << "M" << x - r << "," << y << " ";
                m_output << "a " << r << "," << r << " 0 0 0 " << r << "," << r << " ";
                m_output << "a " << r << "," << r << " 0 1 0 " << -r << "," << -r << " ";
                m_output << "z ";
            }
            y -= ystep;
        }
        m_output << "\"/>" << std::endl;
    }

    m_output << "</font>" << std::endl;

    m_output << "</defs>" << std::endl;

    //m_output << "<text x=\"100\" y=\"100\" style=\"font-family: 'Robotron Dot Matrix'; font-weight: normal; font-style: normal\">" << std::endl;
    //m_output << "0123456789" << std::endl;
    //m_output << "ABCDEFGHIJKLMNOPQRSTUVWXYZ" << std::endl;
    //m_output << "abcdefghijklmnopqrstuvwxyz" << std::endl;
    //m_output << "</text>" << std::endl;

    m_output << "</svg>" << std::endl;

    m_output.close();

    return 0;
}


//////////////////////////////////////////////////////////////////////
