#include<iostream>
#include<cstdio>

using namespace std;

class SJF {
	
public:
	int pid, bt, at, wt, tt, rt, ct;
	
	void input() {
          
          cout<<"Enter the pid:\n";
          cin>>pid;
          
          cout<<"Enter the arrival time:\n";
          cin>>at;
           
          cout<<"Enter the burst time:\n";
          cin>>bt;
        
        
          
          
	}
	
	
	
	
	void display(int i) {
		
		cout<<"\t"<<pid<< "\t\t" << bt<< "\t\t"<< at << "\t\t" << wt<< "\t\t\t"<< tt<<"   "<<rt;
	}
	
	
	
};


int shortestJob(SJF s[], int curTime, int totalp, int remTime[], int shortestPIndex) {
		
		
		for(int i = 0; i < totalp; ++i) {
			
			if(curTime >= s[i].at) {
				
				//current process is over
				if(remTime[shortestPIndex] != -1) {
				
					
					if(remTime[i] != -1) {
						
						if(remTime[shortestPIndex] > remTime[i]) {
						shortestPIndex = i;
						}	
					}
				}
				
			
				else {
					
					//Giving an another value to shortestProcessIndex
					
					for(int i = 0; i < totalp; ++i) {
						
						if(remTime[i] != -1) {
							shortestPIndex = i;
							break;
						}
					}
					
			}
		}
	}
		
		return shortestPIndex;
	}
	

int main() 
{
	int totalp;

	
	cout<<"\n\n\n<------------------- Shortest Job First (Non - Preemptive)------------------->";
	cout<<"\n\nEnter total number of processes present:";
	cin>>totalp;
	
	SJF *s = new SJF[totalp];
	
	
	cout<<"\n\nEnter the details of processes in order of their arrival\n\n";

	for(int i = 0; i < totalp; ++i) {
		
		cout<<"\nEnder details of P"<<i+1<<endl;
		
		  s[i].input();
          
	}
	
	
	int remTime[totalp];
	
	
	int curTime = 0, totalTime=0;
	
	for(int i = 0; i < totalp; ++i) {
		
		totalTime += s[i].bt;
		
		remTime[i] = s[i].bt;
	}
	

int i=0, c=0, n;

int shortestPIndex=0;


		//Searching Process with shortest bt

		shortestPIndex = shortestJob(s, curTime, totalp, remTime, shortestPIndex);


	while(totalTime--) {
		
		
		
		
		curTime++;
		remTime[shortestPIndex]--;
		
		//If process is completed
		if(remTime[shortestPIndex] ==0) {
			
			remTime[shortestPIndex] = -1;
			s[shortestPIndex].ct = curTime;
			
			
		cout<<s[shortestPIndex].pid<<" | ";
		
		//Searching new Process with shortest bt
		shortestPIndex = shortestJob(s, curTime, totalp, remTime, shortestPIndex);
	

		}
	
	}
	
	//cout<<endl<<curTime;
	
	
	
		for(int i = 0; i < totalp; ++i) {
	
			s[shortestPIndex].rt = s[i].wt = s[i].ct - s[i].bt - s[i].at;
			s[i].tt = s[i].ct - s[i].at;
			
		}
		

	
	cout << "\n\nProcesses" << "\tBurst Time" << "\tArrival Time"
         << "\tWaiting Time" << "\tTurn-Around Time"<<"\tResponse Time\n";
         

	
	for(int i = 0; i < totalp; ++i) {
		
				  //s[i].display(i);
				  
				  cout<<s[i].wt<<" "<<s[i].tt<<" "<<s[i].rt<<endl;
	}
	
	
	
	
	return 0;
	
}
