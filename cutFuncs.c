#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

// check if string is a number
int isNumber(char num[]){
    int i = 0;
    int len = strlen(num);
    for (i=0; i<len;i++){
        if (!isdigit(num[i])){
            return 0;
        }
    }
    return 1;
}

// check if element is contained within an array
int isInArray(int fields[], int el, int len){

    int i = 0;
    for (i=0; i<len; i++){
        if (el==fields[i]){
            return 1;
        }
    }
    return 0;
}

// remove trailing new line
void removeTrail(char S[]){
    S[strlen(S)-1]='\0';
}

// cut command
void cut(char *S, char inputDelimeter[], char outputDelimeter[], int fields[], int lenArr,int Max){
    char fragment[100] = "";
    int first = 1;
    int count = 0;
    char curr;

    // check each field till end
    while (*S != '\0')
    {
        curr = *S;
        // if the current field is a delimeter
        if (curr==inputDelimeter[0])
        {
            count++;
            // if it is specified field, print
            if (isInArray(fields, count, lenArr)){
            if (first==0)
            {
                printf("%s",outputDelimeter);
            }
            printf("%s",fragment);
            first=0;
            }
            strcpy(fragment, "");

        }
        // keep forming word till delimetre
        else{
            strncat(fragment, &curr,1);
        }
        S++;
    }

    if (count == 0){
        printf("%s",fragment);
        strcpy(fragment, "");
    }

    count++;
    // print last word after the delimetre -> only if last field

    if (isInArray(fields, count, lenArr)){
         if (first==0)
            {
                printf("%s",outputDelimeter);
            }
            printf("%s",fragment);
            first=0;
            }
            strcpy(fragment, "");

    printf("\n");
}
