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