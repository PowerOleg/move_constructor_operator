#include <iostream>
#include <vector>

class Big_integer 
{
public:
	Big_integer(const char* new_chars = "") : result_char{nullptr}
	{
		if (strlen(new_chars) > 0)
		{
			std::size_t n = std::strlen(new_chars) + 1;
			result_char = new char[n];
			std::memcpy(result_char, new_chars, n);
		}
		else
		{
			throw std::logic_error("Big_integer can't be empty");
		}
	}
	~Big_integer()
	{
		delete[] result_char;
	}


private:
	//std::vector<char> result;
	char* result_char;
};

template<class T>
void move_vectors(T& dest, T& src)
{
	dest = std::move(src);
}

int main(int argc, char** argv)
{
	auto number1 = Big_integer("114575");
	auto number2 = Big_integer("78524");
	//auto result = number1 + number2;
	//std::cout << result; // 193099


	return 0;
}