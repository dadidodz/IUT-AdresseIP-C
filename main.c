#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include "ip.h"
#include "fichier.h"
#include "validation.h"
#include "mask.h"

int main() {

	char adresse[20];
	int ip_v4[4];
	int reseau[4];
	int s_reseau[4];
	int p_rest[4];
	int hote[4];
	char *ip;
	char *ch;
	char *mask;
	int slash=-1;
	char *type;
	int masque=0;
	char *classe;



	printf("Saisissez l'adresse ip voulu avec ou sans masque:\n");
	scanf("%s", adresse);
	ch = adresse;

	separation_format(ch, &ip, &mask, &slash);
	switch (validation_format(&ip,&mask,&slash,ip_v4)){
	  
	case 1:
		  classe=classe_ip(ip_v4[0]);
		  type=type_ip(ip_v4[0],ip_v4[1],ip_v4[2],ip_v4[3]);
		  masque=attribution_masque_classe(ip_v4[0]);
		  if(masque!=0){
			 masque_reseau(masque,reseau);
			 adresse_reseau(ip_v4,reseau,s_reseau);
			 calc_partie_restante(reseau,p_rest);
			 adresse_reseau(ip_v4,p_rest,hote);
		  }
		  creation_fichier(ip_v4,masque,hote,s_reseau,reseau,p_rest,classe,type);
		  afficher_fichier();
		  break;
	case 2:
		masque = atoi(mask);
		classe=classe_ip(ip_v4[0]);
		type=type_ip(ip_v4[0],ip_v4[1],ip_v4[2],ip_v4[3]);
		masque_reseau(masque,reseau);
		adresse_reseau(ip_v4,reseau,s_reseau);
		calc_partie_restante(reseau,p_rest);
		adresse_reseau(ip_v4,p_rest,hote);
		creation_fichier(ip_v4,masque,hote,s_reseau,reseau,p_rest,classe,type);
		afficher_fichier();
		break;
	default:
		printf("\nLe format est invalide\n");
		break;
 
	}
}