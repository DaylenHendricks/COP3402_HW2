//Homework 2: PL0 Scanner
//Authors: Daylen Hendricks, Brandon Ramlagan
//COP 3402 Spring 2024
//Date 2/16/2024

//libraries
#include <stdio.h>
#include <stdlib.h>

//static values
#define MAXNUM 5 //max number of digits for a number
#define MAXIDENTIFIER 11 //max length of identifier name

//global variables
int tokenArr[500] = {0};//finalized token array
int tokenIndex = 0;


typedef enum {
skipsym = 1, identsym, numbersym, plussym, minussym,
multsym, slashsym, fisym, eqsym, neqsym, lessym, leqsym,
gtrsym, geqsym, lparentsym, rparentsym, commasym, semicolonsym,
periodsym, becomessym, beginsym, endsym, ifsym, thensym,
whilesym, dosym, callsym, constsym, varsym, procsym, writesym,
readsym , elsesym} token_type;


int main(int argc, char *fileName[])
{
    int fileArr[500] = {0};//array to store input
    int index = 0;//array index
    int curVal = 0;//current input value
    int flag = 0;//EOF flag
    int lastVal;
    int varCount = 0;
    FILE* inputFile = fopen(fileName[1], "r");//file name string for input

        while(flag == 0)//loop through text and insert in array
        {
            curVal = (int)fgetc(inputFile);//getting next value & cast to int
            if(curVal == 47)//finding "/"
            {
                lastVal = curVal;
                curVal = (int)fgetc(inputFile);//getting next value & cast to int
                if(curVal == 42 && lastVal == 47)//finding "/*"
                {
                    int commentFlag = 0;//flag for comment exclusion loop
                    while(commentFlag == 0)
                    {
                        lastVal = curVal;
                        curVal = (int)fgetc(inputFile);//getting next value & cast to int
                        if(curVal == 47 && lastVal == 42)
                        {
                            break;//want to break out of comment loop
                        }
                    }
                }
                else//if just "/"
                {
                fileArr[index] = lastVal;//store "/"
                index++;//move on
                }
            }
            if(curVal == -1)//end of file detection
            {
                flag = 1;
            }
            else if(curVal == 10 || curVal == 32)// \n to whitespace
            {
                fileArr[index] = 32;//insert value into array
                //printf("%d\n", fileArr[index]);
                index++;//incrementing to next array index
            }
            else
            {
                fileArr[index] = curVal;//insert value into array
                //printf("%d\n", curVal);//debugging to check input
                index++;//incrementing to next array index
            }
        }
        
//begin tokenization
        int i = 0; 
        int flag1 = 0;    
        while(flag1 == 0)
        {
    //reserved words

            
            if(fileArr[i] == 32)
            {
                i++;
            }
            //const
            else if(fileArr[i] == 99 && fileArr[i+1] == 111 && fileArr[i+2] == 110 && fileArr[i+3] == 115 && fileArr[i+4] == 116 && fileArr[i+5] == 32)
            {
                tokenArr[tokenIndex] = constsym;
                tokenIndex++;
                i += 6;
                printf("%d", tokenArr[tokenIndex]);
            }
            
            //var
            else if(fileArr[i] == 118 && fileArr[i+1] == 97 && fileArr[i+2] == 114 && fileArr[i+3] == 32)
            {
                tokenArr[tokenIndex] = varsym;
                tokenIndex++;
                i += 4;
            }

            //procedure
            else if(fileArr[i] == 112 && fileArr[i+1] == 114 && fileArr[i+2] == 111 && fileArr[i+3] == 99 && fileArr[i+4] == 101 && fileArr[i+5] == 100 && fileArr[i+6] == 117 && fileArr[i+7] == 114 && fileArr[i+8] == 101 && fileArr[i+9] == 32)
            {
                tokenArr[tokenIndex] = procsym;
                tokenIndex++;
                i += 10;
            }

            //call
            else if(fileArr[i] == 99 && fileArr[i+1] == 97 && fileArr[i+2] == 108 && fileArr[i+3] == 108 && fileArr[i+4] == 32)
            {
                tokenArr[tokenIndex] = callsym;
                tokenIndex++;
                i += 5;
            }

            //begin
            else if(fileArr[i] == 98 && fileArr[i+1] == 101 && fileArr[i+2] == 103 && fileArr[i+3] == 105 && fileArr[i+4] == 110 && fileArr[i+5] == 32)
            {
                tokenArr[tokenIndex] = beginsym;
                tokenIndex++;
                i += 6;
            }

            //end
            else if(fileArr[i] == 101 && fileArr[i+1] == 110 && fileArr[i+2] == 100 && fileArr[i+3] == 32)
            {
                tokenArr[tokenIndex] = endsym;
                tokenIndex++;
                i += 4;
            }
            //if
            else if(fileArr[i] == 105 && fileArr[i+1] == 102 && fileArr[i+3] == 32)
            {
                tokenArr[tokenIndex] = ifsym;
                tokenIndex++;
                i += 3;
            }
            //fi?
            else if(fileArr[i] == 102 && fileArr[i+1] == 105 && fileArr[i+3] == 32)
            {
                tokenArr[tokenIndex] = fisym;
                tokenIndex++;
                i += 3;
            }
            //then
            else if(fileArr[i] == 116 && fileArr[i+1] == 104 && fileArr[i+2] == 101 && fileArr[i+3] == 110 && fileArr[i+4] == 32)
            {
                tokenArr[tokenIndex] = thensym;
                tokenIndex++;
                i += 5;
            }
            //else
            else if(fileArr[i] == 101 && fileArr[i+1] == 108 && fileArr[i+2] == 115 && fileArr[i+3] == 101 && fileArr[i+4] == 32)
            {
                tokenArr[tokenIndex] = elsesym;
                tokenIndex++;
                i += 5;
            }
            //while
            else if(fileArr[i] == 119 && fileArr[i+1] == 104 && fileArr[i+2] == 105 && fileArr[i+3] == 108 && fileArr[i+4] == 101 && fileArr[i+5] == 32)
            {
                tokenArr[tokenIndex] = whilesym;
                tokenIndex++;
                i += 6;
            }
            //do
            else if(fileArr[i] == 100 && fileArr[i+1] == 111 && fileArr[i+3] == 32)
            {
                tokenArr[tokenIndex] = dosym;
                tokenIndex++;
                i += 3;
            }
            //read
            else if(fileArr[i] == 114 && fileArr[i+1] == 101 && fileArr[i+2] == 97 && fileArr[i+3] == 100 && fileArr[i+4] == 32)
            {
                tokenArr[tokenIndex] = readsym;
                tokenIndex++;
                i += 5;
            }
            //write
            else if(fileArr[i] == 119 && fileArr[i+1] == 114 && fileArr[i+2] == 105 && fileArr[i+3] == 116 && fileArr[i+4] == 101 && fileArr[i+5] == 32)
            {
                tokenArr[tokenIndex] = writesym;
                tokenIndex++;
                i += 6;
            }
            


    //identifiers
            else if((fileArr[i] >= 65 && fileArr[i] <= 90) || (fileArr[i] >= 97 && fileArr[i] <= 122))
            {
                int flag2 = 0;
                char ident[100] ={0};
                int identLen = 0;
                while(flag2 == 0)
                {
                    printf("hi");
                    if((fileArr[i] >= 65 && fileArr[i] <= 90) || (fileArr[i] >= 97 && fileArr[i] <= 122))
                    {
                                tokenArr[tokenIndex] = identsym;
                                tokenIndex++;
                                ident[identLen] = fileArr[i];
                                i++;
                                identLen++;
                    }
                     else
                    {
                        flag2 = 1;
                        i++;
                        varCount++;
                    }
                }

            }
//numbers
            else if(fileArr[i] >= 48 && fileArr[i] <= 57)
            {
                char num[20];
                tokenArr[tokenIndex] = numbersym;
                tokenIndex++;
                //tokenArr[tokenIndex] = fileArr[i];
                int numLen = 0;
                while(fileArr[i] >= 48 && fileArr[i] <= 57)
                {
                    num[numLen] = fileArr[i];
                    numLen++;
                    i++;
                }
                int c = atoi(num);
                tokenArr[tokenIndex] = c;
                tokenIndex++;
                i++;
            }
//symbols
            //lparentsym
           else if(fileArr[i] == 40)
            {
                tokenArr[tokenIndex] = lparentsym;
                tokenIndex++;
                i++;
            }
            //rparentsym
           else if(fileArr[i] == 41)
            {
                tokenArr[tokenIndex] = rparentsym;
                tokenIndex++;
                i++;
            }
            //mult
           else if(fileArr[i] == 42)
            {
                tokenArr[tokenIndex] = multsym;
                tokenIndex++;
                i++;
            }
            //plus
           else if(fileArr[i] == 43)
            {
                tokenArr[tokenIndex] = plussym;
                tokenIndex++;
                i++;
            }
            //comma
           else if(fileArr[i] == 44)
            {
                tokenArr[tokenIndex] = commasym;
                tokenIndex++;
                i++;
            }
            //minus
           else if(fileArr[i] == 45)
            {
                tokenArr[tokenIndex] = minussym;
                tokenIndex++;
                i++;
            }
            //period
            else if(fileArr[i] == 46)
            {
                tokenArr[tokenIndex] = periodsym;
                tokenIndex++;
                i++;
                flag1 = 1;
            }
            //slash
           else if(fileArr[i] == 47)
            {
                tokenArr[tokenIndex] = slashsym;
                tokenIndex++;
                i++;
            }
            //semicolon
            else if(fileArr[i] == 59)
            {
                tokenArr[tokenIndex] = semicolonsym;
                tokenIndex++;
                i++;
            }
            //equal
            else if(fileArr[i] == 61)
            {
                tokenArr[tokenIndex] = eqsym;
                tokenIndex++;
                i++;
            }
        }//tokenize while loop end
        for(int i = 0; i < tokenIndex; i++)
        {
            printf("%d ", tokenArr[i]);
        }
}//main end
