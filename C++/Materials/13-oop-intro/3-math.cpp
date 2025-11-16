#include <iostream>

class Product {
private:
	int id;
	std::string name;

public:
	Product(int id, const std::string& name) {
		this->id = id;
		setName(name);
	}

	int getId() const { 
		return id; 
	}

	std::string getName() const {
		return name;
	}

	void setName(const std::string& name) { 
		this->name = name;
	}
};

int main() {
	Product product(1, "Продукт 1");

	// Отримання значення readonly поля
	std::cout << "ID: " << product.getId() << std::endl;

	// Зміна значення readonly поля (неможливо)
	// product.id_ = 456; // ERROR: cannot assign to member 'id_' in 'const Product'

	// Зміна та отримання значення не-readonly поля
	product.setName("Товар");
	std::cout << "Назва: " << product.getName() << std::endl;

	return 0;
}