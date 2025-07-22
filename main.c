#include "ft_printf.h"
#include <stdio.h>

int	main(void)
{
	int	ret1;
	int	ret2;

	ret1 = ft_printf("Test char: %c\n", 'A');
	ret2 = printf("Test char: %c\n", 'A');
	ft_printf("ft_printf return: %d, printf return: %d\n\n", ret1, ret2);

	ret1 = ft_printf("");
	ret2 = printf("");
	ft_printf("ft_printf return: %d, printf return: %d\n\n", ret1, ret2);

	ret1 = ft_printf("Test string: %s\n", "Hello, World!");
	ret2 = printf("Test string: %s\n", "Hello, World!");
	ft_printf("ft_printf return: %d, printf return: %d\n\n", ret1, ret2);

	ret1 = ft_printf("Test pointer: %p\n", (void *)0x12345678);
	ret2 = printf("Test pointer: %p\n", (void *)0x12345678);
	ft_printf("ft_printf return: %d, printf return: %d\n\n", ret1, ret2);

	ret1 = ft_printf("Test decimal: %d\n", -42);
	ret2 = printf("Test decimal: %d\n", -42);
	ft_printf("ft_printf return: %d, printf return: %d\n\n", ret1, ret2);

	ret1 = ft_printf("Test integer: %i\n", 2147483647);
	ret2 = printf("Test integer: %i\n", 2147483647);
	ft_printf("ft_printf return: %d, printf return: %d\n\n", ret1, ret2);

	ret1 = ft_printf("Test unsigned: %u\n", 4294967295U);
	ret2 = printf("Test unsigned: %u\n", 4294967295U);
	ft_printf("ft_printf return: %d, printf return: %d\n\n", ret1, ret2);

	ret1 = ft_printf("Test hex lower: %x\n", 255);
	ret2 = printf("Test hex lower: %x\n", 255);
	ft_printf("ft_printf return: %d, printf return: %d\n\n", ret1, ret2);

	ret1 = ft_printf("Test hex upper: %X\n", 255);
	ret2 = printf("Test hex upper: %X\n", 255);
	ft_printf("ft_printf return: %d, printf return: %d\n\n", ret1, ret2);

	ret1 = ft_printf("Test percent: %%\n");
	ret2 = printf("Test percent: %%\n");
	ft_printf("ft_printf return: %d, printf return: %d\n\n", ret1, ret2);

	ret1 = ft_printf("Test NULL string: %s\n", (char *)NULL);
	ret2 = printf("Test NULL string: %s\n", (char *)NULL);
	ft_printf("ft_printf return: %d, printf return: %d\n\n", ret1, ret2);

	ret1 = ft_printf("Test NULL pointer: %p\n", NULL);
	ret2 = printf("Test NULL pointer: %p\n", NULL);
	ft_printf("ft_printf return: %d, printf return: %d\n\n", ret1, ret2);

	return (0);
}
