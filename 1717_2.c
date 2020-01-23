#include<stdio.h>

int par[1000001]={0};



void init(int index){
	for(int i=0;i<=index;i++){
		par[i]=i;
	}
}

void sum(int first, int second,int index){
	int count;
	if(first!=second){
	if(par[second]>=par[first]){
		count=par[second];
		par[second]=par[first];
			for(int i=0;i<=index;i++){
				if(par[i]==count)
				sum(second,i,index);
			}
	}
	else{
		count=par[first];
		par[first]=par[second];
			for(int i=0;i<=index;i++){
				if(par[i]==count)
				sum(first,i,index);
			}

	}
}
}

void check(int first, int second){
	if(par[first]==par[second])
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
		if(first<=second){

		if(divide==0)
			sum(first,second,index);
		else if(divide==1)
			check(first, second);
	}
		else{
			temp=second;
			second=first;
			first=temp;

			if(divide==0)
				sum(first,second,index);
			else if(divide==1)
				check(first,second);

		}
	}
}
