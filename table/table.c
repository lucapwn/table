// MIT License

// Copyright (c) 2022 Lucas Araújo

// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:

// The above copyright notice and this permission notice shall be included in all
// copies or substantial portions of the Software.

// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
// SOFTWARE.

#include <stdio.h>
#include <string.h>
#include <stddef.h>

#include "table.h"

#if defined(__linux__) || defined(__linux)   // GNU/Linux
    #define WHITE   "\e[1;37;40m"
    #define RED     "\e[1;31;40m"
    #define GREEN   "\e[1;32;40m"
    #define BLUE    "\e[1;34;40m"
    #define YELLOW  "\e[1;33;40m"
    #define MAGENTA "\e[1;35;40m"
    #define CYAN    "\e[1;36;40m"
    #define RESET   "\e[0m"
#endif // defined

void print_spaces(size_t amount) {
    for (size_t i = 0; i < amount; i++) {
        printf(" ");
    }
}

void print_hyphens(size_t amount) {
    for (size_t i = 0; i < amount; i++) {
        printf("-");
    }
}

#if defined(__WIN32__) || defined(__NT__)    // Windows
void color(HANDLE hConsole, char *color) {
    if (!strcmp(color, "white")) {
        SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
    }
    else if (!strcmp(color, "red")) {
        SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_INTENSITY);
    }
    else if (!strcmp(color, "green")) {
        SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
    }
    else if (!strcmp(color, "blue")) {
        SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_INTENSITY);
    }
    else if (!strcmp(color, "yellow")) {
        SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
    }
    else if (!strcmp(color, "magenta")) {
        SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
    }
    else if (!strcmp(color, "cyan")) {
        SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
    }
}

void reset_color(HANDLE hConsole, WORD saved_attributes) {
    SetConsoleTextAttribute(hConsole, saved_attributes);
}

#elif defined(__linux__) || defined(__linux)   // GNU/Linux
void color(char *color) {
    if (!strcmp(color, "white")) {
        printf(WHITE);
    }
    else if (!strcmp(color, "red")) {
        printf(RED);
    }
    else if (!strcmp(color, "green")) {
        printf(GREEN);
    }
    else if (!strcmp(color, "blue")) {
        printf(BLUE);
    }
    else if (!strcmp(color, "yellow")) {
        printf(YELLOW);
    }
    else if (!strcmp(color, "magenta")) {
        printf(MAGENTA);
    }
    else if (!strcmp(color, "cyan")) {
        printf(CYAN);
    }
}

void reset_color(void) {
    printf(RESET);
}
#endif // defined

void table(size_t spacing, char *key_color, char *value_color, size_t key_attributes, char key[][MAXIMUM_STRING_LENGTH], size_t value_attributes, char value[][key_attributes][MAXIMUM_STRING_LENGTH])
{
    int overall_width = 0;
    int largest_column[key_attributes];

    /* Initializes variables and functions to save console information */

#if defined(__WIN32__) || defined(__NT__)    // Windows
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO consoleInformation;
    WORD saved_attributes;
    GetConsoleScreenBufferInfo(hConsole, &consoleInformation);
    saved_attributes = consoleInformation.wAttributes;
#endif // defined

    for (size_t i = 0; i < key_attributes; i++) {
        largest_column[i] = 0;
        largest_column[i] += strlen(key[i]);
    }

    for (size_t i = 0; i < value_attributes; i++) {
        for (size_t j = 0; j < key_attributes; j++) {
            if (strlen(value[i][j]) > largest_column[j]) {
                largest_column[j] = strlen(value[i][j]);
            }
        }
    }

    for (size_t i = 0; i < key_attributes; i++) {
        overall_width += largest_column[i];
    }

    overall_width += (3 * key_attributes) - 1;

    print_spaces(spacing);

    printf("+");

    print_hyphens(overall_width);

    printf("+\n");

    print_spaces(spacing);

    for (size_t i = 0; i < key_attributes; i++) {
        printf("|");

        #if defined(__WIN32__) || defined(__NT__)      // Windows
            color(hConsole, key_color);
        #elif defined(__linux__) || defined(__linux)   // GNU/Linux
            color(key_color);
        #endif // defined

        printf(" %*s ", largest_column[i], key[i]);

        #if defined(__WIN32__) || defined(__NT__)      // Windows
            reset_color(hConsole, saved_attributes);
        #elif defined(__linux__) || defined(__linux)   // GNU/Linux
            reset_color();
        #endif // defined
    }

    printf("|\n");

    print_spaces(spacing);

    printf("+");

    print_hyphens(overall_width);

    printf("+\n");

    print_spaces(spacing);

    for (size_t i = 0; i < value_attributes; i++) {
        for (size_t j = 0; j < key_attributes; j++) {
            printf("|");

            #if defined(__WIN32__) || defined(__NT__)      // Windows
                color(hConsole, value_color);
            #elif defined(__linux__) || defined(__linux)   // GNU/Linux
                color(value_color);
            #endif // defined

            printf(" %*s ", largest_column[j], value[i][j]);

            #if defined(__WIN32__) || defined(__NT__)      // Windows
                reset_color(hConsole, saved_attributes);
            #elif defined(__linux__) || defined(__linux)   // GNU/Linux
                reset_color();
            #endif // defined
        } 
        printf("|\n");
        print_spaces(spacing);
    }

    printf("+");

    print_hyphens(overall_width);

    printf("+\n");
}
