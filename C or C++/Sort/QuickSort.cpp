/**
*快速排序的C语言实现
*@time 2017年1月11日 22:33:49
*@note 快速排序是一种交换排序
*just for practice
*/

#include<stdio.h>
int partition(int* arr,int low,int high);
void printArr(int *insertSortArr,int len);
void quickSort(int *arr);

/**
*将数组 从给定起点和给定终点 置为一个一第一个元素为枢轴的数组
*使得枢轴左边的元素都小于它，右边的元素都大于它
*@param int * arr 要进行快速排序的数组的指针
*@param int low 开始位置
*@param int high 结束位置
*@return int 枢轴所在位置
*2,5,3,1,8,4,6
*/
int partition(int* arr,int low,int high){


	int pivot=arr[low];     //记下枢轴 的 值
	int pivotIndex=low;		//记下枢轴所在的位置值

	while(low<high){
		
		while(arr[high]>=pivot&&low<high){

			high--;
		
		}
		
			arr[pivotIndex]=arr[high];
			arr[high]=pivot;
			pivotIndex=high;
	
	
		while(arr[low]<=pivot&&low<high){
		
				low++;
		
		}
			arr[pivotIndex]=arr[low];
			arr[low]=pivot;
			pivotIndex=low;
		
	}

	return pivotIndex;
}


/**
*快速排序
*@param int * arr 要进行快速排序的数组的指针
*@param int low 开始位置
*@param int high 结束位置
*/
void quickSort(int* arr,int low,int high){
	
	int pivotIndex=0;
	
	if(low<high){
		
		pivotIndex=partition(arr,low,high);
		//printArr(arr,7);
		quickSort(arr,low,pivotIndex-1);
		quickSort(arr,pivotIndex+1,high);
		
	}


}


int main(){

	int arr[]={2,5,3,1,8,4,6,0};
	quickSort(arr,0,7);
	printArr(arr,8);
	//getchar();
	return 0;

}

/**
*打印数组
*@param int* arr 要打印的数组的指针
*@param int  len 数组的长度
*/
void printArr(int *arr,int len){

	for(int i=0;i<len;i++){

		printf("%5d",arr[i]);

	}

	printf("\n");
}
