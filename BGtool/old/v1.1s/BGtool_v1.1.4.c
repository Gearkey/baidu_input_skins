#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <stdbool.h>
#include <time.h>

bool debug_mode = 
//true;
false;

#define MAIN bgtool
#define PLACEHOLDER "占"
#define NEXT printf("\n");
#define LOADING printf("...\n");

#define S_MATERIAL_COLLECT switch_control(1);
#define S_MATERIAL_MODE switch_control(2);
#define S_MATERIAL_PERSET switch_control(3);
#define S_SKIN_COLLECT1 switch_control(4);
#define S_SKIN_COLLECT2 switch_control(5);

#define E_ADD_OPERATE printf("　　‖补充表达式:");
#define E_NONE printf("...\n⚠　‖没有这个的说>_<\n");
#define E_OUT_WIDTH printf("⚠　‖宽度溢出，请重新输入表达式\n");

#define GET_TIME time_t t = time(0); strftime(tmp, sizeof(tmp),"%Y/%m/%d %X %A",localtime(&t));

//1# 素材制作
int material_maker_collect();
int material_maker_export();
int material_maker_mode();
int material_maker_mode_preset();
int png_set_body();
int png_set_escape();
//2# 素材衍生
int til_set_body();
int css_set_body();
int til_set_collect();
int css_set_collect();
//3# 皮肤制作
int skin_maker();
int skin_maker_export();
int skin_maker_set();
int skin_maker_visual();
int operate_calculator();
int average_calculator();
int ini_set();
//4# 其他
int more_tools();
int pngtext();
int skin_editor();
int fontcss_set();
int extract_nums(char*);
int smart_strlen(char*);
//5# 系统控制
int switch_control(int);
int filter(int);
int help(),ready();

FILE *fp;

//整体
int i,ii,j,jj;
int n=0,choose,num;
int result[10];
char part[10],part2[10];
char tmp[64];

//素材制作
int size,more=0,char_num=5;
int n_exact=0,n_get;
int width=0,height=0;
int y,y_start=0,style_start=0;
char font[]="bgttf",color[9];
char til_name[50]="null",remark[50];
char *names[20];
bool p_myfont,p_rectangle,p_takecss,p_notecss,p_mycssnote,p_subline;
bool p_exact,p_empty,p_placehold,p_num_placehold,p_preset;
bool p_en,p_ens,p_nums,p_symbles;

//ini生成
int back,line_gap[8][30],row_gap[8];
int line,lines,key=1,keys[10];
int x[10],xv[10],yv=0,h[10],hv[10];
int w[8][30],wv[8][30];
int xx,xxv;//x，xv的备份
int interval=1,arrow;
int nums[2];
char operator = '0';
char operate[]="*99";
bool p_up,p_down,p_pos,p_show,p_hold,p_visual,p_advanced;
bool p_left,p_right,p_holdsym,p_touch,p_start,p_top_margin,p_left_margin,p_only_pos;

int main()
{
//material_maker_mode_preset();
//material_maker_mode();
//skin_maker_set(1);
//测试头
if (access("/mnt/sdcard/Baidutool",0) == -1)
	ready();
printf("　　　—— BGtool 1.1.4 ——\n");
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
	material_maker_mode();
	material_maker_export();
	png_set_body();
	til_set_body();
	css_set_body();
	if (debug_mode == false){
		if(y_start == 0){
			NEXT
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
	til_set_body();
	printf("已生成至:/mnt/sdcard/Baidutool/#til段.til");
	break;
	}
case 3:{
	css_set_collect();
	css_set_body();
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
	fontcss_set();
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
	printf("　　‖输入任意内容返回:\n　　‖");
	scanf("%s",operate);
	clrscr();
	main();
	break;
	}
default:
	E_NONE
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
//printf("　　‖7>字体样式变更\n");
printf("　　‖0>不用了\n");
printf("　　‖选择：");
scanf("%d",&choose);
filter(choose);
S_MATERIAL_COLLECT
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
if (sprintf(part,"/mnt/sdcard/Simple Text/styles/%s.xml",til_name) == -1)
	printf("⚠　‖当前不存在此文件\n");
else
	printf("⚠　‖当前已存在同名文件\n");
if (p_takecss == true||p_notecss == true){
	printf("　　‖起始样式:");
	scanf("%d",&style_start);
	}
if (p_notecss == true){
	printf("　　‖备注文本:");
	scanf("%s",&remark);
	}
if (p_mycssnote == true){
	printf("　　‖注释格式:");
	}
NEXT
return 0;
}

int material_maker_export()
{
//sprintf(part,"/mnt/sdcard/Simple Text/notes/%s.txt",til_name);
sprintf(part,"/mnt/sdcard/Simple Text/styles/%s.xml",til_name);
if (y_start == 0){
	fp=fopen(part,"w");
	fprintf(fp,"<?xml version='1.0' encoding='UTF-8' standalone='yes' ?>\n");
	}
else{
	fp=fopen(part,"a");
	fprintf(fp,"\n<!-- 去除前面的结束符并更改高度为%d -->\n",y_start+height);
	}
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
fprintf(fp,"<!-- BGtool\n");
GET_TIME
fprintf(fp,"%s\n",tmp);
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
	fprintf(fp,"　　‖备注文本:%s\n",remark);
	}
for (i = 0;i < n;i++)
	fprintf(fp,"%s\n",&names+i);
fprintf(fp,"-->\n");
fclose(fp);
return 0;
}

