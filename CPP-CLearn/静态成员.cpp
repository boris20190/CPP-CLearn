#include<iostream>

using namespace std;

class Student {
public:
	static int classId;//加上static就变成静态成员
	//static const int classId = 1;	如果是常量, 就必须在定义的同时进行初始化, 不能再像原来一样在外面初始化, 因为常量不能改变
	static void printClassId() {
		cout << classId << endl;
		//cout << sid << endl;	静态函数不能使用非静态成员
	}
	int sid;
	void printSid() {
		cout << sid << endl;
		cout << classId << endl;//非静态函数能够使用静态成员
	}
};

//静态成员初始化必须在类外面进行, 不能在任何其他地方进行(如函数内, 类内等), 因为静态是无条件的, 不能和其他因素扯上关系
int Student::classId = 1; //这句话一般会放在.cpp文件中, 而class一般会放在.h头文件中
//静态和非静态与变量与常量是两个概念, 静态是稳定存在, 常量是不发生改变, 这俩没有必然关系

int main() {
	//静态的成员函数不需要对象, 可以直接调用
	//非静态的成员是依附于对象的, 必须通过对象调用
	Student::printClassId();
	return 0;
}