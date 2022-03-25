#ifndef _APP_HPP_
#define _APP_HPP_

#include "Window.hpp"

namespace Custom
{
    class App
    {
    private:
        Window window{W, H, "Test Window"};

    public:
        static constexpr int W{800}, H{600};
        void run();
    };
}

#endif