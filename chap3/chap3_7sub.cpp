#include "chap3_7.h"

Animal::Animal()
{
	name = "No name";
	order = -1;
	type = 'o';
}

Animal::Animal(string n, char t)
{
	name = n;
	type = t;
}

void Animal::setName(string n)
{
	name = n;
}

void Animal::setOrder(int ord)
{
	order = ord;
}

void Animal::setType(char t)
{
	type = t;
}

string Animal::getName()
{
	return name;
}

int Animal::getOrder()
{
	return order;
}

Shelter::Shelter()
{
	Cat = new queue<Animal>; 
	Dog = new queue<Animal>;
	num  = -1;
}

Shelter::~Shelter()
{
	delete Dog;
	delete Cat;
}

void Shelter::enqueue(string aname, char type)
{
	num++;
	if(type == 'c')
	{
		Animal acat(aname,'c');
		acat.setOrder(num);
		Cat->push(acat);
		cout << "Cat " << aname << " added into shelter." << endl;
	} else if(type == 'd')
	{
		Animal adog(aname,'d');
		adog.setOrder(num);
		Dog->push(adog);
		cout << "Dog " << aname << " added into shelter." << endl;
	}	
}

string Shelter::dequeueCat()
{
	if(!Cat->empty()) {
		string catname = Cat->front().getName();
		Cat->pop();
		cout << "Cat " << catname << " is taken out." << endl;
		return catname;
	} else { 
		cout << "No cat in the shelter." << endl;
		return "No name";
	}
}

string Shelter::dequeueDog()
{
	if(!Dog->empty()) {
		string dogname = Dog->front().getName();
		Dog->pop();
		cout << "Dog " << dogname << " is taken out." << endl;
		return dogname;
	} else { 
		cout << "No dog in the shelter." << endl;
		return "No name";
	}
}

string Shelter::dequeueAny()
{
	string aname;
	
	if( Cat->empty() && Dog->empty() )
	{
		cout << "No animal in shelter." << endl;
		return "No name";
	} else if(Cat->empty()) {
		aname = dequeueDog();
		return aname;
	} else if (Dog->empty()) {
		aname = dequeueCat();
		return aname;
	}
	
	int oldestCat = Cat->front().getOrder();
	int oldestDog = Dog->front().getOrder();
	if(oldestCat < oldestDog)
		aname = dequeueCat();
	else
		aname = dequeueDog();
	return aname;
}


