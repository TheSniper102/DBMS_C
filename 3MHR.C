/**

allowed operations 
select * from std 
select * from dept 
select any column from any table 
delete from any table 
delete from any table where condition id = value 
update by any column
insert into table name values (all columns)
open file and save data
**/

#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>
#define blink 0x70+BLINK
#define enter 13
#define up 72
#define down 80
#define escape 27
struct Dept
{
	int did;
	char dname[10];
	struct Dept * prev;
	struct Dept * next;
};
struct std
{
	int id;
	char name[20];
	char phone[10];
	char address[10];
	int deptId;
	struct std * prev;
	struct std * next;
};

struct std * head=NULL;
struct std * tail=NULL;
struct Dept * headDept=NULL;
struct Dept * tailDept=NULL;

void append(struct std * temp);


void appendDp(struct Dept * temp);
void printall(int student);
void crud(char* str);
struct std*  createStudent(int id,char* name,int deptId,char* phone,char* address);
struct Dept* createnodeDp(int id, char * name) ;
struct std* searchBySName(char s[] );

int deleteBySId(int id);   //std
int deleteDept(char* n, int id) ;

void delletealldept() ;
void delleteallstd() ;
char * moveNext(char * pch, int * index,char delmeter[],int * legal);
struct std* searchBySName(char s[] );
struct std* searchBySId(int id);
struct std* searchBySdept(int did);
struct Dept* searchByName(char s[] );
struct Dept* searchById(int id);
int Update(int id,char* name,int deptId,char* phone, char* address);
int UpdateDept(int id,char* name);

char * del(char *src, char ch);
void openFile(int student,int disp);
void saveFile(int student);
char * rmvchar(char * pch, char character);
int  chkchar(char * pch, char character,int lastPosition ,int left, int right);
void  printsel(int id,char* name,int deptId,char* phone,char* address,int searchId,int all);
  void  printdepart(int id,char* name,int searchId,int all);
void  printsels(int id,char* name,int deptId,char* phone,char* address,int searchId);
//void printJoin(int id,char* name,char dname[],char* phone,char* address,int searchId);
void show_message(char * message, int erro);
void selection_sort (int n);
void depart_sort ( int n );
int deleteSetting(int departId);
int count (struct std * q);
int del_setting=1;
int appended = 0;
//int query(char operation[], char * stmt, int * index, char delmeter[]);
int main()
{
	char * str;
	struct std* temp;
   int i,pos=0,flag=0,j,pos2=0,pos3=0,flag2=0,k;
   char ch;
   char name[6][30]={"Delete Settings","Run sql quary","Open student file","Open department file","About Us","Exit"};
   char names[2][10]={"No","Save"};
   char named[4][15]={"Cascade","NO ACTION","Set Null","Restrict"};
   clrscr();
   
   openFile(1,0);
   openFile(0,0);
   appended=1;
	do{
   clrscr();
		for(i=0;i<6;i++)
		{
		   gotoxy(30,i+5);
			if(i==pos)
				textattr(blink);
			cprintf("\n%s",name[i]);
			textattr(0x07);
		}
		ch=getch();
		switch (ch)
		{
			case escape:
				flag=1;
			break;
			case enter:
				switch (pos)
				{
					case 0:
					do{
						clrscr();
						for(k=0;k<4;k++)
						{
							gotoxy(30,i=k+5);
							if(k==pos3)
							textattr(blink);
							cprintf("\n%s",named[k]);
							textattr(0x07);
						}
						ch=getch();
						switch (ch)
						{
							case enter:
								switch (pos3)
								{
									case 0:
										del_setting=1;
										flag2=1;
											
										ch=getch();
									break;
									case 1:
										del_setting=2;
										flag2=1;
											
										ch=getch();
									break;
									case 2:
										del_setting=3;
										flag2=1;
										
										
										ch=getch();
									break;
									case 3:
										del_setting=4;
										flag2=1;
											
										
										ch=getch();
									break;
								}
							break;
							case NULL:
								ch=getch();
								switch (ch)
								{
									case up:
										pos3--;
										if(pos3<0)
											pos3=3;
									break;
									case down:
										pos3++;
										if(pos3>3)
											pos3=0;
									break;
								}
							break;
						}
					}while(flag2==0);
					break;
					case 1:
						clrscr();
						printf("\n please enter sql command.....\n");
						flushall();
						gets(str);
						crud(str);
						getch();
					break;
					case 2:
						clrscr();
						openFile(1,1);
						getch();
					break;
					case 3:
						clrscr();
						openFile(0,1);
						getch();
					break;
					case 4:
						clrscr();
						gotoxy(30,5);
						printf("\nDesinged By:");
						printf("\nMohamed Abd El-Rahhman");
						printf("\nMohamed Mohamed Kiwan");
						printf("\nMohamed Hosni");
						printf("\nHusein Rezk");
						printf("\nRagaey Mohamed");
                        //printsels(1, "name",3,"phone","address",3);

						getch();
					break;
					case 5:		//exit
						do{
							clrscr();
							gotoxy(30,8);
							printf("Are u want to save");
							for(j=0;j<2;j++)
							{
								gotoxy(30,j+8);
								if(j==pos2)
								textattr(blink);
								cprintf("\n%s",names[j]);
								textattr(0x07);
							}
							ch=getch();
							switch (ch)
								{
									case enter:
									switch (pos2)
									{
										case 0:
											flag=1;
										break;
										case 1:
											saveFile(1);
											saveFile(0);
											
											clrscr();
											gotoxy(30,i+5);
											show_message("data saved",0);
											getch();
											flag=1;
										break;
									}
								break;
								case NULL:
								ch=getch();
								switch (ch)
							{
								case up:
									pos2--;
									if(pos2<0)
										pos2=1;
								break;
								case down:
									pos2++;
									if(pos2>1)
										pos2=0;
								break;
								}
								break;
							 }
						}while(flag==0);
					break;
				}
			break;
				case NULL:
					ch=getch();
					switch (ch)
					{
					case up:
						pos--;
						if(pos<0)
							pos=5;
					break;
					case down:
						pos++;
						if(pos>5)
							pos=0;
					break;
					}
				break;
		}

   }while(flag==0);
	return 0;
}


