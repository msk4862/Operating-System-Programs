#include<iostream>
#include<cstdlib>
#include<fcntl.h>
#include<unistd.h>
#include <linux/kernel.h>
#include <stdio.h>
#include <sys/sysinfo.h>

using namespace std;


int main(){

char buffer[10];
int n;


cout<<endl<<" OS RELEASE ::"<<endl;
int kernelRelease = open("/proc/sys/kernel/osrelease",O_RDONLY);

while((n = read(kernelRelease,buffer,sizeof(buffer))) != 0)
{
 write(1,buffer,n);
}

cout<<endl;
close(kernelRelease);

cout<<endl<<" KERNEL VERSION :: "<<endl;
int kernelVersion = open("/proc/sys/kernel/version",O_RDONLY);
int flag =0;

while((n = read(kernelVersion,buffer,sizeof(buffer))) != 0)
{
 for(int i=0;i<n;i++){
  
 
   if(buffer[i] !='S')
    cout<<buffer[i];
  
   else{
    flag=1;break;
     }
}

 if(flag == 1)
  break;

}


cout<<endl;

close(kernelVersion);

flag =0;

cout<<endl<<" CPU INFO :: ";
int cpuInfo = open("/proc/cpuinfo",O_RDONLY);

while((n = read(cpuInfo,buffer,sizeof(buffer))) != 0)
{
 for(int i=0;i<n;i++){
  
  
   if(buffer[i] !='z')
   cout<<buffer[i];
  
   else{
    flag=1;break;
  }
}

 if(flag == 1)
  break;

}
cout<<endl;
close(cpuInfo);
cout<<endl;

 const double megabyte = 1024 * 1024;

 struct sysinfo si;
 sysinfo (&si);

 cout<<"total RAM   : "<<si.totalram / megabyte<<"MB"<<endl;
 
 cout<<"free RAM   : "<<si.freeram / megabyte<<"MB"<<endl;


cout<<"used memory :"<<si.totalram / megabyte - si.freeram / megabyte<<"MB"<<endl;

return 0;

}

