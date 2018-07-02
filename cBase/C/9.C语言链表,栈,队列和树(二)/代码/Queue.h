//Queue.h
//用读列实现循环缓冲区
#ifndef CHARQUEUE_H
#define CHARQUEUE_H
#include <string.h>
#include <stdlib.h>
#define MAXSIZE 4096
typedef int ElemType;
typedef struct Queue {
	ElemType *base;
	int wp;//写指针
	int rp;//读指针
	int queueCnt;//标记队列是否满或空
} CommQueue;
//队列状态：满、空、运行正确、运行错误
typedef enum {
	QueueFull = 0,
	QueueEmpty,
	QueueOK,
	QueueFail
} QueueStatus;
//初始化队列
QueueStatus init_queue(CommQueue* queue);
//入队列
QueueStatus inQueue(ElemType val, CommQueue* queue);
//出队列
QueueStatus outQueue(CommQueue* queue, ElemType *val);
//读取缓冲区数据
int readQueue(ElemType *buf, int size, CommQueue *queue);
//往缓冲区写入数据
int writeQueue(const ElemType *buf, int size, CommQueue *queue);
#endif