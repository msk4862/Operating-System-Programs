#include<iostream>
using namespace std;


class RoundRobin{

public:
int PID;
int burstTime;
int arrivalTime;

public:


void addProcess(int pid){

cout<<" ENTER BURST TIME "<<endl;
cin>>burstTime;
cout<<" ENTER ARRIVAL TIME "<<endl;
cin>>arrivalTime;


PID = pid;


}

};



int main(){

int timeSlot=2,totalTime=0,time=0;

int *burstTimeRe,*completionTime,*waitingTime,*turnAroundTime,*responseTime;

int *serviceTime;

cout<<" HOW MANY PROCESS DO YOU WANT "<<endl;
int x;
cin>>x;

burstTimeRe = new int[x];
completionTime = new int[x];
waitingTime  = new int[x];
turnAroundTime  = new int[x];
responseTime  = new int[x];

for(int i=0;i<x;i++){
completionTime[i] =0;
waitingTime[i] =0;
turnAroundTime[i] = 0;
responseTime[i] = 0;

}

RoundRobin *obj = new RoundRobin[x];

for(int i=0;i<x;i++){

cout<<" FOR PROCESS "<<i+1<<endl;
obj[i].addProcess(i+1);

burstTimeRe[i] = obj[i].burstTime;
totalTime += obj[i].burstTime;

}


cout<<" Gantt Chart :\n";
while(totalTime!=0){


for(int i=0;i<x;i++){

if(obj[i].burstTime >0){

if(obj[i].burstTime > timeSlot){

  time += timeSlot;

 cout<<obj[i].PID<< " | ";

 obj[i].burstTime -= timeSlot;
 totalTime -=timeSlot;

}

else{

time += obj[i].burstTime ; 

completionTime[i] = time;

cout<<obj[i].PID<< " | ";
totalTime -= obj[i].burstTime;

obj[i].burstTime = 0;

}

}

}

}

//turn around = completion - arrival
// wait = turn around time - burst time



for(int i=0;i<x;i++)
    {
     turnAroundTime[i] = completionTime[i] - obj[i].arrivalTime;
     waitingTime[i] = turnAroundTime[i] - burstTimeRe[i];

    }


  cout<<"\nProcess\t    Arrival Time \t Burst Time   \tCompletion Time \tWaiting Time\tTurnaround Time";
    for(int i=0;i<x;i++)
    {
    
        cout<<"\nP["<<obj[i].PID<<"]\t\t  "<<obj[i].arrivalTime<<"\t\t    "<<burstTimeRe[i]<<"\t\t    "<<completionTime[i]<<"\t\t\t"<<waitingTime[i]<<"\t\t  "<<turnAroundTime[i];
    }

cout<<endl;
return  0;

} 











