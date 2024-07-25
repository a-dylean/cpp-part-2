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
    A* a = dynamic_cast<A*>(p);
    if(a == NULL)
    {
        B* b = dynamic_cast<B*>(p);
        if(b == NULL)
        {
            C* c = dynamic_cast<C*>(p);
            if(c == NULL)
            {
                std::cout << "It's either an unknown type or a Base pointer!" << std::endl;
            }
            else
            {
                std::cout << "It's a type C! (Found in the identify pointer function)" << std::endl;
            }
        }
        else
        {
            std::cout << "It's a type B! (Found in the identify pointer function)" << std::endl;
        }
    }
    else
    {
        std::cout << "It's a type A! (Found in the identify pointer function)" << std::endl;
    }
}

void identify(Base &p)
{
    try
    {
        A& a = dynamic_cast<A&>(p);
        (void)a;
        std::cout << "It's a type A! (Found in the identify ref function)" << std::endl;
        return;
    }
    catch(std::exception& e){}
    try
    {
        B& b = dynamic_cast<B&>(p);
        (void)b;
        std::cout << "It's a type B! (Found in the identify ref function)" << std::endl;
        return;
    }
    catch(std::exception& e){}
    try
    {
        C& c = dynamic_cast<C&>(p);
        (void)c;
        std::cout << "It's a type C! (Found in the identify ref function)" << std::endl;
        return;
    }
    catch(std::exception& e)
    {
        std::cout << "It's either an unknown type or a Base pointer!" << std::endl;
    }
}

int main() {
	srand(time(NULL));
	
	int	i = 0;
	while (i < 2)
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