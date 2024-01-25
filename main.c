#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "ip.h"
#include "validate.h"
#include "fichier.h"
#include "masque.h"

int main() {
//déclaration des variables
   char adresse[20];
   int ipv4[4];
   int reseau[4];
   int p_rest[4];
   int s_reseau[4];
   int hote[4];
   char *ip;
   char *mask;
   char *ch;
   int slash=-1;
   char *classe;
   char *type;
   int masque=0;

//entrée de l'adresse IP
   printf("Saisissez l'ip souhaitée(avec ou sans masque au format IPV4):\n");
   scanf("%s", adresse);
   ch = adresse;


//vérification du format
 //segmentation ip/masque
  separation_format(ch, &ip, &mask, &slash);
  //validation du format
  switch (validation_format(&ip,&mask,&slash,ipv4)){

   case 1:
      masque = atoi(mask);
      classe=classe_ip(ipv4[0]);
      type=type_ip(ipv4[0],ipv4[1],ipv4[2],ipv4[3]);
      masque_reseau(masque,reseau);
      adresse_reseau(ipv4,reseau,s_reseau);
      calc_partie_restante(reseau,p_rest);
      adresse_reseau(ipv4,p_rest,hote);
      creation_fichier(ipv4,masque,hote,s_reseau,reseau,p_rest,classe,type);
      afficher_fichier();
      break;

   case 2:
      classe=classe_ip(ipv4[0]);
      type=type_ip(ipv4[0],ipv4[1],ipv4[2],ipv4[3]);
      masque=attribution_masque_classe(ipv4[0]);
      if(masque!=0){
         masque_reseau(masque,reseau);
         adresse_reseau(ipv4,reseau,s_reseau);
         calc_partie_restante(reseau,p_rest);
         adresse_reseau(ipv4,p_rest,hote);
      }
      creation_fichier(ipv4,masque,hote,s_reseau,reseau,p_rest,classe,type);
      afficher_fichier();
      break;

   default:
      printf("\nFormat invalide\n");
      break;
   }
}