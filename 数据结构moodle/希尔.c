#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void sort(int *a,int n,int gap){
    if(gap==0){
        return;
    }
    int b[n];
    for (int i=0;i<n;++i){
        b[i]=a[i];
    }
    int j,k;
    for (int i=0;i<gap;++i){
        for (j=i;j<n;j+=gap){
            int temp=b[j];
            for(k=j;k>gap && temp < b[k-gap];k-=gap){
                b[k]=b[k-gap];
            }
            b[k]=temp;
        }
    }
    for (int i=0;i<n;++i){
        printf("%d ",b[i]);
    }
    printf("\n");
    sort(b,n,--gap);
}
int main(){
    int a[12];
    for (int i=0;i<12;i++){
        scanf("%d",&a[i]);
    }
    sort(a,12,3);
}