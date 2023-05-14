#include <stdio.h>
#include <pthread.h>
#include <inttypes.h>
#include <errno.h>
#include <sys/neutrino.h>

void server(void )
{
int rcvid;
int chid;
char message[512];

	printf ("Server start working \n");
	chid=ChannelCreate(0);
	printf("Channel id: %d \n", chid);
	printf("Pid: %d \n", getpid());

while(1)
	{

	rcvid=MsgReceive(chid,message,sizeof(message), NULL);
	printf("Polychili soobshenie, rcvid %X \n",rcvid );
	printf("Soosbshenie takoe: \"%s\". \n", message );

	if (!strcmp(message,"Kuzmin")) strcpy(message, "Alexander");
	else strcpy(message, "Another answer");

	MsgReply(rcvid, EOK, message, sizeof(message));
	printf("\"%s\". \n", message);
}

}

int main()
{
printf("Prog server \n");
server();
sleep(5);
return 0;
}
