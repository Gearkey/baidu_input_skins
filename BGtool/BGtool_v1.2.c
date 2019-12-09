/* BGtool.c 

锚
---
//测试头 #
//皮肤模板//


*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <stdbool.h>
#include <time.h>

bool debug_mode = //true;
false;

#define MAIN bgtool
#define PLACEHOLDER "占"
#define NEXT printf("\n");
#define LOADING printf("...\n");

//(PART)
#define P_MATERIAL "/mnt/sdcard/Simple Text/styles/%s.xml"
#define P_MATERIAL_TTF "/mnt/sdcard/Simple Text/fonts/%s.ttf"
#define P_MATERIAL_TIL "/mnt/sdcard/Simple Text/%s.til"
#define P_TIL "/mnt/sdcard/Baidutool/#til段.til"
#define P_CSS "/mnt/sdcard/Baidutool/#css段.txt"
#define P_SKIN "/mnt/sdcard/Baidutool/#皮肤模板.ini"
#define P_SKIN_EXPORT "/mnt/sdcard/Baidutool/#皮肤模板_log.txt"

/*
#define  
#define  
#define  
#define  
#define  
#define  
*/

//(TXT)
#define T_STYLE "[STYLE %d]\n"
#define T_STYLE_NOTE "[STYLE %d]%s - "
#define T_NM_IMG "	NM_IMG = %s,%d\n"
#define T_HL_IMG "	HL_IMG = %s,%d\n\n"

#define T_PRESET_SYM "@#%!?_,.+-*=/\'\"\\:^~|;{}[]()<>"

//(SWITCH)
#define S_MATERIAL_COLLECT switch_control(1);
#define S_MATERIAL_MODE switch_control(2);
#define S_MATERIAL_PERSET switch_control(3);
#define S_SKIN_COLLECT1 switch_control(4);
#define S_SKIN_COLLECT2 switch_control(5);

//错误信息
#define E_ADD_OPERATE printf("　　‖补充表达式:");
#define E_NONE printf("...\n⚠　‖没有这个的说>_<\n");
#define E_OUT_WIDTH printf("⚠　‖宽度溢出，请重新输入表达式\n");

//宏函数
#define GET_TIME time_t t = time(0); strftime(tmp, sizeof(tmp), "%Y/%m/%d %X %A", localtime(&t));

//1# 素材制作
int material_maker_collect(); //信息收集
int material_maker_export(); //导出
int material_maker_mode(); //模式选择
int material_maker_mode_preset(); //预设项

int png_set_body(); //xml生成
int png_set_escape(int); //转义处理

//2# 素材衍生
int til_set_body(); //til生成主体
int til_set_collect(); //til信息单独收集

int css_set_body(); //css生成主体
int css_set_collect(); //css信息单独收集

//3# 皮肤制作
int skin_maker(); //信息收集
int skin_maker_export(); //导出
int skin_maker_set(); //按行生成
int skin_maker_visual(); //可视化

int ini_set(); //ini生成
int operate_calculator(); //操作符运作
int average_calculator(); //平均值计算器

//4# 其他
int more_tools(); //更多工具
	int pngtext(); //文字图片化
int skin_editor(); //皮肤编辑器 0
int fontcss_set(); //字体样式生成 0

int extract_nums(char*); //导出数字
int smart_strlen(char*); //智能长度计算

//5# 系统控制
int switch_control(int);
int filter(int); //切割器
int help(),ready();

FILE *fp;
FILE *fpp;

// -整体-
int i = 0;
int ii = 0;
int j = 0;
int jj = 0;
int flag = 0;
	
int n = 0;
int choose = 0; //选择
int num = 0; //数量
int result[10]; //用于切割的结果数组

char part[10]; //文件路径
char part2[10];
char tmp[64]; //临时字符串

// -素材制作-
int size; //字体大小
int more = 0; //溢出调节值
int char_num = 5; //字符串长度
int n_exact = 0; //精确生成切片数量
int n_get = 0; //模糊数量

int width = 0;
int height = 0;
int y;
int y_start = 0; //起始y
int style_start = 0; //起始style序号

char font[] = "my_default"; //字体名称
char color[9]; //字体颜色
char til_name[50] = "null"; //素材名称
char remark[50]; //注释前缀
char *names[20]; //切片内容数组

bool p_myfont; //自定义字体
bool p_rectangle; //矩形素材 0
bool p_takecss; //带上css
bool p_notecss; //注释css
bool p_mycssnote; //自定义注释连接符 0
bool p_subline; //辅助线 0

