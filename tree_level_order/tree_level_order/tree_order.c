#pragma warning(disable:4996)
#include <stdio.h>
#include<stdlib.h>
#include<memory.h>
typedef int element;
typedef struct TreeNode {
	element data;
	struct TreeNode* left, * right;

}TreeNode;
/*X
		   1
	   6       8
   0        2     6
2     1         6*/
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
void inorder(TreeNode* root) {
	if (root) {
		inorder(root->left);
		printf("%d", root->data);
		inorder(root->right);
	}
}
void preorder(TreeNode* root) {
	if (root) {
		printf("%d", root->data);
		preorder(root->left);
		preorder(root->right);
	}
}
void postorder(TreeNode* root) {
	if (root) {
		postorder(root->left);
		postorder(root->right);
		printf("%d", root->data);
	}
}
int main() {
	inorder(root);
	printf("\n");
	preorder(root);
	printf("\n");
	postorder(root);
	printf("\n");
	getchar();
	return 0;
}

