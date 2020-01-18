#include <stdio.h>

int PDVmonstre=150; 
int PDVjoueur=100;
int ChoixAttaque=0;


int attaqueSimple (int PDVcible){
	
	PDVcible=PDVcible-10;
	return PDVcible;
}

int main(){
	
	printf("Vous avez %d points de vie \n",PDVjoueur); 
	printf("Un monstre apparait! Il a %d points de vie! \n",PDVmonstre); 
	
	while (PDVmonstre>1){
		
		
		printf(" taper (1) pour attaquer/ (2) pour vous defendre/ (3) pour empoisonner \n");
		scanf("%d",&ChoixAttaque);
		while(ChoixAttaque!=1){
			printf("l'attaque numero %d n'existe pas! \n",ChoixAttaque);
			scanf ("%d taper (1) pour attaquer/ (2) pour ce defendre/ (3) pour empoisonner \n",&ChoixAttaque);
		}
		if (ChoixAttaque==1){
			printf ("Le monstre a %d points de vie \n",PDVmonstre);
			printf ("Vous attaquez a l'aide de votre katana! le monstre subie -10 points de vie \n");
			PDVmonstre=attaqueSimple(PDVmonstre);
			printf ("Le monstre a %d points de vie \n",PDVmonstre);
			}
			
		printf("Le monstre vous attaque! Vous subissez -10 points de vie! \n \n");
		PDVjoueur=attaqueSimple(PDVjoueur);
		printf ("Vous avez %d points de vie \n",PDVjoueur);
	}
	
	
	return 0;
}