#include<stdio.h>

int arr[1001][1001]={0};
int arrD[1001]={0};
	int arrB[1001]={0};
	int stack[1001]={0};
	int queue[1001]={0};
int vertex;
	int edge;
	int start;

int add(int a,int b){
	arr[a][b]=1;
	arr[b][a]=1;
}

void DFS(int vertex,int start){
	int i;
	arrD[start]=1;
	printf("%d ",start);
	for(i=1;i<=vertex;i++){
		if(arr[start][i]==1 && arrD[i]==0){
			DFS(vertex,i);
		}
	}
}


		




void BFS(int vertex,int start,int arrB[],int queue[],int end,int edge,int index){
	if(end==0)
		return;
	if(edge<0)
		return;
	if(queue[index]==0)
		return;
	int i;
	int j;
	int count=0;
	
	i=index;
	printf("%d ",queue[i]);
	for(j=i;j>=0;j--){
		if(queue[j]==0)
			break;
	}
	for(int k=0;k<=vertex;k++){
		if(arr[start][k]==1){
			if(arrB[k]==0){
			arrB[k]=1;
			queue[j]=k;
			j--;
			}
		}
	}
	BFS(vertex,queue[i-1],arrB,queue,end-1,edge-1,i-1);
	


}

int main(){
	
	scanf("%d %d %d",&vertex,&edge,&start);
	for(int i=0;i<edge;i++){
		int a;
		int b;
		scanf("%d %d",&a,&b);
		add(a,b);
	}
	//	printf("ffff\n");
	int arrD[1001]={0};
	int arrB[1001]={0};
	int stack[1001]={0};
	int queue[1001]={0};
	stack[0]=start;
	queue[1000]=start;
	arrB[start]=1;
	//printf("%d ",start);
	DFS(vertex,start);
	printf("\n");
	BFS(vertex,start,arrB,queue,vertex,edge,1000);
	printf("\n");
}

