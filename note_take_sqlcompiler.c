#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define maxc 500
struct d1int{
int Id;
int top;
int cappa;
int *arr;
};
struct d2int{
int top;
int cappa;
struct d1int **d1;
};
struct Stack { 
    int top; 
    int cappa; 
    char **array; 
}; 
struct Note
{
 int Id;
char **tags;
int tagIndex;
char **lines;
int lindex;
int lcapacity;
int tagCap;
};
int pop1darray(struct d1int *i);
struct d1int* pop2darray(struct d2int *i);
void push2darray(struct d2int *i,struct d1int *d);
struct d1int  startd1int(struct d1int *i);
void push1darray (struct d1int *i,int data);
struct d2int startd2int(struct d2int *i);
void pushStack(struct Stack *n1,char *a);
char* popSt(struct Stack *st);
struct  Stack startStack(struct Stack *st);
void printNote(struct Note *n,FILE *out);
struct Note initializeNote(struct Note *n,char *id,char  *l);
void putLines(struct Note *n,char*line);
void push(struct Note **arr, int *index,struct Note *ptr, int *size, int *capacity);
void putTags(struct Note *n,char *tag);
int d1Id=0;
int main(int argc,char*argv[])
{
	int size,index,cap;
	cap=5;
	index=0;
	int *pcap=&cap;
	int *pindex=&index;
	size=(index)+1;
	char *line=(char*)malloc(sizeof(char)*maxc);	
	char *res;
	int d2arrCap=5;
	int d1arrIndex=0;

	FILE *input=stdin,*output=stdout;
//	input=fopen(argv[1],"r");
//	printf("deneme\n");
//	output=fopen(argv[2],"w");

	struct Note *arr[100];
	int i=0;
	int tagco=0;
	
	while(res=fgets(line,maxc,input))
	{
		if(strstr(line,"ADD")!=NULL)
		{
		 strtok(res," ");
		 char *a,*str;
		 a=strtok(NULL," ");
		 struct Note *newN= (struct Note*)malloc(sizeof(struct Note));
		 *newN=initializeNote(newN,a,line);
			
		 	while(fgets(line,maxc,input)&&!(strstr(line,"END")))
			{
		 		str=res;
				putLines(newN,str);
			}
			push(arr,pindex,newN,&size,pcap); 
		}
			
		else if(strstr(line,"FIND")!=NULL)
		{		
			strtok(res," ");
			struct Stack *st=(struct Stack*)malloc(sizeof(struct Stack));
			struct Stack *st2=(struct Stack*)malloc(sizeof(struct Stack));
			struct Stack *stres=(struct Stack*)malloc(sizeof(struct Stack));
			
			struct d1int *i0=(struct d1int*)malloc(sizeof(struct d1int));
			
			struct d2int *i2=(struct d2int*)malloc(sizeof(struct d2int));
			
			*i0=startd1int(i0);
			*i2=startd2int(i2);	
			*st=startStack(st);
			*st2=startStack(st2);
			
			int d1arrCap=0;
			int d1arrIndex=0;

			int d1arr[d1arrCap];

			char *a=(char*)malloc(100);
			int c=0;
			while(1)
			{
				if(strcmp(a,")")==0||strcmp(a,")\n")==0)
				{
					break;
				}
				a=strtok(NULL," ");
				pushStack(st,a);
				c++;
			}
			int ia=0;
			while(ia<c)
			{
				a=popSt(st);
				if(strcmp("AND(",a)==0)
				{
					 int ca=st2->top+1;
					
				int plus=0;
				if(i2->top!=-1)
					plus=1;
					 for(int tb=0;tb<ca;tb++)
					{
						struct d1int *i1=(struct d1int*)malloc(sizeof(struct d1int));
						*i1=startd1int(i1);
						char*t;
						t=popSt(st2);
						//loops through notes
						for(int iz=0;iz<*pindex;iz++)
						{
							//loops th tags of one note
							for(int ze=0;ze<arr[iz]->tagIndex;ze++)
							{
								if(strcmp(arr[iz]->tags[ze],t)==0)
								{
										push1darray(i1,arr[iz]->Id);
								}	
							}
						}
						push2darray(i2,i1);
					}
					
					 for(int sa=0;sa<ca-1+plus;sa++)
					 {
						struct d1int *c;
						struct d1int *b;
						b=pop2darray(i2);
						c=pop2darray(i2);
						struct d1int *stable=(struct d1int*)malloc(sizeof(struct d1int));
						*stable=startd1int(stable);
						int btop=b->top+1;
						int ctop=c->top+1;
						
						for(int av=0;av<btop;av++)
						{
							int ztop= btop>ctop? btop:ctop;
							for(int ae=0;ae<ztop;ae++)
							{
								if(b->arr[av]==c->arr[ae])
								{
									push1darray(stable,b->arr[av]);	
								}
							}
						}
						
						push2darray(i2,stable);	
					//	free(stable);
					}	
					i=0;
				}//ands end
				else if(strcmp(a,")\n")==0|| strcmp(a,")")==0)
				{
			            ;
				}
				else if(strcmp(a,"OR(")==0)
				{
					 int ca=st2->top+1;
					int plus=0;
					if(i2->top!=-1)
					plus=1;
					for(int tb=0;tb<ca;tb++)
					{
						struct d1int *i1=(struct d1int*)malloc(sizeof(struct d1int));
						*i1=startd1int(i1);
						char*t;
						t=popSt(st2);
						//loops through notes
						for(int iz=0;iz<*pindex;iz++)
						{
							//loops th tags of one note
							for(int ze=0;ze<arr[iz]->tagIndex;ze++)
							{
								//if tag and notes tag 0
								if(strcmp(arr[iz]->tags[ze],t)==0)
								{
										push1darray(i1,arr[iz]->Id);
								}	
							}
						}
																		
						push2darray(i2,i1);
						//taglerin arrayde nigga.	
					}
				 		 for(int sa=0;sa<ca-1+plus;sa++)
						 {
							struct d1int *c;
							struct d1int *b;
							b=pop2darray(i2);
							c=pop2darray(i2);
						//b en son sonuç olduğu için b de olmayan tag sonuçlarını doldurmak yeterli olabilir sonra bir or
							struct d1int *stable=(struct d1int*)malloc(sizeof(struct d1int));
						*stable=startd1int(stable);
							int btop=b->top+1;
							int ctop=c->top+1;
					
							for(int av=0;av<ctop;av++)
							{
								int ztop=btop;
								int s=-1;
								int bo=0;
								for(int ae=0;ae<ztop;ae++)
							{
								if(b->arr[av]==c->arr[ae])
								{
									bo=1;
								}
							}
							if(bo==0)
							push1darray(b,c->arr[av]);	
							}		
							push2darray(i2,b);	
						}
				i=0;
				}
				else if(strcmp(a,"NOT(")==0)
				{
					 int ca=st2->top+1;
					int plus=0;
					if(i2->top!=-1)
					plus=1;
					for(int tb=0;tb<ca;tb++)
					{
						struct d1int *i1=(struct d1int*)malloc(sizeof(struct d1int));
						*i1=startd1int(i1);
						char*t;
						t=popSt(st2);
						//loops through notes
						for(int iz=0;iz<*pindex;iz++)
						{
							for(int ze=0;ze<arr[iz]->tagIndex;ze++)
							{
								if(strcmp(arr[iz]->tags[ze],t)==0)
								{
										push1darray(i1,arr[iz]->Id);
								}	
							}
						}
						push2darray(i2,i1);
					}
							struct d1int *b;
							b=pop2darray(i2);
							struct d1int *stable=(struct d1int*)malloc(sizeof(struct d1int));
							*stable=startd1int(stable);
				 		 for(int sa=0;sa<*pindex;sa++)
						 {
							int btop=b->top+1;
							int bo=0;
							//notelar kadar
							for(int av=0;av<b->top+1;av++)
							{
								///sonuç sabit note un arr Id leri kıyaslaması
									if(b->arr[av]==arr[sa]->Id)
									{
										bo=1;
									}
							}
									
							if(bo==0)
							push1darray(stable,arr[sa]->Id);	
						}
							push2darray(i2,stable);	//bir sonucu invert etmesi gerekir.
				i=0;
				}
				else
				{
				pushStack(st2,a);	
				i++;
				}
				ia++;
			}         
				//fprintf(output,"Results:\n");
				    printf("Results:\n");
				for(int iz=0;iz<*pindex;iz++)
				{
					for(int l=0;l<i2->d1[0]->top+1;l++)
					{
						if((arr[iz]->Id)==i2->d1[0]->arr[l])
						{
							//fprintf(output,"Id: %d %s",arr[iz]->Id,arr[iz]->lines[0]);
						    printf("Id: %d %s",arr[iz]->Id,arr[iz]->lines[0]);
						    
						}
					}
				}
	}//find ending
	else if(strstr(line,"TAG")!=NULL)
	{
		char *tg;
		strtok(res," ");
		tg=strtok(NULL," ");
		char *in;
			
		while(1)
		{
		int i=0;
			in=strtok(NULL," ");
			if(strcmp(in,"-1\n")==0)
			{
				break;
			}
			else{
				char*n;
				n=(char*)malloc(strlen(in)+2);
				strcpy(n,in);
				while(arr[i]->Id!=atoi(n))
				{
					i++;
				}
				putTags(arr[i],tg);
				}
		}
	}

	else if(strstr(line,"DISPLAY")!=NULL)
	{
		char *id;
		strtok(res," ");
		id=strtok(NULL," ");
		int i=0;
		while((arr[i]->Id!=atoi(id)))
		{
			i++;	
		}
		printNote(arr[i],output);
	}
}
//fprintf
fclose(input);
fclose(output);
return 0;
}
struct d1int  startd1int(struct d1int *i)
{
i->Id=d1Id++;
i->cappa=5;
i->top=-1;
i->arr=(int*)malloc(sizeof(int)*i->cappa);
return *i;
}

