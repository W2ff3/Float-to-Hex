// Wilson Lopez
// May 5, 2021

// References:
// https://www.programiz.com/cpp-programming/examples/quotient-remainder
// https://www.bitdegree.org/learn/c-plus-plus-vector
// https://www.cplusplus.com/reference/vector/vector/
// https://www.cplusplus.com/doc/tutorial/ntcs/
// https://www.binaryhexconverter.com/decimal-to-hex-converter

#include <iostream>
#include <iomanip>
#include <vector>

// Converts decimal digit into hexidecimal.
void Conversion(unsigned int conv, std::vector<char>& Hex_Char)
{
	if (conv == 0)
		Hex_Char.push_back('0');
	else if (conv == 1)
		Hex_Char.push_back('1');
	else if (conv == 2)
		Hex_Char.push_back('2');
	else if (conv == 3)
		Hex_Char.push_back('3');
	else if (conv == 4)
		Hex_Char.push_back('4');
	else if (conv == 5)
		Hex_Char.push_back('5');
	else if (conv == 6)
		Hex_Char.push_back('6');
	else if (conv == 7)
		Hex_Char.push_back('7');
	else if (conv == 8)
		Hex_Char.push_back('8');
	else if (conv == 9)
		Hex_Char.push_back('9');
	else if (conv == 10)
		Hex_Char.push_back('A');
	else if (conv == 11)
		Hex_Char.push_back('B');
	else if (conv == 12)
		Hex_Char.push_back('C');
	else if (conv == 13)
		Hex_Char.push_back('D');
	else if (conv == 14)
		Hex_Char.push_back('E');
	else if (conv == 15)
		Hex_Char.push_back('F');
}

std::vector<char> Float_To_Hex(double& FP)
{
	std::vector<char> Hex_Char;
	std::vector<int> remainder_integer, remainder_decimal;

	double FPtemp;
	int FPinteger = trunc(FP); // Store integer part of input.
	double FPdecimal = FP - FPinteger; // Store decimal part of input.

	// Integer Part
	if (FPinteger > 15)
	{
		do
		{
			FPtemp = int(FPinteger) / 16;
			remainder_integer.push_back(FPtemp * 16);
			FPinteger = trunc(FPtemp);
		} while (FPtemp != 0);
	}
	else
		remainder_integer.push_back(FPinteger);

	// Decimal Part
	if (FPdecimal != 0)
	{
		do
		{
			FPtemp = FPdecimal * 16;
			FPinteger = trunc(FPtemp); // The integer part of FPtemp is the remainder.
			remainder_decimal.push_back(FPinteger);
			FPdecimal = FPtemp - FPinteger;
		} while (FPtemp != 0);
	}

	// Conversion to Hex
	reverse(remainder_integer.begin(), remainder_integer.end());
	for (unsigned int i = 0; i < remainder_integer.size(); i++)
		Conversion(remainder_integer[i], Hex_Char);
	Hex_Char.push_back('.');
	for (unsigned int i = 0; i < remainder_decimal.size(); i++)
		Conversion(remainder_decimal[i], Hex_Char);

	return Hex_Char;
}

void Display_1D_Vector(std::vector<char>& Hex)
{
	std::cout << "Hexadecimal Equivalent: ";
	for (unsigned int i = 0; i < Hex.size(); i++)
		std::cout << Hex[i];
}

int main()
{
	char response;
	double FP;

	do
	{
		std::cout << "---------------------------------------------" << std::endl;
		std::cout << "Input a floating-point number: ";
		std::cin >> FP;

		std::vector<char> Hexadecimal_Number = Float_To_Hex(FP); // Float-To-Hex() will return a value and initialize Hexadecimal_Number.
		Display_1D_Vector(Hexadecimal_Number);

		std::cout << std::endl << std::endl << "Do you want to continue (Y/y)? ";
		std::cin >> response;
		std::cout << std::endl;
	} while ((response == 'Y') || (response == 'y'));

	return 0;
}