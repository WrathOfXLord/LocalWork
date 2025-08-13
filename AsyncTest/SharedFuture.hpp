#ifndef _SHARED_FUT_HPP_
#define _SHARED_FUT_HPP_

#include <thread>
#include <future>
#include <iostream>
#include <format>
#include <sstream>

// template<> struct std::formatter<std::thread::id> {
//     auto format(const std::thread::id &tId, std::format_context &context) {
//         std::stringstream ss;
//         ss << tId;
//         return std::format_to(context.out(), "{}", ss);
//     }

//     constexpr auto parse(std::format_parse_context& ctx) {
//         return ctx.end();
//     }
// };

namespace SharedFuture {
    // wrong way, race condition
    // void printResult(std::future<int> &fut) {
    //     if(fut.valid()) {
    //         std::cout << "this is a valid future - threadId: " << std::this_thread::get_id() << "\n";
    //         std::cout << "value: " << fut.get() << "\n";
    //     } else {
    //         std::cout << "this is an invalid future - threadId: " << std::this_thread::get_id() << "\n";
    //     }
    // }

    void printResult(std::shared_future<int> &fut) {

        std::hash<std::thread::id> hasher;
        std::cout << std::format("value: {}, threadId: {}\n", fut.get(), hasher(std::this_thread::get_id()));
    }

}

#endif