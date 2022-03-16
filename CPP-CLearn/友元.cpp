#include<iostream>

using namespace std;

//void LampController::control(Lamp&);直接在最上面声明这个函数依然不行, 报错提示不能在类外面声明这个函数
//只能这样了:把LampController类放前面, 好让Lamp类顺利检测到, 然后control函数只在LampController类中声明, 具体写在后面,
//同时在前面声明Lamp类, 这样也就避免了control函数检测不到Lamp类的情况, 最终矛盾顺利解决.
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
	//友元, 在类外有函数需要调用类中私有的元素, 通过友元的方式使其正常调用.
	//说白了, 就是类中函数的扩展, 把类外函数纳入类中. 和邀请朋友回家做客一样, 所以叫友元.
	friend void lampControl(Lamp&);//友元函数声明
	//friend class LampController;
	//friend void LampController::control(Lamp&);现在我们能够发现依然是报错的
	//为什么? 因为C系语言的特点是从上往下看, 在Lamp类读取到这句话时, 并没有发现这个control函数, 所以依然是报错的.
	//那么, 怎么解决呢?
	//
	friend void LampController::control(Lamp& lp);
};

//友元函数
void lampControl(Lamp& lp) {//传入引用
	lp.power = 1;
	lp.color = 2;
}

void LampController::control(Lamp& lp) {
	lp.power = 1;
	lp.color = 2;
}

//友元类		在这个类中的函数都可以访问Lamp中的元素
//class LampController {
//public:
//	void control(Lamp& lp) {
//		lp.power = 1;
//		lp.color = 1;
//	}
//	//如果这个类里面有些函数与Lamp类无关, 我们不想让这些函数能够修改Lamp类的元素, 怎么办?
//	//我们可以把LampController类中所有与Lamp类有关的函数单独声明友元.
//	//相当于单独把这个班的个别同学邀请到家里做客, 其他人不邀请.
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