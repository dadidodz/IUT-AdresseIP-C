#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "fichier.h"

void creation_fichier(int *ipv4,int masque,int *hote,int *s_reseau,int *reseau,int *p_rest,char *classe_ip,char *type_ip){
   FILE* fic;

   fic = fopen("ip.txt", "w");
   if (fic == NULL) {
      printf("Erreur à l'ouverture du fichier texte\n");
   } else {
      fprintf(fic, "Adresse renseigné:%d.%d.%d.%d/%d\n\n",ipv4[0] ,ipv4[1] ,ipv4[2] ,ipv4[3] ,masque);
      fprintf(fic,"Etude de l'IP:%d.%d.%d.%d\n",ipv4[0] ,ipv4[1] ,ipv4[2] ,ipv4[3]);
      fprintf(fic, "Classe:%s\n", classe_ip);
      fprintf(fic, "Type:%s\n\n", type_ip);
      fprintf(fic, "Etude du masque:%d\n",masque);
      if(masque!=0){
         fprintf(fic, "Adresse Masque:%d.%d.%d.%d\n", reseau[0] ,reseau[1] ,reseau[2] ,reseau[3]);
         fprintf(fic, "Adresse Reseau:%d.%d.%d.%d\n", s_reseau[0] ,s_reseau[1] ,s_reseau[2] ,s_reseau[3]);
         fprintf(fic, "Partie restante:%d.%d.%d.%d\n", p_rest[0] ,p_rest[1] ,p_rest[2] ,p_rest[3]);
         fprintf(fic, "Adresse Hote:%d.%d.%d.%d\n\n", hote[0] ,hote[1] ,hote[2] ,hote[3]);
      }
      else{
         fprintf(fic, "Adresse Reseau:ERROR NO MASK\n");
         fprintf(fic, "Adresse Hote:ERROR NO MASK\n");
      }

      fclose(fic);
   }
}

void afficher_fichier(){
   FILE* fic;
   fic = fopen("ip.txt", "r");
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