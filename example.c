#include <stdio.h>
#include <stdlib.h>

#include "table/table.h"

#define LINES                   3
#define COLUMNS                 6
#define MAXIMUM_STRING_LENGTH  50

int main(int argc, char *argv[]) {
    char keys[COLUMNS][MAXIMUM_STRING_LENGTH] = { "ID", "Name", "Birth Date", "Telephone", "Email", "Password" };

    char values[LINES][COLUMNS][MAXIMUM_STRING_LENGTH] = {
        { "1", "Lucas", "01/01/2000", "(11) 99999-9999", "lucas@gmail.com", "qwerty" },
        { "100", "Vanessa", "02/02/2000", "(11) 99999-9999", "vanessa@gmail.com", "qwerty" },
        { "1234", "Fernando", "03/03/2000", "(11) 99999-9999", "fernando@gmail.com", "qwerty" }
    };

    table(1, "blue", "", COLUMNS, keys, LINES, values);

    return EXIT_SUCCESS;
}