//chap3_7.h
#include <iostream>
#include <queue>
#include <string>

using namespace std;

class Animal
{
  public:
	Animal();
	Animal(string, char);
	void setName(string);
	void setOrder(int);
	void setType(char);
	string getName();
	int getOrder();
  private:
	string name;
	int order;
	char type;
};

// Time Stamp would keep increasing. Any way to solve? < add a reset function?
class Shelter
{
  public:
	Shelter();
	~Shelter();
	void enqueue(string,char);
	string dequeueCat();
	string dequeueDog();
	string dequeueAny();
  private:
	queue<Animal> *Cat;
	queue<Animal> *Dog;
	int num;
};


