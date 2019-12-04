using namespace std;

#include <iostream>
#include <stdlib.h>
#include <time.h>

const int arraySize=10;

//function prototypes
void displayOptions();
void populateArray(int a[][arraySize]);
void showElements(int a[][arraySize]);
void showLargestElement(int a[][arraySize]);
void transposeArray(int a[][arraySize]);


main ()
{
 int a[arraySize][arraySize];
 int option;
 
option = displayOptions();


//loop executed until user enters '1' as first command
while (option!=1)
	{
		cout<<"\n__________________________________________________\n\nSorry the array is empty, first populate it by pressing 1 to perform this task.\n\n\n";
		displayOptions();
	}

do	
	{
		switch(option)
		{	case 1:
			    {populateArray(a);
				option = displayOptions();
				break;
				}	
				
			case 2:
				{showElements(a);
				option = displayOptions();
				break;
				}
				
			case 3:
				{showLargestElement(a);
				option = displayOptions();
				break;
				}
				
			case 4:
				{transposeArray(a);
				showElements(a);
				option = displayOptions();
				break;
				}
			case 5:
				{cout<<"\nThe array has been processed.\n\n\n";
				option = displayOptions();
				break;
				}
			default:
				{cout<<"\nPlease enter the correct option number.\n\n\n";
				option = displayOptions();
				break;
				}

		}
	}
while(option==1||2||3||4||5);

}

//function to display options to the user
int displayOptions()
{
	int selectedOption;
	cout << "1. Press 1 to populate a two-dimensional array with integers from 1 to 100.\n2. Press 2 to display the array elements.\n3. Press 3 to display the largest element present in the array along with its row and column index.\n4. Press 4 to find and show the transpose of the array.\n\nPlease select an option, use numbers from 1 to 5: ";
	cin >> selectedOption;
}

//populating the array with random numbers
void populateArray(int a[][arraySize])
{
int element;
int i=0;
int j=0;
srand(time(0));
	for(i=0; i<arraySize; i++)
	{
		for(j=0; j<arraySize; j++)
		{ element=rand() % 100 + 1;
		  a[i][j]=element;
		}
		
	}
cout<<"\n__________________________________________________\n\nArray has been populated successfully!\n\n\n";
}

//displaying elements of the two dimensional array
void showElements(int a[][arraySize])
{int i=0;
int j=0;
cout<<"\n__________________________________________________\n\n";
	for(i=0; i<arraySize; i++)
	{
		for(j=0; j<arraySize; j++)
		{cout<<a[i][j]<<'\t';
		}
	cout<<endl;
	}
cout<<"\n\n";
}

//identifying and displaying the largest element
void showLargestElement(int a[][arraySize])
{
int largestElement=0;
int i=0;
int j=0;
int rowIndex, colIndex, rowNumber, colNumber;   

	for(i=0; i<arraySize; i++)	
	{
		for(j=0; j<arraySize; j++)
		{ if(a[i][j]>largestElement)
		  {largestElement=a[i][j];
		   rowIndex=i;
		   colIndex=j;
		   rowNumber=i+1;
		   colNumber=j+1;
		  }
		  
		}
	}
 cout<<"\n__________________________________________________\n\nLargest element is "<<largestElement<<" which is at row index "<<rowIndex<<", present at row number "<<rowNumber<<" and column index "<<colIndex<<", present at column number "<<colNumber<<".\n\n\n";
}


//transpose matrix	
void transposeArray(int a[][arraySize])
{
int i=0;
int j=0;
int store;
		for(i=0; i<arraySize; i++)	
		{
			for(j=i; j<arraySize; j++)
			{store=a[i][j];
			 a[i][j]=a[j][i];
			 a[j][i]=store;
			}	
		}
}
