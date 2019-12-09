#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <stdbool.h>

#define MAIN bgtool
#define PLACEHOLDER "占"
#define LOADING printf("...\n");

int material_maker_collect();
int material_maker_export();
int material_maker_set();
int material_maker_easier(int);
int png_set();
int png_set_body(int);
int png_set_escape();
int til_set();
int css_set();
int til_set_collect();
int css_set_collect();
int skin_maker();
int skin_maker_export();
int skin_maker_set();
int operate_calculator();
int skin_maker_visual();
int ini_set();
int average_calculator();
int skin_editor();
int extract_num(char*);
int fontcss_set();
int filter(int),more_tools();
int help(),error(int);

FILE *fp;
enum boolean {NO,YES}

//整体
int i,ii,j,n=0,nn=0,choose,num;
bool debug_mode;
int result[10];
char part[10],part2[10],text[50];

//素材制作
int size,more=0,n_backup,char_num=5;
int n_exact=0,n_get;
int width=0,widths,height=0;
int y,y_start=0,style_start=0;
bool p_myfont,p_rectangle,p_takecss,p_notecss,p_mycssnote,p_subline;
bool p_exact,p_empty,p_placehold,p_num_placehold,p_preset;
bool p_en,p_ens,p_nums,p_symbles;
char font[]="bgttf",color[9];
char til_name[50]="null",remark[50];
char *names[50];
char operator;

//ini生成
int width,back,line_gap=0,row_gap=0;
int line=0,lines,key=1,keys[10];
int x[10],y=0,xv[10],yv=0,h[10],hv[10];
int w[10][20],wv[10][20],wn,more;
int xx,xxv;//x，xv的备份
int interval=1,arrow;
bool p_up,p_down,p_pos,p_show,p_hold,p_advanced;
bool p_left,p_right,p_holdsym,p_touch,p_start,p_top_margin,p_left_margin;
char operate[]="*99";

int main()
{
//png_set(1);
//material_maker_set();
//skin_maker_set(1);
//测试头
printf("　　　—— BGtool 1.1.1 ——\n");
printf("开始‖1>素材制作\n");
printf("　　‖2>生成til\n");
printf("　　‖3>生成css\n");
printf("　　‖4>皮肤模板制作\n");
//printf("　　‖5>字体前景生成\n");
//printf("　　‖6>皮肤简单操作集\n");
printf("　　‖7>更多工具...\n");
printf("　　‖0>帮助\n");
printf("　　‖选择:");
scanf("%d",&choose);
switch(choose)
{
case 1:{
	material_maker_collect();
	material_maker_export();
	material_maker_set();
	png_set();
	til_set();
	css_set();
	if (debug_mode == false){
		if(y_start == 0){
			system("am start -n com.redphx.simpletext/com.redphx.simpletext.MainActivity");
			}
		else{
			printf("请打开xml文件进行编辑:\n去除原有的</style>，并调整高度为:%d",y_start+height);
			}
		}
	break;
	}
case 2:{
	til_set_collect();
	til_set();
	printf("已生成至:/mnt/sdcard/Baidutool/#til段.til");
	break;
	}
case 3:{
	css_set_collect();
	css_set();
	printf("已生成至:/mnt/sdcard/Baidutool/#css段.txt");
	break;
	}
case 4:{
	skin_maker();
	skin_maker_export();
	ini_set();
	break;
	}
case 5:{
	
	break;
	}
case 6:{
	skin_editor();
	break;
	}
case 7:{
	more_tools();
	break;
	}
case 9:{
	filter (123568);
	for (i = 0;i <=9 ;i++)
		printf("%d",result[i]);
	break;
	}
case 0:{
	help();
	break;
	}
default:
	error(0);
	break;
}
return 0;
}


