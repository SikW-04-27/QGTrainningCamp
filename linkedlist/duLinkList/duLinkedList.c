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
		printf("�������쳣��\n\n");
		return ERROR; 
	} 
	printf("�������ɹ���\n\n");
	(*L)->next=NULL;	//�ҵ��˾ͽ�����ڵ����һ���ڵ�ָ��NULL,ȷ����ֻ��ͷ��� 
	(*L)->prior=NULL;
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
DuLNode* AddData(DuLinkedList *L){
 	int num;
	DuLinkedList p, q;
	int i = 0;
	p = (*L);
	ElemType e;
	printf("������ڵ����\n");
	scanf("%d",&num); 
	printf("������ڵ�����\n");
	while (i < num) {
		scanf("%d", &e);
		q = (DuLinkedList)malloc(sizeof(DuLNode));
		q->data = e;
		p->next = q;
		q->prior=p;	//�뵥�������������ǻ�ָ��ǰһ���ڵ� 
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
	DuLinkedList p;	//����һ����������ʱ�洢ɾ��ÿһ���ڵ������� 
	while(*L!=NULL){	//����Ϊ�յ�ʱ������ѭ�� 
		p=(*L)->next;
		free(*L);	//ÿָ��һ���ڵ���ͷ���һ���ڵ� 
		*L=p;
	} 
	if(p!=NULL){
		p->prior=NULL;
	}
	printf("����ݻٳɹ�\n\n");
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
		printf("���޴����ݣ�");
		return ERROR;
	}
	if(p->prior!=NULL){
		p->prior->next=q;	//���ڵ�p���������������q���� 
		q->prior=p->prior;
		q->next=p;
		p->prior=q;						
	}		
	
	printf("���ӳɹ�"); 
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
		printf("���޴����ݣ�");
		return ERROR;
	}
	if(p->next!=NULL){
	 	p->next->prior=q;	//���ڵ�p���������������q���� 
	 	q->next=p->next;	
		p->next=q;					
		q->prior=p;
		
	}
	printf("���ӳɹ�"); 
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
	if(p->next==NULL){		//���p�Ƿ�Ϊ���һ���ڵ� 
		printf("�ýڵ��������һ���ڵ�");
		return ERROR;
	}
	if(p==NULL){			//����Ƿ����p�ڵ� 
		printf("�ýڵ㲻����");
		return ERROR; 
	}
	DuLNode *q;		//����һ��q�ڵ� 
	q=p->next;		//��p���������������q����
	*e=q->data;		//��q�����ݴ���e 
	p->next=q->next;	//ɾ��p����ĵ�һ���ڵ� 
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
	DuLNode *p;	//����һ������p�洢����L 
	p=L;
	while(p!=NULL){		//�ж��ǲ������һ���ڵ� 
		(*visit)(p->data);	//����visit������ʾ�ڵ��е����� ,���Ҳ���ʾ��һ����ָ��ĵ�ַ 
		
		if(p->next!=NULL){	//�ж��Ƿ�Ϊ���һ���ڵ㣬���ǵĻ�����żӡ�-> �� 
			printf("<->");
		}
		p=p->next;		//ָ����һ���ڵ� 
	}  
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
		printf("\n�Ѷ�λ��ָ��λ�ã�\n"); 
		return L;
	}
	else{
		printf("������û������ڵ㣡\n"); 
	}
}

//������˵�����
void menu(){
	printf("---------------------˫������-----------------------\n");
	printf("--------------����һ��˫������,����0----------------\n");
	printf("--------------��������˫������ֵ,����1------------\n");
	printf("--------------�ݻ�һ��˫����������2---------------\n"); 
	printf("--------------����һ���ڵ�(ǰ)������3---------------\n");
	printf("--------------����һ���ڵ�(��)������4---------------\n"); 
	printf("--------------����˫����������5-------------------\n"); 
	printf("--------------�˳�������ո�------------------------\n"); 
	
} 
