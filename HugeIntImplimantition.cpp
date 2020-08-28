#include<iostream>
#include"HugeInt.h"
#include<conio.h>

using namespace std;

char* HugeInt::hugeIntToChar(HugeInt& p) { // convert HugeInt into char
	int storeNumber; // store number of each index of int array
	char* temp = new char[55]; //store HugeInt array numbers;
	temp[54] = '\0';
	char secondary[9]; //store saperate character before storing it in permanent array
	int k = 53; // control the index of temp array
	int countDigits = 0; // count digits that place on last index of Integer array 
	int lastIndex = 0; // store last index
	int Sto; // store last index number of integer array
	for (int i = 0; i < 54; i++) { // initiallize temp array by 0
		temp[i] = '0';
	}
	if (size > 0 && size <= 8) // decide last index 
		lastIndex = 0;
	else if (size > 8 && size <= 17)
		lastIndex = 1;
	else if (size > 17 && size <= 26)
		lastIndex = 2;
	else if (size > 26 && size <= 35)
		lastIndex = 3;
	else if (size > 35 && size <= 45)
		lastIndex = 4;
	else if (size > 45 && size <= 50)
		lastIndex = 5;
	Sto = p.ptr[lastIndex];
	while (Sto != 0) { // count digits of last index
		Sto = Sto / 10;
		countDigits++;
	}
	int cCDigits = 0; // count copy Digits;
	for (int i = 5; i >= 0; i--) { //contol index of integer array index
		storeNumber = p.ptr[i];
		for (int j = 0; j < 9; j++) { // control secondary array
			secondary[j] = (storeNumber % 10) + 48;
			storeNumber = storeNumber / 10;
		}
		int cCLoop = 9; // control copy loop
		for (int j = 0; j < cCLoop; j++) { //sopy from secondary to temp array
			k--;
			if (i == lastIndex && j == 0) { // if last index found
				cCLoop = countDigits;
				k = size - 1;
			}
			temp[k] = secondary[j];
		}
		if (i == lastIndex && cCDigits != 0) { //if last index not consist on zero
			cCDigits = cCDigits - 8;
			k = cCDigits;
		}
		cCDigits = k;
	}
	if (lastIndex == 0) { //if last index is zero
		char *temp1 = new char[55];
		int t1Index = 0; // control index of temp1 array
		temp1[54] = '\0';
		for (int i = 0; i < 54; i++) { // initiallize temp1 by zero
			temp1[i] = '0';
		}
		for (int i = countDigits - 1; i >= 0;i-- ) { // copy loop that copy data from secondary to temp1
			temp1[t1Index] = secondary[i];
			t1Index++; // control the index of temp1 array
		} 
		return temp1;
	}
	return temp;
}
void HugeInt::charToHugeInt(char p[]) { //convert char number in to HugeInt
	int receive; // receive character from char array
	int k = 0; // control char array index
	for (int i = 0; i < 6; i++) { // control array of integer of class
		receive  = 0;
		for (int j = 0; j < 9; j++) { // use to make pair of 9 decimal number
			if(k < size)
				receive = receive * 10 + (p[k] - 48);
			k++;
		}
		ptr[i] = receive;
	}
}
void HugeInt::intToHugeInt(int p) { // convert integer in to HugeInt
	if (p < 0) { // check enter number is '-'
		symbol = '-';
		p *= -1;
	}
	int temp = p; // stor number that present on left side
	int countDigits = 0; // count number of digits in each number
	while (temp != 0) {  // perform count operation
		temp = temp / 10;
		countDigits++;
	}
	char tempArr[10] = "000000000"; // store each digits saperately
	for (int i = 0; i < 9; i++) { // copyData from integer to array
		tempArr[i] = (p % 10) + 48;
		p = p / 10;
	}
	size = countDigits;
	char revTempArr[10] = "000000000"; // reverse the tempArr
	int revIndex = 0;
	for (int i = size - 1; i >= 0; i--) {
		revTempArr[revIndex] = tempArr[i];
		revIndex++;
	}
	ptr = new int[6];
	charToHugeInt(revTempArr); // conver char to huge int
}
HugeInt::HugeInt() { // default constructor
	ptr = NULL;
	size = 0;
	symbol = '+';
}
HugeInt::HugeInt(int p) { // parameterized constructor
	while (p <= 0 || p > 50) { // check size enter by user
		cout << "Enter correct size :";
		cin >> p;
	}
	symbol = '+';
	char* temp = new char[54]; // use to store char number
	ptr = new int[6]; // allocate memory for class data member
	int number = 0; //store number extract from array
	size = p; 
	int k = 0; // handle tempMemory
	int getChar; // get charatcter from user and store temporary
	temp[53] = '\0';
	for (int i = 0; i < 53; i++) { // initialize temp array by zero
		temp[i] = '0';
	}
	for (int i = 1; i < 6; i++) { // initialize integer array of class by zero
		ptr[i] = 0;
	}
	cout << "Enter number : ";
	for (int i = 0; i < p; ) { // take in put in temp array from user
		getChar = getche();
		if (getChar == '-' && i == 0 ) {
			symbol = '-';
		}
		else if (getChar >= '0' && getChar <= '9' &&(symbol == '-' || symbol == '+')){ 
			temp[i] = getChar;
			i++;
		}
		else if ((getChar <= '0'||getChar>='9') && i != 0) { // if user enter more than one aymbol in a number
				cout << "\nReenter number not expression : ";
				i = 0;
		}
	}
	charToHugeInt(temp);
}
HugeInt::HugeInt(HugeInt& p) { // copy constructor
 	if (p == NULL) { // if any object is empty
		p.ptr = new int[6];
	}
	this->symbol = p.symbol;
	this->size = p.size;
	this->ptr = new int[6];
	for (int i = 0; i < 6; i++) { //copy data
		this->ptr[i] = p.ptr[i];
	}
}