/** append in student (std) **/
void append(struct std * temp)
{
	if(head== NULL){
	   head=temp;
	   tail=temp;
	   tail->next=NULL;
	 }else{

		tail->next=temp;
	   temp->prev=tail;
	   tail=temp;
	   tail->next=NULL;

	 }
}

/** append in department dept **/
void appendDp(struct Dept * temp)
{
	if(headDept==NULL)
	{
		headDept=temp;
		tailDept=temp;
		tailDept->next=NULL;
	}
	else
	{
		tailDept->next=temp;
		temp->prev=tailDept;
		tailDept=temp;
		tailDept->next=NULL;
	}
}

/** print all student data std **/
void printall(int student)
{

    int counter=0;
    int i=5,num;
    int y;

	if(student > 0)
	 {
	 	struct std * temp=head;
        num=count(temp);
        selection_sort(num);
        
	 	 gotoxy(2,i);
		  printf("id");
		  gotoxy(17,i);
		  printf("name");
		  gotoxy(32,i);
		  printf("deptId ");
		  gotoxy(47,i);
		  printf("phone");
		  gotoxy(62,i);
		  printf("address");
		while(temp!=NULL)
		{
			y=i;
			 counter++;
			 gotoxy(2,i+2);
			printf("%d",temp->id);
			  i=y;
			 gotoxy(17,i+2);
			printf("%s",temp->name);
			  i=y;
             gotoxy(32,i+2);
			printf("%d",temp->deptId);
			  i=y;
			  gotoxy(47,i+2);
			printf("%s",temp->phone);
			  i=y;
			  gotoxy(62,i+2);
			printf("%s",temp->address);
			  i +=2;
			temp=temp->next;
		}
		printf("\n ( %d ) Row Selected",counter);
	 }
	else
	 {
	   struct Dept * temp=headDept;
	   num=count_dept(temp);
        depart_sort(num);
	      gotoxy(2,i);
		  printf("id");
		  gotoxy(17,i);
		  printf("name");
		  
		while(temp!=NULL)
		{
			y=i;
			counter++;
			gotoxy(2,i+2);
			printf("%d",temp->did);
			 i=y;
			gotoxy(17,i+2);
			printf("%s",temp->dname);
			i +=2;
			temp=temp->next;
		}
		printf("\n ( %d ) Row Selected",counter);
	 }
}//end printall

/** search by name in  student std **/
struct std* searchBySName(char s[] )
 {
	struct std* temp;
	temp=head;
	while(temp != NULL)
	{
		if(strcmp(temp->name,s)==0)
		{
			return temp ;
		}
		 temp=temp -> next  ;
	}
		return NULL;
 }

/** search by id in  student std **/
struct std* searchBySId(int id)
 {
	struct std* temp;
	temp=head;
	while(temp != NULL)
	{
		if(temp->id == id)
		{
			return temp ;
		}
		 temp=temp-> next  ;
	}
		return NULL;
 }

struct std* searchBySdept(int did)
 {
	struct std* temp;
	temp=head;
	while(temp != NULL)
	{
		if(temp->deptId == did)
		{
			return temp ;
		}
		 temp=temp-> next  ;
	}
  return NULL;
 }

 /** search by id in department **/

struct Dept* searchById(int id)
 {
	struct Dept* temp;

	temp=headDept;

	while(temp != NULL)
	{
		if(temp ->did == id)
		{
			return temp ;
		}
		 temp=temp -> next  ;
	}
		return NULL;
 }

 /** search by name in department **/
struct Dept* searchByName(char s[] )
 {
	struct Dept * temp;
	temp=headDept;
	while(temp != NULL)
	{
		if(strcmp(temp->dname,s)==0)
		{
			return temp ;
		}
		 temp=temp->next  ;
	}
		return NULL;
 }
 /** delete  department dept by name or id **/
int  deleteDept(char* n, int id)
{
	int res=0;
	struct Dept*temp;
	temp= (n)? searchByName(n): searchById(id) ;
	if(headDept == NULL)
	 {
		return -1;

	 }
	else if(headDept==temp&&tailDept==temp)
	{
		headDept=tailDept=NULL;
		free(temp);
		res=1;
	}
	else if(temp==headDept)
	{
		headDept=temp->next;
		head->prev=NULL;
		free(temp);
		res=1;
	}
	else if(temp==tailDept)
	{
		tailDept=temp->prev;
		tailDept->next=NULL;
		free(temp);
		res=1;
	}
	else
	{
		temp->prev->next=temp->next;
		temp->next->prev=temp->prev;
		free(temp);
		res=1;
	}
	return  res;
}



int deleteBySId(int id)        //delete id in std
{
	int res=0;
	struct std* temp;
	temp=searchBySId(id);
	if(temp==NULL)
	{
	 return -1;
	}
   else	if(head==temp&&tail==temp)
	{
		head=tail=NULL;
		free(temp);
		   res=1;

	}
   else if(temp==head)
	{
		head=temp->next;
		head->prev=NULL;
		free(temp);
				 res=1;
	}
	 else if(temp==tail)
	{
		tail=temp->prev;
		tail->next=NULL;
		free(temp);
		  res=1;
	}
	else
	{
		temp->prev->next=temp->next;
		temp->next->prev=temp->prev;
		free(temp);
		res=1;
	}


	return res;
}

