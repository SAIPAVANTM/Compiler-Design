%{
int coun = 0;
%}

%%
[a-z . 0-9]+@[a-z]+".com"|".in" {coun = 1;}
%%

int yywrap() {return 1;}

int main(int argc, char * argv[]){
yyin = fopen(argv[1],"r");
yylex();
if(coun==1){
printf("Accepted");
}
else{
printf("Not Accepted");
}
return 0;
}