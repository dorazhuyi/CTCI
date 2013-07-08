#include <iostream>
#include <stack>

using namespace std;

class Tower
{
  public:
  	Tower();
	Tower(int);
	void addDisk(int);
	void moveTopTo(Tower*);
	void moveDisks(int, Tower*, Tower*);
	int towerIndex();
  private:
	stack<int> *disk;  
	int index;
};

Tower::Tower()
{
	disk = new stack<int>;
	index = -1;
}

Tower::Tower(int n)
{
	disk = new stack<int>;
	index = n;
}

void Tower::addDisk(int d)
{
	/* Since this function is not only used in the initialization but in
	   the recursions, d could be a smaller disk when this tower is used
	   as a buffer. */
	if( disk->empty() || d < disk->top() ) // " d == disk -> top() - 1 " only holds in initialization
		disk->push(d);
	else
		cout << "Error: cannot add new disk. Please check disk size." << endl;
	cout << "Disk " << d << " added to tower " << index << "." << endl;
}

/*  This function is actually moving the [TOP] disk.
	See how it works in the recursive process.*/
void Tower::moveTopTo(Tower *t)
{
	int top = disk->top();
	disk->pop();
	cout << "Disk " << top << " moved from " << index << " to " << t->towerIndex() << ". ";
	t->addDisk(top);
}

void Tower::moveDisks(int n, Tower *destination, Tower *buffer)
{
	if( n > 0 ) {
		moveDisks(n-1, buffer, destination);
		moveTopTo(destination);
		buffer->moveDisks(n-1, destination, this);
	}
}

int Tower::towerIndex()
{
	return index;
}

int main()
{
	Tower *hanoi[3]; // An array of Tower pointers.
	for(int i = 0; i < 3; i++) {
		hanoi[i] = new Tower(i); 
	}
	
	int ndisk = 5;
	
	for(int i = ndisk; i > 0; i--) {
		hanoi[0] -> addDisk(i);
	}
	
	hanoi[0] -> moveDisks(ndisk, hanoi[2], hanoi[1]);


}
