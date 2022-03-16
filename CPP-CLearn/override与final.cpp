//这俩说明符最先是在Java中使用, 后来c++借鉴过来了		c++11版本开始才能使用, 之前不行
//override:	用来标记派生类中写的这个函数是对基类中函数的重写覆盖, 不是重载, 更不是另写一个新函数
//			加上这个关键字后, 重写的函数格式就必须和基类中函数的格式一致了, 否则就会报错. 这是防止重写的时候写歪, 写成了新函数
//只有基类中的函数是虚函数, 派生类中的重写才能标记override
//final:	加在基类的虚函数后, 加上之后这个函数就不能再被派生类重写了
//			加在类名称之后, 这个类就不能再被派生
//这俩说明符是为了控制派生与继承关系
//这么说哈, 虽然规矩多了点, 但是越严谨, 程序出错的可能性就越小, 以后尽量用上, 减少bug

#include<iostream>

using namespace std;

class People /*final*/ {//加上final后, People类就不能派生了
public:
	virtual void say() /*final*/{//加上final后, say()函数就不能被重写了
		cout << "I'm a person!" << endl;
	}
};

class Student : public People {
public:
	void say() override {//加上override, say()就是对基类say()函数的严格重写, 必须格式一致
		cout << "I'm a student!" << endl;
	}
};

int main() {
	return 0;
}