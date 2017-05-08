## 用好 C++11 move语义

### 使用方法原始文档：[move](http://www.cplusplus.com/reference/utility/move/)  

### 右值引用与使用：[move](https://www.ibm.com/developerworks/cn/aix/library/1307_lisl_c11/)


### 条条道路通罗马
假设你都阅读并理解了上述2个文档，那么就知道了对右值主要解决拷贝的性能问题。  
但是只要你实现并运用好swap函数或者使用常量指针当做返回参数，也可以达到0拷贝。  
当然如果你觉得swap和指针参数会使得代码难看，以及写代码稍微复杂，那么可以使用move右值语义。  

### 如何写好一个有move语义的自定义数据结构
 

在C++11标准中，编译器会自定义数据结构默认生成6个函数： **无参构造，拷贝构造，赋值，右值构造，右值赋值，析构函数**，如下：

    struct DefaultNote {
        // 无参构造
        DefaultNote() {

        }
        // 析构
        ~DefaultNote() {

        }
        // 拷贝构造
        DefaultNote(const DefaultNote& o) {
            printf("default copy construct\n");
        }
        // 赋值
        DefaultNote& operator = (const DefaultNote& o) {
            printf("default assign\n");
            return *this;
        }
        // 右值构造
        DefaultNote(DefaultNote&& o) {
            printf("default right value copy construct\n");
        }
        // 右值赋值
        DefaultNote& operator = (DefaultNote&& o) {
            printf("default right value assign\n");
            return *this;
        }
		/* 

        */       
    };   


注意没有赋值构造这一说法：  

	DefaultNote node;  
	// 此处是调用的拷贝构造  
	DefaultNote node2 = node;  
	// 相当于  
	// DefaultNote node2(node);  

当我们自定义数据结构的时候，**要么都不定义以上任何函数，要么就全部定义以上所有6个函数**，否则编译器默认函数的加入会使问题变得不可控。  
如果需要自定义某个函数，又想充分利用编译器自动生成的函数，而又想数据结构安全，必须全面了解编译器干了什么。  
如下表，整理了用户自定义函数和编译器默认生成函数的关系。  
user-def: 表示用户自定义  
delete:   表示编译器不允许调用此函数，调用此函数编译错  
default:  表示编译器生成的默认函数  
左值函数：拷贝构造函数，赋值函数  
右值函数：右值构造函数，右值赋值函数  



	| 用户构造 | 无参构造 | 拷贝构造 | 赋值     | 右值构造     | 右值赋值 | 析构函数 |
	|----------|----------|----------|----------|--------------|----------|----------|
	| user-def | delete   | default  | default  | default      | default  | default  |
	| none     | default  | default  | default  | default      | default  | default  |
	| none     | user-def | default  | default  | default      | default  | default  |
	| none     | delete   | user-def | default  | like拷贝构造 | like赋值 | default  |
	| none     | default  | default  | user-def | like拷贝构造 | like赋值 | default  |
	| none     | delete   | delete   | delete   | user-def     | like赋值 | default  |
	| none     | default  | delete   | delete   | like赋值     | user-def | default  |

###  总结：
 
  * 析构函数完全置身于这些构造函数和赋值函数的纠纷中  
  * 用户自定义了构造函数（包括拷贝构造和右值构造）后，编译器拒绝生成无参构造函数
  * 用户**自定义了某个函数，完全以这个函数为全部，编译器对于这个函数不会生成任何附加代码**  
    例如：定义了右值构造，那么结构体内的变量的右值构造也需要手动调用，否则结构体内的变量什么构造函数都不会调用
  * 拷贝构造和赋值函数对等互不影响
  * 一旦自定义了一个左值函数，右值函数like对应的左值函数  
  * 一旦自定义了一个右值函数，左值函数delete，另一个右值函数like对应的左值函数
  * STL类型的右值赋值是调用的swap函数
  * 为保持和STL一致，**自定义右值赋值函数最好也调用swap函数**
 
###  测试Demo见[git地址](https://github.com/haike1363/c11-demo) move目录
