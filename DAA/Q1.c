#include<stdio.h>

void what(int n, int a[][11])
{
	for(int i = 1; i <= n; ++i)
	{
		for(int j = 1; j <= n; ++j)
		{
			a[i][j] = (i/j) * (j/i);
            printf("%d",a[i][j]);
		}
	}
}

int main()
{
    int a[10][10];
    what(10,a);
}