/** delete all department  dept **/
void delletealldept()
{
	struct Dept * temp;
	temp=headDept;
	if(temp!=NULL)
	{
		while(temp!=NULL)
		{
			temp=headDept;
			headDept=temp->next;
			headDept->prev=NULL;
			free(temp);
			temp=temp->next;
			clrscr();
			show_message("data delete sucessed",0);
			
		}
	}
	else
	{
		clrscr();
		show_message("There is no date",1);
		
	}
	getch();
}
/** delete all student  std **/
void delleteallstd()
{
	struct std * temp;
	temp=head;
	if(temp!=NULL)
	{
		while(temp!=NULL)
		{
			temp=head;
			head=temp->next;
			head->prev=NULL;
			free(temp);
			temp=temp->next;
			clrscr();
			show_message("data delete sucessed",0);
		}
	}
	else
	{
		clrscr();
		show_message("There is no date",1);
	}
	getch();
}

/** update student by  id **/
 int Update(int id,char* name,int deptId,char* phone, char* address)
  {
	   struct std * temp;
	   int updated=0;

		temp=searchBySId(id);
	   //if there found  node update it
		if(temp){

		   if(name)
				strcpy(temp->name,name);

		   if(deptId >0 )
				temp->deptId= deptId;

		   if(phone)
				strcpy(temp->phone,phone);

		   if(address)
				   strcpy(temp->address,address);

		   updated=1;
		 }

	return updated;
  }
/** update depratment **/
 int UpdateDept(int id,char* name)
  {
	   struct Dept * temp;
	   int updated=0;

		temp= searchById(id);
	   //if there found  node update it
		if(temp){

		   if(name)
				strcpy(temp->dname,name);

		   updated=1;
		 }

	return updated;
  }
   
void crud (char* str)

