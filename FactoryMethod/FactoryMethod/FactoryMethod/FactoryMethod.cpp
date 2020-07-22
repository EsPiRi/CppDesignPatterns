// FactoryMethod.cpp: Uygulamanın giriş noktasını tanımlar.
//

#include "FactoryMethod.h"

class Product
{
public:
	Product()
	{
		std::cout << "Product created." << std::endl;
	}
	virtual ~Product()
	{
		std::cout << "Product deleted." << std::endl;
	};
	virtual std::string Operation() const = 0;
};

class ConcreteProduct1 :public Product
{
public:
	std::string Operation() const override
	{
		return "{Result of the ConcreteProduct1}";
	}
};
class ConcreteProduct2 :public Product
{
public:
	std::string Operation() const override
	{
		return "{Result of the ConcreteProduct2}";
	}
};

class Creator
{
public:
	Creator() {
		std::cout << "Creator created." << std::endl;
	}
	virtual ~Creator()
	{
		std::cout << "Creator deleted." << std::endl;
	};
	virtual Product* FactoryMethod() const = 0;

	std::string SomeOperation() const
	{
		Product* product = this->FactoryMethod();

		std::string result = "Creator: The same creator's code has just worked with " + product->Operation();

		delete product;
		return result;
	}
};

class ConcreteCreator1 :public Creator
{
public:
	Product* FactoryMethod() const override
	{
		return new ConcreteProduct1();
	}
};


class ConcreteCreator2 :public Creator
{
public:
	Product* FactoryMethod() const override
	{
		return new ConcreteProduct2();
	}
};



void ClientCode(const Creator& creator)
{
	std::cout << "Client: I'm not aware of the creator's class, but it still works.\n"
		<< creator.SomeOperation() << std::endl;
}



int main()
{
	std::cout << "App: Launched with the ConcreteCreator1.\n";
	Creator* creator = new ConcreteCreator1();
	ClientCode(*creator);
	std::cout << std::endl;


	std::cout << "App: Launched with the ConcreteCreator2.\n";
	Creator* creator2 = new ConcreteCreator2();
	ClientCode(*creator2);
	std::cout << std::endl;


	delete creator;
	delete creator2;
	return 0;
}
