/**
 * 堆排序的C语言实现
 * @time 2017年1月12日 21:33:36
 * @author puremdq
 * just for practice
 */

#include<stdio.h>
void printArr(int *arr,int len);
void swap(int &a,int &b);
void heapAdjust(int *list,int start,int end);
void heapSort(int *list,int *resArr,int length);
/**
 * 交换两个整数
 */
void swap(int &a,int &b){

	int temp=a;
	a=b;
	b=temp;

}


/**
 *调整  在在start到end 中除了start所在的位置
 *不符合要求，余下部分为一个堆调整使其整个
 *成为一个(小)顶堆
 * @param list  用顺序表存储的小顶堆
 * @param start 开始位置
 * @param end   结束位置
 */
void heapAdjust(int *list,int start,int end){

	int i=start*2,k;

	while(i<=end){

		k=i;

		if(i+1<=end){		//如果存在右字树

			if(list[i+1]<list[i]){

				//如果右子树 比左子树小
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
 *（小）堆排序
 *@param int *list 用顺序表存储的小顶堆
 *@param int *resArr 用于存储排序的结果
 *@param int length  要排序的元素的个数（数组的长度）
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
 *打印数组
 *@param int *arr 要打印的数组
 */
void printArr(int *arr,int len){

	for(int i=0;i<len;i++){


		printf("%5d",arr[i]);


	}

	printf("\n");
}