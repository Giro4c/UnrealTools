#pragma once
#include <string>

namespace UnrealTools
{
    namespace Cmd
    {
        
        std::string Execute(const char* cmd);

        std::string MakeCmdBuild(std::string projectPath, std::string projectName, std::string target, std::string platform, std::string optimization);

        std::string MakeCmdPackage(std::string projectPath, std::string packagePath, std::string optimization, std::string platform);
        
    }
}
