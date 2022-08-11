#include<omp.h>
#include<stdio.h>
#include<iostream>
using namespace std;

int main()
{
    int pid=0;
    omp_set_num_threads(1000);

    #pragma omp parallel private(pid)
    {
        cout<<omp_get_thread_num()<<" ";
    }

    return 0;
}