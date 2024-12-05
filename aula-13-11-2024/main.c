#include <stdio.h>
#include <stdlib.h>

struct elemento{
    int dado;
    struct elemento *prox;
};

typedef struct elemento Nodo;
typedef Nodo* Lista;

// Função para criar uma lista vazia
Lista criarLista() {
    return NULL;
}

// Função para inserir um elemento de forma ordenada na lista
Lista inserirElemento(Lista l, int e) {
    Lista p, ant;
    Lista novo = malloc(sizeof(Nodo));

    if (novo == NULL) {
        printf("Erro ao alocar a memória!\n");
        return l;
    }

    novo->dado = e;

    // Caso a lista esteja vazia ou o novo elemento deva ser inserido no início
    if (l == NULL || l->dado >= e) {
        novo->prox = l;
        return novo;  // O novo elemento passa a ser o início da lista
    }

    p = l;
    ant = p;

    // Procura o ponto onde o elemento deve ser inserido (manter a lista ordenada)
    while (p != NULL && p->dado < e) {
        ant = p;
        p = p->prox;
    }

    // Insere o novo elemento entre 'ant' e 'p'
    ant->prox = novo;  // O anterior agora aponta para o novo elemento
    novo->prox = p;    // O novo elemento aponta para o próximo elemento (p)

    return l;  // Retorna a lista modificada
}

// Função para imprimir todos os elementos da lista
void imprimirLista(Lista l) {
    Lista p = l;
    if (p == NULL) {
        printf("Lista vazia.\n");
    } else {
        while (p != NULL) {
            printf("%d -> ", p->dado);
            p = p->prox;
        }
        printf("NULL\n");
    }
}

// Função para contar o número de elementos da lista
int contarElementos(Lista l) {
    Lista p = l;
    int cont = 0;
    while (p != NULL) {
        cont++;
        p = p->prox;
    }
    return cont;
}

// Função para buscar um elemento na lista
Lista buscarElemento(Lista l, int e) {
    Lista p = l;
    while ((p != NULL) && (p->dado != e)) {
        p = p->prox;
    }
    return p;
}

// Função para excluir um elemento da lista
Lista excluirElemento(Lista l, int e) {
    Lista p = l, ant = NULL;

    while ((p != NULL) && (p->dado != e)) {
        ant = p;
        p = p->prox;
    }

    if (p != NULL) {
        if (ant == NULL) {  // Removendo o primeiro elemento
            l = p->prox;  // Atualiza o início da lista
        } else {
            ant->prox = p->prox;  // O anterior agora aponta para o próximo do p
        }
        free(p);
    }
    return l;
}

// Função para exibir o menu de opções
void opcoes(Lista *l1) {
    int opt;
    int el;
    int items;

    printf("Informe a opção que deseja: \n");
    printf("1. Inserir elemento\n");
    printf("2. Retirar elemento\n");
    printf("3. Criar/redefinir lista\n");
    printf("4. Contar elementos da lista\n");
    printf("5. Exibir o conteúdo da lista\n");
    printf("6. Sair\n");
    fflush(stdin);
    scanf("%i", &opt);

    switch(opt) {
        case 1:
            printf("Informe o elemento que deseja inserir\n");
            fflush(stdin);
            scanf("%d", &el);
            *l1 = inserirElemento(*l1, el);  // Atualiza o ponteiro de l1
            opcoes(l1);
            break;
        case 2:
            printf("Informe o elemento que deseja retirar\n");
            fflush(stdin);
            scanf("%d", &el);
            *l1 = excluirElemento(*l1, el);  // Atualiza o ponteiro de l1
            opcoes(l1);
            break;
        case 3:
            *l1 = criarLista();  // Redefine a lista
            opcoes(l1);
            break;
        case 4:
            items = contarElementos(*l1);  // Conta elementos na lista
            printf("Existem %i elementos na lista\n", items);
            opcoes(l1);
            break;
        case 5:
            imprimirLista(*l1);  // Imprime a lista
            opcoes(l1);
            break;
        case 6:
            break;
        default:
            printf("Informe uma opcao valida!\n");
            opcoes(l1);
    }
}

int main(void) {
    Lista l1 = criarLista();  // Criação da lista na função main
    opcoes(&l1);  // Passa o endereço de l1 para a função de opções
    return 0;
}
