#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char a[30];
void front(int pos,int length){
    if(pos<=length-1 && a[pos]!='0'){
        printf("%c",a[pos]);
        front(2*pos+1,length);
        front(2*pos+2,length);
    }
}
void mid(int pos,int length){
    if(pos<=length-1 && a[pos]!='0'){
        mid(2*pos+1,length);
        printf("%c",a[pos]);
        mid(2*pos+2,length);
    }
}
void later(int pos,int length){
    if(pos<=length-1 && a[pos]!='0'){
        later(2*pos+1,length);
        later(2*pos+2,length);
        printf("%c",a[pos]);
    }
}
int main(){
    scanf("%[^\n]",a);
    int length=strlen(a);
    front(0,length);
    printf("\n");
    mid(0,length);
    printf("\n");
    later(0,length);
}