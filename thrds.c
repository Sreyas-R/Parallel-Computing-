#include <stdio.h>
#include<pthread.h>
#include<ctime>
#include<time.h>
#include<iostream>
using namespace std;

/*thread function definition*/
void* threadFunction(void* args)
{
    cout<<"Thread no "<<pthread_self()<<endl;
    pthread_exit(NULL);
}
int main()
{
   // creating thread id
    pthread_t id;
    int ret;
   //hi
    clock_t t;
    t = clock();

    for(int i=0; i<10000; i++)
    {    ret=pthread_create(&id,NULL,&threadFunction,NULL);
    }
    t= clock() -t;
    double time_spend= ((double)(t))/CLOCKS_PER_SEC;
    cout<<"10000 Threads takes"<<time_spend<<endl;

   clock_t t2;
    t2 = clock();

    for(int i=0; i<20000; i++)
    {    ret=pthread_create(&id,NULL,&threadFunction,NULL);
    }
    t2=clock() - t2;
    double time_spend2= ((double)(t2))/CLOCKS_PER_SEC;
    cout<<"20000 Threads takes"<<time_spend2<<endl;

    clock_t t3;
    t3=clock();

    for(int i=0; i<50000; i++)
    {    ret=pthread_create(&id,NULL,&threadFunction,NULL);
    }
    t3=clock()-t3;
    double time_spend3= ((double)(t3))/CLOCKS_PER_SEC;
    cout<<"50000 Threads takes"<<time_spend3<<endl;
    
    return 0;
}
