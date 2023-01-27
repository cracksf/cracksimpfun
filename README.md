# 简介

由于简幻欢的诸多限制，导致我们在上面开服非常的不便。故开发了此插件

本插件只是对于简幻欢的对策性更强，但不仅仅可以运行在简幻欢面板，在修改配置文件后，也同样适用于绝大多数面板！

以下内容数据均来自简幻欢10/11号节点面板，且插件已通过测试。

本插件实现的功能如下：

| 模块                                       | 依赖       |
| ------------------------------------------ | ---------- |
| 【实验性】延长没人就关服的时间             | FakePlayer |
| 单端口端口转发 ，实现反向代理（类似于CDN） | Frp        |
| 强制修改server.properties配置文件          | 内置       |
| 自动配置Frp为反向代理                      | 内置       |
| 执行后台命令                               | 内置       |
| 循环执行游戏指令或命令                     | 内置       |
| 开服前删除/复制文件                        | 内置       |

由于简幻欢平台的固有限制，并不能完全破解自动关服，但是可以延长这个时间。目前由本插件驱动的服务器已正常运行1小时之久(对照 ``如何使用第五步``的例图可知道服务器启动时间)

![image](https://www.minebbs.com/attachments/1673354798073-png.40662/)

然后就被强制关闭了（但是依旧是很大的提高！）

![image](https://www.minebbs.com/attachments/1673354798073-png.40663/)

注意！使用本插件的前提是你必须学会JSON语法，如果你不会，可以去[菜鸟教程](https://www.runoob.com/json/json-tutorial.html)快速学习

为了方便描述，本贴规定根目录为你打开文件管理器的第一个页面

## 如何使用

1.在[Release](https://github.com/cracksf/cracksimpfun/releases/latest)下载 ``csf.dll``，在[网盘](https://wwnr.lanzoum.com/b047la7oj)下载 ``data.7z``和 ``jre.7z``。 网盘密码是 ``csf``

2.将它们上传到 ``plugins``目录下

3.开服，执行 ``csfinit``，插件会自动解压数据文件，请等待控制台输出 ``CrackSimpfun Init!``。就进入下一步。如果你想运行自定义版本的服务器，就进入 ``启动自定义版本服务器``的步骤（往下翻）

![image](https://www.minebbs.com/attachments/1673350456116-png.40654/)

4.按照下面的配置文件板块修改配置文件，之后重启服务器，如果你看到插件加载失败，错误代码1114，则表明你的配置文件写错了

5.如果你开启了假人，看到有五个假人在开服完成后加入服务器，且服务器端口为19132，则代表启动成功

![image](https://www.minebbs.com/attachments/1673350657950-png.40655/)

在控制台执行 ``cmd``之后即可进入cmd命令执行模式，再次输入 ``cmd``即可退出该模式。在该模式下，可以执行cmd命令，为了保证输出结果的可读性，输出的结果将保存到 ``plugins/csf/cmd.txt``

## 启动自定义版本服务器

这只是一个示例，你可以自己修改对应的文件夹和文件名字，来满足自己的需求

进入文件管理器，你需要在 ``plugins``文件夹下创建文件夹，命名为 ``bds``

![image](https://www.minebbs.com/attachments/1673780556028-png.40986/)

然后在 ``plugins/bds``文件夹中上传加载器和BDS，此处使用的是 ``bedrock-server-1.19.51.01.zip``+``LiteLoader-2.9.1.zip``

![image](https://www.minebbs.com/attachments/1673780746552-png.40987/)

1.回到控制台，你现在应该能看到控制台输出的 ``CrackSimpfun Init!``，输入 ``cmd``进入执行cmd命令模式，然后我们要使用LL自带的7za对刚才上传的文件进行解压

2.在控制台输入

```shell
plugins\LiteLoader\7z\7za.exe -y -oplugins\bds x plugins\bds\bedrock-server-1.19.51.01.zip
```

![image](https://www.minebbs.com/attachments/1673780856111-png.40988/)

检查是否完成：前往 ``plugins/csf/cmd.txt``查看输出消息，解压时间较长，记得反复刷新网页，直到出现 ``Everything is Ok``(如下图)

![image](https://www.minebbs.com/attachments/1673606247198-png.40884/)

这样，bds就算是解压完成了

3.在控制台输入

```shell
plugins\LiteLoader\7z\7za.exe -y -oplugins\bds x plugins\bds\LiteLoader-2.9.1.zip
```

![image](https://www.minebbs.com/attachments/1673780969309-png.40989/)

重复第二步的 ``检查是否完成``

这样，LiteLoader也完成了解压

4.运行LLPeEditor.exe，在控制台输入 ``cmd.exe``

然后输入 ``cd plugins\bds\``

再输入 ``LLPeEditor.exe``

这时控制台将会被清空，不要慌张，这是正常现象。

重复第二步的 ``检查是否完成``，如果出现了 ``Press any key to continue . . .``(如下图)，表明这一步也完成了。

![image](https://www.minebbs.com/attachments/1673606725864-png.40885/)

在控制台输入 ``q``，退出LLPeEditor。然后输入 ``exit``，退出cmd.exe。再输入 ``cmd``，退出cmd命令执行模式，再输入 ``stop``关闭服务器。

![image](https://www.minebbs.com/attachments/1673781260582-png.40990/)

5.修改我们的server.properties文件，将其中的端口改为简幻欢提供的，且IPv6端口也要相应的修改，如下图

![image](https://www.minebbs.com/attachments/1673611377622-png.40888/)

6.切换配置文件，将 ``plugins/csf/config.json``删除，并且将 ``plugins/csf/config.run_new_bds.json``重命名为 ``plugins/csf/config.json``，然后启动服务器

![image](https://www.minebbs.com/attachments/1673781478227-png.40992/)

7.不出意外的话，控制台会输出以下内容，代表运行成功。以后你开服都将使用 ``plugins/bds``作为bds的文件夹，而且可以访问所有文件

![image](https://www.minebbs.com/attachments/1673783221235-png.40995/)

## 配置文件

| 描述         | 目录                          |
| ------------ | ----------------------------- |
| CrackSimpfun | plugins/csf/config.json       |
| Frpc         | plugins/csf/csfc.ini          |
| Frps         | plugins/csf/csfs.ini          |
| FakePlayer   | plugins/fp/config/config.yaml |

CrackSimpfun的主配置文件，如果你不需要Frp或假人服务，将 ``exec_background_cmd``中的对应项目删除即可，不希望修改端口可以删除 ``server_properties``中的对应项目

### 默认配置文件

```json
{
    "delete_files": [ //删除文件
        "plugins\\csf\\csfs.log", //删除Frps日志，目录要加反斜杠
        "plugins\\csf\\csfc.log" //删除Frpc日志，目录要加反斜杠
    ],
    "copy_files": { //复制文件
        "plugins\\csf\\csf.dll": "plugins\\plugin.dll" //复制文件，目录要加反斜杠
    },
    "server_properties": [ //修改server.properties配置文件
        {
            "server-port": "19132" //防止占用唯一的公网端口
        },
        {
            "player-idle-timeout": "0" //防止假人被踢
        },
        {
            "online-mode": "false" //允许假人加入
        }
    ],
    "check_running": [ //检查正在运行的程序进程，如果超过规定数量，插件就不加载
        {
            "1": "bedrock_server.exe"
        },
        {
            "1": "bedrock_server_mod.exe"
        }
    ],
    "exec_cmd": [], //执行前台命令，语法与执行后台命令的一致
    "exec_background_cmd": [ //执行后台命令
        {
            "0": "cmd.exe /c plugins\\fp\\bin\\FakePlayer.bat" //启动假人
        },
        {
            "0": "plugins\\csf\\csfs.exe -c plugins\\csf\\csfs.ini" //启动Frps
        },
        {
            "5000": "plugins\\csf\\csfc.exe -c plugins\\csf\\csfc.ini" //延迟5000毫秒(5秒)启动Frpc
        }
    ],
    "modify_configs": true, //是否自动配置Frp端口及FakePlayer配置
    "run_loop_interval": 180, //循环间隔，此处为180秒
    "run_loop": [
        {
            "system": "cmd.exe /c echo Running AutoCompaction..." //前台命令
        },
        {
            "console": "list" //游戏命令list
        }
    ]
}
```

如果你是正常开服但是想延长关服时间的服主，可以将 ``plugins/csf/config.json``删除，并且将 ``plugins/csf/config.keep_alive.json``重命名为 ``plugins/csf/config.json``，这样只会启动假人模块。

## 面板主机信息一览（已优化可读性）

由下图可知，简幻欢提供的平台并不是Wine，而是使用Win Server 2019加Docker容器。这允许我们进行更多操作，包括运行大型程序(如Java)，以及运行各种能够在命令行运行的软件。甚至是启动虚拟机

![image](https://www.minebbs.com/attachments/1673353887112-png.40659/)

## 简幻欢限制面板使用的手段

1.使用链接文件夹和文件对部分文件进行隔离，防止用户对服务端等核心文件进行修改，仅对用户暴露部分文件夹。根据对其目录的探索，可以得知面板暴露给用户的目录为 ``C:\container\``，而BDS服务端位于 ``C:\bds\``。在服务器目录使用 ``dir``命令产生的输出，其中标为 ``JUNCTION``和 ``SYMLINK``的部分为已链接的目录或文件

```text
Volume in drive C has no label.
 Volume Serial Number is AE10-7026

 Directory of C:\bds

01/10/2023  07:34 PM    <DIR>          .
01/10/2023  07:34 PM    <DIR>          ..
01/10/2023  07:34 PM    <SYMLINK>      allowlist.json [C:/container/allowlist.json]
11/16/2022  07:39 AM        41,913,296 bedrock_server.exe
11/16/2022  07:37 AM       207,917,056 bedrock_server.pdb
11/16/2022  06:50 AM            25,018 bedrock_server_how_to.html
12/10/2022  08:20 PM        44,243,200 bedrock_server_mod.exe
12/11/2022  12:23 PM    <DIR>          behavior_packs
01/10/2023  07:34 PM    <JUNCTION>     config [C:\container\config]
12/11/2022  12:23 PM    <DIR>          definitions
12/10/2022  08:20 PM    <DIR>          development_behavior_packs
12/10/2022  08:20 PM    <DIR>          development_resource_packs
12/10/2022  08:20 PM    <DIR>          development_skin_packs
12/11/2022  12:22 PM    <DIR>          lib
12/10/2022  10:43 AM        10,187,264 LiteLoader.dll
12/10/2022  11:05 AM           597,504 LLPeEditor.exe
12/10/2022  10:36 AM           347,648 LLPreLoader.dll
01/10/2023  07:34 PM    <JUNCTION>     logs [C:\container\logs]
01/10/2023  07:34 PM    <SYMLINK>      permissions.json [C:/container/permissions.json]
01/10/2023  07:34 PM    <JUNCTION>     plugins [C:\container\plugins]
11/16/2022  06:50 AM               592 release-notes.txt
12/11/2022  12:22 PM    <DIR>          resource_packs
01/10/2023  07:34 PM    <SYMLINK>      server.properties [C:/container/server.properties]
01/10/2023  07:35 PM             4,973 valid_known_packs.json
01/10/2023  07:34 PM    <JUNCTION>     worlds [C:\container\worlds]
12/10/2022  08:20 PM    <DIR>          world_templates
              12 File(s)    305,236,551 bytes
              14 Dir(s)  21,096,980,480 bytes free
```

打开文件管理器的第一页面：

![image](https://www.minebbs.com/attachments/1673352324173-png.40656/)

2.禁止修改启动参数（面板服务商常用）

3.在容器启动时强制替换文件，包括server.properties，Simpfun.dll等文件，防止用户修改服务器端口或删除用于上报服务器状态的插件

4.在服务器没人的时候自动关服，这是最麻烦的一点。没人进入服务器的情况下：在白天，一般开服不到十分钟就会自动关服。晚上，半小时之内也会关服。经过分析，简幻欢使用的关服方法为直接强制结束进程，存在潜在的数据丢失风险，这种对用户数据不重视的态度是应当被谴责的。在DllMain中使用 ``ul_reason_for_call``进行关服检测，正常输入stop关服，插件会立刻输出消息，不过由于在服务器运行过程中会多次触发 ``DLL_PROCESS_DETACH``事件，所以将服务器端口改回简幻欢提供的默认端口，然后在本地使用motd工具，每秒发包一次，进行存活性探测。如果motd发生超时的时候插件刚好输出了消息，则说明服务器是正常关闭的，反之则是非正常关闭。利用该方法以增强结论可信度

```cpp
BOOL APIENTRY DllMain(HMODULE hModule, DWORD ul_reason_for_call, LPVOID lpReserved) {
    switch (ul_reason_for_call) {
    case DLL_PROCESS_ATTACH:
    case DLL_THREAD_ATTACH:
    case DLL_THREAD_DETACH:
    case DLL_PROCESS_DETACH:
        std:: cout << "DLL_PROCESS_DETACH event has been triggered!" << std::endl;
        break;
    }
    return TRUE;
}
```

## 关于 ``Simpfun.dll``

由于作者精力不多，不想深挖该插件的功能，故使用假人进行延长开服时间（BDS内置的simulatedPlayer应该也能达到目的）

复制文件处的示例本来是要替换简幻欢自带的Simpfun.dll插件，使其无法工作的，但是后来经过检查，发现该插件使用了WS2_32.dll（如下图），故判断该插件是用于检测服务器状态，并与面板通信，达到根据在线状态关闭服务器的功能。

![image](https://www.minebbs.com/attachments/1673336925495-png.40637/)

检索并整理了该插件中使用的ANSI字符串，发现其调用了两个BDS的API：

```text
偏移        大小   类型      字符串
00006954    3f     A       ?_Unlock@?$basic_streambuf@DU?$char_traits@D@std@@@std@@UEAAXXZ
00009e44    45     A       ?xsputn@?$basic_streambuf@DU?$char_traits@D@std@@@std@@MEAA_JPEBD_J@Z
00042920    42     A       ?showmanyc@?$basic_streambuf@DU?$char_traits@D@std@@@std@@MEAA_JXZ
003f0bc8    4a     A       ?imbue@?$basic_streambuf@DU?$char_traits@D@std@@@std@@MEAAXAEBVlocale@2@@Z
004033fe    42     A       ?pbackfail@?$basic_streambuf@DU?$char_traits@D@std@@@std@@MEAAHH@Z
0040a216    5c     A       ?seekpos@?$basic_streambuf@DU?$char_traits@D@std@@@std@@MEAA?AV?$fpos@U_Mbstatet@@@2@V32@H@Z
00412034    3d     A       ?uflow@?$basic_streambuf@DU?$char_traits@D@std@@@std@@MEAAHXZ
00417550    5b     A       ?seekoff@?$basic_streambuf@DU?$char_traits@D@std@@@std@@MEAA?AV?$fpos@U_Mbstatet@@@2@_JHH@Z
0042c03c    3c     A       ?sync@?$basic_streambuf@DU?$char_traits@D@std@@@std@@MEAAHXZ
00450ae8    41     A       ?underflow@?$basic_streambuf@DU?$char_traits@D@std@@@std@@MEAAHXZ
00479bf2    45     A       ?xsgetn@?$basic_streambuf@DU?$char_traits@D@std@@@std@@MEAA_JPEAD_J@Z
0047a81a    3d     A       ?_Lock@?$basic_streambuf@DU?$char_traits@D@std@@@std@@UEAAXXZ
004922f8    4a     A       ?setbuf@?$basic_streambuf@DU?$char_traits@D@std@@@std@@MEAAPEAV12@PEAD_J@Z
004c98e0    39     A       ??1?$basic_streambuf@DU?$char_traits@D@std@@@std@@UEAA@XZ
004a75ec    53     A       ?_copy@@YA?AV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@AEBV12@@Z
0009d34a    26     A       ?set_new_handler@std@@YAP6AXXZP6AXXZ@Z

# 疑似定时任务
0040595e    54     A       ?nextTick@Schedule@@YA?AVScheduleTask@@V?$function@$$A6AXXZ@std@@PEAUHINSTANCE__@@@Z

# BDS函数
# 检查配置文件：是否使用Xbox验证
000683be    35     A       ?useOnlineAuthentication@PropertiesSettings@@QEBA_NXZ
# BDS 1.19.51.01 中的符号:  ?useOnlineAuthentication@PropertiesSettings@@QEBA_NXZ
# 遍历每一个玩家
0040e024    44     A       ?forEachPlayer@Level@@QEAAXV?$function@$$A6A_NAEAVPlayer@@@Z@std@@@Z
# BDS 1.19.51.01 中的符号:  ?forEachPlayer@Level@@UEBAXV?$function@$$A6A_NAEBVPlayer@@@Z@std@@@Z
```

如果仔细观察，可以发现插件中使用的遍历玩家的符号与当前最新版本BDS(1.19.51.01)之中的不符，而经过查询时间戳可以知道该插件的生成日期。经查维基百科，可以知道该插件是在1.19.50.02和1.19.51.01发布期间编译的

![image](https://www.minebbs.com/attachments/1673339410766-png.40641/)

猜测：也许该插件并没有正常检测玩家数量

## ~~插件为什么不开源~~

~~由于本插件的特殊性，永远都不会全部开源。但是本插件的安全性是可以保证的，由于会操作某些文件并且使用了 ``system()``进行cmd命令执行，某些杀毒软件可能会产生误报。如果不放心，各位可以使用各大工具对本插件进行反汇编和动态调试。~~

~~点击查看本插件的VirusTotal页面（更新可能不及时，欢迎自行上传）~~

## 免责声明

本插件仅供学习交流使用，下载后请在24小时内删除！由使用本插件产生的危害和问题，作者概不负责！
