#include<iostream>

using  namespace std;
//���ʿ��Ʒ�Ϊ����: private < protected < public (�ɷ��ʵĶ����С����)
//private:		��֧�ֱ������
//protected:	��֧�ֱ�����ʺ����������
//public:		ȫ��������λ�÷���
class People {
private:
	string name;
protected:
	int id;
public:
	//name��˽��, Ҳ����ֻ��ͨ���Լ�д��getName������, ������Ҳ��Ҫ�����������������name, ����ֱ����
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

//����ķ��ʿ��ƹؼ���(public, protected, private) �����ǽ��̳еõ��ĳ�Ա�ķ��ʿ��Ƶȼ�ͳһ���������ڵ��ڸùؼ��ֵ��ϸ�ȼ�
//����public ���Ǻ���Ӱ��õ��ĳ�Ա�ķ��ʵȼ�, ��protected�ͻὫ�̳еĳ�Ա��public���protected, �����ϸ��private����, private��ȫ�����private
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