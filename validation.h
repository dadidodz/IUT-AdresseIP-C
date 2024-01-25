	int validation_number(char *str);
	int validation_ip(char *ip,int *ptid,size_t size);
	int validation_mask(char *mask);
	int validation_format(char **ip,char **mask,int * slash,int *ptid);
	void separation_format(char *ch,char **ip,char **mask,int * slash);