#include <iostream>
#include <gtest/gtest.h>
#include "IFactory.h"
#include "ConcreteFactory.h"
#include "ConcreteProductA.h"
#include "ConcreteProductB.h"

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
// Тест на создание ConcreteProductA и вызов методов init и performTask
TEST(FactoryPatternTest, CreateConcreteProductA) {
    IFactory* factory = new ConcreteFactory();
    IProduct* product = factory->createConcreteProductA();

    product->init();
    product->performTask();

    delete product;
    delete factory;
}

// Тест на создание ConcreteProductB и вызов методов init и performTask
TEST(FactoryPatternTest, CreateConcreteProductB) {
    IFactory* factory = new ConcreteFactory();
    IProduct* product = factory->createConcreteProductB();

    product->init();
    product->performTask();

    delete product;
    delete factory;
}

// Тест на создание ConcreteFactory и вызов методов createConcreteProductA и createConcreteProductB
TEST(FactoryPatternTest, CreateConcreteFactory) {
    IFactory* factory = new ConcreteFactory();

    IProduct* productA = factory->createConcreteProductA();
    IProduct* productB = factory->createConcreteProductB();

    productA->init();
    productA->performTask();

    productB->init();
    productB->performTask();

    delete productA;
    delete productB;
    delete factory;
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
