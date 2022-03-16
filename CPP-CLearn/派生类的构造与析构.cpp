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
	Student(int id, int sid) : sid(sid), People(id) {//���Ҫ��������е�id, ����Ҫ�ڹ����ʱ����, ��sidһ�������ﶨ��
		cout << "Student(int id, int sid)" << endl;	 //��������������ڲ����ж���. ��Ϊ�����ڲ�������ʱ����, ���������ͻ�����, �޷����� (�����ڵĶ�����ʱ��, �����ֶ������ڴ�). 
		//this->id = id;	��Ȼ������this->sid=sid����, ���ǲ���. id�ǻ����, ��Ӧ���û���Ĺ���. �������id��people˽�е�, �Ϳ϶��޷���������
	}												 //����������ʱ�Ļ��๹���Ĭ�ϵ����޲ι���, �����ֶ�ָ��People(id), ����ʹ���Լ�д�Ĵ��ι���
	~Student() {
		cout << "~Student()" << endl;
	}
};

//�����ʱ��ʱһ��һ�㹹���, �ӻ��ൽ������ (���ڵ���)
//������ʱ��ʱһ��һ��������, �������ൽ���� (���⵽��)
int main() {
	Student zs(1001, 1002);
	zs.say();
	zs.People::say();
	return 0;
}
