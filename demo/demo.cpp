#语法比较简单的一门语言，和C语言有很多类似的地方。

#字符串
s = "Peace and love"  #没有分号呦~
//char s[] = "Peace and love";
//string s = "Peace and love";

s = "Peace " "and " "love"

s1 = "Peace "
s2 = "and "
s3 = "love"
s = s1 s2 s3 

#变量
    #所有awk里面的数字都以双精度浮点值表示
        #awk的世界里只有字符串和数字，随意进行初始化，并且不需要指定是数值还是字符串。当使用变量时，在内容中期待的是字符串还是数字就已经很清楚了
        #并且其值也可以在需要的时候自动转换。~方便，省事，简单
        #初始值：可以理解为一个空的字符串，但是当需要它是数值时，会被视为零。
    #运算符使用方式和c++一样
    #内建变量名：
        。。。。FS
    #数组变量---关联数组
        Glory["Xiao"]  = "ADC"
        Glory["Yuan"]  = "Mage"
        Glory["Jacky"] = "Jungle"
        Glory["Yahua"] = "Tank"
        Glory["Zhen"]  = "Support"
    #跟c++里面的键值对还是很像的！
    //std::map<std::string, std::string> Glory;
    #数组的空间无需声明无需配置，自动增长。跟c++的一些容器也很像！

    #元素用完了怎么办？
    delete Glory["Xiao"]
    delete Glory

#控制语句-和c++相同
if(expression)
    statement
while(expression)
    statement
for(expr1;expr2;expr3)
    statement
for(key in array)
    statement
#警告： awk缺乏逗点运算符，无法以逗点作为表达式列表的分割;



#awk的基本思想：  

          aaa bbb ccc
          111 222 333
          ddd eee fff
          444 555 666
          ...

====>  FS = " "  RS = "\n"

          1   2   3
        --------------
     1 |  aaa bbb ccc
     2 |  111 222 333
     3 |  ddd eee fff
     4 |  444 555 666
     5 |  ...

====>  FS = " "  RS = "\n"

            1   2   3
        --------------
    1 $0 |  $1  $2  $3
    2 $0 |  $1  $2  $3
    3 $0 |  $1  $2  $3
    4 $0 |  $1  $2  $3
    NR $0 |  ...
     

#awk 的基本格式:
    最简单的 awk 程序是一个由多个 模式–动作 语句构成的序列:
        pattern { action } 
        pattern { action }
        .....
    For example:
        /home/zhenkong/test/register.cpp

        awk '$3=="=="{print $0}' register.cpp

            '$3=="=="{print $0}'

        '$3 ==   "=="     {print $0}'



        awk '$0~" }.*"{print $0}' register.cpp

            '$0~" }.*"{print $0}'

         '$0 ~  " }.*"     {print $0}'

#awk 的常用格式:

    //

    BEGIN{statement} //打开文件之前

    expression{ statements}
    /regular expression/ { statements}
    ...

    END{ statements} //关闭文件之后










