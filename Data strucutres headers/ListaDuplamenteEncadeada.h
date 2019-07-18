/*typedef struct node{
    struct node *pProx;
    struct node *pAnt;
    int val;
}node_t;*/

typedef struct lista{
    node_t *pIni;
    node_t *pFim;
    int tam;
}lista_t;

lista_t* criarLista(){
    lista_t *p;
    p = (lista_t*) malloc(sizeof(lista_t));
    p->tam = 0;
    p->pIni = NULL;
    p->pFim = NULL;
    return p;
}

node_t* criarNo(){
    node_t *pNovo;
    pNovo = (node_t*) malloc(sizeof(node_t));
    pNovo->pAnt = NULL;
    pNovo->pProx = NULL;
    return pNovo;
}

int inserirInicio(lista_t *p, int c){
    node_t *pNovo;
    pNovo = criarNo();
    pNovo->val = c;
    
    if(p->pFim==NULL && p->pIni==NULL){//vazia
        p->pIni = pNovo;
        p->pFim = pNovo;
    }
    else{
        p->pIni->pAnt = pNovo;
        pNovo->pProx = p->pIni;
        p->pIni = pNovo;
    }
    p->tam++;
    
    return 1;
}

void inserirFim(lista_t *p, int c){
    node_t *pAux;
    pAux = criaNo();
    
    if(p->pIni==NULL && p->pFim==NULL){
        p->pIni = pAux;
        p->pFim = pAux;
    }
    else{
        p->pFim->pProx = pAux;
        pAux->pAnt = p->pFim;
        p->pFim = pAux;
    }
    p->pFim->val = c;
    p->tam++;
}

void inserirPos(lista_t *p, int c, int pos){
    if(pos >= p->tam && p->tam != 0){
        inserirFim(p,c);
    }
    else if(p->tam == 0){
        inserirInicio(p, c);
    }
    else{
        node_t *pAtual;
        pAtual = p->pIni;
        for(int i=1;i<pos;i++){
            pAtual = pAtual->pProx;
        }
        
        
        node_t *pNovo;
        pNovo=criaNo();
        pNovo->val = c;
        
        pNovo->pProx = pAtual;
        pNovo->pAnt = pAtual->pAnt;
        pNovo->pAnt->pProx = pNovo;
        pNovo->pProx->pAnt = pNovo;
        p->tam++;
    }
}

void imprimir(lista_t *p){
    node_t *pAtual;
    pAtual = p->pIni;
    while(pAtual!=NULL){
        printf("%d ",pAtual->val);
        pAtual = pAtual->pProx;
    }
}

int removerInicio(lista_t *p){
    if(p->tam > 1){
        p->pIni = p->pIni->pProx;
        free(p->pIni->pAnt);
        p->pIni->pAnt = NULL;
        p->tam--;
        return 1;
    }
    else if(p->tam == 1){
        p->tam = 0;
        free(p->pIni);
        p->pIni = NULL;
        p->pFim = NULL;
        return 1;
    }
    else{
        return 0;
    }
}

int removerFim(lista_t *p){
    if(p->tam > 1){
        p->pFim = p->pFim->pAnt;
        free(p->pFim->pProx);
        p->pFim->pProx = NULL;
        return 1;
    }
    else if(p->tam == 1){
        p->tam = 0;
        p->pIni = NULL;
        p->pIni = NULL;
        return 1;
    }
    else{
        return 0;
    }
}

int removerPosicao(lista_t *p, int pos){
    if(pos == 0 || p->tam == 0){
        return 0;
    }
    else if(pos >= p->tam){
        removerFim(p);
        return 1;
    }
    else if(pos < p->tam){
        node_t *pAtual;
        pAtual = p->pIni;
        for(int i=1;i<pos;i++){
            pAtual = pAtual->pProx;
        }
        pAtual->pAnt->pProx = pAtual->pProx;
        pAtual->pProx->pAnt = pAtual->pAnt;
        free(pAtual);
        return 1;
    }
    else{
        return 0;
    }
}
