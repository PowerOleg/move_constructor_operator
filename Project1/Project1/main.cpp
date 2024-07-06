#include <iostream>
#include <vector>



template<class T>
void move_vectors(T dest, T&& src)
{
	std::string tmp(std::move(src));
	//T temp = src;
	//&&src = nullptr;
	//dest = temp;
}

/*template<> void move_vectors(std::vector<std::string> dest, std::vector<std::string>&& src)
{
	std::vector <std::string> temp = src;
	//src.erase(src.begin(), src.end());
	delete[] src.data();
	dest = temp;
}*/

int main(int argc, char** argv)
{
	std::string first = {"first"};
	std::string second = { "second" };
	//std::string** second_link_link = &&second;
	move_vectors(first, "second");

	//std::vector<std::string> one = { "test_string1", "test_string2" };
	//std::vector<std::string> two;
	//move_vectors(two, one);
	return 0;
}