#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

#define MAX 5

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
        int ret = f->elem[f->primeiro];
        f->primeiro = (f->primeiro+1) % MAX;
        return ret;
    }
}

int verTamanho(fila_t* f){
    return f->tamanho;
}

void imprime(fila_t* f){
    int i=f->primeiro;
    int t = f->tamanho;
    while (t>0){
        printf("%ds\n", f->elem[i]);
        t--;
        i = (i+1) % MAX;
    }
}

int main() {
    char opc;
    int num;
    fila_t *fN, *fP;
    
    fN = criarFila();
    fP = criarFila();

    do{
        scanf("%c", &opc);
        
        switch(opc){
            case 'N':{
                scanf("%d", &num);
                queue(fN, num);
                break;
            }
            
            case 'I':{
                scanf("%d", &num);
                queue(fP, num);
                break;
            }
                
            case 'G':{
                scanf("%d", &num);
                queue(fP, num);
                break;
            }
                
            case 'C':{
                if(vazia(fP) == 1){
                    num = dequeue(fN);
                    printf("%d ", num);
                }
                else{
                    num = dequeue(fP);
                    printf("%d ", num);
                }
                break;
            }
            
            case 'F':{
                num = verTamanho(fN) + verTamanho(fP);
                printf("\nRestaram %d pessoas na fila", num);
            }
        }
        
    }while(opc != 'F'); 
    return 0;
}
