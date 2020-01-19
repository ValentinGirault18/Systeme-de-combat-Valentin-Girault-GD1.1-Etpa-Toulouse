#include <stdio.h>
#include <stdlib.h>

int PDVmonstre=250; 
int PDVjoueur=200;
int ChoixAttaque=0;
int ChoixMonstre=0;
int degatJoueur=20;
int degatMonstre=20;

int PMmonstre=20;
int PMjoueur=20;

int nbToursPoisonJoueur=0;
int nbToursPoisonMonstre=0;

int attaqueJoueur (int PDVciblej){
	
	PDVciblej=PDVciblej-degatJoueur;
	return PDVciblej;
}
int attaqueMonstre (int PDVcibleM){
	
	PDVcibleM=PDVcibleM-degatMonstre;
	return PDVcibleM;
}
int poison (int PDVcibleMpoison){
	
	PDVcibleMpoison=PDVcibleMpoison-5;
	return PDVcibleMpoison;
}


int main(){
	
	printf("Vous avez %d points de vie \n",PDVjoueur); 
	printf("Vous avez %d points de magie! \n",PMjoueur); 
	printf("Un monstre apparait! Il a %d points de vie! \n",PDVmonstre); 
	
	while (PDVmonstre>1 && PDVjoueur>1){
		
		if(nbToursPoisonMonstre>=1){
			
		printf("Vous subissez -5 degats a cause du poison! \n");	
	    PDVjoueur=poison(PDVjoueur);
		printf("Vous avez %d points de vie \n \n",PDVjoueur);
		
		nbToursPoisonMonstre=nbToursPoisonMonstre-1;
		}
		
		
	    printf (" taper (1) pour attaquer/ (2) pour ce defendre/ (3) pour empoisonner, empoisonner coute 10 points de magie / (4) pour lancer un sort d'antidote qui coute 2PM\n");
		scanf("%d",&ChoixAttaque);
		while(ChoixAttaque!=1 && ChoixAttaque!=2 && ChoixAttaque!=3 && ChoixAttaque!=4 ){
			printf("l'attaque numero %d n'existe pas! \n",ChoixAttaque);
			printf (" taper (1) pour attaquer/ (2) pour ce defendre/ (3) pour empoisonner, empoisonner coute 10 points de magie \n");
			scanf ("%d",&ChoixAttaque);
		}
		if (ChoixAttaque==1){
			printf ("Le monstre a %d points de vie \n",PDVmonstre);
			printf("Vous avez %d points de vie \n",PDVjoueur); 
			printf("Vous avez %d points de magie! \n",PMjoueur); 
			printf ("Vous attaquez a l'aide de votre katana! le monstre subie %d points de vie \n",degatMonstre);
			PDVmonstre=attaqueMonstre(PDVmonstre);
			printf ("Le monstre a %d points de vie \n",PDVmonstre);
			
			if (nbToursPoisonJoueur>0){
				printf ("Le monstre est sous l'effet du poison pour %d tours. \n",nbToursPoisonJoueur);
				}
			}
		if (ChoixAttaque==2){
			printf ("Le monstre a %d points de vie \n",PDVmonstre);
			printf("Vous avez %d points de vie \n",PDVjoueur); 
			printf("Vous avez %d points de magie! \n",PMjoueur); 
			printf ("Vous vous defendez! Vous subirez moins de degats lors de la prochaine attaque du monstre \n \n");
			degatJoueur=5;
			
			if (nbToursPoisonJoueur>0){
				printf ("Le monstre est sous l'effet du poison pour %d tours. \n",nbToursPoisonJoueur);
				}
			
		}
		if (ChoixAttaque==3){
			if(PMjoueur>=5){
				printf ("Le monstre a %d points de vie \n",PDVmonstre);
				printf("Vous avez %d points de vie \n",PDVjoueur); 
				printf("Le monstre %d points de magie! \n",PMmonstre); 
				printf ("Vous lancez un sort de poison au monstre! Il perdra -5 points de vie par tours pendant 5 tours!  \n \n");
				nbToursPoisonJoueur=nbToursPoisonJoueur+5;
				PMjoueur=PMjoueur-5;
				printf("Vous avez %d points de magie! \n",PMjoueur); 
				
				if (nbToursPoisonJoueur>0){
				printf ("Le monstre est sous l'effet du poison pour %d tours. \n",nbToursPoisonJoueur);
				}
			}
			else{
				printf(" taper (1) pour attaquer/ (2) pour vous defendre/ (3) pour empoisonner \n");
		        scanf("%d",&ChoixAttaque);
			}
		}
		
		if (ChoixAttaque==4){
			
			if (PMjoueur>=2) {
				
				printf ("Le monstre a %d points de vie \n",PDVmonstre);
				printf("Vous avez %d points de vie \n",PDVjoueur); 
				printf("Le monstre %d points de magie! \n",PMmonstre); 
				printf ("Vous lancez un sort d'antidote! Vous n'etes plus sous l'effet du poison! Vous perdez -2 points de magie.  \n \n");
				nbToursPoisonMonstre=0;
				
				PMjoueur=PMjoueur-2;
				printf("Vous avez %d points de magie! \n",PMjoueur); 

				if (nbToursPoisonJoueur>0){
				printf ("Le monstre est sous l'effet du poison pour %d tours. \n",nbToursPoisonJoueur);
				}				
				
			}
		}
		
		
		PMjoueur=PMjoueur+1;
		printf("Vous recouvrez un points de magie! Vous avez %d points de magie. \n \n",PMjoueur);
		
		degatMonstre=20;
		
		ChoixMonstre = rand()%3+1;
		
		
		
		if(nbToursPoisonJoueur>=1){
			
		printf("Le monstre subit -5 degats a cause du poison! \n");	
	    PDVmonstre=poison(PDVmonstre);
		printf("Le monstre a %d points de vie. \n",PDVmonstre);
		
		nbToursPoisonJoueur=nbToursPoisonJoueur-1;
		}
		
		if (ChoixMonstre==1){
			printf("Le monstre vous attaque! Vous subissez %d points de vie! \n",degatJoueur);
			PDVjoueur=attaqueJoueur(PDVjoueur);
			printf ("Vous avez %d points de vie \n",PDVjoueur);
			printf("Vous avez %d points de magie! \n",PMjoueur); 
			degatJoueur=20;
	    }
		if(ChoixMonstre==2){
			printf("Le monstre ce defend, il subira moins de degat au prochain tour \n");
			printf ("Vous avez %d points de vie \n",PDVjoueur);
			printf("Vous avez %d points de magie! \n",PMjoueur); 
			degatMonstre=5;
		}
		if (ChoixMonstre==3){
			if(PMmonstre>=5){
				printf("Le monstre a %d points de magie! \n",PMmonstre); 
				printf ("Le monstre vous lance un sort de poison! Vous perdrez -5 points de vie par tours pendant 3 tours!  \n \n");
				nbToursPoisonMonstre=nbToursPoisonMonstre+3;
				PMmonstre=PMmonstre-5;
				printf("Vous avez %d points de magie! \n \n \n \n",PMjoueur); 
			}
			else{
			ChoixMonstre = rand()%3+1;
			}
		}
	}
	
	if (PDVmonstre<0){
		printf("Vous avez REUSSI!");
	}
	if(PDVjoueur<0){
		printf("Vous etes mort!");
	}
	
	return 0;
}