/*ѧ��ͨѶ¼����ϵͳ:
 1.ѧ����Ϣ����:ѧ�š��������Ա�Ժϵ��רҵ����ϵ�绰;
 2.������ʵ��;
 3.�������ѧ����Ϣ������ѧ����Ϣ(������λ�ò���ѧ����Ϣ),����ѧ����Ϣ(������β������ѧ����Ϣ),
   ɾ��ѧ����Ϣ,����ѧ����Ϣ���޸�ѧ����Ϣ.
*/
#include<stdio.h> 
#include<stdlib.h> 
#include<string.h> 
#include<malloc.h>
typedef struct student_info 
{ 
 char stu_name[15]; 
 long stu_num;
 char stu_sex[10];
 char stu_college[30];
 char stu_profe[30];
 char stu_tel[15];
 struct student_info *next;  
}Student; 
Student *head; /*Ϊȫ�ֱ���*/
Student *load() /*���뺯��,���ļ��ж����ݽ�������*/ 
{  
 FILE *fp;  
 Student *head_1,*p,*q; 
 head_1=NULL; 
 fp=fopen("student","rb"); 
 if(fp==NULL)
 {
  fp=fopen("student","wb");
  fclose(fp);
  return head_1;
 } 
 p=(Student*)malloc(sizeof(Student)); 
 if(fread(p,sizeof(Student),1,fp)!=1)
  return head_1; 
 head_1=p; 
 while(!feof(fp)) 
 {
  q=p; 
  p=(Student*)malloc(sizeof(Student)); 
  fread(p,sizeof(Student),1,fp); 
  q->next=p; 
 } 
 q->next=NULL; 
 free(p); 
 fclose(fp); 
 return head_1; 
} 
int save()  /*���޸ĺ�������е���Ϣ����ļ���*/
{  
 FILE *fp; 
 fp=fopen("student","wb");  
 while(head!=NULL)  
 {
  fwrite(head,sizeof(Student),1,fp); 
  head=head->next; 
 } 
  fclose(fp); 
  return 0; 
 } 
