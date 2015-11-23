#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>
void pass1(char[],char[],int[],char[],FILE *,FILE *,FILE *,int *);
void pass2(char[],char [],int [],FILE *,FILE *,FILE *);
void objprog(char[],int [],int);
int hexvalue( int,int,int,int,int);
int main()
{     char a[20],b[10],pname[50];
 int d[60],size;
	 FILE *fp1 = fopen("sym.txt", "w");
      FILE *fp2 = fopen("int.txt", "w");
    FILE *f = fopen("input4.txt", "r");
     pass1( a,b,d,pname,fp1,fp2,f,&size);
      fp1 = fopen("sym.txt", "r");
       f = fopen("int.txt", "r");
     fp2 = fopen("object.txt", "w");
     pass2( a,b,d,fp1,fp2,f);
     objprog(pname,d,size);   
	 	
}
void pass1( char a[50],char b[10],int d[60],char pname[50],FILE *fp1,FILE *fp2,FILE *f,int *size) 
 {
 	int byte,locctr,count=0,length,i=0,j,gopcode;
 	char c;
 	fscanf(f,"%s",pname);
     fprintf(fp2,"%s",pname);
      fprintf(fp2,"%c",' ');
    fscanf(f,"%s",b);
     fprintf(fp2,"%s",b);
    fscanf(f,"%x",&locctr);
     fprintf(fp2,"%c",' ');
     fprintf(fp2,"%04x",locctr);
     fprintf(fp2,"%c",'\n');
    while(fscanf(f,"%s",a)!=EOF)
   {     
         printf("%s",a);
         count=0;
         byte=0;
          FILE *fp = fopen("optab1.txt", "r");
    	while(fscanf(fp,"%s",b)!=EOF)
    	{
    		if(strcmp(a,b)==0)
    		{
    			 fprintf(fp2,"%c",' ');
    			  fprintf(fp2,"%s",a);
    			  fscanf(fp,"%x",&byte);
    			  if(strcmp(a,"RSUB")!=0&&byte!=1)
    			  {
    			  
    			     fscanf(f,"%s",a);
    			      printf("%s",a);
    			      fprintf(fp2,"%c",' ');
    			       fprintf(fp2,"%s",a);
    			       fscanf(f,"%s",a);
    			      printf("%s",a);
    			      fprintf(fp2,"%c",' ');
    			       fprintf(fp2,"%s",a);
    		      }
    		      
    			fprintf(fp2,"%c",' ');
    			 fprintf(fp2,"%04x",locctr);
    			 d[i]=locctr;
    			 i++;
    			 fprintf(fp2,"%c",'\n');
    			locctr=locctr+byte;
    			count++;
    			break;
    		}
    		
    	}
    	fclose(fp);
    
    	if (count==0)
    	{
    		if(strcmp(a,"WORD")==0)
    		{
    			fprintf(fp2,"%c",' ');
    			fprintf(fp2,"%s",a);
    		    fprintf(fp2,"%c",' ');
    		    fscanf(f,"%d",&byte);
    		    fprintf(fp2,"%d",byte);
    		    	fprintf(fp2,"%c",' ');
    		    fprintf(fp2,"%04x",locctr);
    		     d[i]=locctr;
    			 i++;
    		    	 fprintf(fp2,"%c",'\n');
    			locctr=locctr+3;
    			count++;
    			fprintf(fp2,"%c",' ');

    		}
    		else if(strcmp(a,"RESW")==0)
    		
    		{
    			fprintf(fp2,"%c",' ');
    			fprintf(fp2,"%s",a);
    		    fprintf(fp2,"%c",' ');
    		fscanf(f,"%d",&byte);
    		 fprintf(fp2,"%d",byte);
    		 	fprintf(fp2,"%c",' ');
    		 fprintf(fp2,"%04x",locctr);
    		  d[i]=locctr;
    			 i++;
    		 	 fprintf(fp2,"%c",'\n');
    		byte=3*byte;
    		locctr=locctr+byte;
    		count++;
    		}
    		else if(strcmp(a,"RESB")==0)
    		{
    			fprintf(fp2,"%c",' ');
    			fprintf(fp2,"%s",a);
    		    fprintf(fp2,"%c",' ');
    	     	fscanf(f,"%d",&byte);
    		    fprintf(fp2,"%d",byte);
    		 	fprintf(fp2,"%c",' ');
    		 	fprintf(fp2,"%04x",locctr);
    		 	 d[i]=locctr;
    			 i++;
    		 		 fprintf(fp2,"%c",'\n');
    		locctr=locctr+byte;
    		count++;
    		}
    		else if(strcmp(a,"BYTE")==0)
    		{
    			
    			fprintf(fp2,"%c",' ');
    			fprintf(fp2,"%s",a);
    		    fprintf(fp2,"%c",' ');
    			fscanf(f,"%c",&c);
    			fscanf(f,"%c",&c);
                fprintf(fp2,"%c",c);    	
    			fscanf(f,"%s",a);
    			fprintf(fp2,"%s",a);
    		   fprintf(fp2,"%c",' ');
    		   	fprintf(fp2,"%04x",locctr);
    		   	 d[i]=locctr;
    			 i++;
    		   		 fprintf(fp2,"%c",'\n');
    			if(c=='X')
    			{
    			
    				length=strlen(a);
    				length=length/2;
    				locctr=locctr+length;
    				count++;
    				
    			}
    			else if(c=='C')
    			{
    				length=strlen(a);
    				printf("\n\n hello");
    				locctr=locctr+length;
    				count++;
    			}
    			
    		}

    		
    		
    	}
    		if(count==0)
    		{
    			 fprintf(fp2,"%s",a);
    		 fprintf(fp1,"%s",a);
    		 fprintf(fp1,"%c",' ');
    		 fprintf(fp1,"%04x",locctr);
    		 fprintf(fp1,"%c",'\n');
    		}
    	
   } 
   int start;
   start=d[j];
   for(j=0;j<i;j++)
   {
   	printf("\n%x",d[j]);
   }
   *size=d[j-1];
   *size=*size-start+1;
	fclose(fp1);
    fclose(f);
    fclose(fp2);
    
}


