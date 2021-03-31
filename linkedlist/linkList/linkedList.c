#include "./linkedList.h"
#include <stdlib.h>
#include<stdio.h>

/**
 *  @name        : Status InitList(LinkList *L);
 *	@description : initialize an empty linked list with only the head node without value
 *					创建一个只有头结点的链表 
 *	@param		 : L(the head node)
 *	@return		 : Status
 *  @notice      : None
 */
Status InitList(LinkedList *L) {
	*L=(LinkedList)malloc(sizeof(LinkedList));	//开辟一个空间给L的第一个节点 
	if((*L)==NULL){		//若没找到该空间则返回ERROR 
		printf("链表创建异常！\n\n");
		return ERROR; 
	}
	printf("链表创建成功！\n\n");
	(*L)->next=NULL;	//找到了就将这个节点的下一个节点指向NULL,确保其只有头结点 
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
LNode* AddData(LinkedList *L){
 	int num;
	LinkedList p, q;
	int i = 0;
	p = (*L);
	ElemType e;
	printf("请输入节点个数\n");
	scanf("%d",&num); 
	printf("请输入节点数据\n");
	while (i < num) {
		scanf("%d", &e);
		q = (LinkedList)malloc(sizeof(LNode));
		q->data = e;
		p->next = q;
		p = q;
		i++;
	}
	p->next = NULL;
	*L=(*L)->next;
	return (*L);
}

/**
 *  @name        : void DestroyList(LinkedList *L)
 *	@description : destroy a linked list, free all the nodes
 *					摧毁链表，并释放所有节点 
 *	@param		 : L(the head node)
 *	@return		 : None
 *  @notice      : None
 */
void DestroyList(LinkedList *L) {
	LinkedList p;	//创建一个链表来临时存储删掉每一个节点后的链表 
	while(*L!=NULL){	//链表为空的时候跳出循环 
		p=(*L)->next;
		free(*L);	//每指向一个节点就释放上一个节点 
		*L=p;
	} 
	printf("链表摧毁成功\n\n");
}

/**
 *  @name        : Status InsertList(LNode *p, LNode *q)
 *	@description : insert node q after node p
 *					插入一个节点q在节点p之后 
 *	@param		 : p, q
 *	@return		 : Status
 *  @notice      : None
 */
Status InsertList(LNode *p, LNode *q) {
	//在执行此函数之前需先创建q节点
	 q->next=p->next;	//将节点p后面的链表连接在q后面 
	 p->next=q;			//再将p的下一个节点指向q 
	 printf("连接成功"); 
	 return SUCCESS; 
}
/**
 *  @name        : Status DeleteList(LNode *p, ElemType *e)
 *	@description : delete the first node after the node p and assign its value to e
 *					删除节点p后面的第一个节点并把它的数据分配到e中 
 *	@param		 : p, e
 *	@return		 : Status
 *  @notice      : None
 */
Status DeleteList(LNode *p, ElemType *e) {
	if(p->next==NULL){		//检查p是否为最后一个节点 
		printf("该节点已是最后一个节点");
		return ERROR;
	}
	if(p==NULL){			//检查是否存在p节点 
		printf("该节点不存在");
		return ERROR; 
	}
	LNode *q;		//创建一个q节点 
	q=p->next;		//将p后面的链表连接在q后面
	*e=q->data;		//将q的数据传给e 
	p->next=q->next;	//删除p后面的第一个节点 
	free(q);	
	return SUCCESS;
}

/**
 *  @name        : void TraverseList(LinkedList L, void (*visit)(ElemType e))
 *	@description : traverse the linked list and call the funtion visit
 *					遍历链表，调用visit函数 
 *	@param		 : L(the head node), visit
 *	@return		 : None
 *  @notice      : None
 */
void TraverseList(LinkedList L, void (*visit)(ElemType e)) {
	LNode *p;	//创建一个链表p存储链表L 
	p=L;
	while(p!=NULL){		//判断是不是最后一个节点 
		visit(p->data);	//调用visit函数显示节点中的数据 ,并且不显示第一个空指针的地址 
		
		if(p->next!=NULL){	//判断是否为最后一个节点，不是的话后面才加“-> ” 
			printf("->");
		}
		p=p->next;		//指向下一个节点 
	}  
}

/**
 *  @name        : Status SearchList(LinkedList L, ElemType e)
 *	@description : find the first node in the linked list according to e
 *					查找链表的数据中是否含有e值 
 *	@param		 : L(the head node), e
 *	@return		 : Status
 *  @notice      : None
 */
Status SearchList(LinkedList L, ElemType e) {
	LNode *p;	//创建一个链表p存储链表L 
	p=L;	
	while(p!=NULL){		//遍历链表 
		if(p->data==e){		//查询节点的数据中是否有e值 
			printf("该链表中含有该值！");
			return SUCCESS;		//有则返回SUCCESS 
		}
		p=p->next;		//指向下一个节点 
	} 
	printf("没有找到该要求的节点！");
	return ERROR;		//没有则返回ERROR 
}

/**
 *  @name        : Status ReverseList(LinkedList *L)
 *	@description : reverse the linked list
 *					反转链表 
 *	@param		 : L(the head node)
 *	@return		 : Status
 *  @notice      : None
 */
Status ReverseList(LinkedList *L) {
	if(*L==NULL){		//判断该链表是否存在 
		printf("该链表不存在！\n"); 
		return ERROR;
	}
	if((*L)->next==NULL){		//判断该链表是否只有一个节点 
		printf("该链表只有一个节点，无法反转！\n");
		return ERROR;
	}
	LNode *p1,*p2,*p3;
	p1=(*L);				//将p1指向第一个节点 
	p2=(*L)->next;			//p2指向第二个节点 
	p3=NULL;			//p3指向NULL 
	while(p2!=NULL){	//判断p2指针是否移动到末尾 
		p3=p2->next;	//把p3临时指向p2后面的链表 
		p2->next=p1;	//将p2指向p1 ，完成一个节点箭头的反转 
		p1=p2;			//p1和p2指针后移 
		p2=p3;
	}
	(*L)->next=NULL;		//将头结点反转，指向NULL 
	*L=p1;				//完成链表的反转 
	printf("该链表反转成功！\n");
	return SUCCESS;
}

/**
 *  @name        : Status IsLoopList(LinkedList L)
 *	@description : judge whether the linked list is looped
 *					判断链表是否为循环列表 
 *	@param		 : L(the head node)
 *	@return		 : Status
 *  @notice      : None
 */
Status IsLoopList(LinkedList L) {
	LNode *fast,*slow;	//创建一个快指针和一个慢指针 
	fast=L;
	slow=L;
	while(fast!=NULL&&fast->next!=NULL){	//判断会不会走到头 
		fast=fast->next->next;	//快指针一次运动两个节点 
		slow=slow->next;		//慢指针一次一个节点 
		if(fast==slow){			//如果会相遇，则是循环链表 
			printf("该链表是循环链表！\n") ;
			return SUCCESS;
		}
	}
	printf("该链表不是循环链表！\n"); 
	return ERROR;			//否则则不是循环列表 
	 
}

/**
 *  @name        : LNode* ReverseEvenList(LinkedList *L)
 *	@description : reverse the nodes which value is an even number in the linked list, input: 1 -> 2 -> 3 -> 4  output: 2 -> 1 -> 4 -> 3
 *					反转偶数节点 
 *	@param		 : L(the head node)
 *	@return		 : LNode(the new head node)
 *  @notice      : choose to finish
 */
LNode* ReverseEvenList(LinkedList *L) {
	if((*L)->next==NULL){		//判断该链表是否只有一个节点 
		printf("该链表只有一个节点，无法反转！\n");
		return 0;
	}
	LNode *p1,*p2,*p3;
	p1=(*L);	//p1指向第一个节点 
	p2=p1->next;	//p2指向第二个节点 
	p3=p2->next;	//p3指向第三个节点 
	p1->next=p3;	//把p1的下一个节点指向p3 
	p2->next=p1;	//p2的下一个指向p1，完成前两个的倒序 
	(*L)=p2;		//L指向第二个节点，因为第二个节点反转后为第一个节点 
	while(p3!=NULL&&p3->next!=NULL){	//判断结束 
		p2=p3->next;	
		p3=p2->next;	
		p1->next->next=p3;	//p1的下下个节点指向p3，防止链表断裂 
		p2->next=p1->next;	//将p2下一个元素指向p1的下一个元素 ，完成第二次反转 
		p1->next=p2;	//将p1和p2连起来  
		p1=p2->next;	//p1后移到p2后面 
	} 
	printf("偶数节点反转完成！\n"); 
	return (*L);	//返回反转后的链表 
	
/*	LinkedList p,q,t;
	p=(*L);
	q=p->next;
	t=q->next;
	p->next=t;
	q->next=p;
	(*L)=q;
	while(t!=NULL&&t->next!=NULL){
		q=t->next;
		t=q->next;
		p->next->next=t;
		q->next=p->next;
		p->next=q;
		p=q->next;
	}
	return (*L);*/
}

/**
 *  @name        : LNode* FindMidNode(LinkedList *L)
 *	@description : find the middle node in the linked list
 *					找到链表中的中间节点 
 *	@param		 : L(the head node)
 *	@return		 : LNode
 *  @notice      : choose to finish
 */
LNode* FindMidNode(LinkedList *L) {
	LNode *slow,*fast;
	fast=*L;		//定义快指针和慢指针都在链表头部开始移动 
	slow=*L;
	while(fast->next!=NULL){	//快指针移动到尾部的时候，慢指针刚好在中间，在此时跳出循环 
		if(fast->next->next==NULL){		//判断是否为节点个数是否为偶数 
			printf("这是一个节点个数为偶数的链表!\n");
			break;	
		} 	
		fast=fast->next->next;	//快指针一个移动两个节点 
		slow=slow->next;//慢指针一次移动一个节点 
	}	
	return slow;	//返回中间时刻的指针 
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
LNode* FindNode(LinkedList L, int i) {
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
	printf("----------------------单链表----------------------\n");
	printf("--------------创建一个单链表,输入0----------------\n");
	printf("--------------给创建的单链表赋值,输入1------------\n");
	printf("--------------摧毁一个链表，输入2-----------------\n"); 
	printf("--------------插入一个节点，输入3-----------------\n");
	printf("--------------删除节点，输入4---------------------\n"); 
	printf("--------------遍历链表，输入5---------------------\n"); 
	printf("--------------查找链表中的数据，输入6-------------\n"); 
	printf("--------------反转链表，输入7------------------- -\n"); 
	printf("--------------判断循环链表，输入8-----------------\n"); 
	printf("--------------反转偶数节点 ，输入9----------------\n"); 
	printf("--------------寻找中间节点 ，输入-号--------------\n"); 
	printf("--------------退出 ，输入空格---------------\n"); 
} 
