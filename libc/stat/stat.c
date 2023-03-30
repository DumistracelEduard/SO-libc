// SPDX-License-Identifier: BSD-3-Clause

#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
#include <internal/syscall.h>

int stat(const char *restrict path, struct stat *restrict buf) {
    int data = syscall(__NR_stat, path, buf);
    if (data < 0) {
        errno = -data;
        return -1;
    }
    return data;
}
