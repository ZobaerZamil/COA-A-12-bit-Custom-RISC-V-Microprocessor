#include<stdio.h>
#include<string.h>
#include <stdlib.h>

/*  Required Functions  */
void file_to_Decimal_Command();
void remove_space(char command[], int size);
void remove_Commas_$(char str_command[30], int size);
char* place_OpCode(const char* command, const char* oldOp, const char* newOp);
void remove_R(char str_command[30], int size);
void Decimal_to_3b_Binary();
void Binary_to_HexaDecimal();

/*  MAIN Function  */
int main()
{
    file_to_Decimal_Command();      /* Function called for converting Assembly to Decimal */

    Decimal_to_3b_Binary();         /* Function called for converting Decimal to Binary */

    Binary_to_HexaDecimal();        /* Function called for converting Binary to HexaDecimal Instructions */

    return 0;
}

/*  Assembly Command to Decimal  */
void file_to_Decimal_Command()
{
    char command[30];       /* variables */
    int val;
    char* result = NULL;

    /* Open file */
    FILE *filepointer, *filepointer1;
    filepointer = fopen("E:\\7th SEMESTER\\CSE332\\Project\\Assembler\\Input.txt","r");
    filepointer1 = fopen("E:\\7th SEMESTER\\CSE332\\Project\\Assembler\\Decimal_Input.txt","w");

    if (NULL != filepointer1)       /* Checking whether file is empty or not */
    {
        fseek (filepointer1, 0, SEEK_END);      /* Go to end to the file */
        int size = ftell(filepointer1);

        if (0 != size)
        {
            fputs("\n",filepointer1);       /* Putting a new line at the end of the file */
        }
    }

    /* Reading whole file line by line */
    while(fgets(command,30,filepointer)!=NULL)
    {
        val=strlen(command);  /* find size */
        strlwr(command);      /* lower case command */

        remove_Commas_$(command,val);        /* remove ',' and '$' from command */

        if(strstr(command, "addi") != NULL)             /* Replace ADDi */
        {
            char search[] = "addi";
            char place[] = "2";
            result = place_OpCode(command, search, place);
        }
        else if(strstr(command, "add") != NULL)         /* Replace ADD */
        {
            char search[] = "add";
            char place[] = "0";
            result = place_OpCode(command, search, place);
        }
        else if(strstr(command, "sub") != NULL)         /* Replace SUB */
        {
            char search[] = "sub";
            char place[] = "1";
            result = place_OpCode(command, search, place);
        }
        else if(strstr(command, "load") != NULL)         /* Replace LOAD */
        {
            char search[] = "load";
            char place[] = "3";
            result = place_OpCode(command, search, place);
        }
        else if(strstr(command, "store") != NULL)         /* Replace STORE */
        {
            char search[] = "store";
            char place[] = "4";
            result = place_OpCode(command, search, place);
        }
        else if(strstr(command, "and") != NULL)         /* Replace AND */
        {
            char search[] = "and";
            char place[] = "5";
            result = place_OpCode(command, search, place);
        }
        else if(strstr(command, "beq") != NULL)         /* Replace BEQ */
        {
            char search[] = "beq";
            char place[] = "6";
            result = place_OpCode(command, search, place);
        }
        else if(strstr(command, "jump") != NULL)         /* Replace JUMP */
        {
            char search[] = "jump";
            char place[] = "7";
            result = place_OpCode(command, search, place);
        }
        else
        {

        }

        remove_R(result, val);          /* function called for removing 'r' */

        strcpy(command, result);

        fputs(command,filepointer1);    /* Storing Decimal command string in file */

        printf("%s", command);
    }

    free(result);       /* free pointer variable */

    fclose(filepointer);        /* Close file */
    fclose(filepointer1);
}

/*  Remove Space from Command  */
void remove_space(char command[], int size)
{
    int i, j;
    for(i = 0; i < size; i++)
    {
        if(command[i] == ' ')            /* searching space in command */
        {
            for(j = i; j < size; j++)
            {
                command[j]=command[j+1];    /* place the next value in current location */
            }
            size--;         /* Reducing Size of command */
        }
    }
}

/*  Remove Commas and '$' from Command  */
void remove_Commas_$(char str_command[30], int size)
{
    remove_space(str_command,size);     /* function called for removing space */
    int i;
    for(i=0 ; i< size ; i++)
    {
        if(str_command[i] == ',' || str_command[i] == '$' )     /* searching ',' and '$' in command */
        {
            str_command[i] = ' ';       /* replacing ',' and '$' with space */
        }
    }
    remove_space(str_command,size);     /* function called for removing space */
}