int material_maker_collect()
{
printf("　　　　　　-素材制作-\n");
printf("组件‖1>非预设字体\n");
//printf("　　‖2>矩形素材\n");
printf("　　‖3>带上css\n");
printf("　　‖4>带上css并注释\n");
//printf("　　‖5>自定义注释格式\n");
//printf("　　‖6>使用辅助线\n");
printf("　　‖0>不用了\n");
printf("　　‖选择：");
scanf("%d",&choose);
filter(choose);
material_maker_easier(1);
printf("字体‖");
if (p_myfont == true){
	printf("文件名 (.ttf):");
	scanf("%s",&font);
	printf("　　‖");
	}
printf("颜色：#");
	scanf("%s",&color);
printf("　　‖大小:");
	scanf("%d",&size);
printf("　　‖溢出调节值:");
	scanf("%d",&more);
printf("画布‖总宽度(0为自动适配):");
	scanf("%d",&width);
printf("　　‖起始高度:");
	scanf("%d",&y_start);
printf("样式‖识别名称:");
	scanf("%s",&til_name);
if (p_takecss == true||p_notecss == true){
	printf("　　‖起始样式:");
	scanf("%d",&style_start);
	}
if (p_notecss == true){
	printf("　　‖备注文本:");
	scanf("%s",&remark);
	}
if (p_mycssnote == true){
	error(1);
	printf("　　‖注释格式:");
	}
LOADING
return 0;
}

int material_maker_export()
{
sprintf(part,"/mnt/sdcard/Simple Text/notes/%s.txt",til_name);
fp=fopen(part,"a");
fprintf(fp,"字体‖");
if (p_myfont == true){
	fprintf(fp,"文件名 (.ttf):%s\n",font);
	fprintf(fp,"　　‖");
	}
fprintf(fp,"颜色：#%s\n",color);
fprintf(fp,"　　‖大小:%d\n",size);
fprintf(fp,"　　‖溢出调节值:%d\n",more);
fprintf(fp,"画布‖总宽度(0为自动适配):%d\n",width);
fprintf(fp,"　　‖起始高度:%d\n",y_start);
fprintf(fp,"样式‖识别名称:%s\n",til_name);
if (p_takecss == true||p_notecss == true){
	fprintf(fp,"　　‖起始样式:%d\n",style_start);
	}
if (p_notecss == true){
	fprintf(fp,"　　‖备注文本:%s",remark);
	}
fclose(fp);
return 0;
}

material_maker_set()
{
printf("生成‖1>输入并精确生成(&为end，&&为&)\n");
printf("方式‖2>快速生成空模板\n");
printf("　　‖3>快速占位\n");
printf("　　‖4>快速数字占位\n");
//printf("　　‖5>预设项\n");
printf("　　‖选择：");
scanf("%d",&choose);
filter(choose);
material_maker_easier(2);
if (p_exact == true){
	for (i=0;strcmp("&",&names+i-1)!=0;i++){
		printf("输入‖第%d个素材:",i+1);
		scanf("%s",&names+i);
		//printf("%d",strlen(&names+i));
		if (char_num < strlen(&names+i)){
			char_num = strlen(&names+i);
			}
		}
	n_exact=n=i-1;
	strcpy(&names+n,"");
	}
if (p_empty == true){
	printf("空白‖切片数量:");
		scanf("%d",&n_get);
	n += n_get;
	}
if (p_placehold == true){
	printf("占位‖切片数量:");
		scanf("%d",&n_get);
	for (i=n;i < n+n_get;i++)
		strcpy(&names+i,PLACEHOLDER);
	n += n_get;
	}
if (p_num_placehold == true){
	printf("数字‖切片数量:");
		scanf("%d",&n_get);
	for (i=n;i < n+n_get;i++){
		sprintf(&names+i,"%d",i+1);
		}
	n += n_get;
	}
if (width == 0){
	width = char_num /3 * size;
	}
nn=0;
height=size*n+2*more*n;
LOADING
return 0;
}


png_set()
{
if (p_preset == true){
	printf("预设‖1>英文小写\n组件‖2>英文大写\n　　‖3>数字1~0\n　　‖4>预设符号\n");
		scanf("%d",&choose);
	filter(choose);
	material_maker_easier(3);
	if (p_en == true){
	n += 1;
	nn += 26;
		strcpy(&names+n-1,"qwertyuiopasdfghjklzxcvbnm");
		printf("%s",&names);
		}
	if (p_ens == true){
		strcpy(&names+n-1,"QWERTYUIOPASDFGHJKLZXCVBNM");
		}
	if (p_nums == true){
		strcpy(&names+n-1,"1234567890");
		}
	if (p_symbles == true){
		strcpy(&names+n-1,"h");
		}
	}
for (i=0;i<26;i++){
//	printf("%c|",);
	}
png_set_body(nn);
LOADING
return 0;
}


