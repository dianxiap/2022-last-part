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

	struct student s[5];//��ֵһ��ѧ������


};

void allteacher(struct teacher ss[], int len)
{//����ʦ��ֵ
	string nameseed = "ABCDE";
	for (int i = 0; i < len; i++)
	{
		ss[i].tname = "teacher_";
		ss[i].tname += nameseed[i];

		//ͨ��ѭ����ÿ����ʦ����ѧ����ֵ
		for (int j = 0; j < 5; j++)
		{
			ss[i].s[j].sname = "student_";
			ss[i].s[j].sname += nameseed[j];
			int random = rand() % 61 + 40;//40-100

			ss[i].s[j].score = random;
		}
	}

}

//��ӡ������Ϣ�ĺ���
void ppp(struct teacher ss[], int len)
{
	for (int i = 0; i < len; i++)
	{

		cout << "��ʦ������" << ss[i].tname << endl;
		for (int j = 0; j < 5; j++)
		{
			cout << "ѧ��������" << ss[i].s[j].sname << "ѧ���ĳɼ�" << ss[i].s[j].score << endl;
		}

	}

}




int main()
{

	srand((unsigned int)time(NULL));

	//����������ʦ������    ͨ��������������ʦ��ֵ����������ѧ����ֵ
	struct teacher ss[3];
	int len = sizeof(ss) / sizeof(ss[0]);
	allteacher(ss, len);
	ppp(ss, len);
	system("pause");
	return 0;
}