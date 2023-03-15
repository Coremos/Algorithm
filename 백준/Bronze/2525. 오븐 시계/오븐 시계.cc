#include <iostream>

int main()
{
	int A;
	int B;
	int C;
	int hour;

	std::cin >> A;
	std::cin >> B;
	std::cin >> C;

	B += C;
	hour = B / 60;
	B -= hour * 60;
	A += hour;
	A %= 24;
	
	std::cout << A << " " << B;
}