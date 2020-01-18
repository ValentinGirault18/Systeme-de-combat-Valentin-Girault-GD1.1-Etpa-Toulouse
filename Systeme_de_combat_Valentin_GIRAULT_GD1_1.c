#include <stdio.h>

int PDVmonstre=300; 
int PDVjoueur=200;
int ChoixAttaque=0;
int degat=20;

int attaqueSimple (int PDVcible){
	
	PDVcible=PDVcible-degat;
	return PDVcible;
}

int main(){
	
	printf("Vous avez %d points de vie \n",PDVjoueur); 
	printf("Un monstre apparait! Il a %d points de vie! \n",PDVmonstre); 
	
	while (PDVmonstre>1){
		
		
		printf(" taper (1) pour attaquer/ (2) pour vous defendre/ (3) pour empoisonner \n");
		scanf("%d",&ChoixAttaque);
		while(ChoixAttaque!=1 && ChoixAttaque!=2 && ChoixAttaque!=3 ){
			printf("l'attaque numero %d n'existe pas! \n",ChoixAttaque);
			scanf ("%d taper (1) pour attaquer/ (2) pour ce defendre/ (3) pour empoisonner \n",&ChoixAttaque);
		}
		if (ChoixAttaque==1){
			printf ("Le monstre a %d points de vie \n",PDVmonstre);
			printf ("Vous attaquez a l'aide de votre katana! le monstre subie %d points de vie \n",degat);
			PDVmonstre=attaqueSimple(PDVmonstre);
			printf ("Le monstre a %d points de vie \n",PDVmonstre);
			}
		if (ChoixAttaque==2){
			printf ("Le monstre a %d points de vie \n",PDVmonstre);
			printf ("Vous vous defendez! Vous subirez moins de degats lors de la prochaine attaque du monstre \n \n");
			degat=5;
			
		}
		
		printf("Le monstre vous attaque! Vous subissez %d points de vie! \n",degat);
		PDVjoueur=attaqueSimple(PDVjoueur);
		printf ("Vous avez %d points de vie \n",PDVjoueur);
		degat=20;
	}
	
	
	return 0;
}