int png_set_body(int nn)
{
sprintf(part,"/mnt/sdcard/Simple Text/styles/%s.xml",til_name);
//debug_mode = true;
/*printf("样式‖识别名称:");
	scanf("%s",&til_name);
if(access(part,F_OK) == 0){
	printf("同名文件已存在，输入备份信息(0为不备份):");
		scanf("%s",&text);
	if (strcmp("0",&text)!=0){
		sprintf(part2,"/mnt/sdcard/Simple Text/backup/%s - %s.xml",til_name,text);
		rename(part,part2);
		}
	}*/
if(y_start==0){
fp=fopen(part,"w");
	fprintf(fp,"<?xml version='1.0' encoding='UTF-8' standalone='yes' ?>\n");
	fprintf(fp,"<style width=\"%d\" height=\"%d\">\n",width,height);
	}
else{
	fp=fopen(part,"a");
	}
if (p_preset != true){
	for (i=0;i<n;i++){
		y=size*(i+1)-(size+3)/7+more*i*2+more+y_start;
		if (debug_mode==true)
		printf("   <text align=\"center\" x=\"0.0\" y=\"%d.0\" rotate=\"0\" size=\"%d\" font=\"%s.ttf\" text=\"%s\" color=\"#%s\" autoScaleX=\"0\" scaleX=\"1.0\" flags=\"65\" />\n",y,size,font,&names+i,color);
		else
		fprintf(fp,"   <text align=\"center\" x=\"0.0\" y=\"%d.0\" rotate=\"0\" size=\"%d\" font=\"%s.ttf\" text=\"%s\" color=\"#%s\" autoScaleX=\"0\" scaleX=\"1.0\" flags=\"65\" />\n",y,size,font,&names+i,color);
//		png_set_escape();
		}
	}
else {
	for (i=0;i<n;i++){
		for (ii=0;ii<=nn;ii++){
			y=size*(ii+1)-(size+3)/7+more*i*2+more+y_start;
			if (debug_mode==true)
			printf("   <text align=\"center\" x=\"0.0\" y=\"%d.0\" rotate=\"0\" size=\"%d\" font=\"%s.ttf\" text=\"%c\" color=\"#%s\" autoScaleX=\"0\" scaleX=\"1.0\" flags=\"65\" />\n",y,size,font,(&names+i)[ii],color);
			else
			fprintf(fp,"   <text align=\"center\" x=\"0.0\" y=\"%d.0\" rotate=\"0\" size=\"%d\" font=\"%s.ttf\" text=\"%c\" color=\"#%s\" autoScaleX=\"0\" scaleX=\"1.0\" flags=\"65\" />\n",y,size,font,(&names+i)[ii],color);
			}
		}
	}
fprintf(fp, "</style>");
fclose(fp);
return 0;
}

int png_set_escape()
{
for (i=0;i<n;i++){
	for (ii=0;ii<=nn;ii++){
/*		switch ((&names+i)[ii]){
			case '&':
			case '<':
			case '>':
			// &amp; &lt; &gt;
			}*/
		}
	}
return 0;
}

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

int til_set()
{
int x = 0;
if (strcmp("null",&til_name)!=0){
	sprintf(part,"/mnt/sdcard/Simple Text/%s.til",til_name);
	}
else{
	sprintf(part,"/mnt/sdcard/Baidutool/#til段.til",til_name);
	}
if(y_start == 0){
	fp=fopen(part,"w");
	fprintf(fp,"[GLOBAL]\n");
	fprintf(fp,"USE_ALPHA=1\n");
	fprintf(fp,"TILE_NUM=%d\n",n);
	}
else if(strcmp("null",&til_name)==0){
	fp=fopen(part,"w");
	}
else{
	fp=fopen(part,"a");
	}
for (i=0;i<n;i++){
	y=(size+2*more)*i+y_start;
	fprintf(fp,"\n[IMG%d]\n",y_start/(size+more*2)+i+1);
	fprintf(fp,"SOURCE_RECT=%d,%d,%d,%d\n",x,y,width,size+2*more);
	}
fclose(fp);
return 0;
}