int material_maker_mode()
{
printf("生成‖1>输入并精确生成(&为end)\n");
printf("方式‖2>快速生成空模板\n");
printf("　　‖3>快速占位\n");
printf("　　‖4>快速数字占位\n");
printf("　　‖5>预设项(beta)\n");
printf("　　‖选择：");
scanf("%d",&choose);
filter(choose);
S_MATERIAL_MODE
if (p_exact == true){
	for (i=0;strcmp("&",&names+i-1)!=0;i++){
		printf("输入‖第%d个素材:",i+1);
		scanf("%s",&names+i);
		if (char_num < smart_strlen(&names+i)){
			char_num = smart_strlen(&names+i);
			}
		}
	n_exact = n = i-1;
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
	for (i=n;i < n+n_get;i++)
		sprintf(&names+i,"%d",i+1);
	n += n_get;
	}
if (p_preset == true){
	NEXT
	material_maker_mode_preset();
	}
if (width == 0){
	width = char_num /3 * size;
	}
height = size*n + 2*more*n;
LOADING
NEXT
return 0;
}


int material_maker_mode_preset()
{
char en[] = "qwertyuiopasdfghjklzxcvbnm";
char ens[] = "QWERTYUIOPASDFGHJKLZXCVBNM";
char symbles[] = "@#+-=():/_!?";
printf("预设‖1>英文小写\n");
printf("组件‖2>英文大写\n");
printf("　　‖3>数字1~0\n");
printf("　　‖4>基本符号\n");
//printf("　　‖5>扩展符号\n");
//printf("　　‖6>常用功能键\n");
printf("　　‖选择:");
scanf("%d",&choose);
filter(choose);
S_MATERIAL_PERSET
if (p_en == true){
	for (i=0;i < 26;i++){
		sprintf(&names+n+i,"%c",*(en+i));
		}
	n += 26;
	}
if (p_ens == true){
	for (i=0;i < 26;i++){
		sprintf(&names+n+i,"%c",*(ens+i));
		}
	n += 26;
	}
if (p_nums == true){
	for (i=0;i < 9;i++){
		sprintf(&names+n+i,"%c",'1'+i);
		}
	strcpy(&names+n+9,"0");
	n += 10;
	}
if (p_symbles == true){
	for (i=0;i < strlen(symbles);i++){
		sprintf(&names+n+i,"%c",*(symbles+i));
		}
	n += strlen(symbles);
	}
LOADING
/*for (i=0;i < n;i++){
	printf("%s",&names+i);
	png_set_escape();
	}*/
return 0;
}


