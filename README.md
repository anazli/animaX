# AnimaX
Animation Renderer side project.
under construction...

Building
--------
Linux:
---
1. change to the project's root folder.
2. copy the appropriate conan profile to the .conan/profiles folder.
3. execute the following commands and choose the build type between release and debug. 
```bash
$ conan install . -pr:b x86_64-linux-gcc11 -pr:h x86_64-linux-gcc11 -s build_type=<Release|Debug>
$ cmake --build build/<Release|Debug>
```
4. the executable should be in build/<Release|Debug>/bin folder.
5. run the executable on terminal.

Windows:
---
1. change to the project's root folder.
2. copy the appropriate conan profile to the .conan/profiles folder.
3. execute the following command and choose the build type between release and debug. 
```powershell
> conan install . -pr:b x86_64-windows-vs2022 -pr:h x86_64-windows-vs2022 -s build_type=<Release|Debug>
```
4. the VS2022 solution should be in build/<Release|Debug> folder.
5. open it with VS2022 and build the project.
6. in solution explorer do a right click on Animation and set it as a startup project.
7. run the Local Windows Debugger.