bool p_exact; //精确生成
bool p_empty; //空模板
bool p_placehold; //占位符
bool p_num_placehold; //数字占位
bool p_preset; //预设项

bool p_en; //英文小写
bool p_ens; //英文大写
bool p_nums; //数字
bool p_symbles; //符号

// -皮肤模板-
int back; //背景样式
int line_gap[8][30]; //每行横向间距
int row_gap[8]; //纵向间距

int line = 0; //第x行
int lines = 0; //总行数
int key = 1; //起始按键序号
int keys[10]; //每行按键数

int x[10]; //计算之用
	int xv[10]; //TR开时VR之值
int yv=0;
int h[10];
int hv[10];

int w[8][30]; //按键宽度
int wv[8][30]; //显示按键宽度
int interval = 1; //区间，同时用作判断
int arrow; //箭头·指向xx位置

char operator = '0'; //操作数
char operate[] = "*99"; //操作表达式

bool p_up;
bool p_down;
bool p_pos;
bool p_show;
bool p_hold;
bool p_visual; //old
bool p_advanced;

bool p_left;
bool p_right;
bool p_holdsym;
bool p_touch; //old
bool p_start;
bool p_top_margin; //old
bool p_left_margin; //old
bool p_only_pos;

bool p_export;


int main()
{
	//material_maker_mode_preset();
	//material_maker_mode();
	//png_set_body();
	//skin_maker_set(1);
	//测试头 #
	
	if (access ("/mnt/sdcard/Baidutool", 0) == -1)
		ready();
	printf("　　　—— BGtool v1.2 ——\n");
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
	
	switch(choose){
		//素材制作
		case 1:{
			material_maker_collect();
			material_maker_mode();
			material_maker_export();
			
			png_set_body();
			til_set_body();
			css_set_body();
			NEXT
			
			printf("xml生成至:\n%s\n",P_MATERIAL);
			printf("til生成至:\n%s\n",P_MATERIAL_TIL);
			printf("css(如果有)生成至:\n%s\n",P_CSS);
			
			//如果没有debug，继续操作
			if (debug_mode == false){
				if (y_start == 0)
					system("am start -n com.redphx.simpletext/com.redphx.simpletext.MainActivity");
				else 
					printf("请打开xml文件进行编辑:\n去除原有的</style>，并调整高度为:%d", y_start + height);
			}
			
			break;
		}
		
		//生成til
		case 2:{
			til_set_collect();
			til_set_body();
			
			printf("已生成至:%s\n",P_TIL);
			
			break;
		}
		
		//生成css
		case 3:{
			css_set_collect();
			css_set_body();
			
			printf("已生成至:%s\n",P_CSS);
			
			break;
		}
		
		//皮肤模板制作
		case 4:{
			skin_maker();
			ini_set();
			skin_maker_export();
			
			printf("已生成至:%s\n",P_SKIN);
			
			break;
		}
		
		//字体前景生成
		case 5:{
			fontcss_set();
			
			break;
		}
		
		//皮肤简单操作集
		case 6:{
			skin_editor();
			
			break;
		}
		
		//更多工具...
		case 7:{
			more_tools();
			
			break;
		}
		
		//test
		case 9:{
			filter (123568);
			for (i = 0; i <= 9; i++)
				printf("%d",result[i]);
			
			break;
		}
		
		//帮助
		case 0:{
			help();
			printf("　　‖输入任意内容返回:\n");
			printf("　　‖");
			scanf("%s",operate);
			
			clrscr();
			main();
			
			break;
		}
		
		default:{
			clrscr();
			E_NONE
			main();
			
			break;
		}
	}
	
	return 0;
}


