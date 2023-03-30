#include <internal/syscall.h>
#include <stdlib.h>
#include <errno.h>
#include <time.h>
#include <internal/nanosleep.h>

int sleep(unsigned int seconds) {
    struct timespec second;
    second.tv_sec = seconds;
    second.tv_nsec = 0;

    struct timespec t2;
    t2.tv_sec = 0;
    t2.tv_nsec = 0;

    return nanosleep(&second, &t2);
}
