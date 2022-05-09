//Sam Moores
//Project 04
//
//
//
//
//
//

#include <iostream>

struct Container {
	int size = 0;
	int capacity = 0;
	int* data = nullptr;
};

//Constructs a Container c with a size s and initial value val
//Defaults are zero
void construct_container(Container& c, int s, int val);

void destroy_container(Container& c);

int* data(Container& c);

int size(Container& c);

int& at(Container& c, int i);

int& back(Container& c);

int capacity(Container& c);

void clear(Container& c);

bool empty(Container& c);


int main() {

	Container a;

	construct_container(a, 5, 0);

	std::cout << "//Container a\n";
	for (int i = 0; i < a.size; i++)
	{
		std::cout << a.data[i] << " ";
	}

	std::cout << "\nsize(a): " << size(a) << std::endl;
	std::cout << "capacity(a): " << capacity(a) << std::endl;

	std::cout << "\n//add elements to a\n";
	at(a, 0) = 10;
	at(a, 3) = 5;

	for (int i = 0; i < size(a); i++)
	{
		std::cout << a.data[i] << " ";
	}

	

	return 0;
}

void construct_container(Container& c, int s, int val)
{
	c.size = s;
	c.capacity = s;

	c.data = new int[s];

	for (int i = 0; i < s; i++)
	{
		c.data[i] = val;
	}

}

void destroy_container(Container& c)
{
	delete &c;
}

int* data(Container& c)
{
	int* p1 = &c.data[0];

	return p1;
}

int size(Container& c)
{
	return c.size;
}

int& at(Container& c, int i)
{
	return c.data[i];
}

int& back(Container& c)
{
	return c.data[c.size - 1];
}

int capacity(Container& c)
{
	return c.capacity;
}

void clear(Container& c)
{
	delete c.data;
}

bool empty(Container& c)
{
	
		if (c.data == nullptr)
		{
			std::cout << "c.data == nullptr" << std::endl;
			return true;
		}
		else
		{
			std::cout << "c.data != nullptr" << std::endl;
			return false;
		}
	
}




