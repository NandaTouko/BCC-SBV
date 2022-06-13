#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char string[3][41]; // 3 strings de 40 caracteres + um para \0
    int comp1;

    for(int i = 0; i < 3; i++){
        printf("String %d: ", i+1);
        fgets(string[i], 41, stdin);

        string[i][strlen(string[i])-1] = '\0';
    }

    comp1 = strcmp(string[0], string[1]);

    if(comp1 < 0){
        printf("%s, %s", string[0], string[1])
    }

    return 0;
}
