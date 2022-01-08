#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(){
    int a[12];
    for (int i=0;i<12;++i){
        scanf("%d",&a[i]);
    }
    int i,j;
    for (i=0;i<12;++i){
        int temp=a[i];
        for (j=i;j>0 && (temp%10)<(a[j-1]%10);--j){
            a[j]=a[j-1];
        }
        a[j]=temp;
    }
    for (int k=0;k<12;++k){
        printf("%d ",a[k]);
    }
    printf("\n");
    for (i=0;i<12;++i){
        int temp=a[i];
        for (j=i;j>0 && temp<a[j-1];--j){
            a[j]=a[j-1];
        }
        a[j]=temp;
    }
    for (int k=0;k<12;++k){
        printf("%d ",a[k]);
    }
}