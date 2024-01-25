#include "ip.h"

char * classe_ip_(int ip_1){
	if(ip_1<=126 & ip_1>=0){
		return "A";
	}
	else if(ip_1==127){
		return "L";
	}
	else if(ip_1>=128 & ip_1<=191 ){
		return "B";
	}
	else if(ip_1>=192 & ip_1<=223 ){
		return "C";
	}
	else if(ip_1>=224 & ip_1<=239 ){
		return "D";
	}
	else{
		return "E";
	}

}

char * type_ip_(int ip_1,int ip_2,int ip_3,int ip_4){
	if(classe_ip_(ip_1)=="A"){
		if(ip_1==10){
			return "Privé";
		}
		else{
			return "Publique";
		}
	}
	else if(classe_ip_(ip_1)=="B"){
		if(ip_1==172 & ip_2>=16 & ip_2<=31){
			return "Privé";
		}
		else{
			return "Publique";
		}
	}
	else if(classe_ip_(ip_1)=="C"){
		if(ip_1==192 & ip_2==168){
			return "Privé";
		}
		else{
			return "Publique";
		}
	}
	else if(classe_ip_(ip_1)=="L"){
		return "Localhost";
	}
	else if(ip_1>=224 & ip_1<=239){
		return "Multicast";
	}
	else if(ip_1!=0 & ip_2!=0 & ip_3!=0 & ip_4!=0 ){
		return "Publique";
	}
}

int attribution_masque_classe(int ip_1){
		if(classe_ip_(ip_1)=="A" || classe_ip_(ip_1)=="L" ){
			return 8;
		}
		if(classe_ip_(ip_1)=="B"){
			return 16;
		}
		if(classe_ip_(ip_1)=="C"){
			return 24;
		}
		return 0;
}