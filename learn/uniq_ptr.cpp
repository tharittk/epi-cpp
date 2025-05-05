#include <iostream>


class Resource {
	public:
		Resource() {std::cout << "resource created" << std::endl;}
		~Resource() {std::cout << "resource destroyed" << std::endl;}
};

int main() {
	auto r = new Resource();
	std::unique_ptr<Resource> u(new Resource);
	
	// this will fail, copy constructor is deleted
	//auto u2 = u; 	

	auto u2 = std::move(u);	
	return 0;
}
