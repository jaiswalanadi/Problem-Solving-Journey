#include <iostream>

class Solution {
public:
    bool isPalindrome(int x) {
        // Handle negative numbers and numbers ending in 0 (except 0 itself)
        // Negative numbers cannot be palindromes.
        // Numbers ending in 0 (like 10, 120) cannot be palindromes unless the number itself is 0.
        if (x < 0 || (x % 10 == 0 && x != 0)) {
            return false;
        }

        int reversedNumber = 0;
        int originalNumber = x; // Store the original number for comparison

        while (x > 0) {
            int digit = x % 10; // Get the last digit
            // Check for potential overflow before updating reversedNumber
            // This is important for large numbers where reversedNumber * 10 might exceed INT_MAX
            if (reversedNumber > INT_MAX / 10 || (reversedNumber == INT_MAX / 10 && digit > 7)) {
                return false; // Overflow would occur, so it's not a valid palindrome
            }
            reversedNumber = reversedNumber * 10 + digit; // Append the digit to reversedNumber
            x /= 10; // Remove the last digit from x
        }

        return originalNumber == reversedNumber;
    }
};

