#include <iostream>
#include <string>

int main()
{
	int A;
	int B;
	int C;

	std::cin >> A >> B >> C;

	std::cout << (A + B) % C << std::endl;
	std::cout << ((A % C) + (B % C)) % C << std::endl;
	std::cout << (A * B) % C << std::endl;
	std::cout << ((A % C) * (B % C)) % C << std::endl;
}