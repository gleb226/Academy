// #include <iostream>
// #include <vector>
// #include <iterator>
//
//
// template<typename InputIt, typename OutputIt, typename Predicate>
// OutputIt myFilter(InputIt first, InputIt last, OutputIt result, Predicate pred) {
//     for (; first != last; ++first) {
//         if (pred(*first)) {
//             *result = *first;
//             ++result;
//         }
//     }
//
//     return result;
// }
//
// int main() {
//     std::vector<int> input = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
//     //std::vector<int> output;
//     std::vector<int> output(input.size());
//
//     auto isEven = [](int number) { return number % 2 == 0; };
//
//     //myFilter(input.begin(), input.end(), std::back_inserter(output), isEven);
//     myFilter(input.begin(), input.end(), output.begin(), isEven);
//
//     output.resize(std::distance(output.begin(), std::remove(output.begin(), output.end(), 0)));
//     for (int number: output) {
//         std::cout << number << " ";
//     }
//     std::cout << std::endl;
//
//     return 0;
// }
