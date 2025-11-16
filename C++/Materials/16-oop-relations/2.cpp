
#include <iostream> 
#include <string>

class Worker
{
private:
    std::string m_name;

public:
    Worker(std::string name): m_name(name)
    {
    }

    std::string getName() { return m_name; }
};

class Department
{
private:
    Worker* m_worker; // щоб було простіше, в цьому Відділі працює тільки один Працівник, але їх може бути і кілька

public:
    Department(Worker* worker = nullptr)
        : m_worker(worker)
    {
    }
};

int main()
{
    // Створюємо Працівника поза областю видимості класу Department
    Worker* worker = new Worker("Anton"); // створюємо Працівника
    {
        // Створюємо Відділ і передаємо Працівника в Відділ через параметр конструктора
        Department department(worker);

    } // department виходить з області видимості і знищується тут

    // worker продовжує своє існування

    std::cout << worker->getName() << " still exists!";

    delete worker;

    return 0;
}