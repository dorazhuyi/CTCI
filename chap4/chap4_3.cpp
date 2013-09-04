#include <iostream>
#include <vector>
#include "TNode.h"

using namespace std;

TNode* convertBST(vector<int> array, int L, int R)
{
	if(L>R)
		return NULL;
	int i = (L+R)/2;
	//cout << "index: " << i << endl;
	TNode* root = new TNode(array[i]);
	root->setLeft(convertBST(array, L, i-1));
	root->setRight(convertBST(array, i+1, R));
	return root;
}

void inorder(TNode* root)
{
	if(root != NULL)
	{
		inorder(root->nodeLeft());
		cout << root->nodeValue() << endl;
		inorder(root->nodeRight());
	}
}

int main()
{
	//int myint[] = {0,1,2,3,4,5}; 
	int myint[] = {2,4,7,9,10,25,27}; 
	vector<int> SA  (myint, myint + sizeof(myint)/sizeof(int));

	/* test
	TNode testroot(3);
	testroot.setLeft(NULL);*/

	/* Display vector */
	for(int i=0;i<SA.size();++i)
		cout << SA[i] << endl;

	TNode* resultBST = convertBST(SA, 0, SA.size()-1);

	inorder(resultBST);

	return 0;
}
