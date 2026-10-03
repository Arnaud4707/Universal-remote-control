#include "include/functions.h"

#define LED 2

int main(void)
{
	PIN_FUNC_SELECT(PERIPHS_IO_MUX_GPIO2_U, FUNC_GPIO2);

	gpio_output_enable(LED);

	gpio_clear(LED);

	for (;;)
		;

	return 0;
}