; ----------------------------------------------------------------------------------------
; Writes the strcpy function in assembly. Runs on 64-bit.
; Parameters/Registers : rdi for (first)dest parameter, rsi for (second)source parameter.
; Return value : rax register.
; ----------------------------------------------------------------------------------------

section .text
global ft_strcpy

ft_strcpy:
          xor   rax, rax                    ; i = 0
          ;xor   rdx, rdx                   ; 64-bit linux parameters order: rdi, rsi, rdx, rcx, r8, and r9.

copy_system:
          cmp   [rsi + rax], byte 0         ; Is source is null/finished
          jz    end                         ; If above check is valid, jump to end instruction
          mov   dl, byte [rsi + rax]        ; One byte = 8 bits, dl = 8-bit char from rdx
          mov   byte [rdi + rax], dl        ; Copying src[i] in dest[i], dest[i] = src[i]
          inc   rax                         ; i++
          jmp   copy_system                 ; Repeating copy_system

end:
          mov   [rdi + rax], byte 0         ; Adding '\0' to dest
          mov   rax, rdi                    ; Moving dest in rax for final return
          ret