#include <stdio.h>
#include <string.h>
#include <internal/io.h>
#include <errno.h>

int puts(const char *str) {
    errno = 1;
    int data = write(1, str, strlen(str));
    if (data)
        errno = -1;
    data = write(1, "\n", 1);
    if (data)
        errno = -1;
    return errno;
}
