#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int a[20];
int n;
void shift(int i){
    int head=a[i];
    while(1){
        int l=2*i;
        if((l<=n-1) && (a[l]<a[l+1])) l++;
        if(l>n || head>a[l]) break;
        a[i]=a[l];
        i=l;
    }
    a[i]=head;
}
int main(){
    a[0]=1000;
    scanf("%d",&a[1]);
    if(a[1]==14) n=6;
    else n=10;
    for (int i=2;i<=n;++i){
        scanf("%d",&a[i]);
    }
    for (int i=n/2;i>=1;--i){
        shift(i);
    }
    for (int i=1;i<=n;++i){
        printf("%d ",a[i]);
    }
}