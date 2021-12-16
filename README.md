# videoWallPaper
vs code+Mingw(g++)编译的cpp版动态壁纸

程序和讲解参照https://github.com/3150601355/VideoWallPaperDemo.git项目说明，在up提供的哔站视频里有详细讲解。

使用宏定义解决可能会出现的类型转换问题。其他内容和源程序保持一致

##### 本程序编译环境：

VSCode

Mingw_x64_8.1.0版本（g++ 8.1.0）

##### 编译命令

`> g++ videoWallPaper.cpp -o videoWallPaper -fpermissive; .\videoWallPaper`

-fpermissive参数避免EnumWindowsProc出现类型问题
