#include "CH_DbDataSet.h"

CH_DbDataSet::CH_DbDataSet()
{
	
}

CH_DbDataSet::~CH_DbDataSet()
{
	
}

long CH_DbDataSet::get_count()
{
	return m_pdataset->GetRecordCount();
}

void CH_DbDataSet::move_first()
{
	m_pdataset->MoveFirst();
}

void CH_DbDataSet::move_last()
{
	m_pdataset->raw_MoveLast();
}

void CH_DbDataSet::move_next()
{
	m_pdataset->MoveNext;
}

void CH_DbDataSet::move_previous()
{
	m_pdataset->MovePrevious();
}

bool CH_DbDataSet::is_eof()
{
	return (bool)m_pdataset->adoEOF;
}

short CH_DbDataSet::get_short_field(const string &name)
{
	return (short)m_pdataset->GetCollect(name.c_str());
}

int CH_DbDataSet::get_int_field(const string &name)
{
	return (int)m_pdataset->GetCollect(name.c_str());
}

long long CH_DbDataSet::get_int64_field(const string &name)
{
	return (long long)m_pdataset->GetCollect(name.c_str());
}

double CH_DbDataSet::get_double_field(const string &name)
{
	return (double)m_pdataset->GetCollect(name.c_str());
}

bool CH_DbDataSet::get_bool_field(const string &name)
{
	return (bool)m_pdataset->GetCollect(name.c_str());
}

void CH_DbDataSet::get_string_field(const string &name, string &value)
{
	_variant_t value_t = m_pdataset->GetCollect(name.c_str());
	value = (const char *)_bstr_t(value_t);
}