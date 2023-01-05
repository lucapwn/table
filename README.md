# Table

[Table](https://github.com/lucapwn/table) is a library developed in the C language for creating dynamic tables.

![Badge](https://img.shields.io/static/v1?label=license&message=MIT&color=1E90FF)
![Badge](https://img.shields.io/static/v1?label=build&message=passing&color=00d110)

## Content

- [About](#about)
    - [Attributes](#attributes)
- [Support](#support)
- [Example](#example)
- [Running](#running)
- [Screenshot](#screenshot)
- [Author](#author)
- [License](#license)

## About

The [Table](https://github.com/lucapwn/table) library allows you to easily create C language tables in CLI (Command Line Interface) format.

With this library, you can set the color of the table text and the left alignment of the table.

The ```table``` function receives seven mandatory parameters, which are:

~~~C
void table(size_t spacing, char *key_color, char *value_color, size_t key_attributes, char key[][MAXIMUM_STRING_LENGTH], size_t value_attributes, char value[][key_attributes][MAXIMUM_STRING_LENGTH]);
~~~

### Attributes

Below is an explanation of each parameter of the ```table``` function.

1. **spacing**: Number of spaces to the left of the table.
2. **key_color**: Assign a color to the attributes of the table. If you leave it empty, it will be the default color. List of available colors: ```white```, ```blue```, ```red```, ```green```, ```yellow```, ```magenta``` and ```cyan```.
3. **value_color**: Assign a color to the values in the table. If you leave it empty, it will be the default color. List of available colors: ```white```, ```blue```, ```red```, ```green```, ```yellow```, ```magenta``` and ```cyan```.
4. **key_attributes**: Defines the number of attributes of the table (columns).
5. **key**: It receives a two-dimensional vector containing the names of the attributes of the table.
6. **values_attributes**: Sets the number of rows in the table (values).
7. **value**: It receives a three-dimensional vector containing the values of the table.

## Support

This library has support for the Windows and GNU/Linux operating systems.

I have not been able to test it on macOS yet, but I believe it will work as well.

## Example

Below is an example of the use of the library.

~~~C
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
~~~

## Running

Compiling the library [example](https://github.com/lucapwn/table/blob/main/example.c) (GNU/Linux):

~~~console
foo@bar:~$ gcc -o example example.c
~~~

Running the created executable:

~~~console
foo@bar:~$ ./example
~~~

## Screenshot

The image below illustrates the example table created with the library.

![](https://lh3.googleusercontent.com/pw/ACtC-3fqQbNZ8qiALv-h11N24LeXL2lZF___BKTIGG1rzR9Vl0ZmX_mY5VWZsffpDqBs675zIYG2w4rUBEWxIivov0Sf_zi-lB2WJaFu0vazY41indOqr_lnLBoYNfKTQeNAYQWAO6yQ8K8M3ERCiZ-NLjwzOw=w678-h132-no?authuser=0)

## Author

Developed by [Lucas Araújo](https://github.com/lucapwn).

## License

This software is [MIT](https://choosealicense.com/licenses/mit/) licensed.
