#include<stdio.h>
void mergeSort(int arr[], int l, int r)
{
    if (l < r)
    {
        int m = l + (r - l) / 2;
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}
void merge(int arr[], int l, int m, int r)
{
    int i,j,k,a=m-l+1,b=r-m;
    int left[a],right[b];
    for(i=0; i<a; i++)
    {
        left[i]=arr[l+i];
    }
    for(j=0; j<b; j++)
    {
        right[j]=arr[m+j+1];
    }
    i=0;
    j=0;
    k=l;
    while(i<a&&j<b)
    {
        if(left[i]<=right[j])
        {
            arr[k++]=left[i++];
        }
        else
        {
            arr[k++]=right[j++];
        }
    }
    while(i<a)
    {
        arr[k++]=left[i++];
    }
    while(j<b)
    {
        arr[k++]=right[j++];
    }
}
int main()
{
    int n;
    printf("\nEnter the size of Integer array : ");
    scanf("%d",&n);
    int a[n];
    printf("\nEnter %d Elements : ",n);
    for(int i=0; i<n; i++)
        scanf("%d",&a[i]);
    mergeSort(a,0,n-1);
    printf("\nAfter Sorting : \n");
    for(int i=0; i<n; i++)
    {
        printf("%d\t",a[i]);
    }
}
