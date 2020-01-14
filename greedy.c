#include<stdio.h>

int main(){
	int N;
	int K;
	scanf("%d %d",&N,&K);
	int arr[11];
	for(int i=1;i<=N;i++){
		scanf("%d",&arr[i]);
	}
	int result=0;
	for(int z=0;z<N;z++){
		int share=K/arr[N-z];
		int remain=K%arr[N-z];
		result=result+share;
		K=remain;
	}
	printf("%d\n",result);
}
