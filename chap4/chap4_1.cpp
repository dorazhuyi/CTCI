#include <iostream>
#include <algorithm>
#include <stdlib.h>
#include "TNode.h"

using namespace std;

int TreeHeight(TNode* root)
{
	if (root == NULL)
		return -1;
	int lefth = TreeHeight(root->nodeLeft());
	int righth = TreeHeight(root->nodeRight());
	return max(lefth, righth)+1;
}

bool isBalanced(TNode* root)
{
	if(root == NULL)
		return true;
	int hdiff = TreeHeight(root->nodeLeft()) - TreeHeight(root->nodeRight());
	if(abs(hdiff)>1)
		return false;
	else
		return isBalanced(root->nodeLeft())&&isBalanced(root->nodeRight());
}

int main()
{
	TNode* root = new TNode(3);
	root->setLeft(new TNode(5));
	root->setRight(new TNode(7));

	TNode* x = root->nodeLeft();
	x->setLeft(new TNode(9));
	x->setRight(new TNode(11));

	cout << TreeHeight(root) << endl;
	//cout << TreeHeight(root->nodeLeft()) << endl;
	//cout << TreeHeight(root->nodeRight()) << endl;

	cout << isBalanced(root) << endl;

	return 0;
}
