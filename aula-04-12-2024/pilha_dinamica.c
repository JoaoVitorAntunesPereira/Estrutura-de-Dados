#include <stdio.h>
#include <stdlib.h>



typedef struct elemento{
  int dado;
  struct elemento *prox;
}*PILHA;

PILHA criarPilha(){
  return NULL;
}

int pilhaVazia(PILHA p){
  if(p == NULL){
    return (1);
  }else{
    return (0);
  }
}

PILHA empilharElemento(PILHA p, int e){
  PILHA novo;

  novo = malloc(sizeof(PILHA));
  novo -> dado = e;
  novo -> prox = p;
  return novo;
}

PILHA desempilharElemento(PILHA p){
  PILHA ap;

  if(pilhaVazia(p)){
    printf("Pilha vazia.");
  }else{
  ap = p;
    p = p -> prox;
  }

  free(ap);
  return p;
}

void imprimirPilha(PILHA p){
  PILHA ap;
  ap = p;

  printf("\n Elementos da pilha");
  while(ap != NULL){
    printf(" %d ->", ap -> dado);
    ap = ap -> prox;
  }
  printf("\n");
}

void opcoes(PILHA p) {
  int opt;
  int el;

  printf("Informe a opção que deseja: \n");
  printf("1. Empilhar elemento\n");
  printf("2. Desempilhar elemento\n");
  printf("3. Imprimir lista\n");
  printf("4. Sair\n");
  fflush(stdin);
  scanf("%i", &opt);

  switch(opt) {
      case 1:
          printf("Informe o elemento que deseja inserir\n");
          fflush(stdin);
          scanf("%d", &el);
          p = empilharElemento(p, el);
          opcoes(p);
          break;
      case 2:
          printf("Elemento retirado\n");
          p = desempilharElemento(p); 
          opcoes(p);
          break;
      case 3:
          imprimirPilha(p); 
          opcoes(p);
          break;
      case 4:
          break;
      default:
          printf("Informe uma opcao valida!\n");
          opcoes(p);
  }
}

int main(void) {
  PILHA p;
  p = criarPilha();
  opcoes(p); 
  return 0;
}
