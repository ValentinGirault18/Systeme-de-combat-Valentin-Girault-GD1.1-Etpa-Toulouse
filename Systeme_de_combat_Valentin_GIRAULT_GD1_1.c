#include <stdio.h>

int PDV=100; 

int attaqueSimple (int PDVcible){
	
	PDVcible=PDVcible-10;
	return PDVcible;
}

int main(){
	
	printf ("Vous avez %d points de vie \n",PDV);
	printf ("Vous subissez une attaque! -10 points de vie \n");
	PDV=attaqueSimple(PDV);
	printf ("Vous avez %d points de vie \n",PDV);
	
	
	return 0;
}