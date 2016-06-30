#ifndef __CH_DBCONN_H__
#define __CH_DBCONN_H__
/************************************************************************/
/* Author: Sylar.Chen     2015-6-06-20                                  */
/* File Description: ���ݿ����Ӷ����װ                                 */
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
		 * @brief ��������Ƿ��
		 * @return ���ݿ��Ƿ��Ѵ�
		 */
		bool is_open();

		/**
		 * @brief �����ݿ�����
		 * @paran udl_file_name: UDL�ļ�·��
		 * @return �Ƿ����ӳɹ�
		 */
		bool open(const string &udl_file_name);

		/// �ر����ݿ�����
		void close();

		/// ��ʼ����
		void begin_trans();

		/// �ع�����
		void roll_back();

		/// ȡ��һ��ִ��
		void cancle();

		/// �ύ����
		void commit_trans();

	public:
		/**
		 * @brief ִ�в����ؽ������SQL
		 * @param sql: SQL���
		 */
		void excute_no_result(const string &sql);

		/**
		 * @brief ִ��SQL��ѯ
		 * @param sql: SQL���
		 * @return �����¼��
		 */
		const CH_DbDataSet& excute_select(const string &sql);

		/**
		 * @brief ִ�д洢����
		 * @param proc: �洢��������
		 */
		void excute_procedure(const string &proc);

		/// ��մ洢���̵Ĳ����б�
		void clear_parameters();

		/**
		* @brief ��Ӵ洢����double���Ͳ���
		* @param name: ��������
		* @param derection: ָ�������뻹����������������
		* @param pvalue: ��������ֵ
		*/
		void add_double_param(const string &name, ParameterDirectionEnum dereiction, double value);

		/**
		 * @brief ��ȡ�洢����doubel���ͷ���ֵ
		 * @param name: ��������
		 * @return �洢���̴�������ֵ
		 */
		double get_double_param(const string &name);

		/**
		* @brief ��Ӵ洢����int���Ͳ���
		* @param name: ��������
		* @param derection: ָ�������뻹����������������
		* @param pvalue: ��������ֵ
		*/
		void add_int_param(const string &name, ParameterDirectionEnum dereiction, int value);

		/**
		 * @brief ��ȡ�洢����int���ͷ���ֵ
		 * @param name: ��������
		 * @return �洢���̴�������ֵ
		 */
		int get_int_param(const string &name);

		/**
		* @brief ��Ӵ洢����bool���Ͳ���
		* @param name: ��������
		* @param derection: ָ�������뻹����������������
		* @param pvalue: ��������ֵ
		*/
		void add_bool_param(const string &name, ParameterDirectionEnum dereiction, bool value);

		/**
		 * @brief ��ȡ�洢����bool���ͷ���ֵ
		 * @param name: ��������
		 * @return �洢���̴�������ֵ
		 */
		bool get_bool_param(const string &name);

		/**
		* @brief ��Ӵ洢����longlong���Ͳ���
		* @param name: ��������
		* @param derection: ָ�������뻹����������������
		* @param pvalue: ��������ֵ
		*/
		void add_64int_param(const string &name, ParameterDirectionEnum dereiction, long long value);

		/**
		 * @brief ��ȡ�洢����long long���ͷ���ֵ
		 * @param name: ��������
		 * @return �洢���̴�������ֵ
		 */
		long long get_64int_param(const string &name);

		/**
		* @brief ��Ӵ洢����short���Ͳ���
		* @param name: ��������
		* @param derection: ָ�������뻹����������������
		* @param pvalue: ��������ֵ
		*/
		void add_short_param(const string &name, ParameterDirectionEnum dereiction, short value);

		/**
		 * @brief ��ȡ�洢����short���ͷ���ֵ
		 * @param name: ��������
		 * @return �洢���̴�������ֵ
		 */
		short get_short_param(const string &name);

		/**
		* @brief ��Ӵ洢����string���Ͳ���
		* @param name: ��������
		* @param derection: ָ�������뻹����������������
		* @param pvalue: ��������ֵ
		*/
		void add_string_param(const string &name, ParameterDirectionEnum dereiction, const string &value);

		/**
		 * @brief ��ȡ�洢����doubel���ͷ���ֵ
		 * @param name: ��������
		 * @param value: �洢���̴�������ֵ[OUT]
		 */
		void get_string_param(const string &name, string &value);

	private:
		
		/// ��ʼ������
		void init();

	public:
		_ConnectionPtr  m_pconn;                ///< ���ݿ����Ӷ���
		CH_DbCommand    *m_pcommand;             ///< ���ݿ��������
};

#endif