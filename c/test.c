#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <pthread.h>

void* threadFunc(void* arg){ //线程函数
        for(int i=0;i<3;i++)
        printf("In NEW thread\n");

}

int main()
{
    pthread_t tid;
    
    pthread_create(&tid, NULL, threadFunc, NULL);
    
    pthread_join(tid, NULL);
    for(int i=0;i<3;i++)
    printf("In main thread\n"); 
    
    return 0;
}