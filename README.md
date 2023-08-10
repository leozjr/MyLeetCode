# 在VScode中使用C++刷LeetCode

由于MinGW64不支持中文文件，而MSVC编译器 cl.exe 支持，并且vscode支持的很好，因此本项目使用MSVC编译，详细使用方式请参照[这里](https://blog.futrime.com/zh-cn/p/visual-studio-code%E9%85%8D%E7%BD%AEmsvc%E7%BC%96%E8%AF%91%E7%8E%AF%E5%A2%83/)。

优点：

- 使用VScode插件 LeetCode 可以直接在内部获取题目和代码模板
- 可以在 `// @lc code=start // @lc code=end` 代码块之外书写自己的本地调试信息，不影响提交
- 再次打开还是上次编辑过的文件，可以方便自己记录更多的东西