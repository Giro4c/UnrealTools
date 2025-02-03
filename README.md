# Unreal Tools
_Current version : 1.0_

A executable tool to be placed at the root of an Unreal Engine from source.  
Currently works only with command lines and only supports default values for platform, optimizations and target.  
Will try to make a GUI in 2.0.

## Tools  

### Show Project infos

How to use :  
```
UnrealTools_Build UPROJECT_PATH show-infos
```
This command displays the project infos contained within an uproject file. 
This includes the project's name, the plugin used and the engine version used 
along with a "FROM SOURCE" marker if that's the case.  

### Build Project  

How to use :  
```
UnrealTools_Build UPROJECT_PATH build
```
This command builds the given project using Unreal Build Tool (UBT).  
Currently does not support custom parameters. Their default values are as follow :  

| Parameter           | Supported Value     |
| ------------------- | ---------------     |
| Target              | Editor              |
| Platform            | Win64 (Windows x64) |
| Optimization        | Development         |



### Package Project

How to use :  
```
UnrealTools_Build UPROJECT_PATH package PACKAGE_PATH
```
This command packages the given project into the target folder given.
Currently does not support custom parameters. Their default values are as follow :  

| Parameter           | Supported Value     |
| ------------------- | ---------------     |
| Platform            | Win64 (Windows x64) |
| Optimization        | Development         |