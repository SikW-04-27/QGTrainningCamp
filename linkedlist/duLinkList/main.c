#include <stdio.h>
//#include "linkedList.h" 
#include "dulinkedList.c"
#include<windows.h> 
#include<conio.h> 
DuLinkedList L=NULL;
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
			InitList_DuL(&L);
			system("pause");
			system("cls");
			menu();
		}
		if(m=='1'){
			if(L==NULL){
				printf("没有创建链表！\n");
			}else{
				AddData(&L);
				TraverseList_DuL(L,visit);
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
				DestroyList_DuL(&L);
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
				DuLinkedList p =FindNode(L,location);
				printf("请输入该节点的数据："); 
				scanf("%d",&newdata);
				DuLinkedList q = (DuLinkedList)malloc(sizeof(DuLNode));
				q->data = newdata;
				if(InsertBeforeList_DuL(p,q)){
					printf("插入成功！\n");
					TraverseList_DuL(L, visit);
					system("pause");
				}else{
					printf("插入失败！\n");
				}
				system("cls");
				menu();
			}
			system("pause");
			system("cls");
			menu();
		}
		
		else if(m=='4'){
			int newdata;
			int location;
			if(L==NULL){
				printf("没有创建链表！\n");
			}
			else{
				printf("请输入要插入的位置:");
				scanf("%d",&location);
				DuLinkedList p =FindNode(L,location);
				printf("请输入该节点的数据："); 
				scanf("%d",&newdata);
				DuLinkedList q = (DuLinkedList)malloc(sizeof(DuLNode));
				q->data = newdata;
				if(InsertAfterList_DuL(p,q)){
					printf("插入成功！\n");
					TraverseList_DuL(L, visit);
					system("pause");
				}else{
					printf("插入失败！\n");
				}
				system("cls");
				menu();
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
				TraverseList_DuL(L,visit);
				system("pause");
				system("cls");
				menu();
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
