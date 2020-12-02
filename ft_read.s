; ----------------------------------------------------------------------------------------
; Writes the read function in assembly. Runs on 64-bit.
; Parameters/Registers : rdi for (first)fd parameter, rsi for (second)buf parameter,
;                        rdx for (third)count parameter.
; Return value : rax register.
; Warning : using gcc with errno call in the VM may cause segfault, runs with clang !
; ----------------------------------------------------------------------------------------

section .text
extern	__errno_location
global ft_read

ft_read:
        mov rax, 0                     ; Return value of read syscall is 0
        syscall                        
        cmp rax, 0                     ; Is read return is null ?
        jl end_err                     ; If lower, jump to end_err
        ret                            ; Return rax : contains the result of the syscall

end_err:
        neg rax                        ; Getting the absolute value
        mov rdx, rax                   ; Saving rax/write value in rdx
        call __errno_location          ; Calling errno value, rax now has the errno address
        mov [rax], rdx                 ; Putting rdx (we set before) in rax value
        mov rax, -1                    ; Assigning -1 to rax in case of error, as read function
        ret