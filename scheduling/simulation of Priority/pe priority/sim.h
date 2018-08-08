#include <iostream>
#ifndef SIM_H
#define SIM_H

using namespace std;

class dash
{
public:
	int at,bt,ct,tat,wt,rt,id,pt;
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






void pri(dash p[],int n);





void print(dash p[],int n);


#endif