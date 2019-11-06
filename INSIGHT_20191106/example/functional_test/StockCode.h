#ifndef STOCKCODE_H
#define STOCKCODE_H
#include <fstream>
#include <string>
#include <iostream>
#include <sstream>
#include <vector>

using namespace std;


class StockCode
{
private:
	vector <vector <string>> fieldss;           //存放代码表
	string Csvname;                            //代码表文件名称
public:
	StockCode(const string &Csv):Csvname(Csv){};
	virtual ~StockCode(){};
public:
	// 删除字符串中空格，制表符tab等无效信息
	string Trim(string &str)
	{
		str.erase(0,str.find_first_not_of(" \t\r\n"));
		str.erase(str.find_last_not_of(" \t\r\n") + 1);
		return str;
	}

	vector <vector <string>> getfieldss()
	{
		ifstream fin(Csvname);
		string	line;
		if(fin)	// 有该文件  
			{
				while(getline(fin,line))	// line中不包括每行的换行符  
				{
					//cout<<line;
					istringstream sin(line); //将整行字符串line读入到字符串流istringstream中
					vector <string> fields;
					string field;
					while (getline(sin, field, ',')) //将字符串流sin中的字符读入到field字符串中，以逗号为分隔符
					{
					//	cout << field << endl;
						fields.push_back(field);     //将刚刚读取的字符串添加到向量fields中
					}
					fieldss.push_back(fields);
			/*		string code = Trim(fields[0]);      //清除掉向量fields中第一个元素的无效字符，并赋值给变量code
					string stock = Trim(fields[1]);     //清除掉向量fields中第二个元素的无效字符，并赋值给变量name
					cout << code << "\t" << stock << endl;*/
				}
			/*	string code = Trim(fieldss[5][0]);
				string stock = Trim(fieldss[5][1]);
				cout << code << "\t" << stock << endl;
				cout << fieldss.size() << endl;*/
			}
			else // 没有该文件  
			{
				error_print("no StockCode table file");
			}
		fin.close();
		return fieldss;
	}

};
#endif
