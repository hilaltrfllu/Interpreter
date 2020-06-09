#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <unistd.h>
#include <stdbool.h>
void echo1(char *str);
void cp1(char *fs,char *fd);
int wc1(char opt,char *fname);
void cat1(char *fname);
int expr1(char *opnd1, char opr, char *opnd2);
void assign(char *lhs, int value);
int Search(char *par);
struct ParseTable {
	int exists; 	 // 1-exists, 0-does not exists
	char cmd[10];	 // command
	char par1[10];	 // parameter 1
	char par2[10];	 // parameter 2
	char par3[10];	 // parameter 3
	
};
struct ParseTable PT[3];
struct SymbolTable{
	char symbol[10];
	int value;
};
struct SymbolTable ST[20];

void echo1(char *str){
	int count=0;printf("%s",str);
	if(strlen(str) != 0 ){
		for(count;ST[count].symbol[0]!='\0';count++){
			//printf("ST symbol %s",ST[count].symbol);
			if(strcmp(str,ST[count].symbol)==0){
				//printf("found %d",ST[count].value);
			}
			else printf("%s",str);

			
		}
	}

}	
	/*int count=Search(str);
	if(count)
	{
		printf("%d\n",ST[count-1].value);
	}
	else
	{
		printf("%s\n",PT[0].par1);
		
		
	}*/


void cp1(char *fs,char *fd){
	int i=0;
	FILE *fp,*fp2;
	fp = fopen(fs,"r");
	fp2 = fopen(fd,"w");
	while(!feof(fp)){
		putc(getc(fp),fp2);
	}
	/*while(fs[i] != '\0'){
		fd[i] = fs[i];
		i++;
	}*/
	fclose(fp);
	fclose(fp2);
}

int wc1(char opt,char *fname){
	int w=0;
	int c=0;
	int l=0;
	
	FILE *fp;
	//getc(fname);
	fp = fopen(fname,"r");
	char ch;
	if (fp == NULL){
		exit(0);
	}
	ch = getc(fp);
	while (!feof(fp))
	{	
		
  		if (ch == '\n'){
			l++;
		}
		if(ch == ' ' || ch == '\n'){
			w++;
		}
		ch = getc(fp);
		c++;
	}
	
	//printf("OPT %d\n", opt);
	char wordcount = opt;
	if (wordcount == 'l'){
		printf("Total line count = %d\n",l);
		return l;
	}
	if(wordcount == 'w'){
		printf("Total word count = %d\n",w);
		return w;
	} 
	if(wordcount == 'c'){
		printf("Total character count = %d\n",c-l);
		return (c-l);
	}
	//fclose(fname);
}

void cat1(char *fname){
	//Open file
	char c;
	//c = fgetc(fname);
	FILE *fptr;
	fptr = fopen(fname, "r");
	if (fptr == NULL)
	{ 
		printf("Cannot open file \n"); 
		exit(0); 
	}
	// Read contents from file
	
	//printf("The contents of %s file are: \n",fname);
    else{
		c = fgetc(fptr);
		while (c != EOF)
		{
		    printf ("%c", c); //Display contents
		    c = fgetc(fptr); 
		} 
	}
	fclose(fptr);
}

int expr1(char *opnd1, char opr, char *opnd2){
	int n= atoi(opnd1);printf("%s =",PT[2].par1);
	int m= atoi(opnd2);int c;
	if(opr== '+'){
		c=n+m;
	}
	else if(opr== '-'){
		c=n-m;
	}
	else if(opr== '*'){
		c=n*m;
	}
	else if(opr== '/'){
		c=n/m;
	}
	else{
		c= n;
	}

	printf(" %d\n",c);
	
}


void assign(char *lhs, int value){
	bool flag=true;
	int k;
	int i;
	for(k=0; k<20; k++){
		int j=0;
		while(ST[k].symbol[j] != '\0'){
			j++;
		}
		for(i=0; i<strlen(lhs) || i<j ; i++){
			if(lhs[i] == ST[k].symbol[i]){
				if(i==j){
					lhs = ST[k].symbol;
					flag=false;
				}
			}
		}
	}
	if(flag){
		printf("%s",lhs);
	}
}

