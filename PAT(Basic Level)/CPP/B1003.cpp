/*
1003. 我要通过！(20)
时间限制 400 ms
内存限制 65536 kB
代码长度限制 8000 B

“答案正确”是自动判题系统给出的最令人欢喜的回复。本题属于PAT的“答案正确”大派送 —— 只
要读入的字符串满足下列条件，系统就输出“答案正确”，否则输出“答案错误”。得到“答案正确”
的条件是：
1. 字符串中必须仅有P, A, T这三种字符，不可以包含其它字符；
2. 任意形如 xPATx 的字符串都可以获得“答案正确”，其中 x 或者是空字符串，或者是仅由字
母 A 组成的字符串；
3. 如果 aPbTc 是正确的，那么 aPbATca 也是正确的，其中 a, b, c 均或者是空字符串，或
者是仅由字母 A 组成的字符串。
现在就请你为PAT写一个自动裁判程序，判定哪些字符串是可以获得“答案正确”的。

输入格式： 
每个测试输入包含1个测试用例。第1行给出一个自然数n (<10)，是需要检测的字符串个数。接下来
每个字符串占一行，字符串长度不超过100，且不包含空格。

输出格式：
每个字符串的检测结果占一行，如果该字符串可以获得“答案正确”，则输出YES，否则输出NO。

输入样例：
8
PAT
PAAT
AAPATAA
AAPAATAAAA
xPATx
PT
Whatever
APAAATAA

输出样例：
YES
YES
YES
YES
NO
NO
NO
NO
*/

// 结论:
// 只能出现P(只能出现一次),A,T(只能出现一次)三个字母,且必须都出现;不能出现其他字符
// P之前的A的个数 * PT之间的A的个数 = T之后的A的个数
// 推导：
// 1: PAT			0 = 0
// 2: xPATx			x = x
// 3: 如果 aPbTc 要正确,根据1,2可得b只能为'A',即aPATc;再由2可得 a = c;
//	  那么 aPbATca 即 aPAATac; 又 a=c => aPAATaa

#include <cstdio>
#include <cstring>

int main(){
	char str[101],tmp;
	int n;
	scanf("%d%c",&n,&tmp);
	while(n--){
		int p1 = 0,t1 = 0,a1 = 0,p2,t2,strl;//p1:P的个数; t1:T的个数; a1:A的个数; p2:P所在的位置; t2:T所在的位置
		gets(str);
		strl = strlen(str);
		for(int i = 0; i < strl; i++){
			if(str[i] == 'P'){
				p1 ++;
				p2 = i;
			}else if(str[i] == 'T'){
				t1 ++;
				t2 = i;
			}else if(str[i] == 'A'){
				a1 ++;
			}
		}
		if(p1 != 1 || t1 != 1 || p1+t1+a1 < strl || t2 <= p2 + 1){ // P不只出现1次(0次) || T不只出现1次(0次)|| 有其他字符 || (P出现在T之前,PT相邻的情况)
			printf("NO\n");
		}else{
			if(p2*(t2-p2-1) == strl-t2-1){	//P所在的位置index即P之前A的个数
				printf("YES\n");
			}else{
				printf("NO\n");
			}
		}
	}
	return 0;
}
