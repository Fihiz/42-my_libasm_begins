# LIBASM PROJECT

Assembly yourself : [FR subject](https://cdn.intra.42.fr/pdf/pdf/13297/fr.subject.pdf)

## What is assembler ?

*"The assembler is a so-called low-level language, that is to say that its operation is very close to machine language. It also means that a coding error can absolutely crash your machine. But the advantage of assembly language is that it can manage down to the smallest byte of memory and always know what code is being executed by the microprocessor at a given time. \
The assembler also has the advantage of being fast and low in volume. It is arguably the preferred language of all virus designers. Small comparison: a program displaying "Hello, World!" in C weighs 15,839 bytes, while the same program displaying the same message in Assembler weighs 23 bytes."*

## What are instructions ?
*"All microprocessors are designed to be programmable using machine language instructions, that is, binary code.
In contrast, assembly code uses text instructions, called source code.
This text source code is then compiled, by a special program called a compiler, to produce binary code.
For x86 family microprocessors , there are a large number of instructions, ranging from the most common, such as ADD to add two numbers, to more complex, such as XCHG allowing the exchange of values ​​between two registers. The successors to x86 have seen new features appear, such as the x87 family floating point calculation unit."*

## Syntax
*"A statement per line : Assembly language can only perform simple actions compared to those of higher level programming languages.
Each line contains only one instruction.
Depending on its complexity, an assembly code instruction can be executed in one or more microprocessor clock cycles.
In addition, the same instruction can cost more or less clock cycles depending on the processor model."*

```label: instruction operands ; comments```

## Some keywords

* __A microprocessor__, any of a type of miniature electronic device that contains the arithmetic, logic, and control circuitry necessary to perform the functions of a digital computer’s central processing unit. In effect, this kind of integrated circuit can interpret and execute program instructions as well as handle arithmetic operations.

* __A register__ is a memory location internal to a processor. Registers are at the top of the memory hierarchy  : they are the fastest memory in a computer, but the manufacturing cost is the highest because space in a microprocessor is limited.

* __A processor__ is the part of a computer that performs operations on the information that is put into it (CPU = Central Processing Unit)

* __An opcode__ is an instruction that performs a simple task on the computer.

* __An inline assembly__ is to embed assembler instructions in your C/C++ code, using the asm keyword. (in Libasm project, we need to render .s files)

* __In Intel syntax Assembly__, the destination is before the source (like : ```mov eax, 5```). The main difference between Intel and AT&T syntax is that Intel leaves the sizes of the instruction operands implicit, while AT&T makes them explicit, by appending suffixes to the instruction name (in Libasm project, we need to use Intel syntax).

* __A calling convention__ governs how functions on a particular architecture and operating system interact. This includes rules about includes how function arguments are placed, where return values go, what registers functions may use, how they may allocate local variables, and so forth.

* __A section/segment__ (from nasm official doc = "The SECTION directive (SEGMENT is an exactly equivalent synonym)") is a code section. For example, my section.text is the fixed area that stores my instruction codes.

## Need to remind some basics about computer memory

*"__Computer memory__ is any physical device capable of storing information temporarily, like RAM (random access memory), or permanently, like ROM (read-only memory). Memory devices utilize integrated circuits and are used by operating systems, software, and hardware.*"

__Stack and heap__ are two different memory management mechanisms. Both are used to manage memory access but their operation and use are not the same. \
__The stack__ is a portion of the memory allocated by the operating system for the execution of a task. It works like a stack of objects, meaning that the last item to arrive in the stack is the first that can be removed. The stack is used in particular when variables are passed from one function to another. Thanks to the stack system, the task does not have to remember the location of an item within the stack, which makes the stack much faster to use. The size of the stack is decided by the operating system when the task is launched, it cannot be varied, and the stack is deleted when the task is finished. \
__The heap__ is a location in memory used for dynamic allocations, such as pointers. Unlike the stack, any block in this space can be allocated or released at any time. This system makes the management of the heap more complex and less rapid because it is necessary to constantly know which block is allocated. The heap is created when a process starts and is linked to it. This means that several tasks can access the same block in this memory. It is therefore necessary to manage concurrency. The size of the heap varies and may increase if the program needs more memory. Using the heap is not automatic and depends on the language you are programming with. In C ++ ++, the heap is called with the new or malloc keywords. In the C language, it is necessary to free the memory occupied by pointers when it is no longer needed with the delete or free instructions. Misuse of the heap can cause memory leaks and slow or even disrupt the operation of an application.

### Helpful links
[Computer memory](https://www.computerhope.com/jargon/m/memory.htm) \
[Computer overview](https://www.computerhope.com/issues/ch001262.htm) \
[Assembly langage](https://www.computerhope.com/jargon/a/al.htm) \
[Calling Convention tutorial](https://www.raywenderlich.com/615-assembly-register-calling-convention-tutorial) \
[Intel vs AT&T syntax](http://staffwww.fullcoll.edu/aclifton/courses/cs241/syntax.html) \
[Assembly Calling Convention](https://cs61.seas.harvard.edu/site/2018/Asm2/)

### Assembly portability (and comparison to C)
*"__Is ASM portable?__ \
No. Because assembly languages are tied to one specific computer architecture, they are not portable.
__A program written in one assembly language would need to be completely rewritten for it to run on another type of machine.__
Portability is one of the main advantages of higher-level languages. \
__The C programming language is often called "portable assembly" because C compilers exist for nearly every modern system architecture.__ A program written in C may require some changes before it will compile on another computer, but the core language is portable.
Generally speaking, the higher-level a language is, the fewer changes need to be made for it to run on another architecture. The lowest-level languages — machine language and assembly language — are not portable."*

* As we sew above, we need to remind that assembly is proper to the architecture machine. Let's have a look on an asm example :

#### ASM EXAMPLE FOR LINUX SYSTEM (source : COMPUTER HOPE)

*compile the assembly with NASM, which you can install with your package manager. For instance, on Ubuntu or Debian, you can install NASM using apt:*

```sudo apt update && sudo apt install nasm```

*touch hello.asm*

```
        extern printf           ; the C printf function, to be called
        section .data           ; Data section, initialized variables
msg:    db "Hello, world!", 0   ; C string terminates with 0
fmt:    db "%s", 10, 0          ; The printf format, "\n",'0'
        section .text           ; Begin code section
        global main             ; the standard gcc entry point
main:                           ; the program label for the entry point
        push    rbp             ; set up stack frame, must be aligned
        mov     rdi,fmt
        mov     rsi,msg
        mov     rax,0           ; can also be: xor rax,rax
        call    printf          ; Call C printf function
        pop rbp                 ; restore stack
        mov rax,0               ; normal, no error, return value
        ret                     ; return
```

*run this command to create your object file:*

```nasm -f elf64 hello.asm```

*the object file is named hello.o.* \
*use gcc to link this object file to the necessary libraries on your computer, and compile it to an executable file called hello:*

```gcc hello.o -o hello```

*lastly, run the executable file:*

```./hello```

*Hello, world!\
this is the same program, written in C:*

```
#include <stdio.h>
int main()
{
  char msg[] = "Hello world\n";
  printf("%s\n",msg);
  return 0;
}
```

[NASM Assembly Cheat Sheet](https://www.cs.uaf.edu/2017/fall/cs301/reference/x86_64.html)  