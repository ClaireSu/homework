#include<stdio.h>
#include<string.h>
int changeToTen (char num_zt[100]);//0-10中文转化为数字 
int changeAboutTen (char num_ten[100]);//十几与整十转化为数字 
int changeOthers(char num_oth[100]);//其他两位数转化为数字 
int Calculate(char ope[100],int num,int cha_num);//加减乘除的计算 
char printToTen(int single_D);//0-10输出 
char printTwoDigits(int two_D);//两位数中的十位输出 
char printUnitsDigits (int units_D);//两位数中的个位输出 
int main()
{
	int num,cha_num;
	char str1[100],count[100],change_num[100],pre_num[100];
	scanf("%s %s %s %s",str1,count,change_num,pre_num);
	num=changeToTen(pre_num);//钱包中最初拥有的钱数 
	for(;;){
	    scanf("%s",str1);
		if(strcmp(str1,"看看")==0){
			scanf("%s",count);//如果出现看看，则进行最后一次输入后结束输入 
			break;
		 } 
		else{
			scanf("%s %s",count,change_num);//输入“增加，减少”，以及相应的钱数 
			if(strlen(change_num)==2)cha_num=changeToTen(change_num);//如果是一个汉字，即0-10 
		    if(strlen(change_num)==4)cha_num=changeAboutTen(change_num);//如果是两个汉字，即11-19，以及整十 
		    if(strlen(change_num)==6)cha_num=changeOthers(change_num);//如果是三个汉字，即其他的两位数 
		    num=Calculate(count,num,cha_num); //计算结果 
		}
	}
	if(num<=10)printToTen(num);//输出0-10的转换 
	else printTwoDigits(num);//输出大于10的转换 
	return 0;
 } 
 int changeToTen (char num_zt[100])//处理零到十的输入的转化 
 {
 	
 	if(strcmp(num_zt,"零")==0)return 0;
	else if(strcmp(num_zt,"一")==0)return 1; 
	else if(strcmp(num_zt,"二")==0)return 2;
	else if(strcmp(num_zt,"三")==0)return 3;
	else if(strcmp(num_zt,"四")==0)return 4;  
	else if(strcmp(num_zt,"五")==0)return 5;
	else if(strcmp(num_zt,"六")==0)return 6;
	else if(strcmp(num_zt,"七")==0)return 7;
	else if(strcmp(num_zt,"八")==0)return 8;
	else if(strcmp(num_zt,"九")==0)return 9;
	else if(strcmp(num_zt,"十")==0)return 10;
 }
 int changeAboutTen (char num_ten[100])//处理整十和十几的输入 
 {
 	char second_num[100];
 	int num;
	strncpy(second_num,num_ten+2,2);//复制后两个字符，即第二个汉字  
	num_ten[2]='\0';//保留第一个汉字，去除第二个汉字 
	second_num[2]='\0';//切记要加\0！ 
	if(changeToTen(num_ten)==10)//判断第一个汉字是否是十 
	num=10+changeToTen(second_num);//如果是十几 
	else
	num=10*changeToTen(num_ten);//如果是整十 
	return num; 
 }
 int changeOthers (char num_oth[100])//处理其他两位数输入 
 {
 	char first_num[100],third_num[100];
 	int num;
 	strncpy(first_num,num_oth,2);//取第一个汉字，即十位数 
 	first_num[2]='\0';//切记要\0 !
 	strncpy(third_num,num_oth+4,2);//取第三个汉字，即个位数 
 	third_num[2]='\0';//切记要\0 !
	num=changeToTen(first_num)*10+changeToTen(third_num);
	return num; 
 }
 char printToTen(int single_D)//处理输出0-10 
 { 
 		if(single_D==0)printf("零");
	else if(single_D==1)printf("一");
	else if(single_D==2)printf("二");
	else if(single_D==3)printf("三");
	else if(single_D==4)printf("四");
	else if(single_D==5)printf("五");
	else if(single_D==6)printf("六");
	else if(single_D==7)printf("七");
	else if(single_D==8)printf("八");
	else if(single_D==9)printf("九");
	else if(single_D==10)printf("十");
}
char printTwoDigits(int two_D)//处理输出两位数 
{
		 int tens_digit,units_digit;
 		units_digit=two_D%10;//取出它的个位数 
 		two_D=two_D/10;
 		tens_digit=two_D;        //取出它的十位数 
 		 if(tens_digit==1)printf("一十");//对十位数处理 
	else if(tens_digit==2)printf("二十");
	else if(tens_digit==3)printf("三十");
	else if(tens_digit==4)printf("四十");  
	else if(tens_digit==5)printf("五十");
	else if(tens_digit==6)printf("六十");
	else if(tens_digit==7)printf("七十");
	else if(tens_digit==8)printf("八十");
	else if(tens_digit==9)printf("九十");
	else if(tens_digit==10)printf("一百"); 
	if(units_digit!=0)printf("%s",printUnitsDigits (units_digit));//如果不是整十，则另外输出个位数 

	 }	
char printUnitsDigits (int units_D)//处理输出两位数中的个位数 
{
	if(units_D==1)printf("一");
	else if(units_D==2)printf("二");
	else if(units_D==3)printf("三");
	else if(units_D==4)printf("四");  
	else if(units_D==5)printf("五");
	else if(units_D==6)printf("六");
	else if(units_D==7)printf("七");
	else if(units_D==8)printf("八");
	else if(units_D==9)printf("九");
}
	 
 int Calculate(char ope[100],int num,int cha_num)//处理加减乘除转化 
 {
 	if(strcmp(ope,"增加")==0)
    num=num+cha_num;
	if(strcmp(ope,"减少")==0)
	num=num-cha_num;
	if(strcmp(ope,"乘以")==0)
	num=num*cha_num;
	if(strcmp(ope,"除以")==0)
	num=num/cha_num;
	return num;
 }