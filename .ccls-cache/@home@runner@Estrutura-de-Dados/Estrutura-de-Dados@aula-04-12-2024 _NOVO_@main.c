#include <stdio.h>
#define TRUE 1
#define FALSE 0
  


typedef struct{
  int dado;
  struct elemento *prox;
}*PILHA;

PILHA criarPilha(){
  return NULL;
}

PILHA p;

p = criarPilha();

int pilhaVazia(PILHA p){
  if(p == NULL){
    return (TRUE);
  }else{
    return (FALSE);
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
  PILHA pilha = p;

  if(pilhaVazia(p)){
    return p;
  }else{
    pilha = p -> prox;
  }

  return pilha;
}

void imprimirPilha(PILHA p){
  PILHA ap;
  ap = p;

  printf("\n Elementos da pilha");
  printf("\np\n|\n");
  while(ap != NULL){
    printf("\n%d\n|", ap -> dado);
  }
}

void opcoes(PILHA p) {
  int opt;
  int el;
  int items;

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
          *l1 = emilharElemento(*l1, el);
          opcoes(l1);
          break;
      case 2:
          printf("Informe o elemento que deseja retirar\n");
          fflush(stdin);
          scanf("%d", &el);
          *l1 = desempilharElemento(*l1, el); 
          opcoes(l1);
          break;
      case 3:
          *l1 = imprimirPilha(); 
          opcoes(l1);
          break;
      case 4:
          break;
      default:
          printf("Informe uma opcao valida!\n");
          opcoes(l1);
  }
}

int main(void) {
  opcoes(p); 
  return 0;
}