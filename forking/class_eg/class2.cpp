#include <iostream>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>
using namespace std;


int main()
{
	fork();
	fork() && fork() || fork();
	fork();
	cout<<" hello \n";
	return(0);
}