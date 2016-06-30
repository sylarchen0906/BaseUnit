#ifndef __CH_TOOLS_H__
#define __CH_TOOLS_H__

/************************************************************************/
/* @file descript: �ṩ���õĹ���                                        */
/* @author: Sylar.Chen  2016-05-25                                      */
/************************************************************************/

#include <stdio.h>
#include <string>

#define IP_MAX              17               ///< ����IP�ĳ���

using std::string;

class CH_Tool
{
		CH_Tool();                           ///< ��̬�࣬���Բ���Ҫ���캯��������Ϊprivate

		~CH_Tool();
	public:
		/**
		 * @brief ���ݱ�ǽ�ȡstring�ַ����еĵ�һ����
		 * @param source:Դ�ַ���
		 * @param dest: �õ��ĵ�һ����
		 * @param flag: ��ȡ���
		 * @return ��ȡͷ���Ƿ�ɹ�
		 * @li true: ��ȡͷ���ɹ�
		 * @li false: ��ȡͷ��ʧ��, û���ҵ����ұ��
		 */
		static bool fetch_head(string &source, string &dest, char flag);

		/**
		 * @brief ���ݱ�ǽ�ȡstring�ַ����еĵ�һ����
		 * @param source:Դ�ַ���
		 * @param dest: �õ��ĵ�һ����
		 * @param flag: ��ȡ���
		 * @return ��ȡͷ���Ƿ�ɹ�
		 * @li true: ��ȡͷ���ɹ�
		 * @li false: ��ȡͷ��ʧ�ܣ� û���ҵ����ұ��
		 */
		static bool fetch_head(string &source, string &dest, const string &flag);

		/**
		 * @brief ��string��ʽ��IPת��Ϊuint��ʽ��IP
		 * @param ip: �ַ���IP
		 * @return �������͵�IP�����IP�����Ϲ����򷵻�0
		 */
		static unsigned int ipv4_to_uint(const string &ip);

		/**
		 * @brief ��32λIPת��Ϊ���ʮ����IP
		 * @param ip: 32λIP
		 * @return ���ʮ����IP������ַ����ǹ̶��ģ������������ֱ�ӷ���string
		 */
		static string uint_to_ipv4(unsigned int ip);

		/**
		 * @brief ��32λint����ת��Ϊ�ַ�����ʽ
		 * @param num: 32λint����
		 * @return ת������ַ���
		 */
		static string int32_to_str(int num);

		/**
		 * @brief ��64λint����ת��Ϊ�ַ�����ʽ
		 * @param num: 64λint����
		 * @return ת������ַ���
		 */
		static string int64_to_str(long long num);

		/**
		 * @brief ���ַ���ת��Ϊ32λ���ַ���
		 * @param str: 32λ�ַ�������
		 * @param num: ת�����32λint����
		 * @return ת�����
		 * @li true: ת���ɹ�
		 * @li false: ת��ʧ��
		 */
		static bool str_to_int32(const string &str, int &num);

		/**
		 * @brief ���ַ���ת��Ϊ64λ���ַ���
		 * @param str: 64λ�ַ�������
		 * @param num: ת�����64λint����
		 * @return ת�����
		 * @li true: ת���ɹ�
		 * @li false: ת��ʧ��
		 */
		static bool str_to_int64(const string &str, long long &num);

};

#endif