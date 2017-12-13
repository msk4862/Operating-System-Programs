#include <iostream>
#include <cmath>
using namespace std;

class Frame_Table
{ private:
    int **ft;
    int pg_size, pm_size, nframes;
    int pids[100], pnos[100];
    //int p_no;
 
  public:
   Frame_Table(int n1,int n2)
    { //p_no=0;
      pg_size=n1;
      pm_size=n2;
      nframes= ceil(pm_size/pg_size);
      ft=new int*[nframes];
      for(int i=0;i<nframes;i++)
        ft[i]=new int[2];
      for(int i=0;i<nframes;i++)
         for(int j=0;j<2;j++)
           ft[i][j]=-1;
    }
   void allocate(int a,int b);
   void deallocate(int a);
   void frame_no(int a,int b);
   void display_ft();

};

void Frame_Table::allocate(int a,int b)
{  int pid=a;
   int psize=b;  //program size
   int nf= ceil(psize/pg_size);
   int j=0;
   while(pids[j]!=0 && j<100)
         j++;
   if(pids[j]==0)
   {   pids[j]=pid;
       pnos[j]=nf;
   }
   int n=0,i=0;
   while(i<nframes && n<nf)
   {if(ft[i][0]==-1)
      {ft[i][0]=pid;
       ft[i][1]=n;
       n++;}
    i++;
    }
   if(i==nframes && n<nf)
   { cout<<"NOT ENOUGH MEMORY PRESENT!!! MEMORY NOT ALLOCATED!! \n\n";
     deallocate(pid);}
   else if(n==nf)
   {cout<<"MEMORY ALLOCATED FOR PROCESS "<<pid<<endl<<endl;}
   
   return;
}


void Frame_Table::deallocate(int a)
{   int pid=a;
    bool found=false;
    int j=0;
    while(j<100 && (!found))
    { if(pids[j]==pid)
        {pids[j]=0;
         pnos[j]=0;
         found=true;} 
      j++;
     }
    if(!found)
    {cout<<"PROCESS with PID = "<<pid<<"is NOT ALLOCATED MEMORY!!\n\n";
     return;}
    else{
    for(int i=0; i<nframes; i++)
       { if(ft[i][0]==pid)
            {ft[i][0]=-1;
             ft[i][1]=-1;
             }
        }
    }
    
}

void Frame_Table::frame_no(int a,int b)
{    int pid=a;
     int p_no=b;
     bool found=false;
     int j=0;
     
     while(j<100 && (!found))
     {  if(pids[j]==pid)
        { if(pnos[j]>b)
             found = true;
          else
            {cout<<"INVALID PAGE NO FOR VALID PROCESS ID!!\n\n";
              return;}
         }
        j++;
     }  
     if(!found)
     { cout<<"INVALID PROCESS ID!!\n\n";
       return; 
     }
     
     else 
     { for(int i=0;i<nframes;i++)
         { if( (pid==ft[i][0]) && (ft[i][1]==p_no) )
              {cout<<"THE CORRESPONDING FRAME NUMBER IS "<<i<<endl<<endl;
               break;
               }
          }     
     }
     return;
}

void Frame_Table::display_ft()
{ cout<<"\n********* FRAME TABLE ***************\n\n";
  cout<<"FRAME NO.    PID    PAGE NO.\n\n";
  for(int i=0;i<nframes;i++)
    cout<<"   "<<i<<"       "<<ft[i][0]<<"        "<<ft[i][1]<<endl;
  cout<<endl;
}

int main( )
{ int n1,n2;
  cout<<"Enter the PAGE SIZE : ";
  cin>>n1;
  cout<<"Enter the PHYSICAL MEMORY SIZE : ";
  cin>>n2;
  Frame_Table ft(n1,n2);
  int ch1;
  
  do
{ cout<<"\nCHOOSE:\n1).Allocate Memory \n2).Deallocate Memory \n3).Get Frame Number\n4).Display Frame Table\n5).Exit\n";
  cout<<"\nEnter your Choice : ";
  cin>>ch1;
  switch(ch1)
  { case 1:	 { int pid,psize;
                   cout<<"\nEnter PROCESS ID to allocate memory : ";
	           cin>>pid;
                   cout<<"\nEnter PROCESS SIZE : ";
	           cin>>psize;
	           ft.allocate(pid,psize);
                   break;
                 }

    case 2:     {  int pid;
                   cout<<"\nEnter PROCESS ID to deallocate memory : ";
	           cin>>pid;
                   ft.deallocate(pid);
                   break;
                }

    case 3:     {  int pid,pno;
                   cout<<"\nEnter PROCESS ID : ";
	           cin>>pid;
                   cout<<"\nEnter PAGE NUMBER : ";
	           cin>>pno;
                   ft.frame_no(pid,pno);
                   break;
                }

    case 4:     { ft.display_ft();
                  break;
                }
  
   }
}while(ch1!=5);
 return 0;
}



