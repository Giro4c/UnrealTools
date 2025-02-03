#include "cmd_executer.h"

#include <cstdio>
#include <memory>
#include <stdexcept>
#include <string>
#include <array>

std::string UnrealTools::Cmd::Execute(const char* cmd)
{
    std::array<char, 128> buffer;
    std::string result;
    // std::unique_ptr<FILE, decltype(&pclose)> pipe(popen(cmd, "r"), pclose);
    std::unique_ptr<FILE, decltype(&_pclose)> pipe(_popen(cmd, "r"), _pclose);
    if (!pipe) {
        throw std::runtime_error("popen() failed!");
    }
    while (fgets(buffer.data(), static_cast<int>(buffer.size()), pipe.get()) != nullptr) {
        result += buffer.data();
    }
    return result;
}