void HugeInt:: operator =(const HugeInt &p) { 
	if (ptr != NULL && p.ptr == NULL) { // if first object not NUll but second NULL
		size = 0;
		symbol = '+';
		ptr = NULL;
	}
	else if (ptr == NULL && p.ptr != NULL) { // if first NULL but second not NULL
		size = p.size;
		symbol = p.symbol;
		ptr = new int[6];
		for (int i = 0; i< 6; i++) { // copy data in first object by 2nd
			ptr[i] = p.ptr[i];
		}
	}
	else if (ptr != NULL && p.ptr != NULL) { // if both objects are empt
		size = p.size;
		symbol = p.symbol;
		for (int i = 0; i < 6; i++) {
			ptr[i] = p.ptr[i];
		}
	}
	else if (ptr == NULL && p.ptr == NULL) {
		size = 0;
		symbol = '+';
	}
}

bool HugeInt::operator ==(HugeInt& p) {
	if (this->ptr == NULL || p.ptr == NULL) {// if any object is empty
		cout << "Empty";
		return 0;
	}
	bool isEquall = false; // tells both objects are equal or not
	char *leftNumber = hugeIntToChar(*this); // store numbers of lef sided object
	char *rightNumber = p.hugeIntToChar(p); // store numers of right sided object
	if (this->size == p.size && this->symbol==p.symbol) { //check size and symbol are equal
		for (int i = 0; i < 54; i++) {
			if (leftNumber[i] == rightNumber[i]) {//check both sided numbers are equal
				isEquall = true;
			}
			else {
				isEquall = false;
				i = 54;
			}
		}
	}
	return isEquall;
}
bool HugeInt :: operator ==(int p) {
	if (ptr == NULL ) {// if any object is empty
		cout << "Empty";
		return 0;
	}
	HugeInt temp;
	temp.intToHugeInt(p); //convert integer in to hugeint
	return (*this == temp);
}

