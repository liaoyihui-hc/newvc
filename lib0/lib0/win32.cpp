#include "stdafx.h"

#include "win32.h"
int Factorial(int n)
{
	int fact = 1;
	int i = 0;
	for (i = 1; i <= n; i++)
	{
		fact = fact*i;

	}
	return fact;

}
float hudu(int n)
{
float hudu;
	hudu = n / 53.7;

	return hudu;

}

