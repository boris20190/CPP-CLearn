//������ʹ�ö����, ������������ͬʱ, ���������ľ������Ҫ�����������, ������Ȼ���˷ѵ�.
//��˾Ͳ����˶�̬. �����ǹ�ͬ�Ļ���������, �Ͳ���Ҫ����������, ֻ��Ҫдһ�麯��, �����˺ܶ�
//��˼һ��, ������Ϊ��ʲô: �����������һ��, ����������Ͳ�ͬ, �����ڲ�����ʽ��ͬ
//������Ե������Ǵ���������Ͳ�ͬ, �������ڲ�����ʽ��ͬ, ����Ƕ�̬��Ӧ�����
//�ٸ����������: �������й��˻��Ƕ���˹��, ��Ҫ�Է�. ����Ǵ���ʽȫ�ǳԷ�, ��������˲���һ�����ҵ�. ���Ҫ�ö�̬���
//����Ŀ��:	���������ǹ�ͬ�����ָ��, �������洫��ͬ��������ͻ���ò�ͬ��������ĺ���
//�����������: ����������ָ��, �����ǳ�, �����й���, ���ǳ���ͷ, �������˹��, ���ǳ����

#include<iostream>

using namespace std;

class People {
public:
	virtual void say() {//����virtual, ��say()����麯�����ܹ�ʵ�ֶ�̬����, Ҳ����ʹ�ö�̬
		cout << "I'm a person!" << endl;
	}
};

class Student : public People {
public:
	void say() {
		cout << "I'm a student!" << endl;
	}
};

//����CollegeStu��Student��������, ���������Ȼ�����̬.
//c++����: ��ĳ����дvirtual��, ���������е�������ȫ�������̬.
//Ҳ����Person��д��virtual, ����������������඼Ĭ�������̬��, ����Studentû��дvirtual
class CollegeStu : public Student {
public:
	void say() {
		cout << "I'm a college student" << endl;
	}
};

class Teacher : public People {
public:
	void say() {
		cout << "I'm a teacher!" << endl;
	}
};

void funSay(People* p) {
	//c++������Ĭ�ϵ��Ǿ�̬����, Ҳ����û��ʹ�ö�̬
	//����virtual��, ʹ�ö�̬����, ������ȷ�����
	p->say();
}

void funSay(People& p) {
	p.say();
}

int main() {
	Student zs;
	Teacher ls;
	CollegeStu ww;
	//�ʼ����virtualʱ,�������õ�����ǲ����������, ȫ�� I'm a person!
	//����ϣ���ֱ���student��teacher
	funSay(&zs);
	funSay(&ls);
	funSay(&ww);
	//��ֻ�Ǵ�ָ�����, ������ͬ��ok
	cout << "**************" << endl;
	funSay(zs);
	funSay(ls);
	funSay(ww);
	return 0;
}