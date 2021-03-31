#include "./linkedList.h"
#include <stdlib.h>
#include<stdio.h>

/**
 *  @name        : Status InitList(LinkList *L);
 *	@description : initialize an empty linked list with only the head node without value
 *					����һ��ֻ��ͷ�������� 
 *	@param		 : L(the head node)
 *	@return		 : Status
 *  @notice      : None
 */
Status InitList(LinkedList *L) {
	*L=(LinkedList)malloc(sizeof(LinkedList));	//����һ���ռ��L�ĵ�һ���ڵ� 
	if((*L)==NULL){		//��û�ҵ��ÿռ��򷵻�ERROR 
		printf("�������쳣��\n\n");
		return ERROR; 
	}
	printf("�������ɹ���\n\n");
	(*L)->next=NULL;	//�ҵ��˾ͽ�����ڵ����һ���ڵ�ָ��NULL,ȷ����ֻ��ͷ��� 
	return SUCCESS;
	
}

/**
 *  @name        : Status AddData(LinkList *L);
 *	@description : initialize an empty linked list with only the head node without value
 *					����һ��ֻ��ͷ�������� 
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
	printf("������ڵ����\n");
	scanf("%d",&num); 
	printf("������ڵ�����\n");
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
 *					�ݻ��������ͷ����нڵ� 
 *	@param		 : L(the head node)
 *	@return		 : None
 *  @notice      : None
 */
void DestroyList(LinkedList *L) {
	LinkedList p;	//����һ����������ʱ�洢ɾ��ÿһ���ڵ������� 
	while(*L!=NULL){	//����Ϊ�յ�ʱ������ѭ�� 
		p=(*L)->next;
		free(*L);	//ÿָ��һ���ڵ���ͷ���һ���ڵ� 
		*L=p;
	} 
	printf("����ݻٳɹ�\n\n");
}

/**
 *  @name        : Status InsertList(LNode *p, LNode *q)
 *	@description : insert node q after node p
 *					����һ���ڵ�q�ڽڵ�p֮�� 
 *	@param		 : p, q
 *	@return		 : Status
 *  @notice      : None
 */
Status InsertList(LNode *p, LNode *q) {
	//��ִ�д˺���֮ǰ���ȴ���q�ڵ�
	 q->next=p->next;	//���ڵ�p���������������q���� 
	 p->next=q;			//�ٽ�p����һ���ڵ�ָ��q 
	 printf("���ӳɹ�"); 
	 return SUCCESS; 
}
/**
 *  @name        : Status DeleteList(LNode *p, ElemType *e)
 *	@description : delete the first node after the node p and assign its value to e
 *					ɾ���ڵ�p����ĵ�һ���ڵ㲢���������ݷ��䵽e�� 
 *	@param		 : p, e
 *	@return		 : Status
 *  @notice      : None
 */
Status DeleteList(LNode *p, ElemType *e) {
	if(p->next==NULL){		//���p�Ƿ�Ϊ���һ���ڵ� 
		printf("�ýڵ��������һ���ڵ�");
		return ERROR;
	}
	if(p==NULL){			//����Ƿ����p�ڵ� 
		printf("�ýڵ㲻����");
		return ERROR; 
	}
	LNode *q;		//����һ��q�ڵ� 
	q=p->next;		//��p���������������q����
	*e=q->data;		//��q�����ݴ���e 
	p->next=q->next;	//ɾ��p����ĵ�һ���ڵ� 
	free(q);	
	return SUCCESS;
}

/**
 *  @name        : void TraverseList(LinkedList L, void (*visit)(ElemType e))
 *	@description : traverse the linked list and call the funtion visit
 *					������������visit���� 
 *	@param		 : L(the head node), visit
 *	@return		 : None
 *  @notice      : None
 */
