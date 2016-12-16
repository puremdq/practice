#include<stdio.h>
#include<Windows.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h>
#include<winsock.h>
#pragma comment(lib,"wsock32.lib")
#define SERVERPORT 5000
DWORD WINAPI sendMessage(LPVOID);
int canUseScreen=1;


int main(){

	struct sockaddr_in addrServ;//ip 结构体

	int addrClilentLen=0;

	char sendBuf[100]={0};


	// windows need
	WORD wVersionRequested;
	WSADATA wsaData;
	int retVal;

	SOCKET sockfd;
	char pacLength[5]={0};
	HANDLE h1;

	wVersionRequested=MAKEWORD(1,1);
	retVal=WSAStartup(wVersionRequested,(LPWSADATA)&wsaData);

	if(retVal!=0){

		printf("error\n");getchar();

		return -1;


	}
	//end windows need



	sockfd=socket(AF_INET,SOCK_STREAM,0);//初始化一个socket


	if(sockfd<0){

		printf("socket error\n");getchar();

		return -1;

	}

	memset(&addrServ,0,sizeof(addrServ));

	addrServ.sin_family=AF_INET;

	addrServ.sin_port=htons(SERVERPORT);
	addrServ.sin_addr.S_un.S_addr=htonl(INADDR_ANY);

	//retVal=connect(sockfd,(struct sockaddr*)&addrServ,sizeof(addrServ));//建立连接
	retVal=bind(sockfd,(struct sockaddr*)&addrServ,sizeof(addrServ));//绑定地址


	if(retVal<0){

		printf("bind error\n");getchar();

		return -1;

	}



	int addrlen=sizeof(sockaddr);

	char buf[100]={0};
	retVal=listen(sockfd,10);

	if(retVal<0){

		printf("listen error\n");getchar();

		return -1;

	}

	SOCKET cilentSocId=accept(sockfd,(sockaddr*)&addrServ,&addrlen);

	if(cilentSocId<0){

		printf("accept error\n");getchar();

		return -1;

	}


	
	h1=::CreateThread(NULL,0,sendMessage,&cilentSocId,0,NULL);//建立子线程

	//::CloseHandle(h1);

	while (true)
	{
		memset(pacLength,0,sizeof(pacLength));
		memset(buf,0,sizeof(buf));

		recv(cilentSocId,pacLength,4,0);

		recv(cilentSocId,buf,atoi(pacLength),0);

		canUseScreen=0;
		printf("%s\n",buf);
		canUseScreen=1;
		

	}
	getchar();

}

//子线程 发送信息;
DWORD WINAPI sendMessage(LPVOID cilentId){

	char sendBuf[100]={0};
	char buf[100]={0};
	int retVal=0;

	SOCKET sockfd=* (SOCKET *)(cilentId);

	while (true)
	{

		memset(buf,0,sizeof(buf));

		memset(sendBuf,0,sizeof(sendBuf));

		//printf("input\n");

		if(canUseScreen==1){
			canUseScreen=0;
			gets(buf);
			canUseScreen=1;
		}
		int len=strlen(buf);

		sprintf(sendBuf,"%4d%s",len,buf);

		//printf("%s\n",sendBuf);

		retVal=send(sockfd,sendBuf,strlen(sendBuf),0);

		if(retVal<0){

			printf("send error\n");

		}

	}

}
