#include "vector.h"

Vector::Vector()
{
	m_capacity = MIN_CAPACITY;
	m_size = 0;
	arr = new int(m_capacity);
	if (!arr)
		throw	std::bad_alloc();
}

Vector::~Vector()
{
	delete arr;
}

void		Vector::push_back(int value)
{
	if (m_size > m_capacity)
		resize();
	*(arr + m_size++) = value;
}

size_t		Vector::size()
{
	return	m_size;
}

bool		Vector::empty()
{
	if (m_size == 0)
		return true;
	else
		return false;
}

void		Vector::move(size_t start)
{
	for (int i = start; i < m_size; i++)
		std::swap(arr[i], arr[i + 1]);	
}

void		Vector::clear()
{
	m_size = 0;
}

void		Vector::erase(size_t pos)
{
	if (pos > m_size)
		throw std::out_of_range("erasing an element out of bounds");
	move(pos);
	m_size--;
}

size_t		Vector::resize()
{
	size_t	capacity = m_capacity * CAP_FACTOR;
	int		*tmp = new int(capacity);
	if (!tmp)
		throw	std::bad_alloc();
	arr = tmp;
	m_capacity = capacity;
	delete tmp;
}