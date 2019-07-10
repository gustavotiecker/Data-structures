/*João está trabalhando em uma mina, tentando retirar o máximo que consegue de diamantes
"<>". Ele deve excluir todas as particulas de areia "." do processo e a cada retirada de
diamante, novos diamantes poderão se formar. Se ele tem como uma entrada
.<...<<..>>....>....>>>., três diamantes são formados. O primeiro é retirado de <..>,
resultando .<...<>....>....>>>. Em seguida o segundo diamante é retirado, restando
.<.......>....>>>. O terceiro diamante é então retirado, restando no final .....>>>., sem
possibilidade de extração de novo diamante.

Input Format
Deve ser lido um valor inteiro N que representa a quantidade de casos de teste. Cada linha
a seguir é um caso de teste que contém até 1000 caracteres, incluindo "<,>, ."

Output Format
Você deve imprimir a quantidade de diamantes possíveis de serem extraídos em cada caso de
entrada.*/

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

void zerar(pilha_t* p){
    p->topo = 0;
}

int main() {
    
    int n, cont;
    char vet[MAX];
    pilha_t* p1;
    
    p1 = criarPilha();
    scanf("%d", &n);
    
    for(int i=0;i<n;i++){
        cont=0;
        zerar(p1);
        
        scanf("%s", vet);
        int tamanho = strlen(vet);
        
        for(int j=0;j<tamanho;j++){
            if(vet[j] == '<'){
                empilhar(p1, 1);
            }
            else if(vet[j] == '>'){
                int result = desempilhar(p1);
                if(result == 1){
                    cont++;
                }
            }
        }
        printf("%d\n", cont);
    }
    
    
    return 0;
}
