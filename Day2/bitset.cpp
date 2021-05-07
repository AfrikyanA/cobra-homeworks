#include <iostream>
#include <stdio.h>
#include <assert.h>
#include <climits>

using namespace std;

template<size_t n>
class BitSet {
   private:
       static const size_t IntBits = CHAR_BIT * sizeof(int);
       int ctr[n];

  public:
    BitSet();
    void set (size_t);
    void reset (size_t);
    void flip (size_t);
    int test (size_t);
	size_t getSize();
  public:
	BitSet<n>& operator& (const BitSet<n>& rhs);
	BitSet<n>& operator| (const BitSet<n>& rhs);
  	void operator&= (const BitSet<n>& rhs);
  	void operator|= (const BitSet<n>& rhs);

};



template <size_t n>
BitSet<n>::BitSet()
: ctr() 
{}


template <size_t n>
size_t BitSet<n>::getSize()
{
	return sizeof(ctr)/sizeof(int);
}


template <size_t n>
void BitSet<n>::set (size_t k)
{
  ctr[k/IntBits] |= (1U << (k%IntBits));
}


template <size_t n>
void BitSet<n>::reset (size_t k)
{
  ctr[k/IntBits] &= ~(1U << (k%IntBits));
}


template <size_t n>
int BitSet<n>::test (size_t k)
{
  return ( (ctr[k/IntBits] & (1U<<(k%IntBits))) != 0 );
}


template <size_t n>
void BitSet<n>::flip (size_t k)
{
  ctr[k/IntBits] ^= (1U <<(k%IntBits));
}


template <size_t n>
BitSet<n>& BitSet<n>::operator& (const BitSet<n>& rhs)
{
	for(int i = 0; i <= this->getSize(); ++i)
		this->ctr[i] &= rhs.ctr[i];
	return *this;
}


template <size_t n>
BitSet<n>& BitSet<n>::operator| (const BitSet<n>& rhs)
{
	for(int i = 0; i <= this->getSize(); ++i)
		this->ctr[i] |= rhs.ctr[i];
	return *this;
}


template <size_t n>
void BitSet<n>::operator&= (const BitSet<n>& rhs)
{
	for(int i = 0; i <= this->getSize(); ++i)
		this->ctr[i] &= rhs.ctr[i];
}


template <size_t n>
void BitSet<n>::operator|= (const BitSet<n>& rhs)
{
	for(int i = 0; i <= this->getSize(); ++i)
		this->ctr[i] |= rhs.ctr[i];
}