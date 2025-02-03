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

std::string UnrealTools::Cmd::MakeCmdBuild(std::string projectPath, std::string projectName, std::string target,
    std::string platform, std::string optimization)
{
    std::string cmd = "./Engine/Build/BatchFiles/Build.bat ";
    cmd += projectName;
    cmd += " ";
    cmd += projectName + target;
    cmd += " ";
    cmd += platform;
    cmd += " ";
    cmd += optimization;
    cmd += " ";
    cmd += projectPath;
    cmd += " -waimutex";

    return cmd;
}

std::string UnrealTools::Cmd::MakeCmdPackage(std::string projectPath, std::string packagePath, std::string optimization, std::string platform)
{
    std::string cmd = "./Engine/Build/BatchFiles/RunUAT.bat BuildCookRun -project=";
    cmd += projectPath;
    cmd += " -noP4 -clientconfig=";
    cmd += optimization;
    cmd += " -serverconfig=";
    cmd += optimization;
    cmd += " -nocompileeditor -utf8output -platform=";
    cmd += platform;
    cmd += " -build -cook -CookCultures=fr -unversionedcookedcontent -stage -package -stagingdirectory=";
    cmd += packagePath;
    cmd += " -cmdline=\" -Messaging\"";

    return cmd;
}
