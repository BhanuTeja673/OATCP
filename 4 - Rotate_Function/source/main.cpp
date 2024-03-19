#include <bits/stdc++.h>
using namespace std;

int maxRotateK(vector<int> &array, int size) {
    int sum = 0, totalSum = 0;
    for (int i = 0; i < size; ++i) {
        sum += array[i];
        totalSum += i * array[i];
    }
    
    int maxRotation = totalSum;

    for (int i = 1; i < size; ++i) {
        totalSum = totalSum + sum - size * array[size - i];
        maxRotation = max(maxRotation, totalSum);
    }

    return maxRotation;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ifstream inputFile("input.txt");
    ofstream outputFile("../output/output.txt");
    
    int n;
    inputFile >> n;
    vector<int> numbers(n);
    for (int i = 0; i < n; i++) 
        inputFile >> numbers[i];
    int result = maxRotateK(numbers, n);
    outputFile << result;

    return 0;
}