bool HugeInt :: operator !=(HugeInt & p) {
	if (this->ptr == NULL || p.ptr == NULL) {// if any object is empty
		cout << "Empty";
		return 0;
	}
	return !(*this == p);
}
bool HugeInt :: operator !=(int p){
	if (this->ptr == NULL) {// if any object is empty
		cout << "Empty";
		return 0;
	}
	return !(*this == p); 
}
bool HugeInt ::operator <(HugeInt& p) {
	if (this->ptr == NULL || p.ptr == NULL) {// if any object is empty
		cout << "Empty";
		return 0;
	}
	bool isSmall = false;
	if (symbol == '-' && p.symbol == '+') {
		return true;
	}
	else if (symbol == '+' && p.symbol == '-') {
		return true;
	}
	else if (size <= p.size) {// if both sizes are same
		if (*this != p) { // if both objects are not same
			for (int i = 0; i < 6; i++) { //check first number is less than second number
				if (this->ptr[i] <= p.ptr[i]) {
					isSmall = true;
				}
				else {
					isSmall = false;
					i = 6;
				}
			}
		}
	}
	return isSmall;
}
bool HugeInt ::operator <(int p) {
	if (this->ptr == NULL) {// if any object is empty
		cout << "Empty";
		return 0;
	}
	HugeInt temp;
	temp.intToHugeInt(p); //convert integer in to hugeInt 
	return (*this<temp);
}
bool HugeInt :: operator >(HugeInt& p) {
	if (this->ptr == NULL || p.ptr == NULL) {// if any object is empty
		cout << "Empty";
		return 0;
	}
	if (!(*this < p) && (*this != p)) { 
		return true;
	}
	else {
		return false;
	}
}
bool HugeInt ::operator >(int p) {
	if (this->ptr == NULL) {// if any object is empty
		cout << "Empty";
		return 0;
	}
	HugeInt temp;
	temp.intToHugeInt(p); // convert integer into Huge int
	return (*this > temp);
}
bool HugeInt :: operator <=(HugeInt& p) {
	if (this->ptr == NULL || p.ptr == NULL) {// if any object is empty
		cout << "Empty";
		return 0;
	}
	if ((*this < p) || (*this == p)) {
		return true;
	}
	else {
		return false;
	}
}
bool HugeInt :: operator <=(int p) {
	if (this->ptr == NULL) { // if any object is empty
		cout << "Empty";
		return 0;
	}
	HugeInt temp;
	temp.intToHugeInt(p); //convert integer in to hugeint
	return(*this <= temp);
}
bool HugeInt :: operator >=(HugeInt& p) {
	if (this->ptr == NULL || p.ptr == NULL) { // if any object is empty
		cout << "Empty";
		return 0;
	}
	if ((*this > p) || (*this == p)) {
		return true;
	}
	else {
		return false;
	}
}

bool HugeInt :: operator >=(int p) {
	if (this->ptr == NULL) { // if any object is empty
		cout << "Empty";
		return 0;
	}
	HugeInt temp;
	temp.intToHugeInt(p);//convert integer into hugeint
	return(*this >= temp);
}

istream& operator >>(istream& in, HugeInt& p) {
	
	char getChar; // store number temporary enter by user 
	if (p.ptr == NULL) { // if any object is empty
		p.ptr = new int[6];
		for (int i = 0; i < 6; i++) { //initialize integer of class data member
			p.ptr[i] = 0;
		}
	}
	for (int i =0; i < 6; i++) { //initialize integer of class data member
		p.ptr[i] = 0;
	}
	char temp[54]; // temp to store numbers of hugeint;
	temp[53] = '\0';
	for (int i = 0; i < 53; i++) { // initialize temp by zero
		temp[i] = '0';
	}
	cout << "Enter Number of digits : ";
	cin >> p.size;
	if (p.size <= 0 || p.size > 50) {
		cin >> p;
	}

	cout << "Enter number : ";
	for (int i = 0; i < p.size; ) { //get input from user
		getChar = getche();
		if (getChar == '-' && i == 0) {
			p.symbol = '-';
		}
		else if (getChar >= '0' && getChar <= '9' && (p.symbol == '-' || p.symbol == '+')) {
			temp[i] = getChar;
			i++;
		}
		else if ((getChar <= '0' || getChar >= '9') && i != 0) {
			cout << "\nReenter number not expression : ";
			i = 0;

		}
	}

	p.charToHugeInt(temp); //convert char in to hugeInt
	return in;
}