void push1darray (struct d1int *i,int data)
{
	if(i->top>i->cappa)
	{
		i->arr=realloc(i->arr,sizeof(i->arr)*2);
		i->cappa*=2;
	}		
	i->top+=1;
	i->arr[i->top]=data;
}

int pop1darray(struct d1int *i)
{
	int data=i->arr[i->top--];
	return data; 
}

char* popSt(struct Stack *st)
{
	char *b;
	b=st->array[st->top];
	st->top-=1;	
	return b;
}
struct  Stack startStack(struct Stack *st)
{
st->top=-1;
st->cappa=5;
st->array=(char**)malloc(sizeof(char*)*st->cappa);
return *st;
}

void pushStack(struct Stack *n,char *a)
{
if(n->top>=n->cappa)
{
	n->cappa*=2;
	*n->array=realloc(*n->array,sizeof(char*)*n->cappa);
}
n->top++;
n->array[n->top]=(char*)malloc(sizeof(char)*(100));
strcpy(n->array[n->top],a);
}

void printNote(struct Note *n,FILE *output)
{
	fprintf(output,"Id: %d\n",n->Id);
	for(int i=0;i<n->lindex;i++)
	{
		fprintf(output,"%s",n->lines[i]);
	}
}
void putTags(struct Note *n,char *tag)
{
     if((n->tagIndex)>(n->tagCap))
        {
			
	       	n->tagCap*=2;
                n->tags=realloc(n->tags,sizeof(n->tags)*n->tagCap);
        }
        n->tags[n->tagIndex]=(char*)malloc(sizeof(char)*(strlen(tag)+1));
        strcpy(n->tags[n->tagIndex++],tag);
}
void putLines(struct Note *n,char*line)
{
	if((n->lindex)>(n->lcapacity))
	{
		n->lines=realloc(n->lines,sizeof(n->lines)*2);
		n->lcapacity*=2;
	}
	n->lines[n->lindex]=(char*)malloc(sizeof(char)*(strlen(line)+1));
	strcpy(n->lines[n->lindex++],line);
}

