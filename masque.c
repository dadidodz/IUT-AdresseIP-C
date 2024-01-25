
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "masque.h"

void masque_reseau(int masque,int *reseau){
   int nb=masque/8;//nombre d'octets
   int reste=masque%8;
   int p=0;
   int puiss2[8];
   puiss2[0]=128;

//puissance de 2
   for(int i=1;i<8;i++){
      puiss2[i]=puiss2[i-1]/2;
   }

//calcul adresse de masque reseau
   for (int i=0;i<4;i++){
      if(nb>i){
         reseau[i]=255;
      }
      else if(reste!=0){
         reseau[i]=0;
         while(reste>0){
            reseau[i]=reseau[i]+puiss2[p];
            p++;
            reste--;
         }
      }
      else{
         reseau[i]=0;
      }
   }
}

void adresse_reseau(int *ipv4,int *reseau,int *s_reseau){
   int puiss2[8];
   puiss2[0]=128;
   int reste1;
   int reste2;

   //puissance de 2
   for(int i=1;i<8;i++){
      puiss2[i]=puiss2[i-1]/2;
   }

   //adresse de sous reseau
   for (int i=0;i<4;i++){

      reste1=ipv4[i];
      reste2=reseau[i];
      s_reseau[i]=0;

      for (int p=0;p<8;p++){
         if(reste1-puiss2[p]>=0 & reste2-puiss2[p]>=0){
            reste1=reste1-puiss2[p];
            reste2=reste2-puiss2[p];
            s_reseau[i]+=puiss2[p];
            
         }
         else if(reste1-puiss2[p]>=0){
            reste1=reste1-puiss2[p];
         }
         else if(reste2-puiss2[p]>=0){
            reste2=reste2-puiss2[p];
         }
      }
   }
}

void calc_partie_restante(int *reseau,int *p_rest){
   for(int i=0;i<4;i++){
      p_rest[i]=255-reseau[i];
   }
}