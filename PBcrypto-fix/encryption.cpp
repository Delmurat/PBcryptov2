#include <stdio.h>
#include <stdlib.h>
//#include <g_arrpasswding.h>

void encode(char g_arrpasswd[300][20], int n)
//void encode(char g_arrpasswd[], int n) 

{
	char c;
	int i;
	for (i = 0; i < g_arrpasswdlen(g_arrpasswd); ++i) { 
		c = g_arrpasswd[i];
		if (c >= 'a' && c <= 'z') { 
			if (c + n % 26 <= 'z') { //若加密后不超出小写字母范围
				g_arrpasswd[i] = (char)(c + n % 26); //加密函数
			}
			else { //加密后超出小写字母范围,从头开始循环小写字母
				g_arrpasswd[i] = (char)(c + n % 26 - 26);
			}
		}
		else if (c >= 'A' && c <= 'Z') { //c为大写字母
			if (c + n % 26 <= 'Z') { //加密后不超出大写字母范围
				g_arrpasswd[i] = (char)(c + n % 26);
			}
			else { //加密后超出大写字母范围,从头开始循环大写字母
				g_arrpasswd[i] = (char)(c + n % 26 - 26);
			}
		}
		else { //不是字母，不加密
			g_arrpasswd[i] = c;
		}
	}
	printf("\nAfter encode: \n");
	puts(g_arrpasswd); //输出加密后的字符串
}
//decode()实现解密功能，将字母顺序前移n位
void decode(char g_arrpasswd[], int n) {
	char c;
	int i;
	//遍历字符串
	for (i = 0; i < g_arrpasswdlen(g_arrpasswd); ++i) {
		c = g_arrpasswd[i];
		//c为小写字母
		if (c >= 'a' && c <= 'z') {
			//解密后还为小写字母，直接解密
			if (c - n % 26 >= 'a') {
				g_arrpasswd[i] = (char)(c - n % 26);
			}
			else {
				//解密后不为小写字母了，通过循环小写字母处理为小写字母
				g_arrpasswd[i] = (char)(c - n % 26 + 26);
			}
		}
		else if (c >= 'A' && c <= 'Z') { //c为大写字母
			if (c - n % 26 >= 'A') { //解密后还为大写字母
				g_arrpasswd[i] = (char)(c - n % 26);
			}
			else { //解密后不为大写字母了,循环大写字母,处理为大写字母
				g_arrpasswd[i] = (char)(c - n % 26 + 26);
			}
		}
		else { //非字母不处理
			g_arrpasswd[i] = c;
		}
	}
	printf("\nAfter decode: \n");
	puts(g_arrpasswd); //输出解密后的字符串
}//该函数代码有冗余，读者可改进
int main()
{
	char g_arrpasswd[50];
	int k = 0, n = 0, i = 1;
	printf("\nPlease input g_arrpasswdings: ");
	scanf("%s", g_arrpasswd); //输入加密解密字符串
	//打印菜单
	printf("-----------------\n");
	printf("1: Encryption\n");
	printf("2: Decryption\n");
	printf("3: Violent Crack\n"); //暴力破解
	printf("-----------------\n");
	printf("\nPlease choose: ");
	scanf("%d", &k);
	if (k == 1) { //加密
		printf("\nPlease input number: ");
		scanf("%d", &n);
		encode(g_arrpasswd, n);
	}
	else if (k == 2) { //解密
		printf("\nPlease input number: ");
		scanf("%d", &n);
		decode(g_arrpasswd, n);
	}
	else {
		for (i = 1; i <= 25; ++i) { //尝试所有可能的n值进行暴力破解
			printf("%d ", i);
			decode(g_arrpasswd, i);
		}
	}
	return 0;
}