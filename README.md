# Cpp Playground

It is a sandbox repo where I put all the stuff related cpp (tutorial, experiments and so on...)

## General Setup

Cpp Playground is a container of cpp Cmake projects, open vscode on those folders and not from here.

TODO: try to handle all the codes from here.

For vscode settings add this if it is missing:
.vscode/settings.json

```json
{
    "cmake.generator": "Unix Makefiles",
    "cmake.buildDirectory": "build",
    "cmake.configureOnOpen": true,
    "C_Cpp.default.configurationProvider": "ms-vscode.cmake-tools",
    "clangd.arguments": [
        "--compile-commands-dir=build"
    ]
}
```

For debug in vscode add this

.vscode/launch.json

```json
{
    "version": "0.2.0",
    "configurations": [
        {
            "name": "chain_of_responsibility_test",
            "type": "cppdbg",
            "request": "launch",
            "program": "${workspaceFolder}/./build/chain_of_responsibility_test",
            "cwd": "${workspaceFolder}"
        }
    ]
}
```
