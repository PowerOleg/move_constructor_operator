#include <iostream>
#include <vector>

template<class T>
void move_vectors(T& dest, T& src)
{
	dest = std::move(src);
}

/*template<> void move_vectors(std::vector<std::string>& dest, std::vector<std::string>& src)
{
	dest = std::move(src);
}*/

int main(int argc, char** argv)
{
	std::string first = {"first"};
	std::string second = {"second"};
	move_vectors(first, second);

	std::vector<std::string> one = { "test_string1", "test_string2" };
	std::vector<std::string> two;
	move_vectors(two, one);
	for (size_t i = 0; i < two.size(); i++)
	{
		std::cout << two[i] << " ";
	}
	return 0;
}