// #include <iostream>
// #include <cstdio>
// using namespace std;

// int max_of_four(int a, int b, int c, int d);

// int main()
// {
//     int a, b, c, d;
//     scanf("%d %d %d %d", &a, &b, &c, &d);
//     int ans = max_of_four(a, b, c, d);
//     printf("%d", ans);

//     return 0;
// }

// int max_of_four(int a, int b, int c, int d)
// {
//     if (a > b)
//     {
//         if (a > c)
//         {
//             if (a > d)
//             {
//                 return a;
//             }
//             else
//                 return d;
//         }
//         else if (c > d)
//         {
//             return c;
//         }
//     }
//     else if (b > c)
//     {
//         if (b > d)
//         {
//             return b;
//         }
//     }
// }

// ***********
// OOPS
// ***********

#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
#include <sys/types.h>
#include <dirent.h>
#include <sys/stat.h>

// class Animal
// {

//     // Private variables are only available to methods
//     // in the class
// private:
//     std::string name;
//     double height;
//     double weight;

//     // Static variables share the same value for all
//     // objects of the Animal class
//     static int numOfAnimals;

//     // Public fields and methods can be accessed by
//     // anything with access to the object
// public:
//     std::string GetName() { return name; }

//     // Because we don't know what an objects name is
//     // because the class is created before the object
//     // we can refer to all objects using this
//     // The pointer operator is used to access an
//     // objects fields and methods
//     void SetName(std::string name) { this->name = name; }
//     double GetHeight() { return height; }
//     void SetHeight(double height) { this->height = height; }
//     double GetWeight() { return weight; }
//     void SetWeight(double weight) { this->weight = weight; }

//     // You can declare function prototypes
//     void SetAll(std::string, double, double);

//     // A constructor is called each time an object is created
//     Animal(std::string, double, double);

//     // Create an overloaded constructor for when no data is passed
//     Animal();

//     // A deconstructor is called automatically when an object
//     // is deleted or is no longer used
//     // The default is fine, but you should create custom ones
//     // when you must release memory, or resources
//     ~Animal();

//     // Static methods can only access static fields
//     static int GetNumOfAnimals() { return numOfAnimals; }

//     // Created to be overwritten
//     void ToString();
// };

// // Refer to class fields and methods with ::
// int Animal::numOfAnimals = 0;

// // Define the prototype method
// void Animal::SetAll(std::string name, double height,
//                     double weight)
// {
//     this->name = name;
//     this->weight = weight;
//     this->height = height;
//     Animal::numOfAnimals++;
// }

// // Define the constructor
// Animal::Animal(std::string name, double height,
//                double weight)
// {
//     this->name = name;
//     this->weight = weight;
//     this->height = height;
//     Animal::numOfAnimals++;
// }

// Animal::Animal()
// {
//     this->name = "";
//     this->weight = 0;
//     this->height = 0;
//     Animal::numOfAnimals++;
// }

// Animal::~Animal()
// {
//     std::cout << "Animal " << this->name << " destroyed\n";
// }

// void Animal::ToString()
// {
//     std::cout << this->name << " is " << this->height << " cms tall and " << this->weight << " kgs in weight\n";
// }

// // Through inheritance a class inherits all fields and methods
// // defined by the super, or inherited from class
// class Dog : public Animal
// {
// private:
//     std::string sound = "Wooof";

// public:
//     // You can access to the private field name
//     // by calling GetName()
//     void MakeSound()
//     {
//         std::cout << "The dog " << this->GetName() << " says " << this->sound << "\n";
//     }

//     // The Dogs constructor
//     Dog(std::string, double, double, std::string);

//     // The default constructor calls Animals default
//     // constructor
//     Dog() : Animal(){};

//     // Overwrite ToString
//     void ToString();
// };

// // Calls the superclasses constructor to handle
// // initalization
// Dog::Dog(std::string name, double height,
//          double weight, std::string sound) : Animal(name, height, weight)
// {
//     this->sound = sound;
// }

// // Overwrite ToString
// void Dog::ToString()
// {
//     // Because the attributes were private in Animal they must be retrieved
//     // by called the get methods
//     std::cout << this->GetName() << " is " << this->GetHeight() << " cms tall, " << this->GetWeight() << " kgs in weight and says " << this->sound << "\n";
// }

// int main()
// {
//     // Create object without setting values in constructor
//     Animal fred;
//     fred.SetHeight(33);
//     fred.SetWeight(10);
//     fred.SetName("Fred");
//     // Get the values for the Animal
//     fred.ToString();

//     fred.SetAll("Fred", 34, 12);

//     fred.ToString();

//     // Setting values with constructor
//     Animal tom("Tom", 36, 15);
//     tom.ToString();

//     // Demonstrate inherited Dog class
//     Dog spot("Spot", 38, 16, "Wooof");

//     // See different output from overwritten ToString()
//     spot.ToString();

//     // Call static methods by using the class name to
//     // show the total Animals created
//     std::cout << "Number of Animals " << Animal::GetNumOfAnimals() << "\n";

//     return 0;
// }

class Person
{
private:
    std::string name;
    int age;
    std::string job;

    // static for every instance
    static int NumofPersons;

public:
    std::string getName()
    {
        return this->name;
    }
    void SetName(std::string name) { this->name = name; }
    int getAge()
    {
        return this->age;
    }
    void SetAge(int age) { this->age = age; }
    std::string getJob()
    {
        return this->job;
    }
    void SetJob(std::string job) { this->job = job; }

    // set all prototypes
    void SetAll(std::string, int, std::string);

    // Constructor
    Person(std::string, int, std::string);

    // Contructor Overload - for default values.
    Person();

    // Destructor
    ~Person();

    static int GetNumofPersons()
    {
        return NumofPersons;
    }

    void toString();
};

int Person::NumofPersons = 0;

void Person::SetAll(std::string name, int age, std::string job)
{
    this->name = name;
    this->age = age;
    this->job = job;
    Person::NumofPersons++;
}

// Defining the Constructor
Person::Person(std::string name, int age, std::string job)
{
    this->name = name;
    this->age = age;
    this->job = job;
    Person::NumofPersons++;
}

// Defining Constructor Overload
Person::Person()
{
    this->name = "";
    this->age = 0;
    this->job = "";
    Person::NumofPersons++;
}

// Defining Destructor
Person::~Person()
{
    std::cout << "The Person " << this->name << " is destroyed.\n";
}

void Person::toString()
{
    std::cout << this->name << " is " << this->age << " years old and is a " << this->job << "\n";
}

class Student : public Person
{
private:
    int grade;

public:
    int getQualification()
    {
        std::cout << this->getName() << " is in grade " << this->grade << "\n";
    }

    Student(std::string, int, std::string, int);

    Student() : Person(){};

    void toString();
};

Student::Student(std::string name, int age, std::string job, int grade) : Person(name, age, job)
{
    this->grade = grade;
}

void Student::toString()
{
    std::cout << this->getName() << " is " << this->getAge() << " years old and is a " << this->getJob() << " and is in grade " << this->grade << "\n";
}

int main()
{
    Person john;
    john.toString();
    john.SetName("john");
    john.SetAge(19);
    john.SetJob("Scientist");
    john.toString();

    john.SetAll("John", 20, "Inventor");
    john.toString();

    Person max("Max", 20, "Astronaut");
    max.toString();

    Student miley("Miley", 20, "Student", 10);
    miley.toString();

    std::cout << "Number of Persons: " << Person::GetNumofPersons() << "\n";

    return 0;
}