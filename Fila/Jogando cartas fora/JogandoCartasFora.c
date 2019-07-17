#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

#define MAX 50

typedef struct fila{
    int ultimo;
    int primeiro;
    int tamanho;
    int elem[MAX];
}fila_t;

fila_t* criarFila(){
    fila_t *f = (fila_t*) malloc(sizeof(fila_t));
    f->ultimo = 0;
    f->primeiro = 0;
    f->tamanho = 0;
    return f;
}

int cheia(fila_t* f){
    if (f->tamanho == MAX)
        return 1;
    else
        return 0;
}

int queue(fila_t* f, int num){
    if(cheia(f))
        return 0;
    else{
        f->elem[f->ultimo] = num;
        f->ultimo = (f->ultimo+1) % MAX;
        f->tamanho++;
        return 1;
    }
}

void imprimirFila(fila_t* f){
    int i = f->primeiro;
    int t = f->tamanho;
    while (t>0){
        printf("Remaining card: %d\n",f->elem[i]);
        t--;
        i = (i+1) % MAX;
    }
}

int vazia(fila_t* f){
    if(f->tamanho == 0){
        return 1;
    }
    else{
        return 0;
    }
}

int dequeue(fila_t* f){
    if(vazia(f)){
        return 0;
    }
    else{
        f->tamanho--;
        char ret = f->elem[f->primeiro];
        f->primeiro = (f->primeiro+1) % MAX;
        return ret;
    }
}

int verTamanho(fila_t* f){
    return f->tamanho;
}

void zerar(fila_t* f){
    f->primeiro = 0;
    f->ultimo = 0;
    f->tamanho = 0;
}

int main() {

    int n;
    fila_t *f1;
    int vet[MAX];
    
    f1 = criarFila();
    
    do{
        scanf("%d", &n);
        if(n == 0){
            break;
        }
        
        for(int i=1; i<=n; i++){
            queue(f1, i);
        }
        
        printf("Discarded cards: ");
        while(verTamanho(f1) > 2){
            printf("%d, ", dequeue(f1));
            int x = dequeue(f1);
            queue(f1, x);
        }
        if(verTamanho(f1) == 2){
            printf("%d", dequeue(f1));
        }
        printf("\n");
        imprimirFila(f1);
        zerar(f1);
        
    }while(n != 0);
    
    free(f1);
    
    return 0;
}
