#include "CH_DbConn.h"
#include <stdexcept>

CH_DbConn::CH_DbConn()
{
	init();
	m_pconn.CreateInstance(__uuidof(Connection));
	m_pcommand = new CH_DbCommand();
}

CH_DbConn::~CH_DbConn()
{
	CoUninitialize();
	m_pconn.Release();
	if (m_pcommand != NULL)
	{
		delete m_pcommand;
	}
}

void CH_DbConn::init()
{
	
	CoInitialize(NULL);
}

bool CH_DbConn::is_open()
{
	if (m_pconn->GetState() == adStateClosed)
	{
		return false;
	}
	return true;
} 

bool CH_DbConn::open(const string &udl_file_name)
{
	string conn_str = "File Name=";
	conn_str += udl_file_name;
	m_pconn->ConnectionString = conn_str.c_str();
	m_pconn->ConnectionTimeout = 20;
	HRESULT h_ret= m_pconn->Open("", "", "", adConnectUnspecified);
	if (m_pconn->GetState() == adStateClosed)
	{
		return false;
	}
	m_pcommand->add_connection(this);
	return true;
}

void CH_DbConn::close()
{
	if (!is_open())
	{
		m_pconn->Close();
	}
}

void CH_DbConn::begin_trans()
{
	m_pconn->BeginTrans();
}

void CH_DbConn::roll_back()
{
	m_pconn->RollbackTrans();
}

void CH_DbConn::commit_trans()
{
	m_pconn->CommitTrans();
}

void CH_DbConn::cancle()
{
	m_pconn->Cancel();
}

void CH_DbConn::excute_no_result(const string &sql)
{
	m_pcommand->excute_no_result(sql);
}

const CH_DbDataSet& CH_DbConn::excute_select(const string &sql)
{
	return m_pcommand->excute_select(sql);
}

void CH_DbConn::excute_procedure(const string &proc)
{
	m_pcommand->excute_procedure(proc);
}

void CH_DbConn::clear_parameters()
{
	m_pcommand->clear_parameters();
}

void CH_DbConn::add_double_param(const string &name, ParameterDirectionEnum dereiction, double value)
{
	m_pcommand->add_paramter(name, adDouble, dereiction, sizeof(double), &value);
}

double CH_DbConn::get_double_param(const string &name)
{
	_variant_t value;
	m_pcommand->get_parameter(name, value);
	return (double)value;
}

void CH_DbConn::add_int_param(const string &name, ParameterDirectionEnum dereiction, int value)
{
	m_pcommand->add_paramter(name, adInteger, dereiction, sizeof(int), &value);
}

int CH_DbConn::get_int_param(const string &name)
{
	_variant_t value;
	m_pcommand->get_parameter(name, value);
	return (int)value;
}

void CH_DbConn::add_64int_param(const string &name, ParameterDirectionEnum dereiction, long long value)
{
	m_pcommand->add_paramter(name, adBigInt, dereiction, sizeof(long long), &value);
}

long long CH_DbConn::get_64int_param(const string &name)
{
	_variant_t value;
	m_pcommand->get_parameter(name, value);
	return (long long)value;
}

void CH_DbConn::add_bool_param(const string &name, ParameterDirectionEnum dereiction, bool value)
{
	m_pcommand->add_paramter(name, adBoolean, dereiction, sizeof(bool), &value);
}

bool CH_DbConn::get_bool_param(const string &name)
{
	_variant_t value;
	m_pcommand->get_parameter(name, value);
	return (bool)value;
}

void CH_DbConn::add_short_param(const string &name, ParameterDirectionEnum dereiction, short value)
{
	m_pcommand->add_paramter(name, adSmallInt, dereiction, sizeof(short), &value);
}

short CH_DbConn::get_short_param(const string &name)
{
	_variant_t value;
	m_pcommand->get_parameter(name, value);
	return (short)value;
}

void CH_DbConn::add_string_param(const string &name, ParameterDirectionEnum dereiction, const string &value)
{
	m_pcommand->add_paramter(name, adVarChar, dereiction, value.length(), (void *)value.c_str());
}

void CH_DbConn::get_string_param(const string &name, string &value)
{
	_variant_t value_t;
	m_pcommand->get_parameter(name, value_t);
	value = (const char *)_bstr_t(value_t);
}