void pass2( char a[50],char b[10],int d[60],FILE *fp1,FILE *fp2,FILE *f)
 {
 	  char c,temp2[10],temp1[10],reg[10],A;
      int byte,locctr,assign,n,count=0,checker=0,length,i=1,e,l,x,y,ta=0,j,disp=0,pc,p,opcode,f1,r,zero,f2,f3,hexadecimalval = 0,k=1,remainder,hex[50],temp;
      FILE *fp3;
      fp1 = fopen("sym.txt", "r");
      f = fopen("int.txt", "r");
      fp2 = fopen("object.txt", "w");   
      fscanf(f,"%s",b);
      printf("%s",b);
      fprintf(fp2,"%s",b);
      fprintf(fp2,"%c",' ');
      fscanf(f,"%s",b);
      printf("%s",b);
      fprintf(fp2,"%s",b);
      fscanf(f,"%x",&locctr);
      printf("%x",locctr);
      fprintf(fp2,"%c",' ');
      fprintf(fp2,"%04x",locctr);
      fprintf(fp2,"%c",'\n');
      int hello=0,word=0,resw=0,byte1=0,tc=0;
      while(fscanf(f,"%s",a)!=EOF)
       {     
         count=0;
         FILE *fp = fopen("optab1.txt", "r");
    	 while(fscanf(fp,"%s",b)!=EOF)
    	 {
    		if(strcmp(a,b)==0)
    		{    
    		     count++;
    			 fprintf(fp2,"%c",' ');
    			  fprintf(fp2,"%s",a);
    			  fprintf(fp2,"%c",' ');
    			  fscanf(fp,"%x",&byte);
    			  if(byte==3)
    			  {
    			  	e=1;
    			  	l=1;
    		       }
    			  else if(byte==2)
    			  {
    			  	e=0;
    			  	l=1;
    			  	
    			  }
    			  else if (byte==1)
    			  {
    			  	e=0;
    			  	l=0;
    			  }
    			  fscanf(fp,"%x",&opcode);
    			  if (e==0&&l==0||strcmp(a,"RSUB")==0)
    			  {
    			  	i++;
    			  	if(strcmp(a,"RSUB")==0)
    			  	{
    			  		fscanf(f,"%x",&locctr);
                     fprintf(fp2,"%04x",locctr);
                     fprintf(fp2,"%c",' ');
    			  	   fprintf(fp2,"%02x",opcode);
    			  	   fprintf(fp2,"%s","000000");
    			  	    fprintf(fp2,"%c",'\n');
    			  	   
					  }
					  else
					  {
					  
    			  	    fscanf(f,"%x",&locctr);
                        fprintf(fp2,"%04x",locctr);
                        fprintf(fp2,"%c",' ');
    			  	    fprintf(fp2,"%x",opcode);
					    fprintf(fp2,"%s","000000");
					    fprintf(fp2,"%c",'\n');
				      }
					   
				  }
				  else if(e==0&l==1)
				  {
				  	 i++;
				  	 fscanf(f,"%s",a);
				  	 fprintf(fp2,"%s",a);
				  	 fprintf(fp2,"%c",' ');
    			  	 fscanf(f,"%s",reg);
    			     fprintf(fp2,"%s",reg);
    			  	 fprintf(fp2,"%c",' ');
    			  	 fscanf(f,"%x",&locctr);
                     fprintf(fp2,"%04x",locctr);
                     fprintf(fp2,"%c",' ');
                     fprintf(fp2,"%02x",opcode);
                     if(strcmp(a,"$")!=0)
                     {
                     fprintf(fp2,"%d",a[0]);
                     assign=0;
                    }
                    else
                    {
                    	
                    	assign=1;
                    }
                    fprintf(fp2,"%d",reg[0]);
                      if(assign==1)
                     {
                     	
                     	fprintf(fp2,"%d",'A');
                     }
                     
                     fprintf(fp2,"%s","00");
                     fprintf(fp2,"%c",'\n');
				  	
				  }
    			  else
    			  {
    			     fscanf(f,"%s",a);
    			     fprintf(fp2,"%s",a);
    			      if(strcmp(a,"@")==0)
    			      {
    			      	x=0;
    			      	y=0;
    			      	p=1;
    			      	f1=0;
    			      	f2=0;
    			      	f3=0;
    			      	fscanf(f,"%s",a);
    			      	fprintf(fp2,"%c", ' ');
    			      	 fprintf(fp2,"%s",a);
    			      	 fprintf(fp2,"%c",' ');
    			      	 fp1=fopen("sym.txt","r");
    			      	while(fscanf(fp1,"%s",b)!=EOF)
    			      	   {
    			      	       if(strcmp(a,b)==0)
						       {
						       	tc++;
						       	fscanf(fp1,"%x",&ta);
						       	printf(" \n\nta =%x",ta);
						     	pc=d[i];
							  	i++;
							  	break;
							    }
    			      		
    			      	    }
    			      	       fclose(fp1);
    			      	       disp=ta-pc;
							if(disp<0)
    			      	    {
	                                   sprintf(temp2,"%x",disp);
	                                   strncpy(temp1,temp2+4,4);
	                                  sscanf(temp1,"%x",&disp);
                                    	printf("\n%x",x);
							}
							    fscanf(f,"%x",&locctr);
                                fprintf(fp2,"%04x",locctr);
                                fprintf(fp2,"%c",' ');
							    fprintf(fp2,"%02x",opcode);
							    hexadecimalval=hexvalue(x,y,p,e,l);
							     fprintf(fp2,"%lX", hexadecimalval);         
							     fprintf(fp2,"%04x",disp);
							     fprintf(fp2,"%c",'\n');
                           
					  }	
    			      else if(strcmp(a,"#")==0)
    			      {
    			      	x=0;
    			      	y=1;
    			      	p=0;
    			      	f1=0;
    			      	f2=0;
    			      	f3=0;
    			      	fprintf(fp2,"%c",' ');
    			      	fscanf(f,"%d",&disp);
    			      	fprintf(fp2,"%d",disp);
    			      	fp3 = fopen("io.txt", "w");
    		            fprintf(fp3,"%x",disp);
    		            fclose(fp3);
    		            fp3 = fopen("io.txt", "r");
    		            fscanf(fp3,"%x",&disp);
    		            fclose(fp3);
    			      	fprintf(fp2,"%c",' ');
    			      	fscanf(f,"%x",&locctr);
                        fprintf(fp2,"%04x",locctr);
                        fprintf(fp2,"%c",' ');
    			      	fprintf(fp2,"%02x",opcode);
    			      	hexadecimalval=hexvalue(x,y,p,e,l);
							             fprintf(fp2,"%lX", hexadecimalval);
						                 fprintf(fp2,"%04x",disp);
						                  fprintf(fp2,"%c",'\n');
    			      	                   i++;
    			      }
    			      else if(strcmp(a,"*")==0)
    			      {
    			      	x=1;
    			      	y=1;
						p=1;
						f1=0;
						f2=0;
						f3=0;
    			      	fscanf(f,"%s",a);
    			      	fprintf(fp2,"%c", ' ');
    			      	 fprintf(fp2,"%s",a);
    			      	 fprintf(fp2,"%c",' ');
    			      	   fp1=fopen("sym.txt","r");
    			      	while(fscanf(fp1,"%s",b)!=EOF)
    			      	 {
    			      		if(strcmp(a,b)==0)
							  {
							  	fscanf(fp1,"%x",&ta);
							  	pc=d[i];
							  	i++;
							  	break;
							  }
    			      		
    			      	 }
    			      	 fclose(fp1);
    			      	 disp=ta-pc;
    			      	 int m;
    			      	 m=0;
    			      	    if(disp<0)
    			      	    {
    			      	                sprintf(temp2,"%x",disp);
	                                   strncpy(temp1,temp2+4,4);
	                                  sscanf(temp1,"%x",&disp);
                                    	printf("\n%x",x);
                                    	m++;
							}
							    fscanf(f,"%x",&locctr);
                                fprintf(fp2,"%04x",locctr);
                                fprintf(fp2,"%c",' ');
							    fprintf(fp2,"%02x",opcode);
							    hexadecimalval=hexvalue(x,y,p,e,l);
							    fprintf(fp2,"%lX", hexadecimalval);
							     fprintf(fp2,"%04x",disp);
							     fprintf(fp2,"%c",'\n');
    

    		      }
		         }
		    break;
		    }
		 }
		 fclose(fp);
             
    		     if(strcmp(a,"WORD")==0&&count==0)
    		   {     
    		         word++;
    		     	count++;
    			    fprintf(fp2,"%c",' ');
    			    fprintf(fp2,"%s",a);
    		        fprintf(fp2,"%c",' ');
    		        fscanf(f,"%d",&byte);
    		        fprintf(fp2,"%d",byte);
    		        fprintf(fp2,"%c",' ');
    		        fp3 = fopen("io.txt", "w");
    		        fprintf(fp3,"%x",byte);
    		        fclose(fp3);
    		        fp3 = fopen("io.txt", "r");
    		        fscanf(fp3,"%x",&byte);
    		        fclose(fp3);
    		        fscanf(f,"%x",&locctr);
                    fprintf(fp2,"%04x",locctr);
                    fprintf(fp2,"%c",' ');
							 fprintf(fp2,"%06x",byte);
							 fprintf(fp2,"%c",'\n');   
							 i++;
 
    	   	    }
    	
    		    else if(strcmp(a,"BYTE")==0&&count==0)
    		   {
    		   	byte1++;
    			count++;
    			fprintf(fp2,"%c",' ');
    			fprintf(fp2,"%s",a);
    		    fprintf(fp2,"%c",' ');
    			fscanf(f,"%c",&c);
    			fscanf(f,"%c",&c);
                fprintf(fp2,"%c",c); 	
    			fscanf(f,"%s",a);
    			fprintf(fp2,"%s",a);
    		    fprintf(fp2,"%c",' ');
    		    fscanf(f,"%x",&locctr);
                fprintf(fp2,"%04x",locctr);
                fprintf(fp2,"%c",' ');
    		   int k=0;
    			if(c=='C')
    			{
    				while(a[k]!='\0')
                 	{
                 	
		              c=a[k];
		              k++;
		              fprintf(fp2,"%x",c);
	                }
    			
    				
    			}
    			else if(c=='X')
    			{
    				fprintf(fp2,"%c",' ');
    				fprintf(fp2,"%s",a);
    				
    			}
    				fprintf(fp2,"%c",'\n');
    				i++;
    			
    	       }
    	        		  
         		if(count==0)
    		{
    		 
    		
    		 if(strcmp(a,"RESB")==0||strcmp(a,"RESW")==0)
    		 {
    		 	fprintf(fp2,"%c",' ');
    		 	i++;
    		 	
			 }
			 fprintf(fp2,"%s",a);
			 fprintf(fp2,"%c",' ');
			  if(strcmp(a,"RESB")==0||strcmp(a,"RESW")==0)
    		 {
    		 	resw++;
    		 	fscanf(f,"%s",a);
    		 	fprintf(fp2,"%c",' ');
    		 	fprintf(fp2,"%s",a);
    		 	fscanf(f,"%s",a);
    		 	fprintf(fp2,"%c",' ');
    		 	fprintf(fp2,"%s",a);
    		 	fprintf(fp2,"%c",'\n');
    		 	
    		 	
	
			 }
    		}
        }
       fclose(f);
       fclose(fp2);
}

