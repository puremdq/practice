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


double caculate(double Operand1,char Operator,double Operand2){

	switch (Operator)
	{

	case '+':

		return Operand1+Operand2;
		break;
	case '-':
		return Operand1-Operand2;
		break;
	case '*':
		return Operand1*Operand2;
		break;
	case '/':
		return Operand1/Operand2;
		break;

	}

}

//是否为操作数
bool isOperand(char *str){


	double temp=atof(str);
	if(temp==0&&str[0]!='0'){

		return false;

	}else{

		return true;
	}

}


//是否为操作符号
bool isOperator(char ch){


	char OperatorArr[]="+-*/()#";
	bool flag=false;

	for (int i = 0; i<strlen(OperatorArr); i++)
	{
		if(OperatorArr[i]==ch){
			flag=true;
			break;
		}
	}

	return flag;

}

//得到操作符的优先级值
int getOperatorValue(char Operator){


	if(Operator=='#'){
		Operator=0;

	}
	else if(Operator=='+'||Operator=='-'){
		Operator=1;

	}

	else if(Operator=='*'||Operator=='/'){
		Operator=2;

	}

	else if(Operator=='('||Operator==')'){
		Operator=3;

	}else{

		return -1;

	}
	return Operator;
}

//比较操作符的优先级  -2表示非法
int compareOperator(char tempOperator1,char tempOperator2){

	int Operator1=getOperatorValue(tempOperator1);
	int Operator2=getOperatorValue(tempOperator2);

	if(Operator2!=-1&&Operator2!=-1){
		int res=Operator1-Operator2;

		if(res==0){

			if(Operator1!=0){

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

double getValue(char (*bds)[10],int leng){

	bds[leng][0]='#';
	bds[leng][1]='\0';
	leng=leng+1;

	charStack OperatorStack(20);//操作符
	doubleStack OperandStack(20);//操作数

	OperatorStack.push('#');


	char *temp;//存放当前

	//printf("%s   %d\n",temp,i);

	for (int i=0;i<leng;i++)
	{
		temp=bds[i];

		if(isOperand(temp)){

			OperandStack.push(atof(temp));

		}else if(isOperator(temp[0])){

			if(temp[0]=='('){

				OperatorStack.push('(');

			}else if(temp[0]==')'){


				char tempOperator=OperatorStack.pop();

				if(tempOperator!='('){
					//jisuan


					double Operand2=OperandStack.pop();
					double Operand1=OperandStack.pop();


					double res=caculate(Operand1,tempOperator,Operand2);
					OperandStack.push(res);

					if(OperatorStack.pop()!='('){


						printf("error");

					}


				}


			}else if(compareOperator(temp[0],OperatorStack.getstackTop())>0){


				//printf("%c da  %c\n",temp[0],OperatorStack.getstackTop());
				if(OperatorStack.getstackTop()!='#'){


					if(bds[i+1][0]!='('){
						//jisuan

						double Operand1=OperandStack.pop();
						double Operand2=atof(bds[++i]);


						double res=caculate(Operand1,temp[0],Operand2);
						OperandStack.push(res);


					}else{


						//printf("pus %c\n",temp[0]);
						OperatorStack.push(temp[0]);

					}

				}else{

					//printf("pus %c\n",temp[0]);
					OperatorStack.push(temp[0]);

				}
			}
			else if(compareOperator(temp[0],OperatorStack.getstackTop())<=0){

				char tempOperator=OperatorStack.getstackTop();

				//printf("%c xiao  %c\n",temp[0],OperatorStack.getstackTop());

				if(tempOperator!='#'){

					if(tempOperator!='('&&tempOperator!=')'){

						OperatorStack.pop();

						double Operand2=OperandStack.pop();
						double Operand1=OperandStack.pop();

						double res=caculate(Operand1,tempOperator,Operand2);
						OperandStack.push(res);
						OperatorStack.push(temp[0]);

					}else{
						OperatorStack.push(temp[0]);

					}

				}

			}

			//end 操作符
		}



		else{
			printf("%s error burenshi\n",temp);
		}



	}
	return OperandStack.pop();

}



int fenge(char *str,char (*arr)[10]){


	char temp[10];

	int j=0;int k=0;int flag=0;

	for (int i = 0; i < strlen(str); i++)
	{

		if(isOperator(str[i])){

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
	int leng=fenge(str,bds);//分割
	double res=getValue(bds,leng);

	printf("%lf\n",res);
	getchar();
}
