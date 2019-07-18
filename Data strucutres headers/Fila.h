fila_t* cria(){
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

void queue(fila_t* f, char c){
    if(cheia(f))
        printf("Cheia!");
    else{
        f->elem[f->ultimo] = c;
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
        printf("O %d-esimo elemento da fila e: %c\n",i,f->elem[i]);
        t--;
        i = (i+1) % MAX;
    }
}

void destroi(fila_t* f){
    free(f);
}

int verTamanho(fila_t* f){
    return f->tamanho;
}

void zerar(fila_t* f){
    f->primeiro = 0;
    f->ultimo = 0;
    f->tamanho = 0;
}
