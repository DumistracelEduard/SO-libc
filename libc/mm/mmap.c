// SPDX-License-Identifier: BSD-3-Clause

#include <sys/mman.h>
#include <errno.h>
#include <internal/syscall.h>

void *mmap(void *addr, size_t length, int prot, int flags, int fd, off_t offset) {
    long data = syscall(__NR_mmap, addr, length, prot, flags, fd, offset);
    if (data < 0) {
        errno = -data;
        return MAP_FAILED;
    }
    return (void *) data;
}

void *mremap(void *old_address, size_t old_size, size_t new_size, int flags) {
    long data = syscall(__NR_mremap, old_address, old_size, new_size, flags, 0);
    if (data < 0) {
        errno = -data;
        return MAP_FAILED;
    }
    return (void *) data;
}

int munmap(void *addr, size_t length) {
    long data = syscall(__NR_munmap, addr, length);
    if (data < 0) {
        errno = -data;
        return -1;
    }
    return data;
}