{
   struct Dept * temp1;
   struct std* temp;

   int  legal=-1,id=0,deptId=0,searchId;
   int  index=0,correct=1;
	//char * first;
	char* pch;
	char* name=NULL;
	char* phone=NULL;
	char* address=NULL;
	

	  pch    =(char *)malloc(1+ strlen(str));
	//convert string to lower
	strlwr(str);
	//split string using space
	pch=strtok(str," =,");


	while(pch != NULL)
	{


	  if( (strcmpi("select",pch)== 0) && index == 0)//if select
	   {

			 pch=moveNext( pch, &index," =,",&legal);

			// select statment
			 if(strcmpi("*",pch)==0 && index== 1)
			   {

					pch=moveNext( pch, &index," =,",&legal);

				 if(strcmpi("from",pch)==0 && index == 2)
				   {

					  pch=moveNext( pch, &index," =,",&legal);

					   if(strcmpi("std",pch)==0 && index == 3)
						{
							legal=1;
							clrscr();
							printall(1);

						   //display all  std data
						   break;
						}
					   else if(strcmpi("dept",pch)== 0 && index ==3)
						{
							legal=1;
						  printall(0);
						   break;
						}
					  else
						{
						   
						   show_message("Please select table",1);
						   legal=-1;
						   break;
						}

				   }// end from
				   else
				   {
					legal = -1;
					show_message("you forgot from",1);
					 break;
				   }
			   }//end *
			   
			while((strcmpi("id",pch)==0) || (strcmpi("name",pch)==0)|| (strcmpi("deptId",pch)==0)||
				  (strcmpi("phone",pch)==0) ||(strcmpi("address",pch)==0))
             {
			  if (strcmpi("id",pch)==0)
				{
						id=1;
						pch=moveNext( pch, &index," =,",&legal);
				}
	         

			  if (strcmpi("name",pch)==0)
				{
					name   = (char *)malloc(100* sizeof(char));
						strcpy(name,"found");
						pch=moveNext( pch, &index," =,",&legal);
				}

			  if (strcmpi("deptId",pch)==0)
				{
						deptId=1;
						pch=moveNext( pch, &index," =,",&legal);
				}

			   if (strcmpi("phone",pch)==0)
				{
					   phone  = (char *)malloc(100* sizeof(char));
						strcpy(phone,"found");
						pch=moveNext( pch, &index," =,",&legal);
				}

			   if (strcmpi("address",pch)==0)
				{
					   address= (char *)malloc(100* sizeof(char));
						strcpy(address,"found");
						pch=moveNext( pch, &index," =,",&legal);
				}
               }//end while loop

			   if (strcmpi("from",pch)==0 &&index>1)
				{
						pch=moveNext( pch, &index," =,",&legal);

					   if(strcmpi("std",pch)==0 )
						{
							pch=moveNext( pch, &index," =,",&legal);
                            
							if(strcmpi("where",pch)== 0)
                             {
									pch=moveNext( pch, &index," =,",&legal);
									if (strcmpi("id",pch)== 0)
						               {
											pch=moveNext( pch, &index," =,",&legal);
											 searchId= atoi(pch);
											 if(searchId > 0)
                                               { 
													
													printsel(id,name,deptId,phone,address,searchId,0);
											         
											      break;
											    }else
												{
											    	legal=-1;
											    	show_message("invalid where cluse supplied",1);
											    	
											    	break;
											    }  
									    }//end id  
									    else{
									    	legal=-1;
									    	show_message("you forgot  id (condition id = number)",1);
									    	break;
									    } 
						         

						     }//end where
						     else{
							     	legal=1;
							     	printsel(id,name,deptId,phone,address,searchId,1);
									break;
						     }
						}//end std
					   else if(strcmpi("dept",pch)== 0 )
						{
							pch=moveNext( pch, &index," =,",&legal);
                            if(strcmpi("where",pch)== 0)
                             {
						         	pch=moveNext( pch, &index," =,",&legal);
						         	if (strcmpi("id",pch)== 0)
						               {
						               	    pch=moveNext( pch, &index," =,",&legal);
											 searchId= atoi(pch);
                                             if(searchId > 0)
                                               { 
													printdepart(id,name,searchId,0);
													
												  break;
											    }else
											    {
											    	legal=-1;
											    	show_message("invalid where cluse supplied",1);
											    	break;
											    }  
									    }//end id 
										else{
									    	legal=-1;
									    	show_message("you forgot  id (condition id = number)",1);
									    	break;
									    } 
						         
							     
						     }//end where
						     else{
						     	legal=1;
						     	printdepart(id,name,searchId,1);
						     	break;
						     }
						}
					  else
						{
						   show_message("Please select table",1);
						   legal=-1;
						   break;
						}

				}// end from
				else
				  {
					legal = -1;
					show_message("you forgot from or forgot select colunms",1);
					 break; 
				  }


	   }//end select
	   else if((strcmpi("insert",pch)==0 ) && index == 0)
	  {
		// insert into values section
		   pch=moveNext( pch, &index," =,",&legal);

	   if(strcmpi("into",pch)==0 && index== 1)
		 {
			   pch=moveNext( pch, &index," =,",&legal);

			if((strcmpi("std",pch)==0) && index == 2)
				{
					   pch=moveNext( pch, &index, " =,",&legal);

					if(strcmpi("values",pch)== 0 && index == 3)
					{

						  pch=moveNext( pch, &index," =,",&legal);
						   correct= chkchar(pch,'(',1,1,0);
                           	if(correct < 0)
                           	 {
                                legal=-1;
                                show_message("you forgot (",1);
                                break;
                           	 }
						   pch= rmvchar(pch,'(');

										id=  atoi(pch);
										if(id == 0)
										{
											clrscr();
											show_message("Invalid id splied",1);
											break;
										}
										 pch=moveNext( pch, &index," =,",&legal);
										 correct= chkchar(pch,'"',1,1,1);
			                           	if(correct < 0)
			                           	 {
			                                legal=-1;
			                                show_message("you forgot \" ",1);
			                                break;
			                           	 }
										pch= rmvchar(pch,'"');

										  name=(char *) malloc(1+ strlen(pch));
										  strcpy(name,pch);
										 pch=moveNext( pch, &index," =,",&legal);


										deptId= atoi(pch);
										if(deptId == 0)
										{
											clrscr();
											show_message("invalid department splied",1);
											break;
										}
										  pch=moveNext( pch, &index," =,",&legal);
										 
			                           	  correct= chkchar(pch,'"',1,1,1);
			                           	if(correct < 0)
			                           	 {
			                                legal=-1;
			                                show_message("you forgot \" ",1);
			                                break;
										 }
										  pch= rmvchar(pch,')');
										 pch= rmvchar(pch,'"');
										
										  phone= (char *) malloc( 1+ strlen(pch));
										  strcpy(phone,pch);
										  pch=moveNext( pch, &index," =,",&legal);
                                        
                                        correct= chkchar(pch,'"',1,1,0);
			                           	if(correct < 0)
			                           	 {
			                                legal=-1;
			                                show_message("you forgot \" ",1);
			                                break;
			                           	 }
			                           	    correct= chkchar(pch,')',1,0,1);

			                           	if(correct < 0)
			                           	 {
			                                legal=-1;
			                                show_message("you forgot ) ",1);
			                                break;
			                           	 }
			                           	 correct= chkchar(pch,'"',2,0,1);
			                           	if(correct < 0)
			                           	 {
			                                legal=-1;
			                                show_message("you forgot \" ",1);
			                                break;
			                           	 } 
			                           	
										 pch = rmvchar(pch,')');
										 pch= rmvchar(pch,'"');

										 
										  address=(char *)  malloc(1+ strlen(pch));
										  strcpy(address,pch);
                                          
										  if((id>0) && (strcmpi(name,NULL) != 0)  && (deptId > 0) && (strcmpi(phone,NULL) != 0) && (strcmpi(address,NULL) != 0) )
										   {
                                                 temp=createStudent(id,name,deptId,phone,address);
                                                 if(temp)
										           {append(temp); show_message("1 row affected",0);}

										        free(name);
												free(phone);
												free(address);
												break;
										    }
										    else
										      {
										      	legal=-1;
										      	show_message("table contain 5 values that all must be inserted in the following squence\n id,name,deptId,phone,address",1);
										      	free(name);
												free(phone);
												free(address);
												break;
											  }
					}else
					{
						legal=-1;
						show_message("you forgot values",1);
						
						break;
					}
				}
			else if((strcmpi("dept",pch)== 0) && index == 2)
				{
					  pch=moveNext( pch, &index," =,",&legal); 

					if(strcmpi("values",pch)== 0 && index == 3)
					{
						   pch=moveNext( pch, &index," =,",&legal);
                            correct= chkchar(pch,'(',1,1,0);
                           	if(correct < 0)
                           	 {
                                legal=-1;
                                show_message("you forgot (",1);
                                break;
                           	 }
						   pch= rmvchar(pch,'(');

										id=  atoi(pch);
										if(id == 0)
										{
											clrscr();
											show_message("INvalid id splied",1);
											break;
										}
										 pch=moveNext( pch, &index," =,",&legal);
										 correct= chkchar(pch,'"',1,1,0);
			                           	if(correct < 0)
			                           	 {
			                                legal=-1;
			                                show_message("you forgot \" ",1);
			                                break;
			                           	 }
			                           	    correct= chkchar(pch,')',1,0,1);

			                           	if(correct < 0)
			                           	 {
			                                legal=-1;
			                                show_message("you forgot ) ",1);
			                                break;
			                           	 }
			                           	 correct= chkchar(pch,'"',2,0,1);
			                           	if(correct < 0)
			                           	 {
			                                legal=-1;
			                                show_message("you forgot \" ",1);
			                                break;
			                           	 } 
										pch= rmvchar(pch,')');
										pch= rmvchar(pch,'"');

										  name=(char *) malloc(1+ strlen(pch));
										  strcpy(name,pch);
                                          
										  if((id>0) && (strcmpi(name,NULL) != 0))
										   {
                                                  temp1=createnodeDp(id,name);
                                                   if(temp1)
											         {appendDp(temp1); show_message("1 row affected",0); }
										           
										        free(name);
												free(phone);
												free(address);
												break;
										    }else
										      {
										      	legal=-1;
										      	show_message("table contain 2 values that all must be inserted in the following squence\n id,name\n",1);
										      
												free(name);
												free(phone);
												free(address);
										      	break;
											  }

					}else{
						legal=-1;
						show_message("you forgot values",1);
						break;
					}
				}
			 else
				{
					legal=-1;
					show_message("Please select table",1);
					break;
				}
		}//end into
	}//end insert
	else if( (strcmpi("delete",pch)== 0) && index == 0)//if delete
	   {

			  pch=moveNext( pch, &index," =,",&legal);

			 if((strcmpi("from",pch)==0) && index==1)//if from
			 {
				 pch=moveNext( pch, &index," =,",&legal);

				if((strcmpi("std",pch)==0) && index==2)//if std
				{
					 pch=moveNext( pch, &index," =,",&legal);

					 if((strcmpi("where",pch)==0) && index ==3) //if where exisit
						{
							  pch=moveNext( pch, &index," =,",&legal);

							 if((strcmpi("id",pch)==0) && index==4)
							 {
								  pch=moveNext( pch, &index," =,",&legal);

								
									 id=atoi(pch);
									 if(deleteBySId(id)> 0)
									 {
										clrscr();
										show_message("1 row affected",0);
										break;
									 }
									 else
									 {
										clrscr();
										show_message("row  not found ",1);
										break;
									 }



							 }else
							 {
								legal = -1;
								show_message("specify condition after where",1);

								break;
							 }
						}
					 else{
						 delleteallstd();
						 break;
					   }

				} //end std
				else if((strcmpi("dept",pch)==0) && index==2)//if dept
				{
					 pch=moveNext( pch, &index," =,",&legal);

					 if((strcmpi("where",pch)==0) && index==3) //if where exisit
						{
							  pch=moveNext( pch, &index," =,",&legal);

							 if((strcmpi("id",pch)==0) && index==4)
							 {
								  pch=moveNext( pch, &index," =,",&legal);

									 id=atoi(pch);
									 if(deleteSetting(id) > 0)
									 {
										clrscr();
										show_message("1 row affected",0);
										break;
									 }
									 else
									 {
										clrscr();
										show_message("row has another row assocaited with it in another table",1);
										break;
									 }

							 }else
							 {
								legal = -1;
								show_message("specify condition after where",1);
								break;
							 }
						}
					 else{
						 delletealldept();
						 break;
					   }


				}  //end dept
				else
				{
					legal=-1;
					show_message("please select table",1);
					break;
				}
			 }//end from
			 else
			 {
				legal=-1;
				show_message("you forget to write \t from \t",1);
				break;
			 }
	   }//end delete
	   else if((strcmpi("update",pch))==0 && index == 0)
		  {
			  pch=moveNext( pch, &index," =,",&legal);
			  
			   
			  if((strcmpi("std",pch)==0) && index == 1)
			   {

					pch=moveNext( pch, &index," =,",&legal);

					if((strcmpi("set",pch)== 0) && index == 2)
					 {

						 pch=moveNext( pch, &index," =,",&legal);
                        	
						if(strcmpi("name",pch) == 0 )
						 {
							pch=moveNext( pch, &index," =,",&legal);
						    pch= rmvchar(pch,'"');		
							name=(char *) malloc(1+ strlen(pch));
							strcpy(name,pch);
							pch=moveNext( pch, &index," =,",&legal);

						 }

						if(strcmpi("phone",pch) == 0)
						 {

							pch=moveNext( pch, &index," =,",&legal);
							 pch= rmvchar(pch,'"');	
							phone= (char *) malloc( 1+ strlen(pch));

							strcpy(phone,pch);
							pch=moveNext( pch, &index," =,",&legal);

						 }
						if(strcmpi("address",pch)==0)
						 {
							pch=moveNext( pch, &index," =,",&legal);
							 pch= rmvchar(pch,'"');	
							address=(char *)  malloc(1+ strlen(pch));
							strcpy(address,pch);
							pch=moveNext( pch, &index," =,",&legal);
						   //	pch= strtok(pch,"=,");

						 }
						if(strcmpi("deptId",pch)==0)
						 {
							pch=moveNext( pch, &index," =,",&legal);
							deptId= atoi(pch);
							if(deptId == 0)
							 {
								clrscr();
								show_message("Invalid department splied",1);
								break;
							 }
							pch=moveNext( pch, &index," =,",&legal);


						 }



						if((strcmpi("where",pch)== 0) && index > 4)
						 {
						   pch=moveNext( pch, &index," =,",&legal);
							if((strcmpi("id",pch)== 0))
							 {
								pch=moveNext( pch, &index," =,",&legal);
								
									id=atoi(pch);
									if(id <=0 )
									{
										show_message("invalid id supplied",1);
										break;
									}
									if(Update(id, name, deptId, phone, address)> 0)
									 {
									 	show_message("1 row affected",0);
									   
									   break;
									 } 

							 }
						 }
						 else
						  {
							legal=-1;
							show_message(" you forgot where cluse",1);
							 break;
						  }

					 }//end set
					else
					 {
					   legal=-1;
					   show_message(" you messing set",1);
					   break;
					 }
			   }//end std
			  else if((strcmpi("dept",pch)==0) && index==1)
			   {
			   	     pch=moveNext( pch, &index," =,",&legal);
					if((strcmpi("set",pch)== 0) && index == 2)
					 {
					 	 pch=moveNext( pch, &index," =,",&legal);
					 	 if(strcmpi("name",pch) == 0 )
						 {
							pch=moveNext( pch, &index," =,",&legal);
							 pch= rmvchar(pch,'"');	
							name=(char *) malloc(1+ strlen(pch));
							strcpy(name,pch);
							pch=moveNext( pch, &index," =,",&legal);
							if( strcmpi("where",pch)== 0)
							 {
							   pch=moveNext( pch, &index," =,",&legal);
								if((strcmpi("id",pch)== 0))
								 {
									pch=moveNext( pch, &index," =,",&legal);
									
										id=atoi(pch);
										if(id <=0)
										 { show_message(" invalid id supplied ",1); break;}	

										if(UpdateDept(id,name) > 0)
										 {
										 	show_message(" 1 row affected ",0);
						
										   break;
										 } 

								 }
							 }
							 else
							  {
								legal=-1;
								show_message("you forgot where cluse",1);
								 break;
							  }

						 }else{
						 	legal=-1;
						 	show_message("only update name",1);
						 	break;
						 }
                         
					 }
			   }//edn dept
			  else
			   {
				  legal=-1;
				  show_message("incorrect table",1);
				  break;
			   }
		  }//end update


	else
	  {

		legal=-1;
		break;
	  }
	  index++;
	  pch=strtok(NULL," ");
	}//end while
	  if(legal == -1)
	  	show_message("Sorry Error Command",1);
} //end crud
 void openFile(int student,int disp)
{
	int i,id,did;
	char str[999];
	FILE * file;
	struct std* temp;
	struct Dept * temp2;
    char name[20];
	char phone[10];
	char address[10];

  if(student >0 )
	{
	file = fopen("1.txt" , "r");

	if (file)
	{
		while (!feof(file))
		{ 
			temp=(struct std*)malloc(sizeof(struct std));

			fscanf(file,"%d ",&id);
			if ( feof(file) )    /* check for EOF right after fscanf() */
			break;
			temp->id= id;
			if(disp> 0)
			{
			  printf("%d \t", id);
             }
			fscanf(file,"%s ",name);
			if ( feof(file) )    /* check for EOF right after fscanf() */
			 break;
			 strcpy(temp->name,name);
			 if(disp> 0)
			 {
			  printf("%s \t", name);
             }
			

			fscanf(file,"%d",&did);
			 if ( feof(file) )    /* check for EOF right after fscanf() */
			 break;
			
			 temp->deptId=did;
			 if(disp> 0)
			 {
			  printf("%d \t", did);
             }

			fscanf(file,"%s",phone);
			if ( feof(file) )    /* check for EOF right after fscanf() */
			break;
			
			  strcpy(temp->phone,phone);
			  if(disp> 0)
			 {
			  printf("%s \t", phone);
             }
			fscanf(file,"%s ",address);

			if(disp> 0)
			 {
			   printf("%s \t \n ", address);
             }
			  strcpy(temp->address,address);
			  if (appended != 1) {append(temp);}
			//printf("\n");
			if ( feof(file) )    /* check for EOF right after fscanf() */
			break;

		}
		fclose(file);
	}
  }else
   {
       file = fopen("2.txt" , "r");
       if (file)
		{
			while (!feof(file))
			{
				temp2=(struct Dept *)malloc(sizeof(struct Dept));
				fscanf(file,"%d ",&i);
				if ( feof(file) )    /* check for EOF right after fscanf() */
				 break;
				 if(disp> 0)
			    {
				  printf("%d \t", i);
	             }
				
	            temp2->did= i;
				fscanf(file,"%s ",str);
				strcpy(temp2->dname, str);

			   if(disp> 0)
			     {
				  printf("%s \t \n ", str);
	             }
				 if(appended != 1) {appendDp(temp2);}
				 
			}
			fclose(file);
		}

   }

}
void saveFile(int student )
{


   char name[20];
   int num;

	FILE * f;

	 (student > 0)? strcpy(name,"1.txt") : strcpy(name,"2.txt");
	  remove(name);
	f = fopen(name, "a");

	if(student > 0)
	 {
		struct std * temp=head;
		num=count(temp);
        selection_sort(num);

		while(temp!=NULL)
		{
			fprintf(f, "\n");
			fprintf(f,"%d ",temp->id);
			fprintf(f,"%s ",temp->name);
			fprintf(f,"%d ",temp->deptId);
			fprintf(f,"%s ",temp->phone);
			fprintf(f,"%s ",temp->address);
			fprintf(f,"\n");
			temp=temp->next;
		}

	}

	else
	 {
	   struct Dept * temp1=headDept;
	    num=count_dept(temp1);
        depart_sort(num);
        
		while(temp1!=NULL)
		{
			fprintf(f, "\n");
			fprintf(f,"%d ",temp1->did);
			fprintf(f,"%s ",temp1->dname);
			temp1=temp1->next;
		}
	 }
		fclose(f);


}//end save


