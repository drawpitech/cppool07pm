#include "../ex00/Skat.hpp"

int main() {
    Skat s("Junior", 5);
    std::cout << "Soldier " << s.name() << std::endl;
    s.status();
    s.useStimPaks();
    return 0;
}
