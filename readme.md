# Code in 《 Essential C++ 》

`原创` `kevin_up`

1. 当前阶段所有的代码都理解完之后才`git commmit`, 改好的代码及时`git add` 
2. 代码注释规范化：
    - 注释代码时，`//`这种注释的为调试过程中的代码，`/** 说明 **/`这种注释为代码说明
3. `commit`的时候的描述为版本号，对应版本号的说明写在`readme`中

## Version 1.X.X

- 4.1 如何实现一个Class
- 4.2 什么是构造函数和析构函数
- 4.3 何谓mutable（可变）和const（不变）
- 4.4 什么是this指针
- 4.5 静态类成员
- 4.6 打造一个Iterator Class
- 4.7 合作的关系必须建立在友谊的基础上
- 4.8 实现一个 copy assignment operator
- 4.10重载iostram运算符

## Version 2.X.X

- 5.1 面向对象编程概念
- 5.2 漫游：面向对象编程思维
- 4.11 指针，指向Class Member Function
- 5.3 不带继承的多态

Version 2.2.1

- 5.4 定义一个抽象基类
- 5.5 定义一个派生类

Version 2.3.X

- 5.6 运用继承体系
- 5.7 基类应该多么抽象
- 5.8 初始化、析构、复制
- 5.9 在派生类中定义一个虚函数

## Version 3.X.X

- 6.1 被参数化的模型
- 6.2 Class Template 的定义
- 6.3 Template 类型参数的处理
- 6.4 实现一个Class Template 
- 6.5 一个以Function Template 完成的Output运算符
- 6.7 以Template参数作为一种设计策略

### Version 3.2.0
- 简化了Makefile，能够自动将新添加进`src`文件夹下的cpp文件进行编译，而无需每次对Makefile文件进行修改