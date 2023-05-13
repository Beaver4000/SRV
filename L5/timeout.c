#include <stdio.h>
#include <pthread.h>
#include <inttypes.h>
#include <errno.h>
#include <sys/neutrino.h>

#define SEC_NSEC 1000000000LL

void * long_thread(void *notused)

{
	printf("V etom potoke moe imya Kuzmin, a imya Alexander, i on vipolnyaetsa 20 sekund \n");
	sleep(20);
}

int main(void)
{
	uint64_t timeout;
	struct sigevent event;
	int rval;
	pthread_t thread_id;

	printf("Prog timer \n");
	event.sigev_notify = SIGEV_UNBLOCK;
	pthread_create(&thread_id, NULL, long_thread, NULL);

	timeout = 10LL*SEC_NSEC;
	TimerTimeout(CLOCK_REALTIME, _NTO_TIMEOUT_JOIN, &event, &timeout, NULL);
	rval = pthread_join(thread_id, NULL);
	if (rval == ETIMEDOUT) printf("istekli 10 sec, potok %d vipolniaetsa, a groupa I992 \n", thread_id);
	sleep(5);
	
	TimerTimeout(CLOCK_REALTIME, _NTO_TIMEOUT_JOIN, &event, &timeout, NULL);
	rval = pthread_join(thread_id, NULL);
	if (rval == ETIMEDOUT) printf("potok %d >25", thread_id);
	else printf("potok %d ended normalno \n", thread_id);
	
return 0;

}