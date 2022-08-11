#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

void *printLab(void *args)
{
    printf("LAB");
    pthread_exit(NULL);
}
void *printPDC(void *args)
{
   printf("PDC ");
    pthread_exit(NULL);
}
int main()
{
    pthread_t thread1;
    //creating the thread
    pthread_t thread2;
    
    pthread_create(&thread1, 0, &printPDC, NULL);
    pthread_create(&thread2, 0, &printLab, NULL);
    pthread_join(thread1, 0);
    
    return  0;
}