int css_set()
{
if (num == 0){
	num = y_start/(size+more*2)+1;
	}
fp=fopen("/mnt/sdcard/Baidutool/#css段.txt","w");
if (p_takecss == true && p_notecss == false){
	for(i=0;i<n;i++){
		fprintf(fp,"[STYLE%d]\n",style_start+i);
		fprintf(fp,"NM_IMG=%s,%d\n",til_name,num+i);
		fprintf(fp,"HL_IMG=%s,%d\n\n",til_name,num+i);
		}
	}
if (p_notecss == true){
	for(i=0;i<n_exact;i++){
		fprintf(fp,"[STYLE%d] %s - %s\n",style_start+i,remark,&names+i);
		fprintf(fp,"NM_IMG=%s,%d\n",til_name,num+i);
		fprintf(fp,"HL_IMG=%s,%d\n\n",til_name,num+i);
		}
	for(i=n_exact;i<n;i++){
		fprintf(fp,"[STYLE%d] %s - \n",style_start+i,remark);
		fprintf(fp,"NM_IMG=%s,%d\n",til_name,num+i);
		fprintf(fp,"HL_IMG=%s,%d\n\n",til_name,num+i);
		}
	}
fclose(fp);
return 0;
}

int til_set_collect()
{
printf("　　　　　　-til生成-\n");
//printf("组件‖1>溢出调节值");
//printf("　　‖2>矩形");
//printf("　　‖");
//printf("　　‖");
//printf("整体‖切片名:");
//scanf("%s",&til_name);
printf("整体‖数量:");
scanf("%d",&n);
printf("　　‖起始高度:");
scanf("%d",&y_start);
printf("单元‖大小:");
scanf("%d",&size);
//printf("　　‖溢出调节值:");
//scanf("%d",&more);
//printf("");
LOADING
return 0;
}

int css_set_collect()
{
p_takecss = true;
printf("　　　　　　-css生成-\n");
printf("整体‖起始序号:");
scanf("%d",&style_start);
printf("　　‖数量:");
scanf("%d",&n);
printf("　　‖素材名:");
scanf("%s",&til_name);
printf("　　‖起始切片号:");
scanf("%d",&num);
printf("附加‖注释前缀(0为无注释):");
scanf("%s",&remark);
if(strcmp("0",remark) != 0)
	p_notecss = true;
//printf("自定义注释格式");
//scanf("%",&);
//printf("");
//scanf("%",&);
LOADING
return 0;
}

int skin_maker()
{
printf("　　　　　　-皮肤模板-\n");
printf("组件‖1>UP=\n");
printf("多选‖2>DOWN=\n");
printf("　　‖3>POS_TYPE=\n");
printf("　　‖4>SHOW=\n");
printf("　　‖5>HOLD=\n");
printf("　　‖6>高级模式\n");
printf("　　‖0>不用了\n");
printf("　　‖选择:");
scanf("%d",&choose);
filter(choose);
skin_maker_easier(1);
if (p_advanced == true){
	printf("\n");
	printf("高级‖1>LEFT=\n");
	printf("　　‖2>RIGHT=\n");
	printf("　　‖3>HOLDSYM=\n");
	//printf("　　‖4>TOUCH_RECT=(慎用!)\n");
	printf("　　‖5>起始序号\n");
	printf("　　‖6>上边距\n");
	printf("　　‖7>左边距\n");
	printf("　　‖0>还是不用了\n");
	printf("　　‖选择:");
	scanf("%d",&choose);
	filter(choose);
	skin_maker_easier(2);
	}
printf("面板‖总宽:");
scanf("%d",&width);
printf("　　‖总行数:");
scanf("%d",&lines);
printf("按键‖默认背景样式:");
scanf("%d",&back);
if (p_start == true){
	printf("　　‖起始序号:");
	scanf("%d",&key);
	}
if (p_top_margin == true){
	printf("　　‖上边距:");
	scanf("%d",&y);
	if (p_touch == true){
		printf("　　‖【显示】上边距:");
		scanf("%d",&yv);
		}
	}
if (p_touch == true){
	printf("　　‖【显示】横向间隔:");
		scanf("%d",&line_gap);
	printf("　　‖【显示】纵向间隔:");
		scanf("%d",&row_gap);
	}
for (line = 0;line < lines;line++){
	skin_maker_set();
	}
LOADING
return 0;
}

