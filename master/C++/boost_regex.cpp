#include<boost/regex.hpp>
#include<locale>
#include<iostream>
#include<string>

int main()
{
	
	std::string s("hello world");
	{
		//std::locale::global(std::locale("english"));//设置说明本地化(使用英语)
		boost::regex expr("\\w+\\s\\w+");// \\w+代表匹配任意字符，\\s代表匹配空格
		std::cout<<boost::regex_match(s,expr)<<std::endl;//判断是否匹配
	}
	{
		boost::regex expr("(\\w+)(\\s)(\\w+)");//()分组子串
		boost::smatch what;
		if(boost::regex_search(s,what,expr))//搜索匹配规则的字符串,搜索结果放在what里
		{
			std::cout<<what[0]<<std::endl;//完全匹配的结果
			std::cout<<what[1]<<std::endl;//第一个子串
			std::cout<<"_"<<what[2]<<"_"<<std::endl;//第二个字串匹配了空格
			std::cout<<what[3]<<std::endl;//第三个子串
			std::cout<<what[4]<<std::endl;//搜索不到了，为空
		}
	}
	{
		//boost::regex expr("\\s");
		//std::string fmt("_");
		boost::regex expr("(\\w+)\\s(\\w+)");
		std::string fmt("\\2\\1");//格式参数\\1和\\2用于访问子串,此处第二个字串在前，第一个字串在后，意味这调换位置
		std::cout<<boost::regex_replace(s,expr,fmt)<<std::endl;//按照正则表达式制定的匹配内容进行替换
		std::cout<<boost::regex_replace(s,expr,fmt,boost::regex_constants::format_literal);	//第四个入参抑制了格式入参中的特殊字符处理，也即\\2和\\1失去了指代字串的作用，当成普通字符串来处理
		
		//std::cout<<s<<std::endl;//不会修改原数据
	}	
	return 0;
}
