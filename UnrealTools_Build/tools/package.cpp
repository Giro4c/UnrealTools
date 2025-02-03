#include "package.h"

#include <iostream>

#include "cmd_executer.h"

int UnrealTools::package(std::string projectPath, std::string packagePath)
{
    std::cout << "Package project\n";

    const std::string cmd = Cmd::MakeCmdPackage(projectPath, packagePath, "Development", "Win64");
    std::cout << cmd << "\n";
    const std::string result = Cmd::Execute(cmd.c_str());
    std::cout << result << "\n";

    return 0;
}
