// general TSP question//
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<limits.h>

int cache[16][65536];
int dist[17][17];
int n;

int minimum(int a,int b){
	if(a>=b)
		return b;
	else
		return a;
}
int min(int visited,int current){
	int result;
	int ret=(cache[visited][current]);
	if((ret)!=0) return ret;
	if(current==((1<<n)-1))
	{
		if(dist[visited][0]!=0){
			return dist[visited][0];
		}
		else
			return 1000000000;
	}
	
	 ret=(1000000000);
	//int count=0;
	for(int i=0;i<n;i++){
		
		if((current & (1<<i))) continue;
		if(dist[visited][i]==0) continue;

		result=(min(i,current|(1<<i))+dist[visited][i]);
		if(result<ret)
			ret=result;
		//printf("%d  ||   %d  %d,%d\n",min(i,current|(1<<i)),dist[visited][i], visited, current);
		}	
	cache[visited][current]=ret;
	return ret;
}



int main(){
	
	int d;
	scanf("%d",&d);	
	n=d;
	//int find=1<<n;
	for(int i=0;i<n;i++){
		getchar();
		char* forweight=(char*)malloc(sizeof(char)*1000000000);;
		scanf("%[^\n]s",forweight);
		int j=0;
		char* count=strtok(forweight," ");
		while(count!=NULL){
			dist[i][j]=atoi(count);
			//printf("%d\n",dist[i][j]);
			j++;
			count=strtok(NULL," ");
		}
	}
	//memset(cache,0,sizeof(cache));
	int result=min(0,1);
	printf("%d\n",result);
}