int material_maker_collect()
{
	printf("　　　　　　-素材制作-\n");
	printf("组件‖1>非预设字体\n");
	//printf("　　‖2>矩形素材\n");
	printf("　　‖3>带上css\n");
	printf("　　‖4>带上注释\n");
	//printf("　　‖5>自定义注释格式\n");
	//printf("　　‖6>使用辅助线\n");
	//printf("　　‖7>字体样式变更\n");
	printf("　　‖0>不用了\n");
	printf("　　‖选择：");
	scanf("%d", &choose);
	
	filter(choose);
	S_MATERIAL_COLLECT
	
	printf("字体‖");
	//字体文件存在性检测
	if (p_myfont == true){
		do {
			printf("文件名 (.ttf):");
			scanf("%s", &font);
			printf("　　‖");
			sprintf(part, P_MATERIAL_TTF, font);
		}
		while (access (part, 0) == -1);
	}
	
	printf("颜色：#");
	scanf("%s", &color);
	printf("　　‖大小:");
	scanf("%d", &size);
	printf("　　‖溢出调节值:");
	scanf("%d", &more);
	
	printf("画布‖总宽度(0为自动适配):");
	scanf("%d", &width);
	printf("　　‖起始高度:");
	scanf("%d", &y_start);
	
	printf("样式‖识别名称:");
	scanf("%s", &til_name);
	sprintf(part, P_MATERIAL, til_name);
	
	//检查是否有重名文件
	if (access(part, 0) == -1)
		printf("⚠　‖当前不存在此文件\n");
	else
		printf("⚠　‖当前已存在同名文件\n");
	
	if (p_takecss == true||p_notecss == true){
		printf("　　‖起始样式:");
		scanf("%d", &style_start);
	}
	
	if (p_notecss == true){
		printf("　　‖备注文本:");
		scanf("%s", &remark);
	}
	
	/*
	if (p_mycssnote == true){
		printf("　　‖注释格式:");
	}
	*/
	
	NEXT
	return 0;
}


int material_maker_export()
{
	sprintf(part, P_MATERIAL, til_name);
	
	//以起始高度判断新建 or 追加
	if (y_start == 0){
		fp = fopen(part, "w");
		fprintf(fp, "<?xml version='1.0' encoding='UTF-8' standalone='yes' ?>\n");
	}
	else {
		fp = fopen(part, "a");
		fprintf(fp, "\n<!-- 去除前面的结束符并更改高度为%d -->\n", y_start + height);
	}
	
	/* xml文件备份
	printf("样式‖识别名称:");
	scanf("%s", &til_name);
	if(access(part, F_OK) == 0) {
		printf("同名文件已存在，输入备份信息(0为不备份):");
		scanf("%s", &text);
		if (strcmp("0", &text)!=0){
			sprintf(part2, "/mnt/sdcard/Simple Text/backup/%s - %s.xml", til_name, text);
			rename(part, part2);
		}
	}
	*/
	
	fprintf(fp, "<!-- BGtool\n");
	GET_TIME
	fprintf(fp, "%s\n", tmp);
	
	fprintf(fp, "字体‖");
	if (p_myfont == true){
		fprintf(fp, "文件名 (.ttf):%s\n", font);
		fprintf(fp, "　　‖");
	}
	fprintf(fp, "颜色：#%s\n", color);
	fprintf(fp, "　　‖大小:%d\n", size);
	fprintf(fp, "　　‖溢出调节值:%d\n", more);
	
	fprintf(fp, "画布‖总宽度(0为自动适配):%d\n", width);
	fprintf(fp, "　　‖起始高度:%d\n", y_start);
	
	fprintf(fp, "样式‖识别名称:%s\n", til_name);
	if (p_takecss == true||p_notecss == true){
		fprintf(fp, "　　‖起始样式:%d\n", style_start);
		}
	if (p_notecss == true){
		fprintf(fp, "　　‖备注文本:%s\n", remark);
		}
	fprintf(fp, "\n");
	
	for (i = 0; i < n; i++)
		fprintf(fp, "%s\n", &names+i);
	fprintf(fp, "-->\n");
	
	fclose(fp);
	return 0;
	}


int material_maker_mode()
{
	int choose_backup = choose;
	
	printf("生成‖1>输入并精确生成(&为end)\n");
	printf("方式‖2>快速生成空模板\n");
	printf("　　‖3>快速占位\n");
	printf("　　‖4>快速数字占位\n");
	printf("　　‖5>预设项\n");
	printf("　　‖选择：");
	scanf("%d", &choose);
	
	filter(choose);
	S_MATERIAL_MODE
	
	printf("%d\n",p_takecss);
	printf("%d\n",p_notecss);
	//精确生成
	if (p_exact == true){
		for (i = 0; strcmp("&", &names + i - 1) != 0; i++){
			printf("输入‖第%d个素材:",i + 1);
			scanf("%s", &names + i);
			
			printf("%d\n",p_takecss);
	printf("%d\n",p_notecss);
			//若字符串长度大于保底长，xxxx，求得最长
			if (char_num < smart_strlen(&names + i))
				char_num = smart_strlen(&names + i);
		}
		n_exact = n = i-1; //确定数量
		strcpy(&names + n, ""); //清除"&"之位
	}
	
	//快速生成空模板
	if (p_empty == true){
		printf("空白‖切片数量:");
		scanf("%d",&n_get);
		
		n += n_get;
	}
	
	//快速占位
	if (p_placehold == true){
		printf("占位‖切片数量:");
		scanf("%d",&n_get);
		
		for (i = n; i < n + n_get; i++)
			strcpy(&names+i,PLACEHOLDER);
		
		n += n_get;
	}
	
	//快速数字占位
	if (p_num_placehold == true){
		printf("数字‖切片数量:");
		scanf("%d",&n_get);
		
		for (i = n; i < n + n_get; i++)
			sprintf(&names + i, "%d", i + 1);
		
		n += n_get;
	}
	
	//预设项
	if (p_preset == true){
		NEXT
		material_maker_mode_preset();
	}
	
	if (width == 0) //若未设定画布宽度，则通过最长字符串长度换算
		width = char_num /3 * size;
	
	height = size*n + 2*more*n;
	
	//重新来上次的分割，那个选择会被精确生成模式干扰而改变数值，，这不是好的方法。
	filter(choose_backup);
	S_MATERIAL_COLLECT
	
	LOADING
	NEXT
	return 0;
}


