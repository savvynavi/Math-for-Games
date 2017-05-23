#include<iostream>
#include<vector>
using namespace std;
#define BITLEN 32

bool IsLeftMostBitSet(unsigned int value);
bool IsRightMostBitSet(unsigned int value);
bool IsBitSet(unsigned int value, unsigned char bitToCheck);
int GetRightMostBitSet(unsigned int value);
void PrintBinary(unsigned char value);

int main(){
	PrintBinary(6);
	PrintBinary(10);
	cout << GetRightMostBitSet(6) << " expected 1" << endl;
	cout << IsLeftMostBitSet(6) << " expected 0" << endl;
	cout << IsLeftMostBitSet((1 << (BITLEN - 1))) << " expected 1" << endl;
	cout << IsRightMostBitSet((1 << (BITLEN - 1))) << " expected 0" << endl;
	cout << IsRightMostBitSet(2) << " expected 0" << endl;
	cout << IsRightMostBitSet(10) << " expected 0" << endl;
	cout << IsRightMostBitSet(1) << " expected 1" << endl;
	cout << IsBitSet(10, 3) << " Expected 1" << endl;
	cout << IsBitSet(10, 2) << " Expected 0" << endl;
	cout << IsBitSet(1, 0) << " Expected 1" << endl;
	system("pause");
	return 0;
}

//returns true if left most bit is set, false otherwise
bool IsLeftMostBitSet(unsigned int value){
	value >>= BITLEN - 1;
	if((value & 1) == 1){
		return true;
	}
	return false;
}

//returns true if right most bit is set, false otherwise
bool IsRightMostBitSet(unsigned int value){
	if((value & 1) == 1){
		return true;
	}
	return false;
}

//returns true if the bit at the position given is set, false otherwise
bool IsBitSet(unsigned int value, unsigned char bitToCheck){
	value >>= bitToCheck;
	if((value & 1) == 1){
		return true;
	}
	return false;
}

//returns the position of the rightmost set bit, eg 10011100 would return 2, 00000000 returns -1
int GetRightMostBitSet(unsigned int value){
	for(int i = 0; i < BITLEN; i++){
		if((value & 1) == 1){
			return i;
		}
		value >>= 1;
	}
	return -1;
}

//prints value as a binary number
void PrintBinary(unsigned char value){
	if(value == 1){
		cout << "1" << endl;
		return;
	}else if(value == 0){
		cout << "0" << endl;
		return;
	}
	vector<int> binNum;
	while(value >= 1){
		if(value %2 == 0){
			binNum.push_back(0);
		}else{
			binNum.push_back(1);
		}
		value /= 2;
	}
	
	for(vector<int>::reverse_iterator it = binNum.rbegin(); it != binNum.rend(); it++){
		cout << *it;
	}
	cout << endl;
}