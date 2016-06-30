#ifndef __CH_TOOLS_H__
#define __CH_TOOLS_H__

/************************************************************************/
/* @file descript: 提供常用的功能                                        */
/* @author: Sylar.Chen  2016-05-25                                      */
/************************************************************************/

#include <stdio.h>
#include <string>

#define IP_MAX              17               ///< 定义IP的长度

using std::string;

class CH_Tool
{
		CH_Tool();                           ///< 静态类，所以不需要构造函数，设置为private

		~CH_Tool();
	public:
		/**
		 * @brief 根据标记截取string字符串中的第一部分
		 * @param source:源字符串
		 * @param dest: 得到的第一部分
		 * @param flag: 截取标记
		 * @return 截取头部是否成功
		 * @li true: 截取头部成功
		 * @li false: 截取头部失败, 没有找到查找标记
		 */
		static bool fetch_head(string &source, string &dest, char flag);

		/**
		 * @brief 根据标记截取string字符串中的第一部分
		 * @param source:源字符串
		 * @param dest: 得到的第一部分
		 * @param flag: 截取标记
		 * @return 截取头部是否成功
		 * @li true: 截取头部成功
		 * @li false: 截取头部失败， 没有找到查找标记
		 */
		static bool fetch_head(string &source, string &dest, const string &flag);

		/**
		 * @brief 将string格式的IP转换为uint格式的IP
		 * @param ip: 字符串IP
		 * @return 数字类型的IP，如果IP不符合规则，则返回0
		 */
		static unsigned int ipv4_to_uint(const string &ip);

		/**
		 * @brief 将32位IP转换为点分十进制IP
		 * @param ip: 32位IP
		 * @return 点分十进制IP，因此字符串是固定的，数据量不大固直接返回string
		 */
		static string uint_to_ipv4(unsigned int ip);

		/**
		 * @brief 将32位int数据转换为字符串格式
		 * @param num: 32位int数据
		 * @return 转换后的字符串
		 */
		static string int32_to_str(int num);

		/**
		 * @brief 将64位int数据转换为字符串格式
		 * @param num: 64位int数据
		 * @return 转换后的字符串
		 */
		static string int64_to_str(long long num);

		/**
		 * @brief 将字符串转换为32位的字符串
		 * @param str: 32位字符串数据
		 * @param num: 转换后的32位int数据
		 * @return 转换结果
		 * @li true: 转换成功
		 * @li false: 转换失败
		 */
		static bool str_to_int32(const string &str, int &num);

		/**
		 * @brief 将字符串转换为64位的字符串
		 * @param str: 64位字符串数据
		 * @param num: 转换后的64位int数据
		 * @return 转换结果
		 * @li true: 转换成功
		 * @li false: 转换失败
		 */
		static bool str_to_int64(const string &str, long long &num);

};

#endif