; ----------------------------------------------------------------------------------------
; Writes the strlen function in assembly. Runs on 64-bit.
; ----------------------------------------------------------------------------------------

section .text                       ; this is my text segment : my area memory that stores my executable code/instructions
global ft_strlen                   ; this my 'function declaration', my entrypoint that i labellize with _

ft_strlen:                         ; this is my label function and linker entrypoint
            ;push    rax             ; as if i was declaring the register i'll use for my counter
            xor     rax, rax        ; as if i was writing mov rcx, 0 : it means i initialize my counter to 0

ft_strlen_sys:
            cmp     [rdi], byte 0   ; is my str is null ?
            jz      ft_strlen_end  ; if my str is null (in case of empty or finished), jump (thanks to the instruction jz which treat the result of a logical comparison) to the next instructions in the section I labellized for that part
            inc     rax             ; if my str is valid (full or non-finished), I increment my counter I placed in rcx with 0
            inc     rdi             ; I also go on my str, to read the next char
            jmp     ft_strlen_sys  ; I am repeating the process, jmp tells where to pursue instructions (kind of loop in our case)

ft_strlen_end:
            ;mov     rax, rcx        ; rcx is my counter, i put it in rax to send it to ret (no need to "push rax" before? is it a norm to use rax for ret?)
            ;pop     rax             ; I retore rcx, kind of "free", I won't need it anymore
            ret                     ; my final return that