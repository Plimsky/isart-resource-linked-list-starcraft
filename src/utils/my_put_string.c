#include <stdlib.h>
#include "utils/my_put_char.h"
#include "utils/my_put_string.h"

void my_put_string(const char *str)
{
	if (str == NULL)
		return;

	while (*str != '\0')
	{
		my_put_char(*str);
		str++;
	}
}