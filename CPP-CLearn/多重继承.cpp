#include<iostream>

using namespace std;

//ɶ�ж��ؼ̳���?	���� �����Ϊѧ������ʦ, Ȼ����ʦ��ѧ�����ںϳ���һ������--����
//����ͬʱӵ����ʦ��ѧ��������, ��ͽж��ؼ̳� (��Ϲ�)
//������ɶ������?	������, Person������id, ������a[100], ��Щ����Student��Teacher�̳���
//TeacherAssistant�ֱַ�̳���Student��Teacher, ���Ծͻ�ӵ������id, ��������a[100]
//����ʵ��������id��a[100]����ͬһ������, ��������û��Ҫ. ͬʱ��ֵʱҲ����Ϊ����������ж�����, �޷�ֱ�ӵ���
//��ô�����?		��̳�.
class Person {
public:
	int id;
	void say() {
		cout << "I'm a person!" << endl;
	}
	int a[100];
};

class Student : virtual public Person {//�����ļ̳й�ϵ��, ����һ��virtual�ͱ����̳���.֮�����ں�, �ͻ��Զ��ϲ�ͬ����, �����������һ���Ķ�����
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

class TeacherAssistant : public Student, public Teacher {//���Ƕ��ؼ̳еĸ�ʽ, �м䶺�Ÿ���
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
	//ͨ����ӡ����Ĵ�С���Է���, ���û��ʹ����̳�, ww�Ĵ�С��zs��ls��С�ĺ�
	//ʹ����̳к�, �ͻ�ϲ�ͬ����, ��������ֻ��һ��. ���Կ��������������ظ�ռ�ÿռ�
	//ͬʱ���û��ʹ����̳�, �ڵ���ʱ��Ҫ��::��˵��������õ���˭, ���ھͿ���ֱ�ӵ�����
	//��Ȼ, ����������໹��ͬ����ͬ��ĳ�Ա, ��Ȼ��Ҫ��::������˵��, ��Ϊ�޷��ϲ�
	ww.id = 123;
	ww.sid = 456;
	ww.tid = 789;
	cout << ww.id << "\t" << ww.sid << "\t" << ww.tid << "\t" << endl;
	return 0;
}