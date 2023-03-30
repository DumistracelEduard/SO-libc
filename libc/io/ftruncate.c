// SPDX-License-Identifier: BSD-3-Clause

#include <unistd.h>
#include <internal/syscall.h>
#include <errno.h>

int ftruncate(int fd, off_t length) {
    int data = syscall(__NR_ftruncate, fd, length);
    if (data < 0) {
        errno = -data;
        return -1;
    }
    return data;
}
