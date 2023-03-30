// SPDX-License-Identifier: BSD-3-Clause

#include <sys/stat.h>
#include <errno.h>
#include <internal/syscall.h>

int fstat(int fd, struct stat *st) {
    int data = syscall(__NR_fstat, fd, st);
    if (data < 0) {
        errno = -data;
        return -1;
    }
    return data;
}
