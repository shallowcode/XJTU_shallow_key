#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int matrix[5][5];
int dist[6];
int list[5];
void dijk(int i){
    list[i]=1;
    for(int j=0;j<5;++j){
        if(matrix[i][j]!=-1){
            if(dist[i]+matrix[i][j]<dist[j]){
                dist[j]=dist[i]+matrix[i][j];
            }
        }
    }
    int temp=5;
    for (int j=0;j<5;++j){
        if(!list[j] && dist[j]<dist[temp]){
            temp=j;
        } 
    }
    if(temp==5){
        return;
    }
    else{
        dijk(temp);
    }
}
int main(){
    for(int i=0;i<5;++i){
        for (int j=0;j<5;++j){
            scanf("%d",&matrix[i][j]);
        }
        dist[i]=1000;
        list[i]=0;
    }
    dist[0]=0;
    dist[5]=1000;
    dijk(0);
    for (int i=0;i<5;++i){
        printf("%d ",dist[i]);
    }
}