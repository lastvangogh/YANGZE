#ifndef TRADE_DAY_H
#define TRADE_DAY_H
#include <fstream>
#include <string>
#include <iostream>
#include <vector>

using namespace std;


class Trade_day
{
private:
	vector <string> fields;           //存放代码表
	string Csvname;                            //代码表文件名称
public:
	Trade_day(const string &Csv):Csvname(Csv){};
	virtual ~Trade_day(){};
public:
	// 删除字符串中空格，制表符tab等无效信息
	string Trim(string &str)
	{
		str.erase(0,str.find_first_not_of(" \t\r\n"));
		str.erase(str.find_last_not_of(" \t\r\n") + 1);
		return str;
	}

	vector <string> getfields()
	{
		ifstream fin(Csvname);
		string	line;
		if(fin)	// 有该文件  
			{
				while(getline(fin,line))	// line中不包括每行的换行符  
				{
					fields.push_back(line);
				}
			}
			else // 没有该文件  
			{
				error_print("no trade day file");
			}
		fin.close();
		return fields;
	}

};
#endif
