#include  "Bureaucrat.hpp"

int main(void)
{
    {
        try
        {
            Bureaucrat bur("name",1000);
            std::cout <<bur<<std::endl;
        }
        catch(const std::exception &e)
        {
            std::cout<<e.what();
        }
    }
    {
        try
        {
            Bureaucrat bur("name",-10);
            std::cout <<bur<<std::endl;
        }
        catch(const std::exception &e)
        {
            std::cout<<e.what();
        }
    }
    {
        try
        {
            Bureaucrat bur("alex",10);
            std::cout <<bur<<std::endl;
        }
        catch(const std::exception &e)
        {
            std::cout<<e.what();
        }
    }

}