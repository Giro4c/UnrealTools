#pragma once
#include <string>
#include <vector>

namespace UnrealTools
{
    struct project_info
    {
        std::string name;
        std::string version;
        bool fromSource;
        std::vector<std::string> plugins;
    };

    bool isUUID(const std::string& str);
    
    int parseUProject(const std::string& projectPath, project_info& infos);

    void displayUProject(const project_info& infos);
    
    int showInfos(const std::string& projectPath);
    
}