struct Note initializeNote(struct Note *n,char *id,char  *l)
{
	int a=atoi(id);
	n->Id=a;
	n->lindex=0;
	n->tagIndex=0;
	n->tagCap=2;
	n->lcapacity=2;
	n->lines=(char**)malloc(sizeof(char*)*n->lcapacity);
	n->tags=(char**)malloc(sizeof(char*)*n->tagCap);
	//strcpy(n->Id,id);
//l=
//return note gerekebilir function return type ını da düzelt öyle olursa
	return *n;
}	

//check cab give structs as arguent to this method
void push(struct Note **ar, int *index,struct Note *ptr, int *size, int *capacity)
{
	if(*index > *capacity)
     {
         *capacity *=2;
	     *ar=realloc(*ar, sizeof(struct Note) * *capacity); 
     }
     ar[(*index)++]=ptr;
     *size = *size + 1;
}
struct d2int startd2int(struct d2int *i)
{
i->top=-1;
i->cappa=5;
i->d1=(struct d1int**)malloc(sizeof(struct d1int)*i->cappa);
return *i;
}
void push2darray(struct d2int *i,struct d1int *d)
{
	if(i->top>i->cappa)
	{
		i->d1=realloc(i->d1,sizeof(i->d1)*2);
		i->cappa*=2;
	}

i->d1[++i->top] =(struct d1int*)malloc(sizeof(struct d1int));
i->d1[i->top]=d;
}
struct d1int* pop2darray(struct d2int *i)
{
return (i->d1[i->top--]);
}