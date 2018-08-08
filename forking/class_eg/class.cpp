#include <iostream>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>s
using namespace std;


int main()
{
	int pid=fork();
	if(pid==0)
	{
		cout<<"pid"<<getpid()<<"\n";
		cout<<"ppid"<<getppid()<<"\n";
		fork();

	}
	else if (pid>0)
	{
		cout<<"pid"<<getpid()<<"\n";
		wait(NULL);
	}
	return(0);
}