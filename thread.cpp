#include <pthread.h>
#include <iostream>
#include <cstdlib>

using namespace std;

int sum;


void *adder(void * number) 
{

    int num = *((int *) number);
    
    for (int i = 1; i <= num; i++)
    {
        sum += i;
    }
    
    pthread_exit(0);
}


int main(int argc, char *argv[])
{
    if (argc != 2) {
        cout << "\nPlease enter a number:" << endl;
        cin>>argv[1];
    }

    int number = atoi(argv[1]);
    
    pthread_t tid; 
    pthread_attr_t attr;
    
    pthread_attr_init(&attr);

    pthread_create(&tid,&attr,adder,(void *) number);
    
    pthread_join(tid,NULL);
    
    cout << "\nSum(" << 1 << ", " << number << ") = " << sum << endl;
    
    return 0;
}


