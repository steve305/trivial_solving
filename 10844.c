#include<stdio.h>

int main(){
	long long arr[101][12];
	int index;
	scanf("%d",&index);
	if(index==1)
	{
		printf("%d\n",9);
	}
	else{
	for(int i=0;i<=index;i++){
		arr[i][0]=0;
		arr[i][11]=0;
	}
	for(int j=1;j<10;j++)
	{
		arr[1][j+1]=1;
	}
	
	for(int k=2;k<=index;k++){
		for(int num=0;num<10;num++){
			arr[k][num+1]=(arr[k-1][num]+arr[k-1][num+2])%1000000000;
		}
	}
	long long sum=0;
	for(int count=0;count<10;count++){
		sum=(sum+arr[index][count+1])%1000000000;
	}
	printf("%lld\n",sum%1000000000);
	}
}
	