void TraverseList(LinkedList L, void (*visit)(ElemType e)) {
	LNode *p;	//����һ������p�洢����L 
	p=L;
	while(p!=NULL){		//�ж��ǲ������һ���ڵ� 
		visit(p->data);	//����visit������ʾ�ڵ��е����� ,���Ҳ���ʾ��һ����ָ��ĵ�ַ 
		
		if(p->next!=NULL){	//�ж��Ƿ�Ϊ���һ���ڵ㣬���ǵĻ�����żӡ�-> �� 
			printf("->");
		}
		p=p->next;		//ָ����һ���ڵ� 
	}  
}

/**
 *  @name        : Status SearchList(LinkedList L, ElemType e)
 *	@description : find the first node in the linked list according to e
 *					����������������Ƿ���eֵ 
 *	@param		 : L(the head node), e
 *	@return		 : Status
 *  @notice      : None
 */
Status SearchList(LinkedList L, ElemType e) {
	LNode *p;	//����һ������p�洢����L 
	p=L;	
	while(p!=NULL){		//�������� 
		if(p->data==e){		//��ѯ�ڵ���������Ƿ���eֵ 
			printf("�������к��и�ֵ��");
			return SUCCESS;		//���򷵻�SUCCESS 
		}
		p=p->next;		//ָ����һ���ڵ� 
	} 
	printf("û���ҵ���Ҫ��Ľڵ㣡");
	return ERROR;		//û���򷵻�ERROR 
}

/**
 *  @name        : Status ReverseList(LinkedList *L)
 *	@description : reverse the linked list
 *					��ת���� 
 *	@param		 : L(the head node)
 *	@return		 : Status
 *  @notice      : None
 */
Status ReverseList(LinkedList *L) {
	if(*L==NULL){		//�жϸ������Ƿ���� 
		printf("���������ڣ�\n"); 
		return ERROR;
	}
	if((*L)->next==NULL){		//�жϸ������Ƿ�ֻ��һ���ڵ� 
		printf("������ֻ��һ���ڵ㣬�޷���ת��\n");
		return ERROR;
	}
	LNode *p1,*p2,*p3;
	p1=(*L);				//��p1ָ���һ���ڵ� 
	p2=(*L)->next;			//p2ָ��ڶ����ڵ� 
	p3=NULL;			//p3ָ��NULL 
	while(p2!=NULL){	//�ж�p2ָ���Ƿ��ƶ���ĩβ 
		p3=p2->next;	//��p3��ʱָ��p2��������� 
		p2->next=p1;	//��p2ָ��p1 �����һ���ڵ��ͷ�ķ�ת 
		p1=p2;			//p1��p2ָ����� 
		p2=p3;
	}
	(*L)->next=NULL;		//��ͷ��㷴ת��ָ��NULL 
	*L=p1;				//�������ķ�ת 
	printf("������ת�ɹ���\n");
	return SUCCESS;
}

/**
 *  @name        : Status IsLoopList(LinkedList L)
 *	@description : judge whether the linked list is looped
 *					�ж������Ƿ�Ϊѭ���б� 
 *	@param		 : L(the head node)
 *	@return		 : Status
 *  @notice      : None
 */
Status IsLoopList(LinkedList L) {
	LNode *fast,*slow;	//����һ����ָ���һ����ָ�� 
	fast=L;
	slow=L;
	while(fast!=NULL&&fast->next!=NULL){	//�жϻ᲻���ߵ�ͷ 
		fast=fast->next->next;	//��ָ��һ���˶������ڵ� 
		slow=slow->next;		//��ָ��һ��һ���ڵ� 
		if(fast==slow){			//���������������ѭ������ 
			printf("��������ѭ������\n") ;
			return SUCCESS;
		}
	}
	printf("��������ѭ������\n"); 
	return ERROR;			//��������ѭ���б� 
	 
}

