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
    FILE* inputFile = fopen(fileName[1], "r");//file name string for input

        while(flag == 0)//loop through text and insert in array
        {
            curVal = (int)fgetc(inputFile);//getting next value & cast to int
            if(curVal == -1)
            {
                flag = 1;
            }
            else if(curVal != 32 && curVal != 9 && curVal != 10)//whitespace exception
            {
                fileArr[index] = curVal;//insert value into array
                printf("%d\n", curVal);//debugging to check input
                index++;//incrementing to next array index
            }
            else
            {
                printf("whitespace\n");//debug, in final implement won't do anything
            }
        }
        
        //begin tokenization
        int i = 0; 
        int flag1 = 0;    
        while(flag1 == 0)
        {
            if(fileArr[i] == 99 && fileArr[i+1] == 111 && fileArr[i+2] == 110 && fileArr[i+3] == 115 && fileArr[i+4] == 116)
            {
                tokenArr[tokenIndex] = constsym;
                tokenIndex;
            }
            
        }


}
