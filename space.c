// This is the problem of connecting stars which are represented as X-Y coordinates
// first input shows how many stars we have
// second input is the coordinates of stars
// result should be the minimum cost(cost are distances)

#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>


int visited[1200];
int star;
typedef struct stars{
	int x;
	int y;
}Star;
typedef struct distance{
	int a;
	int b;
	double dist;
}DIST;

double getdistance(Star* a, Star* b){
//	printf("%lf\n",sqrt(pow((a->x-b->x),2)+pow(a->y-b->y),2));
	return sqrt(pow((a->x-b->x),2)+pow((a->y-b->y),2));
}
int static compare(const void* first, const void* second){
	DIST* a=(DIST*)first;
	DIST* b=(DIST*)second;
//printf("%lf %lf\n",a->dist,b->dist);
	if(a->dist>b->dist)
		return 1;
	else if(a->dist<b->dist)
		return -1;
	else
		return 0;
}
int visitall(){

	for(int i=0;i<star;i++){
		if(visited[i]==-1)
			return 0;
	}
	return 1;
}
int findparent(int index){
	if(visited[index]==index)
		return index;
	
	return visited[index]=findparent(visited[index]);
}

void init(int index){
	for(int i=0;i<index;i++){
		visited[i]=i;
	}
}





int main(){
//	int star;
	int already;
	memset(visited,-1,sizeof(visited));
	//printf("%d\n",visited[90]);
	int X;
	int Y;
	double result=0;
	scanf("%d %d",&star,&already);
	init(star);
//	printf("%dzxc\n",visited[0]);
	Star** setofstar=(Star**)malloc(sizeof(Star*)*(star+1));
	for(int i=0;i<star;i++){
		setofstar[i]=(Star*)malloc(sizeof(Star));
		scanf("%d %d",&X,&Y);
	//	scanf("%lf %lf",&setofstar[i]->x,&setofstar[i]->y);
	//	printf("%lf %lf\n",X, Y);
		setofstar[i]->x=X;
	//	printf("asdf\n");
		setofstar[i]->y=Y;
	//	printf("zxc\n");
	}
	//Star** astar=(Star**)malloc(sizeof(Star*)*(already+1));
	for(int qwe=0;qwe<already;qwe++){
		int a1;
		int a2;
		int temp;
		scanf("%d %d",&a1,&a2);
		a1=a1-1;
		a2=a2-1;
		if(a1>a2){
			temp=a1;
			a1=a2;
			a2=temp;
		}
		if(visited[a1]==-1 &&visited[a2]==-1){
			visited[a1]=a1;
			visited[a2]=a1;
		}
		else if(visited[a1]==-1 ||visited[a2]==-1){
			if(visited[a1]==-1)
				visited[a1]=visited[a2];
			else
				visited[a2]=visited[a1];
		}
		else if(findparent(a1)==findparent(a2))
			continue;
		else{
			if(findparent(a1)>findparent(a2)){
				visited[findparent(a1)]=findparent(a2);
			}
			else
				visited[findparent(a2)]=findparent(a1);

		}
			
		
	}
	
	
	int count=0;
	
DIST length[1000100];
	for(int j=0;j<star;j++){
		for(int k=j;k<star;k++){
			//length[count]=(DIST*)malloc(sizeof(DIST));
			length[count].a=j;
			length[count].b=k;
			length[count].dist=getdistance(setofstar[j],setofstar[k]);
			count++;
		}
	}
	qsort(length,count,sizeof(DIST),compare);
	
	for(int index=0;index<count;index++){
		if(length[index].dist==(double)0){
			//printf("0\continue");
			continue;
		}
		if(visited[length[index].a]==-1 &&visited[length[index].b]==-1){
		visited[length[index].a]=length[index].a;
		visited[length[index].b]=length[index].a;
		result=result+length[index].dist;
		//printf("%dasasdd %d\n",length[index].a,length[index].b);
		}
		else if(visited[length[index].a]==-1 ||visited[length[index].b]==-1){
		//	printf("%dasd3000asd %d\n",length[index].a,length[index].b);
			if(visited[length[index].a]==-1)
				visited[length[index].a]=visited[length[index].b];
			else
				visited[length[index].b]=visited[length[index].a];
			result=result+length[index].dist;
		}
		else if(findparent(length[index].a)==findparent(length[index].b)){
			//printf("already visited\n");
			continue;
		}
		else{
		//printf("newone here\n");
		//printf("%d %d asd\n",length[index].a, length[index].b);
		
		
		result=result+length[index].dist;
			if(findparent(length[index].a)<=findparent(length[index].b)){
				visited[findparent(length[index].b)]=findparent(length[index].a);


			}
			else
				visited[findparent(length[index].a)]=findparent(length[index].b);
		}
}

	
	printf("%.2lf\n",result);
}






