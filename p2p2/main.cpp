#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

int sum(vector<int> vec, int i, int j) { //return sum of vector from indicies i to j
	int sum = 0;
	for (; i <= j; i++) { //iterate through array from i to j
		sum += vec[i]; //add current element to sum
	}
	return sum; //return sum
}

void largestSum(vector<int> vec, int &b, int &e) { //iterate through array and return indicies to the starting and ending point of the max sum subvector
	for (int i = 0; i < vec.size(); i++) {//iterate through array
		for (int j = i + 1; j < vec.size(); j++) {//iterate through sub array from n+1 to end
			if (sum(vec, i, j) > sum(vec, b, e)) {//if current values at indicies is greater than stored indicies then set current as new highest
				b = i;
				e = j;
			}
		}
	}
}

int main() {
	ifstream file("data.txt"); //file
	vector<int> vec; //vector of numbers
	int num, b = 0, e = 1, sum = 0;
	if (!file) { //error reading file
		cerr << "Error opening file" << endl;
	}
	while (file >> num) { //pushback numbers from txt file to vector
		vec.push_back(num);
	}
	largestSum(vec, b, e); //find largest subarray
	for (; b <= e; b++) { //print largest subarray
		cout << vec.at(b) << " ";
	}
}