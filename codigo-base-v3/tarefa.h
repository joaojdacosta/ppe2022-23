/*
	Name: TaskMan
	Copyright: ISPTEC
	Author: joaojdacosta@gmail.com
	Date: 08/12/22 15:24
	Description: Software para gestão de tarefas.
*/

#define MAX 100

typedef struct {
	int id;  // identificador
	char descricao[30]; // descrição
	int importante; // 0 - não é importante, 1 - é importante
	int hoje; // 0 - significa que a tarefa não é para hoje e 1 significa....
	char prazo[100]; // data "15/12/2022", 15122022
	int estado; // concluiu (1) a tarefa ou nao(0) 
	int id_lista; // identifica a lista
}t_tarefa;

typedef struct {
	t_tarefa v[MAX]; // conjunto de 7 listas
	int t; // numero de elementos adicionados em v
} t_tarefas;

void iniciar_tarefas (t_tarefas *);
int adicionar_tarefa (t_tarefas *, t_tarefa);
int contar_tarefa_lista (t_tarefas, int lista);




