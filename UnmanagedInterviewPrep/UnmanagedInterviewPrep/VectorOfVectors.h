#pragma once
#include <vector>
#include <iostream>
using namespace std;
class VectorOfVectors
{
public:
	
	VectorOfVectors(vector<vector<int>> & v);
	VectorOfVectors(vector<int> & v1, vector<int> & v2, vector<int> & v3);
	~VectorOfVectors(void);

	int getNextInt();

private:
	
	vector<int> & m_v1;
	vector<int> & m_v2;
	vector<int> & m_v3;

	size_t m_index;

};

class VectorOfVectorsException : public exception
{
public:
	virtual const char* what() const throw()
	{
		return "At the end of the sequence";
	}
};


class VectorOfVectorsTest
{
public:
	void Test()
	{
		vector<int> v1;  v1.push_back(1); v1.push_back(2); v1.push_back(3); v1.push_back(4); v1.push_back(5); 
		vector<int> v2;  v2.push_back(6); v2.push_back(7); v2.push_back(8); v2.push_back(9); v2.push_back(10); 
		vector<int> v3;  v3.push_back(11); v3.push_back(12); v3.push_back(13); v3.push_back(14); v3.push_back(15); 

		VectorOfVectors v(v1, v2, v3);

		try
		{
			cout << endl;
			while(true)
			{
				cout << v.getNextInt() << ", ";
			}

		}
		catch (VectorOfVectorsException ex)
		{
			cout << ex.what() << endl;
		}

	}
};