struct std*  createStudent(int id,char* name,int deptId,char* phone,char* address)
{

	struct std* temp;
	struct Dept * temp2;

   temp=searchBySId(id);
	if(temp==NULL)
	{
		temp=(struct std*)malloc(sizeof(struct std));
		temp->id= id;
		strcpy(temp->name,name);


		temp2 = searchById(deptId);
		if(temp2) //if found department
		   temp->deptId= deptId;
		else
		 {
		 	show_message("this department does not exist",1);
			return temp2;
         }

		strcpy(temp->phone,phone);
		strcpy(temp->address,address);
		temp->prev=NULL;
		temp->next=NULL;
		return temp;
	}
	else
	{
		show_message("this student with that id  already is exit",1);
		return NULL;
	}
}
/** create department node **/
struct Dept* createnodeDp(int id, char * name)
{
	struct Dept * temp1;
	temp1 = searchById(id);
	if(temp1 == NULL)
	 {
		temp1 =(struct Dept*)malloc(sizeof(struct Dept));
	     
		  temp1->did= id;
		  strcpy(temp1->dname,name);
         temp1->prev=NULL;
		temp1->next=NULL;
		return temp1;
     }else{

   	    show_message("this department with that id is exit",1);
		return NULL;
     }
}

char * moveNext(char * pch, int * index,char delmeter[],int * legal)
  {
			 *(legal)=1;
			 pch=strtok(NULL,delmeter);
			 (*index)++;
			 return pch;
  }