int Add_student() /*���ѧ����Ϣ���� */
{ 
 Student *p,*q; 
 Student *stud1; 
 char flag='y'; 
 stud1=(Student*)malloc(sizeof(Student)); 
 while(flag=='y'||flag=='Y') 
 {
  q=p=head; 
  printf("������Ҫ��ӵ�ѧ��������:\n");
  scanf("%s",stud1->stu_name);
  printf("������Ҫ��ӵ�ѧ����ѧ��(���8λ��):\n");
  scanf("%ld",&stud1->stu_num);
  printf("������Ҫ��ӵ�ѧ�����Ա�:\n");
  scanf("%s",&stud1->stu_sex);
  printf("������Ҫ��ӵ�ѧ����Ժϵ:\n");
  scanf("%s",&stud1->stu_college);
  printf("������Ҫ��ӵ�ѧ����רҵ:\n");
  scanf("%s",&stud1->stu_profe);
  printf("������Ҫ��ӵ�ѧ������ϵ�绰:\n");
  scanf("%s",&stud1->stu_tel);
  stud1->next=NULL; 
  fflush(stdin); 
  if(head==NULL)head=stud1; 
  else
  { 
   while(p->stu_num<stud1->stu_num&&p->next!=NULL)
   {q=p;p=p->next;} 
   if(p->stu_num>stud1->stu_num) 
    if(p==head){stud1->next=head;head=stud1;}  
     else {q->next=stud1;stud1->next=p;} 
   else p->next=stud1; 
  }  
  stud1=(Student*)malloc(sizeof(Student));
  printf("��ӽ���,�Ƿ�������,'y'��'Y'����,�����˳�!\n");  
  flag=getchar(); 
  fflush(stdin); 
 }  
 free(stud1);  
 system("cls"); 
 return 0;  
}  
int del_stu() /*��ѧ��ɾ��ѧ����Ϣ����*/ 
{ 
 Student *p,*q; 
 long stu_num; 
 char flag='y'; 
 int tage=0;  
 while(flag=='y'||flag=='Y') 
 {
  p=head; 
  printf("\ninput the delete student number!\n"); 
  scanf("%d",&stu_num);  
  if(head==NULL){printf("������ѧ����Ϣ!\n");return 0;} 
  while(p!=NULL) 
  {
   if(p->stu_num==stu_num) 
   {
    tage=1; 
    if(p==head)head=head->next; 
    else q->next=p->next; 
    free(p);break; 
   } 
   q=p;p=p->next; 
  } 
  if(tage==0) printf("Ҫɾ����ѧ����Ϣ������!\n"); 
  tage=0; 
  printf("ɾ������,�Ƿ����ɾ������:y��Y����,���߽���!\n"); 
  fflush(stdin); 
  scanf("%c",&flag); 
 } 
 system("cls"); 
 return 0;  
}   
int find_student() /*��ѧ�Ų���ѧ����Ϣ*/
{
 Student *p; 
 char flag='y'; 
 long stu_num; 
 int tage=0; /*1��Ϊ�ҵ�ѧ���ı�־,0Ϊû���ҵ�*/  
  
 while(flag=='y'||flag=='Y') 
 { 
  printf("input the finding student number!\n"); 
  scanf("%d",&stu_num);  
  p=head; 
  if(head==NULL){printf("������ѧ����Ϣ!\n");return 0;} 
  else  
  while(p!=NULL) 
  if(p->stu_num==stu_num)  
  {
   tage=1; 
   printf("��Ҫ���ҵ�ѧ����Ϣ����:\n"); 
   printf("%s\t\t%ld\t\t%s\t\t%s\t%s\t\t%s\t\t\n",p->stu_name,p->stu_num,p->stu_sex,p->stu_college,p->stu_profe,p->stu_tel);   
   break; 
  } 
  
  else p=p->next; 
  if(tage==0)printf("�޸�ѧ����Ϣ!\n"); 
  tage=0; 
  printf("���ҽ���,�Ƿ�������Ҳ���:y��Y����,�����˳�!\n"); 
  fflush(stdin); 
  scanf("%c",&flag); 
 }  
 return 0; 
} 
int ame_student() /*�޸�ѧ����Ϣ*/ 
{ 
 Student *p; 
 long stu_num; 
 int tage=0; 
 int chiose; 
 char flag='y'; 
 printf("input the change student number!\n"); 
 scanf("%ld",&stu_num);  
 p=head; 
 while(flag=='y'||flag=='Y') 
 {
  if(head==NULL){printf("��ѧ����Ϣ����!\n");return 0;}  
  while(p!=NULL) 
  {
   if(p->stu_num==stu_num) 
   {
    tage=1; 
    printf("��ѡҪ�޸ĵı��!\n"); 
    printf("1:<�޸�����>\n"); 
    printf("2:<�޸�ѧ��>\n");
    printf("3:<�޸��Ա�>\n");
    printf("4:<�޸�Ժϵ>\n");
    printf("5:<�޸�רҵ>\n");
    printf("6:<�޸ĵ绰>\n");
    printf("������1-6!else�Ƿ�!\n"); 
    scanf("%d",&chiose); 
    switch(chiose) 
    {
    case 1:
     {
      char stu_name[15]; 
      printf("�������޸ĵ�����!\n"); 
      scanf("%s",stu_name); 
      strcpy(p->stu_name,stu_name); 
      break; 
     } 
    case 2:
     {
      long stu_num; 
      printf("�������޸ĵ�ѧ��!\n"); 
      scanf("%ld",&stu_num); 
      p->stu_num=stu_num; 
      break; 
     } 
    case 3:
     {
      char stu_sex[10];
      printf("�������޸ĵ��Ա�!\n");
      scanf("%s",&stu_sex);
      strcpy(p->stu_sex,stu_sex);
      break;
     }
    case 4:
     {
      char stu_college[30];
      printf("�������޸ĵ�Ժϵ!\n"); 
      scanf("%s",stu_college); 
      strcpy(p->stu_college,stu_college); 
      break; 
     }
    case 5:
     {
      char stu_profe[30];
      printf("�������޸ĵ�רҵ!\n"); 
      scanf("%s",stu_profe); 
      strcpy(p->stu_profe,stu_profe); 
      break; 
     }
    case 6:
     {
      char stu_tel[15];
      printf("�������޸ĵ���ϵ�绰!\n"); 
      scanf("%s",stu_tel); 
      strcpy(p->stu_tel,stu_tel); 
      break; 
     }
    default: {printf("�޴˲���!\n");break;} 
    }break; 
   }  
   else p=p->next; 
  } 
  if(tage==0)printf("�޸�ѧ����Ϣ!\n"); 
   tage=0; 
  printf("�޸Ľ���,�Ƿ�����޸ĸ�ѧ����Ϣ����:y��Y����,�����˳�!\n"); 
  fflush(stdin); 
  scanf("%c",&flag); 
 } 
 fflush(stdin);  
 system("cls"); 
 return 0; 
}  
int print_student() /*���ѧ����Ϣ����*/
{ 
 Student *p; 
 p=head; 
 if(head==NULL){printf("��ѧ����Ϣ!\n");return 0;} 
 printf("����\tѧ��\t�Ա�\tԺϵ\tרҵ\t�绰\t\n"); 
 printf("===========================================================\n"); 
 while(p!=NULL) 
 {
  printf("%s\t%ld\t%s\t%s\t%s\t%s\t\n",p->stu_name,p->stu_num,p->stu_sex,p->stu_college,p->stu_profe,p->stu_tel); 
  p=p->next; 
 } 
 printf("===========================================================\n"); 
 printf("�������!\n"); 
 return 0; 
}  
int main() /*������*/
{ 
 int tage; 
 head=load(); 
 while(1) 
 {  
  printf("\4\4\4\4\4��ӭ����ѧ������ϵͳ!\4\4\4\4\4\n");  
  printf(" 1: ���ѧ����Ϣ\n");  
  printf(" 2: ɾ��ѧ����Ϣ\n");  
  printf(" 3: ����ѧ����Ϣ\n");  
  printf(" 4: �޸�ѧ����Ϣ\n"); 
  printf(" 5: ���ѧ����Ϣ\n"); 
  printf(" 6: �˳�����\n"); 
  printf("\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\n");
  putchar(10); 
  printf("������1-6,��������Ƿ�!\n");  
  scanf("%d",&tage);  
  switch(tage)  
  {  
   case 1:Add_student();break; 
   case 2:del_stu();break; 
   case 3:find_student();break; 
   case 4:ame_student();break;  
   case 5:print_student();break; 
   case 6:save();exit(0);break; 
   default:printf("�޴˲���\n");break;  
  } 
 }  
 }