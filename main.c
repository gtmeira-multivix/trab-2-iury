#include <stdio.h>
#include <string.h>
#include "arvore.h"
Arvore* carregar_candidatos() {
  char linha[1024];
  FILE *arquivo = fopen("candidatos.csv", "r");
  
  //Descartar cabeçalho do arquivo:
  fgets(linha, 1024, arquivo);
  
  //Número da coluna que contém cada informação (0 é a primeira):
  int campoNome = 18;
  int campoNumero = 16;
  int campoCargo = 14;
  int totalCampos = 57;
  
  //Arvore que será preenchida;
  Arvore *a = NULL;
  
  //Ler enquanto houver linhas:
  while(!feof(arquivo)) {
    //Ler uma linha do arquivo:
    if(fgets(linha, 1024, arquivo) == 0) {
      break;
    }
    
    //Estrutura que iremos preencher:
    Candidato c;
    
    //Inicializar busca por tokens:
    char *delimitadores = "\";";
    char *token = strtok(linha, delimitadores);
    
    int i;
    for(i = 0; i < totalCampos; i++) {
      //Verificar se o campo atual é algum dos que nos interessa:
      if(i == campoNome) {
        strcpy(c.nome, token);
      } else if(i == campoNumero) {
        sscanf(token, "%d", &(c.numero));
      } else if(i == campoCargo) {
        strcpy(c.cargo, token);
      }
      
      //Avançar para o próximo token:
      token = strtok(NULL, delimitadores);
    }
    
    //Os campos do candidato foram preenchidos, vamos adicioná-lo à árvore:
    a = arvore_inserir(a, c);
  }
  
  //Retornar �rvore construída:
  return a;
}

void buscar_por_numero(Arvore *candidatos) {
    int candNumero;
	printf("Digite o numero: ");
	scanf("%d", &candNumero);
	
	if((arvore_buscar(candidatos,candNumero))==NULL){
		printf("Esse candidato nao existe! \n\n");
	}
		
	
}

void imprimir_todos(Arvore *candidatos) {
    arvore_imprime_em_ordem(candidatos);
}

int main() {
  Arvore *candidatos = carregar_candidatos();
  
  while(1) {
    printf("O que deseja fazer?\n[1] Buscar candidato por numero\n[2] Listar candidatos em ordem de numero\n[3] Sair\n\n>> ");
    int opcao;
    scanf("%d", &opcao);
    
    if(opcao == 1) {
      buscar_por_numero(candidatos);
    } else if(opcao == 2) {
      imprimir_todos(candidatos);
    } else if(opcao == 3) {
      return 0;
    } else {
      printf("Opcao invalida!\n");
    }
  }
}