int png_set_body()
{
sprintf(part,"/mnt/sdcard/Simple Text/styles/%s.xml",til_name);
if(y_start == 0){
fp=fopen(part,"a");
	fprintf(fp,"<style width=\"%d\" height=\"%d\">\n",width,height);
	}
else{
	fp=fopen(part,"a");
	}
for (i=0;i < n;i++){
	y = size*(i+1) - (size+3)/7 + more*i*2 + more + y_start;
	if (debug_mode == true)
		printf("	<text align=\"center\" x=\"0.0\" y=\"%d.0\" rotate=\"0\" size=\"%d\" font=\"%s.ttf\" text=\"%s\" color=\"#%s\" autoScaleX=\"0\" scaleX=\"1.0\" flags=\"65\" />\n",y,size,font,&names+i,color);
	else
		fprintf(fp,"	<text align=\"center\" x=\"0.0\" y=\"%d.0\" rotate=\"0\" size=\"%d\" font=\"%s.ttf\" text=\"%s\" color=\"#%s\" autoScaleX=\"0\" scaleX=\"1.0\" flags=\"65\" />\n",y,size,font,&names+i,color);
	png_set_escape();
	}
fprintf(fp, "</style>");
fclose(fp);
return 0;
}

int png_set_escape()
{
/*for (ii=0;ii <= strlen(&names+i);ii++){
	switch (*(&names+i)+ii){
		case '&':
			(*(&names+i)+ii) = &amp;
		case '<':
		case '>':
		// &amp; &lt; &gt;
		}
	}*/
return 0;
}

