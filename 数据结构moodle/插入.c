#include<stdio.h>

int main(){
    char a[100];
    a[0]='\0';//输入为无的处理
    scanf("%[^\n]",a);
    int n;
    scanf("%d",&n);
    if (a[0]=='\0'){
        printf("x");
    }
    else{
        int sum=0;
        while(a[sum]!='\0'){
            sum++;
        }
        if ((n-1)*2>sum){
            a[sum]=' ';
            a[sum+1]='x';
            a[sum+2]='\0';
        }
        else{
            for (int i=sum+2;i>=2*n;--i){
            a[i]=a[i-2];
            }
            a[2*n-2]='x';
        }
        printf("%s",a);
    }
}