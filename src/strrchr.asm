;       char *strrchr(const char *s, int c);
[BITS 64]
global strrchr
section .text

extern strlen

strrchr:
        xor rax, rax
        call strlen wrt ..plt

    .loop:
        cmp byte [rdi + rax], sil
        je .found
        cmp rax, 0x0
        je .end
        sub rax, 1
        jmp .loop

    .found:
        add rdi, rax
        mov rax, rdi
        ret

    .end:
        mov rax, 0x0
        ret