/** remove character **/
char * rmvchar(char * pch, char character)
  {
	  int stlen;
		stlen = strlen(pch);

	   // found in first place
	   if(pch[0]== character)
		{memmove(pch, pch+1, stlen);}

		stlen = strlen(pch);
	   //remove in last place
	   if(pch[stlen-1]== character)
		{pch[stlen-1]='\0';}

		return pch;
  }
int  chkchar(char * pch, char character,int lastPosition ,int left, int right)
  {
		int stlen;

	if(left > 0)
	 {

		stlen = strlen(pch);

	   // found in first place
		if(pch[0] != character)
		{return -1;}
	 }
	if(right > 0)
	 {
		stlen = strlen(pch);
	   //found in last place
	   if(pch[stlen-lastPosition] != character)
		{return -1;}
     }
		return 1;
  }  
void show_message(char * message, int erro)
  {
  	  (erro > 0 )? textattr(RED) : textattr(GREEN) ;
  	   cprintf("\n %s\n", message);
  	   textattr(0x07);
  }
void  printsel(int id,char* name,int deptId,char* phone,char* address,int searchId,int all)
  {
			
	struct std* temp;
	int counter=0;
	int i=5;
	int y;
	if(all<=0)
	{
	
	temp=searchBySId(searchId);
	
	if(temp==NULL)
		show_message("No student Data  to display",1);
	else
	{
		
        if(id>0)
		  {
		  	gotoxy(2,i);
		    printf("id");
			
		  }
		if(name)
		 {  
		  gotoxy(17,i);
		  printf("name");
		 }
		if(deptId>0)
		 { 
		  gotoxy(32,i);
		  printf("deptId ");
		 } 
		if(phone)
		 { 
		  gotoxy(47,i);
		  printf("phone");
		 }
		if(address)
		 { 
		  gotoxy(62,i);
		  printf("address");
		 }
			if(id>0)
			 {
			  	gotoxy(2,7);
			  	printf("%d",temp->id);
			 }	
			if(name)
		     {
		       gotoxy(17,7);		
			   printf("%s",temp->name);
             }
			if(deptId>0)
		     {
		       gotoxy(32,7);		
			   printf("%d",temp->deptId);
             }
			if(phone)
             {
                gotoxy(47,7);	
			   printf("%s",temp->phone);
			 }
			if(address)
             {
			   gotoxy(62,7);
			  printf("%s",temp->address);
			 }
		printf("\n (1) Row Selected");	 
			
	}
  }else
		{
		
		temp=head;
	
		if(id>0)
		  {
			gotoxy(2,5);
			printf("id");
		  }
		if(name)
		 {  
		  gotoxy(17,5);
		  printf("name");
		  
		 }
		if(deptId>0)
		 { 
		  gotoxy(32,5);
		  printf("deptId ");
		 } 
		if(phone)
		 { 
		  gotoxy(47,5);
		  printf("phone");
		 }
		if(address)
		 { 
		  gotoxy(62,5);
		  printf("address");
		 }
		 
		 
    while(temp)
	   {

           y=i;
           counter++;
			if(id>0)
			 {
			  gotoxy(2,i+2);
			  printf("%d",temp->id);
			  i=y;
			 }
			if(name)
		     {
			  gotoxy(17,i+2);
			  printf("%s",temp->name);
			  i=y;
			 }
			if(deptId>0)
		     {  
              gotoxy(32,i+2);
			  printf("%d",temp->deptId);
			  i=y;
			 }
			if(phone)
             {  
			  gotoxy(47,i+2);
			  printf("%s",temp->phone);
			  i=y;
			 }
			if(address)
             { 
			  gotoxy(62,i+2);
			  printf("%s",temp->address);
			 }
			  i +=2;
			temp=temp->next;

	   
		}
		printf("\n ( %d ) Row Selected",counter);
  }
  
  }


  void  printdepart(int id,char* name,int searchId,int all)
   {
	   struct Dept * temp;

	   int i=5,counter=0;
	int y;
	if(all<=0)
	{
		temp=searchById(searchId);
		if(temp == NULL)
			show_message("not found depratment with that id %d",searchId);
		else
		{
			
		if(id>0)
		  {
			gotoxy(2,5);
			printf("id");
		  }
		if(name)
		 {
		  gotoxy(17,5);
		  printf("name");
		 }
		if(id>0)
			 {
				gotoxy(2,7);
				printf("%d",temp->did);
			 }
			if(name)
			 {
			   gotoxy(17,7);
			   printf("%s",temp->dname);
			 }
	 printf("\n 1 Row Selected");
	  }

	}

	else
	{

		temp=headDept;
		if(id>0)
		  {
			gotoxy(2,5);
			printf("id");
		  }
		if(name)
		 {
		  gotoxy(17,5);
		  printf("name");
		 }
		 //
		 while(temp)
		{
			y=i;
			counter++;
			if(id>0)
			 {
				gotoxy(2,i+2);
				printf("%d",temp->did);
				 i=y;
			 }
			if(name)
			 { 	 
				gotoxy(17,i+2);
				printf("%s",temp->dname);
			 }	
				i +=2;
				temp=temp->next;
		}
		printf("\n ( %d ) Row Selected",counter);
			
	}

   }

