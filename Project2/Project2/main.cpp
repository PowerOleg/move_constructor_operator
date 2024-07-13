#include <iostream>
#include <vector>
#include <string>

class Big_integer 
{
public:
	Big_integer(const std::string new_chars) : result_char{new_chars}
	{
		if (new_chars == "")
		{
			throw std::logic_error("Big_integer can't be empty");
			/*std::size_t n = new_chars.length() + 1;
			result_char = new char[n];
			std::memcpy(result_char, new_chars, n);*/
		}
	}

	Big_integer(const Big_integer& other) : result_char{other.result_char}
	{}
	Big_integer& operator=(const Big_integer& other)
	{
		auto new_big_int = new Big_integer(other);
		return /**this=new_big*/*new_big_int;
	}

	Big_integer(Big_integer&& other) noexcept
	{
		//auto exchange = std::exchange(other.result_char, nullptr);				//ошибка при чтении 0x000000,
		//																			вот это не понятно почему программа думает что  other.result_char  0x000?
		this->result_char = std::move(other.result_char);
	}
	Big_integer& operator=(Big_integer&& other) noexcept
	{
		std::swap(result_char, other.result_char);
		return *this;
	}

	Big_integer& operator+(Big_integer& right)
	{
		long left_value = std::stol(this->result_char);
		*this = std::move(right);								//???1)есть смысл? 2)почему right не стал nullptr 3)почему значение в нём изменилось???
		long right_value = std::stol(this->result_char);
		long result = left_value + right_value;
		std::string str = std::to_string(result);
		this->result_char = std::move(str);							//???есть смысл?

		auto big_int_new = new Big_integer(std::move(*this));		
		return *this;
	}
	friend std::ostream& operator<<(std::ostream& os, Big_integer& big_integer);
private:
	//std::vector<char> result;
	std::string result_char;
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