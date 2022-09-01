# ***12-bit-Custom-RISC-V-Microprocessor***

This is Projecet of my **Undergraduate Studies** for the **Computer Organization And Architecture** course. 

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
  
  ![Instructions List](https://user-images.githubusercontent.com/72562681/187966777-076c9413-796f-4cfe-bc9f-210dd0ccd79d.jpg)
      
 
## 2. Assembler
  My designed assembler will convert the assembly instruction into Binary format and Hexadecimal Format. I designed this assembler in C Language. Firstly, it will convert the instructions into Binary formate or machine code. It will be one instruction per line. Then it will convert that machine code into Hexadecimal format which will be helpful for my processor. After converting the instructions into Hexadecimal format as Output file(.txt), we can load that file into Logisim and simulate the 12-bit Microprocessor.  
  
  
## 3. Processor
  For performing operations, I designed 12-bit Arithmetic Logic Unit and 12-bit Register file.
  For Automation, I designed a Control Unit.

  
