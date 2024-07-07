#include <iostream>
#include <vector>
#include <string>

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

	Big_integer(const Big_integer& other) : result_char{other.result_char}//не понимаю почему есть доступ до other.result_char ведь private?
	{}
	Big_integer& operator=(const Big_integer& other)
	{
		auto new_big_int = new Big_integer(other);
		return /**this=new_big*/*new_big_int;
	}

	Big_integer(Big_integer&& other) noexcept : result_char{std::exchange(other.result_char, nullptr)}
	{}
	Big_integer& operator=(Big_integer&& other) noexcept
	{
		std::swap(result_char, other.result_char);
		return *this;
	}

	Big_integer& operator+(Big_integer& right)
	{
		long left_value = std::stol(this->result_char);
		//long right_value = std::stol(right.result_char);

		delete[] this->result_char;
		*this = std::move(right);


		long right_value = std::stol(this->result_char);

		long result = left_value + right_value;
		std::string str = std::to_string(result);

		char* result_char_new = new char[str.length() + 1];
		for (size_t i = 0; i < str.length() + 1; i++)
		{
			result_char_new[i] = str[i];
		}
		delete[] this->result_char;
		this->result_char = std::move(result_char_new);


		auto big_int_new = new Big_integer(std::move(*this));
		return *big_int_new;
	}
	friend std::ostream& operator<<(std::ostream& os, Big_integer& big_integer);
private:
	//std::vector<char> result;
	char* result_char;
};
std::ostream& operator<<(std::ostream& os, Big_integer& big_integer)
{
	return os << big_integer.result_char;
}

template<class T>
void move_vectors(T& dest, T& src)
{
	dest = std::move(src);
}

int main(int argc, char** argv)
{
	auto number1 = Big_integer("114575");
	auto number2 = Big_integer("78524");
	auto result = number1 + number2;
	std::cout << result; // 193099
	return 0;
}