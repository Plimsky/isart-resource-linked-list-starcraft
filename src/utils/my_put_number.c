#include "utils/my_put_char.h"
#include "utils/my_put_number.h"

void my_put_number(int num)
{
	int div = 1;

	if (num < 0)
	{
		my_put_char('-');
		num = -num;
	}

	while (num / div > 9 || num / div < -9)
		div = div * 10;

	while (div >= 1)
	{
		if (num > 0)
			my_put_char((char) ('0' + (num / div) % 10));
		else
			my_put_char((char) ('0' - (num / div) % 10));
		div = div / 10;
	}
}