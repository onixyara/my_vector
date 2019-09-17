#include "vector.hpp"

Vector::Vector()
{
	m_capacity = MIN_CAPACITY;
	m_size = 0;
	arr = new int(m_capacity);
}

Vector::~Vector()
{
	delete arr;
}

void		Vector::push_back(int value)
{
	if (m_size >= m_capacity)
		resize();
	*(arr + m_size++) = value;
}

size_t		Vector::size() const
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

void		Vector::resize()
{
	size_t	capacity = m_capacity * CAP_FACTOR;
	int		*tmp = new int(capacity);
	arr = tmp;
	m_capacity = capacity;
	delete tmp;
}