/**
 *  @name        : LNode* ReverseEvenList(LinkedList *L)
 *	@description : reverse the nodes which value is an even number in the linked list, input: 1 -> 2 -> 3 -> 4  output: 2 -> 1 -> 4 -> 3
 *					��תż���ڵ� 
 *	@param		 : L(the head node)
 *	@return		 : LNode(the new head node)
 *  @notice      : choose to finish
 */
LNode* ReverseEvenList(LinkedList *L) {
	if((*L)->next==NULL){		//�жϸ������Ƿ�ֻ��һ���ڵ� 
		printf("������ֻ��һ���ڵ㣬�޷���ת��\n");
		return 0;
	}
	LNode *p1,*p2,*p3;
	p1=(*L);	//p1ָ���һ���ڵ� 
	p2=p1->next;	//p2ָ��ڶ����ڵ� 
	p3=p2->next;	//p3ָ��������ڵ� 
	p1->next=p3;	//��p1����һ���ڵ�ָ��p3 
	p2->next=p1;	//p2����һ��ָ��p1�����ǰ�����ĵ��� 
	(*L)=p2;		//Lָ��ڶ����ڵ㣬��Ϊ�ڶ����ڵ㷴ת��Ϊ��һ���ڵ� 
	while(p3!=NULL&&p3->next!=NULL){	//�жϽ��� 
		p2=p3->next;	
		p3=p2->next;	
		p1->next->next=p3;	//p1�����¸��ڵ�ָ��p3����ֹ������� 
		p2->next=p1->next;	//��p2��һ��Ԫ��ָ��p1����һ��Ԫ�� ����ɵڶ��η�ת 
		p1->next=p2;	//��p1��p2������  
		p1=p2->next;	//p1���Ƶ�p2���� 
	} 
	printf("ż���ڵ㷴ת��ɣ�\n"); 
	return (*L);	//���ط�ת������� 
	
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
 *					�ҵ������е��м�ڵ� 
 *	@param		 : L(the head node)
 *	@return		 : LNode
 *  @notice      : choose to finish
 */
LNode* FindMidNode(LinkedList *L) {
	LNode *slow,*fast;
	fast=*L;		//�����ָ�����ָ�붼������ͷ����ʼ�ƶ� 
	slow=*L;
	while(fast->next!=NULL){	//��ָ���ƶ���β����ʱ����ָ��պ����м䣬�ڴ�ʱ����ѭ�� 
		if(fast->next->next==NULL){		//�ж��Ƿ�Ϊ�ڵ�����Ƿ�Ϊż�� 
			printf("����һ���ڵ����Ϊż��������!\n");
			break;	
		} 	
		fast=fast->next->next;	//��ָ��һ���ƶ������ڵ� 
		slow=slow->next;//��ָ��һ���ƶ�һ���ڵ� 
	}	
	return slow;	//�����м�ʱ�̵�ָ�� 
}

/**
 *  @name        : visit(ElemType e);
 *	@description : printf date 
 *					��ӡ�ڵ��е�dateֵ 
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
		printf("\n�Ѷ�λ��ָ��λ�ã�\n"); 
		return L;
	}
	else{
		printf("������û������ڵ㣡\n"); 
	}
}

//������˵�����
void menu(){
	printf("----------------------������----------------------\n");
	printf("--------------����һ��������,����0----------------\n");
	printf("--------------�������ĵ�����ֵ,����1------------\n");
	printf("--------------�ݻ�һ����������2-----------------\n"); 
	printf("--------------����һ���ڵ㣬����3-----------------\n");
	printf("--------------ɾ���ڵ㣬����4---------------------\n"); 
	printf("--------------������������5---------------------\n"); 
	printf("--------------���������е����ݣ�����6-------------\n"); 
	printf("--------------��ת��������7------------------- -\n"); 
	printf("--------------�ж�ѭ����������8-----------------\n"); 
	printf("--------------��תż���ڵ� ������9----------------\n"); 
	printf("--------------Ѱ���м�ڵ� ������-��--------------\n"); 
	printf("--------------�˳� ������ո�---------------\n"); 
} 
