#include<stdio.h>
#include<stdlib.h>

typedef struct stack{
    struct stack* next;
    char data;
}stack;

stack* push(stack* p,char elem){
    stack* a=(stack*)malloc(sizeof(stack));
    a->data=elem;
    a->next=p;
    p=a;
    return p;
}

stack* pop(stack* p){
    if (!p){
        return p;
    }
    stack* temp=p;
    p=p->next;
    free(temp);
    return p;
}
int main(){
    //三个栈作为缓冲区，两个栈记录入站和出站顺序
    stack* a=NULL;
    stack* b=NULL;
    stack* c=NULL;
    stack* ru=NULL;
    stack* chu=NULL;
    //数据预处理
    char m[20];
    scanf("%[^\n]",m);
    int i=0;
    while(m[i]!='\0'){
        if (m[i]!=' '){
            ru=push(ru,m[i]);
        }
        ++i;
    }
    //循环条件：缓冲区有车厢或者入站顺序非空
    while(ru || a || b || c){
        //入站直接出站
        if (!chu && ru && ru->data=='1' || ru && chu && ru->data==chu->data+1){
            chu=push(chu,ru->data);
            ru=pop(ru);
        }
        else{
            //在缓冲区寻找合适的出站元素
            if (chu && a && a->data==chu->data+1){
                chu=push(chu,a->data);
                a=pop(a);
            }
            else if (chu && b && b->data==chu->data+1){
                chu=push(chu,b->data);
                b=pop(b);
            }
            else if (chu && c && c->data==chu->data+1){
                chu=push(chu,c->data);
                c=pop(c);
            }
            else{
                //找不到的话找一个空的缓冲区存放元素，如果没有则重排失败
                if (!a && ru){
                    a=push(a,ru->data);
                    ru=pop(ru);
                }
                else if(!b && ru){
                    b=push(b,ru->data);
                    ru=pop(ru);
                }
                else if(!c && ru){
                    c=push(c,ru->data);
                    ru=pop(ru);
                }
                else{
                    printf("重排失败");
                    return 0;
                }
            }
        }
    }
    //打印出站链表
    while(chu){
        printf("%c ",chu->data);
        chu=chu->next;
    }
}