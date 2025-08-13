#include <iostream>
#include "Runner.hpp"


int main() {
    
    Promise::run(false);
    PackagedTask::run(false);
    PromiseExcept::run(false);
    
    SharedFuture::run(true);

    return 0;
}