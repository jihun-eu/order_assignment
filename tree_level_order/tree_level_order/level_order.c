#pragma warning(disable:4996)
#include<stdio.h>
#include<stdlib.h>
#include<memory.h>
#define MAX_SIZE 15
typedef struct TreeNode {
	int data;
	struct TreeNode* left, * right;
}TreeNode;
typedef struct QueueType {
	TreeNode* queue[MAX_SIZE];
	int front, rear;
}QueueType;
TreeNode n1 = { 2, NULL, NULL };
TreeNode n2 = { 1,NULL,NULL };
TreeNode n3 = { 0,&n1,&n2 };
TreeNode n4 = { 6,&n3,NULL };
TreeNode n5 = { 6,NULL,NULL };
TreeNode n6 = { 6,&n5,NULL };
TreeNode n7 = { 2,NULL,NULL };
TreeNode n8 = { 8,&n7,&n6 };
TreeNode n9 = { 1,&n4,&n8 };
TreeNode* root = &n9;
void init(QueueType* q) {
	q->front = q->rear = 0;
}
int is_empty(QueueType* q) {
	return (q->front == q->rear);
}
int is_full(QueueType* q) {
	return (q->front == ((q->rear + 1) % MAX_SIZE));
}
void enqueue(QueueType* q, TreeNode* item) {
	if (is_full(q)) {
		fprintf(stderr, "MAX QUEUE!");
		exit(1);
	}
	q->rear = (q->rear + 1) % MAX_SIZE;
	q->queue[q->rear] = item;
}
TreeNode* dequeue(QueueType* q) {
	if (is_empty(q)) {
		fprintf(stderr, "QUEUE is empty!");
		exit(1);
	}
	q->front = (q->front + 1) % MAX_SIZE;
	return q->queue[q->front];
}
void level_order(TreeNode* ptr) {
	QueueType q;
	TreeNode* temp = ptr;
	int tmp;
	init(&q);
	if (ptr->data == NULL)return;
	enqueue(&q, ptr);
	while (!is_empty(&q)) {
		ptr = dequeue(&q);
		printf("%d", ptr->data);
		if (ptr->left)
			enqueue(&q, ptr->left);
		if (ptr->right)
			enqueue(&q, ptr->right);
	}
}
int main() {
	level_order(root);
	getchar();
	return 0;
}