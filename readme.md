# 百手输皮肤系列 & BGtool

2013-2016 期间的项目，目前停更中。  
包括输入法皮肤系列和一个生成皮肤配置文件的C程序 BGtool。

皮肤直接放上 bds 文件，它实际上就是源代码的 zip。  
BGtool 以当时的仓库原样放出，最新的版本和 v1.2 一致。

## 皮肤系列说明

![](https://disk.vvnote.org/github/baidu_input_skins/2.png)

1. 暑瓦：初始皮肤，默认隐藏顶栏，打字时弹出
2. 黑瓷：全新的键盘布局和交互逻辑，包含了一个编辑操作顶栏
3. 白瓷：黑瓷的样式改进，并且功能上更加成熟
4. 白瓮：白瓷普通界面顶栏和 morebar 顶栏调换后的版本
5. 白铁：基于白瓷，增加一个侧边栏，系列的最成熟版本

在主题之下，还有一些针对输入方案的小版本：

1. 暑瓦：假双拼 / 五韵
2. 黑瓷：传统（商店版） / 乱17（左右删除键版本） / 五韵（含五韵17和独孤14） / 简易双拼
3. 白瓷：传统（商店版） / 双键 / 五韵
4. 白瓮：双键
5. 白铁：双键 / 乱17 / 独孤14 / 雅歌1417 / 五韵

从黑瓷到白铁都属于瓷系列，统一版本号，具体操作详见[这里](https://gearkey.vvnote.org/index.php/post-18.html)，关于[五韵](https://gearkey.vvnote.org/index.php/post-21.html)。

## BGtool 说明

![](https://disk.vvnote.org/github/baidu_input_skins/1.png)

这是一款百手输皮肤制作工具，可以：

+ 生成 xml，结合软件 Simple Text 进行文字图片素材制作
+ 根据输入，生成连续的切片和样式配置文件
+ 使用操作符组成的表达式，快速生成皮肤布局文件，并且在一定程度上是可视化的

具体操作详见[这里](https://gearkey.vvnote.org/index.php/post-17.html)。
