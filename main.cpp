#include<ctype.h>
#include<inttypes.h>
#include"linked_list.h"
#include"core.h"

int main(int argc, char *argv[]){

FILE *fin,*fout;
char mode;

for(int i=0;i<argc;i++){//put some error check aginst wrong file names and etc.
	if(strcmp(argv[i],"if")==0){
		fin=fopen(argv[i+1],"r");
	}
	
	else if(strcmp(argv[i],"of")==0){
		fout=fopen(argv[i+1],"a");
	}
		else if(strcmp(argv[i],"m")==0){
			if(strcmp(argv[i+1],"0")==0){mode='0';}
			else if(strcmp(argv[i+1],"1")==0){mode='1';}
			else if(strcmp(argv[i+1],"2")==0){mode='2';}	
	}

	else if(strcmp(argv[i],"w")==0){
		char wlist[6][MAXLEN];
		for(int k=0;k<(argc-i);k++){
			strcpy(wlist[k],argv[i+k+1]);
			//printf("%s\n",wlist[k]);
		}
	}
//	else{}	
}
switch(mode){

	case '0':
	node_t *upls,*ctn;
	upls=ctn=NULL;	

	if(fin!=NULL){
		size_t srs=strlen(fin);
		char sr[srs][MAXLEN];
		RFtA(fin,sr);
	
	for(int i=0;i<=srs;i++){
		upls=add_beginning(upls,UpLoScram(sr[i],0));
		ctn=add_beginning(ctn,ChrTNum(sr[i]));
	}

	FILE *uplsF=fopen(WLtF(upls,'l',"upls.txt","w"),"r");
	FILE *ctnF=fopen(WLtF(ctn,'l',"ctn.txt","w"),"r");

	char scr1[srs][MAXLEN];
	char scr2[srs+srs][MAXLEN];

	
	RFtA(uplsF,scr1);
for(int i=0;i<=srs;i++)
	strcpy(scr2[i],scr1[i]);
	RFtA(ctnF,scr1);
	int k=0;
for(int i=srs;i<=srs+srs;i++)
	strcpy(scr2[i],scr1[k++]);


node_t *t=NULL;
	
	for(int i=0;i<srs+srs;i++){
			t=Conc(scr2[i],Lvl_3,scr2);		
		WLtF(t,'l',fout);

	}
}
		break;

	case '1':

		break;
	
	case '2':

		break;


}

return 0;
}
