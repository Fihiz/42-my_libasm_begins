; ----------------------------------------------------------------------------------------
; Writes the write function in assembly. Runs on 64-bit.
; Parameters/Registers : rdi for (first)fd parameter, rsi for (second)buf parameter,
;                        rdx for (third)count parameter.
; Return value : rax register.
; Warning : using gcc with errno call in the VM may cause segfault, run with clang !
; ----------------------------------------------------------------------------------------

section .text
extern	__errno_location
global ft_write

ft_write:
        mov rax, 1                     ; Return value of read syscall is 1
        syscall                        ; Syscall entrypoint is in rax, we gave 1 so it calls write
        cmp rax, 0                     ; Is write return is null ?
        jl end_err                     ; jl (if lower) : if the destination operand is less than the source operand, jump
        ret                            ; Return rax : contains the result of the syscall

end_err:
        mov rdx, rax                    ; Saving rax/write value in rdx
        call __errno_location           ; Calling errno value, rax now has the errno address
        mov [rax], rdx                  ; In rax value, rdx we set
        mov rax, -1                     ; Assigning -1 to rax in case of error, as write function
        ret