/*void printJoin(int id,char* name,char dname[],char* phone,char* address,int searchId)
 {
   struct Dept * d;
   struct std  * temp;
  int counter=0,i=5,y;
 
  temp=searchBySId(searchId);
   
   if(temp==NULL)
		show_message("No student Data  to display",1);
	else
	{
		
        if(id>0)
		  {
		  	gotoxy(2,i);
		    printf("id");
			
		  }
		if(name)
		 {  
		  gotoxy(17,i);
		  printf("name");
		 }
		if(dname)
		 { 
		  gotoxy(32,i);
		  printf("department ");
		 } 
		if(phone)
		 { 
		  gotoxy(47,i);
		  printf("phone");
		 }
		if(address)
		 { 
		  gotoxy(62,i);
		  printf("address");
		 }
	while(temp)
	   {

           y=i;
           counter++;
			if(id>0)
			 {
			  gotoxy(2,i+2);
			  printf("%d",temp->id);
			  i=y;
			 }
			if(name)
		     {
			  gotoxy(17,i+2);
			  printf("%s",temp->name);
			  i=y;
			 }
			 if(dname)
		     {
		       gotoxy(32,i+2);
		       d= searchBySdept(temp->deptId);		
			   printf("%d",d->dname);
			   i=y;
             }
			
			if(phone)
             {  
			  gotoxy(47,i+2);
			  printf("%s",temp->phone);
			  i=y;
			 }
			if(address)
             { 
			  gotoxy(62,i+2);
			  printf("%s",temp->address);
			 }
			  i +=2;
			temp=temp->next;

	   
		}
		printf("\n ( %d ) Row Selected",counter);
	
			
				 
			
	}
   
 }*/

