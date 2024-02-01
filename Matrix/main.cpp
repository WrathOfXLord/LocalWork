#include <iostream>

#include "Matrix.hpp"
#include "../BLUEPRINTS/timer_blueprint/TimeCounter.hpp"

int main()
{
    TimeCounter t {};

    t.restart_timer();
    Matrix<int, 4, 4> mat {{
        {3,   2,   5,  6},
        {6,   163, 7,  3},
        {1,   6,   4,  464},
        {894, 466, 4,  164}
    }};
    t.timedelta();
    mat.setOStreamWidth(8);
    std::cout << mat << "\n\n";

    t.restart_timer();

    Matrix<int, 4, 4> mat2 {
        3,   2,   5,  6,
        6,   163, 7,  3,
        1,   6,   4,  464,
        894, 466, 4,  164
    };
    t.timedelta();
    mat2.setOStreamWidth(8);
    std::cout << mat2 << "\n";
    t.restart_timer();
    auto mat3 = makeMatrix<int, 4, 4>(
        3,   2,   5,  6,
        6,   163, 7,  3,
        1,   6,   4,  464,
        894, 466, 4,  164
    );

    t.timedelta();
    mat3.setOStreamWidth(8);
    std::cout << mat3 << "\n";


   
    return 0;
}