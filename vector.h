#pragma once

#include <cstdlib>
#include <new>
#include <stdexcept>

#define MIN_CAPACITY 10
#define	CAP_FACTOR	 2

class		Vector{
	public:
		Vector() = default;
		~Vector();

		void	push_back(int value);
		size_t	size();
		void	erase(size_t pos);
		void	clear();
		bool	empty();
		int		&operator[](size_t pos){
			if (pos > m_size)
				throw	std::out_of_range("element out of bound");
			else
				return *(arr + pos);
		};
	private:
		size_t	m_size;
		size_t	m_capacity;
		int		*arr;
		size_t	resize();
		void	move(size_t start);
};