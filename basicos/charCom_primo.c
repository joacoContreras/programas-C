#include "charComp.h"

int char_comp(char c1, char c2){ // Definir funcion
	
	if (c1==c2 || c1== c2 + 32 || c1 == c2 - 32) {
		return True;
	} else {
		return False;
	}
}
	
	
