#include "stack.h"

//Inizializzazione dello Stack di MAX_stack elementi
STACK stack_init() {
	STACK pila = NULL;
    if((pila = (int **)calloc(MAX_stack, sizeof(int *))))	{
		if(!(pila[0] = (int *)malloc(sizeof(int))))	{
			printf("[MEM] ATTENZIONE: Problema di allocazione STACKel - stack_init\n");
			exit(1);
		}
		*(pila[0]) = 0;
	} else  {
		printf("[MEM] ATTENZIONE: Problema di allocazione STACK - stack_init\n");
		exit(1);
	}
    return pila;
}


//Inserimento in testa dell'elemento nello Stack
void stack_push(STACK pila, int key){
	if(!stack_isFull(pila)){
		*(pila[0]) += 1;
		if(!(pila[*(pila[0])] = (int *)malloc(sizeof(int))))	{
			printf("[MEM] ATTENZIONE: Problema di allocazione STACKel - stack_push\n");
			exit(1);
		}
		*(pila[*(pila[0])]) = key;
	} else 
		printf("[STACK] ATTENZIONE: lo Stack è pieno - stack_push\n\n");
}


//Estrazione dell'elemento in testa allo Stack
int stack_pop(STACK pila)	{
	if(!stack_isEmpty(pila))	{
		int val = *(pila[*(pila[0])]);
		pila[*(pila[0])] = stack_freeNode(pila[*(pila[0])]);
		*(pila[0]) -= 1;
		return val;
	} else {
		printf("[STACK] ATTENZIONE: lo Stack è vuoto - stack_pop\n\n");
		return 0;
	}
}

//Visualizzazione dell'elemento in testa allo Stack
int stack_top(STACK pila)	{
	if(!stack_isEmpty(pila))	{
		return *(pila[*(pila[0])]);;
	} else {
		printf("[STACK] ATTENZIONE: lo Stack è vuoto - stack_pop\n\n");
		return 0;
	}
}

//Liberazione efficiente della memoria allocata dinamicamente
STACK stack_free(STACK pila, int del_complete)	{   //il parametro 'del_complete' == 1 libera memoria in fase di chiusura dell'applicazione
    int idx;
    for(idx=1;idx<=*(pila[0]);idx++)	      //ciclo solo fino all'ultima riga 
        pila[idx] = stack_freeNode(pila[idx]);   //libero il vertice dallo Stack

    if(del_complete) {  //se sto chiudendo l'applicazione
        free(pila[0]);  //dealloco il numero di elementi del stack
	    free(pila);     //dealloco il stack
        return NULL;
    } else  //se l'utente decide di eliminare il stack
        *(pila[0]) = 0; //resetto il numero di elementi del stack
	return pila;
}


//Deallocazione del nodo estratto
STACKel stack_freeNode(STACKel curr)	{
	free(curr);
	return NULL;
}


//Stampa dello Stack 
void stack_print(STACK pila){
	int key;
	if(!stack_isEmpty(pila)){
		key = stack_pop(pila);
		printf("%d\n", key);
		stack_print(pila);
		stack_push(pila, key);
	}
}


//Controllo dello Stack pieno
int stack_isEmpty(STACK pila){
	if(*(pila[0]) == 0)
		return 1;
	return 0;
}


//Controllo dello Stack vuoto
int stack_isFull(STACK pila){
	if(*(pila[0]) == MAX_stack)
		return 1;
	return 0;
}