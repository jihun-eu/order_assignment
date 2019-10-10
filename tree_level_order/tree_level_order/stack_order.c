#pragma warning (disable:4996)
#include<stdio.h>
#include<stdlib.h>
#include<memory.h>
#define MAX_SIZE 15
#define False 1
/*X
		   1
	   6       8
   0        2     6
2     1         6*/
typedef int element;
typedef struct TreeNode {
	element data;
	struct TreeNode* left, * right;
	int check;
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

void Stack_preorder(TreeNode* ptr) {
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

void Stack_inorder(TreeNode* ptr) {
	StackType s;
	StackType s_temp;
	TreeNode* temp = ptr;
	
	init(&s);
	if (ptr->data == NULL)return;
	while (ptr) {
		push(&s, ptr);
		ptr->check = False;
		ptr=ptr->left;
	}
	while (!is_empty(&s)) {
		ptr = pop(&s);
		printf("%d", ptr->data);
		
		
		if (ptr->left && ptr->left->check != False) {
			push(&s, ptr->left);
			ptr->left->check = False;
		}
		if (ptr->right && ptr->right->check != False) {
			push(&s, ptr->right);
			ptr->right->check = False;
			if (ptr->right->left && ptr->right->left->check != False) {
				push(&s, ptr->right->left);
				ptr->right->left->check = False;
			}
		}
		
	}
}
void Stack_postorder(TreeNode* ptr) {
	/*StackType s;
	init(&s);
	while (ptr) {
		push(&s, ptr);
		ptr->check = False;
		if (ptr->right) {
			push(&s, ptr->right);
			ptr->right->check = False;
			
			if (ptr->right->right){
				push(&s, ptr->right->right);
				ptr->right->right->check = False;
			}
			if (ptr->right->left) {
				push(&s, ptr->right->left);
				ptr->right->left->check = False;
			}
		}
		ptr = ptr->left;
	}*///1차구현(스택에 들어가지지 않음)
	/*while (ptr||!is_empty(&s)) {
		push(&s, ptr);
		ptr->check = False;
		if (ptr->right && ptr->right->check != False)
			ptr = ptr->right;
		else if (ptr->left && ptr->left->check != False)
			ptr = ptr->left;
		else {
			while (!ptr->left) {
				ptr = pop(&s);
				printf("%d", ptr->data);
			}
		}
	}*///2차구현(스택에 들어가지지 않음)
	/*
	while (!is_empty(&s)) {
		ptr = pop(&s);
		printf("%d", ptr->data);


		if (ptr->left && ptr->left->check != False) {
			push(&s, ptr->left);
			ptr->left->check = False;
		}
		if (ptr->right && ptr->right->check != False) {
			push(&s, ptr->right);
			ptr->right->check = False;
			if (ptr->right->left && ptr->right->left->check != False) {
				push(&s, ptr->right->left);
				ptr->right->left->check = False;
			}
		}

	}	*///3차구현(스택에 들어가지지 않음)
	/*while (ptr) {
		if (ptr->check != False) {
			push(&s, ptr);
			ptr->check = False;
		}
		if (ptr->left) {
			ptr = ptr->left;
			push(&s, ptr);
			ptr->check = False;
		}
		if (ptr->right) {
			ptr = ptr->right;
			push(&s, ptr);
			ptr->check = False;
		}
		
	}
	while (!is_empty(&s)) {
		ptr = pop(&s);
		printf("%d", ptr->data);
		if (ptr->right && ptr->right->check != False) {
			push(&s, ptr);
			ptr = ptr->right;
			push(&s, ptr);
			ptr->right->check = False;

		}
		else if (ptr->left && ptr->left->check != False) {
			ptr = ptr->left;
			push(&s, ptr);
		}
	}*///4차구현(무한반복)
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
		printf("%d", pstack->stack[i]->data);
	}

}
int main() {
	
	printf("preorder: ");
	Stack_preorder(root);
	printf("\n");
	printf("inorder: ");
	Stack_inorder(root);
	printf("\n");
	printf("postorder: ");
	Stack_postorder(root);
	printf("\n");
	getchar();
	return 0;
	
}