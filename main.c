#include "get_next_line.c"
#include <stdio.h>
#include <stdlib.h>

int		main()
{
	int		fd1;
	int		fd2;
	FILE	*fael1;
	FILE	*fael2;
	char	**kek;

	fael1 = fopen("suka1.txt", "r");
	fael2 = fopen("suka2.txt", "r");
	fd1 = fileno(fael1);
	fd2 = fileno(fael2);
	get_next_line(fd1, line);
	return (0);
}
