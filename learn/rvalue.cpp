#include<iostream>
#include<utility>

template<typename T>
class Resource{
	public:
		Resource(){
			std::cout << "Empty constructor" << std::endl;	
		}
		Resource(Resource& other){
			std::cout << "Copy constructor" << std::endl;
		}
		Resource(Resource&& other){
			std::cout << "Move constructor" << std::endl;
		}
		Resource& operator=(Resource&& other){
			std::cout << "Move assignment" << std::endl;
			return *this;
		}
};

int main(){
	Resource<int> resource;
	Resource<int> lcon = resource;
	Resource<int> mcon = std::move(resource);
	std::cout << "----" << std::endl;	
	Resource<int> a;
	Resource<int> ma;
	ma = std::move(a);	
}
