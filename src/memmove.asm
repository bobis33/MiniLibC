;       void *memmove(void *dest, const void *src, size_t n);
[BITS 64]
global memmove
section .text
extern memcpy

    memmove:
        xor rax, rax
        mov rcx, rdi
        sub rcx, rsi
        cmp rcx, rdx
        jge .memcpy
        mov r9, rdx
        jmp .loop

    .memcpy:
        call memcpy wrt ..plt
        ret

    .loop:
        mov r8b, byte [rsi - 1 + r9]
        mov byte [rdi - 1 + r9], r8b
        dec r9
        cmp r9, 0x0
        je .end
        jmp .loop

    .end:
        mov rax, rdi
        ret