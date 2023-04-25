#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;
#include<ctime>
#include<string>
struct student
{

	string sname;
	int score;


};
struct teacher
{
	string tname;

	struct student s[5];//赋值一个学生数组


};

void allteacher(struct teacher ss[], int len)
{//给老师赋值
	string nameseed = "ABCDE";
	for (int i = 0; i < len; i++)
	{
		ss[i].tname = "teacher_";
		ss[i].tname += nameseed[i];

		//通过循环给每名老师带的学生赋值
		for (int j = 0; j < 5; j++)
		{
			ss[i].s[j].sname = "student_";
			ss[i].s[j].sname += nameseed[j];
			int random = rand() % 61 + 40;//40-100

			ss[i].s[j].score = random;
		}
	}

}

//打印所有信息的函数
void ppp(struct teacher ss[], int len)
{
	for (int i = 0; i < len; i++)
	{

		cout << "老师的姓名" << ss[i].tname << endl;
		for (int j = 0; j < 5; j++)
		{
			cout << "学生的姓名" << ss[i].s[j].sname << "学生的成绩" << ss[i].s[j].score << endl;
		}

	}

}




int main()
{

	srand((unsigned int)time(NULL));

	//创建三名老师的数组    通过函数给三名老师赋值并给所带的学生赋值
	struct teacher ss[3];
	int len = sizeof(ss) / sizeof(ss[0]);
	allteacher(ss, len);
	ppp(ss, len);
	system("pause");
	return 0;
}