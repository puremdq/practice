/**
*插入排序的C语言实现
*@time 2017年1月4日
*just for practice
*/

#include<stdio.h>
void insertSort(int *insertSortArr,int len);
void printArr(int *insertSortArr,int len);

int main(){

	int insertSortArr[]={2,5,3,1,8,4,6};
	insertSort(insertSortArr,7);
	printArr(insertSortArr,7);
	getchar();

	return 0;


}


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


/**
*向后移动数组 把from到to-1 向后移动1位
*把to移动到from
*@param int* arr 要操作的数组
*@param int form 从哪里开始移动
*@param int to		移动到
*/
void moveArr(int *arr,int from,int to){


	int temp=0;

	//from 到 to-1 都往后移动一位

	temp=arr[to];//存下to的值

	for(int k=to-1;k>=from;k--){

		arr[k+1]=arr[k];


	}

	//ito 到 from 的 位置
	arr[from]=temp;
}



/**
*@param insertSortArr 要进行插入排序的数组的指针
*@param len 数组的长度
*/
void insertSort(int *insertSortArr,int len){

	int j=0;int temp=0;

	for(int i=1;i<len;i++){

		j=i-1;
		while(j>=0){

			if(insertSortArr[i]>=insertSortArr[j]){

				//j+1 到 i-1 都往后移动一位  i dao j+1

				moveArr(insertSortArr,j+1,i);
					
				break;

			}else{
				//要插入的数 比当前小

				if(j==0){
					//比最小的还小

					//0到i-1 向后移动一位  i dao 0
					moveArr(insertSortArr,0,i);
					break;
				

				}else{

					j--;

				}

			}	

		}


	}


}