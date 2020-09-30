#include <array>
#include <bitset>
#include <iostream>
#include <sstream>
#include <stdexcept>
#include "stdlib.h"
#ifndef BITMATRIX_HPP
#define BITMATRIX_HPP
using namespace std;
template<const std::size_t N,const std::size_t M>
class Bitmatrix
{
private:
	std::array<std::bitset<M>, N> data;
	
public:
	constexpr Bitmatrix() noexcept = default;	//Default constructor(No need to implement since std::array<bitset<M>N>data already initialized at run time
	explicit constexpr Bitmatrix(unsigned long long integer) noexcept; //Overloaded constructor
	Bitmatrix(const Bitmatrix<N, M>& data); //Copy constuctor
	Bitmatrix(Bitmatrix<N, M>&& data) noexcept; //Move constructor
	virtual ~Bitmatrix();						//Destructor
	void set() noexcept;						//Set each row to true
	void set(std::size_t  pos);					//Set at specific row to be  alle true
	void Reset() noexcept;						//Reset each row
	void Reset(std::size_t  pos);				//set at specific row
	void Flip() noexcept;						//Flip each row
	void Flip(std::size_t  pos);				//Flip at certain posistion
	bool None() const noexcept;					//Check if each row has none of their bits set
	bool None(std::size_t  pos) const;			//Check if specific row has none of their bits set
	bool Any() const noexcept;					//Check if any row has their bits set
	bool Any(std::size_t  pos) const;			//Check if at a specific posistion if any of their bits set
	bool All() const noexcept;					//Check  if each row has their bits set
	bool All(std::size_t  pos) const ;			//Check  if specified row has their bits set
	bool get(std::size_t  pos_1,std::size_t  pos_2);   //Returns (pos_1,pos_2) value
	std::size_t count() const noexcept;					//Count all the set bits
	std::size_t count(std::size_t  pos) const;			//Count at specific row
	Bitmatrix<N, M>& operator=(const Bitmatrix<N, M>& data); //assignment operations
	Bitmatrix<N, M>& operator=(const Bitmatrix<N, M>&& data); //move operations operations
	Bitmatrix<N, M>& operator|=(const Bitmatrix<N,M>& matrix_2); //Or operator
	Bitmatrix<N, M>& operator^=(const Bitmatrix<N,M>& matrix_2); //Xor operations
	Bitmatrix<N, M>& operator&=(const Bitmatrix<N,M>& matrix_2); //AND OPERATIONS
    std::string toString() const ;	//Tostring operations
	friend ostream& operator<<(ostream& os, Bitmatrix<N, M>matrix) //Inline function for << operator to print out the function
	{
		os << matrix.toString();
		return os;
	}
	
};
#ifndef BITMATRIX_CPP
#include "Bitmatrix.cpp"
#endif
#endif 