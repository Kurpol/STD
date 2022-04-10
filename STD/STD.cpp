
#include <iostream>
#include <memory>


class My_Class
{
private:
    int obNumber;
    int obDenumber;

public: 

    My_Class(int number = 0, int denumber = 0) : obNumber(number), obDenumber(denumber)
    {
        std::cout << "Konstryctor My_Class is completed " << std::endl;
    }

    ~My_Class()
    {
        std::cout << "Object My_Class was destroyed" << std::endl;
    }

    void setNumberDenumber(const int &number, const int &denumber)
    {
        this->obNumber = number;
        this->obDenumber = denumber;
        std::cout << "setNumberDenumber is completed" << std::endl;
    }
    void getNumberDenumber()
    {
        std::cout << "odNumber = " << this->obNumber << std::endl;
        std::cout << "odDenumber = " << this->obDenumber << std::endl;
    }

    friend std::ostream& operator<<(std::ostream& out, My_Class& a)
    {
        out << a.obNumber << " / " << a.obDenumber;
        return out;
    }

    void operator[](const int& number)
    {
        std::cout << "OPERATOR [] " << std::endl;
        getNumberDenumber();
    }

    friend void Foo(My_Class* object);

};

void Foo(My_Class* object, int &&number)
{
    if (object)
    {
        std::cout << "Foo object" << object << std::endl;
    }
    std::cout << object[1] << std::endl;
    
}

int main()
{
    std::unique_ptr<My_Class> object1 = std::make_unique<My_Class>(3,4);
    std::unique_ptr<My_Class> object2 = std::make_unique<My_Class>(1);

    std::cout << "Object1 = " << object1 << std::endl;
    std::cout << "Object2 = " << object2 << std::endl;

    std::cout << "=============================" << std::endl;

    std::cout << "Object1 = " << *object1 << std::endl;
    std::cout << "Object2 = " << *object2 << std::endl;

    auto f2 = std::make_unique<My_Class[]>(5);

    f2[1].setNumberDenumber(2, 3);
    std::cout << f2[1] << std::endl;

    f2[2].setNumberDenumber(4, 5);
    std::cout << f2[2] << std::endl;

    f2[3].setNumberDenumber(6, 7);
    std::cout << f2[3] << std::endl;

    //std::cout << "Foo -> " << std::endl;
    //Foo(f2.get(), 3);

    return 0;
}

