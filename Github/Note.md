# Issues


---
# Pull Request
- [参考链接](https://www.zhihu.com/question/21682976)
- 以下为文章原文:
- 我尝试用类比的方法来解释一下 pull reqeust。想想我们中学考试，老师改卷的场景吧。
  - 你做的试卷就像仓库，你的试卷肯定会有很多错误，就相当于程序里的 bug。
  - 老师把你的试卷拿过来，相当于先 fork。
    - 在你的卷子上做一些修改批注，相当于 git commit。
    - 最后把改好的试卷给你，相当于发 pull request，
  - 你拿到试卷重新改正错误，相当于 merge。

---
# Actions
- [参考链接](http://www.ruanyifeng.com/blog/2019/09/getting-started-with-github-actions.html)


# Markdown
## 数学公式
- [参考链接]
- [访问改地址](https://github.com/orsharir/github-mathjax/releases/tag/v0.2.1)
  - 下载`Source code(zip)`
  - 解压到`C:/Users/"你的用户名"/AppDataLocal/Google/Chrome/User Data/Default/Extensions
    - 注意解压后的文件夹表层和里一层都是一样的文件夹名
      - 只要里层的
  - 打开Chrome扩展程序,打开开发者模式
  - 加载已解压的扩展程序
    - 就是刚才放到上面目录里的整个文件夹
    - ![结构示意图](../res/img/Github/Chrome插件github-mathjax文件结构示意图.png)
  - 此时再打开Github查看源码就能显示markdown的数学公式了
  - ![成功演示](../res/img/Github/Github查看Markdown数学公式成功演示.png)

# webhooks
## 借助钉钉的Github机器人将仓库变动通知到钉钉群里
- [参考链接](https://blog.csdn.net/q563573095/article/details/79580249)
- 进入钉钉群聊
  - 侧边栏第一个图标`群设置`
  - 智能群助手
  - 添加机器人
  - 更多`...`
  - **Github**机器人
  - 添加
  - 复制Webhook链接
- 打开Github仓库
  - Settings
  - 左侧边栏`Webhooks`
  - `Add webhook`
  - `Payload URL`填刚才从钉钉Github机器人那里复制来的webhook链接
  - 其余选项自行发挥
    - 记得勾选Active
  - `Add webhook`
- push一次提交
  - 这时候就会有钉~的提醒啦