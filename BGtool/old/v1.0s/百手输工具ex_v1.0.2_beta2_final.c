#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

#define PART 50

int material_maker(int main_choose);
int til_set(int main_choose);
int css_set(int main_choose);
int skin_maker();
int coordinate_calculator(int main_choose);
int fontcss_set();
int help();
FILE *fp;

int i,j,n;
int set_choose,set_chooses[10];
char part[PART];

int main()
{
system("mkdir /mnt/sdcard/Baidutool");
clrscr();
int main_choose;
printf("　　　——百手输工具ex 1.0.2 beta——\n");
printf("素材‖1>简单素材\n制作‖2>全套制作\n　　‖3>全套&注释css\n　　‖4>生成til【41+左边距】\n　　‖5>生成css【51+待定注释】\n皮肤‖6>模板制作\n相关‖7>平均值法估测【71+间隔】\n　　‖8>背景til制作【81+左边距】\n　　‖9>字体前景生成\n　　‖0>帮助\n　　‖选择:");
scanf("%d",&main_choose);
switch(main_choose)
{
case 1:
case 2:
case 3:{
	material_maker(main_choose);
	break;
	}
case 4:
case 41:
case 8:
case 81:{
	til_set(main_choose);
	break;
	}
case 5:
case 51:{
	css_set(main_choose);
	break;
	}
case 6:{
	skin_maker();
	break;
	}
case 7:
case 71:{
	coordinate_calculator(main_choose);
	break;
	}
case 9:{
	fontcss_set();
	break;
	}
case 0:{
	help();
	break;
	}
}
return 0;
}//main_end

