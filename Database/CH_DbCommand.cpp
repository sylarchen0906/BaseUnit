#include "CH_DbCommand.h"

CH_DbCommand::CH_DbCommand()
{
	m_pcommand.CreateInstance(__uuidof(Command));
}

CH_DbCommand::~CH_DbCommand()
{
	m_pcommand.Release();
}

void CH_DbCommand::add_connection(const CH_DbConn *pconn)
{
	if (pconn)
	{
		m_pcommand->ActiveConnection = pconn->m_pconn;
	}
}


const CH_DbDataSet& CH_DbCommand::excute_select(const string &sql)
{
	m_pcommand->CommandText = (_bstr_t)sql.c_str();
	_RecordPtr set = m_pcommand->Execute(NULL, NULL, adCmdTable);
	m_dataset.m_pdataset = set;
	return m_dataset;
}

void CH_DbCommand::excute_no_result(const string &sql)
{
	m_pcommand->CommandText = (_bstr_t)sql.c_str();
	m_pcommand->Execute(NULL, NULL, adCmdText);
}

void CH_DbCommand::excute_procedure(const string &proc)
{
	m_pcommand->Execute(NULL, NULL, adCmdStoredProc);
}

void CH_DbCommand::add_paramter(const string &name, DataTypeEnum type, ParameterDirectionEnum dereiction, long size, void *pvalue)
{
	_ParameterPtr pparam = NULL;
	const char *pname = name.c_str();
	
	switch (type)
	{
	case adEmpty:             ///< Пе
		pparam = m_pcommand->CreateParameter((_bstr_t)pname, type, dereiction, size, NULL);
		break;
	case adDouble:            ///< double
	do 
	{
		_variant_t value(double(*pvalue));
		pparam = m_pcommand->CreateParameter((_bstr_t)pname, type, dereiction, size, value);

	} while (0);	
		break;
	case adInteger:           ///< int
		do
		{
			_variant_t value(int(*pvalue));
			pparam = m_pcommand->CreateParameter((_bstr_t)pname, type, dereiction, size, value);

		} while (0);
		break;
	case adBoolean:           ///< bool
		do
		{
			_variant_t value(bool(*pvalue));
			pparam = m_pcommand->CreateParameter((_bstr_t)pname, type, dereiction, size, value);

		} while (0);
		break;
	case adBigInt:            ///< long long 
		do
		{
			_variant_t value(long long(*pvalue));
			pparam = m_pcommand->CreateParameter((_bstr_t)pname, type, dereiction, size, value);

		} while (0);
		break;
	case adSmallInt:          ///< short
		do
		{
			_variant_t value(short(*pvalue));
			pparam = m_pcommand->CreateParameter((_bstr_t)pname, type, dereiction, size, value);

		} while (0);
		break;
	case adVarChar:           ///< string
		do
		{
			_variant_t value(char *(pvalue));
			pparam = m_pcommand->CreateParameter((_bstr_t)pname, type, dereiction, size, value);

		} while (0);
		break;

	}
	m_pcommand->Parameters->Append(pparam);
}

void CH_DbCommand::get_parameter(const string &name, _variant_t &value)
{
	value = m_pcommand->GetParameters()->GetItem(name.c_str())->GetValue();
}

void CH_DbCommand::clear_parameters()
{
	m_pcommand->Parameters.Release();
}