int main(){
	int st=1;int o=0;
	int r=0; 
	do{
		bool hi;
		char array[50];
		int  i=0,s=0,k=0,f=0;
		bool eq=false,pipe=false;
		printf("> ");
		fgets(array, 50, stdin);
		int size = strlen(array);
		//printf("Size of it: %d",size);
		array[size-1]='\0';		
		
		if(array[r] == '-') {
        	if(array[r+1]=='1') {
				return EXIT_SUCCESS;
			}
			break;        
    	}
while (i<size-1) {
	if(array[i]==' '){f++;}//boşluk sayıyor
	if(array[i]=='='){eq=true;}//eşit sayıyor
	if(array[i]=='|'){pipe=true;}//pipe tespit ediyor
	i++;
}//boşluk sayısını tespit ent makes integer fromettik

if (pipe){f-=3;}// pipe varsa -3 çünkü 2 extra boşluk oluyor, 2 boşluk 3 kelimeyi tutar.
int com_num=0;

while (s<=f) { //boşluk sayısından 1 fazla dönücek yani 2 boşluk varsa 3 kere 0 varsa 1 kere... s-> current word
	if (eq) {//assign var demektir
		eq=false;hi=true;
		int local_int=0;
		PT[2].exists=1;
		PT[2].cmd[0]='\0';
		PT[2].par1[0]='\0';	//insert here
		PT[2].par2[0]='\0';
		PT[2].par3[0]='\0';
		while (array[local_int]!='=') {
			PT[2].par1[local_int]=array[local_int];local_int++;k++;
		}PT[2].par1[local_int]='\0';k++;
	}

	if (array[k]=='\'') {k++;}
	if(s==0){ //sadece tek cmd var ise
		PT[com_num].exists=1;
		PT[com_num].par1[0]='\0';
		PT[com_num].par2[0]='\0';
		PT[com_num].par3[0]='\0';
		int local_int=0;
		while(array[k]!=' ' && k<size) {PT[com_num].cmd[local_int]=array[k];k++;local_int++;}	//cmd dolduruldu
		PT[com_num].cmd[local_int]='\0';k++;		//printf("\ncmd:%s /k: %d",PT[com_num].cmd,k);
		if(array[k]=='|'){k+=2;s=-1;com_num=1;}	//check and transfer for second part
	}else if(s==1) {// for ex: echo $1
		int local_int=0;
		while (array[k]!=' ' && k<size){
			if(array[k]!='$' && array[k]!='\''){
				PT[com_num].par1[local_int]=array[k];k++;local_int++;
			}
			else {k++;}
		}PT[com_num].par1[local_int]='\0';k++;	//printf("\npar1:%s",PT[com_num].par1);
		if(array[k]=='|'){k+=2;s=-1;com_num=1;}	//check and transfer for second part
	}else if(s==2) {// for ex: echo $2 $4
		int local_int=0;
		while (array[k]!=' ' && k<size) {
			if(array[k]!='$' && array[k]!='\''){
				PT[com_num].par2[local_int]=array[k];k++;local_int++;
			}
			else {k++;}
		}PT[com_num].par2[local_int]='\0';k++;	//printf("\npar2:%s",PT[com_num].par2);
		if(array[k]=='|'){k+=2;s=-1;com_num=1;}	//check and transfer for second part
	}else if(s==3) {// for ex: echo $1 + $3
		int local_int=0;
		while (array[k]!=' ' && k<size) {
			if(array[k]!='$' && array[k]!='\''){
				PT[com_num].par3[local_int]=array[k];k++;local_int++;
			}
			else {k++;}
		}PT[com_num].par3[local_int]='\0';k++;	//printf("\npar3:%s",PT[com_num].par3);
		if(array[k]=='|'){k+=2;s=-1;com_num=1;}	//check and transfer for second part
	}
	s++;
}

printf("\nLine1--> %d; %s; %s; %s; %s;",PT[0].exists,PT[0].cmd,PT[0].par1,PT[0].par2,PT[0].par3);
printf("\nLine2--> %d; %s; %s; %s; %s;",PT[1].exists,PT[1].cmd,PT[1].par1,PT[1].par2,PT[1].par3);
printf("\nLine3--> %d; %s; %s; %s; %s;\n",PT[2].exists,PT[2].cmd,PT[2].par1,PT[2].par2,PT[2].par3);
char des[10];
char src[10];
char echo[5] = "echo";char wc[3] = "wc";
char cp[3]= "cp";char cat[4]= "cat";char expr[5]="expr";
/*if(strcmp(echo,PT[0].cmd)==0){
	if(PT[0].par1 != '\0')	{ printf("\n%s ",PT[0].par1);
		if(PT[0].par2 != '\0')	{ printf(" %s ",PT[0].par2);
			if(PT[0].par3 != '\0')	{ printf(" %s ",PT[0].par3);}}}		
}*/
if(strcmp(cp,PT[0].cmd)==0){
	strcpy(src,PT[0].par1);strcpy(des,PT[0].par2);
	//cp(*src,*des);
}
for(int i = 0; PT[0].par1[i] != '\0'; ++i)
    {
        ST[0].symbol[i] = PT[0].par1[i];
    }
if(strlen(PT[0].cmd)==0 && hi){
//printf("impressive\n");printf("PT par2 : %c",PT[0].par2[0]);
if(o<20){
	strcpy(ST[o].symbol,PT[2].par1);printf("symbol: %s",ST[o].symbol);
	int n= atoi(PT[0].par1);
	int m= atoi(PT[0].par3);
	if(PT[0].par2[0]== '+'){
		ST[o].value=n+m;
	}
	else if(PT[0].par2[0]== '-'){
		ST[o].value=n-m;
	}
	else if(PT[0].par2[0]== '*'){
		ST[o].value=n*m;
	}
	else if(PT[0].par2[0]== '/'){
		ST[o].value=n/m;
	}
	else{
		ST[o].value = n;
	}

	printf(" value %d\n",ST[o].value);printf("index of ST : %d",o);
	o++;
}

}
hi=false;
//printf("COMMAND: %s par1: %c\n", PT[0].cmd, PT[0].par1);
if(strcmp(echo,PT[0].cmd)==0){//printf("hiecho\n");
	echo1(PT[0].par1);
}
else if(strcmp(cp,PT[0].cmd)==0){//printf("hicp\n");
	cp1(PT[0].par1,PT[0].par2);
}
else if(strcmp(wc,PT[0].cmd)==0){//printf("hiwc\n");
	wc1(PT[0].par1[0],PT[0].par2);
}
else if(strcmp(cat,PT[0].cmd)==0){//printf("hicat\n");
	cat1(PT[0].par1);
}
else if(strcmp(expr,PT[0].cmd)==0){//printf("hiexpr\n");
	expr1(PT[0].par1,PT[0].par2[0],PT[0].par3);
}
/*else if(PT[3].cmd != '\0'){printf(//"hielse\n");
	assign(PT[3].par1,ST[0].value);
}*/


//////////////////////////////
		
		
	}while(st);
	/*FILE *file = fopen(argv[1],"r");
	wc('c',file);
	fclose(file);*/
	return EXIT_SUCCESS;
}
