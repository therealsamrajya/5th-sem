#include<iostream>
using namespace std;
int countB=0;
int bubbleSort(int A[],int n)
{
	int i,j;
	for(i=0;i<n-1;i++)
	{
		countB++;
		for(j=0;j<n-i-1;j++)
		{
		
			if(A[j]> A[j+1])
			{
				swap(A[j],A[j+1]);
			}
		}
	}
	cout<<"the output of bubble sort is :"<<endl;
	for(i=0;i<n;i++)
		cout<<A[i]<<endl;
	cout<<"Time complexity is "<<countB;	
}

int selectionSort(int A[],int n)
{
	int countS=0;
	int i,j,minIndex=0,minValue=0;
	{
		for(i=0;i<n;i++)
		{
			minIndex=i;
			minValue=A[i];
		
		for(j=i+1;j<n;j++)
		{
			countS++;
			if(A[j]<minValue)
			{
				minIndex=j;
				minValue=A[j];
			}
		}
		swap(A[i],A[minIndex]);
	}	
}
	cout<<"the output of selection sort is :"<<endl;
	for(i=0;i<n;i++)
		cout<<A[i]<<endl;
	cout<<"Time complexity is "<<countS;
}

int main()
{
	int A[]={1,5,3,4,6,2,9},n=7;
	bubbleSort(A,n);
	selectionSort(A,n);
//	insertionSort(A);
	
}

