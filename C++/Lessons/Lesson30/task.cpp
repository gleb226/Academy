// #include <iostream>
// #include <vector>
// #include <string>
//
// template<typename InputIt, typename OutputIt, typename Predicate>
// OutputIt myFilter(InputIt first, InputIt last, OutputIt result, Predicate pred) {
//     for (; first != last; ++first) {
//         if (pred(*first)) {
//             *result = *first;
//             ++result;
//         }
//     }
//     return result;
// }
//
// class Student {
//     std::string name;
//     int age;
//     double averageMark;
// public:
//     Student(std::string name, int age, double averageMark)
//         : name(name), age(age), averageMark(averageMark) {}
//     std::string getName() const { return name; }
//     int getAge() const { return age; }
//     double getAverageMark() const { return averageMark; }
//     void print() const {
//         std::cout << name << " (" << averageMark << ")" << std::endl;
//     }
// };
//
// int main() {
//     std::vector<Student> students = {
//         {"Alice", 19, 85},
//         {"Bob", 21, 92},
//         {"Charlie", 18, 75},
//         {"Diana", 20, 81},
//         {"Eve", 17, 68}
//     };
//
//     std::vector<Student> excellent;
//     myFilter(students.begin(), students.end(), std::back_inserter(excellent),
//              [](const Student& s){ return s.getAverageMark() > 80; });
//
//     std::vector<Student> young;
//     myFilter(students.begin(), students.end(), std::back_inserter(young),
//              [](const Student& s){ return s.getAge() < 20; });
//
//     std::cout << "Excellent students:" << std::endl;
//     for (auto& s : excellent) s.print();
//
//     std::cout << "\nStudents younger than 20:" << std::endl;
//     for (auto& s : young) s.print();
//
//     return 0;
// }
