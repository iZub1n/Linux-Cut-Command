#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "cutFuncs.h"

#define MAX 100

//This Program mimics the Linux Command Cut!


// CLA 0: file name, 1: Input Delimeter, 2: Output Delimiter, 3: Field(s) 
int main(int argc, char *argv[]){
    //vars
    char inputDelimiter[2];
    char outputDelimiter[2];
    int i;
    char line[MAX];
    int prev;

    // cla checks
    if (argc<4 || argc>MAX+3 || strlen(argv[1])>1 || strlen(argv[2])>1 || (!isNumber(argv[3]))){
        fprintf(stderr, "%s: specify input_delimiter output_delimiter and 1-%d fields in order\n", argv[0], MAX);
        exit(1);
    }

    strcpy(inputDelimiter, argv[1]);
    strcpy(outputDelimiter, argv[2]);

    int fields[argc-3];
    prev=atoi(argv[3]);
    fields[0]=atoi(argv[3]);

    // save fields in a array and check validity
    for (i=4; i<argc;i++){

        if ((!isNumber(argv[i])) || prev>=atoi(argv[i])){
            fprintf(stderr, "%s: specify input_delimiter output_delimiter and 1-%d fields in order\n", argv[0], MAX);
            exit(1);
        }
        fields[i-3]=atoi(argv[i]);
        prev=atoi(argv[i]);
    }
    // cuts each line
      while (fgets(line, sizeof(line), stdin)){
            removeTrail(line);
            cut(line, inputDelimiter, outputDelimiter, fields, argc-3,MAX);
    }

    exit(0);

}