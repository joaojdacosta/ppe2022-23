/*
	Name: TaskMan
	Copyright: ISPTEC
	Author: joaojdacosta@gmail.com
	Date: 08/12/22 15:24
	Description: Software para gest�o de tarefas.
*/

#include "lista.h"
#include <string.h>

void iniciar (t_listas *l){
	l->v[0].id = 4;
	strcpy(l->v[0].nome,"Tarefas");
	l->v[0].fixo = 1;
	
	l->t = 1;
}

/**
Adicionar uma nova lista em listas
*/
int adicionar(t_listas *k, char nome[30]){
	
	if(k->t >= 7) return 0; // nao foi possivel adicionar
	
	// garantir que os nomes n�o se repitam
	int i;
	for(i = 0; i < k->t; i++)
		if(strcmp(k->v[i].nome,nome) == 0)
			return 0;
	
	k->v[k->t].id = k->t + 4;
	//k->v[k->t].id = k->v[k->t - 1].id + 1;
	strcpy(k->v[k->t].nome,nome);
	k->v[k->t].fixo = 0;
	
	k->t++; //6
	
	return 1; // adicionado com sucesso
}

int remover(t_listas *k, int id){
	
	/*ToDo: Verificar os limites do buffer*/
	if (id <= 4) return 0; // n�o � possivel remover
	
	// determinar o index
	id = id - 4;

	int i;
	for(i = id; i < k->t; i++)
		k->v[i] = k->v[i + 1];
	k->t--;
	return 1; // removido com sucesso
}
