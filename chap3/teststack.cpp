#include <iostream>
#include "Stack.h"

using namespace std;

int main()
{
 /*
 LStack LS;
 for(int i=0;i<5;i++) LS.push(i);
 while(!LS.isEmpty()) cout << LS.pop() << endl;*/

 AStack* AS = new AStack(7);
 for(int i=0;i<5;i++) AS->push(i);
 
 while(!AS->isEmpty()) cout << AS->pop() << endl;
}
