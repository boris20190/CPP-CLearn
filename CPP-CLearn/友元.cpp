#include<iostream>

using namespace std;

//void LampController::control(Lamp&);ֱ�����������������������Ȼ����, ������ʾ�����������������������
//ֻ��������:��LampController���ǰ��, ����Lamp��˳����⵽, Ȼ��control����ֻ��LampController��������, ����д�ں���,
//ͬʱ��ǰ������Lamp��, ����Ҳ�ͱ�����control������ⲻ��Lamp������, ����ì��˳�����.
class Lamp;

class LampController {
public:
	void control(Lamp&);
	void powerBtn() {}
};

class Lamp {
private:
	int color = 0;
	int power = 1;
public:
	void powerBtn() {}
	void switchBtn() {}
	void showStatus() {
		if (!power) {
			cout << "OFF" << endl;
		} else {
			cout << "ON.	Color: " << color << endl;
		}
	}
	//��Ԫ, �������к�����Ҫ��������˽�е�Ԫ��, ͨ����Ԫ�ķ�ʽʹ����������.
	//˵����, �������к�������չ, �����⺯����������. ���������ѻؼ�����һ��, ���Խ���Ԫ.
	friend void lampControl(Lamp&);//��Ԫ��������
	//friend class LampController;
	//friend void LampController::control(Lamp&);���������ܹ�������Ȼ�Ǳ����
	//Ϊʲô? ��ΪCϵ���Ե��ص��Ǵ������¿�, ��Lamp���ȡ����仰ʱ, ��û�з������control����, ������Ȼ�Ǳ����.
	//��ô, ��ô�����?
	//
	friend void LampController::control(Lamp& lp);
};

//��Ԫ����
void lampControl(Lamp& lp) {//��������
	lp.power = 1;
	lp.color = 2;
}

void LampController::control(Lamp& lp) {
	lp.power = 1;
	lp.color = 2;
}

//��Ԫ��		��������еĺ��������Է���Lamp�е�Ԫ��
//class LampController {
//public:
//	void control(Lamp& lp) {
//		lp.power = 1;
//		lp.color = 1;
//	}
//	//��������������Щ������Lamp���޹�, ���ǲ�������Щ�����ܹ��޸�Lamp���Ԫ��, ��ô��?
//	//���ǿ��԰�LampController����������Lamp���йصĺ�������������Ԫ.
//	//�൱�ڵ����������ĸ���ͬѧ���뵽��������, �����˲�����.
//	void powerBtn() {}
//};


int main() {
	Lamp lp;
	//lampControl(lp);
	LampController ct;
	//ct.control(lp);
	ct.control(lp);
	lp.showStatus();
	return 0;
}