#pragma warning (disable:4996)
#include<stdio.h>
#include<stdlib.h>
#include<memory.h>
#define MAX_SIZE 15
typedef int element;
typedef struct TreeNode {
	element data;
	struct TreeNode* left, * right;
}TreeNode;
typedef struct StackType {
	TreeNode* stack[MAX_SIZE];
	int top;
}StackType;
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
void init(StackType *s) {
	s->top = -1;
}
int is_empty(StackType* s) {
	return s->top == -1;
}
int is_full(StackType* s) {
	return s->top == MAX_SIZE;
}
void push(StackType* s, TreeNode* item) {
	if (is_full(s))return;
	s->stack[++s->top] = item;
}
TreeNode* pop(StackType* s) {
	if (is_empty(s)) {
		fprintf(stderr, "NO DATA!!");
		exit(1);
	}
	return s->stack[s->top--];
}

void level_order(TreeNode* ptr) {
	StackType s;
	init(&s);
	if (ptr->data == NULL)return;
	push(&s, ptr);
	while (!is_empty(&s)) {
		ptr = pop(&s);
		
		
		if (ptr->right)
			push(&s, ptr->right);
		
		if (ptr->left)
			push(&s, ptr->left);
		printf("%d", ptr->data);
	}
}

int main() {
	level_order(root);
	getchar();
	return 0;
	
}