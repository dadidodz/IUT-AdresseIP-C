#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "fichier.h"

void creer_fichier(int *ip, int masque, int *hote, int *reseau, int *reste, int *adreseau, char *classe, char *type){
   FILE* fic;
   fic = fopen("adresseip.txt", "wx");
   if (fic == NULL) {
      printf("Ouverture impossible\n");
	} else {
	   fprintf(fic, "Classe : %s\n", classe);
	   fprintf(fic, "Public / Prive : %s\n\n", type);
	   fprintf(fic, "Adresse donnee  :%d.%d.%d.%d/%d\n\n",ip[0] ,ip[1] ,ip[2] ,ip[3] ,masque);
	   fprintf(fic, "IP : %d.%d.%d.%d\n",ip[0] ,ip[1] ,ip[2] ,ip[3]);
	   if(masque!=0){
		   fprintf(fic, "Adresse masque : %d.%d.%d.%d\n", reseau[0] ,reseau[1] ,reseau[2] ,reseau[3]);
		   fprintf(fic, "Adresse reseau : %d.%d.%d.%d\n", adreseau[0] ,adreseau[1] ,adreseau[2] ,adreseau[3]);
		   fprintf(fic, "Reste : %d.%d.%d.%d\n", reste[0] ,reste[1] ,reste[2] ,reste[3]);
		   fprintf(fic, "Adresse hote : %d.%d.%d.%d\n\n", hote[0] ,hote[1] ,hote[2] ,hote[3]);
		} else {
			fprintf(fic, "Adresse reseau : pas de masque\n");
			fprintf(fic, "Adresse hote : pas de masque\n");
		}
	fclose(fic);
   }
}

void afficher_fic(){
   FILE* fic;
   fic = fopen("adresseip.txt", "rx");
   if (fic != NULL) {
      char* ligne = NULL;
      size_t taille = 0;
      getline(&ligne, &taille, fic);
      while (!feof(fic)) {
		  printf("%s", ligne);
		  getline(&ligne, &taille, fic);
      }
   free(ligne);
   fclose(fic);
   }

}