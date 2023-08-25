//Constants, Operators, Identifiers
#include<string.h>
#include<ctype.h>
#include<stdio.h>
int main()
{
	char identifiers[100],constants[100],operators[100];
	char string[100];
	char oper[6] = {'+','-','*','/','%','='};
	int i,j,n,ic=0,op=0,c=0;
	printf("Enter the string : ");
	gets(string);
	n = strlen(string);
	for(i=0;i<=n;i++){
		if(isalpha(string[i])){
			identifiers[ic] = string[i];
			ic++;
		}
	}
	for(i=0;i<6;i++){
		for(j=0;j<=n;j++){
			if(string[j] == oper[i]){
				operators[op] = string[j];
				op++;
			}
		}
	}
	for(i=0;i<=n;i++){
		if(isdigit(string[i])){
			constants[c] = string[i];
			c++;
		}
	}
	printf("Operators : ");
	for(i=0;i<op;i++){
		printf("%c",operators[i]);
	}
	printf("\nIdentifiers : ");
	for(i=0;i<ic;i++){
		printf("%c",identifiers[i]);
	}
	printf("\nConstants : ");
	for(i=0;i<c;i++){
		printf("%c",constants[i]);
	}
}
