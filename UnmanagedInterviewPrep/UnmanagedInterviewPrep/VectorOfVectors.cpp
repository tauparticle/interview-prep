#include "stdafx.h"
#include "VectorOfVectors.h"



VectorOfVectors::VectorOfVectors(vector<int> & v1, vector<int> & v2, vector<int> & v3)
	: m_index(-1)
	, m_v1(v1)
	, m_v2(v2)
	, m_v3(v3)
{
}



VectorOfVectors::~VectorOfVectors(void)
{
}

int VectorOfVectors::getNextInt()
{
	if (++m_index >= (m_v1.size() + m_v2.size() + m_v3.size()))
	{
		throw VectorOfVectorsException();
		m_index = 0;
	}

	if (m_index < m_v1.size())
	{
		return m_v1[m_index];
	}

	if (m_index < m_v1.size() + m_v2.size())
	{
		int tmpIndex = m_index - m_v1.size();
		return m_v2[tmpIndex];
	}


	int tmpIndex = m_index - m_v2.size() - m_v1.size();
	return m_v3[tmpIndex];
}
