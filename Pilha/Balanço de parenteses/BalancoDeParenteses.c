#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

#define MAX 1000

typedef struct pilha{
    int elem[MAX];
    int topo;
}pilha_t;

pilha_t* criarPilha(){
    pilha_t* p = (pilha_t*) malloc(sizeof(pilha_t));
    p->topo = 0;
    return p;
}

void empilhar(pilha_t* p, int num){
    if(p->topo < MAX){
        p->elem[p->topo] = num;
        p->topo = p->topo + 1;
    }
}

int desempilhar(pilha_t* p){
    if(p->topo == 0){
        return 0;
    }
    else{
        p->topo = p->topo - 1;
        return 1;
    }
}

void zerarPilha(pilha_t* p){
    p->topo = 0;
}

int pilhaVazia(pilha_t* p){
    if(p->topo == 0){
        return 1;
    }
    else{
        return 0;
    }
}

int main() {
    int n, aux = 0;;
    char vet[MAX];
    pilha_t *p1;
    
    p1 = criarPilha();
    scanf("%d", &n);
    
    for(int i=0;i<n;i++){
        zerarPilha(p1);
        aux = 0;
        
        scanf("%s", vet);
        int tamanho = strlen(vet);
        
        for(int j=0;j<tamanho;j++){
            if(vet[j] == '('){
                empilhar(p1, 1);
            }
            else if(vet[j] == ')'){
                int result = desempilhar(p1);
                if(result == 0){
                    printf("incorrect\n");
                    aux = 1;
                    break;
                }
            }
        }
        if(aux == 0){
            if(pilhaVazia(p1)){
                printf("correct\n");
            }
            else{
                printf("incorrect\n");
            }
            
        }
    }
    free(p1);
    return 0;
}
