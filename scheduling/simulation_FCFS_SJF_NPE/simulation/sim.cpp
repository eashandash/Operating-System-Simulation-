#include <iostream>
#include "sim.h"
using namespace std;

void fcfs(dash p[],int n)
{
	cout<<"--------------------------------------\n";
	cout<<"--------------------------------------\n";
	cout<<"--------------------------------------\n";
	cout<<"--------------------------------------\n";
	cout<<"first come first serve\n";
	cout<<"--------------------------------------\n";

	//sorting

	for(int i=0;i<n;i++)
	{
		for(int j=i+1;j<n;j++)
		{
			if(p[i].at>p[j].at)
			{
				int temp1=p[i].at;
				p[i].at=p[j].at;
				p[j].at=temp1;

				int temp2=p[i].bt;
				p[i].bt=p[j].bt;
				p[j].bt=temp2;


			}

		}
	}




	for(int i=0;i<n;i++)
	{

		if(i==0)
		{
			p[i].ct=p[i].bt+p[i].at;
			p[i].cal_tat();
			p[i].cal_wt();

		}

		else if(p[i].at<=p[i-1].ct)
		{
			p[i].ct=p[i-1].ct+p[i].bt;
			p[i].cal_tat();
			p[i].cal_wt();

		}
		else if(p[i].at>p[i-1].ct)
		{
			p[i].ct=p[i].at+p[i].bt;
			p[i].cal_tat();
			p[i].cal_wt();

		}

	}



	float wait;
	float count=0;;
	for(int i=0;i<n;i++)
	{
		count=count+p[i].wt;
		
	}
	wait=count/n;
	cout<<"\n";
	cout<<"The average waiting time for First come first serve is : "<<wait;
	cout<<"\n";



}



void sjf(dash p[],int n)
{

    cout<<"--------------------------------------\n";
	cout<<"shortest job first schedule\n";
	cout<<"--------------------------------------\n";
	p[0].ct=p[0].bt+p[0].at;
	p[0].cal_tat();
	p[0].cal_wt();
	//soting on the basis of bt
	
/*for(int x=1;x<5;x++)
  {
  	int i=x;
		for(int j=i+1;j<5;j++)
		{

			if((p[i].bt>p[j].bt)&&(p[i].at<=p[x-1].ct)&&(p[j].at<=p[x-1].ct))
			{
				int temp1=p[i].bt;
				p[i].bt=p[j].bt;
				p[j].bt=temp1;

				int temp2=p[i].at;
				p[i].at=p[j].at;
				p[j].at=temp2;
				cout<<"lol";


			}
			else if((p[i].bt==p[j].bt)&&(p[i].at<=p[x-1].ct)&&(p[j].at<=p[x].ct))
			{
				if(p[i].at>p[j].at)
				{
					int temp3=p[i].bt;
				    p[i].bt=p[j].bt;
				    p[j].bt=temp3;

				    int temp4=p[i].at;
				    p[i].at=p[j].at;
				    p[j].at=temp4;
				    cout<<"lol3";
				}

			}
	}*/

for(int i=1;i<n;i++)
  {
  	
		for(int j=i+1;j<n;j++)
		{

			if((p[i].bt>p[j].bt)&&(p[i].at<=p[i-1].ct)&&(p[j].at<=p[i-1].ct))
			{
				int temp1=p[i].bt;
				p[i].bt=p[j].bt;
				p[j].bt=temp1;

				int temp2=p[i].at;
				p[i].at=p[j].at;
				p[j].at=temp2;
			


			}
			else if((p[i].bt==p[j].bt)&&(p[i].at<=p[i-1].ct)&&(p[j].at<=p[i-1].ct))
			{
				if(p[i].at>p[j].at)
				{
					int temp3=p[i].bt;
				    p[i].bt=p[j].bt;
				    p[j].bt=temp3;

				    int temp4=p[i].at;
				    p[i].at=p[j].at;
				    p[j].at=temp4;
				    
				}

			}
	}



	for(int i=1;i<n;i++)
	{

		if(p[i].at<=p[i-1].ct)
		{
			p[i].ct=p[i-1].ct+p[i].bt;
			p[i].cal_tat();
			p[i].cal_wt();

		}
		else if(p[i].at>p[i-1].ct)
		{
			p[i].ct=p[i].at+p[i].bt;
			p[i].cal_tat();
			p[i].cal_wt();

		}

	}







}

float wait;
	float count=0;;
	for(int i=0;i<n;i++)
	{
		count=count+p[i].wt;
		
	}
	wait=count/n;
	cout<<"\n";
	cout<<"The average waiting time for shortest job first is : "<<wait;
	cout<<"\n";


	//running sjf schedule
	

	
}




void print(dash p[],int n)
{
	for(int i=0;i<n;i++)
	{
		//cout<<"/t/t/t/t/t/t/t/t/t/t/t/t/t/t/ AT || BT || CT || TAT || WT";
		//cout<<"\n at bt ct tat wt of process "<<i+1<<" are : ";
		cout<<"The AT ,BT , CT , TAT , WT are of process "<<i+1<<" are : ";
		
		cout<<p[i].at<<" || "<<p[i].bt<<" || "<<p[i].ct<<" || "<<p[i].tat<<" || "<<p[i].wt<<"\n";
	}


}
