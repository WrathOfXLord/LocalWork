#pragma once

#if defined(_WIN32)

#elif defined(__linux__)
    #error "This feature has not been implemented on Linux yet!"
#elif defined(__APPLE__)
    #error "This feature has not been implemented on MacOS yet!"
#else
    #error "Unsupported Operating System!"
#endif