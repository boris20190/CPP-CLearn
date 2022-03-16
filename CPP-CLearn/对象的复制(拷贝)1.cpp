#include<iostream>

using namespace std;

class Vector {
private:
	int x;
	int y;
public:

	Vector(int x = 0, int y = 0) : x(x), y(y) {
		cout << "Vector(int, int)" << endl;//只要调用一次构造函数就会打印一遍这句话
	}

	friend ostream& operator <<(ostream&, const Vector&);

	Vector(const Vector& a) : x(a.x), y(a.y) {
		cout << "Vector(Vector &)" << endl;//自己重载了一个拷贝构造, 如果调用的是拷贝构造, 就会打印一遍这句话
	}

	//自己再重载一个赋值函数:
	Vector& operator =(const Vector& v) {
		cout << "operator = ()" << endl;
		x = v.x;
		y = v.y;
		return *this;
	}

};

ostream& operator <<(ostream& o, const Vector& v) {
	o << "<" << v.x << "," << v.y << ">" << endl;
	return o;
}

//讨论一个问题: 把a赋值给b的过程是如何进行的
int main() {
	Vector a(1, 2);
	Vector b = a; //这是构造b, 同时把a赋给b, 所以会调用一次构造函数	这句话也会默认调用拷贝构造, 而不是普通构造
	//b = a		这是单纯的把a赋给b, 不包括构造
	cout << a << endl;
	cout << b << endl;
	cout << "****************" << endl;

	//拷贝构造: 创建新变量, 并拷贝赋值, 但不执行构造函数
	//拷贝构造必须只能传引用, 同时如果传值的话拷贝的内容过大, 会效率很低, 因为会发生两次拷贝(拷贝给函数的中间变量, 中间变量拷贝给目标变量), 和以前说的传指针不传值的原因一样
	Vector c(a);//这是拷贝构造的正规写法, 尽量写成...(...)形式, 而不是用 = , 虽然这里等号也行
	cout << c << endl;
	cout << "****************" << endl;
	Vector d;
	cout << "我再创建一个空向量d, 用来展示赋值运算" << endl;
	cout << d << endl;
	d = a;
	cout << d << endl;//成功调用拷贝函数
	return 0;
}