int skin_maker_set()
{
printf("\n第%d行>>\n",line+1);
widths=width;
for (;interval != 0;){
	printf("　　‖现有%d空间盈余，请划分区间\n",width);
	printf("　　‖(1-20为分数，0为结束)\n");
	//负数为指定区块序号
	//scanf("%d",&interval);
	printf("　　‖操作表达式:");
	scanf("%s",&operate);
	if(strcmp("0",operate) == 0){
		break;
		}
	else {
		extract_num(operate);
/*	if (interval != 0){*/
		if (interval <= 20){
			interval = width / interval;
			printf("　　‖计算得区间长度为:%d\n",interval);
			}
		if (num == atoi(operate)){
			printf("　　‖补充表达式:");
			scanf("%s",&operate);
			extract_num(operate);
			}
		}
	operate_calculator();
	interval = 1;
	if (width == 0){
		printf("　　‖已排满\n");
		break;
		}
	//skin_maker_visual();
	}
printf("按键‖高度(0取前行值):");
scanf("%d",&h[line]);
if (h[line] == 0){
	h[line] = h[line-1];
	}
if (p_left_margin == true){
	printf("　　‖左边距:");
	scanf("%d",&x[line]);
	if (p_touch == true){
		printf("　　‖【显示】左边距:");
		scanf("%d",&xv[line]);
		}
	}
interval=1;
width=widths;
arrow = 0;
return 0;
}

int operate_calculator()
{
switch (operator){
	//case "+" :
	//case "-" :
	case '*' :{
		for (i=0;i < num;i++){
			w[line][arrow] = interval;
			arrow += 1;
			width -= interval;
			keys[line]++;
			}
		break;
		}
	case '/' :{
		interval /= num;
		printf("　　‖计算得单元长度为:%d\n",interval);
		for (i=0;i < num;i++){
			w[line][arrow] = interval;
			arrow += 1;
			width -= interval;
			keys[line]++;
			}
		break;
		}
	default:{
		printf("　　‖未知操作符，请重新输入");
		break;
		}
	}
return 0;
}

int skin_maker_visual()
{
int grick = width/40;
int line_backup;
line_backup = line;
for (line = 0;line < lines;line++){
	for (i=0;i < keys[line];i++){
		if (w[line][i] != 0){
			if (w[line][i+1] != w[line][i]){
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
				}
			}
		else {
//			for (ii=0;ii < w[line][i]/grick;ii++)
				printf("[︿]");
			}
		}
	printf("\n");
	}
line = line_backup;
return 0;
}

int skin_maker_export()
{
return 0;
}

int ini_set()
{
fp=fopen("/mnt/sdcard/Baidutool/#皮肤模板.ini","w");
for(line = 0;line < lines;line++){
	for(i = 0;i < keys[line];i++){
		if (key == 1){
			fprintf(fp,"[INPUT]\n\n[CAND]\n\n[PANEL]\n\n[MORE]\n\n[HINT]\n\n[LIST]\n");
			}
		fprintf(fp,"\n[KEY%d]\n",key);
		if (p_touch == true){
			fprintf(fp,"VIEW_RECT=%d,%d,%d,%d\n",xv[line],yv,wv[line][i],hv[line]);
			fprintf(fp,"TOUCH_RECT=%d,%d,%d,%d\n",x[line],y,w[line][i],h[line]);
		}
		else {
			fprintf(fp,"VIEW_RECT=%d,%d,%d,%d\n",x[line],y,w[line][i],h[line]);
		}
		fprintf(fp,"BACK_STYLE=%d\n",back);
		fprintf(fp,"FORE_STYLE=\n");
		if (p_up == true){
			fprintf(fp,"UP=\n");
		}
		if (p_down == true){
			fprintf(fp,"DOWN=\n");
		}
		if (p_left == true){
			fprintf(fp,"LEFT=\n");
		}
		if (p_right == true){
			fprintf(fp,"RIGHT=\n");
		}
		fprintf(fp,"CENTER=\n");
		if (p_show == true){
			fprintf(fp,"SHOW=\n");
		}
		if (p_hold == true){
			fprintf(fp,"HOLD=\n");
		}
		if (p_holdsym == true){
			fprintf(fp,"HOLDSYM=\n");
		}
		if (p_touch == true){
			xv[line]=xv[line]+wv[line][i]+line_gap;
		}
		x[line]=x[line]+w[line][i];
		key++;
	}
	y=y+h[line];
	yv=yv+hv[line]+row_gap;
}
fclose(fp);
printf("已生成至sdcard/Baidutool/#皮肤模板.ini");
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
	p_advanced = result[6];
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
	break;
	}
