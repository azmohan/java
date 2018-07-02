//Queue.h
//�ö���ʵ��ѭ��������
#ifndef CHARQUEUE_H
#define CHARQUEUE_H
#include <string.h>
#include <stdlib.h>
#define MAXSIZE 4096
typedef int ElemType;
typedef struct Queue {
	ElemType *base;
	int wp;//дָ��
	int rp;//��ָ��
	int queueCnt;//��Ƕ����Ƿ������
} CommQueue;
//����״̬�������ա�������ȷ�����д���
typedef enum {
	QueueFull = 0,
	QueueEmpty,
	QueueOK,
	QueueFail
} QueueStatus;
//��ʼ������
QueueStatus init_queue(CommQueue* queue);
//�����
QueueStatus inQueue(ElemType val, CommQueue* queue);
//������
QueueStatus outQueue(CommQueue* queue, ElemType *val);
//��ȡ����������
int readQueue(ElemType *buf, int size, CommQueue *queue);
//��������д������
int writeQueue(const ElemType *buf, int size, CommQueue *queue);
#endif