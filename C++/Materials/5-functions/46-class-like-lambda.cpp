class {

private:
	int id; // копіювання зовнішнього id 

public:
	void operator() () {
		std::cout << "id: " << id << std::endl;
		++id; // OK 
	}
};