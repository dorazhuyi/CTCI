#include <iostream>
#include <algorithm>
#include <stdlib.h>
#include "TNode.h"

using namespace std;

int checkHeight(TNode* root)
{
	if (root == NULL)
		return -1;

	//Check Left Child
	int H_left = checkHeight(root->nodeLeft());
	if (H_left == -2)
		return -2;

	//Check Right Child
	int H_right = checkHeight(root->nodeRight());
	if (H_right == -2)
		return -2;

	//Check current
	int H_diff = abs(H_left) - abs(H_right);
	if (H_diff > 1)
		return -2;
	else
		return max(H_left, H_right)+1;
}

bool isBalanced(TNode* root)
{
	if(checkHeight(root) == -2)
		return false;
	else
		return true;
}

int main()
{
	TNode* root = new TNode(3);
	root->setLeft(new TNode(5));
	root->setRight(new TNode(7));

	TNode* x = root->nodeLeft();
	x->setLeft(new TNode(9));
	x->setRight(new TNode(11));

	cout << checkHeight(root) << endl;
	//cout << TreeHeight(root->nodeLeft()) << endl;
	//cout << TreeHeight(root->nodeRight()) << endl;

	cout << isBalanced(root) << endl;

	return 0;
}
