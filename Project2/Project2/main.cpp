#include <iostream>
#include <vector>



template<class T>
void move_vectors(T& dest, T& src)
{
	dest = std::move(src);
}

int main(int argc, char** argv)
{
	std::vector<std::string> one = { "test_string1", "test_string2" };
	std::vector<std::string> two;
	move_vectors(two, one);
	return 0;
}