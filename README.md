# ***12-bit-Custom-RISC-V-Microprocessor***

This is a project of my **Undergraduate Studies** for the **Computer Organization And Architecture** course. 

## **Design And Building** 
In this project, I used Logisim and C Language for designing *12-bit-Custom-RISC-V-Microprocessor*, which has 3 different parts. Those are
### *1. ISA (Instruction Set Architecture)*
### *2. Assembler*
### *3. Processor*
-------------------------------------------------------------------------------------------------------------------------------------------------------

## 1. ISA (Instruction Set Architecture)
  Firstly, I designed the ISA for the 12-bit-Custom-RISC-V-Microprocessor. As I have 12 bits, so I allocate those bits carefully for R-type, I-type, and J-type ISA format.
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
  My designed assembler will convert the assembly instruction into Binary format and Hexadecimal Format. I created this assembler in C Language. 
    1. First, it will convert the assembly instructions into Binary format or machine code. It will be one instruction per line. 
    2. Then, it will convert that machine code into Hexadecimal format, which will be helpful for my processor. 
    3. After converting the instructions into Hexadecimal format as **Output file(.txt)**, we can load that file into *Logisim* and simulate the *12-bit Microprocessor*.  
  
  
## 3. Processor
  I designed **12-bit Arithmetic Logic Unit**to perform the operations, which perform arithmetic and logical operations. Here is the *12-bit ALU -* 
     
   ![ALU 12-bit](https://user-images.githubusercontent.com/72562681/188276083-a113c0f8-c104-4b28-a75b-4fea5bdea27b.jpg)
  
  
  Then I designed a **12-bit Register file**, which helps to write and read data in registers and calculate according to the instructions. Here is the *12-bit Register file -* 
         
   ![Register File 12-bit](https://user-images.githubusercontent.com/72562681/188276215-5b2a54fe-23dc-4425-986f-dc3c47c78436.jpg)


  For Automation, I designed a Control Unit where the Operation code will generate signals for that specific operation to complete the task properly. Here is the *Control Unit*  
          
   ![Control Unit](https://user-images.githubusercontent.com/72562681/188276354-03922313-d905-4afc-b50b-81b0c0edc268.jpg)


## ***Full-Single-Cycle Datapath***
    
   ![A 12-bit Custom RISC-V Microprocessor Datapath](https://user-images.githubusercontent.com/72562681/188276683-269c2c43-66b3-4ce8-9fd2-a0fde51a1181.jpg)

  