void objprog( char pname[50],int d[60],int size)
   {
    FILE  *f = fopen("object.txt", "r");
    FILE *fp2 = fopen("objectprog.txt", "w");
   	int j=0,l,re,n=0,addr,i=0,resw=0,t1=0,counter=0,r,length,byte;
   	char a[50];
   	fprintf(fp2,"%s","HEADER");
   	fprintf(fp2,"%c",'^');
   	fprintf(fp2,"%s",pname);
   	l=strlen(pname);
   	re=10-l;
   	while(n<re)
   	{
   		fprintf(fp2,"%c",' ');
   		fprintf(fp2,"%c",'_');
   		n++;
   		
	}
	n=0;
	fprintf(fp2,"%c",'^');
    fprintf(fp2,"%04d",d[i]);
   	fprintf(fp2,"%c",'^');
    fprintf(fp2,"%04x",size);
    fprintf(fp2,"%c",'\n');
    fscanf(f,"%s",a);
    fscanf(f,"%s",a);
    fscanf(f,"%s",a);
    fprintf(fp2,"%s","TEXT");
    fprintf(fp2,"%c",'^');
    fprintf(fp2,"%04x",d[i]);
    fprintf(fp2,"%c",'^');
	int count=0,round=0;
	char c,b[50];
    while(fscanf(f,"%s",a)!=EOF)
    {
         count=0;
         round=0;
          FILE *fp = fopen("optab1.txt", "r");
    	while(fscanf(fp,"%s",b)!=EOF)
    	{
    		if(strcmp(a,b)==0)
    		{  
    		    
    		     count++;
    		      if(strcmp(a,"RSUB")==0||strcmp(a,"TIO")==0)
    		      {
    		      	
    		      }
    		      else
    		      {
    			     fscanf(f,"%s",a);
    			    fscanf(f,"%s",a);
    		
    	          }
				counter=counter+4;
				if(counter<=20)
				{
					fscanf(f,"%s",a);
					if(resw==1)
				  {
					fprintf(fp2,"%s",a);
					fprintf(fp2,"%c",'^');
					resw=0;
			      }
					fscanf(f,"%s",a);
					fprintf(fp2,"%s",a);
					printf("\n");
					printf("%s",a);
					fprintf(fp2,"%c",'^');

				}
				else
				{   
				     counter=counter-4;
				     fprintf(fp2,"%c",'S');
				     fprintf(fp2,"%x",counter);
				     counter=0;
					 fprintf(fp2,"%c",'\n');
				     fprintf(fp2,"%s","TEXT");
				     fprintf(fp2,"%c",'^');
    				 fscanf(f,"%x",&addr);
                     fprintf(fp2,"%04x",addr);
                     fprintf(fp2,"%c",'^');
                     fscanf(f,"%s",a);
					 fprintf(fp2,"%s",a);
					  counter=counter+4;
					 fprintf(fp2,"%c",'^');	


				
				}
				
    			break;
    			
         	}
        }
              fclose(fp);
      if(count==0)
       {
           
		   if(strcmp(a,"BYTE")==0)
           { 	
                 
           	    fscanf(f,"%c",&c);
    			fscanf(f,"%c",&c);   	
    			fscanf(f,"%s",a);
    			if(c=='X')
    			{
    				length=strlen(a);
    				length=length/2;
    				counter=counter+length;
    				
    			}
    			else if(c=='C')
    			{
    				  
    				length=strlen(a);
    				counter=counter+length;
    			}
    			
    			if(counter<=20)
				{
					  
					fscanf(f,"%s",a);
					if(resw==1)
				 {
					fprintf(fp2,"%s",a);
					fprintf(fp2,"%c",'^');
					resw=0;
				 }
					fscanf(f,"%s",a);
					fprintf(fp2,"%s",a);
					printf("%s",a);
					fprintf(fp2,"%c",'^');

				}
				else
				{
					counter=counter-length;
					fprintf(fp2,"%c",'S');
				    fprintf(fp2,"%x",counter);
				    counter=0;
					fprintf(fp2,"%c",'\n');
				    fprintf(fp2,"%s","TEXT");
    				fscanf(f,"%x",&addr);
    				fprintf(fp2,"%c",'^');
                    fprintf(fp2,"%04x",addr);
                    fprintf(fp2,"%c",'^');
					fscanf(f,"%s",a);
					fprintf(fp2,"%s",a);
					 counter=counter+length;
					fprintf(fp2,"%c",'^');	


					
				}
	

    			
    			
           	
           } 
           
           
            else if(strcmp(a,"WORD")==0)
    		{
    			count++;
    		    fscanf(f,"%d",&byte);
    			counter=counter+3;
    			if(counter<=20)
				{
					fscanf(f,"%s",a);
					if(resw==1)
				   {
					fprintf(fp2,"%s",a);
							fprintf(fp2,"%c",'^');
					resw=0;
				   }
					fscanf(f,"%s",a);
					fprintf(fp2,"%s",a);
					fprintf(fp2,"%c",'^');

				}
				else
				{
					counter=counter-3;
					fprintf(fp2,"%c",'S');
				    fprintf(fp2,"%x",counter);
				    counter=0;
					fprintf(fp2,"%c",'\n');
				    fprintf(fp2,"%s","TEXT");
    				fscanf(f,"%x",&addr);
    				 fprintf(fp2,"%c",'^');
    				 n=addr;
    				 fprintf(fp2,"%04x",addr);
                     fprintf(fp2,"%c",'^');
					 fscanf(f,"%s",a);
					 fprintf(fp2,"%s",a);
					 counter=counter+3;
					 fprintf(fp2,"%s",'^');	


					
				}
            }
    		else if(strcmp(a,"RESW")==0||strcmp(a,"RESB")==0)
    		{    
    		    
    			fscanf(f,"%s",a);
    			fscanf(f,"%s",a);
    			if(resw==0)
    			{
    			fprintf(fp2,"%c",'S');
				fprintf(fp2,"%x",counter);
				counter=0;
				fprintf(fp2,"%c",'\n');
				fprintf(fp2,"%s","TEXT");
				fprintf(fp2,"%c",'^');
				resw++;
                }
            }
	   }
	     	
    }
    fclose(f);
     i=0;
     j=0;
      fprintf(fp2,"%c",'s');
       fprintf(fp2,"%x",counter);
    fprintf(fp2,"%c",'\n');
    fprintf(fp2,"%s","END");
	fprintf(fp2,"%c",'^');
    fprintf(fp2,"%04x",d[i]);
    fclose(fp2);
   }
   int hexvalue(int x,int y,int p,int e,int l)
     {
     	int f1=0,f2=0,f3=0;
     	int j=0,hexadecimalval=0,hex[10]
								,k=1,remainder;
							    hex[j]=x;
							    j++;
							    hex[j]=y;
							    j++;
							    hex[j]=p;
							    j++;
							    hex[j]=e;
							    j++;
							    hex[j]=l;
							    j++;
							    hex[j]=f1;
							    j++;
							    hex[j]=f2;
							    j++;
							    hex[j]=f3;
							    
							            
							             for(j=7;j>=0;j--)
                                    	{
                                            remainder = hex[j];
                                            hexadecimalval = hexadecimalval + remainder * k;
                                             k = k * 2;
                                         }
                                         return(hexadecimalval);
			
     	
     }
  



