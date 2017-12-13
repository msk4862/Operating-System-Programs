#include<iostream>
#include<fcntl.h>
#include<unistd.h>
#include<cstdlib>


using namespace std;

int main()

{
	
	int buffer[10];

cout<<"\nKernel Version: \n";

int kernel = open("/proc/sys/kernel/osrelease", O_RDONLY);

while((n = read(kernel, buffer, sizeof(buffer)))!=0) {

		write(1, buffer, n);
    }
    
return 0;

}