int material_maker(int main_choose)
{
int size,more;
int width,height;
int x=0,y,y_start;
int style_start;
char font[10],color[10];
char names[50][50],zw[10]="占";
char til_name[50],remark[50];
printf("　　　　　　-素材制作-\n");
printf("字体‖文件名 (.ttf):");
scanf("%s",font);
printf("　　‖颜色：#");
scanf("%s",color);
printf("　　‖大小:");
scanf("%d",&size);
printf("　　‖溢出调节值:");
scanf("%d",&more);
printf("画布‖总宽度:");
scanf("%d",&width);
printf("　　‖起始高度:");
scanf("%d",&y_start);
printf("样式‖识别名称:");
scanf("%s",til_name);
if (main_choose!=1){
	printf("　　‖起始样式:");
	scanf("%d",&style_start);
	}
if (main_choose==3){
	printf("　　‖备注文本:");
	scanf("%s",remark);
	}
printf("...\n");
printf("生成‖1>输入并精确生成(&为end)\n方式‖2>安全模式\n　　‖3>快速生成空模板\n　　‖4>快速占位\n　　‖5>快速数字占位\n　　‖6>英文小写\n　　‖7>英文大写\n　　‖8>数字1~0\n　　‖9>预设符号\n　　‖选择：");
scanf("%d",&set_choose);
/*if (set_choose > 10){
	set_chooses[set_choose%10]=set_choose%10;
	for(i=1;set_choose/=10;i++){
	set_chooses[set_choose%10]=set_choose%10;
		}
	}*/
switch(set_choose)
{
case 1:{
	for (i=0;names[i-1][0] != '&';i++){
		printf("输入‖第%d个素材:",i+1);
		scanf("%s",names[i]);
/*		for (j=0;j<50;j++){
			if (names[i][j] == '<'){
				names[i][j] = '
				}
			if (names[i][j] == '>'){
				
				}
			}*/
		}
	n=i-1;
	height=size*n+2*more*n;
	break;
	}
case 2:{
	printf("补充‖切片数量:");
	scanf("%d",&n);
	for (i=0;i<n;i++){
		printf("输入‖第%d个素材:",i+1);
		scanf("%s",names[i]);
		}
	height=size*n+2*more*n;
	break;
	}
case 3:
case 4:
case 5:{
	printf("补充‖切片数量:");
	scanf("%d",&n);
	height=size*n+2*more*n;
	break;
	}
case 6:
case 7:{
	n=26;
	height=size*n+2*more*n;
	break;
	}
case 8:{
	n=10;
	height=size*n+2*more*n;
	break;
	}
default:break;
}
/*写输入的说明文件*/
fp=fopen("/mnt/sdcard/Baidutool/#素材制作说明.txt","a");
fprintf(fp,"\n\n-素材制作-\n");
fprintf(fp,"字体‖文件名 (.ttf):%s\n",font);
fprintf(fp,"　　‖颜色：#%s\n",color);
fprintf(fp,"　　‖大小:%d\n",size);
fprintf(fp,"　　‖溢出调节值:%d\n",more);
fprintf(fp,"画布‖总宽度:%d\n",width);
fprintf(fp,"　　‖起始高度:%d\n",y_start);
fprintf(fp,"样式‖识别名称:%s\n",til_name);
if (main_choose!=1){
	fprintf(fp,"　　‖起始样式:%d\n",	style_start);
	}
if (main_choose==3){
	fprintf(fp,"　　‖备注文本:%s\n\n",remark);
	}
fprintf(fp,"%s\n%s\n%d\n%d\n%d\n%d\n%s\n",font,color,size,more,width,y_start,til_name);
if (main_choose!=1){
	fprintf(fp,"%d\n",style_start);
	}
if (main_choose==3){
	fprintf(fp,"%s\n",remark);
	}
switch(set_choose)
{
case 1:{
	for (i=0;names[i-1][0] != '&';i++){
		fprintf(fp,"%s\n",names[i]);
		}
	break;
	}
case 2:{
	fprintf(fp,"%d\n",n);
	for (i=0;i<n;i++){
		fprintf(fp,"%s\n",names[i]);
		}
	break;
	}
case 3:
case 4:
case 5:{
	fprintf(fp,"%d\n",n);
	break;
	}
default:break;
}
fclose(fp);

sprintf(part,"/mnt/sdcard/Simple Text/styles/%s.xml",til_name);
if(y_start==0){
fp=fopen(part,"w");
	fprintf(fp,"<?xml version='1.0' encoding='UTF-8' standalone='yes' ?>\n");
	fprintf(fp,"<style width=\"%d\" height=\"%d\">\n",width,height);
	}
else{
fp=fopen(part,"a");
}
switch(set_choose)
{
case 1:
case 2:{
	for (i=0;i<n;i++){
		y=size*(i+1)-(size+3)/7+more*i*2+more+y_start;
		fprintf(fp,"   <text align=\"center\" x=\"0.0\" y=\"%d.0\" rotate=\"0\" size=\"%d\" font=\"%s.ttf\" text=\"%s\" color=\"#%s\" autoScaleX=\"0\" scaleX=\"1.0\" flags=\"65\" />\n",y,size,font,names[i],color);
		}
	break;
	}
case 3:{
	for (i=0;i<n;i++){
		y=size*(i+1)-(size+3)/7+more*i*2+more+y_start;
		fprintf(fp,"   <text align=\"center\" x=\"0.0\" y=\"%d.0\" rotate=\"0\" size=\"%d\" font=\"%s.ttf\" text=\"\" color=\"#%s\" autoScaleX=\"0\" scaleX=\"1.0\" flags=\"65\" />\n",y,size,font,color);
		}
	break;
	}
case 4:{
	for (i=0;i<n;i++){
		y=size*(i+1)-(size+3)/7+more*i*2+more+y_start;
		fprintf(fp,"   <text align=\"center\" x=\"0.0\" y=\"%d.0\" rotate=\"0\" size=\"%d\" font=\"%s.ttf\" text=\"占\" color=\"#%s\" autoScaleX=\"0\" scaleX=\"1.0\" flags=\"65\" />\n",y,size,font,color);
		}
	break;
	}
case 5:{
	for (i=0;i<n;i++){
		y=size*(i+1)-(size+3)/7+more*i*2+more+y_start;
		fprintf(fp,"   <text align=\"center\" x=\"0.0\" y=\"%d.0\" rotate=\"0\" size=\"%d\" font=\"%s.ttf\" text=\"%d\" color=\"#%s\" autoScaleX=\"0\" scaleX=\"1.0\" flags=\"65\" />\n",y,size,font,i+1,color);
		}
	break;
	}
case 6:{
	char abc[]={'q','w','e','r','t','y','u','i','o','p','a','s','d','f','g','h','j','k','l','z','x','c','v','b','n','m'};
	for (i=0;i<26;i++){
		y=size*(i+1)-(size+3)/7+more*i*2+more+y_start;
		fprintf(fp,"   <text align=\"center\" x=\"0.0\" y=\"%d.0\" rotate=\"0\" size=\"%d\" font=\"%s.ttf\" text=\"%c\" color=\"#%s\" autoScaleX=\"0\" scaleX=\"1.0\" flags=\"65\" />\n",y,size,font,abc[i],color);
		}
	break;
	}
case 7:{
	char abc[]={'Q','W','E','R','T','Y','U','I','O','P','A','S','D','F','G','H','J','K','L','Z','X','C','V','B','N','M'};
	for (i=0;i<26;i++){
		y=size*(i+1)-(size+3)/7+more*i*2+more+y_start;
		fprintf(fp,"   <text align=\"center\" x=\"0.0\" y=\"%d.0\" rotate=\"0\" size=\"%d\" font=\"%s.ttf\" text=\"%c\" color=\"#%s\" autoScaleX=\"0\" scaleX=\"1.0\" flags=\"65\" />\n",y,size,font,abc[i],color);
		}
	break;
	}
case 8:{
	char abc[]={'1','2','3','4','5','6','7','8','9','0'};
	for (i=0;i<10;i++){
		y=size*(i+1)-(size+3)/7+more*i*2+more+y_start;
		fprintf(fp,"   <text align=\"center\" x=\"0.0\" y=\"%d.0\" rotate=\"0\" size=\"%d\" font=\"%s.ttf\" text=\"%c\" color=\"#%s\" autoScaleX=\"0\" scaleX=\"1.0\" flags=\"65\" />\n",y,size,font,abc[i],color);
		}
	break;
	}
case 9:{
	char abc[]={'1','2','3','4','5','6','7','8','9','0'};
	}
default:break;
}
fprintf(fp,"</style>");
fclose(fp);

sprintf(part,"/mnt/sdcard/Simple Text/%s.til",til_name);
if(y_start==0){
fp=fopen(part,"w");
	fprintf(fp,"[GLOBAL]\n");
	fprintf(fp,"USE_ALPHA=1\n");
	fprintf(fp,"TILE_NUM=%d\n",n);
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


fp=fopen("/mnt/sdcard/Baidutool/#css段.txt","w");
switch(main_choose)
{
case 1:{
	break;
	}
case 2:{
	for(i=0;i<n;i++){
		fprintf(fp,"[STYLE%d]\n",style_start+i);
		fprintf(fp,"NM_IMG=%s,%d\n",til_name,y_start/(size+more*2)+i+1);
		fprintf(fp,"HL_IMG=%s,%d\n\n",til_name,y_start/(size+more*2)+i+1);
	}
	break;
	}
case 3:{
if (set_choose==1||set_choose==2){
	for(i=0;i<n;i++){
		fprintf(fp,"[STYLE%d] %s - %s\n",style_start+i,remark,names[i]);
		fprintf(fp,"NM_IMG=%s,%d\n",til_name,y_start/(size+more*2)+i+1);
		fprintf(fp,"HL_IMG=%s,%d\n\n",til_name,y_start/(size+more*2)+i+1);
		}
	}
else {
	for(i=0;i<n;i++){
		fprintf(fp,"[STYLE%d] %s - \n",style_start+i,remark);
		fprintf(fp,"NM_IMG=%s,%d\n",til_name,y_start/(size+more*2)+i+1);
		fprintf(fp,"HL_IMG=%s,%d\n\n",til_name,y_start/(size+more*2)+i+1);
		}
	}
break;
}
}
fclose(fp);
if(y_start==0){
	system("am start -n com.redphx.simpletext/com.redphx.simpletext.MainActivity");
	}
else{
	printf("请打开xml文件进行编辑:\n去除原有的</style>，并调整高度为:%d",y_start+height);
	}
return 0;
}//end

int til_set(int main_choose)
{
int tensile;
int w,h,x=0,y=0,y_start;
char til_name[50];
printf("　　　　　　-til生成-\n");
printf("整体‖识别名称:");
scanf("%s",til_name);
printf("　　‖起始高度:");
scanf("%d",&y_start);
if (main_choose==41||main_choose==81){
	printf("　　‖左边距:");
	scanf("%d",&x);
	}
printf("单元‖高度:");
scanf("%d",&h);
printf("　　‖宽度:");
scanf("%d",&w);
if (main_choose==8||main_choose==81){
	printf("　　‖拉伸边距:");
	scanf("%d",&tensile);
	}
printf("　　‖切片个数:");
scanf("%d",&n);
sprintf(part,"/mnt/sdcard/Baidutool/%s.til",til_name);
if(y_start==0){
fp=fopen(part,"w");
	fprintf(fp,"[GLOBAL]\n");
	fprintf(fp,"USE_ALPHA=1\n");
	fprintf(fp,"TILE_NUM=%d\n",n);
	}
else{
	fp=fopen(part,"a");
	}
if (main_choose==4||main_choose==41){
for (i=0;i<n;i++){
	y=h*i+y_start;
	fprintf(fp,"\n[IMG%d]\n",i+1);
	fprintf(fp,"SOURCE_RECT=%d,%d,%d,%d\n",x,y,w,h);
	}
}
else{
for (i=0;i<n;i++){
	y=h*i+y_start;
	fprintf(fp,"\n[IMG%d]\n",i+1);
	fprintf(fp,"SOURCE_RECT=%d,%d,%d,%d\n",x,y,w,h);
	fprintf(fp,"INNER_RECT=%d,%d,%d,%d\n",x+tensile,y+tensile,w-tensile*2,h-tensile*2);
	}
}
fclose(fp);
return 0;
}//end


int css_set(int main_choose)
{
int til=1,style=1;
char til_name[20],remark[20];
printf("　　　　　　-css生成-\n");
printf("素材‖识别名称:");
scanf("%s",til_name);
printf("　　‖起始切片:");
scanf("%d",&til);
printf("样式‖起始样式:");
scanf("%d",&style);
printf("　　‖数量:");
scanf("%d",&n);
fp=fopen("/mnt/sdcard/Baidutool/#css段.txt","w");
switch (main_choose){
case 5:{
	for(i=0;i<n;i++){
		fprintf(fp,"[STYLE%d]\n",style);
		fprintf(fp,"NM_IMG=%s,%d\n",til_name,til);
		fprintf(fp,"HL_IMG=%s,%d\n\n",til_name,til);
		style+=1;
		til+=1;
		}
	break;
	}
case 51:{
printf("　　‖统一备注文本:");
scanf("%s",remark);
	for(i=0;i<n;i++){
		fprintf(fp,"[STYLE%d]%s - \n",style,remark);
		fprintf(fp,"NM_IMG=%s,%d\n",til_name,til);
		fprintf(fp,"HL_IMG=%s,%d\n\n",til_name,til);
		style+=1;
		til+=1;
		}
	break;
	}
}
fclose(fp);
return 0;
}//end

int skin_maker()
{
int width,back,line_gap=0,row_gap=0;
int line=0,lines,key=1,keys[10];
int x[10],y=0,xv[10],yv=0,h[10],hv[10];
int w[10][20],wv[10][20],wn,more;
int level,level_w,level_wv,level_keys;
int zero[10],zerov[10];
int xx,xxv;//x，xv的备份
printf("　　　　　　-皮肤模板-\n");
printf("组件‖1>UP=\n多选‖2>DOWN=\n　　‖3>LEFT=\n　　‖4>RIGHT=\n　　‖5>SHOW=\n　　‖6>HOLD=\n　　‖7>HOLDSYM=\n　　‖8>TOUCH_RECT=\n　　‖9>高级模式\n　　‖0>不用了\n　　‖选择:");
scanf("%d",&set_choose);
set_chooses[set_choose%10]=set_choose%10;
for(i=1;set_choose/=10;i++){
	set_chooses[set_choose%10]=set_choose%10;
	}//视位放数
/*第一部分:整体得值*/
printf("面板‖总宽:");
scanf("%d",&width);
printf("　　‖总行数:");
scanf("%d",&lines);
printf("按键‖默认背景样式:");
scanf("%d",&back);
if (set_chooses[9]==9){
	printf("　　‖起始序号:");
	scanf("%d",&key);
	printf("　　‖上边距:");
	scanf("%d",&y);
	if (set_chooses[8]==8){
		printf("　　‖【显示】上边距:");
		scanf("%d",&yv);
	}
}
if (set_chooses[8]==8){
	printf("　　‖【显示】横向间隔:");
	scanf("%d",&line_gap);
	printf("　　‖【显示】纵向间隔:");
	scanf("%d",&row_gap);
	}
/*第二部分:行循环计算宽度*/
for (line=0;line<lines;line++)
{
x[line]=0;
xv[line]=0;
printf("\n第%d行>>\n",line+1);
printf("方式‖1>平均值法(现已自动左右闰值)\n　　‖2>层次算法\n　　‖3>标准相增\n　　‖4>逐键输入\n　　‖选择:");
scanf("%d",&set_choose);
printf("按键‖高度(0取前行值):");
scanf("%d",&h[line]);
if (h[line]==0){
	h[line]=h[line-1];
	}
if (set_chooses[8]==8){
	printf("　　‖【显示】高度(0取前行值):");
	scanf("%d",&hv[line]);
	if (hv[line]==0){
		hv[line]=hv[line-1];
		}
	}
if (set_choose==1||set_choose==3){
	printf("　　‖总数(0取前行值):");
	scanf("%d",&keys[line]);
	if (keys[line]==0){
		keys[line]=keys[line-1];
		}
	}
if (set_chooses[9]==9){
	printf("　　‖左边距:");
	scanf("%d",&x[line]);
	if (set_chooses[8]==8){
		printf("　　‖【显示】左边距:");
		scanf("%d",&xv[line]);
		}
	}
switch(set_choose)
{
case 1:{
/*计算w由此开始*/
wn=(width-x[line]*2)/keys[line];
printf("　　‖计算得出标准值为:%d\n",wn);
for (i=0;i<keys[line];i++){
	w[line][i]=wn;
	}//遍历每个宽度为标准值
wn=wn*keys[line]+x[line]*2;
more=width-wn;
printf("　　‖已自动闰%d个键\n",more);
for (i=0;more!=0;i++){
	w[line][i]+=1;
	more-=1;
	if (more!=0){
		w[line][keys[line]-i-1]+=1;
		more-=1;
		}
	}
/*计算wv由此开始*/
if (set_chooses[8]==8){
wn=(width-line_gap*(keys[line]-1)-xv[line]*2)/keys[line];
printf("\n　　‖计算得出【显示】标准值为:%d",wn);
//(总宽-总间隔-左右边距)/按键总数
for (i=0;i<keys[line];i++){
	wv[line][i]=wn;
	}
wn=line_gap*(keys[line]-1)+xv[line]*2+wn*keys[line];
more=width-wn;
printf("\n　　‖【显示】已自动闰%d个键\n",more);
for (i=0;more!=0;i++){
	wv[line][i]+=1;
	more-=1;
	if (more!=0){
		wv[line][keys[line]-i-1]+=1;
		more-=1;
		}
	}
}
break;
}
case 2:{
/*层次法开始*/
keys[line]=0;
for (level=1;;level++){
	printf("　　‖第%d层的按键个数(0为退出):",level);
	scanf("%d",&level_keys);
	if (level_keys==0){
		break;
		}
	else{
		printf("　　‖按键宽度:");
		scanf("%d",&level_w);
		if (set_chooses[8]==8){
			printf("　　‖【显示】按键宽度:");
			scanf("%d",&level_wv);
			}
		for (i=0;i<level_keys;i++){
			i+=keys[line];
			w[line][i]=level_w;
			if (set_chooses[8]==8){
				wv[line][i]=level_wv;
				}
			i-=keys[line];
			}
			keys[line]+=level_keys;
		}
	}
break;
}
case 3:{
/*标准相增法开始*/
printf("　　‖此行零点:");
scanf("%d",&zero[line]);
for (i=0;i<keys[line];i++){
	printf("　　‖第%d个按键与零点之差:",i+1);
	scanf("%d",&w[line][i]);
	w[line][i]+=zero[line];
	}
if (set_chooses[8]==8){
	printf("　　‖【显示】此行零点:");
	scanf("%d",&zerov[line]);
	for (i=0;i<keys[line];i++){
		printf("　　‖【显示】第%d个按键与零点之差:",i+1);
		scanf("%d",&wv[line][i]);
		wv[line][i]+=zerov[line];
		}
	}
break;
}
case 4:{
/*逐个输入法开始*/
keys[line]=0;
for (i=0;;i++){
	printf("　　‖第%d个按键宽度:",i+1);
	scanf("%d",&w[line][i]);
	if (w[line][i]==0){
		break;
		}
	else{
		keys[line]=i+1;
		}
	}
if (set_chooses[8]==8){
for (i=0;i<keys[line];i++){
	printf("　　‖【显示】第%d个显示宽度:",i+1);
	scanf("%d",&wv[line][i]);
		keys[line]=i+1;
	}
}
break;
}//case
}//switch
}//for
/*第三部分:输出结果*/
fp=fopen("/mnt/sdcard/Baidutool/#皮肤模板.ini","w");
for(line=0;line<lines;line++){
	for(i=0;i<keys[line];i++){
		if (key==1) {
			fprintf(fp,"[INPUT]\n\n[CAND]\n\n[PANEL]\n\n[MORE]\n\n[HINT]\n\n[LIST]\n");
			}
		fprintf(fp,"\n[KEY%d]\n",key);
		if (set_chooses[8]==8){
			fprintf(fp,"VIEW_RECT=%d,%d,%d,%d\n",xv[line],yv,wv[line][i],hv[line]);
			fprintf(fp,"TOUCH_RECT=%d,%d,%d,%d\n",x[line],y,w[line][i],h[line]);
		}
		else {
			fprintf(fp,"VIEW_RECT=%d,%d,%d,%d\n",x[line],y,w[line][i],h[line]);
		}
		fprintf(fp,"BACK_STYLE=%d\n",back);
		fprintf(fp,"FORE_STYLE=\n");
		if (set_chooses[1]==1){
			fprintf(fp,"UP=\n");
		}
		if (set_chooses[2]==2){
			fprintf(fp,"DOWN=\n");
		}
		if (set_chooses[3]==3){
			fprintf(fp,"LEFT=\n");
		}
		if (set_chooses[4]==4){
			fprintf(fp,"RIGHT=\n");
		}
		fprintf(fp,"CENTER=\n");
		if (set_chooses[5]==5){
			fprintf(fp,"SHOW=\n");
		}
		if (set_chooses[6]==6){
			fprintf(fp,"HOLD=\n");
		}
		if (set_chooses[7]==7){
			fprintf(fp,"HOLDSYM=\n");
		}
		if (set_chooses[8]==8){
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
}//end

int coordinate_calculator(int main_choose)
{
int wm,wn,gap=0,keys,more;
for (i=0;;i++){
	printf("　　　　　-平均值诂测-\n");
	printf("整体‖长/高:");
	scanf("%d",&wm);
	if (wm==0){
		break;
		}
	if (main_choose==71){
		printf("按键‖间隔:");
		scanf("%d",&gap);
		}
	printf("　　‖总数:");
	scanf("%d",&keys);
	wn=(wm-gap*(keys-1))/keys;
	printf("结果‖标准值为:%d\n",wn);
	wn=gap*(keys-1)+wn*keys;
	more=wm-wn;
	printf("　　‖需要闰%d个像素\n\n",more);
	}
clrscr();
main();
return 0;
}//end

int fontcss_set()
{
int style,size,border;
char color_nm,color_hl,color_border;
printf("　　　　-4.1+字体前景生成-\n");
printf("整体‖起始样式:");
	scanf("%d",&style);
printf("字体‖大小:");
	scanf("%d",&size);
printf("　　‖正常颜色:#");
	scanf("%s",color_nm);
printf("　　‖按下颜色:#(0为相同)");
	scanf("%s",color_hl);
printf("阴影‖大小:");
	scanf("%d",&border);
printf("　　‖颜色:");
	scanf("%s",color_border);
printf("生成‖1>输入并精确生成(&为end)\n方式‖2>安全模式\n　　‖3>快速生成空模板\n　　‖4>快速占位\n　　‖5>快速数字占位\n　　‖6>英文小写\n　　‖7>英文大写\n　　‖8>数字1~0\n　　‖9>预设符号\n　　‖选择：");
}


int help()
{
clrscr();
printf("　　　　　　　-帮助-\n");
printf("特性‖组件形式:多种搭配\n　　‖简单选择:回车再回车\n　　‖视图优化:层级明显\n　　‖强大功能:灵活多变\n");
printf("提示‖组件多选直接输数字无需分隔符\n　　‖ST中<>&未来将自动转义\n");
printf("信息‖百度贴吧@齿轮key 部分参考BSTool\n　　‖bug/反馈:tieba.baidu→齿轮key吧");
}