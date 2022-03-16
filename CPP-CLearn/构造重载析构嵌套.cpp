#include<iostream>
//C++是从上往下看的, 没看到就不认识, 所以调用要在声明下面
using namespace std;

class Student {
public:
	void say() const {//函数括号后面加const意思是整个函数不会修改本类的成员变量
		cout << "I'm a student! My name is " << name << " My id is " << sid << endl;
	}
	void setName(const string);
	void setSid(const int);
	//构造函数:默认是不用写的, 但当有个性需求时, 要自己写. 自己写了, 默认的就没了
	Student(string, int);
	//如果我既想有参构造也想无参构造, 就需要用到重载
	Student();
/*这个关键词是表示函数只能正常用()构造, 不能用=隐式构造, 也就是只能Student zs(...),不能 Student zs = ..., 并且这个关键词也只能用在类的构造函数上, 其他函数会报错*/
	//同时我也发现, 也许是Windows系统的特性, 这个强制显式只能在class里面写函数, 不能放外面写, 否则报错
	explicit Student(int std) : sid(sid) {
		cout << "Student(int)" << endl;
	}
	//析构函数:默认也是不用写的, 但当类中有分配内存的行为发生时, 就需要自己写, 才能在结束的时候清理这部分内存, 否则不会自动清理, 产生内存泄漏
	~Student();
	//嵌套类--类里面也能再定义类
	class Note {
	public:
		string content;
	};
	Note nt;
	//当类里面动内存了, 比如这个函数. 就必须手写析构函数将new出来的delete掉
	void course(int num) {
		score = new int[num];
		coursesCount = num;
	}
private:
	int sid = -1;
	string name = "Anonymous";
	int* score;
	int coursesCount;
};

//一般是在类里面放个函数的声明, 然后函数写外面, 同理, 类还能直接在一个函数里面定义, 在哪里定义, 就只能在哪里被直接使用, 外面不能直接用
void Student::setName(const string name) {
	this->name = name;
}

void Student::setSid(const int sid) {
	this->sid = sid;
}

Student::Student(string name, int sid) : sid(sid), name(name) {//构造函数会在构造类的时候自动调用, 现在就是定义一个Student类就会打印一遍Student()
	cout << "Student()" << endl;//这里初始化参量可以不像上面一样写this->sid = sid, 也可以在括号后面写: 然后写sid(sid)
								//这里叫初始化, 上面的其实是赋值, 构造就是初始化, 一定会调用构造函数
								//以后记住, 初始化就按这么着写,用:初始化,不写上面的写法.
}

//重载的Student构造函数, 无参构造
Student::Student() {}
/*这个关键词是表示函数只能正常用()构造, 不能用=隐式构造, 也就是只能Student zs(...),不能 Student zs = ..., 并且这个关键词也只能用在类的构造函数上, 其他函数会报错*/
//explicit Student::Student(int sid): sid(sid) {
//	cout << "Student(int)" << endl;
//}

//易错:	无参函数不能和完全带默认参的函数一起重载, 因为编译器会分不清无参调用时去用哪个函数, 会报错!

Student::~Student() {
	delete score;
	cout << "~Student()" << endl;
}

//c++特性, 可以在构建函数时提供默认参数, 也就是直接调用fun, 啥也不写, 一样有默认结果. 同时还不耽误正常往里面传值.(所有函数适用)
//而且默认参数也可以不全给, 比如可以只给b,c默认参, a不给. 这样调用的时候就只需要传入a参. 但不能跳着给默认参, 比如光给b默认参. 会报错.
void fun(int a, int b = 2, int c = 3) {
	cout << a << b << c << endl;
}

int main() {
	int num(123);//这里是对num的初始化, 之前熟悉的写法是num=123.在c++可以这么用, 可以想成为"函数"num传入值, 下面类初始化同理
	cout << num << endl;
	fun(1);
	Student zs("Boris", 1001);//现在就可以在构造的时候输入信息了, 也就是说, 构造函数本身也可以用来接收信息
	//zs.setName("boris");
	//zs.setSid(1001);
	zs.say();
	//内部类通过这种方式调用
	Student::Note note;
	note.content = "abcabc";
	cout << "****************" << endl;
	Student ls(1001);
	//Student ls = 1001;因为explicit强制显式, 所以这么写会报错
	Student* p = new Student;//malloc 和 free是一对, new和delete是一对, 在c++中用new和delete, new会调用构造函数, 但malloc不会; free和delete同理
	p->course(10);
	delete p;//在delete p的时候自动调用析构函数, 将score删除, 防止内存泄露
	return 0;
}