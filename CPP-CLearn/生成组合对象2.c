#include "stdio.h"

//Johnson-Trotter算法
//给所有数字赋予一个初始方向(比如向左为-1, 向右为1)
//先找到最大可移动数字(数字尽可能大, 同时它的左边要有数字,且比它自己小)
//将最大可移动数字向左移动(其实就是和它左边的数字换位置)(往一个方向移动就行, 一般都是向左)
//每移动一次就调转所有比刚移动的最大可移动数字大的数字的方向
//上述步骤循环往复, 直到无法找到最大可移动数字
//一般来说, 都习惯在开始之前先把数字按照从左到右递增排好, 方便开展工作
struct element {
    int value;
    int state;//1向右,-1向左
};

#define MAXN 100

struct element arr[MAXN];
int count = 0;
int maxN;

void swap(int i, int j);

void quickSort(struct element* nums, int length);

void quickSortR(struct element* nums, int start, int end);

void JST(int maxIndex);

int main() {
    printf("总共输入数字的个数:\n");
    scanf("%d", &maxN);
    printf("输入数字(空格隔开):\n");
    for (int i = 0; i < maxN; ++i) {
        scanf("%d", &arr[i].value);
        arr[i].state = -1;//初始化所有元素的指向都是向左的
    }
    quickSort(arr, maxN);
    JST(maxN - 1);
    printf("\n%d个数全排列共有%d个", maxN, count);
    return 0;
}

void swap(int i, int j) {
    struct element temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

void JST(int maxIndex) {
    printf("第%d个:", ++count);//输出第count个排列结果
    for (int i = 0; i < maxN; ++i) {
        printf("%d", arr[i].value);
    }
    printf("\n");
    int maxIndexValue = arr[maxIndex].value;//获取数列最大可移动数字
    swap(maxIndex, maxIndex + arr[maxIndex].state);//交换最大可移动数字和它前一个数字的位置
    for (int i = 0; i < maxN; ++i) {//把所有比选定数字大的数字的状态反转
        if (arr[i].value > maxIndexValue) {
            arr[i].state = -1 * arr[i].state;
        }
    }
    int isCanMove = 0;
    int flagMax;
    int valueMax = -1;//存档
    for (int i = 0; i < maxN; ++i) {//判断是否还有下一个的标准: 是否还能找到最大可移动数字
        if (arr[i].state == 1) {//假如是方向朝右
            if ((i != maxN - 1) && (arr[i].value > arr[i + 1].value && arr[i].value >= valueMax)) {//这个元素不能是最右端,这个元素值大于它右边的元素值并且大于之前的存档
                flagMax = i;//记录当前最大可移动元素的数组下标
                valueMax = arr[i].value;//记录当前最大可移动元素的值
                isCanMove = 1;//标记拥有下一个排列
            }
        }
        if (arr[i].state == -1) {//假如是方向向左, 和上面那个if一样
            if ((i != 0) && (arr[i].value > arr[i - 1].value && arr[i].value >= valueMax)) {
                flagMax = i;
                valueMax = arr[i].value;
                isCanMove = 1;
            }
        }
    }
    if (isCanMove) {//假如有下一个排列, 就再进行一次,没有就直接输出结束
        JST(flagMax);//递归
    } else {
        printf("第%d个:", ++count);
        for (int i = 0; i < maxN; ++i) {
            printf("%d", arr[i].value);
        }
    }
}

//就单纯一个排序
void quickSortR(struct element* nums, int start, int end) {
    if (start >= end) {
        return;
    }
    int pivot = nums[start].value;
    //为什么要用left, right接收start和end:
    //后面递归还要用start和end作为边缘值, 这俩数不能在下面挪位置的时候变化了.
    int left = start, right = end;
    while (left < right) {
        //因为定义的pivot是左端值, 所以从右端开始移动比较
        //如果右端值小于pivot,则把右端值交给左端
        //如果右端值大于pivot, 则继续向左移动右端
        while (nums[right].value >= pivot && left < right) {
            right--;
        }
        //为什么中间也要每次判断left ? right:
        //因为是循环嵌套结构, 即使一开始大循环满足left < right, 但内循环仍可能一直循环到left >= right, 这时候就需要每次判断大小关系,否则会出错.
        if (left < right) {
            nums[left] = nums[right];
        }
        //左端移动方式和右端移动方式相同, 二者交替移动
        while (nums[left].value <= pivot && left < right) {
            left++;
        }
        if (left < right) {
            nums[right] = nums[left];
        }
        //当left和right碰头的时候,也就是pivot的值应该在的位置, 这时把pivot值填入该位置.
        if (left == right) {
            nums[left].value = pivot;
        }
    }
    //执行递归操作, 以left和right碰头的位置为分界, 左一半, 右一半二分
    quickSortR(nums, start, left - 1);
    quickSortR(nums, left + 1, end);
}

//这个单纯是因为感觉直接用快排函数太丑, 要填数组,左右端,所以用下面这个美观一下, 只需要填入数组和数组长度即可, 感觉好看一些.
void quickSort(struct element* nums, int length) {
    quickSortR(nums, 0, length - 1);
}