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
void Conversion(std::vector<unsigned int> dec, std::vector<char>& Hex_Char)
{
	for (unsigned int i = 0; i < dec.size(); i++)
	{
		if (dec[i] == 0)
			Hex_Char.push_back('0');
		else if (dec[i] == 1)
			Hex_Char.push_back('1');
		else if (dec[i] == 2)
			Hex_Char.push_back('2');
		else if (dec[i] == 3)
			Hex_Char.push_back('3');
		else if (dec[i] == 4)
			Hex_Char.push_back('4');
		else if (dec[i] == 5)
			Hex_Char.push_back('5');
		else if (dec[i] == 6)
			Hex_Char.push_back('6');
		else if (dec[i] == 7)
			Hex_Char.push_back('7');
		else if (dec[i] == 8)
			Hex_Char.push_back('8');
		else if (dec[i] == 9)
			Hex_Char.push_back('9');
		else if (dec[i] == 10)
			Hex_Char.push_back('A');
		else if (dec[i] == 11)
			Hex_Char.push_back('B');
		else if (dec[i] == 12)
			Hex_Char.push_back('C');
		else if (dec[i] == 13)
			Hex_Char.push_back('D');
		else if (dec[i] == 14)
			Hex_Char.push_back('E');
		else if (dec[i] == 15)
			Hex_Char.push_back('F');
	}
}

std::vector<char> Float_To_Hex(const double FP)
{
	std::vector<char> Hex_Char;
	std::vector<unsigned int> remainder_integer, remainder_decimal;

	int FPinteger;
	double FPtemp;
	double FPdecimal;

	// Integer Part
	FPinteger = trunc(FP); // Store integer number of input and temporary dividends for loop iterations.
	FPdecimal = FP - FPinteger; // Store decimal fractional number of input and fractional numbers used for loop iterations.

	if (FPinteger > 15)
	{
		do
		{
			FPtemp = FPinteger / static_cast<double>(16); // Stores value that is split into FPdecimal and FPinteger.
			FPdecimal = FPtemp - trunc(FPtemp); // Stores fractional number that will be used to get remainder, and directly correlates with do-while loop condition.
			
			if (FPdecimal != 0)
				remainder_integer.push_back(FPdecimal * 16); // Push back the remainder of the previous division.
			else
				break;
			
			FPinteger = trunc(FPtemp); // Stores dividend of next iteration.
		} while (FPdecimal != 0);
	}
	else
		remainder_integer.push_back(FPinteger);

	// Decimal Part
	FPinteger = trunc(FP); // Store integer digit that is pushed back into remainder_decimal integer vector.
	FPdecimal = FP - FPinteger; // Store temporary fractional multiplicand for loop iterations.

	if (FPdecimal != 0)
	{
		do
		{
			FPtemp = FPdecimal * 16; // Stores value that is split into FPinteger and FPdecimal.
			FPinteger = trunc(FPtemp); // The integer part of FPtemp is the remainder.

			// Break the do-while loop if the temporary fractional number is equal to zero (FPtemp == 0).
			// This prevents a zero from being pushed back into the remainder_decimal vector.
			if (FPtemp != 0)
				remainder_decimal.push_back(FPinteger); // Push back the integer part of FPtemp into vector.
			else
				break;

			FPdecimal = FPtemp - FPinteger; // Update decimal value for next iteration.
		} while (FPtemp != 0);
	}

	// Conversion to Hex

	// Convert integer section of input into hexadecimal.
	reverse(remainder_integer.begin(), remainder_integer.end());
	Conversion(remainder_integer, Hex_Char);

	if (!remainder_decimal.empty())
		Hex_Char.push_back('.');

	// Convert fractional section of input into hexadecimal.
	Conversion(remainder_decimal, Hex_Char);

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