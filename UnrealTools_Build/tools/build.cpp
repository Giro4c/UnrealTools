#include "build.h"

#include <iostream>
#include <iostream>
#include "cmd_executer.h"
#include "showinfos.h"

int UnrealTools::build(std::string projectPath)
{
    std::cout << "Build project\n";

    project_info infos;
    UnrealTools::parseUProject(projectPath, infos);
    const std::string cmd = UnrealTools::Cmd::MakeCmdBuild(projectPath, infos.name, "Editor", "Win64", "Development");
    std::cout << cmd << std::endl;
    std::string result = UnrealTools::Cmd::Execute(cmd.c_str());
    std::cout << result << std::endl;
    
    return 0;
}
