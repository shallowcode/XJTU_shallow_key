#include<stdio.h>
#include<stdlib.h>

int main(){
    char father[20]="abacababdeadcde";
    char son[20];
    scanf("%[^\n]",son);
    int next[20];
    next[0]=-1;
    int i=0;
    int j=-1;
    while(son[i]!='\0'){
        if(j==-1 || son[i]==son[j]){
            ++i;
            ++j;
            next[i]=j;
        }
        else{
            j=next[j];
        }
    }
    i=0;
    j=0;
    while(1){
        if(father[i]!=son[j]){
            if(next[j]==-1){
                ++i;
            }
            else{
                j=next[j];
            }
        }
        else{
            ++i;
            ++j;
        }
        if(father[i]=='\0'){
            printf("匹配未成功\n");
            break;
        }
        else if(son[j]=='\0'){
            printf("匹配成功\n");
            break;
        }
    }
    i=0;
    while(son[i]!='\0'){
        printf("%d",next[i++]);
    }
}