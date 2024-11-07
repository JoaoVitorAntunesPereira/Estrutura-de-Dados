#include <stdio.h>
#include <stdlib.h>

// Definição da estrutura do nodo (elemento da lista)
struct elemento {
    int dado;               // Conteúdo do nodo (um número inteiro)
    struct elemento *prox;  // Ponteiro para o próximo nodo
};

// Tipo para representar a lista (um ponteiro para o primeiro nodo)
typedef struct elemento Nodo;
typedef Nodo* Lista;  // Tipo Lista é um ponteiro para Nodo

// Função para criar uma lista vazia
Lista criaLista() {
    return NULL;  // Lista vazia é representada por NULL
}

// Função para inserir um elemento no início da lista
Lista insereLista(Lista l, int e) {
    Lista novo = malloc(sizeof(Nodo));  // Aloca memória para um novo nodo
    if (novo == NULL) {  // Verifica se a alocação falhou
        printf("Erro ao alocar memória.\n");
        return l;  // Retorna a lista original sem alterações
    }
    novo->dado = e;    // Atribui o valor ao novo nodo
    novo->prox = l;     // O próximo nodo será o atual início da lista
    return novo;        // O novo nodo é o primeiro da lista
}

// Função para imprimir todos os elementos da lista
void imprimeLista(Lista l) {
    Lista p = l;
    printf("\nItens da lista: ");
    while (p != NULL) {  // Percorre a lista até o final
        printf("%d -> ", p->dado);  // Imprime o dado do nodo
        p = p->prox;  // Avança para o próximo nodo
    }
    printf("NULL\n");
}

// Função para contar o número de elementos na lista
int contaLista(Lista l) {
    int cont = 0;
    Lista p = l;
    while (p != NULL) {  // Percorre a lista até o final
        cont++;  // Incrementa o contador
        p = p->prox;  // Avança para o próximo nodo
    }
    return cont;  // Retorna a quantidade de elementos
}

// Função para buscar um elemento na lista
Lista buscaLista(Lista l, int e) {
    Lista p = l;
    while (p != NULL && p->dado != e) {  // Percorre a lista buscando o elemento
        p = p->prox;
    }
    return p;  // Retorna o nodo encontrado ou NULL se não encontrado
}

// Função para remover um elemento da lista
Lista retiraLista(Lista l, int e) {
    Lista p = l, ant = NULL;
    while (p != NULL && p->dado != e) {  // Percorre a lista até encontrar o elemento
        ant = p;
        p = p->prox;
    }
    if (p != NULL) {  // Se o elemento foi encontrado
        if (ant == NULL) {  // Se for o primeiro elemento
            l = p->prox;  // O próximo nodo se torna o início da lista
        } else {
            ant->prox = p->prox;  // O anterior agora aponta para o próximo do atual
        }
        free(p);  // Libera a memória do nodo removido
    }
    return l;  // Retorna a lista com o elemento removido
}

int main() {
    Lista l1 = criaLista();  // Cria uma lista vazia
    l1 = insereLista(l1, 10);  // Insere o número 10
    l1 = insereLista(l1, 20);  // Insere o número 20
    l1 = insereLista(l1, 30);  // Insere o número 30

    imprimeLista(l1);  // Imprime a lista

    printf("Número de elementos na lista: %d\n", contaLista(l1));  // Conta os elementos

    Lista busca = buscaLista(l1, 20);  // Busca pelo número 20
    if (busca != NULL) {
        printf("Elemento %d encontrado na lista.\n", busca->dado);
    } else {
        printf("Elemento não encontrado.\n");
    }

    l1 = retiraLista(l1, 20);  // Remove o número 20
    imprimeLista(l1);  // Imprime a lista após remoção

    printf("Número de elementos na lista após remoção: %d\n", contaLista(l1));  // Conta após remoção

    return 0;
}
