#include  "Bureaucrat.hpp"

int main(void)
{
    try
    {
        std::cout << "Test 1: grade = 0" << std::endl;
        Bureaucrat b1("Alex", 0);
        std::cout << b1 << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }
    try
    {
        std::cout << "\nTest 2: grade = 10" << std::endl;
        Bureaucrat b2("Bob", 10);
        std::cout << b2 << std::endl;
        b2.increment();
        std::cout << "After increment: " << b2 << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }
    try
    {
        std::cout << "\nTest 3: grade = 151" << std::endl;
        Bureaucrat b3("Charlie", 151);
        std::cout << b3 << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }
    return 0;
}
