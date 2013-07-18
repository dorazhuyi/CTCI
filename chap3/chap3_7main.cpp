#include "chap3_7.h"

int main()
{
	Shelter ST1;
	ST1.enqueue("C1",'c');
	ST1.enqueue("C2",'c');
	ST1.enqueue("D1",'d');
	ST1.enqueue("D2",'d');
	ST1.enqueue("C3",'c');
	ST1.enqueue("D3",'d');
	
	ST1.dequeueCat();
	ST1.dequeueAny();
	ST1.dequeueDog();
	ST1.dequeueAny();
	ST1.dequeueCat();
	ST1.dequeueAny();
	ST1.dequeueAny();
	
	
	return 0;
}
