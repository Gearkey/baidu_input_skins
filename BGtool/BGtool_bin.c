//char font[],char color[],int size,int more,int width,int y_start,char til_name[],int style_start,char remark[]

//sprintf(part,"/mnt/sdcard/Baidutool/%s.txt",til_name);

//font[],color[],size,more,width,y_start,til_name[],style_start,remark[]

/*printf("方式‖1>平均值法\n　　‖2>层次算法\n　　‖3>标准相增\n　　‖4>逐键输入\n　　‖选择:");
//scanf("%d",&set_choose);*/

skin_maker_set_average()
{
/*wn=(wm-gap*(keys-1))/keys;
printf("结果‖标准值为:%d\n",wn);
wn=gap*(keys-1)+wn*keys;
more=wm-wn;
printf("　　‖需要闰%d个像素\n\n",more);*/
return 0;
}

/*int skin_maker_set_average();
int skin_maker_set_level();
int skin_maker_set_zero();
int skin_maker_set_onebyone();
int skin_maker_easier(int);*/

int level,level_w,level_wv,level_keys;
int zero[10],zerov[10];


int material_maker_easier(int choose)
{
switch (choose)
{
case 1:{
	p_myfont = result[1];
	p_rectangle = result[2];
	p_takecss = result[3];
	p_notecss = result[4];
	p_mycssnote = result[5];
	p_subline = result[6];
	break;
	}
case 2:{
	p_exact = result[1];
	p_empty = result[2];
	p_placehold = result[3];
	p_num_placehold = result[4];
	p_preset = result[5];
	break;
	}
case 3:{
	p_en = result[1];
	p_ens = result[2];
	p_nums = result[3];
	p_symbles = result[4];
	break;
	}
default:
	error(2);
	break;
}
return 0;
}

int skin_maker_easier(int choose)
{
switch (choose)
{
case 1:{
	p_up = result[1];
	p_down = result[2];
	p_pos = result[3];
	p_show = result[4];
	p_hold = result[5];
	p_visual = result[6];
	p_advanced = result[7];
	break;
	}
case 2:{
	p_left = result[1];
	p_right = result[2];
	p_holdsym = result[3];
	p_touch = result[4];
	p_start = result[5];
	p_top_margin = result[6];
	p_left_margin = result[7];
	p_only_pos = result[8];
	break;
	}
default:
	error(2);
	break;
}
return 0;
}


