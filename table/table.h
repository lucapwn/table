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

#ifndef TABLE_H_INCLUDED
#define TABLE_H_INCLUDED

#define MAXIMUM_STRING_LENGTH 50

#if defined(__WIN32__) || defined(__NT__)      // Windows
    #include <windows.h>

    void color(HANDLE hConsole, char *color);
    void reset_color(HANDLE hConsole, WORD saved_attributes);

#elif defined(__linux__) || defined(__linux)   // GNU/Linux
    void color(char *color);
    void reset_color(void);

#endif

void table(size_t spacing, char *key_color, char *value_color, size_t key_attributes, char key[][MAXIMUM_STRING_LENGTH], size_t value_attributes, char value[][key_attributes][MAXIMUM_STRING_LENGTH]);

#include "table.c"

#endif // TABLE_H_INCLUDED