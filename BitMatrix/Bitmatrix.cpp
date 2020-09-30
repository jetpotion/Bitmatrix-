
#include "Bitmatrix.hpp"
#ifndef BITMATRIX_CPP
#define BITMATRIX_CPP

//Std::size_t will make sure all input are posistive integers


//create matrix with an overloaded constructor
 template<std::size_t N, std::size_t M>
 constexpr Bitmatrix<N, M>::Bitmatrix(unsigned long long integer) noexcept
 {
	 for (bitset<M>& v : data)
		 v = std::bitset<M>(integer);
 }
 //Create the copy constructor that takes in a integer
template<std::size_t  N, std::size_t  M>
 Bitmatrix<N, M>::Bitmatrix(const Bitmatrix<N, M>& data) : data(data.data)
{
}
 template<std::size_t N, std::size_t M>
 Bitmatrix<N, M>::Bitmatrix(Bitmatrix<N, M>&& data) noexcept
 {
	 data = std::move(data.data);
 }
 //Destructor
template<std::size_t  N, std::size_t  M>
 Bitmatrix<N, M>::~Bitmatrix()
{
	cout << "Bit matrix deconstructing" << endl;
}
 //Set operations
template<std::size_t  N, std::size_t  M>
 void Bitmatrix<N, M>::set() noexcept
{
	for (auto&bits: data)
		bits.set();
}
 //set at specific row
template<std::size_t  N, std::size_t  M>
 void Bitmatrix<N, M>::set(std::size_t  pos)
{
	 if (pos >= data.size())
		 throw std::out_of_range("Out of bounds");
	data[pos].set();
}
 //Reset all rows
template<std::size_t  N, std::size_t  M>
 void Bitmatrix<N, M>::Reset() noexcept
{
	for (auto& bits : data)
		bits.reset();
}
 //Reset at specific row
template<std::size_t  N, std::size_t  M>
 void Bitmatrix<N, M>::Reset(std::size_t  pos)
{
	 if (pos >= data.size())
		 throw std::out_of_range("Out of bounds");
	data[pos].reset();
}
 //Flip all rows
template<std::size_t  N, std::size_t  M>
 void Bitmatrix<N, M>::Flip() noexcept
{
	for (auto &bits : data)
		bits.flip();
}
 //Flip at specific ops
template<std::size_t  N, std::size_t  M>
 void Bitmatrix<N, M>::Flip(std::size_t  pos)
{
	 if (pos >= data.size())
		 throw std::out_of_range("Out of bounds");
	data[pos].flip();
}
 //Check if any of them are set
template<std::size_t  N, std::size_t  M>
 bool Bitmatrix<N, M>::None() const noexcept
{
	bool none = true;
	for (auto &bits : data)
		none &= bits.none();

	return none;
}
 //Check if at specific posistions the bit matrix does not have any of its bits set
template<std::size_t  N, std::size_t  M>
 bool Bitmatrix<N, M>::None(std::size_t  pos) const
{
	 if (pos >= data.size())
		 throw std::out_of_range("Out of bounds");
	return data[pos].none();
}
 //Check if any bits are set
template<std::size_t  N, std::size_t  M>
 bool Bitmatrix<N, M>::Any() const noexcept
{
	bool any = false;
	for (auto& bits : data)
		any ^= bits.any();


	return any;
}
 //Chekc if specific posistion is any of the bits are set
template<std::size_t  N, std::size_t  M>
 bool Bitmatrix<N, M>::Any(std::size_t  pos) const
{
	 if (pos >= data.size())
		 throw std::out_of_range("Out of bounds");
	return data[pos].any();
}
 //Check if all the bits are set
template<std::size_t  N, std::size_t  M>
 bool Bitmatrix<N, M>::All() const noexcept
{
	bool any = true;
	for (auto &bits : data)
		any &= bits.all();

	return any;
}
 template<std::size_t  N, std::size_t  M>
 bool Bitmatrix<N, M>::All(std::size_t  pos) const 
 {
	 if (pos >= data.size())
		 throw std::out_of_range("Out of bounds");

	 return data[pos].all();
 }
 //Returns the specific bit at specific posistions
template<std::size_t  N, std::size_t  M>
 bool Bitmatrix<N, M>::get(std::size_t  pos_1 ,std::size_t  pos_2)
{
	 if (pos_1 >= data.size() || pos_2 >= data[0].size())
		 throw std::out_of_range("Out of bounds on either columns or rows");
	return data[pos_1][pos_2];
}
 //Count all the bits
template<std::size_t  N, std::size_t  M>
 std::size_t  Bitmatrix<N, M>::count() const noexcept
{
	std::size_t count = 0;
	for (auto & bits: data)
		count += bits.count();

	return count;
}
 //Count specific bits
template<std::size_t  N, std::size_t  M>
 std::size_t Bitmatrix<N, M>::count(std::size_t  pos) const
{
	 if (pos >= data.size())
		 throw std::out_of_range("Out of bounds ");
	return data[pos].count();
}
 
 //Assing operations
template<std::size_t  N, std::size_t  M>
 Bitmatrix<N, M>& Bitmatrix<N, M>::operator=(const Bitmatrix<N, M>& data)
{
	if (this == &data)
		return *this;
	//Perform the assignment operations
	data = data.data;
	return *this;
}
 template<std::size_t N, std::size_t M>
 Bitmatrix<N, M>& Bitmatrix<N, M>::operator=(const Bitmatrix<N, M>&& data)
 {
	 data = std::move(data.data);
	 return *this;
 }
 //or operations 
template<std::size_t  N, std::size_t  M>
Bitmatrix<N, M>& Bitmatrix<N, M>::operator|=(const Bitmatrix<N, M>& matrix_2)
{
	if (data.size() != matrix_2.data.size())
		throw std::domain_error("Cannot perform a binary operations");
	// TODO: insert return statement here
	for (std::size_t  x = 0; x < matrix_2.data.size(); x++)
	{
		data[x] |= matrix_2.data[x];
	}
	return *this;
}


//Xor operations
template<std::size_t  N, std::size_t  M>
 Bitmatrix<N, M>& Bitmatrix<N, M>::operator^=(const Bitmatrix<N, M>& matrix_2)
{
	 if (data.size() != matrix_2.data.size())
		 throw std::domain_error("Cannot perform a binary operations");
	 // TODO: insert return statement here
	 for (std::size_t  x = 0; x < matrix_2.data.size(); x++)
	 {
		 data[x] ^= matrix_2.data[x];
	 }
	
	 return *this;
}
 //And operations
template<std::size_t  N, std::size_t  M>
 Bitmatrix<N, M>& Bitmatrix<N, M>::operator&=(const Bitmatrix<N, M>& matrix_2) 
{
	 if (data.size() != matrix_2.data.size())
		 throw std::domain_error("Cannot perform a binary operations");
	 //Do the and operations for comparison
	 for (std::size_t  x = 0; x < matrix_2.data.size(); x++)
	 {
		 data[x] &= matrix_2.data[x];
	 }
	return *this;
}
 

 //tostring operations. Create a tostring representation of the matrix
 template<std::size_t N, std::size_t M>
 std::string Bitmatrix<N, M>::toString() const
 {

	 stringstream tostring;
	 for (auto bits : data)
		 tostring << bits.to_string() << "\n";
	return tostring.str();
 }
 
#endif
 

