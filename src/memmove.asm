;       void *memmove(void *dest, const void *src, size_t n);
[BITS 64]
global memmove
section .text

    memmove:
        rep movsb
        ret