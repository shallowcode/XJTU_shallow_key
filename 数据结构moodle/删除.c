#include<stdio.h>

int main(){
    char a[100];
    scanf("%[^\n]",a);
    int i=0;
    while(a[i]!='\0'){
        if(a[i]=='x'){
            if (a[i+1]=='\0'){
                a[i]=a[i+1];
                break;
            }
            int j=i;
            while(a[j+1]!='\0'){
                a[j]=a[j+2];
                j++;
            }
            i=0;
            continue;
        }
        i++;
    }
    printf("%s",a);
}