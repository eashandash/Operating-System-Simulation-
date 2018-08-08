#include <iostream>
#include "sim.h"
using namespace std;

int main()
{
	int n;
	cout<<"enter the no of process\n";
	cin>>n;
	dash p[n];
	cout<<"welocme to the non preemtive scheduling";
	cout<<"\nenter the details of each process";
	for(int i=0;i<n;i++)
	{
		cout<<"\n enter the Arrival time(at) and Burst time(bt) and priority of process : "<<i+1<<"  ";
		cin>>p[i].at>>p[i].bt>>p[i].pt;

	}

	// fcfs(p,n);
	// print(p,n);
	pri(p,n);
	print(p,n);
	return(0);
}


// cout<<"\nenter the file name ";
		// cin>>name;
		// strcat(name,".txt > temp.txt");
		// strcat(sys2,name);
		// system(sys2);
		 //ifstream fptr;
		// fptr.open("temp.txt");
		// fptr>>p[i].at;
		// fptr.close();
		// cout<<p[i].at;
