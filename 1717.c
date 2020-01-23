#include<stdio.h>

int par[1000001]={0};
int count1=0;


void init(int index){
	for(int i=0;i<=index;i++){
		par[i]=i;
	}
}

int find(int n){
	if(par[n]==n)
		return n;
	par[n]=find(par[n]);  
	return par[n];


}


void sum(int first, int second,int index){
	int min1;
	int min2;
	min1=find(first);
	min2=find(second);
	if(min1==min2) return;
	if(min1>=min2)
		par[min1]=min2;
	else
		par[min2]=min1;
	if(count1>=4){
for(int i=0;i<=index;i++)
	printf("%d ",par[i]);
}

	count1++;
}

void check(int first, int second){
	if(find(first)==find(second))
		printf("YES\n");
	else
		printf("NO\n");
}




int main(){
	int index;
	int calc;
	int divide;
	int first;
	int second;
	int temp;
	scanf("%d %d",&index,&calc);
	init(index);
	for(int i=0;i<calc;i++){
		scanf("%d %d %d",&divide, &first, &second);
	
		if(divide==0)
			sum(first,second,index);
		else if(divide==1)
			check(first, second);
	
		
	}
}