default:
	error(2);
	break;
}
return 0;
}

int skin_editor()
{
printf("皮肤‖1>隐藏[CAND]工具栏\n");
printf("操作‖2>皮肤透明化\n");
printf("　　‖3>转换全键盘小写字母为大写\n");
printf("　　‖4>强行总是使用拇指数字面板\n");
printf("　　‖5>强行总是使用全键盘数字面板\n");
printf("　　‖6>隐藏输入法内置表情选项\n");
printf("　　‖7>输入法设置备份与还原\n");
printf("　　‖8>皮肤模板构架修改\n");
printf("　　‖选择:");
return 0;
}

int extract_num(char *base)
{
int d;
d=0;
for (i=0;i<strlen(base);i++){
	if(*(base+i)<'0'||*(base+i)>'9'){
		operator = *(base+i);
		// *(operator+ii) = *(base+i);
		d=i+1;
		//ii++;
		}
	}
if (interval == 1)
	interval = atoi(base);
num = atoi(base+d);
return 0;
}

int filter(int base)
{
for (i = 0;i <=9 ;i++){
	result[i] = 0;
	}
if (base != -1){
	result[base%10] = 1;
	for (i=0;base/=10;i++){
		result[base%10] = 1;
		}
	}
else {
	printf("跳转节点");
	}
return 0;
}

int more_tools()
{
printf("\n　　　　　　-更多工具-\n");
printf("更多‖1>debug模式\n");
//printf("　　‖2>快速恢复模式\n");
//printf("　　‖3>4.1+表情图制作\n");
//printf("　　‖4>模拟皮肤模板计算器\n");
//printf("　　‖5>文字图片化\n");
printf("　　‖选择:");
scanf("%d",&choose);
filter(choose);
material_maker_easier(1);
switch(choose)
{
case 1:{
	debug_mode=true;
	clrscr();
	printf("正在使用debug模式...\n");
	main();
	break;
	}
}
return 0;
}

int help()
{
clrscr();
printf("　　　　　　　-帮助-\n");
printf("特性‖组件形式:多种搭配\n");
printf("　　‖视图优化:层级明显\n");
printf("　　‖强大功能:灵活多变\n");
printf("综述‖组件多选直接输数字无需分隔符\n");
printf("　　‖ST中<>&未来将自动转义\n");
printf("　　‖建议调节字体到使本页正常显示的大小\n");
printf("皮肤‖操作表达式说明\n");
printf("　　‖格式为\"[区间]+[操作符]+[数字]\"，例如\"60*75\"\n");
printf("　　‖[*] - 复制此区间  [/] - 分割此区间\n");
printf("关于‖Android可视版在非常长期的计划中:)\n");
printf("　　‖更新日志请查看发布文章\n");
printf("　　‖百度贴吧@齿轮key 部分参考BStool\n");
printf("　　‖博客:http:\/\/blog.csdn.net/Gearkey\n");
printf("　　‖Email:Gearkey@outlook.com\n");
//i=getchar();
//putchar(i)
return 0;
}

int error(int e_num)
{
switch (e_num){
	case 0:printf("...\n⚠　‖没有这个的说>_<\n");
		break;
	case 1:printf("\n⚠　‖还没做好，如此\n");
		break;
	case 2:printf("\n⚠　‖操作数据溢出\n");
		break;
	}
}