#ifndef __DYNAMIC_ARRAY_H
#define __DYNAMIC_ARRAY_H

class DynamicArray 
{
public:
	DynamicArray();
	DynamicArray(size_t);
	DynamicArray(const DynamicArray&);
	DynamicArray& operator=(const DynamicArray&);
	~DynamicArray();

	void push_front(const double&);
	void pop_front();
	void push_back(const double&);
	void pop_back();
	double& at(size_t);
	double& operator[](size_t);
	double operator[](size_t) const;
	size_t size() const;
	size_t capacity() const;
	bool empty() const;

protected:
	void initialize();
	void reserve(size_t);
	void copy(const DynamicArray&);
	void erase(size_t, size_t);
	void clear();

private:
	size_t m_capacity;
	size_t m_size;
	double* m_data;
};

DynamicArray::DynamicArray() 
{
	initialize();
}

DynamicArray::DynamicArray(size_t size) 
{
	initialize();

	if (m_capacity < size)
	{
		reserve(size);
	}

	m_size = size;
}

DynamicArray::DynamicArray(const DynamicArray& other) 
{
	initialize();
	copy(other);
}

DynamicArray& DynamicArray::operator=(const DynamicArray& other) 
{
	if (this != &other) 
	{
		copy(other);
	}

	return *this;
}

DynamicArray::~DynamicArray() 
{
	clear();
}

void DynamicArray::push_front(const double& value) 
{
	if (m_size >= m_capacity)
	{
		reserve(m_capacity * 2);
	}
	
	for (size_t i = m_size; i > 0; --i)
	{
		m_data[i] = m_data[i - 1];
	}

	m_data[0] = value;
	m_size++;
}
void DynamicArray::pop_front() 
{
	erase(0, 1);
}

void DynamicArray::push_back(const double& value) 
{
	if (m_size >= m_capacity)
	{
		reserve(m_capacity * 2);
	}

	m_data[m_size] = value;
	m_size++;
}

void DynamicArray::pop_back() 
{
	erase(m_size - 1, m_size);
}

double& DynamicArray::at(size_t index) 
{
	if(index < 0 && index >= m_size)
	{
		throw "Bad index!";
	}

	return m_data[index];
}

double& DynamicArray::operator[](size_t index) 
{
	if (index < 0 || index >= (size_t)m_size)
	{
		throw "Bad index!";
	}

	return m_data[index];
}

double DynamicArray::operator[](size_t index) const 
{
	if (index < 0 || index >= (size_t)m_size)
	{
		return 0;
	}

	return m_data[index];
}

size_t DynamicArray::size() const 
{
	return m_size;
}

size_t DynamicArray::capacity() const 
{
	return m_capacity;
}

bool DynamicArray::empty() const 
{
	return !m_size;
}

void DynamicArray::initialize() 
{
	m_data = nullptr;
	m_capacity = 0;
	m_size = 0;
}

void DynamicArray::reserve(size_t capacity) 
{
	capacity = (capacity <= 0 ? 1 : capacity);

	if (capacity <= m_capacity) 
	{
		return;
	}

	double* data = new double[capacity];
	m_capacity = capacity;

	for (size_t i = 0; i < m_size; i++)
	{
		data[i] = m_data[i];
	}
	
	delete[] m_data;
	m_data = data;
}

void DynamicArray::copy(const DynamicArray& other) 
{
	clear();
	reserve(other.m_size);
	m_size = other.m_size;

	for (size_t i = 0; i < m_size; ++i)
	{
		m_data[i] = other.m_data[i];
	}
}

void DynamicArray::erase(size_t first, size_t last) 
{
	first = (first < 0 ? 0 : first);
	last = (last < 0 ? first + 1 : last);

	if (first >= m_size || last <= first)
	{
		return;
	}

	for (size_t i = last; i < m_size; ++i)
	{
		m_data[first + i - last] = m_data[i];
	}

	m_size -= last - first;
}

void DynamicArray::clear() 
{
	delete[] m_data;

	initialize();
}

#endif