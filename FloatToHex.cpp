// Wilson Lopez
// Created on May 5, 2021
// Updated on October 18, 2023

// References:
// https://www.programiz.com/cpp-programming/examples/quotient-remainder
// https://www.bitdegree.org/learn/c-plus-plus-vector
// https://www.cplusplus.com/reference/vector/vector/
// https://www.cplusplus.com/doc/tutorial/ntcs/
// https://www.binaryhexconverter.com/decimal-to-hex-converter

#include <iostream>
#include <iomanip>
#include <vector>

// Converts decimal digit inside vector of unsigned integers into hexidecimal.
void Conversion(const std::vector<unsigned int>& dec, std::vector<char>& Hex_Char)
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

	/* Integer Part */

	FPinteger = trunc(FP); // Stores integer number of input and integer dividends for do-while loop iterations.
	FPdecimal = FP - FPinteger; // Stores decimal fractional number of input and fractional numbers used for do-while loop iterations.

	if (FPinteger > 15)
	{
		do
		{
			FPtemp = FPinteger / static_cast<double>(16); // Stores value that is split into FPdecimal and FPinteger.
			FPdecimal = FPtemp - trunc(FPtemp); // Stores fractional number that will be used to get remainder, and directly correlates with do-while loop condition.
			
			// Push back the remainder of the previous division while FPdecimal does not equal zero.
			if (FPdecimal != 0)
				remainder_integer.push_back(FPdecimal * 16);
			// Break the do-while loop, once FPdecimal equals zero.
			// This prevents an unnecessary zero from being pushed back into remainder_integer.
			else
				break; 

			FPinteger = trunc(FPtemp); // Update dividend for next iteration.
		} while (FPdecimal != 0);

	}
	// If FPinteger is less than 15, then no conversion is necessary.
	else
		remainder_integer.push_back(FPinteger);

	/* Decimal Part */

	FPinteger = trunc(FP); // Stores integer digit that is pushed back into remainder_decimal.
	FPdecimal = FP - FPinteger; // Stores fractional multiplicands for do-while loop iterations.

	if (FPdecimal != 0)
	{
		do
		{
			FPtemp = FPdecimal * 16; // Stores value that is split into FPinteger and FPdecimal, and halts loop iteration once it equals to zero.
			FPinteger = trunc(FPtemp); // The integer part of FPtemp is the remainder.
			
			// Push back the integer part of FPtemp into vector while FPtemp does not equal zero.
			if (FPtemp != 0)
				remainder_decimal.push_back(FPinteger);
			// Break the do-while loop if the temporary fractional number is equal to zero (FPtemp == 0).
			// This prevents an unecessary zero from being pushed back into the remainder_decimal vector.
			else
				break;

			FPdecimal = FPtemp - FPinteger; // Update decimal value for next iteration.
		} while (FPtemp != 0);
	}

	/* Conversion to Hex */

	// Convert integer section of input into hexadecimal.
	reverse(remainder_integer.begin(), remainder_integer.end());
	Conversion(remainder_integer, Hex_Char);

	// Convert fractional section of input into hexadecimal, if decimal was included in user input.
	if (!remainder_decimal.empty())
	{
		Hex_Char.push_back('.');

		// Convert fractional section of input into hexadecimal.
		Conversion(remainder_decimal, Hex_Char);
	}

	return Hex_Char;
}

void Display_1D_Vector(const std::vector<char>& Hex)
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