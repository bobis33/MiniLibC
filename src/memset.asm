;       void *memset(void *s, int c, size_t n);
[BITS 64]
global memset
section .text

    memset:
        xor rax, rax
        mov rcx, 0x0

    .loop:
        cmp rcx, rdx
        je .end
        mov byte [rdi + rcx], sil
        inc rcx
        jmp .loop

    .end:
        mov rax, rdi
        ret
