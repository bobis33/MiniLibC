;       int strncmp(const char *s1, const char *s2, size_t n);
[BITS 64]
global strncmp
section .text

    strncmp:
        xor rax, rax
        mov rcx, 0x0
        mov r8, 0x0
        mov r9, 0x0
        sub rdx, 1

    .loop:
        cmp rcx, rdx
        je .end
        cmp byte [rdi + rcx], 0x0
        je .end
        cmp byte [rsi + rcx], 0x0
        je .end
        mov r8b, byte [rsi + rcx]
        cmp byte [rdi + rcx], r8b
        jne .end
        inc rcx
        jmp .loop

    .end:
        mov r8b, byte [rdi + rcx]
        mov r9b, byte [rsi + rcx]
        sub r8, r9
        mov rax, r8
        ret
