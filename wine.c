#include<stdio.h>
int max(int a, int b){
    return a > b ? a: b;
}
int main(void){
    int N;
    int wine[10010]={};
    int Dp[10010]={};
    scanf("%d",&N);
    for(int i=1;i<=N;i++){
        scanf("%d",&wine[i]);
    }
    for(int i=1;i<=3 && i<=N;i++){
        if(i==1)
            Dp[i]=wine[i];
        else
            Dp[i]=wine[i]+wine[i-1];
    }
    for(int i=3;i<=N;i++){
        int result=0;
        result=max(wine[i]+Dp[i-2],Dp[i-1]);
        result=max(result,wine[i]+wine[i-1]+Dp[i-3]);
        Dp[i]=result;
    }
    printf("%d\n",Dp[N]);
}
