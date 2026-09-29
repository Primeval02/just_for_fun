/*
 * Bradley Tate
 *
 * This is my solution to LeetCode 1-TwoSum after learning about hashmaps and the optimal O(n) solution. 
 * Credit: https://www.geeksforgeeks.org/cpp/unordered_map-in-cpp-stl/
 * Credit: https://www.w3schools.com/cpp/cpp_vectors.asp
 * Credit: https://www.geeksforgeeks.org/cpp/measure-execution-time-function-cpp/
 */

#include <iostream>
#include <unordered_map>
#include <vector>
#include <chrono>

//using namespace std;
using namespace std::chrono;

std::vector<int> twoSum(std::vector<int>& nums, int target) {
    std::unordered_map<int, int> known;
    for (int i = 0; i < (int)nums.size(); i++) {
        int complement = target - nums[i];

        if (known.find(complement) != known.end()) {
            return {known[complement], i};
        }

        known.insert({nums[i], i});
    }
    return {0};
}

int main() {

    std::vector<int> nums = {};
    int target = 0;
    int input = 0;

    // Test lest and target input
    do {
        std::cout << "Enter a number > 0 to be added to the list. Press 0 to enter the target: " << std::endl;
        std::cin >> input;
        if (input > 0)
            nums.push_back(input);
    } while(input != 0);

    std::cout << "Enter a target sum: ";
    std::cin >> target;

    // Call twoSum and time it, solution returned as vector
    auto start = high_resolution_clock::now();
    std::vector<int> solution = twoSum(nums, target);
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);

    // Print nums and correct indices
    std::cout << "\nnums = [";
    for (int i = 0; i < (int)nums.size(); i++) {
        if(i == (int)nums.size() - 1) {
            std::cout << nums[i] << "]";
            break;
        }
        std::cout << nums[i] << ", ";
    }

    std::cout << "\nThe two numbers that sum to " << target << " are at the following 2 indices [" << solution[0] << "," <<
    solution[1] << "]" << std::endl;

    std::cout << "\nTwoSum executed in: " << duration.count() << " microseconds" << std::endl;
    return 0;
}
