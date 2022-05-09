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




int main() {

	Container a;

	construct_container(a, 5, 0);
	


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
		std::cout << c.data[i] << " " << std::endl;
	}

	delete c.data;

}




