#include "get_next_line_bonus.h"
#include <stdio.h>


int main()
{
	int x;
	char *str;
	
	x = open("1.txt", O_RDONLY);
	int value = get_next_line(x, &str);
	printf("%s",value);

	x = open("2.txt", O_RDONLY);
	value = get_next_line(x, &str);
	printf("%s",value);
	return 0;
}