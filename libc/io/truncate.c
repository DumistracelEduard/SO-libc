// SPDX-License-Identifier: BSD-3-Clause

#include <unistd.h>
#include <internal/syscall.h>
#include <errno.h>

int truncate(const char *path, off_t length) {
    errno = 0;
    int data = syscall(76, path, length);
    if (data < 0) {
        errno = -data;
        return -1;
    }
    return data;
}
