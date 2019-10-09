#include <stdio.h>
#include <stdlib.h>

#define MAX_STACK_SIZE 10


typedef struct TreeNode {
	int data;
	struct TreeNode* left, * right;
} TreeNode;


typedef struct {
	TreeNode* stack[MAX_STACK_SIZE];
	int top;
} StackType;
//          7 
//     5        6
//1     2    3       4
TreeNode n1 = { 1, NULL, NULL };
TreeNode n2 = { 2, NULL, NULL };
TreeNode n3 = { 5, &n1, &n2 };
TreeNode n4 = { 3, NULL, NULL };
TreeNode n5 = { 4, NULL, NULL };
TreeNode n6 = { 6, &n4, &n5 };
TreeNode n7 = { 7, &n3, &n6 };
TreeNode* root = &n7;


void init(StackType* s) {
	s->top = -1;
}

int is_empty(StackType* s) {
	return (s->top == -1);
}

int is_full(StackType* s) {
	return (s->top == (MAX_STACK_SIZE - 1));
}

void push(StackType* s, TreeNode* item) {
	if (is_full(s)) {
		fprintf(stderr, "스택 포화 에러\n");
		return;
	}
	else s->stack[++(s->top)] = item;
}

TreeNode* pop(StackType* s)
{
	if (is_empty(s)) {
		fprintf(stderr, "스택 공백 에러\n");
		exit(1);
	}
	else return s->stack[(s->top)--];
}

void instackorder() {
	StackType stack;

	TreeNode* node = root;
	init(&stack);
	for (;;) {
		if (node == NULL && is_empty(&stack))
			break;
		if (node != NULL) {
			push(&stack, node);
			node = node->left;
		}
		else {
			node = pop(&stack);
			printf("%d ", node->data);
			node = node->right;
		}
	}
}

void prestackorder() {
	StackType stack;

	TreeNode* node = root;

	init(&stack);

	for (;;) {
		if (node == NULL && is_empty(&stack))
			break;
		if (node != NULL) {
			push(&stack, node);
			printf("%d ", node->data);
			node = node->left;

		}
		else {
			node = pop(&stack);
			printf("%d ", node->data);
			node = node->right;
		}
	}
}

void poststackorder() {
	StackType stack;
	StackType temp;

	StackType* pstack = &temp;

	TreeNode* node = root;

	int i;

	init(&stack);
	init(&temp);
	for (;;) {
		if (node == NULL && is_empty(&stack))
			break;
		if (node != NULL) {
			push(&stack, node); push(&temp, node);
			node = node->right;
		}
		else {
			node = pop(&stack);
			node = node->left;
		}
	}

	for (i = pstack->top; i >= 0; i--) {
		printf("%d ", pstack->stack[i]->data);
	}
}




void main() {
	printf("inorder: ");
	instackorder();
	printf("\n");
	printf("preorder: ");
	prestackorder();
	printf("\n");
	printf("postorder: ");
	poststackorder();
}