void selection_sort ( int n )
{
    int i, j, k, temp,dprt ;
    struct std *p, *q ;
    char * newName, *newPhone, *newAddress;
    p = head ;
    for ( i = 0 ; i < n - 1 ; i++ )
    {
        q = p->next;

        for ( j = i + 1 ; j < n ; j++ )
        {
            if ( p->id > q->id )
			{
				temp = p->id ;
				p->id = q->id;
                q->id = temp ;

                dprt=p->deptId;
                p->deptId= q->deptId;
                q->deptId=dprt;
                 
                newName =(char *)malloc(1+strlen(p->name)); 
                strcpy(newName,p->name);
				strcpy(p->name,q->name);
				strcpy(q->name,newName);

			  newPhone =(char *)malloc(1+strlen(p->phone));
				strcpy(newPhone,p->phone);
				strcpy(p->phone,q->phone);
				strcpy(q->phone,newPhone);

			 newAddress =(char *)malloc(1+strlen(p->address));
				strcpy(newAddress,p->address);
				strcpy(p->address,q->address);
				strcpy(q->address,newAddress);
            }
            q = q->next ;
        }
        p = p->next ;
    }
}

void depart_sort ( int n )
{
    int i, j, k, temp ;
    struct Dept *p, *q ;
    char * newName;
    p = headDept ;
    for ( i = 0 ; i < n - 1 ; i++ )
    {
        q = p->next;

        for ( j = i + 1 ; j < n ; j++ )
        {
            if ( p->did > q->did )
			{
				temp = p->did ;
				p->did = q->did;
				q->did = temp ;

				newName =(char *)malloc(1+strlen(p->dname));
				strcpy(newName,p->dname);
				strcpy(p->dname,q->dname);
				strcpy(q->dname,newName);

            }
            q = q->next ;
        }
        p = p->next ;
    }
}
int deleteSetting(int departId)
 {
	//{"Cascade","NO ACTION","Set Null","Restrict"}
       int res=0,success=0;
	struct std* temp;
	
 	switch(del_setting)
 	 {
 	 	case 1:
 	 	  //Cascade
 	 	  temp=searchBySdept(departId); 
 	 	  while(temp)
 	 	  {   
			  if(temp)
			   {	deleteBySId(temp->id);}
			  temp=searchBySdept(departId);
			 
	      }
	      success=deleteDept(NULL,departId);
	       if(success <= 0)
             { show_message("not found ",1);}
          res=1;
 	 	 break;
 	 	case 2:
 	 	 //NO ACTION
 	 	  res=0;
 	 	 break;
 	 	case 3:
 	 	 //Set Null
 	 	temp=searchBySdept(departId); 
 	 	// we refere assume that 30000 is NULL 
 	 	  while(temp)
 	 	  {   
			  if(temp)
			   {	

			   	Update(temp->id,NULL,30000,NULL,NULL);
                temp->deptId= NULL;
			   }
			   //temp=temp->next;
			  temp=searchBySdept(departId);
			 
	      }
	      success=deleteDept(NULL,departId);
	       if(success <= 0)
             { show_message("not found ",1);}
          res=1;
 	 	 break;
 	 	 
 	 	case 4:
	      res=0;
 	 	 //Restrict
 	 	 break;   
 	 }
 	 return res;
 }

int count ( struct std * q )
{
    int c = 0 ;
    /* traverse the entire linked list */
while ( q != NULL )
    {
        q = q->next ;
        c++ ;
    }

    return c ;
}
int count_dept ( struct Dept * q )
{
    int c = 0 ;
    /* traverse the entire linked list */
while ( q != NULL )
    {
        q = q->next ;
        c++ ;
    }

    return c ;
}