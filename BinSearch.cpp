/*
KULDEEP NATH
19HCS4029
ABOUT : PROGRAM USING ITERATIVE AND RECURSIVE FUNCTION FOR BINARY SEARCHING
*/
#include<iostream>
#include<algorithm>
using namespace std;

//Recursive Function For Binary Searching

bool binarySearchReacursive(int* array, int startIndex, int lastIndex, int element)
{
	int mid=(startIndex+lastIndex)/2;
	
	if(startIndex<=lastIndex)
	{
		if(element == array[mid])
				return false;
		
		else if(array[mid]>element)
				return binarySearchReacursive(array,startIndex,mid-1,element);
		
		else
				return binarySearchReacursive(array,mid+1,lastIndex,element);
	}
  
  return true;
}

//Iterative Function For Binary Searching

bool binarySearchIterative(int* array, int startIndex, int lastIndex, int element)
{
	while(startIndex<=lastIndex)
	{
		int mid=(startIndex+lastIndex)/2;
		
		if(element == array[mid])
		return false;
		
		else if(array[mid]>element)
			lastIndex=mid-1;
		
		else
			startIndex=mid+1;
	}
  return true;
}


int main()
{
	int n;
	cout<<"Enter size of array : ";
	cin>>n;
	
	int *arr = new int[n];
	
	cout<<"Enter an array of "<<n<<" elements : \n";
	for(int i=0;i<n;i++)
		cin>>arr[i];
	
	// Sorting The Array
	sort(arr,arr+n);
	
	cout<<"\n\nArray after sorting : ";
	for(int i=0;i<n;i++)
		cout<<arr[i]<<" ";

	cout<<"\n\n******************************************************************************";
	cout<<"\n\nEnter number to be searched : ";
	int num;
	cin>>num;
	
	cout<<"\n-> Binary Search using Iterative function : ";
	if(!binarySearchIterative(arr,0,n-1,num))
		cout<<"\n-> "<<num<<" exists in the array";
	else
		cout<<"\n-> "<<num<<" does not exists in the array";
	
	
	cout<<"\n\n-> Binary Search using Recursive function : ";
	if(!binarySearchReacursive(arr,0,n-1,num))
		cout<<"\n-> "<<num<<" exists in the array";
	else
		cout<<"\n-> "<<num<<" does not exists in the array";
  
  return 0;
}
