#include <iostream>
using namespace std;

// Структура вузла
struct Node {
    int data;        // Дані
    Node* next;      // Вказівник на наступний вузол
    
    // Конструктор
    Node(int value) : data(value), next(nullptr) {}
};

// Клас односпрямованого списку
class SinglyLinkedList {
private:
    Node* head;  // Вказівник на перший елемент
    int size;    // Розмір списку
    
public:
    // Конструктор
    SinglyLinkedList() : head(nullptr), size(0) {}
    
    // Деструктор — звільнення пам'яті
    ~SinglyLinkedList() {
        clear();
    }
    
    // Перевірка чи список порожній
    bool isEmpty() const {
        return head == nullptr;
    }
    
    // Отримання розміру
    int getSize() const {
        return size;
    }
    
    // Додавання на початок — O(1)
    void pushFront(int value) {
        Node* newNode = new Node(value);
        newNode->next = head;
        head = newNode;
        size++;
    }
    
    // Додавання в кінець — O(n)
    void pushBack(int value) {
        Node* newNode = new Node(value);
        
        if (isEmpty()) {
            head = newNode;
        } else {
            Node* current = head;
            // Знаходимо останній вузол
            while (current->next != nullptr) {
                current = current->next;
            }
            current->next = newNode;
        }
        size++;
    }
    
    // Вставка на певну позицію — O(n)
    void insert(int position, int value) {
        if (position < 0 || position > size) {
            cout << "Некоректна позиція!" << endl;
            return;
        }
        
        if (position == 0) {
            pushFront(value);
            return;
        }
        
        Node* newNode = new Node(value);
        Node* current = head;
        
        // Переходимо до вузла перед позицією вставки
        for (int i = 0; i < position - 1; i++) {
            current = current->next;
        }
        
        newNode->next = current->next;
        current->next = newNode;
        size++;
    }
    
    // Видалення з початку — O(1)
    void popFront() {
        if (isEmpty()) {
            cout << "Список порожній!" << endl;
            return;
        }
        
        Node* temp = head;
        head = head->next;
        delete temp;
        size--;
    }
    
    // Видалення з кінця — O(n)
    void popBack() {
        if (isEmpty()) {
            cout << "Список порожній!" << endl;
            return;
        }
        
        if (head->next == nullptr) {
            delete head;
            head = nullptr;
        } else {
            Node* current = head;
            // Знаходимо передостанній вузол
            while (current->next->next != nullptr) {
                current = current->next;
            }
            delete current->next;
            current->next = nullptr;
        }
        size--;
    }
    
    // Видалення за позицією — O(n)
    void removeAt(int position) {
        if (position < 0 || position >= size) {
            cout << "Некоректна позиція!" << endl;
            return;
        }
        
        if (position == 0) {
            popFront();
            return;
        }
        
        Node* current = head;
        for (int i = 0; i < position - 1; i++) {
            current = current->next;
        }
        
        Node* temp = current->next;
        current->next = temp->next;
        delete temp;
        size--;
    }
    
    // Пошук елемента — O(n)
    int find(int value) const {
        Node* current = head;
        int position = 0;
        
        while (current != nullptr) {
            if (current->data == value) {
                return position;
            }
            current = current->next;
            position++;
        }
        
        return -1;  // Не знайдено
    }
    
    // Отримання елемента за позицією — O(n)
    int get(int position) const {
        if (position < 0 || position >= size) {
            throw out_of_range("Некоректна позиція!");
        }
        
        Node* current = head;
        for (int i = 0; i < position; i++) {
            current = current->next;
        }
        
        return current->data;
    }
    
    // Виведення списку
    void print() const {
        if (isEmpty()) {
            cout << "Список порожній" << endl;
            return;
        }
        
        Node* current = head;
        cout << "Список: ";
        while (current != nullptr) {
            cout << current->data;
            if (current->next != nullptr) {
                cout << " -> ";
            }
            current = current->next;
        }
        cout << " -> NULL" << endl;
    }
    
    // Реверс списку — O(n)
    void reverse() {
        Node* prev = nullptr;
        Node* current = head;
        Node* next = nullptr;
        
        while (current != nullptr) {
            next = current->next;  // Зберігаємо наступний
            current->next = prev;  // Реверсуємо вказівник
            prev = current;        // Рухаємось вперед
            current = next;
        }
        
        head = prev;
    }
    
    // Очищення списку
    void clear() {
        while (!isEmpty()) {
            popFront();
        }
    }
};

int main() {
    SinglyLinkedList list;
    
    // Додавання елементів
    list.pushBack(10);
    list.pushBack(20);
    list.pushBack(30);
    list.pushFront(5);
    list.print();  // 5 -> 10 -> 20 -> 30 -> NULL
    
    // Вставка на позицію
    list.insert(2, 15);
    list.print();  // 5 -> 10 -> 15 -> 20 -> 30 -> NULL
    
    // Пошук
    int pos = list.find(20);
    cout << "Елемент 20 на позиції: " << pos << endl;  // 3
    
    // Видалення
    list.popFront();
    list.popBack();
    list.print();  // 10 -> 15 -> 20 -> NULL
    
    // Реверс
    list.reverse();
    list.print();  // 20 -> 15 -> 10 -> NULL
    
    // Розмір
    cout << "Розмір списку: " << list.getSize() << endl;  // 3
    
    return 0;
}