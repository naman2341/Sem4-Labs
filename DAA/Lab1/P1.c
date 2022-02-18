//Impliment Insertion sort with sentinal a[0...n] a[0]
//Bottom up approach

#include<stdio.h>

// void read(int arr[],n)
// {
//     int n=10;
//     for(int i =0;i<n;i++)
//         scanf("%d",&arr[i]);
// }
// void display(int arr[])
// {
//     for(int i =0;i<10;i++)
//         printf("%d",arr[i]);
// }

void insertionSort(int *arr)
{
    int i,j,temp;
    int n=5;
    for(i =1;i<n;i++)
    {
        temp = arr[i];
        for(j = i-1;j>=0 && arr[j]>temp;j--)
            arr[j+1] = arr[j];
        arr[j+1] = temp;
    }
}


int main()
{
    int a[10],n=5,i;
    // scanf("%d",&n);
    for( i =0;i<n;i++)
        scanf("%d",&a[i]);
    // read(a);
    insertionSort(a);
    printf("Sorted Array is\n");
    for( i =0;i<n;i++)
        printf("%d\n",a[i]);
    // display(a);
    return 0;
}