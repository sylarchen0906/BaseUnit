#ifndef __CH_DBDATASET_H__
#define __CH_DBDATASET_H__

#include <string>
using std::string;

/************************************************************************/
/* Author: Sylar.Chen     2015-6-06-20                                  */
/* File Description: ���ݿ����ݼ������װ                               */
/************************************************************************/
#import "C:\Program Files\Common Files\System\ado\msado15.dll" no_namespace rename("EOF","adoEOF")

class CH_DbDataSet
{
	public:
		CH_DbDataSet();

		virtual ~CH_DbDataSet();

	public:
		/// ��ȡ��ǰ��¼������
		long get_count();

		/// �ƶ�����һ������
		void move_first();

		/// �ƶ������һ������
		void move_last();

		/// �ƶ��α굽��һ����¼
		void move_next();

		/// �ƶ�����һ����¼
		void move_previous();

		/// �α��Ƿ��ƶ�������󣬽�����ʶ
		bool is_eof();

		/**
		 * @brief ��ȡ���ݿ�����Ϊsmallint������
		 * @parma name: �ֶ�����
		 * @return ��Ӧ�ֶε�ֵ
		 */
		short get_short_field(const string &name);

		/**
		 * @brief ��ȡ���ݿ�����Ϊinteger������
		 * @parma name: �ֶ�����
		 * @return ��Ӧ�ֶε�ֵ
		 */
		int get_int_field(const string &name);

		/**
		 * @brief ��ȡ���ݿ�����Ϊbigint������
		 * @parma name: �ֶ�����
		 * @return ��Ӧ�ֶε�ֵ
		 */
		long long get_int64_field(const string &name);

		/**
		 * @brief ��ȡ���ݿ�����Ϊdouble������
		 * @parma name: �ֶ�����
		 * @return ��Ӧ�ֶε�ֵ
		 */
		double get_double_field(const string &name);

		/**
		 * @brief ��ȡ���ݿ�����Ϊboolean������
		 * @parma name: �ֶ�����
		 * @return ��Ӧ�ֶε�ֵ
		 */
		bool get_bool_field(const string &name);

		/**
		 * @brief ��ȡ���ݿ�����Ϊvarchar������
		 * @parma name: �ֶ�����
		 * @value ��Ӧ�ֶε�ֵ [OUT]
		 */
		void get_string_field(const string &name, string &value);




	public:
		_RecordsetPtr             m_pdataset;           ///< ���ݿ��¼������
};

#endif