#include<iostream>

using namespace std;

class People {
public:
	int id;
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

class Student : public People {
public:
	int sid;
	void say() {
		cout << "I'm a student! My sid is " << sid << endl;
	}
	Student() {
		cout << "Student()" << endl;
	}
	Student(int id, int sid) : sid(sid), People(id) {//如果要定义基类中的id, 则需要在构造的时候定义, 和sid一起在这里定义
		cout << "Student(int id, int sid)" << endl;	 //不能在这个函数内部进行定义. 因为函数内部都是临时定义, 函数结束就会销毁, 无法保留 (函数内的都是临时的, 除非手动分配内存). 
		//this->id = id;	虽然这里用this->sid=sid可以, 但是不好. id是基类的, 理应调用基类的构造. 此外如果id是people私有的, 就肯定无法这样定义
	}												 //构造派生类时的基类构造会默认调用无参构造, 必须手动指定People(id), 才能使用自己写的带参构造
	~Student() {
		cout << "~Student()" << endl;
	}
};

//构造的时候时一层一层构造的, 从基类到派生类 (由内到外)
//析构的时候时一层一层析构的, 从派生类到基类 (由外到内)
int main() {
	Student zs(1001, 1002);
	zs.say();
	zs.People::say();
	return 0;
}
