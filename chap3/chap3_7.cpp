#include <iostream>
#include <list>

using namespace std;

class Shelter
{
  public:
	shelter();
	void enqueue(char);
	void dequeueAny();
	void dequeueDog();
	void dequeueCat();
	bool isEmpty();
	bool isEmptyCat();
	bool isEmptyDog();
  private:
	list<int> *Cat;
	list<int> *Dog;
	int oldestCat;
	int newestCat;
	int oldestDog;
	int newestDog;
};

Shelter::Shelter()
{
	Cat = new list<int>; 
	Dot = new list<int>;
	oldestCat = -1;
	newestCat = -1;
	oldestDog = -1;
	newestDog = -1;
}

void Shelter::enqueue(char type)
{
	if(type == c)
		Cat->
}

