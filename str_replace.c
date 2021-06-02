//c = ciao --> str_replace("a", "ef", c) --> ciefo
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "string_replace.h"

void init_str(char *str){
    int i = 0;
    while((*(str+i)) != '\0'){
        *(str+i) = '\0';
        i++;
    }
}

int count_occurrences(char to_replace, char *str){
    int i = 0;
    int occurrences = 0;
    while((*(str+i)) != '\0'){
        if((*(str+i)) == to_replace){
            occurrences++;
        }
        i++;
    }
    return occurrences;
}

char *str_replace(char to_replace, char *replacement, char *str, size_t replacement_size, size_t string_length)
{
    char *tmp = NULL;
    if(str != NULL && replacement != NULL && replacement_size > 0 && string_length > 0){
        int occurrences = count_occurrences(to_replace, str);
        int i = 0;
        int char_to_add = (occurrences*replacement_size) - (occurrences);
        tmp = (char*)malloc((string_length+char_to_add)*sizeof(char));
        init_str(tmp);
        while((*(str+i)) != '\0'){
            if((*(str+i)) == to_replace){
                strcat(tmp, replacement);
            }else{
                char *tmp_var = (char*)malloc(sizeof(char));
                init_str(tmp_var);
                tmp_var[0] = *(str+i);
                strcat(tmp, tmp_var);
            }
            i++;
        }
    }
    return tmp;
}

int *substring(char *str, char *substr, size_t substr_length){ 
    int *indexes = (int*)malloc(sizeof(int));
    indexes[0] = 0;
    indexes[1] = 0;
    int str_index = 0;
    int substr_index = 0;
    while((*(str+str_index)) != '\0' && indexes[0] == 0 && indexes[1] == 0){
        if((*(str+str_index)) == (*(substr+substr_index))){
            indexes[0] = str_index;
            while((*(str+str_index)) != '\0' && (*(substr+substr_index)) != '\0' && (*(str+str_index)) == (*(substr+substr_index))){
                substr_index++;
                str_index++;
            }
            if(substr_index == (substr_length)){
                indexes[1] = str_index;
            }else{
                indexes[0] = 0;
                indexes[1] = 0;
            }
        }else{
            str_index++;
        }
    }
    return indexes;
}