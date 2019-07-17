pilha_t* cria(){
    pilha_t *p = (pilha_t*) malloc(sizeof(pilha_t));
    p->topo = 0;
    return p;
}

int empilha(pilha_t* p, int value){
    if (p->topo < MAX){
        p->elem[p->topo] = value;
        p->topo = p->topo + 1;
        return 1;
    }
    else{
        printf("ERRO: pilha cheia!\n");
        return 0;
    }
}

void imprimir(pilha_t* p){
    for(int i=p->topo-1;i>=0;i--){
        printf("Pilha: %d\n",p->elem[i]);
    }
}

void zerar(pilha_t* p){
    p->topo = 0;
}

int verTamanho(pilha_t* p){
    return p->topo;
}

int desempilha(pilha_t* p){
    p->topo--;
    return  p->elem[p->topo];
}
