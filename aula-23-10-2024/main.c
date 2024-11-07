#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct{
  float nota1;
  float nota2;
  float media;
}NOTA;

typedef struct{
  char nome[40];
  int matricula;
  int faltas;
  NOTA notas;
  char situacao[15];
}ALUNO;

ALUNO turma[40];
int indice = 0;
void opcoes(void);
void inserirDados(int);
void exibirDados(void);
void salvarDados(void);
void carregarDados(void);
void sair(void);

int main(void){

  opcoes();
}

void opcoes(){
  int opt;
  printf("Informe a opção que deseja: \n");
  printf("1. Inserir alunos\n");
  printf("2. Exibir alunos\n");
  printf("3. Salvar dados\n");
  printf("4. Carregar dados\n");
  printf("5. Sair\n");
  scanf("%i", &opt);

  switch(opt){
    case 1:
      inserirDados(indice);
      indice++;
      opcoes();
      break;
    case 2:
      exibirDados();
      opcoes();
      break;
    case 3:
      salvarDados();
      opcoes();
      break;
    case 4:
      carregarDados();
      opcoes();
      break;
    case 5:
      break;
    default:
      printf("Informe uma opcao valida!\n");
      main();
  }
}

void inserirDados(int indice){
  ALUNO aluno;
  printf("Informe o nome do aluno: ");
  scanf("%s", aluno.nome);
  printf("Informe a matricula: ");
  scanf("%i", &aluno.matricula);
  printf("Informe a primeira nota: ");
  scanf("%f", &aluno.notas.nota1);
  printf("Informe a segunda nota: ");
  scanf("%f", &aluno.notas.nota2);
  aluno.notas.media = (aluno.notas.nota1 + aluno.notas.nota2) / 2;
  printf("Informe o numero de faltas: ");
  scanf("%i", &aluno.faltas);

  if(aluno.notas.media >= 6 && aluno.faltas <=20){
    strcpy(aluno.situacao, "Aprovado");
  }else{
    strcpy(aluno.situacao, "Reprovado");
  }

  turma[indice] = aluno;
}

void exibirDados(void){
  int i = 0;
    while(i < indice){
      printf("Nome: %s\n", turma[i].nome);
      printf("Matrícula: %i\n", turma[i].matricula);
      printf("Nota 1: %f\n", turma[i].notas.nota1);
      printf("Nota 2: %f\n", turma[i].notas.nota2);
      printf("Media: %f\n", turma[i].notas.media);
      printf("Faltas: %i\n", turma[i].faltas);
      printf("Situação: %s\n", turma[i].situacao);
      printf("-----------------------------------\n");
      i++;
    }
}

void salvarDados(void){
  FILE *arquivo = fopen("alunosArquivo.txt", "a");
  int i;
  char linha[70] = "";

  if(arquivo == NULL){
    perror("Erro ao abrir o arquivo");
    opcoes();
  }else{
    //fwrite(&turma[0], sizeof(ALUNO), indice, arquivo);
    for(i = 0; i < indice; i++){
      fprintf(arquivo, "%s %i %f %f %f %i %s\n", turma[i].nome, turma[i].matricula, turma[i].notas.nota1, turma[i].notas.nota2, turma[i].notas.media, turma[i].faltas, turma[i].situacao);
    }
  }

  fclose(arquivo);
}

void carregarDados(void){
  FILE *arquivo = fopen("alunosArquivo.txt", "r");
  int i = 0;
  ALUNO aluno;
  if(arquivo == NULL){
    perror("Erro ao abrir o arquivo");
  }else{
    while(fscanf(arquivo, "%s %d %f %f %f %d %s", aluno.nome, &aluno.matricula, &aluno.notas.nota1, &aluno.notas.nota2, &aluno.notas.media, &aluno.faltas, aluno.situacao) == 7) {
      turma[i] = aluno;
      i++;
    }
    indice = i;
  }
  fclose(arquivo);
}
