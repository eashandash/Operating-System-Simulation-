#include <iostream>
#include <fstream>      //file operation
#include <cstdlib>       //for system call
#include <cstring>      
#include "sim.h"       //header file
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
		char sys[50]="wc -w ";             //word count for BT 
		//char sys2[50]="stat -c%%Y ";      //file creation time for AT                           //system call command
		char name[50]="";                                             //  system call  ----(wc -w file1.txt | cut -f1 -d' '>temp.txt)
		                                    //cout<<"\nenter AT of file : "<<i+1<<" -";
		
		cout<<"\nenter the file name ";
		cin>>name;
		
	
		cout<<"\nenter AT of file : "<<i+1<<" -";
		cin>>p[i].at;


		strcat(name,".txt | cut -f1 -d' '> temp.txt");
		strcat(sys,name);
		system(sys);
		ifstream fptr;
		fptr.open("temp.txt");
		fptr>>p[i].bt;
		fptr.close();



		// char string[100]="";
		// char name1[100]="";
		// char name2[100]="";
		// cout<<"\nenter the file name ";
		// cin>>name1>>name2;

		// sprintf(string,"stat -c%%Y %s.txt > temp.txt",name1);
		// system(string);
		// ifstream fptr;
		// fptr.open("temp.txt");
		// fptr>>p[i].at;
		// fptr.close();
		// cout<<"the arrival time is :  ";
		// cout<<p[i].at<<"\n";

		// sprintf(string,"wc -w %s.txt > temp.txt",name2);
		// system(string);
		// fptr.open("temp.txt");
		// fptr>>p[i].bt;
		// fptr.close();
		// cout<<"the burst time is :  ";
		// cout<<p[i].bt;








	}

	fcfs(p,n);
	print(p,n);
	sjf(p,n);
	print(p,n);
	return(0);
}