# Factorio TAS Generator
This is a tool for generating **T**ool **A**ssisted **S**peedruns in Factorio. 

Showcases: 
* Steelaxe%:
  1) [8:04 by EZRaiderz](https://www.youtube.com/watch?v=wbD-xbTWzFk&ab_channel=EZRaiderz)
  2) [7:46 by Theis](https://www.youtube.com/watch?v=4zAw3siu-n8&t=365s&ab_channel=Zaspar)
  3) [7:35 by Theis](https://youtu.be/CHAKin8ipbk?si=JLagreI1bqgo0RvJ)
  4) [7:25 by Ameateye](https://www.youtube.com/watch?v=0F0fLkFbhn4)
  5) [7:23 by EZRaiderz](https://www.youtube.com/watch?v=sqAe57LfNJA&t=3s)
* GOTLAP: [17:00 by EZRaiderz](https://www.youtube.com/watch?v=geEoRQ2JEbM&ab_channel=EZRaiderz)
* Any%: [Zaspar_](https://www.youtube.com/watch?v=1r-i5b153uw&t=1482s&ab_channel=Zaspar).  You can follow his progress on [twitch](https://www.twitch.tv/zaspar_). 
* Default settings: [Omn1](https://www.youtube.com/watch?v=BQzqgQn2lH8). You can follow his progress on [twitch](https://www.twitch.tv/0mn1_io). 

### Tooling
The [latest release](https://github.com/theis999/TAS-Helper-for-Factorio/releases) can stand on its own, but these tools are recommended:

* [Game speed controls](https://mods.factorio.com/mod/game-speed) — To help zoom in on the important actions
* [TAS step planner](https://mods.factorio.com/mod/TAS_step_planner) — To help with building a plan from inside factorio
* [TAS Precision helper](https://mods.factorio.com/mod/Theis_tas_helper) — Provides precision control data and also shows list of TAS steps
* [TAS state printer](https://mods.factorio.com/mod/TAS_state_printer) — To help with run desyncs, when you have changed something in the past and it has cascading effect

*If you find another tool, do let us know*.

### Features and problems
**Bugs** can be reported through [Issues](https://github.com/theis999/TAS-Helper-for-Factorio/issues), and **new features** can be requested there too.

## How it works
This tools works by converting a list of steps into a Factorio mod. The mod will then force the character to execute each step until it reaches the goal.
The list of steps is saved in a csv-like text file, and is displayed in a grid table through the tool.

Steps are executed using [Factorio's Lua API](https://lua-api.factorio.com/latest/), so while we strive to simulate realistic inputs, there are still differences.
A few of the more noteworthy differences:
* The TAS doesn't need the cursor, however it is still bound by character reach distance.
* Huge rocks always yield 47 coal and 47 stone. Instead of the random yields in regular play, which can create some hard to deal with incosistencies.
* Construction robots are not available.

## Developer setup
Do you want to help?
To get started on **Windows** you need [MS Visual studio](https://visualstudio.microsoft.com/downloads/) and [MSYS2](https://www.msys2.org/).
On other platforms you may have discover the process yourself.

#### Visual Studio
0) Download and install [MS Visual studio](https://visualstudio.microsoft.com/downloads/)
1) Through the visual studio installer you need to install `desktop development with c++`
2) Through the visual studio installer you need to install _language pack_ `English`

#### WxWidget
0) Download and install [MSYS2](https://www.msys2.org/)
1) Run MSYS2 and enter the following commands:
```
pacman -Syu
pacman -S ${MINGW_PACKAGE_PREFIX}-toolchain ${MINGW_PACKAGE_PREFIX}-cmake ${MINGW_PACKAGE_PREFIX}-make base-devel git
pacman -S ${MINGW_PACKAGE_PREFIX}-wxWidgets3.2 ${MINGW_PACKAGE_PREFIX}-boost
```
2) [Optinal] to get wxFormBuilder, run the following commands:
```
git clone --recursive https://github.com/wxFormBuilder/wxFormBuilder
cd wxFormBuilder
cmake -S . -B _build -G "MSYS Makefiles" --install-prefix "$PWD/_install" -DCMAKE_BUILD_TYPE=Release
cmake --build _build --config Release -j `nproc`
cmake --install _build --config Release
```
3) Run **msys2-mingw64** and enter the following commands:
```
git clone https://github.com/Microsoft/vcpkg.git
cd vcpkg
./bootstrap-vcpkg.bat
./vcpkg integrate install
./vcpkg install wxwidgets
./vcpkg install wxwidgets:x64-windows
```

#### Finish up
After installing wxwidget, clone the FTG repository by:
1) Open visual studio
2) Open the file menu
3) Click the Clone repository (3rd from the top)
4) In the url field, enter: `https://github.com/theis999/TAS-Helper-for-Factorio`

To open **GUI builder**:
1) Open **MSYS2**
2) Enter `./wxFormBuilder/_install/wxFormBuilder`

#### To change the **Lua code** 
It is recommended to download [Visual studio code](https://visualstudio.microsoft.com/downloads/)  
and add the extension [Factorio Modding Tool Kit](https://github.com/justarandomgeek/vscode-factoriomod-debug)
