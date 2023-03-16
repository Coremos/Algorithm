#include <iostream>

int main()
{
	int A;
	int B;
	int C;
	int flag;
	int result;

	std::cin >> A;
	std::cin >> B;
	std::cin >> C;

	flag = (A == B) + ((B == C) << 1) + ((C == A) << 2);
	if (flag == 0)
	{
		result = (A < B ? (B < C ? C : B) : (A < C ? C : A)) * 100;
	}
	else if (flag == 7)
	{
		result = 10000 + A * 1000;
	}
	else
	{
		result = 1000 + (flag > 3 ? C : B) * 100;
	}
	
	std::cout << result;
}