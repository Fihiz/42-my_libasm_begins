; ----------------------------------------------------------------------------------------
; Writes the strdup function in assembly. Runs on 64-bit.
; Parameters/Registers : rdi for (first)source parameter.
; Return value : rax register.
; ----------------------------------------------------------------------------------------

section .text
extern	ft_strlen
global ft_strdup

ft_strdup:
        call ft_strlen                     ; Rax takes strlen value of rdi
        inc rax                            ; Adding +1 for '\0'
        mov rax, rdi
        ;need to deal with logic and malloc, let's pursue
        ret