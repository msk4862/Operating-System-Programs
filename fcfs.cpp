#include<iostream>
#include<cstdio>

using namespace std;

class FCFS {
	
public:
	int pid, bt, at, wt, tt, rt, ct;
	
	void input() {
          
          cout<<"Enter the pid:\n";
          cin>>pid;
          
          cout<<"Enter the burst time:\n";
          cin>>bt;
          
          cout<<"Enter the arrival time:\n";
          cin>>at;
          
          
	}
	
	
	void display(int i) {
		
		cout<< "\t"<<i+1 << "\t\t" << bt<< "\t\t"<< at << "\t\t" << wt<< "\t\t\t"<< tt;
	}
	
	
	
};

int main() 
{
	int totalp;

	
	cout<<"\n\n\n<------------------- First Come First Serve ------------------->";
	cout<<"\n\nEnter total number of processes present:";
	cin>>totalp;
	
	FCFS *f = new FCFS[totalp];
	
	cout<<"\n\nEnter the details of processes in order of their arrival\n\n";

	for(int i = 0; i < totalp; ++i) {
		
		cout<<"\nEnder details of P"<<i+1<<endl;
		
		  f[i].input();
          
	}
	
	int t, i, j;
	
	f[0].wt=f[0].at;
	
	for(i = 1; i < totalp; ++i) {
		t=0;
		j=i-1;	
			while(j>=0){
				
				t += f[j].bt;	
				j--;

			}
			
			f[i].wt = t-f[i].at;
						
			
	}
	
	
		for(i = 0; i < totalp; ++i) {
			
			f[i].tt = f[i].wt + f[i].bt;
			
			f[i].rt = f[i].wt;
			

			
		}
		

	cout<<"\nGantt Chart: ";
	
	for(int i = 0; i < totalp; ++i ) {
		cout<<f[i].pid<<" | ";
	}	
	
	cout << "\n\nProcesses" << "\tBurst Time" << "\tArrival Time"
         << "\tWaiting Time" << "\tTurn-Around Time";
         
	
	for(int i = 0; i < totalp; ++i) {
		
				  f[i].display(i);
				  cout<<endl;
	}
	
	
	
	return 0;
	
}
