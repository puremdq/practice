#include<iostream>
#include<stdio.h>
#include<string.h>
#define MAX 50
using namespace std;

class doubleStack
{
public:
	doubleStack(){
		this->init(MAX);
	}

	doubleStack(int size){
		this->init(size);
	}

	void init(int size){

		this->size=size;
		this->top=-1;

	}

	//得到栈顶  不出栈
	double getstackTop(){

		if(!this->isEmptyStack()){

			return this->stackArr[this->top];


		}else{

			return false;
		}

	}



	//出栈
	double pop(){

		if(!this->isEmptyStack()){

			return this->stackArr[this->top--];


		}else{

			return false;
		}

	}

	//入栈
	bool push(double ch){

		if(!this->isFullStack()){

			this->stackArr[++this->top]=ch;
			return true;


		}else{

			return false;
		}

	}

	bool isFullStack(){

		if(this->top>=this->size-1){

			return true;
		}else
		{
			return false;
		}

	}

	bool isEmptyStack(){


		if(this->top<=-1){

			return true;

		}else
		{
			return false;
		}
	}





private:
	double stackArr[MAX];
	int top;
	int size;

};



class charStack
{
public:
	charStack(){
		this->init(MAX);
	}

	charStack(int size){
		this->init(size);
	}

	void init(int size){

		this->size=size;
		this->top=-1;

	}

	//得到栈顶  不出栈
	char getstackTop(){

		if(!this->isEmptyStack()){

			return this->stackArr[this->top];


		}else{

			return false;
		}

	}



	//出栈
	char pop(){

		if(!this->isEmptyStack()){

			return this->stackArr[this->top--];


		}else{

			return false;
		}

	}

	//入栈
	bool push(char ch){

		if(!this->isFullStack()){

			this->stackArr[++this->top]=ch;
			return true;


		}else{

			return false;
		}

	}

	bool isFullStack(){

		if(this->top>=this->size-1){

			return true;
		}else
		{
			return false;
		}

	}

	bool isEmptyStack(){


		if(this->top<=-1){

			return true;

		}else
		{
			return false;
		}
	}





private:
	char stackArr[MAX];
	int top;
	int size;

};


double caculate(double czs1,char czf,double czs2){

	switch (czf)
	{

	case '+':

		return czs1+czs2;
		break;
	case '-':
		return czs1-czs2;
		break;
	case '*':
		return czs1*czs2;
		break;
	case '/':
		return czs1/czs2;
		break;

	}

}

//是否为操作数
bool isCzs(char *str){


	double temp=atof(str);
	if(temp==0&&str[0]!='0'){

		return false;

	}else{

		return true;
	}

}


//是否为操作符号
bool isCzf(char ch){


	char czfArr[]="+-*/()#";
	bool flag=false;

	for (int i = 0; i<strlen(czfArr); i++)
	{
		if(czfArr[i]==ch){
			flag=true;
			break;
		}
	}

	return flag;

}

//得到操作符的优先级值
int getCzfValue(char czf){


	if(czf=='#'){
		czf=0;

	}
	else if(czf=='+'||czf=='-'){
		czf=1;

	}

	else if(czf=='*'||czf=='/'){
		czf=2;

	}

	else if(czf=='('||czf==')'){
		czf=3;

	}else{

		return -1;

	}
	return czf;
}

//比较操作符的优先级  -2表示非法
int compareCzf(char tempCzf1,char tempCzf2){

	int czf1=getCzfValue(tempCzf1);
	int czf2=getCzfValue(tempCzf2);

	if(czf2!=-1&&czf2!=-1){
		int res=czf1-czf2;

		if(res==0){

			if(czf1!=0){

				return 1;
			}else{

				return 0;
			}

		}else{


			return res>0?1:-1;

		}


	}else{

		return -2;

	}
}

void getValue(char (*bds)[10],int leng){

	bds[leng][0]='#';
	bds[leng][1]='\0';
	leng=leng+1;

	charStack czfStack(20);//操作符
	doubleStack czsStack(20);//操作数

	czfStack.push('#');


	char *temp;//存放当前




	//printf("%s   %d\n",temp,i);

	for (int i=0;i<leng;i++)
	{
		temp=bds[i];

		if(isCzs(temp)){

			czsStack.push(atof(temp));

		}else if(isCzf(temp[0])){

			if(temp[0]=='('){

				czfStack.push('(');


			}else if(temp[0]==')'){


				char tempCzf=czfStack.pop();

				if(tempCzf!='('){
					//jisuan


					double czs2=czsStack.pop();
					double czs1=czsStack.pop();


					double res=caculate(czs1,tempCzf,czs2);
					czsStack.push(res);

					if(czfStack.pop()!='('){

					
						printf("error");

					}


				}


			}else if(compareCzf(temp[0],czfStack.getstackTop())>0){


				printf("%c da  %c\n",temp[0],czfStack.getstackTop());
				if(czfStack.getstackTop()!='#'){
				
				
					if(bds[i+1][0]!='('){
					//jisuan

					double czs1=czsStack.pop();
					double czs2=atof(bds[++i]);


					double res=caculate(czs1,temp[0],czs2);
					czsStack.push(res);

				
					}else{
				

					printf("pus %c\n",temp[0]);
					czfStack.push(temp[0]);
				
					}

				}else{
				
				printf("pus %c\n",temp[0]);
					czfStack.push(temp[0]);
				
				}
			}
			else if(compareCzf(temp[0],czfStack.getstackTop())<=0){

				char tempCzf=czfStack.getstackTop();

				printf("%c xiao  %c\n",temp[0],czfStack.getstackTop());

				if(tempCzf!='#'){

					if(tempCzf!='('&&tempCzf!=')'){
						
						czfStack.pop();

						double czs2=czsStack.pop();
						double czs1=czsStack.pop();

						double res=caculate(czs1,tempCzf,czs2);
						czsStack.push(res);
						czfStack.push(temp[0]);

					}else{
						czfStack.push(temp[0]);

					}

				}

			}

			//end 操作符
		}
		
		
		
		else{
			printf("%s error burenshi\n",temp);
		}

	

}
	printf("%lf",czsStack.pop());

}



int fenge(char *str,char (*arr)[10]){


	char temp[10];

	int j=0;int k=0;int flag=0;

	for (int i = 0; i < strlen(str); i++)
	{

		if(isCzf(str[i])){

			if(flag==0){
				arr[j][0]=str[i];
				arr[j][1]='\0';
				j++;
			}else{
				temp[k]='\0';
				strcpy(arr[j++],temp);
				k=0;flag=0;


				arr[j][0]=str[i];
				arr[j][1]='\0';
				j++;
			}

		}else{
			temp[k++]=str[i];
			flag=1;
		}

		if(i==strlen(str)-1&&flag==1){

			temp[k]='\0';
			strcpy(arr[j++],temp);

			return j;

		}
	}

}

int main(){

	char str[]="15+(8/2)+100*2";
	char  bds[MAX][10]={'\0'};
	int leng=fenge(str,bds);
	getValue(bds,leng);
	getchar();


}


