#include<iostream>

using namespace std;

class Vector {
private:
	int x;
	int y;
public:

	Vector(int x = 0, int y = 0) : x(x), y(y) {
		cout << "Vector(int, int)" << endl;//ֻҪ����һ�ι��캯���ͻ��ӡһ����仰
	}

	friend ostream& operator <<(ostream&, const Vector&);

	Vector(const Vector& a) : x(a.x), y(a.y) {
		cout << "Vector(Vector &)" << endl;//�Լ�������һ����������, ������õ��ǿ�������, �ͻ��ӡһ����仰
	}

	//�Լ�������һ����ֵ����:
	Vector& operator =(const Vector& v) {
		cout << "operator = ()" << endl;
		x = v.x;
		y = v.y;
		return *this;
	}

};

ostream& operator <<(ostream& o, const Vector& v) {
	o << "<" << v.x << "," << v.y << ">" << endl;
	return o;
}

//����һ������: ��a��ֵ��b�Ĺ�������ν��е�
int main() {
	Vector a(1, 2);
	Vector b = a; //���ǹ���b, ͬʱ��a����b, ���Ի����һ�ι��캯��	��仰Ҳ��Ĭ�ϵ��ÿ�������, ��������ͨ����
	//b = a		���ǵ����İ�a����b, ����������
	cout << a << endl;
	cout << b << endl;
	cout << "****************" << endl;

	//��������: �����±���, ��������ֵ, ����ִ�й��캯��
	//�����������ֻ�ܴ�����, ͬʱ�����ֵ�Ļ����������ݹ���, ��Ч�ʺܵ�, ��Ϊ�ᷢ�����ο���(�������������м����, �м����������Ŀ�����), ����ǰ˵�Ĵ�ָ�벻��ֵ��ԭ��һ��
	Vector c(a);//���ǿ������������д��, ����д��...(...)��ʽ, �������� = , ��Ȼ����Ⱥ�Ҳ��
	cout << c << endl;
	cout << "****************" << endl;
	Vector d;
	cout << "���ٴ���һ��������d, ����չʾ��ֵ����" << endl;
	cout << d << endl;
	d = a;
	cout << d << endl;//�ɹ����ÿ�������
	return 0;
}