#include <algorithm> // copy, sort
#include <iostream> // cin, streamsize
#include <iterator> // back_inserter, istream_iterator
#include <limits> // numeric_limits
#include <sstream> // istringstream
#include <string> // getline, string
#include <vector> // vector

struct Student {
    std::string name;
    int math_grade;
    int english_grade;

    Student(std::string name, int math_grade, int english_grade) :
        name(name), math_grade(math_grade), english_grade(english_grade) {}
};

void print_student_names(std::vector<Student> students) {
    for (int i = 0; i < students.size(); i++) {
        if (i == students.size() - 1) {
            std::cout << students[i].name << '\n';
        } else {
            std::cout << students[i].name << " ";
        }
    }
}

void print_sorted_students(std::vector<Student> students) {
    // sort students by their total grade in ascending order
    std::sort(students.begin(), students.end(), [](Student a, Student b) {
          return a.math_grade + a.english_grade < b.math_grade + b.english_grade;
    });
    print_student_names(students);
    // sort students by their total grade in descending order
    std::sort(students.begin(), students.end(), [](Student a, Student b) {
          return a.math_grade + a.english_grade > b.math_grade + b.english_grade;
    });
    print_student_names(students);
}

template<typename T>
std::vector<T> get_words() {
    std::string line;
    std::getline(std::cin, line);
    std::istringstream ss{line};
    std::vector<T> v;
    std::copy(std::istream_iterator<T>{ss}, std::istream_iterator<T>{}, std::back_inserter(v));
    return v;
}

void ignore_line() {
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

int main() {
    int students_length;
    std::cin >> students_length;
    ignore_line();
    std::vector<Student> students;
    for (int i = 0; i < students_length; i++) {
        std::vector<std::string> line = get_words<std::string>();
        int math_grade = std::stoi(line[1]);
        int english_grade = std::stoi(line[2]);
        Student s(line[0], math_grade, english_grade);
        students.emplace_back(s);
    }
    print_sorted_students(students);
}
