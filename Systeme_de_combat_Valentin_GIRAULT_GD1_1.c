#include <stdio.h>
#include <stdlib.h>

int PDVmonstre=300; 
int PDVjoueur=200;
int ChoixAttaque=0;
int ChoixMonstre=0;
int degatJoueur=20;
int degatMonstre=20;

int attaqueJoueur (int PDVciblej){
	
	PDVciblej=PDVciblej-degatJoueur;
	return PDVciblej;
}
int attaqueMonstre (int PDVcibleM){
	
	PDVcibleM=PDVcibleM-degatMonstre;
	return PDVcibleM;
}


int main(){
	
	printf("Vous avez %d points de vie \n",PDVjoueur); 
	printf("Un monstre apparait! Il a %d points de vie! \n",PDVmonstre); 
	
	while (PDVmonstre>1 || PDVjoueur>1){
		
		
		printf(" taper (1) pour attaquer/ (2) pour vous defendre/ (3) pour empoisonner \n");
		scanf("%d",&ChoixAttaque);
		while(ChoixAttaque!=1 && ChoixAttaque!=2 && ChoixAttaque!=3 ){
			printf("l'attaque numero %d n'existe pas! \n",ChoixAttaque);
			printf (" taper (1) pour attaquer/ (2) pour ce defendre/ (3) pour empoisonner \n");
			scanf ("%d",&ChoixAttaque);
		}
		if (ChoixAttaque==1){
			printf ("Le monstre a %d points de vie \n",PDVmonstre);
			printf ("Vous attaquez a l'aide de votre katana! le monstre subie %d points de vie \n",degatMonstre);
			PDVmonstre=attaqueMonstre(PDVmonstre);
			printf ("Le monstre a %d points de vie \n",PDVmonstre);
			}
		if (ChoixAttaque==2){
			printf ("Le monstre a %d points de vie \n",PDVmonstre);
			printf ("Vous vous defendez! Vous subirez moins de degats lors de la prochaine attaque du monstre \n \n");
			degatJoueur=5;
			
		}
		degatMonstre=20;
		
		ChoixMonstre = rand()%2+1;
		
		if (ChoixMonstre==1){
			printf("Le monstre vous attaque! Vous subissez %d points de vie! \n",degatJoueur);
			PDVjoueur=attaqueJoueur(PDVjoueur);
			printf ("Vous avez %d points de vie \n",PDVjoueur);
			degatJoueur=20;
	    }
		if(ChoixMonstre==2){
			printf("Le monstre ce defend, il subira moins de degat au prochain tour \n");
			printf ("Vous avez %d points de vie \n",PDVjoueur);
			degatMonstre=5;
		}
		
	}
	
	if (PDVmonstre<0){
		printf("Victoire!");
	}
	if(PDVjoueur<0){
		printf("Vous etes mort!");
	}
	
	return 0;
}