#include "showinfos.h"

#include <fstream>
#include <iostream>
#include <regex>
#include "../json/value.h"
#include "../json/reader.h"
#include "../json/writer.h"


bool UnrealTools::isUUID(const std::string& str)
{
    const std::regex uuid_regex("[A-Za-z0-9]+-[A-Za-z0-9]+-[A-Za-z0-9]+-[A-Za-z0-9]+-[A-Za-z0-9]");

    std::smatch uuid_match;
    return std::regex_search(str, uuid_match, uuid_regex);
}

int UnrealTools::parseUProject(const std::string& projectPath, project_info& infos)
{
    Json::Value project;
    std::ifstream project_file(projectPath, std::ifstream::binary);

    // Check that file exists
    if (project_file.fail())
    {
        std::cout << "Error: File does not exist at path " << projectPath << '\n';
        return 1;
    }

    // Convert file content to json value.
    project_file >> project;

    // Project name
    for (unsigned i = 0; i < std::size(project["Modules"]); ++i)
    {
        if (project["Modules"][i]["Type"] == "Runtime")
        {
            // std::cout << project["Modules"][i]["Name"] << "\n";
            infos.name = project["Modules"][i]["Name"].asString() ;
            break;
        }
    }

    // Engine Version
    // std::cout << project["EngineAssociation"] << "\n";
    infos.version = project["EngineAssociation"].asString();
    if (isUUID(infos.version))
    {
        infos.fromSource = true;
        // std::cout << "Project from source. \n";
    }

    // Plugins
    // std::cout << "Number of Plugins : " << std::size(project["Plugins"]) << "\n";
    infos.plugins = std::vector<std::string>(std::size(project["Plugins"]));
    for (unsigned i = 0; i < std::size(project["Plugins"]); ++i)
    {
        // std::cout << project["Plugins"][i]["Name"] << "\n";
        infos.plugins[i] = project["Plugins"][i]["Name"].asString();
    }
    
    return 0;
}

void UnrealTools::displayUProject(const project_info& infos)
{
    std::cout << "Project Name : " << infos.name << "\n";
    std::cout << "Engine Version : " << infos.version;
    std::cout << (infos.fromSource ? " -- FROM SOURCE \n" : "\n");
    std::cout << "Plugins : (" << std::size(infos.plugins) << ")\n";
    for (unsigned i = 0; i < std::size(infos.plugins); ++i)
    {
        std::cout << "\t- " << infos.plugins[i] << "\n";
    }
}

int UnrealTools::showInfos(const std::string& projectPath)
{
    std::cout << "Show Project Infos for " << projectPath <<"\n";
    project_info infos;
    const int result = parseUProject(projectPath, infos);
    if (!result)
    {
        displayUProject(infos);
    }
    
    return result;
}
