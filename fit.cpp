#include<iostream>
using namespace std;


int main(){

int numProcess;
cout<<" ENTER THE NUMBER OF PROCESS "<<endl;
cin>>numProcess;

int numBlock;
cout<<" ENTER THE NUMBER OF BLOCKS "<<endl;
cin>>numBlock;

int processSize[numProcess];
int temp[numProcess];
int flag[numBlock];
int *tempBlock = new int[numBlock] ;


for(int i=0;i<numProcess;i++){
cout<<" ENTER THE SIZE OF PROCESS  P"<<i<<endl;
cin>>processSize[i];

temp[i] =-1;

}

int blockSize[numBlock];
for(int i=0;i<numBlock;i++){
cout<<" ENTER THE SIZE OF BLOCK "<<i+1<<endl;
cin>>blockSize[i];
flag[i] =0;
}

cout<<"============================== O P T I O N ====================================="<<endl;
cout<<"(1) FIRST FIT "<<endl;
cout<<"(2) WORST FIT "<<endl;
cout<<"(3) BEST FIT "<<endl;
cout<<"(4) EXIT"<<endl;

cout<<" ENTER YOUR CHOICE "<<endl;
int choice;
cin>>choice;





do{

 switch(choice){

 case 1 :     
           for(int i=0;i<numProcess;i++)
           	   {
              	      temp[i] = -1;
              for(int j=0;j<numBlock;j++)
                      {
                       
                	 if(processSize[i] <= blockSize[j]){
                	 temp[i] = blockSize[j];
                         blockSize[j] -=processSize[i]; 
                       
                          
                         break ;
                         }

              	      }
                   }
              cout<<" PROCESS "<<"\t\t\tPROCESS SIZE"<<"\t\t\tBLOCK SIZE"<<endl<<endl;
              for(int i=0;i<numProcess;i++)
              cout<<" P["<<i<<"] "<<"\t\t\t\t "<<processSize[i]<<"\t\t\t\t "<<temp[i]<<endl;

                  break;
       



 case 2 :         
                  
               
                    
                        
                        

                        for(int i=0;i<numProcess;i++)
           	         {
              	           temp[i] = -1;
                           int worst=-1;
                          for(int j=0;j<numBlock;j++)
                           {
                            if(blockSize[j]>=processSize[i])
                             {
                               if(worst == -1)
                                worst = j;
                               else if(blockSize[worst] < blockSize[j])
                                 worst = j;
                             }
                           }
                            
                            if(worst != -1){
                                   temp[i] = blockSize[worst];
                                   blockSize[worst] -= processSize[i];
                                }

                           
                         }

              	     
                 

                    
                  cout<<" PROCESS "<<"\t\t\tPROCESS SIZE"<<"\t\t\tBLOCK SIZE"<<endl<<endl;
                   for(int i=0;i<numProcess;i++)
                    cout<<" P["<<i<<"] "<<"\t\t\t\t "<<processSize[i]<<"\t\t\t\t "<<temp[i]<<endl;

                

                 break;


 case 3 :        
                        for(int i=0;i<numProcess;i++)
           	         {
              	           temp[i] = -1;
                           int worst=-1;
                          for(int j=0;j<numBlock;j++)
                           {
                            if(blockSize[j]>=processSize[i])
                             {
                               if(worst == -1)
                                worst = j;
                               else if(blockSize[worst] > blockSize[j])
                                 worst = j;
                             }
                           }
                            
                            if(worst != -1){
                                   temp[i] = blockSize[worst];
                                   blockSize[worst] -= processSize[i];
                                }

                           
                         }


                    
                  cout<<" PROCESS "<<"\t\t\tPROCESS SIZE"<<"\t\t\tBLOCK SIZE"<<endl<<endl;
                   for(int i=0;i<numProcess;i++)
                    cout<<" P["<<i<<"] "<<"\t\t\t\t "<<processSize[i]<<"\t\t\t\t "<<temp[i]<<endl;
                  
                     for(int i=0;i<numBlock;i++)
                      flag[i] = 0;

                  

                     break;


 case 4 :   exit(0);

}

cout<<"============================== O P T I O N ====================================="<<endl;
cout<<"(1) FIRST FIT "<<endl;
cout<<"(2) WORST FIT "<<endl;
cout<<"(3) BEST FIT "<<endl;
cout<<"(4) EXIT"<<endl;

cout<<" ENTER YOUR CHOICE "<<endl;
cin>>choice;

}while(choice<5);





return 0;

}



















