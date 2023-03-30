// SPDX-License-Identifier: BSD-3-Clause

#include <unistd.h>
#include <internal/syscall.h>
#include <stdarg.h>
#include <errno.h>

int close(int fd) {
    int data = syscall(__NR_close, fd);
    if (data < 0) {
        errno = -data;
    }
    return errno;
}
