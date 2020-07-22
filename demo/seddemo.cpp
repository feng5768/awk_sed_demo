cat kzlog5_12.txt | grep Yahua | sed "s/.*[read|write]\s\(.*\)\/.*/\1/" | sort -n | uniq > kzlog5_12.list



#sed 指令格式：
    sed 选项 '指令' 文件 

#常用选项：
    -e：它告诉sed将下一个参数解释为一个sed指令，只有当命令行上给出多个sed指令时才需要使用-e选项
    -f：后跟保存了sed指令的文件
    -i：直接对内容进行修改，不加-i时默认只是预览，不会对文件做实际修改
    -n：取消默认输出，sed默认会输出所有文本内容，使用-n参数后只显示处理过的行
#编辑命令：
    a:追加  向匹配行后面插入内容
    c:更改  更改匹配行的内容
    i:插入  向匹配行前插入内容
    d:删除  删除匹配的内容
    s:替换  替换掉匹配的内容
    p:打印  打印出匹配的内容，通常与-n选项和用
    =:用来打印被匹配的行的行号
    n:读取下一行，遇到n时会自动跳入下一行
    r,w：读和写编辑命令，r用于将内容读入文件，w用于将匹配内容写入到文件

#简单示例
    #增
        zhenkong@kzlala:~/test/demo$ cat doc1
        abc
        123
        zhenkong@kzlala:~/test/demo$ sed '1ahello' doc1
        abc
        hello
        123
        zhenkong@kzlala:~/test/demo$  
        //sed '1ahello' doc1  |  sed '/abc/ahello' doc1
        //sed '1ihello' doc1  |  sed '/abc/ihello' doc1
    #删
        zhenkong@kzlala:~/test/demo$ cat doc1
        abc
        123
        zhenkong@kzlala:~/test/demo$ sed '1d' doc1
        123
        //sed '1d' doc1 | sed '1,3d' doc1 | sed '1,3!d' doc1  
    #改
        zhenkong@kzlala:~/test/demo$ cat doc1
        abc
        123
        zhenkong@kzlala:~/test/demo$ sed '1chello' doc1
        hello
        123
        zhenkong@kzlala:~/test/demo$ 
        //sed '1chello' doc1  |  sed '/abc/chello' doc1
    #查
        //最简单的查找替换格式
            zhenkong@kzlala:~/test/demo$ cat doc1
            abc
            123 abc 123
            zhenkong@kzlala:~/test/demo$ sed 's/123/hello/' doc1
            abc
            hello abc 123
            ////////////////////////////
            zhenkong@kzlala:~/test/demo$ cat doc1
            abc
            123 abc 123
            zhenkong@kzlala:~/test/demo$ sed 's/123/hello/g' doc1
            abc
            hello abc hello
            //替换每行的第二个匹配 | 替换每行所有匹配
            //'s/123/hello/2' doc1  | 's/123/hello/g' doc1
        //找到符合的格式之后，进行查找替换
            zhenkong@kzlala:~/test/demo$ cat doc1
            abc
            123 abc 123
            def
            123 abdc 123
            456
            zhenkong@kzlala:~/test/demo$ sed '/abdc/s/123/hello/g' doc1
            abc
            123 abc 123
            def
            hello abdc hello
            456
            //sed '/^[1-9]*/s/123/hello/2' doc1
        #其他功能
            sed  'r 2.txt'  1.txt
        