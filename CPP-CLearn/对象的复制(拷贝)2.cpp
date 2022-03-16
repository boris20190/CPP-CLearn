#include<iostream>
//深拷贝与浅拷贝
using namespace std;
//目标: 设计一个更加安全不容易出错的数组类型
class Array {

private:
	int* data;//内部数据多少待创建
	int size;//数组大小

public:

	Array(int size = 10) : size(size) {
		data = new int[size];
	}
	//拷贝构造: 调用构造说明对象原本不存在, 现在需要创建, 因此不需要delete, 同时也不会在创建的时候发生自拷贝, 因此简单很多
	Array(const Array& a) : size(a.size) {
		cout << "Array(const Array& a)" << endl;
		data = new int[size];
		for (int i = 0; i < size; i++) {
			data[i] = a.data[i];
		}
	}

	~Array() {//因为创建的时候动内存了, 所以要写一个析构函数来释放
		delete[] data;//只要删除的元素不是一个,而是一片空间, 则加中括号
	}

	int& operator [](int index) {//重载了[]符号, 使得自己写的array也能够正常使用[]了
		return data[index];
	}

	//手动写一个深拷贝--完全把a拷贝给b, 而不是简单的改变指针指向
	Array& operator = (const Array& a) {
		if (this == &a) {//判断一下是不是自赋值a=a的情况, 如果是就直接返回. 虽然a=a没有意义,但要考虑全面
			return *this;//假如自赋值不判断, 执行同样的方法, 则会在复制元素前将内存释放掉, 没有了拷贝目标, 结果只能是报错
		}				 //所以判断一下还是很有用的
		cout << "operator = ()" << endl;
		delete[] data;
		size = a.size;
		data = new int[size];
		for (int i = 0; i < size; i++) {
			data[i] = a.data[i];
		}
		return *this;
	}

};

int main() {
	Array a(5);
	//现在我们想像普通数组一样使用, 比如a[1] = 5, 所以就又需要将[]重载
	a[1] = 123;
	cout << a[1] << endl;
	Array b(5);
	b = a;
	cout << b[1] << endl;
	//在程序结束的时候, 析构自动调用, 但是析构报错了. 为什么呢?
	//直接b=a使得a与b向了同一个内存, 在执行完a的析构后, 这片内存已经不复存在, 再执行b的析构就会报错
	//同时, b=a的过程还伴随着原来指向b空间的指针指向a空间, 导致b空间无法找到, 也就是内存泄漏. 这很不好
	//这样的拷贝就是浅拷贝. 为了实现深拷贝, 需要自己再重载一个 = 
	//重载之后就不报错了, 因为这的的确确是两个数组, 不是两个指针指向同一片区域了
	//但我们要是想c(a)这样拷贝构造呢? 如果按照默认的拷贝构造, 这样还会导致a,c指针指向同一片内存, 因此很有必要重载一下构造函数
	//这也是给我们提了一个醒, 如果拷贝的对象是个指针, 要小心新老指针指向同一块地方的浅拷贝
	return 0;
}