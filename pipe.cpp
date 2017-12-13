#include<iostream>
#include<cstdlib>
#include<fcntl.h>
#include<unistd.h>
#include<cstdlib>
#include<cstring>
#include<sys/wait.h>

using namespace std;

int main(int ac, char* argv[])
{
	int pipe1[2];
	int pipe2[2];
	
	int n, fd;

	if(pipe(pipe1)<0) {
		cout<<"Unable to open pipe-1"<<endl;
		exit(0);
	}

	if(pipe(pipe2)<0) {
		cout<<"Unable to open pipe-2"<<endl;
		exit(0);
	}

	char a[20];
	char buf[5];
	
	int pid=fork();

	if(pid == 0) {
		cout<<"Enter name of the file: ";
		cin>>a;

		close(pipe1[0]);
		close(pipe2[1]);

		write(pipe1[1], a, strlen(a)+1);
		

		;

		while((n = read(pipe2[0], buf, sizeof(buf)))!=0) {

			write(1, buf, n);

		}
	}
 
	else {
		close(pipe1[1]);
		close(pipe2[0]);


		n=read(pipe1[0], a, sizeof(a));

		fd = open(a, O_RDONLY) ; 
		if(fd < 0) {
			cout<<"Unable to open file!!!";
			exit(0);
		}


		    while((n = read(fd, buf, sizeof(buf)))!=0) {

			write(pipe2[1], buf, n);
		    }

		 close(fd);

	}
		
	

return 0;

}
		

	
