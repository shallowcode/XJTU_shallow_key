#include<stdio.h>
#include<stdlib.h>

typedef struct link{
    int data;
    struct link * next;
}link;

link* initlink(int n){
    link* p=(link*)malloc(sizeof(link));
    link* temp=p;
    temp->data=1;
    temp->next=NULL;
    for (int i=1;i<n-1;++i){
        link* a=(link*)malloc(sizeof(link));
        a->data=i+1;
        a->next=NULL;
        temp->next=a;
        temp=a;
    }
    link* a=(link*)malloc(sizeof(link));
    a->data=n;
    a->next=p;
    temp->next=a;
    return p;
}

link* makelink(link* p,int n,int k){
    link* temp=p;
    while(n!=2){
        for (int i=0;i<k-2;++i)
        {
            temp=temp->next;
        }
        link* d=temp->next;
        temp->next=temp->next->next;
        free(d);
        --n;
        temp=temp->next;
    }
    return temp;
}

void printlink(link* p){
    printf("%d %d",p->data,p->next->data);
}

int main(){
    int n;
    scanf("%d",&n);
    link* p=initlink(n);
    p=makelink(p,n,3);
    printlink(p);
    return 0;
}