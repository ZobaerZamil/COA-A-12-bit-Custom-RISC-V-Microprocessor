# ***12-bit-Custom-RISC-V-Microprocessor***

This is Projecet of my **Undergraduate Studies** for the ==Computer Organization And Architecture course==. 

## **Design And Building** 
In this project, I used Logisim and C Language for designing *12-bit-Custom-RISC-V-Microprocessor* which has 3 different parts. Those are
### *1. ISA (Instruction Set Architecture)*
### *2. Assembler*
### *3. Processor*

## 1. ISA (Instruction Set Architecture)
  Firstly, I designed the ISA for 12-bit-Custom-RISC-V-Microprocessor. As I have 12 bits, so I allocate those bit carefully for R-type, I-type, J-type ISA format.
  ### (R-Type) ISA Format
  
          |  Op Code |    rs   |    rt   |    rd   |
          |----------|---------|---------|---------|
          |   3-bit  |  3-bit  |  3-bit  |  3-bit  |
   
   ### (I-Type) ISA Format
   
          |  Op Code |    rs   |    rd   | Immediate |
          |----------|---------|---------|-----------|
          |   3-bit  |  3-bit  |  3-bit  |   3-bit   |
   
   ### (J-Type) ISA Format
   
          |    Op Code    |      Target      |
          |---------------|------------------|
          |     3-bit     |      9-bit       |
          
## List of Instructions
  ![Instructions List](https://drive.google.com/drive/my-drive "Instructions.jpg")

          
 
## 2. Assembler
  I use C languange to make the assembler which converts the assembly instructon into Binary format and Hexa format.
  
## 3. Processor
  For performing operations, I designed 12-bit Arithmetic Logic Unit and 12-bit Register file.
  For Automation, I designed a Control Unit.

  
