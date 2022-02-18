//Selection sort using 1 pass

void selectionsort()
{
    int i,j,min,temp;
    int arr[10] = {1,2,3,4,5,6,7,8,9,10};
    for(i =0;i<5;i++)
    {
        min = i;
        for(j = i+1;j<5;j++)
        {
            if(arr[j]<arr[min])
                min = j;
        }
        temp = arr[i];
        arr[i] = arr[min];
        arr[min] = temp;
    }
}

