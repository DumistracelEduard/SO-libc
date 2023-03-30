#include <internal/syscall.h>
#include <stdlib.h>
#include <errno.h>
#include <time.h>

int nanosleep(const struct timespec *t1, struct timespec *t2) {
    errno = 0;
    int res = syscall(__NR_nanosleep, t1, t2);
    if (res < 0)
        errno = -res;
    return errno;
}
