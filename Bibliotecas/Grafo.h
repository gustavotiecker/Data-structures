/*typedef struct grafo{
    int **adjM;
    int nVertices;
}grafo_t;*/

grafo_t* cria(int nVertices){
    grafo_t *g;
    g = (grafo_t*) malloc(sizeof(grafo_t)); //aloca espaço para a estrutura grafo_t
    
    //cria a matriz e faz o ponteiro **adjM da matriz grafo_t apontar para ela
    g->adjM = (int**) malloc(nVertices*sizeof(int *)); //cria um array de *
    for(int i=0; i<nVertices; i++){
        g->adjM[i] = (int*) malloc(nVertices * sizeof(int)); //cria um array de int
    }
    
    g->nVertices = nVertices;
    return g;
}

void iniciaGrafo(grafo_t *g){
    int n = g->nVertices;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            g->adjM[i][j] = 0;
        }
    }
}

void lerGrafo(grafo_t *g){
    int n = g->nVertices;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            scanf("%d",&g->adjM[i][j]);
        }
    }
}

void imprimirGrafo(grafo_t *g){
    int n = g->nVertices;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            printf("%d ", g->adjM[i][j]);
        }
        printf("\n");
    }
}

void inserirAresta(grafo_t *g, int v1, int v2){
    g->adjM[v1][v2] = 1;
    g->adjM[v2][v1] = 1;
}

void removerAresta(grafo_t *g, int v1, int v2){
    g->adjM[v1][v2] = 0;
    g->adjM[v2][v1] = 0;
}

void inserirArestaDirecionada(grafo_t *g, int v1, int v2){
    g->adjM[v1][v2] = 1;
}

void removerArestaDirecionada(grafo_t *g, int v1, int v2){
    g->adjM[v1][v2] = 0;
}

grafo_t* inserirVertice(grafo_t *g) {
    grafo_t* g2;
    g2 = cria(g->nVertices + 1);
    
    int n = g->nVertices;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            g2->adjM[i][j] = g->adjM[i][j];
        }
    }
    
    return g2;
}

grafo_t* removerVertice(grafo_t *g, int vertice){
    grafo_t *g2;
    int n=0;
    int ind=0;
    ind = g->nVertices;
    n = g->nVertices - 1;
    g2 = cria(n);
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(i > vertice && j > vertice){
                g2->adjM[i][j] = g->adjM[i+1][j+1];
            }else if(i > vertice && j <= vertice){
                g2->adjM[i][j] = g->adjM[i+1][j];
            }else if(j > vertice && i <= vertice){
                g2->adjM[i][j] = g->adjM[i][j+1];
            }
            else{
                g2->adjM[i][j] = g->adjM[i][j];
            }
        }
    }
    return g2;
}

void DirecionadoParaNaoDirecionado(grafo_t *g){
    int n = g->nVertices;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(g->adjM[i][j] == 1){
                g->adjM[j][i] = 1;
            }
        }
    }
}

void verificarAdjacencia(grafo_t *g, int v1, int v2){
    if(g->adjM[v1][v2] == 1){
        printf("sim\n");
    }
    else{
        printf("nao\n");
    }
}

void quantosIsolados(grafo_t *g){
    int cont=0, aux=0;
    
    int n = g->nVertices;
    for(int i=0; i<n; i++){
        cont = 0;
        for(int j=0; j<n; j++){
            if(g->adjM[i][j] == 0){
                cont++;
            }
            if(cont == g->nVertices){
                aux++;
                if(aux == 1){
                    printf("Isolados ");
                }
                printf("%d ", i);
            }
        }
    }
}

void verificarLaco(grafo_t *g){
    int n = g->nVertices, laco=0;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(g->adjM[i][j] == 1 && i == j){
                laco++;
            }
        }
    }
    
    if(laco > 0){
        printf("sim %d\n", laco);
    }
    else{
        printf("nao");
    }
}

void verificarIsolado(grafo_t *g){
    int n = g->nVertices, isolado=0, cont=0;
    for(int i=0; i<n; i++){
        isolado = 0;
        for(int j=0; j<n; j++){
            if(g->adjM[i][j] == 1 || g->adjM[j][i] == 1){
                isolado++;
            }
        }
        if(isolado == 0){
            cont++;
        }
    }
    if(cont > 0){
        printf("sim %d\n", cont);
    }
    else{
        printf("nao\n");
    }
}

int verificarRegular(grafo_t *g){
    int soma=0;
    int n = g->nVertices;
    int vet[n];
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            soma = soma + g->adjM[i][j];
        }
        vet[i] = soma;
        soma = 0;
    }
    
    for(int i=1; i<n; i++){
        if(vet[i] != vet[i-1]){
            return 0;
        }
    }
    
    return 1;
}

int verificarValorado(grafo_t *g){
    int n = g->nVertices;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(g->adjM[i][j] != 0 && g->adjM[i][j] != 1){
                return 1;
            }
        }
    }
    return 0;
}
