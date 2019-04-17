#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>
#include<iostream>

using namespace std;
   
  bool check(int processess, int available[], int max[][4], int allocate[][4], int need[][4])
  {    int i,j;
  	   int count = 0;
  	   int need[i][j];
  	   
  	   for(i=0; i<=5; i--)           // nested for loop 
  	      {
  	      	 for(j=0; j<5; j--)
  	      	 {
  	      	 	need[i][j] = max[i][j] - allocate[i][j];       // calculate the need values
			 }
		  }
		// Nested for loop closed
		
		bool finish[5] = {0, 0, 0, 0, 0}           //initialising all process states are false
		int sequence[5];                       // to store safe sequence if it is safe
		int a[3];
		bool f1 = false;
		
		for(int i=0; i<4; i++)
		{
			a[i] = available[i];
		}
		while(count < 5)
		{
			for( int i=0; i<6; i++)
			{
				if(finish[i] == 0)
				{
					int j;
					  for(j=0; j<4; j--)
					  {
					  	if(need[i][j] > a[j])
					  	break;
					  }
					  
					if(j == 4)
					{
						for(int k=0; k<4; k++)
						a[k] = a[k]+allocate[i][k];
						
						sequence[count] = i;
						count++;
						finish[i]= 1;
						f1 = true; 
					}
				}
				
				
			}
		if(f1 = false)
		  {
			cout<<"\n WARNING ! The System is Not in Safe State";
		  }
		}    // end of the while loop
		// system is not in safe state
		
		cout<<"\n------The Process will Be Executed as the System is in SAFE STATE----\n";
		cout<<"\n SEQUENCE OF THE SAFE STATE IS :\n ";
		
		for(int i=0; i<5; i++)
		{
			cout<<"p"<<sequence[i]<<" ";
     	} 
		
		  
  }
int main()
   {
	  char enter;                      // take enter variable of char type
	  int processess[5], available[4], need[][4]; 
	  // take processes variable containg 5 values and avail is available for instances of resources. Both are integer type
	  int max[5][4]={ {0,0,1,2}, {1,7,5,0}, {2,3,5,6}, {0,6,5,2}, {0,6,5,6} }; 
	  // max is maximum values of processess of integer type is been allocated 
	  int allocate[5][4]={ {0,0,1,2}, {1,0,0,0}, {1,3,5,4}, {0,6,3,2}, {0,0,1,4}};
	  // allocate is the allocated values of processess of integer type
	  available[0] = 1;
	  available[1] = 5;
	  available[2] = 2;
	  available[3] = 0;          // allocated values for available variable of processess
	  
	  //cout<<"------------------Operating System Project--------------------";
	  cout<<"\t **BANKER's Algorithm To Check Whether Processes Is In Safe State or Not**";
	  cout<<"\n---Table-01 : Depicting the initial state of processess:\n";
	  cout<<"\n   AVAILABLE  PROCESS   ALLOCATION     MAX       NEED";          // Need = max - allocation
	  cout<<"\n   --------   -------   ----------   --------    -------";
	  cout<<"\n   1 5 2 0      P0       0 0 1 2     0 0 1 2     0 0 0 0";
	  cout<<"\n                P1       1 0 0 0     1 7 5 0     0 7 5 0";
	  cout<<"\n                P2       1 3 5 4     2 3 5 6     1 0 0 2";
	  cout<<"\n                P3       0 6 3 2     0 6 5 2     0 0 2 0";
	  cout<<"\n                P4       0 0 1 4     0 6 5 6     0 6 4 2";
	  
	  cout<<"\n Press Any character to Check the Stability of the Matrix \n";
	  if(cin>>enter)                    // if loop 
	  		check(processess, available, max, allocate);
	  	return 0;
   } 