ostream& operator <<(ostream& out, HugeInt& p) {
	if (p.ptr == NULL) { // if any object is empty
		cout << "Empty";
		return out;
	}
	char* temp = p.hugeIntToChar(p); // convert hugeInt into char
	if (p.symbol == '-') { // if number is negative
		for (int i = 0; i < 54; i++) {
			if (temp[i] != '0') {
				out << p.symbol;
				i = 54;
			}
		}
	}
	for (int i = 0; i < 53; i++) { // control output
		if (i < p.size) { // if index of array is less than a number enter by user
			out << temp[i];
		}
	}
	return out;
}
HugeInt HugeInt:: sum(HugeInt& p) {
	HugeInt temp; //use to stroe final results
	temp.ptr = new int[6]; // allocate memmory for data member 
	int sumSize; // stor size for temp array;
	int fNSize; // store size of greater number
	int sNSize; // store size of smaller number
	char* firstNum; // will store grater number
	char* secondNum; // will store smaller number
	if (symbol == '-') {
		temp.symbol = '-';
	}
	if (size < p.size) {
		sumSize = p.size;
		firstNum = hugeIntToChar(p); // conversion from huge to char
		secondNum = hugeIntToChar(*this); // conversion from huge to char
		fNSize = p.size;
		sNSize = size;
	}
	else {
		sumSize = size;
		firstNum = hugeIntToChar(*this); // conversion from huge to char
		secondNum = hugeIntToChar(p); // conversion from huge to char
		fNSize = size;
		sNSize = p.size;
	}
	temp.size = sumSize;
	char carry = '0'; // store carry
	char tempSumm = '0'; // store sum of two number before store it in sum array
	char sum[54]; // store sum of tore arraies
	sum[53] = '\0';
	for (int i = 0; i < 53; i++) { //initialize sum array by zero;
		sum[i] = '0';
	}
	int fnIndex = fNSize - 1; // handle firstNum array index
	int snIndex = sNSize - 1; // handle secondNum array index
	int sumIndex = sumSize - 1; // handle sum array index
	while (snIndex >= 0) {
		tempSumm = (firstNum[fnIndex] - 48) + (secondNum[snIndex] - 48) + (carry - 48) + 48;
		sum[sumIndex] = ((tempSumm - 48) % 10) + 48;
		carry = ((tempSumm - 48) / 10) + 48;
		sumIndex--;
		fnIndex--;
		snIndex--;
	}
	while (fnIndex >= 0) { // if first array index is greater than or equal to zero
		tempSumm = (firstNum[fnIndex] - 48) + (carry - 48) + 48;
		sum[sumIndex] = ((tempSumm - 48) % 10) + 48;
		carry = ((tempSumm - 48) / 10) + 48;
		fnIndex--;
		sumIndex--;
	}
	if (carry != '0' && size < 50) { // use for extention in the array of sum
		char copy[54]; // use for copy
		copy[53] = '\0';
		temp.size++;
		for (int i = 51; i >= 0; i--) { // copy data from sum to copy
			copy[i + 1] = sum[i];
		}
		copy[0] = '1';
		temp.charToHugeInt(copy); // converstion from char toHugeInt
		return temp;
	}
	temp.charToHugeInt(sum);
	return temp;
}

HugeInt HugeInt:: operator+(HugeInt& p) {
	HugeInt temp;
	if (ptr == NULL || p.ptr == NULL) { // if any object is empty
		cout << "Empty";
		return temp;
	}
	if (symbol != p.symbol) { // if symbol not equal
		return sub(p);
	}
	return sum(p);
}

HugeInt HugeInt:: sub(HugeInt& p) {
	HugeInt temp; // use to store final results
	temp.ptr = new int[6]; // allocate memory for data member of class
	char* firNum; // store larger number
	char* secNum; // store smaller number
	int fNSize; // store size of larger number
	int sNSize; // store size of smaller number
	int lSize; // store the size of larger object
	if (*this < p) {
		temp.symbol = symbol;
	}
	else {
		temp.symbol = p.symbol;
	}
	if (size < p.size) {
		lSize = p.size;
		fNSize = p.size;
		sNSize = size;
		firNum = hugeIntToChar(p); //converstion from huge int to char
		secNum = hugeIntToChar(*this); //converstion from huge int to char
	}
	else {
		lSize = size;
		fNSize = size;
		sNSize = p.size;
		firNum = hugeIntToChar(*this); //converstion from huge int to char
		secNum = hugeIntToChar(p); //converstion from huge int to char
	}
	temp.size =  lSize;
	char sub[54]; // use to store final result
	sub[53] = '\0';
	for (int i = 0; i < 53; i++) { // initialize sub array by zero
		sub[i] = '0';
	}
	int fNIndex = fNSize- 1; // controll firNum array index
	int sNIndex = sNSize - 1; // controll secNum array index
	int subIndex= lSize - 1; //controll sub array index 
	while (sNIndex >= 0) {
		if (firNum[fNIndex] < secNum[sNIndex]) { //if first number is less than 2nd number
			int x = fNIndex - 1;
			while (firNum[x] == '0') {
				x--;
			}
			for (int l = x; l < fNIndex; l++) { // get carry from left sided numbers
				firNum[l] = firNum[l] - 1;
				firNum[l + 1] = firNum[l + 1] + 10;
			}
		}
		sub[subIndex] = (firNum[fNIndex] - 48) - (secNum[sNIndex] - 48) + 48; // store in sub array
		subIndex--;
		fNIndex--;
		sNIndex--;
	}
	while (fNIndex >= 0) {//if larhger array index is greater than or equal to zero
		sub[subIndex] = firNum[fNIndex];
		subIndex--;
		fNIndex--;
	}
	temp.charToHugeInt(sub); //conversition from char to Huge int
	return temp;
}

