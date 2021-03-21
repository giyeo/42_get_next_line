#include "get_next_line_bonus.h"
#include <stdio.h>


int main()
{
	int x[3];
	char **str;
	char **stra;
	
	x[0] = open("1.txt", O_RDONLY);
	get_next_line(x[0], str);
	x[1] = open("2.txt", O_RDONLY);
	get_next_line(x[1], stra);
	printf("%s", str);
	printf("%s", stra);
	return 0;
}