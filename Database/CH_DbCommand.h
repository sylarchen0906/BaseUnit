#ifndef __CH_DBCOMMAND_H__
#define __CH_DBCOMMAND_H__

#include "CH_DbDataSet.h"
#include "CH_DbConn.h"
#include <string>
using std::string;
/************************************************************************/
/* Author: Sylar.Chen     2015-6-06-20                                  */
/* File Description: 数据库命令对象封装                                 */
/************************************************************************/

class CH_DbConn;
class CH_DbDataSet;

class CH_DbCommand
{
	public:
		CH_DbCommand();

		virtual ~CH_DbCommand();

	public:
		/**
		 * @brief 设置数据库连接
		 * @param p_conn: 数据库连接对象
		 */
		void add_connection(const CH_DbConn *pconn);

		/**
		 * @brief 执行SQL查询
		 * @param sql: SQL语句
		 * @return 结果记录集
		 */
		const CH_DbDataSet& excute_select(const string &sql);

		/**
		 * @brief 执行不返回结果集的SQL
		 * @param sql: SQL语句
		 */
		void excute_no_result(const string &sql);

		/**
		 * @brief 执行存储过程
		 * @param proc: 存储过程名称
		 */
		void excute_procedure(const string &proc);

		/**
		 * @brief 添加存储过程参数
		 * @param name: 参数名称
		 * @param type: 参数类型
		 * @param derection: 指定是输入还是输出或者输入输出
		 * @param size: 参数的大小
		 * @param pvalue: 参数具体值
		 */
		void add_paramter(const string &name, DataTypeEnum type, ParameterDirectionEnum dereiction, long size, void *pvalue);


		/**
		 * @brief 获取存储执行后的传出参数
		 * @param name: 参数名称
		 * @param value: 参数具体值[OUT]
		 */
		void get_parameter(const string &name, _variant_t &value);

		/// 清空存储过程的参数列表
		void clear_parameters();

	private:
		_CommandPtr                  m_pcommand;                ///< 数据库命令行对象
		CH_DbDataSet                 m_dataset;                 ///< 查询语句结果记录集
		
};

#endif