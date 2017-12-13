#include<iostream>
#include<cstdio>

using namespace std;

class Priority {
	
public:
	int pid, bt, at, wt, tt, rt, ct, priority;
	
	void input() {
          
          cout<<"Enter the pid:\n";
          cin>>pid;
          
          cout<<"Enter the priority (Lesser the no. Higher the priority):\n";
          cin>>priority;
          
          cout<<"Enter the arrival time:\n";
          cin>>at;
           
          cout<<"Enter the burst time:\n";
          cin>>bt;
        
        
          
          
	}
	
	
	
	
	void display(int i) {
		
		cout<<"\t"<<pid<< "\t\t"<<priority<<"\t\t" << bt<< "\t\t"<< at << "\t\t" << wt<< "\t\t\t"<< tt<<"   "<<rt;
	}
	
	
	
};


int highestPJob(Priority p[], int curTime, int remTime[], int totalp, int curPIndex) {
		
		
		for(int i = 0; i < totalp; ++i) {
			
			if(curTime >= p[i].at) {
				
				//current process is not over
				if(remTime[curPIndex] != -1) {
				
					//If process is not already completed
					if(remTime[i] != -1) {
						
						//lesser the no. greater the priority
						if(p[curPIndex].priority > p[i].priority) {
							curPIndex = i;
						}	
					}
				}
				
			
				else {
					
					//Giving an another value to shortestProcessIndex
					
					for(int i = 0; i < totalp; ++i) {
						
						if(remTime[i] != -1) {
							curPIndex = i;
							break;
						}
					}
					
			}
		}
	}
	

		
		return curPIndex;
	}
	

int main() 
{
	int totalp;

	
	cout<<"\n\n\n<------------------- Priority (Non - Preemptive)------------------->";
	cout<<"\n\nEnter total number of processes present:";
	cin>>totalp;
	
	Priority *p = new Priority[totalp];
	
	
	cout<<"\n\nEnter the details of processes in order of their arrival\n\n";

	for(int i = 0; i < totalp; ++i) {
		
		cout<<"\nEnder details of P"<<i+1<<endl;
		
		  p[i].input();
          
	}
		
	int remTime[totalp];
	
	int curTime = 0, totalTime=0;
	
	for(int i = 0; i < totalp; ++i) {
		
		totalTime += p[i].bt;
		
		remTime[i] = p[i].bt;
		
	}
	

int i=0, c=0, n;

int highestPIndex=0;

cout<<"\nGantt Chart: ";

//Searching new Process with hieghest priority
	highestPIndex = highestPJob(p, curTime, remTime, totalp, highestPIndex);

			cout<<p[highestPIndex].pid<<" | ";
	
	//Response Time of First processed process		
p[highestPIndex].rt = p[highestPIndex].at;



	while(totalTime--) {
		
		
		//Searching new Process with hieghest priority
		int n = highestPJob(p, curTime, remTime, totalp, highestPIndex);
		
		if( n != highestPIndex) {
			
			highestPIndex = n;
			cout<<p[highestPIndex].pid<<" | ";
			
			p[n].rt = curTime - p[n].at;


		}
		curTime++;
		remTime[highestPIndex]--;
		
		
		
		//If process is completed
		if(remTime[highestPIndex] ==0) {
			
			
			remTime[highestPIndex] = -1;
			p[highestPIndex].ct = curTime;			
		

		}
	
	}
	
	//cout<<endl<<curTime;
	
	
	
		for(int i = 0; i < totalp; ++i) {
	
			p[i].wt = p[i].ct - p[i].bt - p[i].at;
			p[i].tt = p[i].ct - p[i].at;
			
		}
		

	
	cout << "\n\nProcesses" << "\tBurst Time" << "\tArrival Time"
         << "\tWaiting Time" << "\tTurn-Around Time"<<"\tResponse Time\n";
         

	
	for(int i = 0; i < totalp; ++i) {
		
				  //s[i].display(i);
				  
				  cout<<p[i].wt<<" "<<p[i].tt<<" "<<p[i].rt<<endl;
	}
	
	
	
	
	return 0;
	
}
