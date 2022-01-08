#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int a[12];
int comp(const void *a, const void *b){
    return *(int *)a -*(int *)b;
}
void cout(){
    for (int i=0;i<12;++i){
        printf("%d ",a[i]);
    }
    printf("\n");
}
int main(){
    for (int i=0;i<12;++i){
        scanf("%d",&a[i]);
    }
    for (int i=1;i<12;i+=3){
        if(a[i]>a[i+1]){
            int temp=a[i];
            a[i]=a[i+1];
            a[i+1]=temp;
        }
    }
    cout();
    for (int k=3;k<=12;k*=2){
        for (int i=0;i<12;i+=k){
            qsort(&a[i],k,sizeof(int),comp);
        }
        cout();
    }
}