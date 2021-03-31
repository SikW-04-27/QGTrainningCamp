#include "./duLinkedList.h"
#include <stdlib.h>

/**
 *  @name        : Status InitList_DuL(DuLinkedList *L)
 *	@description : initialize an empty linked list with only the head node
 *	@param		 : L(the head node)
 *	@return		 : Status
 *  @notice      : None
 */
Status InitList_DuL(DuLinkedList *L) {
	*L=(DuLinkedList)malloc(sizeof(DuLinkedList));
	if((*L)==NULL){
		printf("链表创建异常！\n\n");
		return ERROR; 
	} 
	printf("链表创建成功！\n\n");
	(*L)->next=NULL;	//找到了就将这个节点的下一个节点指向NULL,确保其只有头结点 
	(*L)->prior=NULL;
	return SUCCESS;
}

/**
 *  @name        : Status AddData(LinkList *L);
 *	@description : initialize an empty linked list with only the head node without value
 *					创建一个只有头结点的链表 
 *	@param		 : L(the head node)
 *	@return		 : Status
 *  @notice      : None
 */
DuLNode* AddData(DuLinkedList *L){
 	int num;
	DuLinkedList p, q;
	int i = 0;
	p = (*L);
	ElemType e;
	printf("请输入节点个数\n");
	scanf("%d",&num); 
	printf("请输入节点数据\n");
	while (i < num) {
		scanf("%d", &e);
		q = (DuLinkedList)malloc(sizeof(DuLNode));
		q->data = e;
		p->next = q;
		q->prior=p;	//与单向链表的区别就是会指向前一个节点 
		p = q;
		i++;
	}
	p->next = NULL;
	*L=(*L)->next;
	return (*L);
}

/**
 *  @name        : void DestroyList_DuL(DuLinkedList *L)
 *	@description : destroy a linked list
 *	@param		 : L(the head node)
 *	@return		 : status
 *  @notice      : None
 */
void DestroyList_DuL(DuLinkedList *L) {
	DuLinkedList p;	//创建一个链表来临时存储删掉每一个节点后的链表 
	while(*L!=NULL){	//链表为空的时候跳出循环 
		p=(*L)->next;
		free(*L);	//每指向一个节点就释放上一个节点 
		*L=p;
	} 
	if(p!=NULL){
		p->prior=NULL;
	}
	printf("链表摧毁成功\n\n");
}

/**
 *  @name        : Status InsertBeforeList_DuL(DuLNode *p, LNode *q)
 *	@description : insert node q before node p
 *	@param		 : p, q
 *	@return		 : status
 *  @notice      : None
 */
Status InsertBeforeList_DuL(DuLNode *p, DuLNode *q) {
	if(p==NULL){
		printf("找无此数据！");
		return ERROR;
	}
	if(p->prior!=NULL){
		p->prior->next=q;	//将节点p后面的链表连接在q后面 
		q->prior=p->prior;
		q->next=p;
		p->prior=q;						
	}		
	
	printf("连接成功"); 
	return SUCCESS; 

}

/**
 *  @name        : Status InsertAfterList_DuL(DuLNode *p, DuLNode *q)
 *	@description : insert node q after node p
 *	@param		 : p, q
 *	@return		 : status
 *  @notice      : None
 */
Status InsertAfterList_DuL(DuLNode *p, DuLNode *q) {
	if(p==NULL){
		printf("找无此数据！");
		return ERROR;
	}
	if(p->next!=NULL){
	 	p->next->prior=q;	//将节点p后面的链表连接在q后面 
	 	q->next=p->next;	
		p->next=q;					
		q->prior=p;
		
	}
	printf("连接成功"); 
	return SUCCESS; 
}

/**
 *  @name        : Status DeleteList_DuL(DuLNode *p, ElemType *e)
 *	@description : delete the first node after the node p and assign its value to e
 *	@param		 : p, e
 *	@return		 : status
 *  @notice      : None
 */
Status DeleteList_DuL(DuLNode *p, ElemType *e) {
	if(p->next==NULL){		//检查p是否为最后一个节点 
		printf("该节点已是最后一个节点");
		return ERROR;
	}
	if(p==NULL){			//检查是否存在p节点 
		printf("该节点不存在");
		return ERROR; 
	}
	DuLNode *q;		//创建一个q节点 
	q=p->next;		//将p后面的链表连接在q后面
	*e=q->data;		//将q的数据传给e 
	p->next=q->next;	//删除p后面的第一个节点 
	free(q);	
	return SUCCESS;
}

/**
 *  @name        : void TraverseList_DuL(DuLinkedList L, void (*visit)(ElemType e))
 *	@description : traverse the linked list and call the funtion visit
 *	@param		 : L(the head node), visit
 *	@return		 : Status
 *  @notice      : None
 */
void TraverseList_DuL(DuLinkedList L, void (*visit)(ElemType e)) {
	DuLNode *p;	//创建一个链表p存储链表L 
	p=L;
	while(p!=NULL){		//判断是不是最后一个节点 
		(*visit)(p->data);	//调用visit函数显示节点中的数据 ,并且不显示第一个空指针的地址 
		
		if(p->next!=NULL){	//判断是否为最后一个节点，不是的话后面才加“-> ” 
			printf("<->");
		}
		p=p->next;		//指向下一个节点 
	}  
}

/**
 *  @name        : visit(ElemType e);
 *	@description : printf date 
 *					打印节点中的date值 
 *	@param		 : ElemType e(the num you deliver)
 *	@return		 : None
 *  @notice      : None
 */
void visit(ElemType e){
	printf("%d",e);
}

/**
 *  @name        : FindNode(LinkedList L, int i)
 *	@description : find the node you want 
 *	@param		 : L(the head node) i(the position you want)
 *	@return		 : LNode
 *  @notice      :None
 */
 
DuLNode* FindNode(DuLinkedList L, int i) {
	int n = 1;
	while(n < i) {
		n++;
		L = L->next;
		if(L==NULL){
			break;
		}
	}
	if (L!=NULL){
		printf("\n已定位至指定位置！\n"); 
		return L;
	}
	else{
		printf("该链表没有这个节点！\n"); 
	}
}

//主界面菜单函数
void menu(){
	printf("---------------------双向链表-----------------------\n");
	printf("--------------创建一个双向链表,输入0----------------\n");
	printf("--------------给创建的双向链表赋值,输入1------------\n");
	printf("--------------摧毁一个双向链表，输入2---------------\n"); 
	printf("--------------插入一个节点(前)，输入3---------------\n");
	printf("--------------插入一个节点(后)，输入4---------------\n"); 
	printf("--------------遍历双向链表，输入5-------------------\n"); 
	printf("--------------退出，输入空格------------------------\n"); 
	
} 
