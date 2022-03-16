#include<iostream>

using  namespace std;
//访问控制分为三类: private < protected < public (可访问的对象从小到大)
//private:		仅支持本类访问
//protected:	仅支持本类访问和派生类访问
//public:		全程序任意位置访问
class People {
private:
	string name;
protected:
	int id;
public:
	//name是私有, 也就是只能通过自己写的getName来访问, 派生类也需要调用这个函数来访问name, 不能直接用
	void getName() {
		cout << "My name is " << name << endl;
	}
	void say() {
		cout << "I'm a person! My id is " << id << endl;
	}
	People() {
		cout << "People()" << endl;
	}
	People(int id) : id(id) {
		cout << "People(int id)" << endl;
	}
	~People() {
		cout << "~People()" << endl;
	}
};

//这里的访问控制关键字(public, protected, private) 作用是将继承得到的成员的访问控制等级统一提升到大于等于该关键字的严格等级
//比如public 就是毫无影响得到的成员的访问等级, 但protected就会将继承的成员从public变成protected, 但更严格的private不变, private就全部变成private
class Student : public People {
private:
	int sid;
public:
	void say() {
		cout << "I'm a student! My sid is " << sid << endl;
		cout << "My id is " << id << endl;
	}
	Student() {
		cout << "Student()" << endl;
	}
	Student(int id, int sid) : People(id), sid(sid) {
		cout << "Student(int id, int sid)" << endl;
	}
	~Student() {
		cout << "~Student()" << endl;
	}
};

int main() {
	Student zs(1001, 2002);
	zs.say();
	zs.People::say();
	return 0;
}