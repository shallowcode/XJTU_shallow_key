#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int a[12];

void quick(int left ,int right){
    int mid=a[left];
    while(1){
        while(a[right]>mid) right--;
        while(a[left]<mid) left++;
        if(left < right){
            int temp=a[left];
            a[left]=a[right];
            a[right]=temp;
        }
        else{
            break;
        }
    }
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
    quick(0,11);
    cout();
    quick(1,11);
    cout();
    quick(1,7);
    cout();
    quick(3,7);
    cout();
    quick(3,5);
    cout();
    quick(3,4);
    cout();
}