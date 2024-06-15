# 我是标题
## 我是小标题

我这句话想  
换行用了两个空格加回车

我是**加粗** 我是*倾斜*  我是***加粗和倾斜***

>引用东西再这里

想用表格看看有什么课  
- 概率论  
- 计算机网络原理  
- 操作系统
    - 实验课
    - 理论课
    > - 不想去上课了   
     
有些指令 `apt install filename` 原来是

*********
 
分隔一下

```pyhton
from pwn import *
io=remote("",)
gdb.attach(io,'b*main')

offset=0x+0x
sys_addr=0x
bin_sh_addr=0x
pop_ret=0x
pop_rdi=0x
payload=b'a'*offset+p64(pop_rdi)+p64(bin_sh_addr)  
payload+=p64(pop_ret)+p64(sys_addr)

io.sendline(payload)
io.interactive()
```

~~wqu~~   <u>H~2~O</u>  $X^2$    $sqrt{x}^2$  \sqrt{x}  

$$
\begin{Bmatrix}
   a & b \\
   c & d
\end{Bmatrix}
$$
$$
\begin{CD}
   A @>a>> B \\
@VbVV @AAcA \\
   C @= D
\end{CD}
$$

- [x] a   
- [ ] 睡觉  是 sk
- [ ] skdk
- [x] b  
***  

| Syntax      | Description | Test Text     |
| :---        |    :----:   |          ---: |
| Header      | Title       | Here's this   |
| Paragraph   | Text        | And more      |

:joy: :cry: :anger:  :s :tent: :house: :cat: :dog: :fire:   
:moon: :car: :airplane: :boat: :book: :watch: :man: :woman:   
:child: :smile: :cloud: :train: :v: 