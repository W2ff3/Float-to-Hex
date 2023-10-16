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

std::vector<char> Float_To_Hex(float& FP)
{
	std::vector<char> Hex_Char;
	unsigned int FPint = (int)FP;
	unsigned int conv[6];
	float FPdecimal = (FP - FPint);
	float flconv[6], fldecimal[6];

	do
	{
		conv[0] = FPint % 16;
		Conversion(conv[0], Hex_Char);
		FPint /= 16;
	} while (FPint > 0);

	reverse(Hex_Char.begin(), Hex_Char.end());
	Hex_Char.push_back('.');

	if (FPdecimal > 0)
	{
		conv[1] = FPdecimal * 16;
		Conversion(conv[1], Hex_Char);

		for (int i = 2; i < 6; i++)
		{
			flconv[i] = FPdecimal * 16;
			fldecimal[i] = flconv[i] - conv[i-1];
			conv[i] = fldecimal[i] * 16;
			Conversion(conv[i], Hex_Char);
		}
	}
	if (FPdecimal == 0)
		Hex_Char.push_back('0');

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
	float FP;
	do
	{
		std::cout << "---------------------------------------------" << std::endl;
		std::cout << "Input a floating-point number: ";
		std::cin >> FP;
		std::vector<char> Hexadecimal_Number = Float_To_Hex(FP);
		Display_1D_Vector(Hexadecimal_Number);
		std::cout << std::endl << std::endl << "Do you want to continue (Y/y)? ";
		std::cin >> response;
		std::cout << std::endl;
	} while ((response == 'Y') || (response == 'y'));

	return 0;
}