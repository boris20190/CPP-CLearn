#include<iostream>

using namespace std;

class Student {
public:
	static int classId;//����static�ͱ�ɾ�̬��Ա
	//static const int classId = 1;	����ǳ���, �ͱ����ڶ����ͬʱ���г�ʼ��, ��������ԭ��һ���������ʼ��, ��Ϊ�������ܸı�
	static void printClassId() {
		cout << classId << endl;
		//cout << sid << endl;	��̬��������ʹ�÷Ǿ�̬��Ա
	}
	int sid;
	void printSid() {
		cout << sid << endl;
		cout << classId << endl;//�Ǿ�̬�����ܹ�ʹ�þ�̬��Ա
	}
};

//��̬��Ա��ʼ�����������������, �������κ������ط�����(�纯����, ���ڵ�), ��Ϊ��̬����������, ���ܺ��������س��Ϲ�ϵ
int Student::classId = 1; //��仰һ������.cpp�ļ���, ��classһ������.hͷ�ļ���
//��̬�ͷǾ�̬������볣������������, ��̬���ȶ�����, �����ǲ������ı�, ����û�б�Ȼ��ϵ

int main() {
	//��̬�ĳ�Ա��������Ҫ����, ����ֱ�ӵ���
	//�Ǿ�̬�ĳ�Ա�������ڶ����, ����ͨ���������
	Student::printClassId();
	return 0;
}