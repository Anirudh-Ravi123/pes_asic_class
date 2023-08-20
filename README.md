# pes_asic_class
 Documentation of ASIC class guided by Kunal Gosh 
 
# Contents

## Day 1

# ARCHITECTURE FLOW 
- HIGH LEVEL CODING LANGUAGE Like C or C++
- Complied to RISCV assembly language program converted to binary level logic 1 and logic 0
- HARDWARE DESCRIPTION LANGAUGE implements the RISCV assembply program using an RTL(register transfer logic)
- RTL converted to layout (GDS - Graphic Data System)

# Apps to Hardware 
- An application usually written using  high level programming language such as C,C++
- The code is compiled with the help of compilers running on a system software
- The compiler converts the high level code into assembly intructions for the system processor
- The assembler then converts the instructions into binary which is fed into the layout of the chip  and the program is hence run.


## Running a Simple C program

# Simple C program to calculates sum from 1 to N

![image](https://github.com/Anirudh-Ravi123/pes_asic_class/assets/142154804/c256fef2-2355-47f1-8221-3f7f79461677)



![image](https://github.com/Anirudh-Ravi123/pes_asic_class/assets/142154804/8966ccc9-d9d3-41f5-97b9-1839e5555592)


## RISCV GCC Compile and Assembly Level code

 We can use the RICSV GCC complier to compile the program by using the command 
```
riscv64-unknown-elf-gcc -O1 -mabi=lp64 -march=rv64i -o sum1ton.o sum1ton.c
riscv64-unknown-elf-objdump -d sum1ton.o | less
```
- O1: This flag sets the optimization level to 1
- mabi=lp64: This flag specifies the ABI (Application Binary Interface) to use. lp64 stands for long int and pointer size 64 bits.
- march=rv64i: This flag specifies the RISC-V architecture to target. rv64i indicates a 64-bit integer base instruction set architecture
- objdump: This is the objdump tool for RISC-V architecture
- | less:  allows you to view the output interactively

  ![image](https://github.com/Anirudh-Ravi123/pes_asic_class/assets/142154804/28a1ff96-61c7-4037-8434-f499a88634e9)


 We navigate the the main function of the assembly level code and we see the number of steps taken to run the code in assembly.
 ![image](https://github.com/Anirudh-Ravi123/pes_asic_class/assets/142154804/8014d335-88cc-4bc1-8444-629cbfe23080)



## Spike Simulation and Debug
Comparing the output of the RICSV gcc complier to the previously used gcc complier

![image](https://github.com/Anirudh-Ravi123/pes_asic_class/assets/142154804/36b21e97-a26d-4480-ac14-482e06b66464)

- spike:command to launch the RISC-V Spike simulator
- pk (proxy kernel):  used to load and run the program

  main function disassembled
 ![image](https://github.com/Anirudh-Ravi123/pes_asic_class/assets/142154804/493df41b-b6f8-46dd-9ee3-e60b93e8b956)


  to open the spike debugger we type the following command :
   ```spike -d pk (filename).o```


  to run partially till a particular intruction of choice then we can use the following command 
```
until pc 0 (line number)
```
![image](https://github.com/Anirudh-Ravi123/pes_asic_class/assets/142154804/4429e2ef-d0d7-4723-b6ef-dca8c05c57dc)

To find the contents of a variable we use the command : 



```reg 0 (variable name)```. 

We can execut the next line by pressing the enter key


![image](https://github.com/Anirudh-Ravi123/pes_asic_class/assets/142154804/c06f0430-d699-430a-a550-2588bd5a4162)


## C Program for highest and lowest signed and unsigned integers


Unsigned Highest
An unsigned integer can only represent non-negative numbers. It uses all bits to represent the magnitude of the number, without reserving any bit for sign representation
The range of values that can be represented by an N-bit unsigned integer is from 0 to 2^N - 1

![image](https://github.com/Anirudh-Ravi123/pes_asic_class/assets/142154804/d4e542e2-1b8a-4a2f-99b3-0ee8d1c60353)



![image](https://github.com/Anirudh-Ravi123/pes_asic_class/assets/142154804/10c1e3ad-3479-4fc4-a962-4b2901a65ea6)


Signed Highest
A signed integer can represent both positive and negative numbers. It uses one bit to represent the sign (positive or negative) and the remaining bits to represent the magnitude of the number
The range of values that can be represented by an N-bit signed integer is from -2^(N-1) to 2^(N-1) - 1

![image](https://github.com/Anirudh-Ravi123/pes_asic_class/assets/142154804/295ab909-bbc8-4fe8-9e46-db6c7288eb25)


![image](https://github.com/Anirudh-Ravi123/pes_asic_class/assets/142154804/a1c94b6e-3cea-4ce5-8b2e-9417055c489a)


## Day 2

# Application Binary Interface

- An Application Binary Interface (ABI) is a set of rules and conventions that dictate how different components of a software system communicate with each other at the binary level. ABI serves as a bridge between high-level programming languages and the machine-level instructions that computers understand.

- ABIs are essential for ensuring compatibility between different parts of a system, especially when those parts are developed by different parties or using different programming languages.

# Memory Allocation for Double Words

Length of a register in the RISCV architecture is 64 bits. The two different ways to load data into these registers:
  - Loading data directly into the registers
  - Loading data into memory and then into the registers.

64-bit number  can be loaded into memory in little-endian or big-endian format.

-Big-Endian:
In a big-endian system the most significant byte value is stored at the lowest memory address, while the least significant byte is stored at the highest memory address. 

-Little-Endian:
In a little-endian system the least significant byte value is stored at the lowest memory address, while the most significant byte is stored at the highest memory address. 

# Load, Add and Store Instructions

**Load Instruction**
Load instructions are used to transfer data from memory into registers.Load instructions are essential for bringing data into the processor's registers before it can be manipulated by other instructions.

```
ld  x6, 16(x7)
```

- ld: Load Doubleword. It indicates that the instruction is used to load a 64-bit value from memory.
- x6: This is the destination register.
- 16: This is the offset value. It specifies the displacement from the address in register x7.
- (x7): This indicates that the address from which to load the data is calculated using the value stored in register x7.


Execution 

![image](https://github.com/Anirudh-Ravi123/pes_asic_class/assets/142154804/51665fdf-d62d-4c06-bb91-06365aa21656)

- funct3 and opcode stores the ld command
- Destination register is stored as 5 bits in rd.
- ource register is stored as 5 bits in rs1.
- Offset is stored as 12 bits in immediate

  
  

 
**Add Instruction**

 Assembly instruction add is used to perform addition between two registers and store the result in a destination register.

 ```
add  x1, x2,x3
```

- x1:destination register
- x2,x3:source registers containing the operands that are to be added.

Execution
![image](https://github.com/Anirudh-Ravi123/pes_asic_class/assets/142154804/505eedee-2f0c-4cf8-9cc6-db5d820eb327)

- funct3 funct7 and opcode stores the add command.
- destination register x1 is stored in rd.
- source registers x2 and x3 are stored in rs1 and rs2.


**Store Instruction**
Store instructions are used to transfer data from registers back to memory. Store instructions are necessary for updating memory with the results of computation carried out by the processor.

 ```
sd  x2, 8(x3)
```
- sd : store doubleword command
- x2 is the data register
- x3 is the source register
- 8 is offset

  ![image](https://github.com/Anirudh-Ravi123/pes_asic_class/assets/142154804/daa44b3e-d70f-4c1c-aa57-bdf84a27de51)

- funct3 and opcode stores the sd command
-  offest 8 is stored as immediate
-  data register x2 is stored in rs2
-  source register x3 in rs1

  # 32-Registers and their ABI Names
  In the RISC-V architecture, there are 32 integer registers, and they are commonly referred to by their numeric indices x0 through x31. 

 **ABI Names**
 These are the names a user uses to access the registers of the RISC-V CPU core.

 
 ![image](https://github.com/Anirudh-Ravi123/pes_asic_class/assets/142154804/e0125ca7-3f3f-40ae-b9b4-90b9c5d5d13d)


 

 # Sum of Numbers from 1 to n using ASM

 We write two programs here, one in C and one in assembly. Main part of the program is processed in ASM and result is desplayed through the C program.

C code 
![image](https://github.com/Anirudh-Ravi123/pes_asic_class/assets/142154804/8cf4ee89-7f69-43f0-ba43-b6a39f1c35d7)

Assembly code

![image](https://github.com/Anirudh-Ravi123/pes_asic_class/assets/142154804/569c005e-d0e1-41a6-865a-37a507adb2bf)


Execution 

![image](https://github.com/Anirudh-Ravi123/pes_asic_class/assets/142154804/b1d3bf31-cad1-4d6e-9dbf-6abd2638c6b4)


![image](https://github.com/Anirudh-Ravi123/pes_asic_class/assets/142154804/9b0153fd-5fea-4461-be70-f1411a5819cf)







 






 
 
