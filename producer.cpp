#include<sys/shm.h>
#include<fcntl.h>
#include<unistd.h>
#include<cstdio>
#include<cstring>
#include <sys/mman.h>
#include<iostream>

using namespace std;

int main()
{
	const int s = 1024;
	const char *name = "OS";
	const char m1[] = "Hello ";
	const char *m2 = "World";

	int shm_fd;
	void *ptr;

	shm_fd = shm_open(name, O_CREAT  | O_RDWR, 0666);
	ftruncate(shm_fd, s);

	ptr = mmap(0, s, PROT_WRITE, MAP_SHARED, shm_fd, 0);


	sprintf((char*)ptr, "%s", m1);
	ptr =(char *)ptr + strlen(m1);
	sprintf((char*)ptr, "%s", m2);
	//ptr =(char *)ptr + strlen(m2);


	cout<<"\n\tProduced\n";

return 0;

}
