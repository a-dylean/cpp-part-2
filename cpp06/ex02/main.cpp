#include "Base.hpp"

Base * generate(void) {
	switch (rand() % 3) {
	case 0:
		return (new A());
		break;
	case 1:
		return (new B());
		break;
	case 2:
		return (new C());
		break;
	default:
		return (NULL);
	}
}

void identify(Base *p)
{
   	if (dynamic_cast<A*>(p) != NULL)
        std::cout << "type A" << std::endl;
    else if (dynamic_cast<B*>(p) != NULL)
        std::cout << "type B" << std::endl;
    else if (dynamic_cast<C*>(p) != NULL)
        std::cout << "type C" << std::endl;
    else
        std::cout << "type Unknown" << std::endl;
}

void identify(Base &p)
{
    try
    {
        A& a = dynamic_cast<A&>(p);
        (void)a;
        std::cout << "type A" << std::endl;
        return;
    }
    catch(std::exception& e){}
    try
    {
        B& b = dynamic_cast<B&>(p);
        (void)b;
        std::cout << "type B" << std::endl;
        return;
    }
    catch(std::exception& e){}
    try
    {
        C& c = dynamic_cast<C&>(p);
        (void)c;
        std::cout << "type C" << std::endl;
        return;
    }
    catch(std::exception& e)
    {
        std::cout << "type Unknown" << std::endl;
    }
}

int main() {
	srand(time(NULL));
	
	int	i = 0;
	while (i < 3)
	{
		Base *Test = generate();

		identify(Test);
		identify(*Test);
		delete (Test);

		std::cout << std::endl;
		i++;
	}
	return (0);
}