int material_maker_mode_preset()
{
	char en[] = "qwertyuiopasdfghjklzxcvbnm";
	char ens[] = "QWERTYUIOPASDFGHJKLZXCVBNM";
	char symbles[] = T_PRESET_SYM;
	
	printf("预设‖1>英文小写\n");
	printf("组件‖2>英文大写\n");
	printf("　　‖3>数字1~0\n");
	printf("　　‖4>基本符号(beta)\n");
	//printf("　　‖5>扩展符号\n");
	//printf("　　‖6>常用功能键\n");
	
	printf("　　‖选择:");
	scanf("%d",&choose);
	filter(choose);
	S_MATERIAL_PERSET
	
	if (p_en == true){
		for (i = 0; i < 26; i++)
			sprintf(&names + n + i, "%c", *(en + i));
		
		n += 26;
	}
	
	if (p_ens == true){
		for (i = 0; i < 26; i++)
			sprintf(&names + n + i, "%c", *(ens + i));
		
		n += 26;
	}
	
	if (p_nums == true){
		for (i = 0; i < 9; i++)
			sprintf(&names + n + i, "%c", '1' + i);
		
		strcpy(&names + n + 9, "0");
		n += 10;
	}
	
	if (p_symbles == true){
		sprintf(&names + n, "&&"); //标记终止符
		n += 1;
		
		for (i = 0; i < strlen(symbles); i++)
			sprintf(&names + n + i, "%c", *(symbles + i));
		
		n += strlen(symbles);
	}
	
	LOADING
	/* little debug
	for (i = 0; i < n; i++) {
		printf("%s",&names + i);
		png_set_escape();
	}
	*/
	return 0;
}


int png_set_body()
{
	sprintf(part, P_MATERIAL, til_name);
	
	//判断新建 or 追加
	if (y_start == 0){
		fp = fopen(part, "a");
		fprintf(fp,"<style width=\"%d\" height=\"%d\">\n",width,height);
	}
	else {
		fp = fopen(part, "a");
	}
	
	for (i = 0; i < n; i++){
		y = size*(i+1) - (size+3)/7 + more*i*2 + more + y_start; //计算纵坐标：将之前单元格累加，然后修正。并加上单元格上下的溢出值和起始高度。
		png_set_escape(i); //检测并执行转义
		
		if (debug_mode == true)
			printf("	<text align=\"center\" x=\"0.0\" y=\"%d.0\" rotate=\"0\" size=\"%d\" font=\"%s.ttf\" text=\'%s\' color=\"#%s\" autoScaleX=\"0\" scaleX=\"1.0\" flags=\"65\" />\n", y, size, font, &names+i, color);
		else
			fprintf(fp,"	<text align=\"center\" x=\"0.0\" y=\"%d.0\" rotate=\"0\" size=\"%d\" font=\"%s.ttf\" text=\'%s\' color=\"#%s\" autoScaleX=\"0\" scaleX=\"1.0\" flags=\"65\" />\n",y, size, font, &names+i, color);
	}
	
	fprintf(fp, "</style>");
	fclose(fp);
	return 0;
}


