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

int& front(Container& c);

int capacity(Container& c);

void clear(Container& c);

bool empty(Container& c);

void pop_back(Container& c);

void push_back(Container& c, int element);

int find(Container& c, int key);


int main() {

	Container a;

	construct_container(a, 5, 0);

	std::cout << "//construct container a\n";
	for (int i = 0; i < a.size; i++)
	{
		std::cout << a.data[i] << " ";
	}

	std::cout << "\nsize(a): " << size(a) << std::endl;
	std::cout << "capacity(a): " << capacity(a) << std::endl;

	std::cout << "\n//add elements to a\n";

	at(a, 0) = 10;
	at(a, 3) = 5;

	std::cout << "at(a, 0) = " << at(a, 0) << std::endl;
	std::cout << "at(a, 3) = " << at(a, 3) << std::endl;

	for (int i = 0; i < size(a); i++)
	{
		std::cout << a.data[i] << " ";
	}

	std::cout << "\n\nfront(a) = " << front(a) << std::endl;
	std::cout << "back(a) = " << back(a) << std::endl;

	std::cout << "\n//destory container a\n";
	destroy_container(a);

	std::cout << "\n//Exception Handling";

	try {
		std::cout << "\nfront(a) = " << front(a) << std::endl;
	}
	catch (std::out_of_range e) { std::cerr << e.what(); }

	try {
		std::cout << "at(a, 9) = " << at(a, 9) << std::endl;
	}
	catch (std::string msg) { std::cerr << "\n" << msg << std::endl; }

	std::cout <<
	"\n\n-------------------------------------------------------------";

	std::cout << "\n//Container b\nconstruct_container(b)\n";

	Container b;

	construct_container(b, 0, 0);

	std::cout << "size(b) = " << size(b);
	std::cout << ", capacity(b) = " << capacity(b) << std::endl;
	
	std::cout << "\n//add elements to b\n";

	std::cout << "push_back(b, 0); push_back(b, 1);\n";
	push_back(b, 0);
	push_back(b, 1);

	std::cout << "push_back(b, 2; push_back(b, 3)\n";
	push_back(b, 2);
	push_back(b, 3);

	std::cout << "\nb = ";

	for (int i = 0; i < b.size; i++)
	{
		std::cout << b.data[i] << " ";
	}

	std::cout << "\nsize(b) is " << size(b);
	std::cout << "; capacity(b) is " << capacity(b);
	std::cout << "\nat(b, 1) is " << at(b, 1);

	at(b, 1) = 88;

	std::cout << "\nb = ";

	for (int i = 0; i < b.size; i++)
	{
		std::cout << b.data[i] << " ";
	}
	std::cout << "\n\n//remove the last element";

	pop_back(b);
	std::cout << "\nb = ";

	for (int i = 0; i < b.size; i++)
	{
		std::cout << b.data[i] << " ";
	}

	std::cout << "\n\n//add 2 more elements";
	push_back(b, 55);
	push_back(b, 75);

	std::cout << "\npush_back(b, 55); push_back(b, 75)";

	std::cout << "\nb = ";

	for (int i = 0; i < b.size; i++)
	{
		std::cout << b.data[i] << " ";
	}

	std::cout << "\n\n//clear the container\n";
	std::cout << "clear(b)";
	clear(b);

	std::cout << "\nsize(b): " << size(b);
	std::cout << "; capacity(b) is " << capacity(b);

	std::cout << "\n\n";

	if (empty(b) == 1)
	{
		std::cout << "empty(b) is true" << std::endl;
	}
	else
	{
		std::cout << "empty(b) is false" << std::endl;
	}

	std::cout << "\npush_back(b, 10); push_back(b, 20); push_back(b, 30)";
	std::cout << "\npush_back(b, 40); push_back(b, 50); push_back(b, 60)";

	push_back(b, 10);
	push_back(b, 20);
	push_back(b, 30);
	push_back(b, 40);
	push_back(b, 50);
	push_back(b, 60);

	std::cout << "\nb = ";

	for (int i = 0; i < b.size; i++)
	{
		std::cout << b.data[i] << " ";
	}

	std::cout << "\nsize(b) is " << size(b);
	std::cout << "; capacity(b) is " << capacity(b) << std::endl;

	std::cout << "\n//Continue container b testing" << std::endl;

	int i = find(b, 30);
	std::cout << "int i = find(b, 30), i = " << i << std::endl;

	i = find(b, 999);
	std::cout << "int i = find(b, 999), i = " << i << std::endl;

	int* ptr = data(b);

	std::cout << "\nb = ";

	for (int i = 0; i < b.size; i++)
	{
		std::cout << *(ptr + i) << " ";
	}
	std::cout << "\n//Destroy container";


	return 0;
}

void construct_container(Container& c, int s, int val)
{
	c.size = s;
	c.capacity = s;

	c.data = new int[c.capacity];

	for (int i = 0; i < s; i++)
	{
		c.data[i] = val;
	}

}

void destroy_container(Container& c)
{
	delete c.data;
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

int& front(Container& c)
{
	return c.data[0];
}

int capacity(Container& c)
{
	return c.capacity;
}

void clear(Container& c)
{
	c.size = 0;
	delete c.data;
	c.data = nullptr;
}

bool empty(Container& c)
{
	
		if (c.data == nullptr)
		{
			return true;
		}
		else
		{
			return false;
		}
	
}

void pop_back(Container& c)
{
	c.capacity = c.size - 1;

	int* tempArray = new int[c.capacity];

	for (int i = 0; i < c.capacity; i++)
	{
		tempArray[i] = c.data[i];
	}

	c.data = tempArray;

	c.size = c.size - 1;
}

void push_back(Container& c, int element)
{
	c.capacity = c.size + 1;


	int* tempArray = new int[c.capacity];

	for (int i = 0; i < c.capacity; i++)
	{
		if (i == c.capacity - 1)
		{
			tempArray[i] = element;
		}
		else {
			
			tempArray[i] = c.data[i];
		}
	}

	c.data = tempArray;

	c.size = c.size + 1;

}

int find(Container& c, int key)
{
	for (int i = 0; i < c.size; i++)
	{
		if (c.data[i] == key)
		{
			return i;
		}
	}
	return -1;
}




