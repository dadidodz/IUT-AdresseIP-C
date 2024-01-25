#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "validate.h"
int validate_number(char *str) {
   while (*str) {
      if(!isdigit(*str)){
         return 0;
      }
      str++; 
   }
   return 1;
}

int validate_ip(char *ip,int *ptid,size_t size) {
   int num, dots = 0;
   char *ptr;
   size_t i = 0;
   if (ip == NULL){
      return 0;
   }
   ptr = strtok(ip, ".");
   if (ptr == NULL){
      return 0;
   }
   while (ptr) {
      if (!validate_number(ptr)){
         return 0;
      }
      num = atoi(ptr);
      if (num >= 0 && num <= 255) {
         //mise dans un tableau d'int des différentes parties
            ptid[i++]=num;
            ptr = strtok(NULL, ".");
            if (ptr != NULL){
               dots++;
            }
         } 
         else{
            return 0;
            }
    }
    if (dots != 3){
       return 0;
    }
      return 1;
}

int validate_mask(char *mask){
   int num;
   if(mask==NULL){
      return 0;
   }
   if (!validate_number(mask)){
      return 0;
   }
   else {
      num = atoi(mask);
   }

   if(num >= 1 && num <= 32){
      return 1;
   }
   return 0;
}

int validation_format(char **ip,char **mask,int * slash,int *ptid){
  if(validate_ip(*ip,ptid,4)==1){
     if(*slash==1){
        if(validate_mask(*mask)==1){
               return 1;
        }
        else{
               return 0;
        }
     }
     else if(*slash==0){
               return 2;
     }
     else{
               return 0;
     }
  }
  else{
               return 0;
  }
}

void separation_format(char *ch,char **ip,char **mask,int * slash){

    char* p;
    p = strtok(ch, "/");
    *ip = p;
    while (p != NULL)

    {
        *mask = p;
        p = strtok(NULL, "/");
        (*slash)++;
    }
}