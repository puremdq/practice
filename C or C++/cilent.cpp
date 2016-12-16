#include<stdio.h>
#include<Windows.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h>
#include<winsock.h>

#pragma comment(lib,"wsock32.lib")

DWORD WINAPI receiveMessage(LPVOID);
int canUseScreen=1;
#define SERVERPORT 5000
int main(){


	struct sockaddr_in addrServ;//ip 结构体

	char sendBuf[100]={0};
	char buf[100]={0};
	HANDLE h1;


	// windows need
	WORD wVersionRequested;
	WSADATA wsaData;
	int retVal;
	int sockfd;

	wVersionRequested=MAKEWORD(1,1);
	retVal=WSAStartup(wVersionRequested,(LPWSADATA)&wsaData);

	if(retVal!=0){

		printf("error\n");

		return -1;


	}
	//end windows need


	sockfd=socket(AF_INET,SOCK_STREAM,0);//初始化一个socket


	if(sockfd<0){

		printf("socket error\n");

		return -1;

	}

	memset(&addrServ,0,sizeof(addrServ));

	addrServ.sin_family=AF_INET;

	addrServ.sin_port=htons(SERVERPORT);
	addrServ.sin_addr.S_un.S_addr=inet_addr("127.0.0.1");

	retVal=connect(sockfd,(struct sockaddr*)&addrServ,sizeof(addrServ));//建立连接


	if(retVal<0){

		printf("connect error\n");

		return -1;

	}

	
	h1=::CreateThread(NULL,0,receiveMessage,&sockfd,0,NULL);//建立子线程 //::CloseHandle(h1);

	while (true)
	{

		memset(buf,0,sizeof(buf));


		memset(sendBuf,0,sizeof(sendBuf));

		if(canUseScreen==1){
			canUseScreen=0;
			//printf("input\n");
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

	getchar();


}

//h1=::CreateThread(NULL,0,sendMessage,&cilentSocId,0,NULL);//建立子线程

//子线程 接受信息;
DWORD WINAPI receiveMessage(LPVOID serverId){

	char pacLength[5]={0};
	char buf[100]={0};
	int retVal=0;

	SOCKET sockfd=* (SOCKET *)(serverId);

	while (true)
	{
		memset(pacLength,0,sizeof(pacLength));
		memset(buf,0,sizeof(buf));

		retVal=recv(sockfd,pacLength,4,0);
		retVal=recv(sockfd,buf,atoi(pacLength),0);

		if(retVal<0){

			printf("客户端不能正常接收\n");

		}else{

				canUseScreen=0;
				printf("%s\n",buf);
				canUseScreen=1;

		}

	}

}