int png_set_escape(int pos)
{
	int i;
	int dot[10]; //标记点，标记需转义处
	int dot_num = 0; //标记点数量
	int length; //字符串长度
	char base[20];
	char str_1[60]="";
	char str_2[60]="";
	bool p_again; //再次进行循环的判断
	
	strcpy(base, &names + pos);
	strcpy(str_2, &names + pos);
	
	//查找字符串中是否含有需转义字符
	for (i = 0; i < strlen(&names+pos); i++){
		if (*(base+i) == '<' || *(base+i) == '>' || *(base+i) == '\'' || *(base+i) == '&'){
			dot[dot_num] = i; //记录点的位置
			dot_num ++;
			
			if (*(base+i) == '&'){
				if (*(base+i+1) == '&' || *(base+i+1) == '_')
					i++;
				else
					p_again = true; //检测到有单个&存在
			}
		}
	}
	
	//替换需转义字符
	for (i = 0; i < dot_num; i++){
		//判断长度
		if (i > 0)
			length = dot[i] - dot[i-1] - 1;
		else
			length = dot[i];
		
		if (i > 0 && *(base+dot[i-1]) == '&')
			length --; //缩短长度
		
		strncat(str_1,str_2,length); //连接前后字符串
		if (*(base+dot[i]) == '<')
			strcat(str_1,"&lt;");
		
		if (*(base+dot[i]) == '>')
			strcat(str_1,"&gt;");
		
		if (*(base+dot[i]) == '\'')
			strcat(str_1,"&apos;");
		
		if (*(base+dot[i]) == '&') {
			if (*(base+dot[i]+1) == '&')
				strcat(str_1,"&amp;");
			
			if (*(base+dot[i]+1) == '_')
				strcat(str_1," ");
			
			length ++;
		}
		strcpy(str_2,str_2+length+1);
	}
	
	if (p_again == false){
		strcat(str_1, str_2); //连接1、2短语
		strcpy(&names+pos, str_1); //将短语加回文本流中
	}
	else {
		printf("⚠　‖字段\"%s\"有错误，请重新输入:\n", base);
		printf("　　‖");
		scanf("%s", &names+pos);
		png_set_escape(pos);
	}
	
	return 0;
}


int til_set_body()
{
	int x = 0; //横坐标
	int y_start_backup = y_start; //起始y值备份
	int n_backup = n; //数量备份
	
	//若起始y值不为0，则进行估算
	if (y_start != 0) {
		n += y_start / (size + more*2); //将前排数量补足
		
		y_start = 0;
		til_set_body(); //令起始值为0后重新执行函数
		
		n = n_backup;
		y_start = y_start_backup;
		strcpy(&til_name, "null"); //默认null
	}
	
	//若til_name不为null，则将til文件生成至ST目录，否则，生成至默认工作目录
	if (strcmp("null", &til_name) != 0)
		sprintf(part, P_MATERIAL_TIL, til_name);
	else
		sprintf(part,P_TIL,til_name);
	
	//写头
	fp = fopen(part, "w");
	if (y_start == 0){
		fprintf(fp,"[GLOBAL]\n");
		fprintf(fp,"	USE_ALPHA = 1\n");
		fprintf(fp,"	TILE_NUM = %d\n",n);
	}
	
	//写body
	for (i = 0; i < n; i++){
		y = (size + 2*more) * i + y_start;
		
		fprintf(fp,"\n[IMG %d]\n",y_start/(size+more*2) + i + 1);
		fprintf(fp,"	SOURCE_RECT = %d,%d,%d,%d\n", x, y, width, size+2*more);
	}
	
	fclose(fp);
	return 0;
}


