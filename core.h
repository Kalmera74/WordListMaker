#define string char*
#define MAXLEN 25
#define PATH "_tmp/"

// Char Lists for Concanateing
char Lvl_1[3] = { '-', '_' };
char Lvl_2[7] = { '-', '_', '+', '&', '<', '>' };
char Lvl_3[16] = { '-', '_', '+', '&', '<', '>', '@', ',', ';', '|', '=', '/', '\\', '%' };
// Char Lists for Concanateing

//Function Prototypes//
char UpLo(char *W, bool md);
string UpLoScram(char *W, bool md);
string Reverse(char * W);
string strcat(string _w1, char _w2, string _w3);
int strlen(string arr[]);
size_t strlen(FILE *f);
node_t * Conc(string W, string _conList, string _list[]);
string ChrTNum(string W);
node_t* RFtL(FILE *f);
void RFtA(FILE *f, char s_arr[][MAXLEN]);
FILE *WLtF(void *pts, string l_typ, string f_name, string f_mode);
node_t * RRtL(string arr[], size_t rlen);
//Function Prototypes//


//SCRAMBEL FUCNTION WILL BE ADDED LATER

char UpLo(char *W, bool md){
	// 0=UPPER
	// 1=lower
	switch (md){//change the external funcs to your own
	case 0:
		return tolower(*W);
		break;
	case 1:
		return  toupper(*W);
		break;
	}
}

string UpLoScram(char *W, bool md){
	// 0=UPPER_lower
	// 1=lower_UPPER
	int _ss = strlen(W);
	char *_w = (char*)malloc(_ss*sizeof(*_w));

	switch(md){
	case 0:
		for (int i = 0; i <= _ss; i++){
			*(_w + i) = UpLo((W + i), (md = !md));
		}

		return _w;
		break;
	case 1:
		for (int i = 0; i <= _ss; i++){
			*(_w + i) = UpLo((W + i), (md = !md));
		}
		return _w;
		break;
	}

}

string Reverse(char * W){


		char _tmp, *_src, *_dst, *_w;
		size_t _len;

		_len = strlen(W);
		_w = (char*)malloc(_len*sizeof(*_w));

		if (_len > 1){
			strcpy(_w, W);
			_src = _w;
			_dst = _src + _len - 1;

			while (_src < _dst){
				_tmp = *_src;
				*_src++ = *_dst;
				*_dst-- = _tmp;
			}
			return _w;
		}
		else
			return W;

}

string strcat(string _w1, char _w2, string _w3){
	string TMP = (string)calloc(sizeof (TMP),((strlen(_w1) + strlen(_w3) + 1)));
	char _tmp[2] = { _w2, '\0' };

	strcat(TMP, _w1);
	strcat(TMP, _tmp);
	strcat(TMP, _w3);

	return TMP;
}

int strlen(char arr[][MAXLEN]){//ANY ARRAY THAT CAME MUST END WITH A NULL
	int i;
	for (i = 0; arr[i][0] != NULL; i++){}
	return i;

}
size_t strlen(FILE *f){
	char tmp[50];
	size_t i=0;
	while(fscanf(f,"%s",tmp)!=EOF)
		i++;
	rewind(f);
return i;
}
node_t * Conc(string W, string _conList, char _list[][MAXLEN] ){//STILL ADD IN A REVERSE ORDER//
//printf("%s\n",W);
	int _f2 = strlen(_conList);
	int _f3 = strlen(_list);

	node_t *t = NULL;

		for (int k = 0; k < _f2; k++){
			for (int j = 0; j < _f3;j++){
				
			//	if (t == NULL)
					t=add_beginning(t, (string)strcat(W, *(_conList + k), *((_list + 0) + j)));
			//	else
			//		add_after(t, (string)strcat(W, *(_conList + k), *((_list + 0) + j)));
			}
		}
	return t;
}

string ChrTNum(string W){
		int i=0;
	char *_w = (char*)malloc(strlen(W)*sizeof(*_w));
	strcpy(_w,W);
		for(int i=0;*(W+i)!=NULL;i++)
			switch(*(_w+i)){
			   
				case 'I':	     
				case 'l':
				case 'i':
					*(_w+i)='1';
					break;
				case 'g':
				case 'G':
				case 'q':
					*(_w+i)='9';
					break;
				case 's':
				case 'S':
					*(_w+i)='5';
					break;

				case 'b':
				case 'B':
					*(_w+i)='3';
					break;
				case 'o':
				case 'O':
					*(_w+i)='0';
					break;
				case 'a':
				case 'A':
					*(_w+i)='4';
					break;			
		}
		
		return _w;
	}

node_t *RFtL(FILE *f){
	node_t *t=NULL;
	char tmp[MAXLEN];
		while(fscanf(f,"%s",tmp)!=EOF)
			t = add_beginning(t,tmp);
return t;

}

void RFtA(FILE *f, char s_arr[][MAXLEN]){
	char tmp[MAXLEN];
	size_t i=0;	
		for (i;fscanf(f,"%s",tmp)!=EOF;i++){
			strcpy(s_arr[i],tmp);
//			printf("%s\n",s_arr[i]);
}
strcpy(s_arr[i],"\0");
}


string WLtF(void *ptl, char l_type, string f_name, string f_mode){
char pth[MAXLEN];
strcpy(pth,PATH);
FILE *f=fopen(strcat(pth,f_name),f_mode);

	switch(l_type){

		case 'a':
			for(int i=0;*((((string *)ptl)+0)+i)!=NULL;i++){
				fputs(*((((string *)ptl)+0)+i),f);
				fputs("\n",f);
			}
				break;
	case 'l':
			node_t *t=((node_t*)ptl);
			while(t!=NULL){
				fputs(t->data,f);
				fputs("\n",f);
				t=t->next;					
			}
			break;
	}
	fclose(f);
	string s=(string)malloc(sizeof(s)*strlen(PATH)+strlen(f_name)+1);strcpy(s,PATH);
return strcat(s,f_name);
//return f;
}

void WLtF(void *ptl, char l_type, FILE *f){

	switch(l_type){

		case 'a':
			for(int i=0;*((((string *)ptl)+0)+i)!=NULL;i++){
				fputs(*((((string *)ptl)+0)+i),f);
				fputs("\n",f);
			}
				break;
	case 'l':
			node_t *t=((node_t*)ptl);
			while(t!=NULL){
				fputs(t->data,f);
				fputs("\n",f);
				t=t->next;					
			}
			break;
	}
//	fclose(f);
}


node_t * RRtL(string arr[], size_t rlen){
		node_t *t=NULL;
		for(int i=0;i<=rlen;i++)
			t=add_beginning(t,arr[i]);
return t;
}
