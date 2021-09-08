#include <stdio.h>
#include<stdlib.h>
int maxAbsDiff(int arr[], int n)
{
	int i;
	int minEle = arr[0];
	int maxEle = arr[0];
	for (i = 1; i < n; i++) {
		if(minEle>=arr[i])
			minEle=arr[i];
		if(maxEle<=arr[i])
			maxEle = arr[i];
	}
	return (maxEle - minEle);
}
int main()
{
	int d,n,i;
	printf("\nEnter no of elements: ");
	scanf("%d",&n);
	int arr[n];
	printf("\nEnter elements: ");
	for(i=0;i<n;i++)
		scanf("%d",&arr[i]);
	d=maxAbsDiff(arr, n);
	printf("\nMaximum Difference: %d",d);
	return 0;
}
