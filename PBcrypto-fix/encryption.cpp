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
			if (c + n % 26 <= 'z') { //�����ܺ󲻳���Сд��ĸ��Χ
				g_arrpasswd[i] = (char)(c + n % 26); //���ܺ���
			}
			else { //���ܺ󳬳�Сд��ĸ��Χ,��ͷ��ʼѭ��Сд��ĸ
				g_arrpasswd[i] = (char)(c + n % 26 - 26);
			}
		}
		else if (c >= 'A' && c <= 'Z') { //cΪ��д��ĸ
			if (c + n % 26 <= 'Z') { //���ܺ󲻳�����д��ĸ��Χ
				g_arrpasswd[i] = (char)(c + n % 26);
			}
			else { //���ܺ󳬳���д��ĸ��Χ,��ͷ��ʼѭ����д��ĸ
				g_arrpasswd[i] = (char)(c + n % 26 - 26);
			}
		}
		else { //������ĸ��������
			g_arrpasswd[i] = c;
		}
	}
	printf("\nAfter encode: \n");
	puts(g_arrpasswd); //������ܺ���ַ���
}
//decode()ʵ�ֽ��ܹ��ܣ�����ĸ˳��ǰ��nλ
void decode(char g_arrpasswd[], int n) {
	char c;
	int i;
	//�����ַ���
	for (i = 0; i < g_arrpasswdlen(g_arrpasswd); ++i) {
		c = g_arrpasswd[i];
		//cΪСд��ĸ
		if (c >= 'a' && c <= 'z') {
			//���ܺ�ΪСд��ĸ��ֱ�ӽ���
			if (c - n % 26 >= 'a') {
				g_arrpasswd[i] = (char)(c - n % 26);
			}
			else {
				//���ܺ�ΪСд��ĸ�ˣ�ͨ��ѭ��Сд��ĸ����ΪСд��ĸ
				g_arrpasswd[i] = (char)(c - n % 26 + 26);
			}
		}
		else if (c >= 'A' && c <= 'Z') { //cΪ��д��ĸ
			if (c - n % 26 >= 'A') { //���ܺ�Ϊ��д��ĸ
				g_arrpasswd[i] = (char)(c - n % 26);
			}
			else { //���ܺ�Ϊ��д��ĸ��,ѭ����д��ĸ,����Ϊ��д��ĸ
				g_arrpasswd[i] = (char)(c - n % 26 + 26);
			}
		}
		else { //����ĸ������
			g_arrpasswd[i] = c;
		}
	}
	printf("\nAfter decode: \n");
	puts(g_arrpasswd); //������ܺ���ַ���
}//�ú������������࣬���߿ɸĽ�
int main()
{
	char g_arrpasswd[50];
	int k = 0, n = 0, i = 1;
	printf("\nPlease input g_arrpasswdings: ");
	scanf("%s", g_arrpasswd); //������ܽ����ַ���
	//��ӡ�˵�
	printf("-----------------\n");
	printf("1: Encryption\n");
	printf("2: Decryption\n");
	printf("3: Violent Crack\n"); //�����ƽ�
	printf("-----------------\n");
	printf("\nPlease choose: ");
	scanf("%d", &k);
	if (k == 1) { //����
		printf("\nPlease input number: ");
		scanf("%d", &n);
		encode(g_arrpasswd, n);
	}
	else if (k == 2) { //����
		printf("\nPlease input number: ");
		scanf("%d", &n);
		decode(g_arrpasswd, n);
	}
	else {
		for (i = 1; i <= 25; ++i) { //�������п��ܵ�nֵ���б����ƽ�
			printf("%d ", i);
			decode(g_arrpasswd, i);
		}
	}
	return 0;
}