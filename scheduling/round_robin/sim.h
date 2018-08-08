#include <iostream>
#ifndef SIM_H
#define SIM_H

using namespace std;

class dash
{
public:
	int at,bt,ct,tat,wt,id,rt,present;
public:
	void cal_tat()
	{
		tat=ct-at;
	}

	void cal_wt()
	{
		wt=tat-bt;
	}
};






// void fcfs(dash p[],int n);




void rr(dash p[],int n,int x);





void print(dash p[],int n);


#endif