; ----------------------------------------------------------------------------------------
; Writes the strlen function in assembly. Runs on 64-bit.
; Parameters/Registers : rdi for string parameter.
; Return value : rax register.
; ----------------------------------------------------------------------------------------

section .text                               ; Area memory that stores my executable code
global ft_strlen                            ; Entrypoint

ft_strlen:
            xor     rax, rax                ; Initializing rax to 0 (i = 0), faster than mov instruction

strlen_system:
            cmp     [rdi + rax], byte 0     ; Is str is null/finished
            jz      end                     ; If logical condition is valid, jump to end instruction
            inc     rax                     ; Incrementing my rax counter
            jmp     strlen_system           ; Jmp tells where to pursue instructions (loop in that case)

end:
            ret                             ; Automatically returns rax