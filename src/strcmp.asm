;       int strcmp(const char *s1, const char *s2);
[BITS 64]
global strcmp
section .text

    strcmp:
        xor rax, rax
        mov rcx, 0x0
        mov r8, 0x0

    .loop:
        cmp byte [rdi + rcx], 0x0
        je .end
        cmp byte [rsi + rcx], 0x0
        je .end
        mov r8b, byte [rdi + rcx]
        cmp byte [rsi + rcx], r8b
        jne .end
        inc rcx
        jmp .loop

    .end:
        mov rax, [rdi + rcx]
        sub rax, [rsi + rcx]
        ret