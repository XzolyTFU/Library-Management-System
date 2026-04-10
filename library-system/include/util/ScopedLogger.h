#ifndef SCOPEDLOGGER_H
#define SCOPEDLOGGER_H

#include <string>
#include <iostream>
#include <chrono>

class ScopedLogger {
    std::string op;
    std::chrono::steady_clock::time_point start;

public:
    ScopedLogger(std::string op)
        : op(op), start(std::chrono::steady_clock::now()) {
        std::cout << "Starting: " << op << std::endl;
    }

    ~ScopedLogger() {
        auto end = std::chrono::steady_clock::now();
        auto ms = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
        std::cout << "Finished: " << op << " in " << ms.count() << " ms" << std::endl;
    }
};

#endif
