#include <stdio.h>
//#include "linkedList.h" 
#include "linkedList.c"
#include<windows.h> 
#include<conio.h> 
LinkedList L=NULL;
char m;
void HideCursor()		//����/��ʾ����̨��� 
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
				printf("û�д�������\n");
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
				printf("û�д�������\n");
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
				printf("û�д�������\n");
			}
			else{
				printf("������Ҫ�����λ��:");
				scanf("%d",&location);
				LinkedList p =FindNode(L,location);
				printf("������ýڵ�����ݣ�"); 
				scanf("%d",&newdata);
				LinkedList q = (LinkedList)malloc(sizeof(LNode));
				q->data = newdata;
				if(InsertList(p,q)){
					printf("����ɹ���\n");
					TraverseList(L, visit);
					system("pause");
				}else{
					printf("����ʧ�ܣ�\n");
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
				printf("û�д�������\n");
			}
			else{
				printf("������ɾ���Ľ�㣺");
            	scanf("%d", &location);
            	p=FindNode(L, location);
            	if(p!=NULL){
            		if (DeleteList(p, &newdata)) {
					printf("���ɾ���ɹ���\n");
					printf("�ý�������Ϊ:%d\n", newdata);	
					}else{
						printf("ɾ��ʧ�ܣ�\n");
					}
				} 
			}
			system("pause");
			system("cls");
            menu();	
		}
		else if(m=='5'){
			if(L==NULL){
				printf("û�д�������\n");
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
				printf("û�д�������\n");
			}
			else{
				printf("������Ҫ��ѯ�����ݣ�");
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
				printf("û�д�������\n");
			}
			else{
				ReverseList(&L);
				printf("��ת�������Ϊ��\n");
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
				printf("û�д�������\n");
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
				printf("û�д�������\n");
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
				printf("û�д�������\n");
			}
			else{
				p=FindMidNode(&L);
				
				if(p!=NULL){
					printf("�м�ڵ�Ϊ%d\n",p->data);	
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
