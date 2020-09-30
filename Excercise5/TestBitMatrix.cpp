#include "Bitmatrix.hpp"
int main()
{
	//Test the deafualt constructor
	Bitmatrix<3,10> matrix;
	cout << matrix.toString() << endl;
	//Test the overloaded constructor
	Bitmatrix<5, 20>matrix_2(232381);
	cout << matrix_2 << endl;
	try {
		matrix.set();
		cout << matrix<< endl;
		matrix.Reset();
		cout << matrix << endl;
		matrix.Flip();
		cout << matrix << endl;

		//Test if Any/all or none  of the bits of the bits set.Also test for th other
		matrix_2.Reset(2);
		cout << std::boolalpha << "Any of the bits set: " << matrix_2.Any() << endl;
		cout << std::boolalpha << "Any of the bits set in the first row: " << matrix_2.Any(0) << endl;
		cout << std::boolalpha << "All of the bits set: " << matrix_2.All() << endl;
		cout << std::boolalpha << "All of the bits set at row 2: " << matrix_2.All(2) << endl;
		cout << std::boolalpha << "Are none of the bit set at row 2:" << matrix.None(2) << endl;
		//Get the element at specific posistion
		cout << std::noboolalpha << "Posistion bit at (1,0): " << matrix_2.get(1, 0) << endl;
		//Count all the ones 
		cout << "Counting bits of matrix_1:" << matrix.count() << endl;
		Bitmatrix<5, 20>matrix_3(362435);
		//Do the binary operations of the matricies
		Bitmatrix<5, 20>matrix_4 = matrix_2 |= matrix_3;
		cout << matrix_4 << endl;
		Bitmatrix<5, 20>matrix_5 = matrix_2 ^= matrix_3;
		cout << matrix_5 << endl;
		Bitmatrix<5, 20>matrix_6 = matrix_2 ^= matrix_3;
		cout << matrix_6<< endl;

		//Now throw an exception
		matrix_6.get(15, 21);
	}
	catch (const std::out_of_range& err)
	{
		cout << err.what() << endl;
	}
	catch (const std::domain_error& err)
	{
		cout << err.what() << endl;
	}
	catch (...)
	{
		cout << "Some error has occured" << endl;
	}

	

}