#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* konkatenacja(char*,char*);

int main(){
	char* napis=konkatenacja("aaaaaa","bbbbbbb");
	puts(napis);
	free(napis);
	return 0;
}

char* konkatenacja(char* str1, char* str2){
	char* str3=malloc((strlen(str1)+strlen(str2)+1)*sizeof(char));
	strcpy(str3,str1);
	strcat(str3,str2);
	return str3;
	
}
