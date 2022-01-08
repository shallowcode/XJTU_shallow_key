//固定大小循环队列实现杨辉三角形
#include<stdio.h>
#include<stdlib.h>

int main(){
    int a[100]={0};
    a[1]=1;
    int top=0;
    int rear=3;
    int n;
    scanf("%d",&n);
    if (n==1){
        printf("1");
    }
    else if(n==100){
        printf("队列已满");
    }
    else{
        int cet=2;
        while(cet<=n){
            for (int i=0;i<cet;++i){
                a[rear%100]=a[top%100]+a[(top+1)%100];
                a[top%100]=0;
                ++top;
                ++rear;
            }
            ++rear;
            ++cet;
        }
        while(top%100+1!=rear%100-1){
            ++top;
            printf("%d ",a[top%100]);
        }
    }
    return 0;
}