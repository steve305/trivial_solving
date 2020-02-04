#include<stdio.h>
#include<stdlib.h>

typedef struct list{
	struct list* next;
	struct list* low;
	int index;
}List;

typedef struct POSITION{
	List* current;
	List* prev;
}position;




void init(int index,List* set){
	
	position* now=(position*)malloc(sizeof(position));
	now->current=set;
	for(int i=0;i<index;i++){
		List* then=(List*)malloc(sizeof(List));
		now->current->next=then;
		then->next=NULL;
		then->low=NULL;
		then->index=i+1;
		now->current=now->current->next;
	}
		free(now);
	//printf("%d\n",set->next->index);
}
void sum(int first,int second,List* set){
	position* now=(position*)malloc(sizeof(position));
	position* bottom=(position*)malloc(sizeof(position));
	position* attached=(position*)malloc(sizeof(position));
	now->current=set;
	
	int count=0;
	if(first==second){
	free(now);
	free(bottom);
	free(attached);
}
	else{
	while(now->current!=NULL){
	if(count==0){
		bottom->current=now->current;
		while(count==0){
			
			if(bottom->current->index==first || bottom->current->index==second)
					count++;
			if(bottom->current->low ==NULL)
						break;
			bottom->current=bottom->current->low;	
		}
		if(count==1){
			while(1){
			if(bottom->current->low ==NULL)
				break;
			bottom->current=bottom->current->low;
			}
		}
		}
	else if(count==1){
		attached->current=now->current;
		while(count==1){
			
			if(attached->current->index==first ||attached->current->index==second)
					count++;
			if(attached->current->low ==NULL)
						break;
			attached->current=attached->current->low;	
		}
	}
	if(count==2)
		break;
	now->prev=now->current;
	now->current=now->current->next;
}
	now->prev->next=now->current->next;
	now->current->next=NULL;
	bottom->current->low=now->current;
	free(now->current);
	free(now);
	free(bottom);
	free(attached);
}
}
void check(int first, int second,List* set){
	position* now=(position*)malloc(sizeof(position));
	position* bottom=(position*)malloc(sizeof(position));
	now->current=set;
	int count;
	while(now->current!=NULL){
		count=0;
	if(first==second){
		bottom->current=now->current;
		while(bottom->current!=NULL){
			if(bottom->current->index==first || bottom->current->index==second){
				count++;
				//bottom->current=bottom->current->low;
			}
			if(count==1)
				break;
			else
				bottom->current=bottom->current->low;
		}
		if(count==1)	//printf("YES\n");
			break;
		
		else{
			now->current=now->current->next;
		}


	}
		else{
		bottom->current=now->current;
		while(bottom->current!=NULL){
			if(bottom->current->index==first || bottom->current->index==second){
				count++;
				//bottom->current=bottom->current->low;
			}
			if(count==2)
				break;
			else
				bottom->current=bottom->current->low;
		}
		if(count==2)//printf("YES\n");
			break;
		
		else{
			now->current=now->current->next;
		}
		}
	}
	if(first==second){
		if(count!=1)
			printf("NO\n");
		else if(count ==1)
			printf("YES\n");
	}
	else{
		if(count!=2)
			printf("NO\n");
		else if(count==2)
			printf("YES\n");
	}
	

}

int main(){
	int index;
	int calc;
	int divide;
	int firstdigit;
	int seconddigit;
	List* set=(List*)malloc(sizeof(List));
	set->next=NULL;
	set->low=NULL;
	set->index=0;
	scanf("%d %d",&index,&calc);
	init(index,set);
	for(int i=0;i<calc;i++){
		scanf("%d %d %d",&divide,&firstdigit,&seconddigit);
		if(divide==0)
			sum(firstdigit,seconddigit,set);
		else if(divide==1)
			check(firstdigit,seconddigit,set);
	}
}









