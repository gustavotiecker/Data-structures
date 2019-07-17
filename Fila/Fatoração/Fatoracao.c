#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

#define MAX 50

typedef struct fila{
    int ultimo;
    int primeiro;
    int tamanho;
    char elem[MAX];
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

void queue(fila_t* f, int num){
    if(cheia(f))
        printf("Cheia!");
    else{
        f->elem[f->ultimo] = num;
        f->ultimo = (f->ultimo+1) % MAX;
        f->tamanho++;
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

char dequeue(fila_t* f){
    if(vazia(f)){
        printf("Vazia!");
        return '0';
    }
    else{
        f->tamanho--;
        char ret = f->elem[f->primeiro];
        f->primeiro = (f->primeiro+1) % MAX;
        return ret;
    }
}

void imprime(fila_t* f){
    int i=f->primeiro;
    int t = f->tamanho;
    while (t>0){
        printf("%d " ,f->elem[i]);
        t--;
        if(t>=1){
            printf("* ");
        }
        i = (i+1) % MAX;
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

void fatorar(fila_t* f, int num){
    int divisor = 2;
    while(num > 1){
        if(num % divisor != 0){
            divisor++;
        }
        else{
            queue(f, divisor);
            num = num/divisor;
        }
    }
}

int main() {
    
    fila_t* f1;
    int n, num;
    
    f1 = criarFila();
    
    scanf("%d", &n);
    
    for(int i=0; i<n; i++){
        scanf("%d", &num);
        
        fatorar(f1, num);
        imprime(f1);
        printf("\n");
        zerar(f1);
    }
    
    free(f1);
    
    return 0;
}


