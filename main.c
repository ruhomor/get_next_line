#include "get_next_line.h"

int		main(int argc, char **argv)
{
	char	*line;
	int		fd;
	int		ans;

	if (argc == 2)
		fd = open(argv[1], O_RDONLY);
	else
		fd = 0;
	line = NULL;
	ans = 1;
	while ((ans = get_next_line(fd, &line)))
	{
		printf("%d: %s\n", ans, line);
		ft_strdel(&line);
	}
	close(fd);
}
