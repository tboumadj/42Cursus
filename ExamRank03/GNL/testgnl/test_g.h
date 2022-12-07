#ifndef GNL_H
# define GNL_H
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>

# define BUFFER_SIZE 42

char *get_next_line(int fd);

#endif