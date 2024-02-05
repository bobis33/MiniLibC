;       char *strchr(const char *s, int c);
[BITS 64]
global strchr
section .text

    strchr:
        xor rax, rax

    .loop:
        cmp byte [rdi], 0x0
        je .end
        cmp byte [rdi], sil
        je .found
        inc rdi
        jmp .loop

    .found:
        mov rax, rdi
        ret

    .end:
        mov rax, 0x0
        ret
