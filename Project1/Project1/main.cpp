#include <iostream>
#include <vector>



template<class T>
void move_vectors(T&& dest, T&& src)
{
	dest = std::move(src);
}


/*template<> void move_vectors(std::vector<std::string> *&dest, std::vector<std::string> *&src)
{
	*dest = std::move(src);
}*/

int main(int argc, char** argv)
{
	std::string first = {"first"};
	std::string second = {"second"};
	move_vectors(std::move(first), std::move(second));

	std::vector<std::string> one = { "test_string1", "test_string2" };
	std::vector<std::string> two;
	move_vectors(std::move(two), std::move(one));
	return 0;
}