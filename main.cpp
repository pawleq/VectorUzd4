#include "Vector.h"
#include "Studentas.h"
#include "timer.h"
#include <iostream>
#include <vector>
#include <chrono>
using std::cout;
using std::endl;
int main()
{

Studentas a;

	Timer t;// Pradėti v1 užpildymo laiko matavimą
	unsigned int sz = 1000000;
	int capacity=0;
	std::vector<Studentas> v1;
	for (int i = 1; i <= sz; ++i)
	{
		if (v1.size() == v1.capacity())
		capacity++;
		v1.push_back(a);
	}
	cout << "stdvector su "<<sz<<" : " << t.elapsed() << endl;
	cout<<"stdvector capacity x : "<<capacity<<endl;
// Baigti v1 užpildymo laiko matavimą

// Pradėti v2 užpildymo laiko matavimą
	capacity=0;
	Timer t2;
	Vector<Studentas> v2;
	for (int i = 1; i <= sz; ++i)
	{
		if (v2.size() == v2.capacity())
		capacity++;
		v2.push_back(a);
	}
	cout << "vector su "<<sz<<" : " << t2.elapsed() << " s" << endl;
	cout<<"vector capacity x : "<<capacity<<endl;



}
