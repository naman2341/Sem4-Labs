#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
int sum(int x,int y)
{
    return x+y;
}
int main()
{
    int res;
    int x,y;
    printf("Enter the 2 numbers(space in between)\n");
    scanf("%d %d",&x,&y);
    res=sum(x,y);
    printf("%d\n",res);
    return 0;
}
