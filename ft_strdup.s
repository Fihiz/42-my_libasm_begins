; ----------------------------------------------------------------------------------------
; Writes the strdup function in assembly. Runs on 64-bit.
; Parameters/Registers : rdi for (first)source parameter.
; Return value : rax register.
; ----------------------------------------------------------------------------------------

section .text
extern	ft_strlen
extern  ft_strcpy
extern  malloc
global ft_strdup

ft_strdup:
        call ft_strlen                     ; Rax takes rdi's strlen (for malloc call)
        inc rax                            ; Adding +1 for '\0'
        push rdi                           ; We'll call an external function that may destroy our register so we'll save it before the call and restore them afterwards
        mov rdi, rax
        call malloc                        ; Calling malloc with rax value (strlen of rdi + 1)
        pop rdi                            ; Restore our save-register    
        cmp rax, 0                         ; Malloc protection
        jz end_null                        ; If zero, jump to null return
        mov rsi, rdi                       ; Setting the two params before ft_strcpy calling (src and dest)
        mov rdi, rax                       
        call ft_strcpy                     ; Operating ft_strcpy in rax which is our dest pointer
        ret

end_null:
        xor rax, rax                       ; Faster than mov instruction
        ret                                ; Null  