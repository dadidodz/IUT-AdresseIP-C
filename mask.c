#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "mask.h"

void mask_reseau(int mask,int *reseau){
	int nb=mask/8;//nmbr octet
	int reste=mask%8;
	int p=0;
	int puissancede2[8];
	puissancede2[0]=128;

//puissance de 2
	for(int i=1;i<8;i++){
		puissancede2[i]=puissancede2[i-1]/2;
	}

//ici on calcule le masque du réseau
	for (int i=0;i<4;i++){
		if(nb>i){
			reseau[i]=255;
		}
		else if(reste!=0){
			reseau[i]=0;
			while(reste>0){
				reseau[i]=reseau[i]+puissancede2[p];
				p+1;
				reste-1;
			}
		}
	}
}

void adresse_reseau(int *ip_v4,int *reseau,int *s_reseau){
	int puissancede2[8];
	puissancede2[0]=128;
	int reste1;
	int reste2;

	//puissance de 2
	for(int i=1;i<8;i++){
		puissancede2[i]=puissancede2[i-1]/2;
	}

	//adresse de sous reseau
	for (int i=0;i<4;i++){

		reste1=ip_v4[i];
		reste2=reseau[i];
		s_reseau[i]=0;

		for (int p=0;p<8;p++){
			if(reste1-puissancede2[p]>=0 & reste2-puissancede2[p]>=0){
				reste1=reste1-puissancede2[p];
				reste2=reste2-puissancede2[p];
				s_reseau[i]+=puissancede2[p];
				
			}
			else if(reste1-puissancede2[p]>=0){
				reste1=reste1-puissancede2[p];
			}
			else if(reste2-puissancede2[p]>=0){
				reste2=reste2-puissancede2[p];
			}
		}
	}
}

void calc_partie_restante(int *reseau,int *p_rest){
	for(int i=0;i<4;i++){
		p_rest[i]=255-reseau[i];
	}
}