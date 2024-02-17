;       void *memcpy(void *dest, const void *src, size_t n);
[BITS 64]
global memcpy
section .text

    memcpy:
        xor rax, rax
        mov rcx, 0x0

    .loop:
        cmp rcx, rdx
        je .end
        mov al, byte [rsi + rcx]
        mov byte [rdi + rcx], al
        inc rcx
        jmp .loop

    .end:
        mov rax, rdi
        ret