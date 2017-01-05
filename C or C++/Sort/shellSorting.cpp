/**
*shell排序的C语言实现
*@time 2017年1月5日 21:06
*just for practice
*/

#include<stdio.h>
void printArr(int *insertSortArr,int len);
void shellMoveArr(int *arr,int from,int to,int dk);
void shellInsertSort(int *insertSortArr,int len,int start,int dk);
void shellSort(int *sortArr,int len);



/**
*打印数组
*@param insertSortArr 要进行插入排序的数组的指针
*/
void printArr(int *insertSortArr,int len){

	for(int i=0;i<len;i++){

		printf("%5d",insertSortArr[i]);

	}

	printf("\n");
}

int main(){

	int sortArr[]={2,5,3,1,8,4,6,0};
	int len=sizeof(sortArr)/sizeof(sortArr[0]);

	shellSort(sortArr,len);
	printArr(sortArr,len);
	getchar();

	return 0;


}

/**
*进行shell排序
*@param int* sortArr 要进行shell排序的数组的指针
*@param int len 数组的长度
*/
void shellSort(int *sortArr,int len){

	int dk=len;//增量
	int i=0;

	while(true){
		
		
		dk=dk/2;	 //求增量
		dk>=1?dk:1;

		for(i=0;i<len;i=i++ ){

			shellInsertSort(sortArr,len,i,dk);

		}
		
		if(dk==1){
			break;
		}

	}
}


/**
*@param int * insertSortArr 要进行shell插入排序的数组的指针
*@param int len 数组的长度
*@param int start 开始的位置
*@param int dk 增量
*/
void shellInsertSort(int *insertSortArr,int len,int start,int dk){

	int j=0;int temp=0;

	for(int i=start+dk;i<len;i=i+dk){

		j=i-dk;

		while(j>=start){

			if(insertSortArr[i]>=insertSortArr[j]){

				//j+dk j+2dk 到 i-dk 都往后移动 dk 位  i 到 j+dk (增量dk)

				shellMoveArr(insertSortArr,j+dk,i,dk);

				break;

			}else{
				//要插入的数 比当前小

				if(j==start){
					//比最小的还小

					//0 0+dk 0+2dk到i-1 向后移动 dk 位  i dao 0
					shellMoveArr(insertSortArr,start,i,dk);
					break;

				}else{

					j=j-dk;

				}

			}	

		}

	}

}

/**
*向后移动数组 把from到to-1 向后移动dk位
*把to移动到from
*@param int* arr 要操作的数组
*@param int form 从哪里开始移动
*@param int to		移动到
*@param int to		增量
*/
void shellMoveArr(int *arr,int from,int to,int dk){


	int temp=0;

	//from 到 to-dk 都往后移动 增量 位 (增量dk)

	temp=arr[to];//存下to的值

	for(int k=to-dk;k>=from;k=k-dk){

		arr[k+dk]=arr[k];


	}

	//ito 到 from 的 位置
	arr[from]=temp;
}