if (p_preset != true){

else {
	for (i=0;i<n;i++){
		for (ii=0;ii<=nn;ii++){
			y=size*(ii+1)-(size+3)/7+more*i*2+more+y_start;
			if (debug_mode==true)
				printf("	<text align=\"center\" x=\"0.0\" y=\"%d.0\" rotate=\"0\" size=\"%d\" font=\"%s.ttf\" text=\"%c\" color=\"#%s\" autoScaleX=\"0\" scaleX=\"1.0\" flags=\"65\" />\n",y,size,font,*(*(&names+i)+ii),color);
			else
				fprintf(fp,"	<text align=\"center\" x=\"0.0\" y=\"%d.0\" rotate=\"0\" size=\"%d\" font=\"%s.ttf\" text=\"%c\" color=\"#%s\" autoScaleX=\"0\" scaleX=\"1.0\" flags=\"65\" />\n",y,size,font,*(*(&names+i)+ii),color);
			}
		}
	}


char *tem;
char en[] = "q   w   e   r   t   y   u   i   o   p   a   s   d   f   g   h   j   k   l   z   x   c   v   b   n   m";
char ens[] = "Q   W   E   R   T   Y   U   I   O   P   A   S   D   F   G   H   J   K   L   Z   X   C   V   B   N   M";
char num[] = "1   2   3   4   5   6   7   8   9   0";

/*	n += 1;
	nn += 26;
	strcpy(&names+n-1,en);
	printf("%s",&names);*/


int skin_maker_visual()
{
int grick = width/40;
int sike,n_sike = 1;
for (j = 0;j < lines;j++){
	for (i=0;i < keys[line];i++){
		if (w[line][i] != 0){
			if (sike == w[line][i]){
				n_sike ++;
				if (sike != w[line][i+1]){
					printf("*%d",n_sike);
					for (ii=0;ii < sike * n_sike / grick - 4;ii++){
						printf(" ");
						}
					printf("]");
					}
				}
			else{
				printf("[%d",w[line][i]);
				sike = w[line][i];
				}
			/*if (w[line][i+1] != w[line][i]){
				printf("[%d]",w[line][i]);
				}
			else if (w[line][i-1] != w[line][i]){
				printf("[%d",w[line][i]);
				}
			else if (w[line][i-1] == w[line][i]){
				n++;
				}
			else {
				printf("*%d",n);
				printf("]");
				}*/
			}
		else {
//			for (ii=0;ii < w[line][i]/grick;ii++)
				printf("[︿]");
			}
		}
	printf("\n");
	}
return 0;
}

int skin_maker_visual()
{
int key_tmp;
int grick = width/40;
int sike,n_sike = 1;
for (j = 0;j < lines;j++){
	printf("[");
	for (i=0;i < keys[j];i++){
		key_tmp = w[j][i];
		for (jj=0;key_tmp == w[j][i+jj];jj++){}
		printf("|%d",key_tmp);
		if (jj != 1)
			printf("*%d",jj);
		jj --;
		i += jj;
		}
	printf("]");
	printf("\n");
	}
NEXT
return 0;
}

		n_sike = key_tmp * jj / grick;
		n_sike -= 4;
		for (k=0;k < n_sike;k++)
			printf(" ");

int extract_num(char *base)
{
int d;
d=0;
for (i=0;i < strlen(base);i++){
	if(*(base+i)<'0'||*(base+i)>'9'){
		operator = *(base+i);
		// *(operator+ii) = *(base+i);
		d=i+1;
		//ii++;
		}
	}
if (interval == 1)
	interval = atoi(base);
if (d == 0){
	num = -1;
	}
else{
	num = atoi(base+d);
	}
/*if (interval == num)
	num = 0;*/
return 0;
}

//printf("%d",strlen(&names+i));

	/*switch (*(base+i)){
		case '&':{
			strncat(str_1,&names+pos,i);
			strcat(str_2,*(*(&names+pos)+i+1));
			strcat(str_1,"&amp");
			strcat(str_1,str_2);
			strcpy(&names+pos,str_1);
			break;
			}
		case '<':
		case '>':
		// &amp; &lt; &gt;
		}*/


/*for (i=0;i < strlen(&names+pos);i++){
	//printf("%c\n",*(base+i));
	if (*(base+i) == '<' || *(base+i) == '>' || *(base+i) == '='){
		//dot = i;
		strcpy(str_1,"");
		strcpy(str_2,"");
		strncat(str_1,base,i);
		strcat(str_2,base+i+1);
		if (*(base+i) == '<')
			strcat(str_1,"&lt;");
		if (*(base+i) == '>')
			strcat(str_1,"&gt;");
		if (*(base+i) == '=' && *(base+i-1) != '='){
			if (*(base+i+1) == '&')
				strcat(str_1,"&amp;");
			if (*(base+i+1) == '_')
				strcat(str_1," ");
			if (*(&base+i+1) == '=' && *(base+i-1) != '=')
				strcat(str_1,"=");
			strcpy(str_2,str_2+1);
			}
		tem[i] = &str_1;
		}
	}*/


/*
qw<12
er>34
qw<12er>34er>34
ty&&56
ui&_78
qw<12er>34ty&&56ui&_78
&
*/



2016/02/20
/*
for(i=0;i < n_exact;i++){
	fprintf(fp,"[STYLE%d] %s%s%s\n",style_start+i,remark,connector,&names+i);
	fprintf(fp,"NM_IMG=%s,%d\n",til_name,num+i);
	fprintf(fp,"HL_IMG=%s,%d\n\n",til_name,num+i);
	}
*/

2016/02/21
#define T_KEY "\n[KEY%d]\n"
#define T_VR "	VIEW_RECT = %d,%d,%d,%d\n"
#define T_TR "	TOUCH_RECT = %d,%d,%d,%d\n"
#define T_BS "	BACK_STYLE = %d\n"
#define T_FS "	FORE_STYLE = \n"
#define T_POS_TYPE "	POS_TYPE = \n"

#define T_CENTER "	\n	CENTER = \n"
#define T_HOLD "	HOLD = \n"
#define T_HOLDSYM "	HOLDSYM = \n"
#define T_SHOW "	SHOW = \n"

#define T_UP "	\n	UP = \n"
#define T_DOWN "	DOWN = \n"
#define T_LEFT "	LEFT = \n"
#define T_RIGHT "	RIGHT = \n"


2016/02/21
connector[50] = " - ", 

//int xx, xxv;//x，xv的备份
