#include<iostream>
#include<fcntl.h>
#include<unistd.h>
#include<cstdlib>
#include<sys/wait.h>

using namespace std;

int main(int argc, char *argv[]) 
{
	int pid=fork();

	
	if(pid == 0) {
		execvp(argv[1], &argv[1]);
		cout<<"Command Failed!!!!"<<endl;
		return 345;
	}

	else {
	
		int s = 0;
		wait(&s);
		cout<<s/256;
	}

return 0;
}
