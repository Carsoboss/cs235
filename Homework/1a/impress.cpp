#include <iostream>
#include <memory>
#include <vector>
#include <stdexcept>

// Base class Animal
class Animal
{
public:
    virtual ~Animal() = default;

    virtual void makeSound() const = 0; // Pure virtual function
};

// Derived class Dog
class Dog : public Animal
{
public:
    void makeSound() const override
    {
        std::cout << "Dog says: Woof!" << std::endl;
    }
};

// Derived class Cat
class Cat : public Animal
{
public:
    void makeSound() const override
    {
        std::cout << "Cat says: Meow!" << std::endl;
    }
};

// Function to demonstrate polymorphism
void animalSound(const Animal &animal)
{
    animal.makeSound();
}

int main()
{
    try
    {
        // Creating a vector of smart pointers to Animal objects
        std::vector<std::unique_ptr<Animal>> zoo;

        // Adding animals to the zoo
        zoo.push_back(std::make_unique<Dog>());
        zoo.push_back(std::make_unique<Cat>());

        // Demonstrating polymorphism
        for (const auto &animal : zoo)
        {
            animalSound(*animal);
        }
    }
    catch (const std::exception &e)
    {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }
    catch (...)
    {
        std::cerr << "An unknown error has occurred" << std::endl;
        return 2;
    }

    return 0;
}
