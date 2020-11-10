# LIBASM PROJECT

Assembly yourself : [SUBJECT](https://cdn.intra.42.fr/pdf/pdf/13297/fr.subject.pdf)

## What is assembler ?

*"The assembler is a so-called low-level language , that is to say that its operation is very close to machine language. It also means that a coding error can absolutely crash your machine. But the advantage of assembly language is that it can manage down to the smallest byte of memory and always know what code is being executed by the microprocessor at a given time.
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

## Some keywords

* __Microprocessor__, any of a type of miniature electronic device that contains the arithmetic, logic, and control circuitry necessary to perform the functions of a digital computer’s central processing unit. In effect, this kind of integrated circuit can interpret and execute program instructions as well as handle arithmetic operations.

* __A register__ is a memory location internal to a processor . Registers are at the top of the memory hierarchy  : they are the fastest memory in a computer, but the manufacturing cost is the highest because space in a microprocessor is limited.

* __A processor__ is the part of a computer that performs operations on the information that is put into it (CPU = Central Processing Unit)

## Need to remind some basics about computer memory

*"Computer memory is any physical device capable of storing information temporarily, like RAM (random access memory), or permanently, like ROM (read-only memory). Memory devices utilize integrated circuits and are used by operating systems, software, and hardware.*"

### Helpful links
[Computer memory](https://www.computerhope.com/jargon/m/memory.htm) \
[Computer overview](https://www.computerhope.com/issues/ch001262.htm) \
[ASSEMBLY LANGAGE](https://www.computerhope.com/jargon/a/al.htm)

### Assembly portability (and comparison to C)
*"__Is ASM portable?__ No. Because assembly languages are tied to one specific computer architecture, they are not portable. __A program written in one assembly language would need to be completely rewritten for it to run on another type of machine.__
Portability is one of the main advantages of higher-level languages. __The C programming language is often called "portable assembly" because C compilers exist for nearly every modern system architecture.__ A program written in C may require some changes before it will compile on another computer, but the core language is portable.
Generally speaking, the higher-level a language is, the fewer changes need to be made for it to run on another architecture. The lowest-level languages — machine language and assembly language — are not portable."*

* As we sew above, we need to remind that assembly is proper to the os and the processor machine. Let's have a look on an asm example :

#### ASM EXAMPLE FOR LINUX SYSTEM (source : COMPUTER HOPE)

*compile the assembly with NASM, which you can install with your package manager. For instance, on Ubuntu or Debian, you can install NASM using apt:*

```sudo apt update && sudo apt install nasm```

*Run this command to create your object file:*

```nasm -f elf64 hello.asm```

*The object file is named hello.o.* \
*use gcc to link this object file to the necessary libraries on your computer, and compile it to an executable file called hello:*

```gcc hello.o -o hello```

*lastly, run the executable file:*

```./hello```

*Hello, world!\
this is the same program, written in C:*

```#include <stdio.h>
int main()
{
  char msg[] = "Hello world\n";
  printf("%s\n",msg);
  return 0;
}