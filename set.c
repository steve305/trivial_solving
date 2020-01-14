//making set//
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int S[21]={0};

void add(int index){
	if(S[index]==0)
		S[index]=1;
}
void removes(int index){
	if(S[index]==1)
		S[index]=0;
}
void check(int index){
	if(S[index]==1)
		printf("%d\n",1);
	else
		printf("%d\n",0);
}
void toggle(int index){
	if(S[index]==1)
		S[index]=0;
	else
		S[index]=1;
}
void all(){
	for(int i=0;i<20;i++)
		S[i+1]=1;
}
void empty(){
	for(int i=0;i<20;i++)
		S[i+1]=0;
}


int main(){
	int count;
	scanf("%d",&count);
//	printf("%d\n",count);
//	fflush(stdin);
	getchar();
	for(int i=0;i<count;i++){
		char str[80];
		scanf("%[^\n]s",str);
		char* fletter=strtok(str," ");
//		printf("%s\n",fletter);
		if(strcmp(fletter,"all")==0){
			all();
			}
		else if(strcmp(fletter,"empty")==0)
			empty();
		else{
			char* numinchar=strtok(NULL,"\n");
			int index=atoi(numinchar);
			if(strcmp(fletter,"add")==0)
				add(index);
			else if(strcmp(fletter,"remove")==0)
				removes(index);
			else if(strcmp(fletter,"check")==0)
				check(index);
			else if(strcmp(fletter,"toggle")==0)
				toggle(index);

		}
		getchar();
	}
}
