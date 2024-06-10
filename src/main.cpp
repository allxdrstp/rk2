#include "IProduct.h"
#include "IFactory.h"
#include "ConcreteFactory.h"

#include <iostream>

class IProduct
{
public:
    virtual void init() const = 0;
    virtual void performTask() const = 0;
};
class IFactory
{
public:
    virtual IProduct* createConcreteProductA() const = 0;
    virtual IProduct* createConcreteProductB() const = 0;
};

class ConcreteFactory : public IFactory
{
public:
    ConcreteFactory();

    IProduct* createConcreteProductA() const override;
    IProduct* createConcreteProductB() const override;
};
class ConcreteProductA : public IProduct
{
    public:
        ConcreteProductA();

        void init() const override;
        void performTask() const override;
};
class ConcreteProductB : public IProduct
{
    public:
        ConcreteProductB();

        void init() const override;
        void performTask() const override;
};

class ConcreteFactory : public IFactory
{
public:
    ConcreteFactory();

    IProduct* createConcreteProductA() const override;
    IProduct* createConcreteProductB() const override;
};

ConcreteFactory::ConcreteFactory()
{
}

IProduct *ConcreteFactory::createConcreteProductA() const
{
    return new ConcreteProductA();
}

IProduct *ConcreteFactory::createConcreteProductB() const
{
    return new ConcreteProductB();
}

int main()
{
    IFactory *factory = new ConcreteFactory();
    IProduct *product;

    int option;
    std::cin >> option;

    if (option == 1)
    {
        product = factory->createConcreteProductA();
    }
    else
    {
        product = factory->createConcreteProductB();
    }

    product->init();
    product->performTask();

    return 0;
}
