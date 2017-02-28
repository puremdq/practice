#include<stdio.h>
#include<malloc.h>
#define MAXLENGTH 4

//邻接表节点（表示图某个点到另一点的边）
struct ArcNode{
	int adjvex;//指向的位置
	ArcNode * nextArc;
};

//头节点（表示图的某个点）
struct VNode{
	
	char data;//数据
	struct ArcNode * firstArc;

};


void initGra(struct VNode *Adlist){
	int pointTo=0;int flag=0;
	ArcNode *currentNode=NULL;
	struct ArcNode *pnode=NULL;
	for(int i=0;i<MAXLENGTH;i++){
		flag=0;Adlist[i].firstArc=NULL;
		
		printf("input the value of node %d\n",i+1);

		fflush(stdin);
		Adlist[i].data=getchar();

		
		printf("input the node %c point to end of '#'\n",Adlist[i].data);
		fflush(stdin);
		pointTo=getchar();
		while(pointTo!='#'){
	
			pnode=(struct ArcNode *)malloc(sizeof(struct ArcNode));	

			pnode->adjvex=pointTo-'0';//指向;
			pnode->nextArc=NULL;

			if(flag==0){
			
				Adlist[i].firstArc=pnode;
				currentNode=pnode;
				flag=1;
			
			}else{
				currentNode->nextArc=pnode;
				currentNode=pnode;
			}

				printf("input the node %c point to end of '#'\n",Adlist[i].data);
				fflush(stdin);
				pointTo=getchar();
		
		}

	}


	for(int i=0;i<MAXLENGTH;i++){
	
		printf("node %c point to: ",Adlist[i].data);

		currentNode=Adlist[i].firstArc;
		while(currentNode!=NULL){
		
			printf("%d  ",currentNode->adjvex);
			currentNode=currentNode->nextArc;
		}
		printf("\n\n");
	}
getchar();
}

int main(){


	struct VNode Adlist[MAXLENGTH];
	initGra(Adlist);
	getchar();
	return 0;

}
