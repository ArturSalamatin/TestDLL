#include <iostream>
#include <Wrapper.h>

int main()
{
    Wrapper* instance = new Wrapper();
    //   instance->useOperator();
    //   instance->useManager();

    delete instance;

    std::cout << "inside main and Wrapper included";

    return 0;
}
