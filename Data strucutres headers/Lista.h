/*typedef struct lista{
    int vet[10];
    int ini;
    int fim;
    int tam;
    int ord;
}lista_t;*/

lista_t* criarLista(){
    lista_t *p;
    p = (lista_t*) malloc(sizeof(lista_t));
    p->ini=0;
    p->fim=0;
    p->tam=0;
    p->ord=0;
    return p;
}

int inserir(lista_t *p, char c){
    p->vet[p->fim] = c;
    p->fim++;
    p->tam++;
    return 1;
}

void imprimir(lista_t *p){
    for(int i=0;i<p->tam;i++){
        printf("%d ",p->vet[i]);
    }
}

char remover(lista_t* p){
    char c = p->vet[p->fim];
    p->fim--;
    p->tam--;
    return c;
}

void bubble_sort(lista_t *p, int n) {
    int i, t, j = n, s = 1;
    while (s) {
        s = 0;
        for (i = 1; i < j; i++) {
            if (p->vet[i] < p->vet[i - 1]) {
                t = p->vet[i];
                p->vet[i] = p->vet[i - 1];
                p->vet[i - 1] = t;
                s = 1;
            }
        }
        j--;
    }
}

void insertion_sort(lista_t *p, int n) {
    
    int escolhido, j;
    
    for (int i = 1; i < n; i++) {
        escolhido = p->vet[i];
        j = i - 1;
        
        while ((j >= 0) && (p->vet[j] > escolhido)) {
            p->vet[j + 1] = p->vet[j];
            j--;
        }
        
        p->vet[j + 1] = escolhido;
    }
}

int cheia(lista_t* p){
    if(p->tam == MAX){
        return 1;
    }
    else{
        return 0;
    }
}

int inserirOrdenado(lista_t* p, int num){
    if(cheia(p)){
        return 0;
    }
    else{
        int i = p->fim;
        while((i > 0) && (num < p->vet[i - 1])){
            p->vet[i] = p->vet[i - 1];
            i--;
        }
        
        p->vet[i] = num;
        p->fim++;
        return 1;
    }
}

int inserirInicio(lista_t* p, int num){
    if(cheia(p)){
        return 0;
    }
    else{
        for(int i = p->fim + 1; i > p->ini; i--){
            p->vet[i] = p->vet[i - 1];
        }
        p->vet[p->ini] = num;
        p->fim++;
        p->tam++;
        return 1;
    }
}

int inserirFim(lista_t *p, int num){
    if(cheia(p)){
        return 0;
    }
    else{
        p->vet[p->fim] = num;
        p->fim++;
        p->tam++;
        return 1;
    }
}

int inserirPosicao(lista_t* p, int posicao, int num){
    if(cheia(p)){
        return 0;
    }
    else{
        if((posicao > p->ini) && (posicao < p->fim)){
            for(int i = p->fim + 1; i > posicao; i--){
                p->vet[i] = p->vet[i - 1];
            }
            p->vet[posicao] = num;
            p->fim++;
            p->tam++;
            return 1;
        }
        else{
            return 0;
        }
    }
}

int vazia(lista_t* p){
    if(p->tam == 0){
        return 1;
    }
    else{
        return 0;
    }
}

int removerInicio(lista_t* p){
    if(vazia(p)){
        return 0;
    }
    else{
        int x = p->vet[p->ini];
        
        for(int i = p->ini; i < p->fim; i++){
            p->vet[i] = p->vet[i + 1];
        }
        
        p->fim--;
        return x;
    }
}

int removerPosicao(lista_t* p, int posicao){
    if(vazia(p)){
        return 0;
    }
    else{
        if((posicao > p->ini) && (posicao < p->fim)){
            int x = p->vet[posicao];
            
            for(int i = posicao; i < p->fim; i++){
                p->vet[i] = p->vet[i + 1];
            }
            
            p->fim--;
            return x;
        }
        else{
            return 0;
        }
    }
}

int removerFim(lista_t* p){
    if(vazia(p)){
        return 0;
    }
    else{
        int x = p->vet[p->fim];
        p->fim--;
        return x;
    }
}

int getInicio(lista_t* p){
    if(vazia(p)){
        return 0;
    }
    else{
        return p->vet[p->ini];
    }
}

int getFim(lista_t* p){
    if(vazia(p)){
        return 0;
    }
    else{
        return p->vet[p->fim];
    }
}

int buscarPosicaoValor(lista_t* p, int num){
    int i;
    if(vazia(p)){
        return 0;
    }
    else{
        for(i = p->ini; i < p->fim; i++){
            if(p->vet[i] == num){
                break;
            }
        }
        if(i == p->fim){
            return 0;
        }
        else{
            return i;
        }
    }
}

int buscarValorPosicao(lista_t* p, int posicao){
    if(vazia(p)){
        return 0;
    }
    else{
        if((posicao > p->ini) && (posicao < p->fim)){
            return p->vet[posicao];
        }
        else{
            return 0;
        }
    }
}
