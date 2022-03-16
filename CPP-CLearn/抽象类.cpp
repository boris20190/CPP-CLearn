//不能产生对象的类
//为了代码复用
//面临的实际情况: 如果两个类之间没有继承关系, 但是他们有相同的行为函数, 该怎么做才能避免代码重复呢?
//因为没有继承关系, 所以多态是没法用的. 因此, 就需要找到一个新的方法来解决问题
//于是抽象类诞生了. 抽象类是由多个类抽象出来的产物, 它看起来和谁都有点关系, 但因为太过于抽象, 也就注定了它不可能产生一个具体的对象
//抽象类单纯就是为了代码复用人为创造的虚拟类
//举个例子: 矩形类和圆形类都能求面积, 但他俩没有继承关系. 为了求面积的函数能够复用, 人为抽象出一个图形类
//图形类里包括了求面积, 但图形是一个抽象的概念, 不可能直接创造某个对象, 只能通过继承关系不断具象化. 这就是抽象类

#include<iostream>

using namespace std;

//为了让圆和矩形产生关系, 人为抽象出了形状这个抽象类
class Shape {
public:
	//virtual double area() {//和多态那里一样, 还是打算直接写一个虚函数
	//	return 0;		   //但是这样真的好吗? 在这里的虚函数和多态那里的虚函数有区别吗?
	//}					   //这里的形状是绝对无法单独创造对象的, 因此这个函数的返回值也就注定是个摆设. 程序里的东西一定是有用的, 绝对不能凑数
	//因此, 在这里虚函数的写法发生了一些变化
	virtual double area() = 0;//直接就没有返回值了, 把没必要的东西省去, 简洁了很多.
							  //另外一个类成为抽象类后, 编译器就不允许这个类产生对象了. 这样可以避免很多潜在bug的产生
	//抽象类: 拥有像这样的抽象函数的类就是抽象类 (有一个就算)
	//抽象类除了不能产生对象, 其他的和普通类没区别
};

class Circle : public Shape {
public:
	double r;
	Circle(int r = 1) : r(r) {}
	//一个小疑问: 如果继承于抽象类的派生类依然没有具体实现这个抽象函数, 它是否也是一个抽象类呢?
	double area() {
		return 3.14 * r * r;
	}
};

//回答刚才的小疑问: 如果派生类依然没有实现这个抽象函数, 它就依然是一个抽象类, 会报错无法实例化抽象类, 尽管它可能没用到抽象类里的函数
//class Shape2D : public Shape {
//public:
//	void fun() {
//		cout << "This is a 2D shape!" << endl;
//	}
//};

class Rectangle : public Shape {
public:
	double a;
	double b;
	Rectangle(int a = 1, int b = 1) : a(a), b(b) {}
	double area() {
		return a * b;
	}
};

//同一个显示面积的函数
void showArea(Shape& s) {
	cout << s.area() << endl;
}

int main() {
	Circle c(2);
	Rectangle r(3, 4);
	//Shape2D s;
	//s.fun();
	showArea(c);
	showArea(r);
	return 0;
}