#include<iostream>

using namespace std;

class Vector {
private:
	int x;
	int y;
public:
	Vector(int x, int y) : x(x), y(y) {}
	friend Vector operator +(const Vector&, const Vector&);//类外函数调用私有变量, 用友元
	friend ostream& operator <<(ostream&, const Vector&);
	//向量模长比大小, 和+号重载一样, 友元与成员写法一致, 只差一个传入参量, 这里就只写成员函数了
	//这个函数作用: 左边比右边向量的模长大, 就返回真, 反之返回假. 因此返回值是一个布尔类型
	bool operator >(const Vector& v) {
		if (x * x + y * y > v.x * v.x + v.y * v.y) {
			return true;
		}
		return false;
	}
	//现在见过的函数, 友元与成员写法都可以等效互相转换
	//如果我想让向量实现++运算, 该怎么写呢?
	//v为向量, v++返回的是向量, ++v返回的是向量的引用
	//++v
	Vector& operator++() {
		++x;
		++y;
		return *this;//因为this是指针, 所以*this是本体, 和fun(&a)函数使用时用作fun(b)一样, 返回值为引用就返回本体, 所以这里时*this
	}
	//v++
	Vector operator++(int) {//这个int是干什么用的?为啥只写个int?
		Vector temp(x, y);	//这里的int是占位符,起占位作用, 没有实际用途, 也没有值传入(因为++是单目运算符),所以只写一个int
		++x;				//我尝试把int换成别的, 会报错, 提示我++的额外参数必须是int类型, 所以说这里的int其实是++的额外参数
		++y;				//我上网查了一圈, 这里的int真的没有意义, 单纯就是给编译器区分++的前置与后置, 不必太过纠结
		return temp;
	}
};

//想要用加号直接实现向量相加, 就需要对加号实现运算符重载	PS:+的重载除了可以用友元函数实现, 也可以放在类里面, 用成员函数实现. 写法一样, 只不过只需要传入一个参量, 所以在这里就不写了
Vector operator +(const Vector& a, const Vector& b) {
	return Vector(a.x + b.x, a.y + b.y);
}

//想通过cout直接打印向量, 打印带括号的向量, 就需要对<<符号进行重载
//c++中cout不是一个函数, 是输出流对象. <<符号是把后面的东西扔给前面的cout进行输出
//既然是要重载<<, 我们就要还原<<的用法. 因为可以有cout<< a << b << endl;的形式, 所以说, 在输出a后的返回值应该也是一个cout, 才能做到持续输出
ostream& operator <<(ostream& o, const Vector& v) {
	o << "<" << v.x << "," << v.y << ">";
	return o;
}

int main() {
	Vector a(1, 2), b(3, 4);
	cout << a << "\t" << b << "\t" << "hello" << endl;//重载之后就可以直接用来输出向量了
	cout << (a > b) << endl;//这个必须得加上括号, 看作整体. 否则会报错的
	cout << "***********" << endl;
	int i = 1;
	//(i++) = 666;
	//cout << i << endl;
	(++i) = 777;
	cout << i << endl;
	//通过实验发现, i++返回的是一个int值, 但++i返回的是i的引用, 所以i++与++i是有区别的
	//同样, (i = 4) = 7;也是返回的引用, 所以可以这样连等
	//引申一下, i++这里是先用temp暂存一下i值, 然后对i进行++i, 最后返回暂存的temp, 因此表现为在本次单目运算i值没有改变, 之后再使用i会发现i值+1
	//而++i是直接进行++i, 表现为本次使用i就已经+1
	//因为i++需要比++i多一个暂存, 所以效率稍差一些
	int j = 1;
	(j = 4) = 7;
	cout << j << endl;
	cout << "***********" << endl;
	cout << a << endl;
	cout << ++a << endl;
	cout << a++ << endl;
	cout << a << endl;
	return 0;
}