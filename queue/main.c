#include <stdio.h>
#include <time.h>

#include "queue_func.h"

int main()  {
    srand(time(NULL));		//funzione per la generazione casuale di valori
	
	queue_func_main();
	io_clearScreen();
	
	return 1;
}
