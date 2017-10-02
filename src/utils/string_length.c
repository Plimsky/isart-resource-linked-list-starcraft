#include <stdlib.h>
#include "utils/string_length.h"

int string_length(const char *str)
{
	int i = 0;

	if (str == NULL)
		return i;

	while (str[i] != '\0')
		i++;

	return i;
}