int css_set_body()
{
	//若个数为0，则依据单元格大小自动计算
	if (num == 0)
		num = y_start/(size+more*2) + 1;
	
	fp = fopen(P_CSS, "w");
	
	//无注释css
	if (p_takecss == true && p_notecss == false){
		for (i = 0; i < n; i++){
			fprintf(fp,T_STYLE,style_start+i);
			fprintf(fp,T_NM_IMG,til_name,num+i);
			fprintf(fp,T_HL_IMG,til_name,num+i);
		}
	}
	
	//注释css
	if (p_notecss == true){
		for (i = 0; i < n_exact; i++){
			fprintf(fp,T_STYLE_NOTE,style_start+i,remark);
			fprintf(fp,"%s\n",&names+i);
			fprintf(fp,T_NM_IMG,til_name,num+i);
			fprintf(fp,T_HL_IMG,til_name,num+i);
		}
		
		for (i = n_exact; i < n; i++){
			fprintf(fp,T_STYLE_NOTE,style_start+i,remark);
			fprintf(fp,"\n");
			fprintf(fp,T_NM_IMG,til_name,num+i);
			fprintf(fp,T_HL_IMG,til_name,num+i);
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
	//printf("　　‖6>可视化操作(beta)\n"); //old 现默认开启
	printf("　　‖7>高级模式\n");
	printf("　　‖0>不用了\n");
	
	printf("　　‖选择:");
	scanf("%d", &choose);
	filter(choose);
	S_SKIN_COLLECT1
	
	if (p_advanced == true){
		NEXT
		printf("高级‖1>LEFT=\n");
		printf("　　‖2>RIGHT=\n");
		printf("　　‖3>HOLDSYM=\n");
		//printf("　　‖4>TOUCH_RECT=(慎用!)\n"); old
		printf("　　‖5>起始序号\n");
		//printf("　　‖6>空行预留\n");
		//printf("　　‖7>\n");
		printf("　　‖8>仅坐标\n");
		printf("　　‖0>还是不用了\n");
		
		printf("　　‖选择:");
		scanf("%d", &choose);
		filter(choose);
		S_SKIN_COLLECT2
	}
	
	printf("面板‖总宽:");
	scanf("%d", &width);
	printf("　　‖总行数:");
	scanf("%d", &lines);
	
	if (p_only_pos == false){
		printf("按键‖默认背景样式:");
		scanf("%d", &back);
	}
	
	if (p_start == true){
		printf("　　‖起始序号:");
		scanf("%d", &key);
	}
	
	for (line = 0; line < lines; line++)
		skin_maker_set();
	
	LOADING
	return 0;
}


int skin_maker_set()
{
	int width_backup;
	
	printf("\n第%d行>>\n", line + 1);
	width_backup = width;
	
	for (;;) {
		printf("　　‖现有%d空间盈余，请划分区间\n", width);
		printf("　　‖(1-20为分数，0为结束)\n");
		//负数为指定区块序号 0
		//scanf("%d", &interval);
		
		printf("　　‖操作表达式:");
		scanf("%s", &operate);
		if (strcmp("0", operate) == 0)
			break; //循环出口
		else
			extract_nums(operate);
		
		//printf("%d %d ", interval, num);
		operate_calculator();
		interval = 0;
		
		//可视化，现直接开启
		//if (p_visual == true)
			skin_maker_visual();
		
		if (width == 0) {
			printf("　　‖已排满\n");
			break; //被动出口
		}
	}
	
	//按键高度设定，防第一行即为0 (有问题，禁用)
	//do {
		printf("按键‖高度(0取前行值):");
		scanf("%d", &h[line]);
	//}
	//while (h[line] == 0 && line == 0);
	
	if (h[line] == 0)
		h[line] = h[line-1];
	
	width = width_backup;
	arrow = 0;
	
	return 0;
}


int operate_calculator()
{
	int interval_backup;
	
	//若操作数为0，则补充表达式以继续
	if (operator == '0') {
		E_ADD_OPERATE
		scanf("%s", &operate);
		
		interval_backup = interval;
		extract_nums(operate);
		interval = interval_backup;
		}
	
	//按实际操作符进行操作
	switch (operator) {
		//&，增加纵向间隔
		case '&' :{
			if (num == 0) {
				E_ADD_OPERATE
				scanf("%d", &num);
			}
			row_gap[line] = num;
			break;
		}
		
		//+，增加横向间隔
		case '+' :{
			if (num == 0) {
				E_ADD_OPERATE
				scanf("%d", &num);
			}
			if (width - num < 0) {
				E_OUT_WIDTH //宽度溢出
				break;
			}
			width -= num;
			line_gap[line][arrow] = num;
			break;
		}
		
		//case "-" :
		
		// *，相同按键
		case '*' :{
			if (num == 0) {
				E_ADD_OPERATE
				scanf("%d", &num);
			}
			
			if (width - (interval * num) < 0) {
				E_OUT_WIDTH //宽度溢出
				break;
			}
			width -= (interval * num);
			
			for (i = 0; i < num; i++){
				w[line][arrow] = interval;
				arrow += 1;
				keys[line]++;
			}
			break;
		}
		
		case '/' :{
			if (num == 0){
				E_ADD_OPERATE
				scanf("%d", &num);
			}
			
			interval /= num;
			printf("　　‖计算得单元长度为:%d\n", interval);
			
			if (width - (interval * num) < 0){
				E_OUT_WIDTH //宽度溢出
				break;
			}
			width -= (interval * num);
			
			for (i = 0; i < num; i++){
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
	int i;
	int ii;
	int j;
	int key_tmp;
	
	//描绘行的循环
	for (j = 0; j < lines; j++){
		printf("[");
		
		//指定行
		for (i = 0; i < keys[j]; i++){
			if (line_gap[j][i] != 0){
				printf("+%d",line_gap[j][i]); //打印空之间隔
				
				printf("]");
				printf("[");
			}
			key_tmp = w[j][i];
			
			for (ii=0; key_tmp == w[j][i+ii]; ii++) {} //计算相同宽度之键的数目
			printf("|%d",key_tmp); //打印宽度
			
			if (ii != 1)
				printf("*%d",ii); //打印个数
			
			ii --;
			i += ii;
		}
		
		if (line_gap[j][i] != 0){
			printf("+%d",line_gap[j][i]);
			printf("]");
			printf("[");
		}
		
		printf("]");
		
		//打印纵间隔
		if (row_gap[j] != 0){
			printf(" ");
			printf("^%d",row_gap[j]);
		}
		
		printf("\n");
	}
	
	/*if (p_export == true && flag != 1){
		//fp = fopen(P_SKIN_EXPORT,"a");
		flag = 1;
		fp = freopen (P_SKIN_EXPORT,"a",fp);
		skin_maker_visual();
		fclose(fp);
		}*/
	
	NEXT
	return 0;
}


int skin_maker_export()
{
	fp = fopen(P_SKIN_EXPORT,"a");
	GET_TIME
	fprintf(fp,"\n%s\n", tmp);
	
	fprintf(fp,"　　　　　　-皮肤模板-\n");
	fprintf(fp,"组件‖1>UP=\n");
	fprintf(fp,"多选‖2>DOWN=\n");
	fprintf(fp,"　　‖3>POS_TYPE=\n");
	fprintf(fp,"　　‖4>SHOW=\n");
	fprintf(fp,"　　‖5>HOLD=\n");
	fprintf(fp,"　　‖7>高级模式\n");
	fprintf(fp,"　　‖0>不用了\n");
	
	fprintf(fp,"　　‖选择:");
	fprintf(fp,"%d\n", choose);
	
	if (p_advanced == true){
		fprintf(fp,"\n");
		fprintf(fp,"高级‖1>LEFT=\n");
		fprintf(fp,"　　‖2>RIGHT=\n");
		fprintf(fp,"　　‖3>HOLDSYM=\n");
		fprintf(fp,"　　‖5>起始序号\n");
		fprintf(fp,"　　‖8>仅坐标\n");
		fprintf(fp,"　　‖0>还是不用了\n");
		
		fprintf(fp,"　　‖选择:");
		fprintf(fp,"%d\n", choose);
	}
	
	fprintf(fp,"面板‖总宽:");
	fprintf(fp,"%d\n", width);
	fprintf(fp,"　　‖总行数:");
	fprintf(fp,"%d\n", lines);
	
	if (p_only_pos == false){
		fprintf(fp,"按键‖默认背景样式:");
		fprintf(fp,"%d\n", back);
	}
	
	if (p_start == true){
		fprintf(fp,"　　‖起始序号:");
		fprintf(fp,"%d\n", key);
	}
	
	fprintf(fp,"\n");
	
	
	int i;
	int ii;
	int j;
	int key_tmp;
	
	//描绘行的循环
	for (j = 0; j < lines; j++){
		fprintf(fp,"[");
		
		//指定行
		for (i = 0; i < keys[j]; i++){
			if (line_gap[j][i] != 0){
				fprintf(fp,"+%d",line_gap[j][i]); //打印空之间隔
				
				fprintf(fp,"]");
				fprintf(fp,"[");
			}
			key_tmp = w[j][i];
			
			for (ii=0; key_tmp == w[j][i+ii]; ii++) {} //计算相同宽度之键的数目
			fprintf(fp,"|%d",key_tmp); //打印宽度
			
			if (ii != 1)
				fprintf(fp,"*%d",ii); //打印个数
			
			ii --;
			i += ii;
		}
		
		if (line_gap[j][i] != 0){
			fprintf(fp,"+%d",line_gap[j][i]);
			fprintf(fp,"]");
			fprintf(fp,"[");
		}
		
		fprintf(fp,"]");
		
		//打印纵间隔
		if (row_gap[j] != 0){
			fprintf(fp," ");
			fprintf(fp,"^%d",row_gap[j]);
		}
		
		fprintf(fp,"\n");
	}
	
	fclose(fp);
	
	/* p_export = true;
	skin_maker_visual();
	*/
	return 0;
}


int ini_set()
{
	fp = fopen(P_SKIN, "w");
	
	//若起始序号为1，则打印头
	if (key == 1){
		fprintf(fp,"[INPUT]\n\n");
		fprintf(fp,"[CAND]\n\n");
		fprintf(fp,"[PANEL]\n\n");
		fprintf(fp,"[MORE]\n\n");
		fprintf(fp,"[HINT]\n\n");
		fprintf(fp,"[LIST]\n");
	}
	
	for(line = 0; line < lines; line++){
		y += row_gap[line];
		yv += row_gap[line];
		for(i = 0; i < keys[line]; i++){
			x[line] += line_gap[line][i];
			
			//皮肤模板//
			fprintf(fp,"\n[KEY %d]\n",key);
			if (p_touch == true){
				fprintf(fp,"	VIEW_RECT = %d,%d,%d,%d\n",xv[line],yv,wv[line][i],hv[line]);
				fprintf(fp,"	TOUCH_RECT = %d,%d,%d,%d\n",x[line],y,w[line][i],h[line]);
				}
			else {
				fprintf(fp,"	VIEW_RECT = %d,%d,%d,%d\n",x[line],y,w[line][i],h[line]);
				}
			
			if (p_only_pos == false){
				fprintf(fp,"	BACK_STYLE = %d\n",back);
				fprintf(fp,"	FORE_STYLE = \n");
				}
			
			if (p_pos == true)
				fprintf(fp,"	POS_TYPE = \n");
			
			if (p_only_pos == false){
				fprintf(fp,"	\n");
				fprintf(fp,"	CENTER = \n");
				}
			
			if (p_hold == true)
				fprintf(fp,"	HOLD = \n");
			
			if (p_holdsym == true)
				fprintf(fp,"	HOLDSYM = \n");
			
			if (p_show == true)
				fprintf(fp,"	SHOW = \n");
			
			//若有如下之一，则打印Tab与前段分割
			if (p_up == true || p_down == true || p_left == true || p_right == true)
				fprintf(fp,"	\n");
			
			if (p_up == true)
				fprintf(fp,"	UP = \n");
			
			if (p_down == true)
				fprintf(fp,"	DOWN = \n");
			
			if (p_left == true)
				fprintf(fp,"	LEFT = \n");
			
			if (p_right == true)
				fprintf(fp, "	RIGHT = \n");
			
			if (p_touch == true)
				xv[line] = xv[line] + wv[line][i];
			
			if (p_only_pos == true)
				fprintf(fp,"\n");
			
			x[line] = x[line] + w[line][i];
			key++;
		}
		y += h[line];
		yv += hv[line];
	}
	fclose(fp);
	
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
		operator = *base; //操作符取得
		d = 1;
		interval = 1;
	}
	
	else {
		interval = atoi(base); //导出区间
		
		for (i = 0; i < strlen(base); i++){
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
	//return num
}


int smart_strlen(char *base)
{
	int i;
	int n = 0;
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
	for (i = 0; i <= 9; i++){
		result[i] = 0;
	}
	
	if (base != -1){
		result[base%10] = 1;
		for (i = 0; base /= 10; i++){
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
	
	switch(choose){
		case 1:{
			debug_mode = true;
			clrscr();
			
			printf("正在使用debug模式...\n");
			main();
			
			break;
		}
		
		case 2:{
			debug_mode = true;
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
	sprintf(part,P_MATERIAL,til_name);
	
	fp=fopen(part,"w");
	fclose(fp);
	
	return 0;
}


int ready()
{
	system("mkdir /sdcard/Baidutool");
	/*if (access("/mnt/sdcard/baidu/ime/.emoji",0) == -1)
		system("mkdir /mnt/sdcard/baidu/ime/.emoji");
	
	if (access("/mnt/sdcard/Simple Text",0) t== -1)
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
	printf("\n");
	printf("综述‖组件多选:直接输数字无需分隔符\n");
	printf("　　‖设置里可调节字体大小\n");
	printf("素材‖特殊转义:& → &&  空格 → &_\n");
	printf("皮肤‖操作表达式说明\n");
	printf("　　‖格式:①[区间]+[操作符]+[数字]，例:60*7\n");
	printf("　　‖　　 ②[操作符]+[数字]，例:*75\n");
	printf("　　‖[*] - 复制此区间①  [/] - 分割此区间①\n");
	printf("　　‖[+] - 增加横向空白②  [&] - 增加纵向空白②\n");
	printf("\n");
	printf("关于‖软 / Gearkey\n");
	printf("　　‖发布页 http:\/\/dwz.cn/gi-bgtool\n");
	
	return 0;
}
