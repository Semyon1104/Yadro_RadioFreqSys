#include <iostream>
#include <vector>

void multiply(std::vector<char>& digits, int multiplier) {
    int carry = 0;
    for (size_t i = 0; i < digits.size(); ++i) {
        int product = (digits[i] - '0') * multiplier + carry;
        digits[i] = (product % 10) + '0';
        carry = product / 10;
    }
    while (carry > 0) {
        digits.push_back((carry % 10) + '0');
        carry /= 10;
    }
}

std::string factorial(int n) {
    if (n < 0) return "0";

    std::vector<char> result = { '1' };
    for (int i = 2; i <= n; ++i) {
        multiply(result, i);
    }

    return std::string(result.rbegin(), result.rend());
}

int main() {
    int n;
    std::cout << "Enter number: ";
    std::cin >> n;

    std::cout << n << "! = " << factorial(n) << std::endl;
    return 0;
}