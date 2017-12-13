#include<iostream>
#include<fcntl.h>
#include<unistd.h>
#include<cstdlib>


using namespace std;

int main(int argc, char *argv[])

{
char* sf= new char[10];
char* tf = new char[10];

	if(argc == 1) {

		cout<<"Enter name of source file:\n";
		cin>>sf;

		cout<<"Enter name of desination file:\n";
		cin>>tf;
		}

		else {
           sf=argv[1];
           tf=argv[2];
		}


    int sd = open(sf, O_RDONLY);

    if(sd<0) {
        cout<<"Error in opening source file";
        exit(0);
    }

    int td = open(tf, O_CREAT| O_WRONLY | O_TRUNC, 0640);

    if(td<0) {
        cout<<"Error in opening destination file";
        close(sd);
        exit(0);
    }


    char buffer[5];

    int n;
    while((n = read(sd, buffer, sizeof(buffer)-1))!=0) {

	buffer[n]='\0';
	cout<<buffer;

        
        write(td, buffer, n);

	//write(1, buffer, n);
    }

    close(sd);
    close(td);


    return 0;
}


