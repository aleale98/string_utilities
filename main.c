#include <stdio.h>
#include "string_replace.h"

int main(){
    //char *tmp = str_replace('p', "yz", "aiao", 1, 4);
    //printf("%s", tmp);
    char *tmp = "ciao come vaome?";
    char *sstr = "ome";
    int *indexes = NULL;
    indexes = substring(tmp, sstr, 3);
    printf("begin: %d\n", indexes[0]);
    printf("end: %d\n", indexes[1]);
    
    return 0;
}