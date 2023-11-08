#include <iostream>

// Function to reverse the bits of a 32-bit unsigned integer
uint32_t reverseBits(uint32_t n) {
    // Base case: If the input is 0 or 1, return it as it is
    if (n <= 1) {
        return n;
    }

    // Calculate the number of bits required to represent n
    int numBits = 0;
    uint32_t temp = n;
    while (temp > 0) {
        numBits++;
        temp >>= 1;
    }

    // Split the input into two parts (left and right)
    uint32_t left = n >> (numBits / 2);
    uint32_t right = n & ((1 << (numBits / 2)) - 1);

    // Reverse the bits of the left and right parts recursively
    uint32_t reversedLeft = reverseBits(left);
    uint32_t reversedRight = reverseBits(right);

    // Combine the reversed left and right parts
    uint32_t reversed = (reversedLeft << (numBits / 2)) | reversedRight;

    return reversed;
}

int main() {
    uint32_t n = 00000000011100011100011101011000; // Example input

    // Call the reverseBits function
    uint32_t reversed = reverseBits(n);

    std::cout << "Original: " << n << std::endl;
    std::cout << "Reversed: " << reversed << std::endl;

    return 0;
}