/*  Replace OpCode with Decimal values  */
char* place_OpCode(const char* command, const char* oldOp, const char* newOp)
{
    char* result;       /* variables */
    int i, count = 0;
    int newOplen = strlen(newOp);
    int oldOplen = strlen(oldOp);

    // Counting the number of times old word
    // occur in the string
    for (i = 0; command[i] != '\0'; i++)
    {
        if (strstr(&command[i], oldOp) == &command[i])
        {
            count++;
            i += oldOplen - 1;       /* Jumping to index after the old word */
        }
    }

    /* Making new string of enough length */
    result = (char*)malloc(i + count * (newOplen - oldOplen) + 1);

    i = 0;
    while (*command)
    {
        if (strstr(command, oldOp) == command)      /* compare the substring with the result */
        {
            strcpy(&result[i], newOp);          /* Placing newOp(Decimal value) */
            i += newOplen;
            command += oldOplen;
        }
        else
            result[i++] = *command++;
    }

    result[i] = '\0';       /* Putting NULL at the end of result */

    return result;
}

/*  Remove R from Command  */
void remove_R(char str_command[30], int size)
{
    remove_space(str_command,size);     /* function called for removing space */
    int i;
    for(i=0 ; i< size ; i++)
    {
        if(str_command[i] == 'r')       /* searching 'r' in command */
        {
            str_command[i] = ' ';       /* replacing 'r' with space */

        }
    }
    remove_space(str_command,size);     /* function called for removing space */
}

/*  Decimal to Binary Command  */
void Decimal_to_3b_Binary()
{
    char command[30], binaryCommand[13];     /* Variables */
    int val, i;

    FILE *filepointer, *filepointer1;           /* File Pointer */
    filepointer = fopen("E:\\7th SEMESTER\\CSE332\\Project\\Assembler\\Decimal_Input.txt","r");            /* Files Opening */
    filepointer1 = fopen("E:\\7th SEMESTER\\CSE332\\Project\\Assembler\\Output(Binary).txt","w");
    printf("\n\n");

    strcpy(binaryCommand, "\0");         /* Copying NULL to binaryCommand variable */

    while(fscanf(filepointer, "%s", command)!=EOF)      /* Reading File line by line */
    {
        val = strlen(command);

        /* convert Decimal to binary string */
        /* concatenation of binary string */
        for(i = 0; i < val; i++)
        {
            if(command[i] == '0')
            {
                strcat(binaryCommand, "000");
            }
            else if(command[i] == '1')
            {
                strcat(binaryCommand, "001");
            }
            else if(command[i] == '2')
            {
                strcat(binaryCommand, "010");
            }
            else if(command[i] == '3')
            {
                strcat(binaryCommand, "011");
            }
            else if(command[i] == '4')
            {
                strcat(binaryCommand, "100");
            }
            else if(command[i] == '5')
            {
                strcat(binaryCommand, "101");
            }
            else if(command[i] == '6')
            {
                strcat(binaryCommand, "110");
            }
            else if(command[i] == '7')
            {
                strcat(binaryCommand, "111");
            }
            else
            {

            }
        }
        printf("%s\n", binaryCommand);

        fputs(binaryCommand,filepointer1);      /* output binary string Storing in file*/
        fputs("\n",filepointer1);

        strcpy(binaryCommand, "\0");            /* Copying NULL to binaryCommand variable */
    }

    fclose(filepointer);        /* Files Closing */
    fclose(filepointer1);
}

/*  Decimal to HexaDecimal Command  */
void Binary_to_HexaDecimal()
{
    char command[14];   /* Variable */
    FILE *filepointer, *filepointer1;       /* File Pointer */
    filepointer = fopen("E:\\7th SEMESTER\\CSE332\\Project\\Assembler\\Output(Binary).txt","r");      /* Files Opening */
    filepointer1 = fopen("E:\\7th SEMESTER\\CSE332\\Project\\Assembler\\Output(Hex).txt","w");
    fputs("v2.0 raw\n",filepointer1);
    printf("\n");

    while(fgets(command,14,filepointer)!=NULL)      /* Reading File line by line */
    {
        int value = (int)strtol(command, NULL, 2);

        char hexCommand[12];
        sprintf(hexCommand, "%x", value);        /* convert binary to hex string */

        printf(hexCommand);     /* output hex string */
        printf("\n");

        fputs(hexCommand,filepointer1);     /* output hex string Storing in file*/
        fputs("\n",filepointer1);
    }

    fclose(filepointer);        /* Files Closing */
    fclose(filepointer1);
}








