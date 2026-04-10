#include "util/ScopedLogger.h"
#include <iostream>
#include <utility>

ScopedLogger::ScopedLogger()
    : operation(""), start(std::chrono::steady_clock::now()) {}

ScopedLogger::ScopedLogger(std::string op)
    : operation(std::move(op)), start(std::chrono::steady_clock::now()) {
    std::cout << "Starting: " << operation << "\n";
}

ScopedLogger::~ScopedLogger() {
    auto end = std::chrono::steady_clock::now();
    auto ms = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();
    if (operation != "") {
        std::cout << "Finished: " << operation << " in " << ms << " ms\n";
    }
}
