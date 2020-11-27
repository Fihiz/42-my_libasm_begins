; ----------------------------------------------------------------------------------------
; Writes the strcmp function in assembly. Runs on 64-bit.
; Parameters/Registers : rdi for first string parameter, rsi for second string parameter.
; Return value : rax register.
; Warning : strcmp return value may differ using gcc or clang ! 
; (clang required to use errno without segfault while testing syscalls for write and read)
; Here ft_strcmp returns 0 or the char difference (not 0, 1 or -1)
; ----------------------------------------------------------------------------------------

section .text
global ft_strcmp

ft_strcmp:
         xor    rax, rax                ; 8-bit part of rcx is al
         ;xor    rcx, rcx               ; 8-bit part of rcx is cl
         ;xor    rdx, rdx               ; 8-bit part of rdx is dl
         xor    r8, r8                  ; 64-bit linux parameters order: rdi, rsi, rdx, rcx, r8, and r9.

strcmp_system:
        mov     cl, byte [rsi]          ; Copying s2 char to rcx
        mov     dl, byte [rdi]          ; Copying s1 char to rdx
        cmp     dl, 0                   ; Is s1[i]
        je      end                     ; If equal, jump to end instructions
        cmp     cl, 0                   ; Is s2[i] is null
        je      end                     
        cmp     dl, cl                  ; Is s1[i] == s2[i]
        jne     end                     ; If not equal
        inc     rdi                     ; Incrementing to the next char
        inc     rsi
        jmp     strcmp_system           

end:
        mov     al, dl                  ; Copying s1[i] in rax
        mov     r8b, cl                 ; Copying s2[i] in r8
        sub     rax, r8                 ; s1[i] - s2[i]
        ret
        