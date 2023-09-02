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


## DAY 1 


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


# Introduction to Verilog RTL design and Synthesis

**Yosys**
Yosys is an open-source software framework for digital logic synthesis and formal verification. It's commonly used in digital design projects to convert high-level hardware description language (HDL) code, such as Verilog, into optimized gate-level representations.
- a netlist is generated by yosys for the given design file  
- Iverlog is used to generate the vcd file from the netlist and testbench.
- Output waveform is observed using gtkwave

**LOGIC SYNTHESIS**
- Synthesis is transforming RTL code lower level implementation(gate level).
- The RTL file and the front end library file is synthesized.
- Some cells should be fast in order to meet the performance rates and we need some slow cells to meet the "hold" condition.
- If we use too many fast cells, then the circuit may become bad in terms of power and area. There may also be hold time violations
- If we use too many slow cells, the circuit may become sluggish and may not meet the required criteria.

**Lab Using yosys and Sky130 PDKs**
- To invoke the Yosys tool from the verilog_files we type
```
yosys
```
- then we read the library
```
read_liberty -lib ../my_lib/lib/sky130_fd_sc_hd_tt_025C_1v80.lib
```
- we read the mux file
![image](https://github.com/Anirudh-Ravi123/pes_asic_class/assets/142154804/134fe11b-4ecf-4953-9c5b-27219bb3ab0b)

- to synthesize the design.
![image](https://github.com/Anirudh-Ravi123/pes_asic_class/assets/142154804/7e8f3efe-0dba-48e9-b2ce-6bb479d32c6e)

![image](https://github.com/Anirudh-Ravi123/pes_asic_class/assets/142154804/d7bf363d-fdc3-462f-8443-084a9199539b)


- To generate the netlist we now use the command
```
abc -liberty ../my_lib//lib/sky130_fd_sc_hd__tt_025C_1v80.lib
```

![image](https://github.com/Anirudh-Ravi123/pes_asic_class/assets/142154804/652921a6-ad67-41b7-9c3c-29edd155c6ca)


- we type ```show``` to display synthesized design.

  
![image](https://github.com/Anirudh-Ravi123/pes_asic_class/assets/142154804/b44efbb6-d11d-48e4-bbb9-a8a5d8bbd7fe)

- to see netlist

  
```
write_verilog good_mux_netlist.v
```

![image](https://github.com/Anirudh-Ravi123/pes_asic_class/assets/142154804/4b4c0d01-7db3-4a29-9050-c788a9ad12c0)


- for shortend verison of netlist

```
write_verilog -noaatr good_mux_netlist.v
```

![image](https://github.com/Anirudh-Ravi123/pes_asic_class/assets/142154804/dd6d8a71-6306-4e64-9cdf-7d1e7b99ebad)

Here 
- io & i1 :inputs
- sel : select line
- y: output


## DAY 4 

# Introduction to Timing Dot Libs

command to open the .lib file is 
```
gvim ../my_lib/lib/sky130_fd_sc_tt_025C_1v80.lib
```
![image](https://github.com/Anirudh-Ravi123/pes_asic_class/assets/142154804/6df9825d-50da-478d-a86a-e35c56328dd7)

# Here
- sky130 indicates 130nm library
- tt means typical. There can be slow fast and typical libraries
- 025C indicates the temperatures
- 1v8 is the voltage
We mainly look into process voltage and temperature as these vary 

We can also observe the units of various parameters.


![image](https://github.com/Anirudh-Ravi123/pes_asic_class/assets/142154804/209c0651-3589-45d4-8c47-e69b7aee6221)


![image](https://github.com/Anirudh-Ravi123/pes_asic_class/assets/142154804/29f0fa49-8712-4c3a-bc2b-570ad7bf9e39)


Keyword cell is used to define logic gates and also variations of the same  logic gate.


![image](https://github.com/Anirudh-Ravi123/pes_asic_class/assets/142154804/51486aee-dc4e-4e46-b660-1a8a1db5e6bf)

![image](https://github.com/Anirudh-Ravi123/pes_asic_class/assets/142154804/adc1f2e7-c4bc-43e9-a31f-926b1a6ace82)


Here 0,2,4 indicate the width of the logic gate in this case and gate.
Wider the transisistors area and power consumption is higher  but  delay is reduced.


## Hierarchical vs Flat Synthesis

# Hierarchical Synthesis:
Hierarchical synthesis involves breaking down a complex digital circuit into smaller, more manageable sub-modules or hierarchies. Each hierarchy can then be designed and optimized separately, and these hierarchies are interconnected to form the complete circuit. This approach is analogous to dividing a large problem into smaller, more understandable sub-problems, making the design process more manageable.

# Flat Synthesis
Flat synthesis, also known as flat design or flat hierarchy, involves designing a digital circuit without significant hierarchical structure. In this approach, the entire design is treated as a single, monolithic block. All the logic components, registers, and other elements are placed on a single level, without being organized into sub-modules or hierarchies. This method can be relatively simple for smaller designs but becomes increasingly challenging to manage as the complexity of the circuit grows. Debugging, optimization, and maintenance can become difficult due to the lack of modularization and organization.


The file being anaylyzed is ```multiple_modules.v```
![image](https://github.com/Anirudh-Ravi123/pes_asic_class/assets/142154804/c9d2e509-8f03-4122-be54-5d7b909b9ff1

Two submodules are defined. One for AND gate and one for OR gate.

To synthesize the desgign we use yosys 
- launch yosys by using the command ```yosys```
- then we read the library file using the command
```
read_liberty -lib ../lib/sky130_fd_sc_hd__tt_025C_1v80.lib
```
- read the verilog file using the command
```
 read_verilog multiple_modules.v
```
![image](https://github.com/Anirudh-Ravi123/pes_asic_class/assets/142154804/684a6ec9-dd8c-4f9b-93ed-4a4621be5f2f)

- to synthesize
```
synth -top multiple_modules
```
![image](https://github.com/Anirudh-Ravi123/pes_asic_class/assets/142154804/05338940-dcca-4f45-8a8a-ba6b1a7135ac)


-to link the design to the respective library file.
```
abc -liberty ../my_lib/lib/sky130_fd_sc_hd__tt_025C_1v80.lib
```
![image](https://github.com/Anirudh-Ravi123/pes_asic_class/assets/142154804/d13888de-2708-4455-9a65-e7ba14b086a8)

- To see the synthesized design we use the command
```
show multiple_modules
```

![image](https://github.com/Anirudh-Ravi123/pes_asic_class/assets/142154804/04fcbe08-e742-479a-bbe6-516d88b791e9)

The modules seen are the logic gates defined in the submodules.

- to generate the netlist
```
write_verilog -noattr multiple_modules_hier.v
geting multiple_modules_hier.v
```
![image](https://github.com/Anirudh-Ravi123/pes_asic_class/assets/142154804/3dc70f1e-8963-49b9-a69a-3c2c213efacd)

- If we use the command
```
flatten
```
the hierarchies won't be preserved and we will get an even more concise program

![image](https://github.com/Anirudh-Ravi123/pes_asic_class/assets/142154804/06c0e126-14dc-4ff2-a130-b214817d84db)



# Sub Module Level Synthesis 

We follow the previous first two steps to read the library and file 

- to synthesize the sub module we type the command 
```
synth -top sub_module1
```
![image](https://github.com/Anirudh-Ravi123/pes_asic_class/assets/142154804/f179c6e9-2709-4281-9f32-9952917961cd)


- link the design to the respective library file see the module 


![image](https://github.com/Anirudh-Ravi123/pes_asic_class/assets/142154804/3bb4f7b7-9592-443e-86d5-108af2fd1e2f)

 Sub Module Synthesis is used if we want to synthisize multiple instances of same module. The submodule can be synthesized and the netlist generated can be replicated.
 If very big design needs to be synthesized we can synthesize the parts one by one, gather the netlist files and then combine them together to get the final result.



## Various Flop Coding Styles and Optimization

- A flip-flop is a fundamental building block of digital circuits and sequential logic circuits in electronics.
- It is a bistable multivibrator, which means it has two stable states and can store one bit of information.
- Flip-flops are used to store and manipulate binary information, making them crucial in the design of memory elements, registers, and other sequential logic components in digital systems.
- Flip-flops are essential for creating sequential logic circuits, where the output depends not only on the current input but also on the previous states of the circuit.
- In digital circuits, glitches are unwanted and temporary fluctuations in the output that can occur due to the propagation delays of signals through combinational logic circuits. These fluctuations can result   in incorrect or unintended outputs for a short period of time.
- To prevent glitches, various techniques are used, and one of these techniques involves the use of flip-flops.
- When a clock signal transitions, the flip-flop reads its inputs and updates its output accordingly. This synchronization helps ensure that data transitions occur only at specific moments in time, reducing the likelihood of glitches.


# D Flip-Flop with Asynchronous Reset

![image](https://github.com/Anirudh-Ravi123/pes_asic_class/assets/142154804/8d43caf3-1bfe-4a6b-bd65-6e368e20996b)

- When the asynchronous reset signal  is high the output Q is forced to  logic 0 irrespective of the clock signal's state.
- On positive edge of the clock and not on the asynchronous reset the stored value is updated at the output.

# D Flip-Flop with Asynchronous Set

![image](https://github.com/Anirudh-Ravi123/pes_asic_class/assets/142154804/ca4d6abf-a0d3-4dbb-bca2-ad4bb15b8eb5)

- When the reset is high on the positive edge of the clock, the output of the flip-flop is set to 1.
- The output is set to d if there is a positive edge on clock and  the asynchronous set is low.

# D Flip-Flop with Synchronous Reset
![image](https://github.com/Anirudh-Ravi123/pes_asic_class/assets/142154804/87ebcd03-1370-4821-b867-4b5938bd626c)

- reset only activates on  a positive edge of the clock.
- the stored value is updated at the output on positive edge of the clock and when reset is low

# D Flip-Flop with Asynchronous Reset and Synchronous Reset

![image](https://github.com/Anirudh-Ravi123/pes_asic_class/assets/142154804/a9147167-a704-4703-94d5-88064b8fdd08)

- synchronous reset is high at the positive edge of the clock the output or asynchronous resest is high is forced to 0
- on positive edge of the clock and when reset is low output is set to d


## Flop Synthesis Simulation
# Asynchronous D Flip Flop 
Commands 
- ``` iverilog dff_asyncres.v tb_dff_asyncres.v```
- ```./a.out```
- ``` gtkwave tb_dff_asyncres.vcd ```
![image](https://github.com/Anirudh-Ravi123/pes_asic_class/assets/142154804/fd2af5e2-5ad6-482d-bd62-47eb53ac0471)

# WAVEFORM  
![image](https://github.com/Anirudh-Ravi123/pes_asic_class/assets/142154804/58044ae8-6f32-4ff4-8bdd-390cda34c514)


- the clock is postive and asynch_reset is high, it sets the output to 0

# Synthesis 
Commands 
```
yosys

read_liberty -lib ../lib/sky130_fd_sc_hd__tt_025C_1v80.lib

read_verilog dff_asyncres.v

synth -top dff_asyncres
```
![image](https://github.com/Anirudh-Ravi123/pes_asic_class/assets/142154804/de5f513f-46f2-40f6-bba0-d68ad0c99328)

![image](https://github.com/Anirudh-Ravi123/pes_asic_class/assets/142154804/0c1f365b-3460-40c9-bd3f-1715e63027f7)


```
dfflibmap -liberty ../mylib/lib/sky130_fd_sc_hd__tt_025C_1v80.lib

abc -liberty ../mylib/lib/sky130_fd_sc_hd__tt_025C_1v80.lib

show
```
![image](https://github.com/Anirudh-Ravi123/pes_asic_class/assets/142154804/88133d0a-28fe-42d6-93cc-18f34805076b)

![image](https://github.com/Anirudh-Ravi123/pes_asic_class/assets/142154804/0eb5c98f-32c0-4ad0-9554-f8ae8a20595a)



# D Flip_Flop with Asynchronous Set

```
iverilog dff_async_set.v tb_dff_async_set.v
./a.out
gtkwave tb_dff_async_set.vcd
```

![image](https://github.com/Anirudh-Ravi123/pes_asic_class/assets/142154804/90952f14-fe05-4425-88a4-3b3c87dcf5a1)

WAVEFORM
![image](https://github.com/Anirudh-Ravi123/pes_asic_class/assets/142154804/e3a0fe16-6713-4924-9789-68e253f953ef)


Here clock is postive and asynch_reset is high, it sets the output to 0 

# Synthesis 
```
yosys
read_liberty -lib ../my_lib/lib/sky130_fd_sc_hd__tt_025C_1v80.lib
read_verilog dff_async_set.v
synth -top dff_async_set
dfflibmap -liberty ../my_lib/lib/sky130_fd_sc_hd__tt_025C_1v80.lib
abc -liberty ../my_lib/lib/sky130_fd_sc_hd__tt_025C_1v80.lib
show
```
![image](https://github.com/Anirudh-Ravi123/pes_asic_class/assets/142154804/fbb37008-0400-446a-89e0-7bf7a9e13239)



# D Flip-Flop with Synchronous Reset

```
iverilog dff_syncres.v tb_dff_syncres.v
./a.out
gtkwave tb_dff_syncres.vcd
```
![image](https://github.com/Anirudh-Ravi123/pes_asic_class/assets/142154804/cebe1da1-e0db-4b78-ab80-423500bf1dcf)

WAVEFORM

![image](https://github.com/Anirudh-Ravi123/pes_asic_class/assets/142154804/33118c34-8c6a-4fb7-8e49-e4b5f93e4985)

Here sync_reset goes high the output remains the same until there is a posedge on the clock

# Synthesis 

```
yosys
read_liberty -lib ../my_lib/lib/sky130_fd_sc_hd__tt_025C_1v80.lib
read_verilog dff_syncres.v
synth -top dff_syncres
dfflibmap -liberty ../my_lib/lib/sky130_fd_sc_hd__tt_025C_1v80.lib 
abc -liberty ../my_lib/lib/sky130_fd_sc_hd__tt_025C_1v80.lib
show
```

![image](https://github.com/Anirudh-Ravi123/pes_asic_class/assets/142154804/4892ce18-178d-4a15-a9f5-06cf262ab300)



## Interesting Optimisations
# First Porgram

![image](https://github.com/Anirudh-Ravi123/pes_asic_class/assets/142154804/33861015-108a-426f-92e9-19b3f831062e)

Program that takes a 3 bit input and enerates a 4 bit output

Synthesis 
```
yosys
read_liberty -lib ../my_lib/lib/sky130_fd_sc_hd__tt_025C_1v80.lib
read_verilog mult_2.v
synth -top mul2
```
![image](https://github.com/Anirudh-Ravi123/pes_asic_class/assets/142154804/33726e6f-fdbd-4307-8721-678d1aeb746e)

![image](https://github.com/Anirudh-Ravi123/pes_asic_class/assets/142154804/f2fafbb6-20a8-44d6-b3ed-c53a23f5135b)


```
abc -liberty ../lib/sky130_fd_sc_hd__tt_025C_1v80.lib
show
```
![image](https://github.com/Anirudh-Ravi123/pes_asic_class/assets/142154804/291ebeb8-8dc2-47f9-8a37-30c816a004db)

to view the netlist 
```
write_verilog -noattr mul2_netlist.v
!gedit mul2_netlist.v
```
![image](https://github.com/Anirudh-Ravi123/pes_asic_class/assets/142154804/7be5949a-c167-4a67-9177-5b0e3a479da6)



# Second Porgram
![image](https://github.com/Anirudh-Ravi123/pes_asic_class/assets/142154804/7e0590cd-63f3-4499-b64d-946ae3693685)


Program  takes a 3 bit input and generates a 4 bit output

Synthesis 
```
yosys
read_liberty -lib ../my_lib/lib/sky130_fd_sc_hd__tt_025C_1v80.lib
read_verilog mult_8.v
synth -top mult8
```
![image](https://github.com/Anirudh-Ravi123/pes_asic_class/assets/142154804/24a6e7e6-c80a-4a2b-b2b2-17637d1b5c08)

![image](https://github.com/Anirudh-Ravi123/pes_asic_class/assets/142154804/9c33d5ef-3eb6-400b-9f7b-5530eb422c38)


```
abc -liberty ../lib/sky130_fd_sc_hd__tt_025C_1v80.lib
show
```
![image](https://github.com/Anirudh-Ravi123/pes_asic_class/assets/142154804/36ca424b-e3f8-44a6-8ff0-55e3bb15a1ed)

to generate netlist 
```
write_verilog -noattr mult8_netlist.v
!gedit mult8_netlist.v
```

![image](https://github.com/Anirudh-Ravi123/pes_asic_class/assets/142154804/7150c97f-2178-411b-9059-fd0ba3e383bd)


## DAY 5

# Introduction to Optimizations
# Combinational Logic Optimisations
Combinational logic optimizations are techniques used to improve the efficiency of combinational circuits, which are digital logic circuits with no feedback loops. These optimizations focus on reducing the number of gates, inputs, or levels of logic to achieve better performance, lower power consumption, and smaller chip area. 

 Some common combinational logic optimizations:
 - Karnaugh Maps (K-maps):
K-maps are graphical tools used to simplify Boolean functions with up to 4 or 5 variables efficiently. They allow you to visualize and group adjacent 1s in the truth table to identify and eliminate redundant terms.

- Multi-level Logic Optimization:
Some optimizations involve restructuring logic into multiple levels of gates, such as converting AND-OR logic to XOR-XNOR logic, or vice versa, to minimize the number of gates and levels.


# Sequential Logic Optimisations

Sequential logic optimizations aim to improve the efficiency, performance, and reliability of digital circuits that contain flip-flops and memory elements, which store information over time. These optimizations are crucial in digital system design to meet timing constraints, reduce power consumption, and enhance the overall functionality of sequential circuits. 
Some common sequential logic optimization techniques:
- Gate-level Optimization:
Within the combinational logic portions of sequential circuits, apply gate-level optimizations (as mentioned in the previous response) to minimize the number of gates, levels, and inputs.

- Sequential Logic Synthesis:
Use synthesis tools that specialize in optimizing sequential circuits. These tools can perform state-of-the-art optimizations such as retiming, resource sharing, and technology mapping.



# Combinational Logic Optimisations Programs 
1


When a = 1 y takes the value of b else  when a = 0 y takes on the value of 0.
![image](https://github.com/Anirudh-Ravi123/pes_asic_class/assets/142154804/58518f90-1916-4ef6-8b59-c0704d87f88e)

Commands to synthesize

```
read_liberty -lib ../my_lib/lib/sky130_fd_sc_hd__tt_025C_1v80.lib
read_verilog opt_check.v
synth -top opt_check
opt_clean -purge
abc -liberty ../my_lib/lib/sky130_fd_sc_hd__tt_025C_1v80.lib
show
```

![image](https://github.com/Anirudh-Ravi123/pes_asic_class/assets/142154804/c77cf423-26cc-48b8-a4d6-13983ae70106)


![image](https://github.com/Anirudh-Ravi123/pes_asic_class/assets/142154804/86373514-2916-4465-976e-adcbe5a5a1f0)

Optimized design



![image](https://github.com/Anirudh-Ravi123/pes_asic_class/assets/142154804/fe5a9b2e-d70a-4da5-8340-de23df8e0735)


2


When a = 1 y takes the value of 1 else  when a = 0 y takes on the value of b.
![image](https://github.com/Anirudh-Ravi123/pes_asic_class/assets/142154804/751e0c48-f545-4e68-a741-9cbd3c3c6324)

Following the same commands as the pervious program but replacing the file name with the respective file to synthesize.

![image](https://github.com/Anirudh-Ravi123/pes_asic_class/assets/142154804/1dec5666-e4d0-46a9-88f0-d6ebc71ec890)

![image](https://github.com/Anirudh-Ravi123/pes_asic_class/assets/142154804/723dc3d3-9017-4fdd-b69e-81e461a30a12)



Optimized design



![image](https://github.com/Anirudh-Ravi123/pes_asic_class/assets/142154804/e68107b4-0962-4fa3-a3b0-472ea02901d7)


3


When a = 1 and c = 1 y gets the value of b else y = 0
When a=0 y=0

![image](https://github.com/Anirudh-Ravi123/pes_asic_class/assets/142154804/b862423c-67e4-41fe-8730-e0ea48f03084)

Following the same commands as the pervious program but replacing the file name with the respective file to synthesize.

![image](https://github.com/Anirudh-Ravi123/pes_asic_class/assets/142154804/65e0d4c6-da09-45fb-81e1-c04389eb8c41)


![image](https://github.com/Anirudh-Ravi123/pes_asic_class/assets/142154804/5e82fb7f-99b0-4f92-80e4-c9c63c7ab618)



Optimized design


![image](https://github.com/Anirudh-Ravi123/pes_asic_class/assets/142154804/b5c3b651-f194-4987-bbbe-6ee37684245d)



4


Represents a XOR gate.

![image](https://github.com/Anirudh-Ravi123/pes_asic_class/assets/142154804/8de8a1c0-4ecc-42b0-b6ea-dc8465dcb73a)


Following the same commands as the pervious program but replacing the file name with the respective file to synthesize.


![image](https://github.com/Anirudh-Ravi123/pes_asic_class/assets/142154804/c30ca7f0-757b-4261-ab6e-cc63fcec0674)



![image](https://github.com/Anirudh-Ravi123/pes_asic_class/assets/142154804/b33d8cb9-37cf-4f12-84b6-f35d66d9255b)


Optimized Design 


![image](https://github.com/Anirudh-Ravi123/pes_asic_class/assets/142154804/fc96da59-06f3-4db1-b239-e4916771501f)



5

![image](https://github.com/Anirudh-Ravi123/pes_asic_class/assets/142154804/60a9cf9d-f2ae-4db2-9d46-52472d7c9652)


Following the same commands as the pervious program but replacing the file name with the respective file to synthsize.


![image](https://github.com/Anirudh-Ravi123/pes_asic_class/assets/142154804/6e538650-79ca-4b9f-8224-bf82b6bce281)


![image](https://github.com/Anirudh-Ravi123/pes_asic_class/assets/142154804/be618fc2-c604-40ec-b2ff-23e3bb17d93b)


Optimized Design 


![image](https://github.com/Anirudh-Ravi123/pes_asic_class/assets/142154804/a938f93f-1bd4-4da4-a274-7fd6855cca4b)




6

![image](https://github.com/Anirudh-Ravi123/pes_asic_class/assets/142154804/5b7e3e87-527f-4aae-8bf0-1f2fe7cd8b10)


Following the same commands as the pervious program but replacing the file name with the respective file to synthsize.

![image](https://github.com/Anirudh-Ravi123/pes_asic_class/assets/142154804/b5616914-c749-4de1-9753-9e3c37530596)


Optimized Design 

![image](https://github.com/Anirudh-Ravi123/pes_asic_class/assets/142154804/56809638-99ad-4098-be66-14f5570faef9)








# Sequential Logic Optimisations  Programs 
1

![image](https://github.com/Anirudh-Ravi123/pes_asic_class/assets/142154804/2cd45324-7acf-4a84-b357-f90d795821f4)

Reset is 1 the output D is always 0.
If Reset is 0 and on  positive edge of the clock the output is D = 1.
Simulation commands
```
iverilog dff_const1.v tb_dff_const1.v
/a.out
gtkwave tb_dff_const1.vcd
```
![image](https://github.com/Anirudh-Ravi123/pes_asic_class/assets/142154804/cceb9b1b-9118-452c-9850-0ba63e80df97)

**WAVEFORM**
![image](https://github.com/Anirudh-Ravi123/pes_asic_class/assets/142154804/89b6fae1-0746-4fe7-80bc-cfe6ee0a919b)



Synthesis commands
```
read_liberty -lib ../my_lib/lib/sky130_fd_sc_hd__tt_025C_1v80.lib
read_verilog dff_const1.v
synth -top dff_const1
dfflibmap -liberty ../my_lib/lib/sky130_fd_sc_hd__tt_025C_1v80.lib 
abc -liberty ../my_lib/lib/sky130_fd_sc_hd__tt_025C_1v80.lib
show
```

![image](https://github.com/Anirudh-Ravi123/pes_asic_class/assets/142154804/f081dde8-a545-4638-b6a9-4bbdf63b2541)


![image](https://github.com/Anirudh-Ravi123/pes_asic_class/assets/142154804/1cddc137-5411-4b22-a1ca-6d3c8e2d5bf7)

**Synthesized Design**

![image](https://github.com/Anirudh-Ravi123/pes_asic_class/assets/142154804/de15e59f-4508-41d9-b1f8-5abed5af57e4)




2

![image](https://github.com/Anirudh-Ravi123/pes_asic_class/assets/142154804/5cccba48-5703-4141-9e84-db0f0e03a394)

Reset is 1 the output D is always 0.
If Reset is 0 and on positive edge of the clock the output is D = 1.

Following the same steps as previous program for current program file.

**WAVEFORM**

![image](https://github.com/Anirudh-Ravi123/pes_asic_class/assets/142154804/3bb6dd1c-3cde-4c15-8392-de460a6368d6)

**Synthesized Design**
![image](https://github.com/Anirudh-Ravi123/pes_asic_class/assets/142154804/215c1ecb-bc4f-4f9c-ae60-bf44f161a2e1)

![image](https://github.com/Anirudh-Ravi123/pes_asic_class/assets/142154804/ed070134-09be-41ef-a6cd-ec2a09505ae6)

![image](https://github.com/Anirudh-Ravi123/pes_asic_class/assets/142154804/a1b0fa6f-78ff-4047-8952-1b69a87eabbf)




3

![image](https://github.com/Anirudh-Ravi123/pes_asic_class/assets/142154804/32d3a598-5cd9-4907-b0ef-98df8c3b551d)

The output of firstflop is input for the other flop.

Following the same steps as previous program for current program file.

**WAVEFORM**

![image](https://github.com/Anirudh-Ravi123/pes_asic_class/assets/142154804/65beba64-79a1-434d-b749-00ae21722c6c)


**Synthesized Design**
![image](https://github.com/Anirudh-Ravi123/pes_asic_class/assets/142154804/82b7125d-c921-457e-887a-2e9e14ca4843)


![image](https://github.com/Anirudh-Ravi123/pes_asic_class/assets/142154804/16f22982-897d-4386-89c4-fb28bdfb73a6)

![image](https://github.com/Anirudh-Ravi123/pes_asic_class/assets/142154804/8f86955c-e19b-442a-ab17-bda9d3b83acf)


4

![image](https://github.com/Anirudh-Ravi123/pes_asic_class/assets/142154804/df1efcf6-5581-4e4f-9bc4-03b9a84f2549)

The output of firstflop is input for the other flop.

Following the same steps as previous program for current program file.

**WAVEFORM**

![image](https://github.com/Anirudh-Ravi123/pes_asic_class/assets/142154804/2c8e44be-0053-444d-bad2-bad5f902c2cd)

**Synthesized Design**

![image](https://github.com/Anirudh-Ravi123/pes_asic_class/assets/142154804/fa5bda5e-3c51-44e1-ba96-0ccc96c6c449)

![image](https://github.com/Anirudh-Ravi123/pes_asic_class/assets/142154804/7b0b521a-0d64-4ae6-8b5b-92065f6370df)

![image](https://github.com/Anirudh-Ravi123/pes_asic_class/assets/142154804/bcb65d10-64e7-49df-9c65-26438c61d2e4)


5

![image](https://github.com/Anirudh-Ravi123/pes_asic_class/assets/142154804/d7845c41-022d-4548-a792-f153605abc34)

The output of firstflop is input for the other flop.

Following the same steps as previous program for current program file.

**WAVEFORM**

![image](https://github.com/Anirudh-Ravi123/pes_asic_class/assets/142154804/1a37ef1a-b2f2-42a2-ba2c-5ef7f22a71d3)

**Synthesized Design**

![image](https://github.com/Anirudh-Ravi123/pes_asic_class/assets/142154804/290ec120-1555-4b40-9ca6-5ea3c919936d)

![image](https://github.com/Anirudh-Ravi123/pes_asic_class/assets/142154804/2e2dd3ba-8217-4017-8657-a591787b4dcc)

![image](https://github.com/Anirudh-Ravi123/pes_asic_class/assets/142154804/8975d6e2-8040-49bf-9bc2-f80bafc643f1)

# Sequential Optimisations for Unused Outputs

1


![image](https://github.com/Anirudh-Ravi123/pes_asic_class/assets/142154804/b0a2ac4f-5b7b-4221-beb3-630878f92ed2)

program for  a 3-bit up counter

Commands for synthesis

```
read_liberty -lib ../my_lib/lib/sky130_fd_sc_hd__tt_025C_1v80.lib
read_verilog counter_opt.v
synth -top counter_opt
dfflibmap -liberty ../my_lib/lib/sky130_fd_sc_hd__tt_025C_1v80.lib
abc -liberty ../my_lib/lib/sky130_fd_sc_hd__tt_025C_1v80.lib
show
```

Synthesis Output 

![image](https://github.com/Anirudh-Ravi123/pes_asic_class/assets/142154804/985f1926-3965-45e1-9e1b-3983539ed7fe)


![image](https://github.com/Anirudh-Ravi123/pes_asic_class/assets/142154804/078c4932-0f13-4d1b-844a-f9bf59ac6d41)




2


![image](https://github.com/Anirudh-Ravi123/pes_asic_class/assets/142154804/56ca7013-9a5f-4ff9-9346-e6e861973c3a)

Following the same procedure as previous program

Synthesis Output 

![image](https://github.com/Anirudh-Ravi123/pes_asic_class/assets/142154804/9d1362aa-9f8a-4b92-98b0-a6aac82aada1)


![image](https://github.com/Anirudh-Ravi123/pes_asic_class/assets/142154804/46448a15-68bf-4ef4-b1ed-04cfa40dba17)




## DAY 6




