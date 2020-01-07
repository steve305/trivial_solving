#include<stdio.h>
//#include<string.h>

long long arr[91]={0};
//memset(arr,0,90);


long long fibo(long long parr[],int index){
	if(index==0)
		{

			return 0;
		}
	else if(parr[index]!=0){
		return parr[index];}
	else if(index==1){
		parr[1]=1;
		return 1;}
	else{
		parr[index]=fibo(parr,index-2)+fibo(parr,index-1);
		return parr[index];
	}
		


}

int main(){
	int index;
	scanf("%d",&index);
	long long result=fibo(arr,index);
	printf("%lld\n",result);










}
