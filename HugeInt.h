#ifndef HugeInt_H
#define HugeInt_H
#include<iostream>

using namespace std;

class HugeInt {
private:
	int* ptr; 
	int size; // store how many number entered by user
	char symbol; // store symbol of each and every object
	char* hugeIntToChar(HugeInt& p); // take an HugeInt array and convert it in char array
	void charToHugeInt(char  p[]); // take an char array and convert it in HugeInt array 
	void intToHugeInt(int p); //take an int array and convert it in HugeInt array
	HugeInt sum(HugeInt& p); // perform sum operation
	HugeInt sub(HugeInt& p); // perform subtraction operation
	HugeInt mul(HugeInt& p); // perform multiply operation
public:
	HugeInt(); //default constructor
	HugeInt(int p); //parameterized constructor
	HugeInt(HugeInt& p); // copy constructor
	
	HugeInt operator+(HugeInt& p);
	HugeInt operator-(HugeInt& p); 
	HugeInt operator*(HugeInt& p); 
	HugeInt operator/(HugeInt& p); 
	HugeInt operator+(int& p); 
	HugeInt operator-(int& p); 
	HugeInt operator*(int& p); 
	HugeInt operator/(int& p); 

	void operator =(const HugeInt& p);
	bool operator ==(HugeInt& p);
	bool operator ==(int p);
	bool operator !=(HugeInt& p);
	bool operator !=(int p);
	bool operator <(HugeInt& p);
	bool operator <(int p);
	bool operator >(HugeInt& p);
	bool operator >(int p);
	bool operator <=(HugeInt& p);
	bool operator <=(int p);
	bool operator >=(HugeInt& p);
	bool operator >=(int p);

	friend istream& operator >>(istream& in, HugeInt& p);
	friend ostream& operator <<(ostream& out, HugeInt& p);
	~HugeInt();
};


#endif
