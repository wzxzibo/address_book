#include <iostream>
#include <string>
using namespace std;
#define MAX 1000

void showMenu()
{
	cout << "***************************" << endl;
	cout << "****** 1、添加联系人 ******" << endl;
	cout << "****** 2、显示联系人 ******" << endl;
	cout << "****** 3、删除联系人 ******" << endl;
	cout << "****** 4、查找联系人 ******" << endl;
	cout << "****** 5、修改联系人 ******" << endl;
	cout << "****** 6、清空联系人 ******" << endl;
	cout << "****** 0、退出通讯录 ******" << endl;
	cout << "***************************" << endl;
}

struct Person
{
	string m_Name;
	int m_Sex;
	int m_Age;
	string m_Phone;
	string m_Addr;
};
struct Addressbooks
{
	struct Person personArray[MAX];
	int m_Size;
};

void addPerson(Addressbooks* abs)
{
	if (abs->m_Size == MAX)
	{
		cout << "通讯录已经满了,无法添加" << endl;
		return;
	}
	else
	{
		//添加姓名
		string name;
		cout << "请输入添加的姓名：" << endl;
		cin >> name;
		abs->personArray[abs->m_Size].m_Name = name;
		//添加性别
		cout << "请输入添加的性别：" << endl;
		cout << "1 ---- 男" << endl;
		cout << "2 ---- 女" << endl;
		int sex = 0;
		
		//防止输入是错误值
		while (true)
		{
			cin >> sex;
			if (sex == 1 || sex == 2)
			{
				abs->personArray[abs->m_Size].m_Sex = sex;
				break;
			}
			else
			{
				cout << "输入错误，请重新输入" << endl;
			}
		}

		//添加年龄
		int age = 0;
		cout << "请输入年龄：" << endl;
		cin >> age;
		abs->personArray[abs->m_Size].m_Age = age;
		//添加电话号码
		cout << "请输入联系电话：" << endl;
		string tel;
		cin >> tel;
		abs->personArray[abs->m_Size].m_Phone = tel;
		//添加住址
		cout << "请输入住址：" << endl;
		string address;
		cin >> address ;
		abs->personArray[abs->m_Size].m_Addr = address;
		//更新通讯录人数
		abs->m_Size++;
		cout << "添加成功" << endl;
		//清屏
		system("pause");
		system("cls");

	}
}
void showPerson(Addressbooks abs)
{
	if (abs.m_Size == 0)
	{
		cout << "通讯录为空" << endl;
		system("pause");
		system("cls");
		return;
	}
	for (int i = 0; i < abs.m_Size; i++)
	{
		cout << "姓名：" << abs.personArray[i].m_Name << "\t";
		cout << "性别：" <<(abs.personArray[i].m_Sex ==1?"男":"女" )<<"\t" ;
		cout << "电话：" << abs.personArray[i].m_Phone << "\t";
		cout << "年龄：" << abs.personArray[i].m_Age << "\t";
		cout << "住址：" << abs.personArray[i].m_Addr << endl;
	}
	system("pause");
	system("cls");

}

int isExist(Addressbooks* abs, string name)
{
	for (int i = 0; i < abs->m_Size; i++)
	{
		if (abs->personArray[i].m_Name == name)
		{
			return i;
		}
	}
	return -1;
}
	
void delPerson(Addressbooks * abs)
{
	if (abs->m_Size == 0)
	{
		cout << "通讯录为空，无法删除" << endl;
		return;
	}
	string name;
	cout << "请输入要删除联系人的名字：" << endl;
	cin >> name;
	int ret = isExist(abs, name);
	if (ret!= -1 )
	{
		for (int i = ret; i < abs->m_Size; i++)
		{
			abs->personArray[i] = abs->personArray[i + 1];
		}
		abs->m_Size--;
		cout << "删除成功" << endl;

	}
	else
	{
		cout << "查无此人" << endl;
	}
	system("pause");
	system("cls");
}
void findPerson(Addressbooks * abs)
{
	string name;
	cout << "请输入要查找的联系人姓名：" << endl;
	cin >> name;
	int ret = isExist(abs, name);
	if (ret >=0)
	{
		cout << "姓名：" << abs->personArray[ret].m_Name << "\t";
		cout << "性别：" << abs->personArray[ret].m_Sex << "\t";
		cout << "年龄：" << abs->personArray[ret].m_Age << "\t";
		cout << "电话：" << abs->personArray[ret].m_Phone << "\t";
		cout << "地址：" << abs->personArray[ret].m_Addr << endl;
	}
	else {
		cout << "查无此人" << endl;
	}
	system("pause");
	system("cls");
}
void modifyPerson(Addressbooks * abs)
{
	cout << "选择要修改的联系人" << endl;
	string name;
	cin >> name;
	int ret = isExist(abs, name);
	if (ret != -1)
	{
		//姓名
		cout << "请输入姓名：" << endl;
		cin >> name;
		abs->personArray[ret].m_Name = name;
		//性别
		cout << "请输入性别：" << endl;
		cout << "1 --- 男" << endl;
		cout << "2 --- 女" << endl;
		int sex = 0;
		while (1)
		{
			cin >> sex;
			if (sex == 1 || sex == 2)
			{
				abs->personArray[ret].m_Age = sex;
				break;
			}
			else {
				cout << "性别输入有误，请重新输入" << endl;
			}
		}
		//年龄
		cout << "请输入年龄：" << endl;
		int age;
		cin >> age;
		abs->personArray[ret].m_Age = age;
		//电话
		cout << "请输入电话号码：" << endl;
		string phone;
		cin >> phone;
		abs->personArray[ret].m_Phone = phone;
		//家庭住址
		cout << "请输入住址：" << endl;
		string address;
		cin >> address;
		abs->personArray[ret].m_Addr = address;
		cout << "修改成功" << endl;

	}
	else
	{
		cout << "查无此人" << endl;
	}
	//清屏操作
	system("pause");
	system("cls");
}
void cleanPerson(Addressbooks* abs)
{
	abs->m_Size = 0;
	cout << "清空成功" << endl;
	system("pause");
	system("cls");
}

int main()
{
	Addressbooks abs;
	abs.m_Size = 0;
	int select = 0;
	while (true)
	{
		showMenu();
		cin >> select;

		switch (select)
		{
		case 1://1、添加联系人
			addPerson(&abs);
			break;
		case 2://2、显示联系人
			showPerson(abs);//这里故意没用指针，看看差别
			break;
		case 3://3、删除联系人
			delPerson(&abs);
			break;
		case 4://4、查找联系人
			findPerson(&abs);
			break;
		case 5://5、修改联系人
			modifyPerson(&abs);
			break;
		case 6://6、清空联系人
			cleanPerson(&abs);
			break;
		case 0://0、退出通讯录
			cout << "欢迎下次使用" << endl;
			system("pause");
			return 0;
			break;
		}

	}
	system("pause");
	return 0;
}