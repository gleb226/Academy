#include <iostream>
#include <string>
#include <vector>

// Оскільки відносини між цими класами двонаправлені, то для класу Doctor тут потрібно використати попереднє оголошення
class Doctor;

class Patient
{
private:
	std::string m_name;
	std::vector<Doctor*> m_doctor; // завдяки вищенаведеному попередньому оголошенню Doctor, цей рядок не викличе помилку компіляції

	// Ми оголошуємо метод addDoctor() закритим, тому що не хочемо його відкритого використання.
	// Доступ до нього відбуватиметься через Doctor::addPatient().
	// Ми визначимо цей метод після визначення класу Doctor, тому що нам спочатку потрібно визначити Doctor, щоб використовувати будь-що, пов'язане з ним
	void addDoctor(Doctor* doc);

public:
	Patient(std::string name)
		: m_name(name)
	{
	}

	// Ми реалізуємо перевантаження оператора виводу нижче визначення класу Doctor, тому що він як раз і потрібен для реалізації перевантаження
	friend std::ostream& operator<<(std::ostream& out, const Patient& pat);

	std::string getName() const { return m_name; }

	// Ми робимо клас Doctor дружнім, щоб мати доступ до закритого методу addDoctor().
	// Примітка: Ми б хотіли зробити дружнім тільки один метод addDoctor(), але ми не можемо це зробити, тому що Doctor попередньо оголошений
	friend class Doctor;
};

class Doctor
{
private:
	std::string m_name;
	std::vector<Patient*> m_patient;

public:
	Doctor(std::string name) :
		m_name(name)
	{
	}

	void addPatient(Patient* pat)
	{
		// Лікар додає Пацієнта
		m_patient.push_back(pat);

		// Пацієнт додає Лікаря
		pat->addDoctor(this);
	}


	friend std::ostream& operator<<(std::ostream& out, const Doctor& doc)
	{
		unsigned int length = doc.m_patient.size();
		if (length == 0)
		{
			out << doc.m_name << " has no patients right now";
			return out;
		}

		out << doc.m_name << " is seeing patients: ";
		for (unsigned int count = 0; count < length; ++count)
			out << doc.m_patient[count]->getName() << ' ';

		return out;
	}

	std::string getName() const { return m_name; }
};

void Patient::addDoctor(Doctor* doc)
{
	m_doctor.push_back(doc);
}

std::ostream& operator<<(std::ostream& out, const Patient& pat)
{
	unsigned int length = pat.m_doctor.size();
	if (length == 0)
	{
		out << pat.getName() << " has no doctors right now";
		return out;
	}

	out << pat.m_name << " is seeing doctors: ";
	for (unsigned int count = 0; count < length; ++count)
		out << pat.m_doctor[count]->getName() << ' ';

	return out;
}


int main()
{
	// Створюємо Пацієнтів поза областю видимості класу Doctor
	Patient* p1 = new Patient("Anton");
	Patient* p2 = new Patient("Ivan");
	Patient* p3 = new Patient("Derek");

	// Створюємо Лікарів поза областю видимості класу Patient
	Doctor* d1 = new Doctor("John");
	Doctor* d2 = new Doctor("Tom");

	d1->addPatient(p1);

	d2->addPatient(p1);
	d2->addPatient(p3);

	std::cout << *d1 << '\n';
	std::cout << *d2 << '\n';
	std::cout << *p1 << '\n';
	std::cout << *p2 << '\n';
	std::cout << *p3 << '\n';

	delete p1;
	delete p2;
	delete p3;

	delete d1;
	delete d2;

	return 0;
}