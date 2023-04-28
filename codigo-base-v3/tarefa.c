/*
	Name: TaskMan
	Copyright: ISPTEC
	Author: joaojdacosta@gmail.com
	Date: 08/12/22 15:24
	Description: Software para gestão de tarefas.
*/

#include "tarefa.h"

void iniciar_tarefas (t_tarefas *k){
	k->t = 0;
}

int contar_tarefa_lista (t_tarefas k, int lista){
	int contador = 0, i;
	for(i = 0; i < k.t; i++)
		if(k.v[i].id_lista == lista)
			contador++;
	
	return contador;
}

int adicionar_tarefa (t_tarefas *k, t_tarefa t){
	
	// verificar a capacidade ... se há espaço ou não para armazenar
	if(k->t >= MAX) return 0;
	
	//t.id = k->t + 1;// contador global
	
	int x = contar_tarefa_lista (*k, t.id_lista);
	t.id = x + 1;// contador local
	
	t.estado = 0; // tarefa não concluida
	k->v[k->t] = t;
	
	k->t++;
	
	return 1;
}
