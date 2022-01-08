#include<stdio.h>
#include<stdlib.h>

int main(){
    char a[100];
    char b[100];
    scanf("%[^\n]",a);
    int i=0;
    int top=-1;
    int ret=1;
    while(a[i]!='\0'){
        if (a[i]=='[' || a[i]=='{'  || a[i]=='(' ){
            b[++top]=a[i];
        }
        else if(a[i]==']'){
            if(top>=0 && b[top]=='['){
                --top;
            }
            else{
                printf("缺少[括号");
                ret=0;
            }
        }
        else if(a[i]=='}'){
            if(top>=0 && b[top]=='{'){
                --top;
            }
            else{
                printf("缺少{括号");
                ret=0;
            }
        }
        else if(a[i]==')'){
            if(top>=0 && b[top]=='('){
                --top;
            }
            else{
                printf("缺少(括号");
                ret=0;
            }
        }
        ++i;
    }
    if(ret && top==-1){
        printf("匹配成功");
    }
    else{
        while(top!=-1){
            if(b[top]=='('){
                printf("缺少)括号");
            }
            else if(b[top]=='{'){
                printf("缺少}括号");
            }
            else if(b[top]=='['){
                printf("缺少]括号");
            }
            --top;
        }
    }

    return 0;
}