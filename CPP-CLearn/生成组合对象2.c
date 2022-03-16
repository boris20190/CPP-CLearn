#include "stdio.h"

//Johnson-Trotter�㷨
//���������ָ���һ����ʼ����(��������Ϊ-1, ����Ϊ1)
//���ҵ������ƶ�����(���־����ܴ�, ͬʱ�������Ҫ������,�ұ����Լ�С)
//�������ƶ����������ƶ�(��ʵ���Ǻ�����ߵ����ֻ�λ��)(��һ�������ƶ�����, һ�㶼������)
//ÿ�ƶ�һ�ξ͵�ת���бȸ��ƶ��������ƶ����ִ�����ֵķ���
//��������ѭ������, ֱ���޷��ҵ������ƶ�����
//һ����˵, ��ϰ���ڿ�ʼ֮ǰ�Ȱ����ְ��մ����ҵ����ź�, ���㿪չ����
struct element {
    int value;
    int state;//1����,-1����
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
    printf("�ܹ��������ֵĸ���:\n");
    scanf("%d", &maxN);
    printf("��������(�ո����):\n");
    for (int i = 0; i < maxN; ++i) {
        scanf("%d", &arr[i].value);
        arr[i].state = -1;//��ʼ������Ԫ�ص�ָ���������
    }
    quickSort(arr, maxN);
    JST(maxN - 1);
    printf("\n%d����ȫ���й���%d��", maxN, count);
    return 0;
}

void swap(int i, int j) {
    struct element temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

void JST(int maxIndex) {
    printf("��%d��:", ++count);//�����count�����н��
    for (int i = 0; i < maxN; ++i) {
        printf("%d", arr[i].value);
    }
    printf("\n");
    int maxIndexValue = arr[maxIndex].value;//��ȡ���������ƶ�����
    swap(maxIndex, maxIndex + arr[maxIndex].state);//���������ƶ����ֺ���ǰһ�����ֵ�λ��
    for (int i = 0; i < maxN; ++i) {//�����б�ѡ�����ִ�����ֵ�״̬��ת
        if (arr[i].value > maxIndexValue) {
            arr[i].state = -1 * arr[i].state;
        }
    }
    int isCanMove = 0;
    int flagMax;
    int valueMax = -1;//�浵
    for (int i = 0; i < maxN; ++i) {//�ж��Ƿ�����һ���ı�׼: �Ƿ����ҵ������ƶ�����
        if (arr[i].state == 1) {//�����Ƿ�����
            if ((i != maxN - 1) && (arr[i].value > arr[i + 1].value && arr[i].value >= valueMax)) {//���Ԫ�ز��������Ҷ�,���Ԫ��ֵ�������ұߵ�Ԫ��ֵ���Ҵ���֮ǰ�Ĵ浵
                flagMax = i;//��¼��ǰ�����ƶ�Ԫ�ص������±�
                valueMax = arr[i].value;//��¼��ǰ�����ƶ�Ԫ�ص�ֵ
                isCanMove = 1;//���ӵ����һ������
            }
        }
        if (arr[i].state == -1) {//�����Ƿ�������, �������Ǹ�ifһ��
            if ((i != 0) && (arr[i].value > arr[i - 1].value && arr[i].value >= valueMax)) {
                flagMax = i;
                valueMax = arr[i].value;
                isCanMove = 1;
            }
        }
    }
    if (isCanMove) {//��������һ������, ���ٽ���һ��,û�о�ֱ���������
        JST(flagMax);//�ݹ�
    } else {
        printf("��%d��:", ++count);
        for (int i = 0; i < maxN; ++i) {
            printf("%d", arr[i].value);
        }
    }
}

//�͵���һ������
void quickSortR(struct element* nums, int start, int end) {
    if (start >= end) {
        return;
    }
    int pivot = nums[start].value;
    //ΪʲôҪ��left, right����start��end:
    //����ݹ黹Ҫ��start��end��Ϊ��Եֵ, ����������������Ųλ�õ�ʱ��仯��.
    int left = start, right = end;
    while (left < right) {
        //��Ϊ�����pivot�����ֵ, ���Դ��Ҷ˿�ʼ�ƶ��Ƚ�
        //����Ҷ�ֵС��pivot,����Ҷ�ֵ�������
        //����Ҷ�ֵ����pivot, ����������ƶ��Ҷ�
        while (nums[right].value >= pivot && left < right) {
            right--;
        }
        //Ϊʲô�м�ҲҪÿ���ж�left ? right:
        //��Ϊ��ѭ��Ƕ�׽ṹ, ��ʹһ��ʼ��ѭ������left < right, ����ѭ���Կ���һֱѭ����left >= right, ��ʱ�����Ҫÿ���жϴ�С��ϵ,��������.
        if (left < right) {
            nums[left] = nums[right];
        }
        //����ƶ���ʽ���Ҷ��ƶ���ʽ��ͬ, ���߽����ƶ�
        while (nums[left].value <= pivot && left < right) {
            left++;
        }
        if (left < right) {
            nums[right] = nums[left];
        }
        //��left��right��ͷ��ʱ��,Ҳ����pivot��ֵӦ���ڵ�λ��, ��ʱ��pivotֵ�����λ��.
        if (left == right) {
            nums[left].value = pivot;
        }
    }
    //ִ�еݹ����, ��left��right��ͷ��λ��Ϊ�ֽ�, ��һ��, ��һ�����
    quickSortR(nums, start, left - 1);
    quickSortR(nums, left + 1, end);
}

//�����������Ϊ�о�ֱ���ÿ��ź���̫��, Ҫ������,���Ҷ�,�����������������һ��, ֻ��Ҫ������������鳤�ȼ���, �о��ÿ�һЩ.
void quickSort(struct element* nums, int length) {
    quickSortR(nums, 0, length - 1);
}