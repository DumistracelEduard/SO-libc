// SPDX-License-Identifier: BSD-3-Clause

#include <unistd.h>
#include <internal/syscall.h>
#include <errno.h>

off_t lseek(int fd, off_t offset, int whence) {
    long data;
    data = syscall(__NR_lseek, fd, offset, whence);
    if (data < 0) {
        errno = -data;
        return -1;
    }
    return data;
}
