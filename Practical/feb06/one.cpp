// #include <bits/stdc++.h>
// using namespace std;

// int main() {
//     long a = 123456789123456789;
//     long b = 987654321987654321;

//     cout << a*b << endl;
//     return 0;
// }
// #include <iostream>
// #include <boost/multiprecision/cpp_int.hpp>

// int main() {
//     using namespace boost::multiprecision;

//     cpp_int a = 123456789123456789;
//     cpp_int b = 987654321987654321;
//     cpp_int result = a * b;

//     std::cout << result << std::endl;
//     return 0;
// }

#include <iostream>

int main() {
    __int128 a = 123456789123456789;
    __int128 b = 987654321987654321;
    __int128 result = a * b;

    // Function to print __int128 since cout doesn't support it
    auto print128 = []( __int128 num ) {
        if (num == 0) {
            std::cout << "0";
            return;
        }
        std::string output;
        while (num > 0) {
            output += (char)('0' + (num % 10));
            num /= 10;
        }
        for (auto it = output.rbegin(); it != output.rend(); ++it)
            std::cout << *it;
    };

    print128(result);
    std::cout << std::endl;
    return 0;
}