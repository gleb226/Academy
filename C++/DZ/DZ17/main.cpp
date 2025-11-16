#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

struct Employee {
    string surname;
    string name;
    int age;
    string position;

    void print() const {
        cout << surname << " " << name << ", age: " << age << ", position: " << position << endl;
    }
};

void load(const string& filename, vector<Employee>& list) {
    ifstream file(filename);
    Employee e;
    while (getline(file, e.surname)) {
        getline(file, e.name);
        file >> e.age;
        file.ignore();
        getline(file, e.position);
        list.push_back(e);
    }
    file.close();
}

void save(const string& filename, const vector<Employee>& list) {
    ofstream file(filename);
    for (const auto& e : list) {
        file << e.surname << endl;
        file << e.name << endl;
        file << e.age << endl;
        file << e.position << endl;
    }
    file.close();
}

void add(vector<Employee>& list) {
    Employee e;
    cout << "Surname: ";
    getline(cin, e.surname);
    cout << "Name: ";
    getline(cin, e.name);
    cout << "Age: ";
    cin >> e.age;
    cin.ignore();
    cout << "Position: ";
    getline(cin, e.position);
    list.push_back(e);
}

void edit(vector<Employee>& list) {
    string s;
    cout << "Enter surname: ";
    getline(cin, s);
    for (auto& e : list) {
        if (e.surname == s) {
            string input;
            cout << "New name (leave empty to skip): ";
            getline(cin, input);
            if (!input.empty()) e.name = input;
            cout << "New age (0 to skip): ";
            int a;
            cin >> a;
            cin.ignore();
            if (a > 0) e.age = a;
            cout << "New position (leave empty to skip): ";
            getline(cin, input);
            if (!input.empty()) e.position = input;
            break;
        }
    }
}

void remove(vector<Employee>& list) {
    string s;
    cout << "Enter surname: ";
    getline(cin, s);
    vector<Employee> temp;
    for (const auto& e : list) {
        if (e.surname != s) temp.push_back(e);
    }
    list = temp;
}

void searchBySurname(const vector<Employee>& list) {
    string s;
    cout << "Enter surname: ";
    getline(cin, s);
    for (const auto& e : list) {
        if (e.surname == s) e.print();
    }
}

void searchByAge(const vector<Employee>& list) {
    int a;
    cout << "Enter age: ";
    cin >> a;
    cin.ignore();
    for (const auto& e : list) {
        if (e.age == a) e.print();
    }
}

void searchByLetter(const vector<Employee>& list) {
    char c;
    cout << "Enter first letter: ";
    cin >> c;
    cin.ignore();
    for (const auto& e : list) {
        if (tolower(e.surname[0]) == tolower(c)) e.print();
    }
}

void exportList(const vector<Employee>& list) {
    string file;
    cout << "Enter .txt filename: ";
    getline(cin, file);
    ofstream out(file);
    for (const auto& e : list) {
        out << e.surname << " " << e.name << " " << e.age << " " << e.position << endl;
    }
    out.close();
}

void showAll(const vector<Employee>& list) {
    for (const auto& e : list) e.print();
}

int main() {
    vector<Employee> employees;
    string file;
    cout << "Enter file to load: ";
    getline(cin, file);
    load(file, employees);

    int choice;
    do {
        cout << "\n1. Add\n2. Edit\n3. Delete\n4. Search by surname\n5. Search by age\n6. Search by letter\n7. Show all\n8. Export to .txt\n9. Save\n0. Exit\nChoice: ";
        cin >> choice;
        cin.ignore();

        if (choice == 1) add(employees);
        else if (choice == 2) edit(employees);
        else if (choice == 3) remove(employees);
        else if (choice == 4) searchBySurname(employees);
        else if (choice == 5) searchByAge(employees);
        else if (choice == 6) searchByLetter(employees);
        else if (choice == 7) showAll(employees);
        else if (choice == 8) exportList(employees);
        else if (choice == 9) save(file, employees);
        else if (choice == 0) save(file, employees);

    } while (choice != 0);

    return 0;
}
