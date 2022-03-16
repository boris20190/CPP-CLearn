#include<iostream>

using namespace std;

//啥叫多重继承呢?	比如 人类分为学生和老师, 然后老师和学生又融合成了一个新类--助教
//助教同时拥有老师和学生的特征, 这就叫多重继承 (缝合怪)
//会遇见啥问题呢?	在这里, Person类中有id, 有数组a[100], 这些都被Student和Teacher继承了
//TeacherAssistant又分别继承了Student和Teacher, 所以就会拥有两份id, 两份数组a[100]
//但是实际上两份id和a[100]都是同一个东西, 按两份算没必要. 同时赋值时也会因为按两份算而有二义性, 无法直接调用
//怎么解决呢?		虚继承.
class Person {
public:
	int id;
	void say() {
		cout << "I'm a person!" << endl;
	}
	int a[100];
};

class Student : virtual public Person {//正常的继承关系中, 加上一个virtual就变成虚继承了.之后再融合, 就会自动合并同类项, 不会出现两份一样的东西了
public:
	int sid;
	void say() {
		cout << "I'm a student!" << endl;
	}
};

class Teacher : virtual public Person {
public:
	int tid;
	void say() {
		cout << "I'm a teacher!" << endl;
	}
};

class TeacherAssistant : public Student, public Teacher {//这是多重继承的格式, 中间逗号隔开
public:
	void say() {
		cout << "I'm a teaching assistant!" << endl;
	}
};

int main() {
	Person p;
	Student zs;
	Teacher ls;
	TeacherAssistant ww;
	cout << sizeof(p) << endl;
	cout << sizeof(zs) << endl;
	cout << sizeof(ls) << endl;
	cout << sizeof(ww) << endl;
	//通过打印对象的大小可以发现, 如果没有使用虚继承, ww的大小是zs和ls大小的和
	//使用虚继承后, 就会合并同类项, 公共部分只算一遍. 可以看出这样避免了重复占用空间
	//同时如果没有使用虚继承, 在调用时需要用::来说明具体调用的是谁, 现在就可以直接调用了
	//当然, 如果两个基类还有同名不同义的成员, 依然需要用::来具体说明, 因为无法合并
	ww.id = 123;
	ww.sid = 456;
	ww.tid = 789;
	cout << ww.id << "\t" << ww.sid << "\t" << ww.tid << "\t" << endl;
	return 0;
}