# pes_asic_class

VLSI (Very Large-Scale Integration) physical design for ASIC (Application-Specific Integrated Circuit) involves the process of transforming a high-level logical design of a digital circuit into a detailed layout that can be manufactured on a silicon wafer. This process includes various steps and considerations to ensure that the final integrated circuit functions correctly, meets performance requirements, and can be produced reliably.
It's a complex process that requires careful planning and attention to detail to ensure that the final ASIC functions as intended and meets performance and reliability requirements.

VLSI (Very Large-Scale Integration):
VLSI refers to the design and fabrication of integrated circuits (ICs) that contain a large number of transistors and other electronic components on a single chip.
ASIC (Application-Specific Integrated Circuit):
An ASIC is a type of integrated circuit that is designed and customized for a specific application or task. Unlike general-purpose microprocessors, which can execute a wide range of software, ASICs are optimized to perform a particular set of functions efficiently. They are tailored to meet the requirements of a specific application, resulting in better performance, lower power consumption, and potentially reduced cost compared to using off-the-shelf components.
# Contents

# Day 1
  - [ARCHITECTURE FLOW ](#architecture-flow)
  - [Apps to Hardware ](#apps-to-hardware)
  - [Running a simple C program](#running-a-simple-c-program)
  - [RISCV GCC Compile and Assembly Level code](#riscv-gcc-compile-and-assembly-level-code)
  - [Spike Simulation and Debug](#spike-simulation-and-debug)
  - [C Program for highest and lowest signed and unsigned integers](#c-program-for-highest-and-lowest-signed-and-unsigned-integers)

# Day 2
  - [Application Binary Interface](#application-binary-interface)
  - [Memory Allocation for Double Words](#memory-allocation-for-double-words)
  - [Load, Add and Store Instructions](#load-add-and-store-instructions)
  - [32-Registers and their ABI Names](#32-registers-and-their-abi-names)
  - [Sum of Numbers From 1 to n using ASM](#sum-of-numbers-from-1-to-n-using-asm)

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


## DAY 3

# Introduction to Verilog RTL design and Synthesis with SKY130 Technology
 # Open-Source Simulator iVerilog

**Simulator**
It is a tool used for simulating the design. It looks for the changes on the input signals to evaluate the outputs.
If there is no change in the inputs, the simulator doesn't evaluate the outputs.

**Iverilog**
Iverilog is an open-source Verilog simulation and synthesis tool used for designing and testing digital circuits. Verilog is a hardware description language (HDL) used to model and design digital systems, such as integrated circuits and FPGA (Field-Programmable Gate Array) designs.

Simulation Flow
-  A design code is the Verilog or VHDL code that you write to define the logic and behavior of your digital circuit.
-   A test bench is a separate piece of code written to simulate and test your design. It creates input stimuli to the design, monitors the outputs, and checks if the design's behavior matches the expected results.
- The iverilog simulator  is going to look for changes in the input and then accordingly dump the changes in the output. The output of the simulator is going to be a VCD file.
-  Output waveforms generated can be viewed using Gtkwave.GTKWave is a open-source waveform viewer used in digital circuit design and simulation.GTKWave is a versatile tool that aids in the debugging and verification of digital designs. It's widely used by digital designers and engineers to gain insights into their designs' behavior, making it easier to ensure correctness and reliability before moving to hardware implementation.

![image](https://github.com/Anirudh-Ravi123/pes_asic_class/assets/142154804/407cd84a-dfb3-4d28-8cff-c6e3db310d4b)


# LAB USING VERILOG AND GTKWAVE 
Installation 
- Create a new directory in home called as vsd and inside vsd create directory vlsi
- run the command
```
git clone https://github.com/kunalg123/sky130RTLDesignAndSynthesisWorkshop.git
```
![image](https://github.com/Anirudh-Ravi123/pes_asic_class/assets/142154804/5d065845-00f0-45be-bf70-fee64eb4465f)


- Navigate to the sky130RTLDesignAndSyntheseWOrkshop direcotry
- the verilog_files contains all the verilog source code files and the test bench files
![image](https://github.com/Anirudh-Ravi123/pes_asic_class/assets/142154804/07ac51a6-f7fa-47ed-8edb-0d7d2bcfe9dc)

EXECUTION 
- to run the file we can use verilog
'''
iverilog good_mux.v tb_good_mux.v
'''
![image](https://github.com/Anirudh-Ravi123/pes_asic_class/assets/142154804/a210fd94-b5a8-41a3-a38d-5467aca83a84)

DESIGN CODE

![image](https://github.com/Anirudh-Ravi123/pes_asic_class/assets/142154804/f6953336-7830-4c99-9ba7-a254fa57d3d0)


TESTBENCH CODE

![image](https://github.com/Anirudh-Ravi123/pes_asic_class/assets/142154804/dff49515-3d74-4679-b09f-f80bf979185c)



- after executing the command using ./a.out the vcd dump is created .
- gtkwave is used to view the waveform

```
  gtkwave tb_good_mux.vcd
```

![image](https://github.com/Anirudh-Ravi123/pes_asic_class/assets/142154804/24b0890a-13aa-41cc-942f-6a1222dce617)







 






 






 
 
