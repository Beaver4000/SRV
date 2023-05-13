#include <stdio.h>
#include <time.h>
#include <sync.h>
#include <sys/neutrino.h>

barrier_t barrier;

void *thread1 (void * not_used)
{
	time_t now;
	char buf[40];
	time (&now);
	printf("Potok 1, vremia starta %s \n", ctime_r(&now, buf));
	sleep(4);
	printf("Kuzmin Alexander \n");
	barrier_wait(&barrier);
	time(&now);
	printf("Barrier in potok 1, srabotal, time: %s \n", ctime_r(&now, buf));
}

void *thread2 (void * not_used)
{
	time_t now;
	char buf[40];
	time (&now);
	printf("Potok 2, vremia starta %s \n", ctime_r(&now, buf));
	sleep(7);
	printf("Group I992 \n");
	barrier_wait(&barrier);
	time(&now);
	printf("Barrier in potok 2, srabotal, time: %s \n", ctime_r(&now, buf));
}

int main()
{
	time_t now;
	char buf[40];
	barrier_init(&barrier, NULL, 3);
	printf("Start \n");
	pthread_create(NULL, NULL, thread1, NULL);
	pthread_create(NULL, NULL, thread2, NULL);
	time(&now);

	printf(" Main(): waiting u barriera, vremia %s \n", ctime_r(&now,buf));
	barrier_wait(&barrier);

	time(&now);

	printf("barrier in main(), srabotal, time: %s \n", ctime_r(&now,buf));
	sleep(5);
	return 0;
}