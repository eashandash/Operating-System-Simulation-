#include <iostream>

using namespace std;

class dash
{
public:
	int at,bt,ct,tat,wt;
public:
	void cal_tat()
	{
		tat=ct-at;
	}

	void cal_wt()
	{
		wt=tat-bt;
	}
}p[5];



void fcfs()
{
	cout<<"\nfirst come first serve\n";
	p[0].ct=p[0].bt+p[0].at;
	p[0].cal_tat();
	p[0].cal_wt();

	for(int i=1;i<5;i++)
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



void sjf()
{


	cout<<"\nshortest job first schedule\n";
	p[0].ct=p[0].bt+p[0].at;
	p[0].cal_tat();
	p[0].cal_wt();
	//soting on the basis of bt
	

for(int x=1;x<5;x++)
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
	}



	for(int i=1;i<5;i++)
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


	//running sjf schedule
	

	
}




void print()
{
	for(int i=0;i<5;i++)
	{
		cout<<"\n at bt ct tata wt of process "<<i+1<<"are : ";
		cout<<p[i].at<<" "<<p[i].bt<<" "<<p[i].ct<<" "<<p[i].tat<<" "<<p[i].wt<<"\n";
	}


}

int main()
{

	cout<<"welocme to the non preemtive scheduling";
	cout<<"\nenter the details of each process";
	for(int i=0;i<5;i++)
	{
		cout<<"\n enter the Arrival time(at) and Burst time(bt)  of process : "<<i+1<<"  ";
		cin>>p[i].at>>p[i].bt;

	}

	//fcfs();
	//print();
	sjf();
	print();
	return(0);
}


