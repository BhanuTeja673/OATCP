#include <bits/stdc++.h>
using namespace std;

int maximumProduct(vector<int> &nums, int size) {
    int prevMax = nums[0], prevMin = nums[0], maxProduct = nums[0];
    for (int i = 1; i < size; i++) {
        int currentMax = max({nums[i], prevMax * nums[i], prevMin * nums[i]});
        prevMin = min({nums[i], prevMax * nums[i], prevMin * nums[i]});
        prevMax = currentMax;
        maxProduct = max(maxProduct, prevMax);
    }
    return maxProduct;
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
    int result = maximumProduct(numbers, n);
    outputFile << result;

    return 0;
}
