//Homework 2: PL0 Scanner
//Authors: Daylen Hendricks, Brandon Ramlagan
//COP 3402 Spring 2024
//Date 2/16/2024

//libraries
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *fileName[])
{
    int * fileArr[500] = {0};//array to store input
    int index = 0;//array index
    int curVal = 0;//current input value
    FILE* inputFile = fopen(fileName[1], 'r');//file for input
    while(curVal != EOF)//loop through text and insert in array
    {
        curVal = fgetc(inputFile);//getting next value
        if(curVal != 32 && curVal != 9 && curVal != 10)//whitespace exception
        {
            fileArr[index] = curVal;//insert value into array
            printf("%d\n", curVal);//debugging to check input
            index++;//incrementing to next array index
        }
    }

    
}
