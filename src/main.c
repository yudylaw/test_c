#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 计算数组长度的宏
#define ARRAY_LEN(array,len) {len = (sizeof(array) / sizeof(array[0]));}

//括号不可少
#define MAX(a, b) ((a) > (b) ? (a) : (b))

//外部函数与变量
//不推荐这样的用法
extern void hello();
extern count;

struct Person {
	int age;
	char *name;
};

//公式1:前面的地址必须是后面的地址正数倍,不是就补齐
//公式2:整个Struct的地址必须是最大字节的整数倍
struct Padding {
	char b;//1byte, 地址1
	char c;//1byte，地址2 + 2 padding
	int a;//4byte，地址8
};

struct Margin {
	short c;//1+7
	long a;//8
	char *d;//8
};

u_char *
my_strlchr(u_char *p, u_char *last, u_char c)
{
    while (p < last) {

        if (*p == c) {
            return p;
        }

        p++;
    }

    return NULL;
}

void test(char* out) {
	char* str = (char*) malloc(3);

	str[0] = 'a';
	str[1] = 'b';
	str[2] = '\0';

	int i;

	for (i=0;i < strlen(str);i++) {
		out[i] = str[i];
		printf("%c", str[i]);
		int i = 10/0;
	}

	out[i] = '\0';

	printf("\n");


	free(str);
}

int sum() {
	static int sum = 0;//该静态变量只在函数内有效
	sum++;
	return sum;
}

int main() {

	sum();
	sum();
	int d = sum();

	printf("sum=%d\n", d);

	hello();

	printf("count=%d\n", count);

	int a = 20;
	int b = 20;

	int max = MAX(a+5, b - 5);

	printf("max=%d\n", max);

	struct Person person = {30, "Yudy"};

	printf("%s\n", person.name);

	struct Padding pad = {10, 'c', 'b'};

	struct Margin margin = {'a', 10};

	printf("size of Padding=%d\n", sizeof(pad));
	printf("size of Margin=%d\n", sizeof(margin));

	return 0;
}

int main3() {

//	unsigned int n = 10;
//	unsigned int m = 20;
//	unsigned int result = n - m;
//
//	unsigned int zero = 0;

//	if (result > zero) {
//		printf("result=%d\n", result);
//		printf("result=%u\n", result);
//	}
//
//	printf("result=%d\n", result);

    unsigned char a = -1;//负数补码 1111 1111=255，反码+1
    char b = a;// 1111 1111 = -1
    //%d 是 int 类型
    printf("%d, %d\n", a, b); // char->int 符号位自动扩充

    int num = 10;
    short s = 23;
    long lg = 1000L;
    double d = 100.123;
    float f = 100.333F;

    printf("sizeof int=%d\n", sizeof(num));//4
    printf("sizeof char=%d\n", sizeof(b));//1
    printf("sizeof short=%d\n", sizeof(s));//2
    printf("sizeof long=%d\n", sizeof(lg));//8
    printf("sizeof double=%d\n", sizeof(d));//8
    printf("sizeof float=%d\n", sizeof(f));//4

	return 0;
}

int main2(int argc, char *args[])
{

	//命令行参数
	printf("argc=%d\n", argc);

	int m;

	for (m=0; m < argc; m++) {
		printf("%d arg=%s\n", m, args[m]);
	}

	//指针数组
	char *name[] = {
	"Illegal month",
	"January", "February", "March",
	"April", "May", "June",
	"July", "August", "September",
	"October", "November", "December"
	};

	printf("%s\n", name[1]);//字符串指针

	printf("%c\n", *name[1]);//首字符

	int len = 0;

	ARRAY_LEN(name, len);

	int j;

	printf("ARRAY_LEN name:%d\n", len);

	for (j=0;j < len;j++) {
		printf("%s\n", name[j]);
	}

	printf("\n");

	char str1[] = "abcd";// 数组指针不可变
	char str2[] = "1234";

	char* str3 = "efef";//字符串长量

//	str2 = str1; //Error 数组指针不可变，指向固定区域
//	str3 = str1;

	printf("%x, sizeof str3:%d\n", str3, sizeof(str3));

	str3 = "GGKK";//指向新字符串

	//sizeof 指针, 32位平台，指针占4byte, 64位平台，占8byte
	printf("%x, sizeof str3:%d\n", str3, sizeof(str3));

//	test(str1);

	int i = 0;

	for (i=0;i < strlen(str3);i++) {
		printf("%c", str3[i]);
	}

	printf("\n");

	for (i=0;i < strlen(str2);i++) {
		printf("%c", str2[i]);
	}

	printf("\n");

	return 0;
}


