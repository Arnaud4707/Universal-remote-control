#include "include/gpio.h"

int main(void)
{
	gpio_mode();
	gpio_output_enable(2);

	gpio_clear(2);

	for (;;)
		;

	return 0;
}