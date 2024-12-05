#include <stdio.h>
#include <stdlib.h>

typedef struct elemento{
  int dado;
  struct elemento *prox;
}*ApElemento;

typedef struct{
  ApElemento ini;
  ApElemento fim;
}Fila;

Fila criarFila(){
  Fila f;
  f.ini = NULL;
  f.fim = NULL;
  return f;
}

int filaVazia(Fila f){
  if(f.ini == NULL){
    return 1;
  }else{
    return 0;
  }
}

Fila inserirFIla(Fila f, int e){
  ApElemento novo;

  novo = malloc(sizeof(ApElemento));
  novo -> dado = e;
  novo -> prox = NULL;
  if(filaVazia(f)){
    f.ini = novo;
    f.fim = novo;
  }else{
    f.fim -> prox = novo;
    f.fim = novo;
  }

  return (f);
}

Fila retirarFila(Fila f, int *e){
  ApElemento af;
  if(!filaVazia(f)){
    *e = f.ini -> dado;
    af = f.ini;
    f.ini = f.ini -> prox;

    free(af);

    if(filaVazia(f)){
      f.fim = NULL;
    }
  }else{
    printf("Fila vazia.\n");
  }

  return f;
}

void imprimirFila(Fila f){
  ApElemento af;

  printf("Imprimindo elementos da fila.\n");
  af = f.ini;
  while(af != NULL){
    printf("%d -> ", af -> dado);
    af = af -> prox;
  }

  printf("\n");
}

void opcoes(Fila f) {
  int opt;
  int el;

  printf("Informe a opção que deseja: \n");
  printf("1. Adicionar elemento na fila\n");
  printf("2. Retirar elemento da fila\n");
  printf("3. Imprimir fila\n");
  printf("4. Sair\n");
  fflush(stdin);
  scanf("%i", &opt);

  switch(opt) {
      case 1:
          printf("Informe o elemento que deseja inserir\n");
          fflush(stdin);
          scanf("%d", &el);
          f = inserirFIla(f, el);
          opcoes(f);
          break;
      case 2:
          printf("Retirando elemento\n");
          f = retirarFila(f, &el); 
          opcoes(f);
          break;
      case 3:
          imprimirFila(f); 
          opcoes(f);
          break;
      case 4:
          break;
      default:
          printf("Informe uma opcao valida!\n");
          opcoes(f);
  }
}

int main(void) {
  Fila f;
  f = criarFila();
  opcoes(f); 
  return 0;
}
