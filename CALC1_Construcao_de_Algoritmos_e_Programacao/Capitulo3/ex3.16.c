#include <stdio.h>
#include <stdlib.h>

int main() {
    int n1 = 0;
    int n2 = 1;
    int auxiliar;

    for(int i = 0; i < 20; i++){
        if(i == 0){
            printf("1 ");
        }else{
            auxiliar = n1 + n2;
            n1 = n2;
            n2 = auxiliar;

            printf("%d ", auxiliar);
        }
    }

    return 0;
}
