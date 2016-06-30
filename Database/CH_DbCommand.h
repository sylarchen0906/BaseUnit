#ifndef __CH_DBCOMMAND_H__
#define __CH_DBCOMMAND_H__

#include "CH_DbDataSet.h"
#include "CH_DbConn.h"
#include <string>
using std::string;
/************************************************************************/
/* Author: Sylar.Chen     2015-6-06-20                                  */
/* File Description: ���ݿ���������װ                                 */
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
		 * @brief �������ݿ�����
		 * @param p_conn: ���ݿ����Ӷ���
		 */
		void add_connection(const CH_DbConn *pconn);

		/**
		 * @brief ִ��SQL��ѯ
		 * @param sql: SQL���
		 * @return �����¼��
		 */
		const CH_DbDataSet& excute_select(const string &sql);

		/**
		 * @brief ִ�в����ؽ������SQL
		 * @param sql: SQL���
		 */
		void excute_no_result(const string &sql);

		/**
		 * @brief ִ�д洢����
		 * @param proc: �洢��������
		 */
		void excute_procedure(const string &proc);

		/**
		 * @brief ��Ӵ洢���̲���
		 * @param name: ��������
		 * @param type: ��������
		 * @param derection: ָ�������뻹����������������
		 * @param size: �����Ĵ�С
		 * @param pvalue: ��������ֵ
		 */
		void add_paramter(const string &name, DataTypeEnum type, ParameterDirectionEnum dereiction, long size, void *pvalue);


		/**
		 * @brief ��ȡ�洢ִ�к�Ĵ�������
		 * @param name: ��������
		 * @param value: ��������ֵ[OUT]
		 */
		void get_parameter(const string &name, _variant_t &value);

		/// ��մ洢���̵Ĳ����б�
		void clear_parameters();

	private:
		_CommandPtr                  m_pcommand;                ///< ���ݿ������ж���
		CH_DbDataSet                 m_dataset;                 ///< ��ѯ�������¼��
		
};

#endif