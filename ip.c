#include "ip.h"

char * classe_ip(int ip1){
   if(ip1<=126 & ip1>=0){
      return "A";
   }
   else if(ip1==127){
      return "L";
   }
   else if(ip1>=128 & ip1<=191 ){
      return "B";
   }
   else if(ip1>=192 & ip1<=223 ){
      return "C";
   }
   else if(ip1>=224 & ip1<=239 ){
      return "D";
   }
   else{
      return "E";
   }

}

char * type_ip(int ip1,int ip2,int ip3,int ip4){
   if(classe_ip(ip1)=="A"){
      if(ip1==10){
         return "Privé";
      }
      else{
         return "Publique";
      }
   }
   else if(classe_ip(ip1)=="B"){
      if(ip1==172 & ip2>=16 & ip2<=31){
         return "Privé";
      }
      else{
         return "Publique";
      }
   }
   else if(classe_ip(ip1)=="C"){
      if(ip1==192 & ip2==168){
         return "Privé";
      }
      else{
         return "Publique";
      }
   }
   else if(classe_ip(ip1)=="L"){
      return "Localhost";
   }
   else if(ip1>=224 & ip1<=239){
      return "Multicast";
   }
   else if(ip1!=0 & ip2!=0 & ip3!=0 & ip4!=0 ){
      return "Publique";
   }
}

int attribution_masque_classe(int ip1){
      if(classe_ip(ip1)=="A" || classe_ip(ip1)=="L" ){
         return 8;
      }
      if(classe_ip(ip1)=="B"){
         return 16;
      }
      if(classe_ip(ip1)=="C"){
         return 24;
      }
      return 0;
}