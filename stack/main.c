#include <stdio.h>
#include <time.h>

#include "stack_func.h"

int main()  {
    srand(time(NULL));		//funzione per la generazione casuale di valori
	
	stack_func_main();
	io_clearScreen();

	return 1;
}
