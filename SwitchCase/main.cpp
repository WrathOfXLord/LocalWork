#include <iostream>


// void breakAt(int at, bool breakable=false) {
//     if(at > 5)
//         return;

//     switch (at)
//     {
//     case 5:
//         std::cout << 5;
//         if(breakable)
//             break;
//     case 4:
//         std::cout << 4;
//         if(breakable)
//             break;
//     case 3:
//         std::cout << 3;
//         if(breakable)
//             break;
//     case 2:
//         std::cout << 2;
//         if(breakable)
//             break;
//     case 1:
//         std::cout << 1;
//     }
// }


void similarToDuff(int value) {
    int num {(value + 4) / 5};
    switch(value % 5) {
        case 0: do { std::cout << 0;
        // c++17 fall through attribute
        [[fallthrough]];
        case 4:      std::cout << 4;
        [[fallthrough]];
        case 3:      std::cout << 3;
        [[fallthrough]];
        case 2:      std::cout << 2;
        [[fallthrough]];
        case 1:      std::cout << 1;
        } while(--num > 0);
    }
}

int main() 
{
    // breakAt(5, true);
    similarToDuff(14);
    return EXIT_SUCCESS;
}