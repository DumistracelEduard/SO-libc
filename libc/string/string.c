// SPDX-License-Identifier: BSD-3-Clause

#include <string.h>
#include <stdlib.h>

char *strcpy(char *destination, const char *source) {
    char *d;

    for (d = destination; *source != '\0'; source++, d++)
        *d = *source;
    *d = *source;

    return destination;
}

char *strncpy(char *destination, const char *source, size_t len) {
    char *d;
    size_t lenCond = 0;

    for (d = destination; *source != '\0' && lenCond < len; source++, d++) {
        *d = *source;
        lenCond++;
    }
    *d = *source;

    return destination;
}

char *strcat(char *destination, const char *source) {
    char *d;

    for (d = destination + strlen(destination); *source != '\0'; source++, d++) {
        *d = *source;
    }
    *d = *source;

    return destination;
}

char *strncat(char *destination, const char *source, size_t len) {
    char *d;
    size_t lenCond = 0;

    for (d = destination + strlen(destination); *source != '\0' && lenCond < len; source++, d++) {
        *d = *source;
        lenCond++;
    }
    *d = '\0';
    return destination;
}

int strcmp(const char *str1, const char *str2) {
    if (strlen(str1) < strlen(str2))
        return -1;
    if (strlen(str1) > strlen(str2))
        return 1;
    while (*str1 && *str2) {
        if (*str1 != *str2)
            break;
        str1++;
        str2++;
    }
    return *(const unsigned char *) str1 - *(const unsigned char *) str2;
}

int strncmp(const char *str1, const char *str2, size_t len) {
    while (*str1 && *str2 && len) {
        if (*str1 != *str2)
            break;
        str1++;
        str2++;
        len--;
    }
    if (len == 0)
        return 0;
    return *(const unsigned char *) str1 - *(const unsigned char *) str2;
}

size_t strlen(const char *str) {
    size_t i = 0;

    for (; *str != '\0'; str++, i++);

    return i;
}

char *strchr(const char *str, int c) {
    while (*str != c && *str != '\0')
        str++;
    if (*str == c)
        return (char *) str;
    return NULL;
}

char *strrchr(const char *str, int c) {
    char *data = NULL;
    while (*str != '\0') {
        if (*str == c)
            data = (char *) str;
        str++;
    }
    return data;
}

char *strstr(const char *haystack, const char *needle) {
    while (*haystack != '\0') {
        if ((*haystack == *needle) && strncmp(needle, haystack, strlen(needle)) == 0) {
            return (char *) haystack;
        }
        haystack++;
    }
    return NULL;
}

char *strrstr(const char *haystack, const char *needle) {
    char *data = NULL;
    while (*haystack != '\0') {
        if ((*haystack == *needle) && strncmp(needle, haystack, strlen(needle)) == 0) {
            data = (char *) haystack;
        }
        haystack++;
    }
    if (data != NULL)
        return data;
    return NULL;
}

void *memcpy(void *destination, const void *source, size_t num) {
    char *dest = (char *) destination;
    char *src = (char *) source;
    while (*src != '\0' && num) {
        *dest = *src;
        dest++;
        src++;
        num--;
    }
    return (void *) destination;
}

void *memmove(void *destination, const void *source, size_t num) {
    char *str1 = destination;
    const char *str2 = source;
    char *buffer = (char *) malloc(num * sizeof(char));

    for (size_t i = 0; i < num; ++i)
        *(buffer + i) = *(str2 + i);
    for (size_t i = 0; i < num; ++i)
        *(str1 + i) = *(buffer + i);
    return destination;
}

int memcmp(const void *ptr1, const void *ptr2, size_t num) {
    const unsigned char *str1 = ptr1;
    const unsigned char *str2 = ptr2;

    if (str1 == str2)
        return 0;
    while (num) {
        if (*str1 != *str2) {
            return *(const unsigned char *) str1 - *(const unsigned char *) str2;
        }
        str1++;
        str2++;
        num--;
    }
    return 0;
}

void *memset(void *source, int value, size_t num) {
    unsigned char *str = source;
    while (num) {
        *str = (unsigned char) value;
        num--;
        str++;
    }
    return source;
}
