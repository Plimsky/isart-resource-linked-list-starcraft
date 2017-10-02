#include <stdio.h>
#include "utils/my_put_char.h"

void my_put_char(char c)
{
	fwrite(&c, 1, 1, stdout);
}