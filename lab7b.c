// Maria Syed
// CS-16004

// Lab 7 - Ex 2

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#define NUM_THREADS 5

char *messages[NUM_THREADS];

void *PrintHello(void *threadid){
  long taskid;
  sleep(1);
  taskid = (long) threadid;
  printf("Thread %ld: %s\n", taskid ,messages[taskid]);
  pthread_exit(NULL);
}

int main(int argc, char *argv[]){
  pthread_t threads[NUM_THREADS];
  long taskids[NUM_THREADS];
  int rc, t;
  messages[0]= "English: Hello world!";
  messages[1]= "French: Bonjour ls monde!";
  messages[2]= "Spanish: Hola sl mundo!";
  messages[3]= "Klingon: Mug neh!";
  messages[4]= "German: Guten tag wait!";

  for(t=0; t<NUM_THREADS; t++){
    taskids[t] = t;
    printf("creating thread %d\n", t);
    rc = pthread_create(&threads[t], NULL, PrintHello, (void*)taskids[t]);
    if(rc){
      printf("Error; return code from pthread_create() is %d\n", rc);
      exit(-1);
    }
  }
  pthread_exit(NULL);
}
