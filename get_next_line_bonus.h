

#ifndef GET_NEXT_LINE_BONUS_H
#define GET_NEXT_LINE_BONUS_H

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>


#ifndef BUFFER_SIZE
#define BUFFER_SIZE 100
#endif
#ifndef FD_MAX
#define FD_MAX 1024
#endif


char *get_next_line(int fd);




#endif