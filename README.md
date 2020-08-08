# LeetCode

分享一下我在 LeetCode 的提交记录，以及一个简单实用的 LeetCode 提交记录下载器

## 提交记录

见 `submissions/` 文件夹，文件名格式为 `${Question ID}-${Title}-${Submission ID}.${Ext}`

同一题可能有多份提交记录，它们可能代表着一道题的多种解法，或者是一种解法的不同改进版。提交记录 ID 越大，提交的时间越靠后

## 提交记录下载器

前述的所有提交纪录均由这个工具自动下载。这个下载器支持以 GitHub 账号登录 LeetCode 中文站，下载 C++ 的 Accepted 提交记录，具有简单的增量下载功能。整体设计非常简单，在此就不详述，你可以自行参考源码

### 安装

确保有 Python 3 运行环境
```console
$ python3 --version
Python 3.6.8
```

下载这个 repo 到本地
```console
$ git clone https://github.com/zhongxinghong/LeetCode.git
$ cd LeetCode/
```

安装依赖包
```console
$ pip3 install Js2Py lxml requests
```

清空我的 `submissions/` 文件夹
```console
$ rm -rf submissions/
```

配置 `config.ini` 文件
```console
$ cp config.sample.ini config.ini
$ vim config.ini
```

运行 `main.py` 开始自动下载
```console
$ python3 main.py
```

