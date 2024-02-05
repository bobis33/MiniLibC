;       char *strrchr(const char *s, int c);
[BITS 64]
global strrchr
section .text

extern strlen

strrchr:
        xor rax, rax
        call strlen wrt ..plt

    .loop:
        cmp rax, 0x0
        je .end
        cmp byte [rdi + rax], sil
        je .found
        sub rax, 1
        jmp .loop

    .found:
        add rdi, rax
        mov rax, rdi
        ret

    .end:
        mov rax, 0x0
        ret
