; ----------------------------------------------------------------------------------------
; Writes the strdup function in assembly. Runs on 64-bit.
; Parameters/Registers : rdi for (first)source parameter.
; Return value : rax register.
; ----------------------------------------------------------------------------------------

section .text
extern	ft_strlen
extern  ft_strcpy
extern  malloc
extern	__errno_location
global ft_strdup

ft_strdup:
        call ft_strlen                     ; Rax takes rdi's strlen (for malloc call)
        inc rax                            ; Adding +1 for '\0'
        mov r8, rdi
        mov rdi, rax
        call malloc                        ; Calling malloc with rax value (strlen of rdi + 1)
        cmp rax, 0                         ; Malloc protection
        jz end_null                        ; If zero, jump to null return
        mov rdi, rax
        mov rsi, r8
        call ft_strcpy
        ret

end_null:
        call __errno_location              ; Calling errno value, rax now has the errno address, is necessary ?
        mov [rax], rdx                     ; In rax value, rdx we set
        xor rax, rax                       ; Faster than mov instruction
        ret                                ; Null  