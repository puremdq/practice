/**
 * �������C����ʵ��
 * @time 2017��1��12�� 21:33:36
 * @author puremdq
 * just for practice
 */

#include<stdio.h>
void printArr(int *arr,int len);
void swap(int &a,int &b);
void heapAdjust(int *list,int start,int end);
void heapSort(int *list,int *resArr,int length);
/**
 * ������������
 */
void swap(int &a,int &b){

	int temp=a;
	a=b;
	b=temp;

}


/**
 *����  ����start��end �г���start���ڵ�λ��
 *������Ҫ�����²���Ϊһ���ѵ���ʹ������
 *��Ϊһ��(С)����
 * @param list  ��˳���洢��С����
 * @param start ��ʼλ��
 * @param end   ����λ��
 */
void heapAdjust(int *list,int start,int end){

	int i=start*2,k;

	while(i<=end){

		k=i;

		if(i+1<=end){		//�������������

			if(list[i+1]<list[i]){

				//��������� ��������С
				k++;

			}

		}

		if(list[k]<list[start]){

			swap(list[start],list[k]);

			start=k;
			i=start*2;


		}else{
			break;
		}

	}

}

/**
 *��С��������
 *@param int *list ��˳���洢��С����
 *@param int *resArr ���ڴ洢����Ľ��
 *@param int length  Ҫ�����Ԫ�صĸ���������ĳ��ȣ�
 */
void heapSort(int *list,int *resArr,int length){
	
	int i=0,j=0;
	for(i=length/2;i>0;i--){

		heapAdjust(list,i,length);

	}

	for(i=length;i>1;i-- ){

		resArr[j++]=list[1];

		swap(list[1],list[i]);

		heapAdjust(list,1,i-1);

	}

	resArr[j]=list[1];

}


int main(){

	int list[]={0,5,8,3,7,6,1,2,4};
	int resArr[8]={0};
	heapSort(list,resArr,8);
	printArr(resArr,8);
	//getchar();

	return 0;
}

/**
 *��ӡ����
 *@param int *arr Ҫ��ӡ������
 */
void printArr(int *arr,int len){

	for(int i=0;i<len;i++){


		printf("%5d",arr[i]);


	}

	printf("\n");
}