//当出现使用多个类, 但做的事情相同时, 按照以往的经验就需要多个函数重载, 但这显然是浪费的.
//因此就产生了多态. 用他们共同的基类来接收, 就不需要反复重载了, 只需要写一遍函数, 方便了很多
//反思一下, 重载是为了什么: 多个函数名称一样, 传入参量类型不同, 函数内部处理方式不同
//现在面对的问题是传入参量类型不同, 但函数内部处理方式相同, 这就是多态的应用情况
//举个形象的例子: 不管是中国人还是俄罗斯人, 都要吃饭. 这就是处理方式全是吃饭, 但传入的人不是一个国家的. 这就要用多态解决
//大体的框架:	函数参量是共同基类的指针, 但往里面传不同的派生类就会调用不同的派生类的函数
//还是这个例子: 参量是人类指针, 动作是吃, 传入中国人, 就是吃馒头, 传入俄罗斯人, 就是吃面包

#include<iostream>

using namespace std;

class People {
public:
	virtual void say() {//加上virtual, 将say()变成虚函数就能够实现动态联编, 也就是使用多态
		cout << "I'm a person!" << endl;
	}
};

class Student : public People {
public:
	void say() {
		cout << "I'm a student!" << endl;
	}
};

//这里CollegeStu是Student的派生类, 但是输出仍然满足多态.
//c++特性: 在某个类写virtual后, 它后面所有的派生类全部满足多态.
//也就是Person类写了virtual, 它后面的所有派生类都默认满足多态了, 尽管Student没有写virtual
class CollegeStu : public Student {
public:
	void say() {
		cout << "I'm a college student" << endl;
	}
};

class Teacher : public People {
public:
	void say() {
		cout << "I'm a teacher!" << endl;
	}
};

void funSay(People* p) {
	//c++在这里默认的是静态联编, 也就是没有使用多态
	//加完virtual后, 使用动态联编, 就能正确输出了
	p->say();
}

void funSay(People& p) {
	p.say();
}

int main() {
	Student zs;
	Teacher ls;
	CollegeStu ww;
	//最开始不加virtual时,这样调用的输出是不会有区别的, 全是 I'm a person!
	//我们希望分别打出student和teacher
	funSay(&zs);
	funSay(&ls);
	funSay(&ww);
	//不只是传指针可以, 传引用同样ok
	cout << "**************" << endl;
	funSay(zs);
	funSay(ls);
	funSay(ww);
	return 0;
}