#pragma once
#include <string>
#include <vector>

namespace UnrealTools
{
    struct project_info
    {
        std::string name;
        std::string version;
        std::vector<std::string> plugins;
    };

    int parseUProject(const std::string& projectPath, project_info& infos);

    void displayUProject(const project_info& infos);
    
    int showInfos(const std::string& projectPath);
    
}
