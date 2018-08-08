


#include <iostream>
#include "schedule.h"
#include <queue>
using namespace std;

void Swap(Schedule obj[],int i, int pos){

	int temp1 = obj[i].AT;
	obj[i].AT = obj[pos].AT;
	obj[pos].AT = temp1;

	int temp2 = obj[i].BT;
	obj[i].BT = obj[pos].BT;
	obj[pos].BT = temp2;

	int temp3 = obj[i].RT;
	obj[i].RT = obj[pos].RT;
	obj[pos].RT = temp3;

	int temp4 = obj[i].Pid;
	obj[i].Pid = obj[pos].Pid;
	obj[pos].Pid = temp4;

}

void print(Schedule obj[],int no){

	cout<<"Pid\t"<<"AT\t"<<"BT\t"<<"CT\t"<<"TAT\t"<<"WT\n";
	for (int i = 0; i < no; ++i){
		cout<<obj[i].Pid<<"\t"<<obj[i].AT<<"\t"<<obj[i].BT<<"\t"<<obj[i].CT<<"\t"<<obj[i].TAT<<"\t"<<obj[i].WT<<endl;
	}
}

void rr(Schedule obj[],int no){

//SORTING  according to the arrival time

	for (int i = 0; i < no; ++i)
	{
		for (int j = i+1; j < no; ++j)
		{
			if(obj[i].AT > obj[j].AT)
			{
				//SWAPP THE CORRESPONDING MEMBERS
				Swap(obj, i, j);
			}

			else if(obj[i].AT == obj[j].AT && obj[i].BT > obj[j].BT)
				Swap(obj, i, j);
		}
	}

	queue<int> q;
	queue<int> dq;
	int qn;
	cout<<"\nEnter the Time quantum: "<<endl;
	cin>>qn;

	int T = obj[0].AT;
	q.push(0);
	int temp = 1;
	dq.push(obj[0].Pid);

	obj[0].Contain = 1;
	int x;
	while(1)
	{	
		//executing the elements present in q

		if(!q.empty())
		{
			x = q.front();
			q.pop();
			
			if(obj[x].RT - qn >= 0)
			{			
				obj[x].RT = obj[x].RT - qn;
				T = T + qn;
				cout<<"Pid.."<<obj[x].Pid<<"   RT.."<<obj[x].RT<<"   T.."<<T<<endl;
				
				if (obj[x].RT == 0)
				{
					cout<<"\n---------Pid.."<<obj[x].Pid<<".......Iam done..at...."<<T<<endl;
					obj[x].CT = T;
					obj[x].findTAT();
					obj[x].findWT();
				}
				
			}
			else
			{
				T = T + obj[x].RT;
				obj[x].RT = 0;
				cout<<"\n---------Pid.."<<obj[x].Pid<<".......Iam done..at...."<<T<<endl;
				obj[x].CT = T;
				obj[x].findTAT();
				obj[x].findWT();
			}
			//insertion into queue
			
			for (int i = 0; i < no; ++i)
			{
				if ((obj[i].AT <= T) && (obj[i].RT > 0) && (obj[i].Contain == 0))
				{
					q.push(i);
					dq.push(obj[i].Pid);
					obj[i].Contain = 1;
				}
			}

			if (obj[x].RT > 0)
			{
				q.push(x);
				dq.push(obj[x].Pid);		
			}
		}


		//checking the terminating condition
		int k = 0;

		for (int i = 0; i < no ; ++i)
		{
			if(obj[i].RT != 0)
				k = 1;
		}

		if(k == 0)
			break;
		if(q.empty())
		{
			T = T + 1;
			for (int i = 0; i < no; ++i)
			{
				if ((obj[i].AT <= T) && (obj[i].RT > 0) && (obj[i].Contain == 0))
				{
					q.push(i);
					dq.push(obj[i].Pid);
					obj[i].Contain = 1;
				}
			}
		}

	}

}

	// while(!dq.empty())
	// {
	// 	cout<<"P("<<dq.front()<<") ->";
	// 	dq.pop();
	// }
rr.cpp
Open with
Displaying rr.cpp.