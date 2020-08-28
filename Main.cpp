#include<iostream>
#include"HugeInt.h"
using namespace std;

int mainMenu() { // show main manue and guide user
	int operation;
	cout << "\n";
	for (int i = 0; i < 30; i++) { //draw a top line
		cout << char(178);
	}
	cout << "\n";
	cout << "0 : Exist";
	cout << "\n1 : Sum 2 HugeInt ";
	cout << "\n2 : Sum HugeInt and integer";
	cout << "\n3 : Subtract 2 HugeInt ";
	cout << "\n4 : Subtract HugeInt and integer ";
	cout << "\n5 : Multiply 2 HugeInt";
	cout << "\n6 : Multiply HugeInt and integer ";
	cout << "\n7 : divide 2 HugeInt";
	cout << "\n8 : divide HugeInt and integer ";
	cout << "\n9 : Perform rational operation ";
	cout << "\n10 : clearScreen";
	cout << "\n";
	cin >> operation;
	cout << "\n";
	for (int i = 0; i < 30; i++) { // draw bottom line
		cout << char(178);
	}
	while (operation < 0 || operation>10) { // true if user enter wrong operation
		cout << "\nWrong opetion";
		cout << "\nReenter : ";
		cin >> operation;
	}
	return operation;
}
int rational() { // show menu of rational operations
	int operation;
	cout << "\n";
	for (int i = 0; i < 30; i++) { // draw a top line
		cout << char(178);
	}
	cout << "\n";
	cout << "0 : Exist from rational function";
	cout << "\n1 : HugeInt < HugeInt ";
	cout << "\n2 : HugeInt < int ";
	cout << "\n3 : HugeInt > HugeInt  ";
	cout << "\n4 : HugeInt > int";
	cout << "\n5 : HugeInt <= HugeInt ";
	cout << "\n6 : HugeInt <= int ";
	cout << "\n7 : HugeInt >= HugeInt ";
	cout << "\n8 : HugeInt >= int";
	cout << "\n9 : HugeInt == HugeInt ";
	cout << "\n10 : HugeInt == int";
	cout << "\n11 : HugeInt != HugeInt ";
	cout << "\n12 : HugeInt != int";
	cout << "\n13 : clearScreen";
	cout << "\n";
	cin >> operation;
	cout << "\n";
	for (int i = 0; i < 30; i++) { // draw bottom line
		cout << char(178);
	}
	cout << "\n";
	while (operation < 0 || operation>13) { // true when conditions are true
		cout << "\nWrong input";
		cout << "\nPlease Reenter :";
		cin >> operation;
	}
	return operation;
}

int main() {
	HugeInt num1; // store hugeNumber 1;
	HugeInt num2; // store hugeNumber 2;
	HugeInt result; // store result of two hugeInteger or normal Integer
	int intNum; // store constant integer;
	int operation = -1; // select calculations 

	cin >> num1;
	cout << "\n";
	cin >> num2;
	cout << "\nEnter an integer number : ";
	cin >> intNum;
	while (operation != 0) {
		operation = mainMenu();
		if (operation == 1) { //sum 2 HugeInt Number
			result = num1 + num2;
			cout << "Sum : ";
			cout << result;
		}
		else if (operation == 2) { //sum HugeInt and normal int Number
			result = num1 + intNum;
			cout << "Sum : ";
			cout << result;
		}
		else if (operation == 3) { //Subtract 2 HugeInt Number
			result = num1 - num2;
			cout << "Subtract : ";
			cout << result;
		}
		else if (operation == 4) {//Subtract HugeInt and normal int Number
			result = num1 - intNum;
			cout << "Subtract : ";
			cout << result;
		}
		else if (operation == 5) {//Multiply 2 HugeInt Number
			result = num1 * num2;
			cout << "Multiply : ";
			cout << result;
		}
		else if (operation == 6) {//Multiply HugeInt and normal int Number
			result = num1 * intNum;
			cout << "Multiply : ";
			cout << result;
		}/*
		else if (operation == 7) {//Divide 2 HugeInt Number
			result = num1 / num2;
			cout << "Sum : ";
			cout << result;
		}
		else if (operation == 8) {//Divide HugeInt and normal int Number
			result = num1 / intNum;
			cout << "Sum : ";
			cout << result;
		}*/

		else if (operation == 9) { // perform rational operation
			int rationalOperation = -1; // select rational operations
			while (rationalOperation != 0) {
				rationalOperation = rational();
				if (rationalOperation == 1) { // num1 < num2
					if (num1 < num2) {
						cout << "\nnum1 is less than to num2";
					}
					else {
						cout << "\nnum1 is not less than to num2";
					}
				}
				else if (rationalOperation == 2) { // num1 < intNUm
					if (num1 < intNum) {
						cout << "num1 is less than to normal int";
					}
					else {
						cout << "num1 is not less than to normal int";
					}
				}
				else if (rationalOperation == 3) { // num1 > num2
					if (num1 > num2) {
						cout << "\nnum1 is greater than to num2";
					}
					else {
						cout << "\nnum1 is not greater than to num2";
					}
				}
				else if (rationalOperation == 4) { // num1 > intNum
					if (num1 > intNum) {
						cout << "num1 is greater than to normal int";
					}
					else {
						cout << "num1 is not greater than to normal int";
					}
				}
				else if (rationalOperation == 5) { // num1 <= num2
					if (num1 <= num2) {
						cout << "\nnum1 is less than or equal to num2";
					}
					else {
						cout << "\nnum1 is not less than or equal to num2";
					}
				}
				else if (rationalOperation == 6) { // num1 <= intNum
					if (num1 <= intNum) {
						cout << "num1 is less than or equal to normal int";
					}
					else {
						cout << "num1 is not less than or equal to normal int";
					}
				}
				else if (rationalOperation == 7) { // num1 >= num2
					if (num1 >= num2) {
						cout << "\nnum1 is greater than or equal to num2";
					}
					else {
						cout << "\nnum1 is greater than or equal to num2";
					}
				}
				else if (rationalOperation == 8) { // num1>= intNum
					if (num1 >= intNum) {
						cout << "num1 is greater than or equal to normal int";
					}
					else {
						cout << "num1 is not greater than or equal to normal int";
					}
				}
				else if (rationalOperation == 9) { // num1 == num2
					if (num1 == num2) {
						cout << "\nnum1 is equal to num2";
					}
					else {
						cout << "\nnum1 is equal to num2";
					}
				}
				else if (rationalOperation == 10) { // num1 == intNum
					if (num1 == intNum) {
						cout << "num1 is equal to normal int";
					}
					else {
						cout << "num1 is not equal to normal int";
					}
				}
				else if (rationalOperation == 11) { // num1 != num2
					if (num1 != num2) {
						cout << "\nnum1 is not Equal to num2";
					}
					else {
						cout << "\nnum1 is Equal than to num2";
					}
				}
				else if (rationalOperation == 12) { // num1 != intNum
					if (num1 != intNum) {
						cout << "num1 is not Equal to normal int";
					}
					else {
						cout << "num1 is Equal to normal int";
					}
				}
				else if (rationalOperation == 13) { // clear screen
					system("CLS");
				}
			}
		}
		else if (operation == 10) { // clear screen
			system("CLS");
		}
	}
	system("PAUSE");
	return 0;
}