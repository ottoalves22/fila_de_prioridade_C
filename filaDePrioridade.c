/*********************************************************************/
/**   ACH2023 - Algoritmos e Estruturas de Dados I                  **/
/**   EACH-USP - Segundo Semestre de 2020                           **/
/**   <turma> - Prof. Luciano Antonio Digiampietri                  **/
/**                                                                 **/
/**   EP1 - Fila de Prioridade                                      **/
/**                                                                 **/
/**   Otto Alves                   10843361          **/
/**                                                                 **/
/*********************************************************************/
/*********************************************************************/
/**   ACH2023 - Algoritmos e Estruturas de Dados I                  **/
/**   EACH-USP - Segundo Semestre de 2020                           **/
/**   <turma> - Prof. Luciano Antonio Digiampietri                  **/
/**                                                                 **/
/**   EP1 - Fila de Prioridade                                      **/
/**                                                                 **/
/**   Otto Alves                   10843361          **/
/**                                                                 **/
/*********************************************************************/

#include "filaDePrioridade.h"

PFILA criarFila(int max){
  PFILA res = (PFILA) malloc(sizeof(FILADEPRIORIDADE));
  res->maxElementos = max;
  res->arranjo = (PONT*) malloc(sizeof(PONT)*max);
  int i;
  for (i=0;i<max;i++) res->arranjo[i] = NULL;
  PONT cabeca = (PONT) malloc(sizeof(ELEMENTO));
  res->fila = cabeca;
  cabeca->ant = cabeca;
  cabeca->prox = cabeca;
  cabeca->id = -1;
  cabeca->prioridade = 1000000;
  return res;
}

void exibirLog(PFILA f){
  printf("Log [elementos: %i (alem do no cabeca)]\n", tamanho(f));
  PONT atual = f->fila;
  printf("%p[%i;%f;%p]%p ", atual->ant, atual->id, atual->prioridade, atual, atual->prox);
  atual = atual->prox;
  while (atual != f->fila){
    printf("%p[%i;%f;%p]%p ", atual->ant, atual->id, atual->prioridade, atual, atual->prox);
    atual = atual->prox;
  }
  printf("\nElementos validos: ");
  atual = atual->prox;
  while (atual != f->fila){
    printf("[%i;%f;%p] ", atual->id, atual->prioridade, atual);
    atual = atual->prox;
  }

  printf("\nValores do arrajo:\n\[ ");
  int x;
  for (x=0;x<f->maxElementos;x++) printf("%p ",f->arranjo[x]);
  printf("]\n\n");
}

/* recebe endereço de uma fila e retorna numero de elementos validos (lista sem contar o vigilante) */
int tamanho(PFILA f){
  int tam = 0;
  PONT end = f->fila->prox;
  while(end != f->fila){
    tam++;
    end = end->prox;
  }
  return tam;
}

PONT buscaSeq(PFILA l, int id){
  PONT atual = l->fila->prox;
  while (atual->id<id && atual->id > -1) atual = atual->prox;
  if (atual != l->fila && atual->id == id) return atual;
  return NULL;
}

/* Recebe o endereço de uma fila de prioridade, oidentificador do novo elemento e o valor de sua prioridade.
return false se:
  - o identificador seja inválido (menor que zero ou maior ou igual a maxElementos);
  - o identificador seja válido, mas já houver um elemento com esse identificador na fila
*/
bool inserirElemento(PFILA f, int id, float prioridade){
  bool resposta = false;
  PONT ant, aux;
  aux = buscaSeq(f, id);
  if (id < 0 || id > f->maxElementos || prioridade > 999999 || aux != NULL) return resposta;
  //aux = buscaAux(f, prioridade, &ant);
  aux = (PONT) malloc(sizeof(ELEMENTO));
  aux->id = id;
  aux->prioridade = prioridade;
  aux->prox = NULL;
  ant = f->fila;
  if (ant->prox == NULL) {
    ant->prox = aux;
  }
  else {
    while (ant->prox != f->fila && ant->prox->prioridade >= prioridade){
      ant = ant->prox;
    }
    aux->prox = ant->prox;
    aux->ant = ant;
    ant->prox = aux;
    (aux->prox)->ant = aux;

  }
  //preciso inverter a insercao, ta crescente e tem de ser decrescente
  f->arranjo[aux->id] = aux;
  resposta = true;
  return resposta;
}



bool aumentarPrioridade(PFILA f, int id, float novaPrioridade){
  bool resposta = false;

  /* COMPLETAR */

  return resposta;
}



bool reduzirPrioridade(PFILA f, int id, float novaPrioridade){
  bool resposta = false;

  /* COMPLETAR */

  return resposta;
}



PONT removerElemento(PFILA f){
  PONT resposta = NULL;
  if(f->fila->prox == f->fila) return resposta;
  resposta = f->fila->prox;
  (resposta->prox)->ant = f->fila;
  (f->fila)->prox = resposta->prox;
  f->arranjo[resposta->id] = NULL;
  return resposta;
}



bool consultarPrioridade(PFILA f, int id, float* resposta){
  bool resp = false;

  /* COMPLETAR */

  return resp;
}
