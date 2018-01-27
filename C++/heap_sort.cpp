#include <stdlib.h>
#include <stdio.h>
#include <iostream>

using namespace std;

void Swap(int *x, int *y);

void Max_heapify(int array[], int i, int heap_size);
void Build_max_heap(int array[],int len);
void Heapsort(int array[],int len);

void Swap(int *x, int *y)
{

	int temp;
	temp=*x;
	*x=*y;
	*y=temp;
}

void Max_heapify(int array[], int i, int heap_size)
{
	int largest;
	int _left=2*i;
	int _right=2*i+1;

	if (_left<=heap_size && array[_left]>array[i])
	{
		largest=_left;
	}
	else
		largest=i;

	if (_right<=heap_size && array[_right]>array[largest])
	{
		largest=_right;
	}

	if (largest!=i)
	{
		Swap(&array[largest],&array[i]);
		Max_heapify(array,largest,heap_size);
	}
}

void Build_max_heap(int array[],int len)
{

	int heap_size=len;
	for (int i=len/2; i>=1; i--)
	{
		Max_heapify(array,i,heap_size);
	}
}

void Heapsort(int array[],int len)
{
	int heap_size=len;
	Build_max_heap(array,len);
	for (int i=len; i>=2; i--)
	{
		Swap(&array[1],&array[i]);
		heap_size--;
		Max_heapify(array,1,heap_size);
	}
}

int main()
{

	int array[]={0,14,10,8,7,9,3,2,4,1};
	int len=9;
	Heapsort(array,len);

	cout<<"heap sort result:\n";
	for (int i=1; i<=len; i++)
	{
		cout<<array[i]<<" ";
	}
	cout<<endl;
}
