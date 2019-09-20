#pragma once

#include <cstdlib>
#include <stdexcept>
#include <algorithm>
#include <iostream>

#define MIN_CAPACITY 10
#define	CAP_FACTOR	 2

template <class T>
class		Vector{
	public:
		Vector();
		~Vector();

		void	push_back(T value);
		size_t	size() const;
		void	erase(size_t pos);
		void	clear();
		bool	empty() const;
		T		operator[](size_t pos){
			if (pos > m_size)
				throw	std::out_of_range("element out of bound");
			else
				return *(arr + pos);
		};
	private:
		size_t	m_size;
		size_t	m_capacity;
		T*		arr;
		void	resize();
		void	move(size_t start);
};


template <class T>
Vector<T>::Vector()
{
	m_capacity = MIN_CAPACITY;
	m_size = 0;
	arr = new T[m_capacity];
}

template <class T>
Vector<T>::~Vector()
{
	delete arr;
}

template <class T>
void		Vector<T>::push_back(T value)
{
	if (m_size >= m_capacity)
		resize();
	*(arr + m_size++) = value;
}

template <class T>
size_t		Vector<T>::size() const
{
	return	m_size;
}

template <class T>
bool		Vector<T>::empty() const
{
	return m_size == 0;
}

template <class T>
void		Vector<T>::move(size_t start)
{
	for (size_t i = start; i < m_size; i++)
		std::swap(arr[i], arr[i + 1]);	
}

template <class T>
void		Vector<T>::clear()
{
	m_size = 0;
}

template <class T>
void		Vector<T>::erase(size_t pos)
{
	if (pos > m_size)
		throw std::out_of_range("erasing an element out of bounds");
	move(pos);
	m_size--;
}

template <class T>
void		Vector<T>::resize()
{
	size_t	capacity = m_capacity * CAP_FACTOR;
	T		*tmp = new T[capacity];
	for (size_t i = 0; i < m_capacity; i++)
		tmp[i] = arr[i];
	delete arr;
	arr = tmp; 
	m_capacity = capacity;
}
