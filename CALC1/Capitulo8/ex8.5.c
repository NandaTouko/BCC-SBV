#include <stdio.h>
#include <stdlib.h>

int buscar(const int *a, int n, int chave);

int main() {
    int n[10];
    int v;
    int r;

    for(int i = 0; i < 10; i++){
        printf("n[%d]: ", i);
        scanf("%d", &n[i]);
    }

    printf("Buscar por: ");
    scanf("%d", &v);

    r = buscar(n, 10, v);

    printf("O valor %d ", v);

    if(r != -1){
        printf("foi encontrado na posicao %d.", r);
    }else{
        printf("nao foi encontrado.");
    }

    return 0;
}

int buscar(const int *a, int n, int chave) {
    for(int i = 0; i < n; i++){
        if(a[i] == chave){
            return i;
        }
    }

    return -1;
}
