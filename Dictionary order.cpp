#include <iostream>
using namespace std;

int C(int upper, int lower)
{
	int result = 0;
	if (upper <= 0 || lower <= 0)
		exit(0);
	if (upper > lower)
		exit(0);
	int i = lower;
	int molecular = 1;
	int denominator = 1;
	while (i > lower - upper)
	{
		molecular *= i;
		i--;
	}
	i = upper;
	while (i >= 1)
	{
		denominator *= i;
		i--;
	}
	result = molecular / denominator;
	return result;
}

int main()
{
	char text[7] = {"abcd"};
	int text_to_num[7] = {};
	int length = strlen(text);
	int* sum = new int[length];
	int index = 0;
	int upper = 0;
	int lower = 0;
	int encode = 0;
	for (index = 0; index < length; index++)
	{
		sum[index] = 0;
	}
	for (index = 0; index < length; index++)
	{
		text_to_num[index] = text[index] - 96;
	}
	for (index = 0; index < length; index++)
	{
		upper = length - index - 1;
		lower = 25;
		if (index == length - 1)
		{
			sum[index] = text_to_num[index];
			break;
		}
		while (lower >= (26 - text_to_num[index]))
		{
			sum[index] += C(upper, lower);
			lower--;
		}
	}
	for (index = 0; index < length; index++)
	{
		encode += sum[index];
	}
	cout << encode;
	return 0;
}