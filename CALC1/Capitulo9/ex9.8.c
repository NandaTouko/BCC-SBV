#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char string[3][41]; // 3 strings de 40 caracteres + um para \0
    int comp1;
    int comp2;
    int comp3;

    for(int i = 0; i < 3; i++){
        printf("String %d: ", i+1);
        fgets(string[i], 41, stdin);

        string[i][strlen(string[i])-1] = '\0';
    }

    comp1 = strcmp(string[0], string[1]);
    comp2 = strcmp(string[1], string[2]);
    comp3 = strcmp(string[2], string[0]);

    if(comp1 <= 0 && comp2 <= 0){
        printf("%s, %s e %s", string[0], string[1], string[2]);
    }else if(comp3 >= 0 && comp2 >= 0){
        printf("%s, %s e %s", string[0], string[2], string[1]);
    }else if(comp2 <= 0 && comp3 >= 0){
        printf("%s, %s e %s", string[1], string[2], string[0]);
    }else if(comp1 >= 0 && comp3 >= 0){
        printf("%s, %s e %s", string[1], string[0], string[2]);
    }else if(comp2 >= 0 && comp1 >= 0){
        printf("%s, %s e %s", string[2], string[1], string[0]);
    }else if(comp3 <= 0 && comp1 <= 0){
        printf("%s, %s e %s", string[2], string[0], string[1]);
    }

    return 0;
}
