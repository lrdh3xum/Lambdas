#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <functional>

/*
	Lambdas are not function, they are a special kind of object called a functor.
	Functors contain an overlaoded operator() that makes them callable
	like a function.

		[ capture-clause ] ( parameters ) -> return-type
		{
			definition
		}
*/

/* Printing values stored in a vector, no lambda.

 	std::vector<std::string> vec{ "foo", "bar", "foobar", "foosy" };

	for (std::vector<std::string>::iterator it = vec.begin(); it != vec.end(); it++)
	{
		if (*it == "testbar")
		{
			std::cout << *it << "\n\n";
		}
		else
		{
			std::cout << "Value not found." << "\n\n";
			break;
		}
	};
*/

void printVector(const std::vector<int> v)
{
	// lambda to get vector values and print them
	std::for_each(v.begin(), v.end(), [](int i)
	{
		std::cout << i << " ";
	});
	std::cout << "\n\n";
}

int main()
{
	std::vector<int> v{ 11,8,7,12,9,8,14 };
	printVector(v);

	// lambda to find first element in vector greater than 9.
	std::vector<int>::iterator p = std::find_if(v.begin(), v.end(), [](int i)
		{
			return i > 11;
		});
	std::cout << "First element greater than 11: \t" << *p << "\n\n";

	// lambda to sort a vector
	std::sort(v.begin(), v.end(), [](const int& a, const int& b)
		{
			return a > b;
		});
	printVector(v);

	// lambda to count numbers greater than 8.
	int gtEight = std::count_if(v.begin(), v.end(), [](int a)
		{
			return (a > 8);
		});
	std::cout << "The number of elements greater than 8: \t" << gtEight <<"\n\n";

	// lambda to remove dupes, requires previous sorting
	auto u = std::unique(v.begin(), v.end(), [](int a, int b)
		{
			return a == b;
		});
	v.resize(std::distance(v.begin(), u));
	printVector(v);


	return 0;
}


