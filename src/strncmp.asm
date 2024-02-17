;       int strncmp(const char *s1, const char *s2, size_t n);
[BITS 64]
global strncmp
section .text

strncmp:
    xor rax, rax
    mov rcx, rdx
    repne scasb
    mov rax, rcx
    sub rax, rcx
    ret