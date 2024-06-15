#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define NUM_THR 10
#define NUM_WRK 10000

void * work(void * ctx);

struct cr {
	int id;
	int *c;//contador
	pthread_mutex_t *mtx;
};

main(){
	
	int count = 0;
	pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
	struct cr ctx[NUM_THR];
	pthread_t worker[NUM_THR] = {};
	
	for(int i=0;i< NUM_THR; i++){
		ctx[i].id = i;
		ctx[i].c = &count;
		ctx[i].mtx = &mutex;
		pthread_create(&worker[i],NULL, work, &ctx[i]);
	}//for
	
	for(int i=0;i< NUM_THR; i++){
		pthread_join(worker[i],NULL);
	}//for
	
	printf("Count %d\n\n",count);
	
}//main

void * work(void* ctx){
	
	struct cr *ptr = (struct cr *)ctx;
	pthread_mutex_lock(ptr->mtx);
	
	for(int i=0;i< NUM_WRK;i++) *ptr->c += 1;
	*ptr->c += ptr->id;
	printf("Thread %d inc %d + %d: %d \n",ptr->id,NUM_WRK,ptr->id, *ptr->c);
	
	pthread_mutex_unlock(ptr->mtx);
}//work


