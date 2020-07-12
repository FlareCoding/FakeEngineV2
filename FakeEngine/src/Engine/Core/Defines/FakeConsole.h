#pragma once

// See: https://stackoverflow.com/questions/4053837/colorizing-text-in-the-console-with-c

/* Console Colors */
#define FAKE_CONSOLE_COLOR_BLACK            "\033[30m"
#define FAKE_CONSOLE_COLOR_RED              "\033[31m"
#define FAKE_CONSOLE_COLOR_GREEN            "\033[32m"
#define FAKE_CONSOLE_COLOR_YELLOW           "\033[33m"
#define FAKE_CONSOLE_COLOR_BLUE             "\033[34m"
#define FAKE_CONSOLE_COLOR_MAGENTA          "\033[35m"
#define FAKE_CONSOLE_COLOR_CYAN             "\033[36m"
#define FAKE_CONSOLE_COLOR_WHITE            "\033[37m"

/* Console Fonts */
#define FAKE_CONSOLE_FONT_BRIGHT            "\033[1m"
#define FAKE_CONSOLE_FONT_DARK              "\033[2m"    /* abgedunkelte Schrift */
#define FAKE_CONSOLE_FONT_ITALIC            "\033[3m" 
#define FAKE_CONSOLE_FONT_UNDERLINE         "\033[4m"    /* Unterstrichen */
#define FAKE_CONSOLE_FONT_BLINK             "\033[5m"    /* Blinken ein */
#define FAKE_CONSOLE_FONT_QBLINK            "\033[6m"    /* schnelles Blinken ein */
#define FAKE_CONSOLE_FONT_REVERSE           "\033[7m"    /* reverse video */
#define FAKE_CONSOLE_FONT_NOECHO            "\033[8m"
#define FAKE_CONSOLE_FONT_NORMAL            "\033[0m"    /* Alles wieder normal */

/* Console Cursor */
#define FAKE_CONSOLE_CURSOR_CLSCR           "\033[2J"
#define FAKE_CONSOLE_CURSOR_CLREOL          "\033[K"     /* Loescht bis Zeilenende */
#define FAKE_CONSOLE_CURSOR_SAVECURPOS      "\033[s"     /*speicher actuelle Position */

#define FAKE_CONSOLE_CURSOR_SETSAVEDPOS     "\033[u"     /* geht zur gespeicherten Position */

#define FAKE_CONSOLE_CURSOR_SCURUP          "\033[A"     /* Eine Zeile hoch */
#define FAKE_CONSOLE_CURSOR_SCURDOWN        "\033[B"     /* eine Zeile runter */

#define FAKE_CONSOLE_CURSOR_SCURRIGHT       "\033[C"     /* eine Zeile nach rechts */
#define FAKE_CONSOLE_CURSOR_SCURLEFT        "\033[D"     /* eine Spalte nach links */

#define FAKE_CONSOLE_CURSOR_CURUP(x)        "\033[xA"   /* Gehe x Zeilen nach oben */
#define FAKE_CONSOLE_CURSOR_CURDOWN(x)      "\033[xB"   /*gehe x Zeile nach unten */
#define FAKE_CONSOLE_CURSOR_CURRIGHT(x)     "\033[xC"   /* gehe x Spalten nach rechts */
#define FAKE_CONSOLE_CURSOR_CURLEFT(x)      "\033[xD"   /* gehe x Spalten nach links */
#define FAKE_CONSOLE_CURSOR_GOTO(x, y)      "\033[x;yH" /*  Gehe zur Position x,y */

#define FAKE_CONSOLE_CURSOR_CURGOHOME(x)    "\033[xf"   /* Geh nach Zeile x und setze Curser auf Anfang */
#define FAKE_CONSOLE_CURSOR_CURDOWNHOME(x)  "\033[xE"   /*Gehe x Zeilen nach  unten und setzte Curser an den Anfang */
#define FAKE_CONSOLE_CURSOR_CURUPHOME(x)    "\033[xF"   /* Gehe x Zeilen nach oben und setze Curser an den Anfang */