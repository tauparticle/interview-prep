// VectorOfVectorsIterator.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <vector>
#include <iostream>

/*
class IntegerIterator
{
public:
    virtual bool hasNext() = 0;

    virtual int getNext() = 0;
};


    [[0],[1,2,3],[4],[5,6,7],[9,10]]

    outputs 0,1,2,3,4,5,6,7,8,9,10
*/



class VectorSetFlattener 
{
public:
	VectorSetFlattener(std::vector<std::vector<int>> & vectors)
	{
		m_outerIt = vectors.begin();
		m_outerItEnd = vectors.end();
		m_innerIt = m_outerIt->begin();
		m_innerItEnd = m_outerIt->end();
		m_index = 0;

		for (auto & v : vectors)
		{
			m_end += v.size();
		}
	}

	bool hasNext()
	{
		return m_index < m_end;
	}

	int getNext()
	{
		if (m_innerIt == m_innerItEnd) 
		{
			advance();
		}

		int value = *m_innerIt;
		m_index++;

		++m_innerIt;
		//if (m_innerIt == m_innerItEnd)
		//{
		//	if (hasNext())
		//	{
		//		advance();
		//	}
		//}

		return value;
	}

private:

	void advance()
	{
		bool ready = false;
		while (!ready)
		{
			++m_outerIt;
			m_innerIt = m_outerIt->begin();
			m_innerItEnd = m_outerIt->end();
			if (m_innerIt != m_innerItEnd)
			{
				ready = true;
			}
		}
	}


	typedef std::vector<std::vector<int>>::const_iterator OuterIter;
	typedef std::vector<int>::const_iterator InnerIter;
	OuterIter m_outerIt;
	OuterIter m_outerItEnd;
	InnerIter m_innerIt;
	InnerIter m_innerItEnd;
	int m_index;
	int m_end;
};


int main()
{
	std::vector<std::vector<int>> vectors;
	std::vector<int> v = { 1,2,3 };
	vectors.push_back(v);
	vectors.push_back({ 1 });
	vectors.push_back({ 4,5,6 });
	vectors.push_back({ 7,8 });
	vectors.push_back({ 100 });

	VectorSetFlattener flattener(vectors);
	while (flattener.hasNext())
	{
		std::cout << flattener.getNext() << ",";
	}
	std::cout << std::endl;

	vectors.clear();
	vectors.push_back({});
	vectors.push_back({ 1 });
	vectors.push_back({});
	vectors.push_back({ 2,3,4 });
	vectors.push_back({});
	vectors.push_back({});
	vectors.push_back({ 5 });

	VectorSetFlattener flattener2(vectors);
	while (flattener2.hasNext())
	{
		std::cout << flattener2.getNext() << ",";
	}

	int i = 5;
}

