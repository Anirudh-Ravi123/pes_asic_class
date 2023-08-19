# pes_asic_class
 Documentation of ASIC class guided by Kunal Gosh 
 
# Contents

# Day 1

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


![image](https://github.com/Anirudh-Ravi123/pes_asic_class/assets/142154804/c06f0430-d699-430a-a550-2588bd5a4162)










 






 
 
