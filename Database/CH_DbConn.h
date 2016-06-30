#ifndef __CH_DBCONN_H__
#define __CH_DBCONN_H__
/************************************************************************/
/* Author: Sylar.Chen     2015-6-06-20                                  */
/* File Description: 数据库连接对象封装                                 */
/************************************************************************/

#include "CH_DbCommand.h"
#include "CH_DbDataSet.h"
#include <windows.h>
#include <string>
using std::string;

#import "C:\Program Files\Common Files\System\ado\msado15.dll" no_namespace rename("EOF","adoEOF")

class CH_DbCommand;

class CH_DbConn
{
	public:
		CH_DbConn();

		virtual ~CH_DbConn();

	public:
		/**
		 * @brief 检查连接是否打开
		 * @return 数据库是否已打开
		 */
		bool is_open();

		/**
		 * @brief 打开数据库连接
		 * @paran udl_file_name: UDL文件路径
		 * @return 是否连接成功
		 */
		bool open(const string &udl_file_name);

		/// 关闭数据库连接
		void close();

		/// 开始事务
		void begin_trans();

		/// 回滚事务
		void roll_back();

		/// 取消一次执行
		void cancle();

		/// 提交事务
		void commit_trans();

	public:
		/**
		 * @brief 执行不返回结果集的SQL
		 * @param sql: SQL语句
		 */
		void excute_no_result(const string &sql);

		/**
		 * @brief 执行SQL查询
		 * @param sql: SQL语句
		 * @return 结果记录集
		 */
		const CH_DbDataSet& excute_select(const string &sql);

		/**
		 * @brief 执行存储过程
		 * @param proc: 存储过程名称
		 */
		void excute_procedure(const string &proc);

		/// 清空存储过程的参数列表
		void clear_parameters();

		/**
		* @brief 添加存储过程double类型参数
		* @param name: 参数名称
		* @param derection: 指定是输入还是输出或者输入输出
		* @param pvalue: 参数具体值
		*/
		void add_double_param(const string &name, ParameterDirectionEnum dereiction, double value);

		/**
		 * @brief 获取存储过程doubel类型返回值
		 * @param name: 参数名称
		 * @return 存储过程传出参数值
		 */
		double get_double_param(const string &name);

		/**
		* @brief 添加存储过程int类型参数
		* @param name: 参数名称
		* @param derection: 指定是输入还是输出或者输入输出
		* @param pvalue: 参数具体值
		*/
		void add_int_param(const string &name, ParameterDirectionEnum dereiction, int value);

		/**
		 * @brief 获取存储过程int类型返回值
		 * @param name: 参数名称
		 * @return 存储过程传出参数值
		 */
		int get_int_param(const string &name);

		/**
		* @brief 添加存储过程bool类型参数
		* @param name: 参数名称
		* @param derection: 指定是输入还是输出或者输入输出
		* @param pvalue: 参数具体值
		*/
		void add_bool_param(const string &name, ParameterDirectionEnum dereiction, bool value);

		/**
		 * @brief 获取存储过程bool类型返回值
		 * @param name: 参数名称
		 * @return 存储过程传出参数值
		 */
		bool get_bool_param(const string &name);

		/**
		* @brief 添加存储过程longlong类型参数
		* @param name: 参数名称
		* @param derection: 指定是输入还是输出或者输入输出
		* @param pvalue: 参数具体值
		*/
		void add_64int_param(const string &name, ParameterDirectionEnum dereiction, long long value);

		/**
		 * @brief 获取存储过程long long类型返回值
		 * @param name: 参数名称
		 * @return 存储过程传出参数值
		 */
		long long get_64int_param(const string &name);

		/**
		* @brief 添加存储过程short类型参数
		* @param name: 参数名称
		* @param derection: 指定是输入还是输出或者输入输出
		* @param pvalue: 参数具体值
		*/
		void add_short_param(const string &name, ParameterDirectionEnum dereiction, short value);

		/**
		 * @brief 获取存储过程short类型返回值
		 * @param name: 参数名称
		 * @return 存储过程传出参数值
		 */
		short get_short_param(const string &name);

		/**
		* @brief 添加存储过程string类型参数
		* @param name: 参数名称
		* @param derection: 指定是输入还是输出或者输入输出
		* @param pvalue: 参数具体值
		*/
		void add_string_param(const string &name, ParameterDirectionEnum dereiction, const string &value);

		/**
		 * @brief 获取存储过程doubel类型返回值
		 * @param name: 参数名称
		 * @param value: 存储过程传出参数值[OUT]
		 */
		void get_string_param(const string &name, string &value);

	private:
		
		/// 初始化工作
		void init();

	public:
		_ConnectionPtr  m_pconn;                ///< 数据库连接对象
		CH_DbCommand    *m_pcommand;             ///< 数据库命令对象
};

#endif