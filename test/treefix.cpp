#include <iostream>

// Class with an implicit public constructor
class TreeFix {
public:
    static void printMessage() {
        std::cout << "Fix" << std::endl;
    }
};

int main() {
    // Attempt to create an instance of TreeFix
    // This should ideally be prevented, but will succeed due to the implicit public constructor
    TreeFix instance;
    instance.printMessage();

    return 0;
}