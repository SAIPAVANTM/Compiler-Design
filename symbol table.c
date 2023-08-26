#include<stdio.h>
#include<string.h>
int main()
{
	char string[100];
	char oper[8] = {'+','-','*','/','%','=','$','#'};
	
	printf("Enter string : ");
	gets(string);
	int i,j,n = strlen(string);
	printf("Name      Type      Address\n");
	for(i=0;i<n;i++){
		printf("%c      ",string[i]);
		for(j=0;j<=6;j++){
			if(string[i]==oper[j]){
				printf("operator");
			}
		}
		if(isalpha(string[i])){
				printf("identifier");
			}
		if(isdigit(string[i])){
				printf("constant");
			}
		if(string[i]==' '){
			printf("identifier(space)");
		}
		if(string[i]=='\t'){
			printf("identifier(tab space)");
		}
			printf("    %d\n",&string[i]);
		}
	}