HugeInt HugeInt:: operator-(HugeInt& p) {
	HugeInt temp;
	if (this->ptr == NULL || p.ptr == NULL) { // if any object is empty
		cout << "Empty";
		return temp;
	}
	if (symbol != p.symbol) {
		return sum(p);
	}
	else {
		return sub(p);
	}
}

HugeInt HugeInt::mul(HugeInt& p) {
	HugeInt temp; // use to store the final result
	temp.ptr = new int[6]; // allocate memory
	if (symbol =='-'&& p.symbol == '-') {
		temp.symbol = '-';
	}
	else if (symbol == '+' && p.symbol == '+') {
		temp.symbol = '+';
	}
	else {
		temp.symbol = '-';
	}
	int cFSize; // store size of coloum of final array
	int rFSize; // store size of row of final array
	int aZerro = 0; // decide appending zero on right side of 2d array
	char* firNum; // use to store larger number
	char* secNum; // use to store smaller number
	int fNSize; // store size of larger array
	int sNSize; // store size of smaller array
	if (size < p.size) {
		cFSize = p.size;
		rFSize = size;
		fNSize = p.size;
		sNSize = size;
		firNum = hugeIntToChar(p); //convertion from huge to char
		secNum = hugeIntToChar(*this);//convertion from huge to char
	}
	else {
		cFSize = size;
		rFSize = p.size;
		fNSize = size;
		sNSize = p.size;
		firNum = hugeIntToChar(*this);//convertion from huge to char
		secNum = hugeIntToChar(p);//convertion from huge to char
	}
	int mulArraySize = size + p.size;
	temp.size = mulArraySize;
	char** final = new char*[cFSize]; //form 2d memry for storing temporary result
	for (int i = 0; i < cFSize; i++) {
		final[i] = new char[53];
	}

	for (int i = 0; i < cFSize; i++) { // initialize 2d memory
		for (int j = 0; j < 53 + 1; j++) {
			final[i][j] = '0';
		}
	}
	char* mulArr = new char [54]; //use to store the result of 2d array
	mulArr[53] = '\0';
	for (int i = 0; i < 53; i++) { // initialize mulArr by zero
		mulArr[i] = '0';
	}
	int coloum = mulArraySize - 1;
	int row = 0;
	int carry = 0;
	int pOEIndex = 0; // store product of each index + carry of last operation

	for (int i = fNSize - 1; i > -1; i--) { // input in 2d array
		for (int j = sNSize-1; j > -1; j--) {
			pOEIndex = ((firNum[i] - 48) * (secNum[j] - 48) + (carry));
			carry = ((pOEIndex) / 10);
			pOEIndex = ((pOEIndex) % 10);
			final[row][coloum - aZerro] = pOEIndex + 48;
			coloum--;
			//prod -= (carry * base);
		}
		row++;
		coloum = mulArraySize - 1;
		aZerro++;
	}
	final[row - 1][coloum - aZerro] = carry + 48;
	carry = '0';
	for (int j = 52; j >= 0; j--) {// in put in mulArr
		int sum = 0;
		for (int i = 0; i< cFSize; i++) {
			sum = ((sum) + (final[i][j] - 48));
		}
		sum = (sum) + (carry);
		carry = ((sum) / 10);
		sum = ((sum) % 10);
		mulArr[j] = sum + 48; // store in mulArr
	}
	temp.charToHugeInt(mulArr); // convertion from char to huge int
	return temp;
}
HugeInt HugeInt:: operator *(HugeInt& p) {
	HugeInt temp; // use to store final result
	temp.ptr = new int[6];
	if (this == NULL || p == NULL) {// if any object is empty
		cout << "Empty";
		return temp;
	}
	if (size + p.size >= 50) {
		cout << "Length of answer is too long ";
		return temp;
	}
	return mul(p);
}
HugeInt HugeInt:: operator+(int& p) {
	HugeInt temp;//use to stor integer enter by user
	temp.ptr = new int[6];
	temp.intToHugeInt(p);
	return(*this + temp);
}
HugeInt HugeInt:: operator-(int& p) {
	HugeInt temp;
	temp.ptr = new int[6];
	temp.intToHugeInt(p);
	return(*this - temp);
}
HugeInt HugeInt:: operator*(int& p) {
	HugeInt temp;
	temp.ptr = new int[6];
	temp.intToHugeInt(p);
	return(*this * temp);
}
HugeInt :: ~HugeInt() {
	delete[]ptr;
	ptr = NULL;
}