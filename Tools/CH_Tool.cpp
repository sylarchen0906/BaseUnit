#include "CH_Tool.h"

CH_Tool::CH_Tool()
{

}

CH_Tool::~CH_Tool()
{

}

bool CH_Tool::fetch_head(string &source, string &dest, char flag)
{
	int pos = source.find_first_of(flag);
	if (pos != string::npos)
	{
		dest = source.substr(0, pos);
		source = source.substr(pos + 1, source.length());
		return true;
	}
	return false;
}


bool CH_Tool::fetch_head(string &source, string &dest, const string &flag)
{
	int pos = source.find_first_of(flag);
	if (pos != string::npos)
	{
		dest = source.substr(0, pos);
		source = source.substr(pos + flag.length(), source.length());
		return true;
	}
	return false;
}


unsigned int CH_Tool::ipv4_to_uint(const string &ip)
{
	int part1 = 0, part2 = 0, part3 = 0, part4 = 0;
	int ret = sscanf_s(ip.c_str(), "%d.%d.%d.%d", &part1, &part2, &part3, &part4);
	if (ret == 4)
	{
		return part1 << 24 | part2 << 16 | part3 << 8 | part4;
	}
	else
	{
		return 0;
	}
}

string CH_Tool::uint_to_ipv4(unsigned int ip)
{
	int part1 = 0, part2 = 0, part3 = 0, part4 = 0;
	char str[IP_MAX] = { 0 };
	part1 = ip >> 24;
	part2 = ip >> 16 & 0xFF;
	part3 = ip >> 8 & 0xFF;
	part4 = ip & 0xFF;
	sprintf_s(str, "%d.%d.%d.%d", part1, part2, part3, part4);
	return str;
}

string CH_Tool::int32_to_str(int num)
{
	char str[33] = { 0 };
	sprintf_s(str, "%d", num);
	return str;
}

string CH_Tool::int64_to_str(long long num)
{
	char str[65] = { 0 };
	sprintf_s(str, "%I64d", num);
	return str;
}

bool CH_Tool::str_to_int32(const string &str, int &num)
{
	int num_ret = 0, ret = 0;
	ret = sscanf_s(str.c_str(), "%d", &num_ret);
	if (ret == 1)
	{
		num = num_ret;
		return true;
	}
	return false;
}

bool CH_Tool::str_to_int64(const string &str, long long &num)
{
	long long num_ret = 0;
	int ret = 0;
	ret = sscanf_s(str.c_str(), "%I64d", &num_ret);
	if (ret == 1)
	{
		num = num_ret;
		return true;
	}
	return false;
}