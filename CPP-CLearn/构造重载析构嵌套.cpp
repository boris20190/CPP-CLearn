#include<iostream>
//C++�Ǵ������¿���, û�����Ͳ���ʶ, ���Ե���Ҫ����������
using namespace std;

class Student {
public:
	void say() const {//�������ź����const��˼���������������޸ı���ĳ�Ա����
		cout << "I'm a student! My name is " << name << " My id is " << sid << endl;
	}
	void setName(const string);
	void setSid(const int);
	//���캯��:Ĭ���ǲ���д��, �����и�������ʱ, Ҫ�Լ�д. �Լ�д��, Ĭ�ϵľ�û��
	Student(string, int);
	//����Ҽ����вι���Ҳ���޲ι���, ����Ҫ�õ�����
	Student();
/*����ؼ����Ǳ�ʾ����ֻ��������()����, ������=��ʽ����, Ҳ����ֻ��Student zs(...),���� Student zs = ..., ��������ؼ���Ҳֻ��������Ĺ��캯����, ���������ᱨ��*/
	//ͬʱ��Ҳ����, Ҳ����Windowsϵͳ������, ���ǿ����ʽֻ����class����д����, ���ܷ�����д, ���򱨴�
	explicit Student(int std) : sid(sid) {
		cout << "Student(int)" << endl;
	}
	//��������:Ĭ��Ҳ�ǲ���д��, ���������з����ڴ����Ϊ����ʱ, ����Ҫ�Լ�д, �����ڽ�����ʱ�������ⲿ���ڴ�, ���򲻻��Զ�����, �����ڴ�й©
	~Student();
	//Ƕ����--������Ҳ���ٶ�����
	class Note {
	public:
		string content;
	};
	Note nt;
	//�������涯�ڴ���, �����������. �ͱ�����д����������new������delete��
	void course(int num) {
		score = new int[num];
		coursesCount = num;
	}
private:
	int sid = -1;
	string name = "Anonymous";
	int* score;
	int coursesCount;
};

//һ������������Ÿ�����������, Ȼ����д����, ͬ��, �໹��ֱ����һ���������涨��, �����ﶨ��, ��ֻ�������ﱻֱ��ʹ��, ���治��ֱ����
void Student::setName(const string name) {
	this->name = name;
}

void Student::setSid(const int sid) {
	this->sid = sid;
}

Student::Student(string name, int sid) : sid(sid), name(name) {//���캯�����ڹ������ʱ���Զ�����, ���ھ��Ƕ���һ��Student��ͻ��ӡһ��Student()
	cout << "Student()" << endl;//�����ʼ���������Բ�������һ��дthis->sid = sid, Ҳ���������ź���д: Ȼ��дsid(sid)
								//����г�ʼ��, �������ʵ�Ǹ�ֵ, ������ǳ�ʼ��, һ������ù��캯��
								//�Ժ��ס, ��ʼ���Ͱ���ô��д,��:��ʼ��,��д�����д��.
}

//���ص�Student���캯��, �޲ι���
Student::Student() {}
/*����ؼ����Ǳ�ʾ����ֻ��������()����, ������=��ʽ����, Ҳ����ֻ��Student zs(...),���� Student zs = ..., ��������ؼ���Ҳֻ��������Ĺ��캯����, ���������ᱨ��*/
//explicit Student::Student(int sid): sid(sid) {
//	cout << "Student(int)" << endl;
//}

//�״�:	�޲κ������ܺ���ȫ��Ĭ�ϲεĺ���һ������, ��Ϊ��������ֲ����޲ε���ʱȥ���ĸ�����, �ᱨ��!

Student::~Student() {
	delete score;
	cout << "~Student()" << endl;
}

//c++����, �����ڹ�������ʱ�ṩĬ�ϲ���, Ҳ����ֱ�ӵ���fun, ɶҲ��д, һ����Ĭ�Ͻ��. ͬʱ�����������������洫ֵ.(���к�������)
//����Ĭ�ϲ���Ҳ���Բ�ȫ��, �������ֻ��b,cĬ�ϲ�, a����. �������õ�ʱ���ֻ��Ҫ����a��. ���������Ÿ�Ĭ�ϲ�, ������bĬ�ϲ�. �ᱨ��.
void fun(int a, int b = 2, int c = 3) {
	cout << a << b << c << endl;
}

int main() {
	int num(123);//�����Ƕ�num�ĳ�ʼ��, ֮ǰ��Ϥ��д����num=123.��c++������ô��, �������Ϊ"����"num����ֵ, �������ʼ��ͬ��
	cout << num << endl;
	fun(1);
	Student zs("Boris", 1001);//���ھͿ����ڹ����ʱ��������Ϣ��, Ҳ����˵, ���캯������Ҳ��������������Ϣ
	//zs.setName("boris");
	//zs.setSid(1001);
	zs.say();
	//�ڲ���ͨ�����ַ�ʽ����
	Student::Note note;
	note.content = "abcabc";
	cout << "****************" << endl;
	Student ls(1001);
	//Student ls = 1001;��Ϊexplicitǿ����ʽ, ������ôд�ᱨ��
	Student* p = new Student;//malloc �� free��һ��, new��delete��һ��, ��c++����new��delete, new����ù��캯��, ��malloc����; free��deleteͬ��
	p->course(10);
	delete p;//��delete p��ʱ���Զ�������������, ��scoreɾ��, ��ֹ�ڴ�й¶
	return 0;
}