#include "Serializer.hpp"

int main()
{
    //should not compile (have to be in comment for the correction)
    // Serializer test_not_compile;
    // (void)test_not_compile;
    Data testptr;
    testptr.name = "testname";
    std::cout << "before : " << &testptr << std::endl;
    uintptr_t serializePtr = Serializer::serialize(&testptr);
    Data * deserializePtr = Serializer::deserialize(serializePtr);
    std::cout << "after : " << deserializePtr << std::endl;
}