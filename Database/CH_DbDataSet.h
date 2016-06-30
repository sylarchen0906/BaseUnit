#ifndef __CH_DBDATASET_H__
#define __CH_DBDATASET_H__

#include <string>
using std::string;

/************************************************************************/
/* Author: Sylar.Chen     2015-6-06-20                                  */
/* File Description: 数据库数据集对象封装                               */
/************************************************************************/
#import "C:\Program Files\Common Files\System\ado\msado15.dll" no_namespace rename("EOF","adoEOF")

class CH_DbDataSet
{
	public:
		CH_DbDataSet();

		virtual ~CH_DbDataSet();

	public:
		/// 获取当前记录集条数
		long get_count();

		/// 移动到第一条数据
		void move_first();

		/// 移动到最后一条数据
		void move_last();

		/// 移动游标到下一条记录
		void move_next();

		/// 移动到上一条记录
		void move_previous();

		/// 游标是否移动到了最后，结束标识
		bool is_eof();

		/**
		 * @brief 获取数据库类型为smallint的数据
		 * @parma name: 字段名称
		 * @return 对应字段的值
		 */
		short get_short_field(const string &name);

		/**
		 * @brief 获取数据库类型为integer的数据
		 * @parma name: 字段名称
		 * @return 对应字段的值
		 */
		int get_int_field(const string &name);

		/**
		 * @brief 获取数据库类型为bigint的数据
		 * @parma name: 字段名称
		 * @return 对应字段的值
		 */
		long long get_int64_field(const string &name);

		/**
		 * @brief 获取数据库类型为double的数据
		 * @parma name: 字段名称
		 * @return 对应字段的值
		 */
		double get_double_field(const string &name);

		/**
		 * @brief 获取数据库类型为boolean的数据
		 * @parma name: 字段名称
		 * @return 对应字段的值
		 */
		bool get_bool_field(const string &name);

		/**
		 * @brief 获取数据库类型为varchar的数据
		 * @parma name: 字段名称
		 * @value 对应字段的值 [OUT]
		 */
		void get_string_field(const string &name, string &value);




	public:
		_RecordsetPtr             m_pdataset;           ///< 数据库记录集对象
};

#endif