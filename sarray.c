#include<stdio.h>
#include<stdlib.h>
int arr[100001];
int stack[100001]={0};
int count=0;
int print[300000]={0};
int printid=0;
int integer=0;
void push(int end){
//printf("yaya\n");
int now=integer;
int cnow=count;
	for(int i=cnow;i<end-now+cnow;i++){
		integer++;
		stack[i]=integer;
		count++;
		//integer++;
		print[printid]=1;
		printid++;
	}
	//integer--;
	stack[count-1]=0;
	count--;
	print[printid]=2;
	printid++;

//printf("%dasd\n",count);
}
int pop(int end,int arrid){
//printf("zvzv\n");
	if(stack[count-1]==end){

		stack[count-1]=0;
		count--;
		print[printid]=2;
		printid++;
//printf("%dasdpop\n",count);
		return 1;
	}
	else
		return 2;



}

int main(){
	int index;
	int breaker;
	scanf("%d",&index);
	for(int i=0;i<index;i++){
		scanf("%d",&arr[i]);
	}
//	push(arr[0]);
	for(int j=0;j<index;j++){
		if(j==0)
			push(arr[0]);
		else{
//printf("uiui\n");
			if(arr[j]>arr[j-1]){
				push(arr[j]);
			}
			else{
				breaker=pop(arr[j],j);
				if(breaker==2){
					printf("NO\n");
					exit(0);
				}

			}
		}
	}
	for(int k=0;k<printid;k++){
		if(print[k]==1)
			printf("+\n");
		else
			printf("-\n");
	}

}
