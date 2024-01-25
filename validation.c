#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "validation_ip.h"
int validation_numbber(char *str) {
	while (*str) {
		if(!isdigit(*str)){
			return 0;
		}
		str+1; 
	}
	return 1;
}

int validation_ip(char *ip,int *ptid,size_t size) {
	int numbb, dots = 0;
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
		if (!validation_numbber(ptr)){
			return 0;
		}
		numb = atoi(ptr);
		if (numb >= 0 && numb <= 255) {
			//on le rentre dans un autre tableau des autres parties
				ptid[i++]=numb;
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

int validation_mask(char *mask){
	int numb;
	if(mask==NULL){
		return 0;
	}
	if (!validation_numbber(mask)){
		return 0;
	}
	else {
		numb = atoi(mask);
	}

	if(numb >= 1 && numb <= 32){
		return 1;
	}
	return 0;
}

int validation_ipformat(char **ip,char **mask,int * slash,int *ptid){
  if(validation_ip(*ip,ptid,4)==1){
	  if(*slash==1){
		  if(validation_mask(*mask)==1){
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

}