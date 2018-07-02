//main.c
#include <stdio.h>
#include <string.h>
#include "Queue.h"
int main(void)
{
	CommQueue queue;
	init_queue(&queue);
	int ret;
	int a[10] = {0, 1,2,3,4,5,6,7,8,9};
	ret = writeQueue(a, 10, &queue);
	
	if (ret <= 0) 
	{
		printf("the queue is full\n");
		return -1;
	}
	int buf[20] = {0};
	ret = readQueue(buf, 5, &queue);
	if (ret > 0) 
	{
		printf("%d %d %d %d %d\n", buf[0], buf[1], buf[2], buf[3],buf[4]);
	}
	ret = readQueue(buf, 5, &queue);
	if (ret > 0) 
	{
		printf("%d %d %d %d %d\n", buf[0], buf[1], buf[2], buf[3],buf[4]);
	}
	return 0;
}