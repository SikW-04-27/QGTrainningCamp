#include <stdio.h>
//#include "linkedList.h" 
#include "linkedList.c"
#include<windows.h> 
#include<conio.h> 
LinkedList L=NULL;
char m;
void HideCursor()		//隐藏/显示控制台光标 
{
	HANDLE fd=GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO cinfo;
	cinfo.bVisible=0;
	cinfo.dwSize=1;
	SetConsoleCursorInfo(fd,&cinfo);
 } 
int main(){
	HideCursor();
	menu();
	while(1){
		
		m=getch();	
		if(m=='0'){
			InitList(&L);
			system("pause");
			system("cls");
			menu();
		}
		if(m=='1'){
			if(L==NULL){
				printf("没有创建链表！\n");
			}else{
				AddData(&L);
				TraverseList(L,visit);
				system("pause");
				system("cls");
				menu();
			}
			system("pause");
			system("cls");
			menu();
		}
		else if(m=='2'){
			if(L==NULL){
				printf("没有创建链表！\n");
			}
			else{
				DestroyList(&L);
				system("pause");
				system("cls");
				menu();
			}
			system("pause");
			system("cls");
			menu();
		}
		else if(m=='3'){
			int newdata;
			int location;
			if(L==NULL){
				printf("没有创建链表！\n");
			}
			else{
				printf("请输入要插入的位置:");
				scanf("%d",&location);
				LinkedList p =FindNode(L,location);
				printf("请输入该节点的数据："); 
				scanf("%d",&newdata);
				LinkedList q = (LinkedList)malloc(sizeof(LNode));
				q->data = newdata;
				if(InsertList(p,q)){
					printf("插入成功！\n");
					TraverseList(L, visit);
					system("pause");
				}else{
					printf("插入失败！\n");
				}
				system("cls"); 
				system("pause");
				system("cls");
				menu();
			}
			system("pause");
			system("cls");
			menu();
		}
		else if(m=='4'){
			LinkedList p;
            int location, newdata;
            if(L==NULL){
				printf("没有创建链表！\n");
			}
			else{
				printf("请输入删除的结点：");
            	scanf("%d", &location);
            	p=FindNode(L, location);
            	if(p!=NULL){
            		if (DeleteList(p, &newdata)) {
					printf("结点删除成功！\n");
					printf("该结点的数据为:%d\n", newdata);	
					}else{
						printf("删除失败！\n");
					}
				} 
			}
			system("pause");
			system("cls");
            menu();	
		}
		else if(m=='5'){
			if(L==NULL){
				printf("没有创建链表！\n");
			}
			else{
				TraverseList(L,visit);
				system("pause");
				system("cls");
				menu();
			}
			system("pause");
			system("cls");
			menu();
		}
		else if(m=='6'){
			int searchdata;
			if(L==NULL){
				printf("没有创建链表！\n");
			}
			else{
				printf("请输入要查询的数据：");
				scanf("%d",&searchdata);
				SearchList(L,searchdata); 
				system("pause");
				system("cls");
				menu();
			}
			system("pause");
			system("cls");
			menu();
		}
		else if(m=='7'){
			if(L==NULL){
				printf("没有创建链表！\n");
			}
			else{
				ReverseList(&L);
				printf("反转后的链表为：\n");
				TraverseList(L,visit);
				system("pause");
				system("cls");
				menu();
			}
			system("pause");
			system("cls");
			menu();
		}
		else if(m=='8'){
			if(L==NULL){
				printf("没有创建链表！\n");
			}
			else{
				IsLoopList(*&L);
				system("pause");
				system("cls");
				menu();
			} 
			system("pause");
			system("cls");
			menu();
		}
		else if(m=='9'){
			LinkedList p;
			if(L==NULL){
				printf("没有创建链表！\n");
			}
			else{
				p=ReverseEvenList(&L);
				TraverseList(p,visit);
				
			}
			system("pause");
			system("cls");
			menu();
		}	
		else if(m=='-'){
			LNode *p;
			if(L==NULL){
				printf("没有创建链表！\n");
			}
			else{
				p=FindMidNode(&L);
				
				if(p!=NULL){
					printf("中间节点为%d\n",p->data);	
				}
			}
			system("pause");
			system("cls");
			menu();
		}
		else if(m==' '){
			break;
		} 
		
	}
	
	
}
