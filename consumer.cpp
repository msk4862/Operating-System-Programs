#include<sys/shm.h>
#include<fcntl.h>
#include <sys/mman.h>
#include<cstdio>
#include<iostream>

using namespace std;

int main()
{
	const int s = 1024;
	const char *name = "OS";

	int shm_fd;

	void *ptr;

	while( (shm_fd = shm_open(name, O_RDWR)) < 0 );

	cout<<"\n\tConsuming.....\n";

	ptr = mmap(0, s, PROT_READ, MAP_SHARED, shm_fd, 0);

	printf("%s", (char *) ptr);



	//cout<<(char *)ptr;

	cout<<"\n\tConsumed\n";

	shm_unlink(name);
	


return 0;

}
