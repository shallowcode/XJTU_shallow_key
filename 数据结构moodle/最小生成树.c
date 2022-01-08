#include<stdio.h>
#include<stdlib.h>
//😅😅😅😅😅
int matrix[6][6];
int dist[6];
int sum;
int main(){
    sum=0;
    for (int i=0;i<6;++i){
        for (int j=0;j<6;++j){
            scanf("%d",&matrix[i][j]);
        }
        dist[i]=0;
    }
    dist[0]=1;
    for (int i=0;i<5;++i){
        int min=100;
        int x,y;
        for (int j=0;j<6;++j){
            if(dist[j]==1){
                for (int k=0;k<6;++k){
                    if(matrix[j][k]<min && matrix[j][k]>0 && !dist[k]){
                        min=matrix[j][k];
                        x=j;
                        y=k;
                    }
                }
            }
        }
        dist[y]=1;
        matrix[x][y]=0;
        sum+=min;
    }
    printf("%d",sum);
}