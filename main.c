#include <stdio.h>

int	main(void)
{
	char c = 'A';
	printf("String: %5.2s\n", "halloechen");
	printf("String: %20.5s\n", "halloechen");
	printf("pointer: %0p\n", &c);
	printf("pointer: %10.2p\n", &c);
	printf("pointer: %5.22p\n", &c);
	printf("pointer: %10.22p\n", &c);
	printf("pointer: %10.32p\n", &c);
	printf("unsigned int: %d\n", 15);
	printf("unsigned int: %020.5d\n", 15);
	printf("unsigned int: %03.5d\n", 15);
	printf("unsigned int: %0.1d\n", 15);
	printf("unsigned int: %#d\n", 15);
	printf("unsigned octal: %o\n", 15);
	printf("unsigned octal: %#o\n", 15);
	printf("unsigned hex: %x\n", 15);
	printf("unsigned hex: %#x\n", 15);
	printf("Int precision: %-010.2u\n", 1111);
	printf("Int precision: %10.6u\n", 1111);
	printf("Int precision: %11.6u\n", 1111);
	printf("Int precision: %10.2i\n", 1111);
	printf("Int precision: %10.6i\n", 1111);
	printf("Percent: [%10.6%]\n");
	printf("Char: [%3.6c]\n", 'A');
	printf("Char: [%03.6c]\n", 'A');
	printf("Char: [%0.2c]\n", 'A');
	printf("Char: [%0.0c]\n", 'A');
	return (0);
}
