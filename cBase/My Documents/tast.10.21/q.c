/*学生通讯录管理系统:
 1.学生信息包括:学号、姓名、性别、院系、专业和联系电话;
 2.用链表实现;
 3.可以浏览学生信息，插入学生信息(在任意位置插入学生信息),新增学生信息(在链表尾部新增学生信息),
   删除学生信息,查找学生信息和修改学生信息.
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
Student *head; /*为全局变量*/
Student *load() /*载入函数,从文件中读数据建立链表*/ 
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
int save()  /*将修改后的链表中的信息存进文件中*/
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
int Add_student() /*添加学生信息函数 */
{ 
 Student *p,*q; 
 Student *stud1; 
 char flag='y'; 
 stud1=(Student*)malloc(sizeof(Student)); 
 while(flag=='y'||flag=='Y') 
 {
  q=p=head; 
  printf("请输入要添加的学生的姓名:\n");
  scanf("%s",stud1->stu_name);
  printf("请输入要添加的学生的学号(最多8位数):\n");
  scanf("%ld",&stud1->stu_num);
  printf("请输入要添加的学生的性别:\n");
  scanf("%s",&stud1->stu_sex);
  printf("请输入要添加的学生的院系:\n");
  scanf("%s",&stud1->stu_college);
  printf("请输入要添加的学生的专业:\n");
  scanf("%s",&stud1->stu_profe);
  printf("请输入要添加的学生的联系电话:\n");
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
  printf("添加结束,是否继续添加,'y'或'Y'继续,否者退出!\n");  
  flag=getchar(); 
  fflush(stdin); 
 }  
 free(stud1);  
 system("cls"); 
 return 0;  
}  
int del_stu() /*按学号删除学生信息函数*/ 
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
  if(head==NULL){printf("不存在学生信息!\n");return 0;} 
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
  if(tage==0) printf("要删除的学生信息不存在!\n"); 
  tage=0; 
  printf("删除结束,是否继续删除操作:y或Y继续,否者结束!\n"); 
  fflush(stdin); 
  scanf("%c",&flag); 
 } 
 system("cls"); 
 return 0;  
}   
int find_student() /*按学号查找学生信息*/
{
 Student *p; 
 char flag='y'; 
 long stu_num; 
 int tage=0; /*1作为找到学生的标志,0为没有找到*/  
  
 while(flag=='y'||flag=='Y') 
 { 
  printf("input the finding student number!\n"); 
  scanf("%d",&stu_num);  
  p=head; 
  if(head==NULL){printf("不存在学生信息!\n");return 0;} 
  else  
  while(p!=NULL) 
  if(p->stu_num==stu_num)  
  {
   tage=1; 
   printf("你要查找的学生信息如下:\n"); 
   printf("%s\t\t%ld\t\t%s\t\t%s\t%s\t\t%s\t\t\n",p->stu_name,p->stu_num,p->stu_sex,p->stu_college,p->stu_profe,p->stu_tel);   
   break; 
  } 
  
  else p=p->next; 
  if(tage==0)printf("无该学生信息!\n"); 
  tage=0; 
  printf("查找结束,是否继续查找操作:y或Y继续,否者退出!\n"); 
  fflush(stdin); 
  scanf("%c",&flag); 
 }  
 return 0; 
} 
int ame_student() /*修改学生信息*/ 
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
  if(head==NULL){printf("无学生信息存在!\n");return 0;}  
  while(p!=NULL) 
  {
   if(p->stu_num==stu_num) 
   {
    tage=1; 
    printf("请选要修改的编号!\n"); 
    printf("1:<修改姓名>\n"); 
    printf("2:<修改学号>\n");
    printf("3:<修改性别>\n");
    printf("4:<修改院系>\n");
    printf("5:<修改专业>\n");
    printf("6:<修改电话>\n");
    printf("请输入1-6!else非法!\n"); 
    scanf("%d",&chiose); 
    switch(chiose) 
    {
    case 1:
     {
      char stu_name[15]; 
      printf("请输入修改的名字!\n"); 
      scanf("%s",stu_name); 
      strcpy(p->stu_name,stu_name); 
      break; 
     } 
    case 2:
     {
      long stu_num; 
      printf("请输入修改的学号!\n"); 
      scanf("%ld",&stu_num); 
      p->stu_num=stu_num; 
      break; 
     } 
    case 3:
     {
      char stu_sex[10];
      printf("请输入修改的性别!\n");
      scanf("%s",&stu_sex);
      strcpy(p->stu_sex,stu_sex);
      break;
     }
    case 4:
     {
      char stu_college[30];
      printf("请输入修改的院系!\n"); 
      scanf("%s",stu_college); 
      strcpy(p->stu_college,stu_college); 
      break; 
     }
    case 5:
     {
      char stu_profe[30];
      printf("请输入修改的专业!\n"); 
      scanf("%s",stu_profe); 
      strcpy(p->stu_profe,stu_profe); 
      break; 
     }
    case 6:
     {
      char stu_tel[15];
      printf("请输入修改的联系电话!\n"); 
      scanf("%s",stu_tel); 
      strcpy(p->stu_tel,stu_tel); 
      break; 
     }
    default: {printf("无此操作!\n");break;} 
    }break; 
   }  
   else p=p->next; 
  } 
  if(tage==0)printf("无该学生信息!\n"); 
   tage=0; 
  printf("修改结束,是否继续修改该学生信息操作:y或Y继续,否者退出!\n"); 
  fflush(stdin); 
  scanf("%c",&flag); 
 } 
 fflush(stdin);  
 system("cls"); 
 return 0; 
}  
int print_student() /*输出学生信息函数*/
{ 
 Student *p; 
 p=head; 
 if(head==NULL){printf("无学生信息!\n");return 0;} 
 printf("姓名\t学号\t性别\t院系\t专业\t电话\t\n"); 
 printf("===========================================================\n"); 
 while(p!=NULL) 
 {
  printf("%s\t%ld\t%s\t%s\t%s\t%s\t\n",p->stu_name,p->stu_num,p->stu_sex,p->stu_college,p->stu_profe,p->stu_tel); 
  p=p->next; 
 } 
 printf("===========================================================\n"); 
 printf("输出结束!\n"); 
 return 0; 
}  
int main() /*主函数*/
{ 
 int tage; 
 head=load(); 
 while(1) 
 {  
  printf("\4\4\4\4\4欢迎进入学生管理系统!\4\4\4\4\4\n");  
  printf(" 1: 添加学生信息\n");  
  printf(" 2: 删除学生信息\n");  
  printf(" 3: 查找学生信息\n");  
  printf(" 4: 修改学生信息\n"); 
  printf(" 5: 输出学生信息\n"); 
  printf(" 6: 退出程序\n"); 
  printf("\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\n");
  putchar(10); 
  printf("请输入1-6,其他输入非法!\n");  
  scanf("%d",&tage);  
  switch(tage)  
  {  
   case 1:Add_student();break; 
   case 2:del_stu();break; 
   case 3:find_student();break; 
   case 4:ame_student();break;  
   case 5:print_student();break; 
   case 6:save();exit(0);break; 
   default:printf("无此操作\n");break;  
  } 
 }  
 }