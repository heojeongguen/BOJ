#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
unsigned long long arr[1000000];

unsigned long long N;
//unsigned long long findMinIndex(unsigned long long, unsigned long long);
//unsigned long long findResult(unsigned long long, unsigned long long);
//unsigned long long fuc(unsigned long long, unsigned long long);
int main() {
	unsigned long long data, minIndex;
	unsigned long long result = 0;
	cin >> N;
	for (unsigned long long i = 0; i < N; i++) {
		cin >> data;
		arr[i] = data;
	}

	int M = 0;

	for (int i = 0; i < N; i++) {
		for (int j = i; j < N; j++) {
			if(arr[i] < arr[j]){

			}
		}
		for (int j = i; j < N; j++) {

		}
	}
}

//unsigned long long fuc(unsigned long long leftIndex, unsigned long long rightIndex) {
//	unsigned long long minIndex = findMinIndex(leftIndex, rightIndex);
//	unsigned long long left = findResult(leftIndex, minIndex-1);
//	unsigned long long right = findResult(minIndex + 1, rightIndex);
//	unsigned long long middle = findResult(leftIndex, rightIndex);
//
//	if (left > right) {
//		if (left >= middle) {
//			fuc(leftIndex, minIndex - 1);
//		}
//		else
//		{
//			return middle;
//		}
//	}
//	else if(left < right){
//		if (right >= middle) {
//			fuc(minIndex + 1, rightIndex);
//		}
//		else {
//			return middle;
//		}
//	}
//	else {
//		if (middle > left) {
//			return middle;
//		}
//		else {
//			return max(fuc(leftIndex, minIndex - 1), fuc(minIndex + 1, rightIndex));
//		}
//	}
//}
//
//unsigned long long findResult(unsigned long long i, unsigned long long j) {
//	unsigned long long minIndex = findMinIndex(i, j);
//	if (i == j) {
//		return arr[i] * arr[j];
//	}
//	unsigned long long result = 0;
//	for (; i <= j; i++) {
//		result += arr[i];
//	}
//	result = result * arr[minIndex];
//	return result;
//}
//
//unsigned long long findMinIndex(unsigned long long i, unsigned long long j) {
//	unsigned long long result = i;
//	for (; i <= j; i++) {
//		if (arr[result] > arr[i]) {
//			result = i;
//			break;
//		}
//	}
//	return result;
//}