int til_set_body()
{
int x = 0;
if (strcmp("null",&til_name) != 0){
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
for (i=0;i < n;i++){
	y=(size+2*more)*i + y_start;
	fprintf(fp,"\n[IMG%d]\n",y_start/(size+more*2)+i+1);
	fprintf(fp,"SOURCE_RECT=%d,%d,%d,%d\n",x,y,width,size+2*more);
	}
fclose(fp);
return 0;
}

int css_set_body()
{
if (num == 0){
	num = y_start/(size+more*2) + 1;
	}
fp=fopen("/mnt/sdcard/Baidutool/#css段.txt","w");
if (p_takecss == true && p_notecss == false){
	for(i=0;i < n;i++){
		fprintf(fp,"[STYLE%d]\n",style_start+i);
		fprintf(fp,"NM_IMG=%s,%d\n",til_name,num+i);
		fprintf(fp,"HL_IMG=%s,%d\n\n",til_name,num+i);
		}
	}
if (p_notecss == true){
	for(i=0;i < n_exact;i++){
		fprintf(fp,"[STYLE%d] %s - %s\n",style_start+i,remark,&names+i);
		fprintf(fp,"NM_IMG=%s,%d\n",til_name,num+i);
		fprintf(fp,"HL_IMG=%s,%d\n\n",til_name,num+i);
		}
	for(i=n_exact;i < n;i++){
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
printf("　　‖6>可视化操作(beta)\n");
printf("　　‖7>高级模式\n");
printf("　　‖0>不用了\n");
printf("　　‖选择:");
scanf("%d",&choose);
filter(choose);
S_SKIN_COLLECT1
if (p_advanced == true){
	printf("\n");
	printf("高级‖1>LEFT=\n");
	printf("　　‖2>RIGHT=\n");
	printf("　　‖3>HOLDSYM=\n");
	//printf("　　‖4>TOUCH_RECT=(慎用!)\n");
	printf("　　‖5>起始序号\n");
	//printf("　　‖6>上边距\n");
	//printf("　　‖7>左边距\n");
	printf("　　‖8>仅坐标\n");
	printf("　　‖0>还是不用了\n");
	printf("　　‖选择:");
	scanf("%d",&choose);
	filter(choose);
	S_SKIN_COLLECT2
	}
printf("面板‖总宽:");
scanf("%d",&width);
printf("　　‖总行数:");
scanf("%d",&lines);
if (p_only_pos == false){
	printf("按键‖默认背景样式:");
	scanf("%d",&back);
	}
if (p_start == true){
	printf("　　‖起始序号:");
	scanf("%d",&key);
	}
for (line = 0;line < lines;line++){
	skin_maker_set();
	}
LOADING
return 0;
}

int skin_maker_set()
{
int width_backup;
printf("\n第%d行>>\n",line+1);
width_backup = width;
for (;;){
	printf("　　‖现有%d空间盈余，请划分区间\n",width);
	printf("　　‖(1-20为分数，0为结束)\n");
	//负数为指定区块序号
	//scanf("%d",&interval);
	printf("　　‖操作表达式:");
	scanf("%s",&operate);
	if(strcmp("0",operate) == 0)
		break;
	else
		extract_nums(operate);
	//printf("%d %d ",interval,num);
	operate_calculator();
	interval = 0;
	if (p_visual == true)
		skin_maker_visual();
	if (width == 0){
		printf("　　‖已排满\n");
		break;
		}
	}
printf("按键‖高度(0取前行值):");
scanf("%d",&h[line]);
if (h[line] == 0){
	h[line] = h[line-1];
	}
width = width_backup;
arrow = 0;
return 0;
}

int operate_calculator()
{
int interval_backup;
if (operator == '0'){
	E_ADD_OPERATE
	scanf("%s",&operate);
	interval_backup = interval;
	extract_nums(operate);
	interval = interval_backup;
	}
switch (operator){
	case '&' :{
		if (num == 0){
			E_ADD_OPERATE
			scanf("%d",&num);
			}
		row_gap[line] = num;
		break;
		}
	case '+' :{
		if (num == 0){
			E_ADD_OPERATE
			scanf("%d",&num);
			}
		if (width - num < 0){
			E_OUT_WIDTH
			break;
			}
		width -= num;
		line_gap[line][arrow] = num;
		break;
		}
	//case "-" :
	case '*' :{
		if (num == 0){
			E_ADD_OPERATE
			scanf("%d",&num);
			}
		if (width - (interval * num) < 0){
			E_OUT_WIDTH
			break;
			}
		width -= (interval * num);
		for (i=0;i < num;i++){
			w[line][arrow] = interval;
			arrow += 1;
			keys[line]++;
			}
		break;
		}
	case '/' :{
		if (num == 0){
			E_ADD_OPERATE
			scanf("%d",&num);
			}
		interval /= num;
		printf("　　‖计算得单元长度为:%d\n",interval);
		if (width - (interval * num) < 0){
			E_OUT_WIDTH
			break;
			}
		width -= (interval * num);
		for (i=0;i < num;i++){
			w[line][arrow] = interval;
			arrow += 1;
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
int key_tmp;
for (j = 0;j < lines;j++){
	printf("[");
	for (i = 0;i < keys[j];i++){
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

int skin_maker_export()
{

return 0;
}

int ini_set()
{
fp=fopen("/mnt/sdcard/Baidutool/#皮肤模板.ini","w");
if (key == 1){
	fprintf(fp,"[INPUT]\n\n");
	fprintf(fp,"[CAND]\n\n");
	fprintf(fp,"[PANEL]\n\n");
	fprintf(fp,"[MORE]\n\n");
	fprintf(fp,"[HINT]\n\n");
	fprintf(fp,"[LIST]\n");
	}
for(line = 0;line < lines;line++){
	y += row_gap[line];
	yv += row_gap[line];
	for(i = 0;i < keys[line];i++){
		x[line] += line_gap[line][i];
		fprintf(fp,"\n[KEY%d]\n",key);
		if (p_touch == true){
			fprintf(fp,"VIEW_RECT=%d,%d,%d,%d\n",xv[line],yv,wv[line][i],hv[line]);
			fprintf(fp,"TOUCH_RECT=%d,%d,%d,%d\n",x[line],y,w[line][i],h[line]);
			}
		else {
			fprintf(fp,"VIEW_RECT=%d,%d,%d,%d\n",x[line],y,w[line][i],h[line]);
			}
		if (p_only_pos == false){
			fprintf(fp,"BACK_STYLE=%d\n",back);
			fprintf(fp,"FORE_STYLE=\n");
			}
		if (p_pos == true){
			fprintf(fp,"POS_TYPE=\n");
			}
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
		if (p_only_pos == false){
			fprintf(fp,"CENTER=\n");
			}
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
			xv[line] = xv[line] + wv[line][i];
			}
		if (p_only_pos == true){
			fprintf(fp,"\n");
			}
		x[line] = x[line] + w[line][i];
		key++;
		}
	y += h[line];
	yv += hv[line];
	}
fclose(fp);
printf("已生成至sdcard/Baidutool/#皮肤模板.ini\n");
return 0;
}

int fontcss_set()
{

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

int extract_nums(char *base)
{
int i;
int d = 0;
if (*base < '0'||*base > '9'){
	operator = *base;
	d = 1;
	interval = 1;
	}
else {
	interval = atoi(base);
	for (i=0;i < strlen(base);i++){
		if(*(base+i) < '0'||*(base+i) > '9'){
			operator = *(base+i);
			d = i+1;
			}
		}
	}
if (d == 0){
	operator = '0';
	if (interval == 1)
		interval = width;
	}
num = atoi(base+d);
if (interval <= 20 && interval != 0){
	interval = width / interval;
	printf("　　‖计算得区间长度为:%d\n",interval);
	}
return 0;
/*
return num
*/
}

int smart_strlen(char *base)
{
int i,n = 0;
int out_num;
out_num = strlen(base);
for (i=0;i < strlen(base);i++){
	if (*(base+i) >= 33 && *(base+i) <= 126)
		n ++;
	}
out_num += n * 4 / 5;
if (out_num < 3)
	out_num = 3;
return out_num;
}

int switch_control(int choose)
{
if (choose == 1){
	p_myfont = result[1];
	p_rectangle = result[2];
	p_takecss = result[3];
	p_notecss = result[4];
	p_mycssnote = result[5];
	p_subline = result[6];
	}
if (choose == 2){
	p_exact = result[1];
	p_empty = result[2];
	p_placehold = result[3];
	p_num_placehold = result[4];
	p_preset = result[5];
	}
if (choose == 3){
	p_en = result[1];
	p_ens = result[2];
	p_nums = result[3];
	p_symbles = result[4];
	}
if (choose == 4){
	p_up = result[1];
	p_down = result[2];
	p_pos = result[3];
	p_show = result[4];
	p_hold = result[5];
	p_visual = result[6];
	p_advanced = result[7];
	}
if (choose == 5){
	p_left = result[1];
	p_right = result[2];
	p_holdsym = result[3];
	p_touch = result[4];
	p_start = result[5];
	p_top_margin = result[6];
	p_left_margin = result[7];
	p_only_pos = result[8];
	}
return 0;
}

int filter(int base)
{
for (i = 0;i <=9 ;i++){
	result[i] = 0;
	}
if (base != -1){
	result[base%10] = 1;
	for (i=0;base /= 10;i++){
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
printf("　　‖5>文字图片化(Beta)\n");
printf("　　‖选择:");
scanf("%d",&choose);
filter(choose);
S_MATERIAL_COLLECT
switch(choose)
{
case 1:{
	debug_mode=true;
	clrscr();
	printf("正在使用debug模式...\n");
	main();
	break;
	}
case 2:{
	debug_mode=true;
	clrscr();
	printf("正在使用快速恢复模式...\n");
	main();
	break;
	}
case 3:{
	break;
	}
case 4:{
	break;
	}
case 5:{
	pngtext();
	png_set_body();
	system("am start -n com.redphx.simpletext/com.redphx.simpletext.MainActivity");
	break;
	}
}
return 0;
}

int pngtext()
{
printf("　　　　　　-文字图片化-\n");
printf("　　‖输入文字:");
scanf("%s",&names);
LOADING
strcpy(color,"111111");
height = 40;
size = 28;
strcpy(til_name,"pngtext");
n = 1;
width = smart_strlen(&names) /3 * size;
sprintf(part,"/mnt/sdcard/Simple Text/styles/%s.xml",til_name);
fp=fopen(part,"w");
fclose(fp);
return 0;
}

int ready()
{
system("mkdir /sdcard/Baidutool");
/*if (access("/mnt/sdcard/baidu/ime/.emoji",0) == -1)
	system("mkdir /mnt/sdcard/baidu/ime/.emoji");
if (access("/mnt/sdcard/Simple Text",0) == -1)
	system("mkdir '/mnt/sdcard/Simple Text'");
if (access("/mnt/Simple Text/styles",0) == -1)
	system("mkdir '/mnt/sdcard/Simple Text/styles'");
if (access("/mnt/sdcard/Simple Text/fonts",0) == -1)
	system("mkdir '/mnt/sdcard/Simple Text/fonts'");*/
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
printf("　　‖设置里可调节字体\n");
printf("皮肤‖操作表达式说明\n");
printf("　　‖格式为\"[区间]+[操作符]+[数字]\"，例如\"60*75\"\n");
printf("　　‖[*] - 复制此区间  [/] - 分割此区间\n");
printf("关于‖Android可视版在非常长期的计划中:)\n");
printf("　　‖更新日志请查看发布文章\n");
printf("　　‖百度贴吧@齿轮key 部分参考BStool\n");
printf("　　‖博客:http:\/\/blog.csdn.net/Gearkey\n");
printf("　　‖Email:Gearkey@outlook.com\n");
return 0;
}
