//This program published under GNU GPL License

#include <stdio.h>
#include <math.h>

long double division(long double num1, long double num2)
{

	long double count = 0.0, count2 = 0.0, remain = 0.0;
	while (num1 > 0) {
		if (num1 < num2)
		break;
		num1 = num1 - num2;
		count++;
	}
	if (num1 != 0)
	remain = num1;
	long double remain2 = remain;
	while (remain2 > 0)
	{
		int c = 1000000;
		long double one = 0.0;
		while (c > 1)
		{
			remain = remain2;
			remain2 = 0.0;
			for (int i = 0; i < 10; i++)
			{
				remain2 = remain2 + remain;
			}
			for (int k = 0; k < c; k++)
			{
				one = one + 0.0000001;
			}
			while (remain2 > 0)
			{
				if (remain2 < num2)
				break;
				remain2 = remain2 - num2;
				count2 = count2 + one;
			}
			one = 0.0;
			c = division(c, 10);
		}
		if (remain2 != 0)
		break;
	}
	if (num1 == 0)
	return count;
	else
	return (count + count2);
}

long double mult(long double num1, long double num2)
{
	int integer1 = num1, integer2 = num2;
	long double fraction1 = 0.0, fraction2 = 0.0;
	fraction1 = num1 - integer1;
	fraction2 = num2 - integer2;
	int result1 = 0;
	for (int i = 0; i < integer1; i++)
	{
		result1 = result1 + num2;
	}
	long double result2 = 0;
	for (int j = 0; j < integer1; j++)
	{
		result2 = result2 + fraction2;
	}
	long double result3 = 0;
	for (int k = 0; k < integer2; k++)
	{
		result3 = result3 + fraction1;
	}
	long double result4 = 0.0;
	if (fraction2 > 0.0)
	result4 = division(fraction1, (division(1, fraction2)));
	else
	result4 = 0.0;
	long double result = result1 + result2 + result3 + result4;

	return result;
}

long double powerinteger(long double num1, long double num2)
{
	int integer = num2;
	long double result = 1.0;
	for (int j = 0; j < integer; j++)
	{
		result = mult(result, num1);
	}
	return result;
}

long double power(long double num1, long double num2)
{
	int integer1 = num1;
	long double fraction1 = num1 - integer1;
	if(fraction1 != 0)
		fraction1 = fraction1 + 0.01;
	int integer2 = num2;
	long double fraction2 = num2 - integer2;
	if(fraction2 != 0)
		fraction2 = fraction2 + 0.01; 
	fraction2 = mult(fraction2, 10);
	long double powerednum = 0.0, assistant = 0.0, result = 1.01;
	int assistant2 = 0;
	powerednum = powerinteger(num1, fraction2);
	assistant = powerednum;
		while (assistant > 1)
		{
			int i = 0;
			while ((assistant >= 1) && (i < 10))
			{
				assistant = division(assistant, result);
				if (assistant <= 1.000001)
				break;
				i++;
			}
			if (assistant > 1.00001)
			{
				result = result + 0.01;
				assistant = powerednum;
			}
			else
			break;
		}
	
		if((num1>1)&&((fraction1>0.001)||(fraction2>0.001)))
		{
		return mult(result, (powerinteger(num1, num2)));
		}
		else if((num1>1)&&((fraction1==0)&&(fraction2==0)))
		{
		return powerinteger(num1, num2);
		}
		else
		{
		assistant2 = mult(fraction1, 10);
		return division(power(assistant2, num2), power(10, num2));
		}

}

long double check(long double num)
{
	if ( num < 0 )
	{		
		while (num <= 0)
		{
		num = num + 2;
		}
		if (num < -1)
		return 0;
		else
		return 1;
	}
	else
	{
		while (num >= 0)
		{
		num = num - 2;
		}
		if (num < 1)
		return 0;
		else
		return 1;
	}
}

int main()
{
	printf("Enter 2 numbers to get power :\n");
	long double a = 0.0, b = 0.0;
	scanf("%Lf%Lf", &a, &b);
	if ((a > 0) && (b > 0))
	printf("Your result is : %Lf\n", power(a, b));
	else if ((a == 0) && (b > 0))
	printf("0\n");
	else if ((a == 0) && (b == 0))
	printf("Indeterminable!\n");
	else if (((a > 0) || (a < 0)) && (b == 0))
	printf("1\n");
	else if ((a > 0) && (b < 0))
	printf("Your result is : %Lf\n", division(1, power(a, fabs(b))));
	else if ((a < 0) && (b > 0))
	{
		if ((check(fabs(b)) == 0))
		printf("Your result is : -%Lf\n", power(fabs(a), b));
		else
		printf("Your result is : -%Lf\n", division(1, power(a, fabs(b))));
    }
	else if ((a < 0) && (b < 0))
	{
	if ((check(fabs(b)) == 0))
	printf("Your result is : %Lf\n", division(1, power(fabs(a), fabs(b))));
	else
	printf("Your result is : -%Lf\n", division(1, power(fabs(a), fabs(b))));
	}
	else
	printf("Undefined!\n");
	return 0;
}
