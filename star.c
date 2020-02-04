// This is the problem of connecting stars which are represented as X-Y coordinates
// first input shows how many stars we have
// second input is the coordinates of stars
// result should be the minimum cost(cost are distances)


#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int visited[101]={1,0};
double distances[101]={0};
int star;
typedef struct stars{
	double x;
	double y;
}Star;
int nextstar;
//checking if all stars are visited
int visitall(){

	for(int i=0;i<=star;i++){
		if(visited[i]==0)
			return 0;
	}
	return 1;



}
double distance(Star* a, Star* b){
//	printf("%lf\n",sqrt(pow((a->x-b->x),2)+pow(a->y-b->y),2));
	return sqrt(pow((a->x-b->x),2)+pow((a->y-b->y),2));
}

double minimum(Star** setofstar,int index){
	double result=-1;
	for(int i=0;i<=star;i++){
		if(visited[i]==1)
			continue;
		else{
			double temporary=distance(setofstar[index],setofstar[i]);
			distances[i]=temporary;
			if(result<0 || temporary<result){
				result=temporary;
			//	printf("%dasd\n",nextstar);
				nextstar=i;
		//		printf("%dasd\n",nextstar);
			}
		}


	}
	return result;
}


//calculating MST with recursive calls
double MST(Star** setofstar,int index){
	visited[index]=1;
	if(visitall())
		return 0;
//	printf("%lf\n",minimum(setofstar,index));
//		return 1;	
	
	return minimum(setofstar,index)+MST(setofstar,nextstar);




}

int main(){
//	int star;
	double X;
	double Y;
	scanf("%d",&star);
//	printf("%dzxc\n",visited[0]);
	Star** setofstar=(Star**)malloc(sizeof(Star*)*(star+1));
	for(int i=0;i<star;i++){
		setofstar[i+1]=(Star*)malloc(sizeof(Star));
		scanf("%lf %lf",&X,&Y);
	//	scanf("%lf %lf",&setofstar[i]->x,&setofstar[i]->y);
	//	printf("%lf %lf\n",X, Y);
		setofstar[i+1]->x=X;
	//	printf("asdf\n");
		setofstar[i+1]->y=Y;
	//	printf("zxc\n");
	}
	double result=MST(setofstar,1);
	printf("%lf\n",result);
}


