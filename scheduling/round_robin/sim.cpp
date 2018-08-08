#include <iostream>
#include "sim.h"
#include <queue>
using namespace std;






void rr(dash p[],int n,int x)
{




    //arival time sorting
	for(int i=0;i<n;i++)
	{
		for(int j=i+1;j<n;j++)
		{
			if(p[i].at>p[j].at)
			{
				int temp1=p[i].bt;
				p[i].bt=p[j].bt;
				p[j].bt=temp1;

				

				int temp3=p[i].at;
				p[i].at=p[j].at;
				p[j].at=temp3;


				int temp2=p[i].id;
				p[i].id=p[j].id;
				p[j].id=temp2;

			}
			else if(p[i].at==p[j].at)
			{
				if(p[i].bt>p[j].bt)
				{
					int temp1=p[i].bt;
					p[i].bt=p[j].bt;
					p[j].bt=temp1;

				

					int temp3=p[i].at;
					p[i].at=p[j].at;
					p[j].at=temp3;

					int temp4=p[i].id;
					p[i].id=p[j].id;
					p[j].id=temp4;

				}

			}
		}
	}

	queue<int> q;
	queue<int> dq;
	int time=p[0].at;

	q.push(0); //pushing the first process into the queue
	dq.push(p[0].id);  //pushing it's process id

	p[0].present = 1; //indicating that the process is in the queue
	int y;            //the first element of the queue


	




	while(1)	
	{

		if(!q.empty())
		{
			y = q.front();   //first element of the queue
			q.pop();

			if(p[y].rt-x >= 0)
			{
				p[y].rt=p[y].rt-x;
				time=time+x;
				cout<<"Pid.."<<p[y].id<<"   RT.."<<p[y].rt<<"   T.."<<time<<"\n";

				if (p[y].rt == 0)
				{
					cout<<"\n---------Pid.."<<p[y].id<<".......Iam done..at...."<<time<<"\n";
					p[y].ct = time;
					p[y].cal_tat();
					p[y].cal_wt();

				}
				

			}
			else
			{
				time=time+p[y].rt;
				p[y].rt=0;
				cout<<"\n---------Pid.."<<p[y].id<<".......Iam done..at...."<<time<<"\n";
				p[y].ct = time;
				p[y].cal_tat();
				p[y].cal_wt();

				
			}

			//inserting new process into the queue

			for(int i=0;i<n;i++)
			{
				if(p[i].at<=time && p[i].rt>0 && p[i].present==0)
				{
					q.push(i);
					dq.push(p[i].id);
					p[i].present = 1;
				}
			}

			if (p[y].rt > 0)
			{
				q.push(y);
				dq.push(p[y].id);		
			}


	}


		//checking the terminating condition
		int k = 0;

		for (int i = 0; i < n ; ++i)
		{
			if(p[i].rt != 0)
				k = 1;
		}

		if(k == 0)
			break;
		if(q.empty())
		{
			time = time + 1;
			for (int i = 0; i < n; ++i)
			{
				if ((p[i].at <= time) && (p[i].rt > 0) && (p[i].present == 0))
				{
					q.push(i);
					dq.push(p[i].id);
					p[i].present = 1;
				}
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
	cout<<"The average waiting time for hrrn is : "<<wait;
	cout<<"\n";


	//running sjf schedule
	

	
}




void print(dash p[],int n)
{
	for(int i=0;i<n;i++)
	{
		cout<<"hiiiii";
		//cout<<"/t/t/t/t/t/t/t/t/t/t/t/t/t/t/ AT || BT || CT || TAT || WT";
		//cout<<"\n at bt ct tat wt of process "<<i+1<<" are : ";
		cout<<"The AT ,BT , CT , TAT , WT are of process "<<i+1<<" are : ";
		
		cout<<p[i].at<<" || "<<p[i].bt<<" || "<<p[i].ct<<" || "<<p[i].tat<<" || "<<p[i].wt<<"\n";
	}


}
