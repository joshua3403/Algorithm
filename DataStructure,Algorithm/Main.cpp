#include "stdafx.h"
#include "Calculator.h"

using namespace std;

int main()
{
	char InfixExpression[100];
	char PostfixExpression[100];
	double Result = 0.0;

	memset(InfixExpression, 0, sizeof(InfixExpression));
	memset(PostfixExpression, 0, sizeof(PostfixExpression));

	printf("Enter Infix Expression");
	scanf("%s", InfixExpression);

	GetPostfix(InfixExpression, PostfixExpression);

	printf("Infix : %s\nPostifx : %s\n", InfixExpression, PostfixExpression);

	Result = Calculate(PostfixExpression);
	printf("Calculation Result : %f\n", Result);
	return 0;
}
