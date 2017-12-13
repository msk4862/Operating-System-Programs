#include<iostream>
#include<fcntl.h>
#include<unistd.h>
#include<cstdlib>
#include<sys/types.h>
#include<sys/stat.h>
#include<time.h>
#include<pwd.h>

using namespace std;

int main() {


	char* fname = new char[10];
	char per[3] = {'x', 'w', 'r'};
	string perm;

	cout<<"Enter filename: ";
	cin>>fname;

	struct stat a;

	if(stat(fname, &a) < 0) {

		cout<<"Error in opening file";
		exit(0);
	}


	int mode=a.st_mode;

	int k=0;
	
	for(int mask=1; mask <=256; mask<<=1) {
		if(mask & mode) 
			//cout<<per[k];
			perm=per[k]+perm;

		else 
			perm="-"+perm;			
			//cout<<"-";
			//cout<<per[k];

	
		if((k+1)%3==0) {
			perm=" "+perm;
			k=0;
		}
		else {
			k++;
		}
	}
	
	cout<<"Permissions: "<<perm<<endl;
	
	
	struct tm *tp = localtime(&a.st_atime);
	
	cout<<"\nLast Accessed at: "<<tp->tm_mday<<"/"<<tp->tm_mon+1<<"/"<<(tp->tm_year)+1900<<"\t"<<tp->tm_hour<<":"<<tp->tm_min<<":"<<tp->tm_sec<<endl;
	
	tp = localtime(&a.st_mtime);
	cout<<"\nLast Modified at: "<<tp->tm_mday<<"/"<<tp->tm_mon+1<<"/"<<(tp->tm_year)+1900<<"\t"<<tp->tm_hour<<":"<<tp->tm_min<<":"<<tp->tm_sec<<endl;
	
	tp = localtime(&a.st_ctime);
	cout<<"\nLast Status changed at: "<<tp->tm_mday<<"/"<<tp->tm_mon+1<<"/"<<(tp->tm_year)+1900<<"\t"<<tp->tm_hour<<":"<<tp->tm_min<<":"<<tp->tm_sec<<endl;
	
	
	struct passwd *pass;
	
	pass = getpwuid(a.st_uid);
	
	cout<<"\nUsername: "<<pass->pw_name<<endl;
	
	
	return 0;
}
