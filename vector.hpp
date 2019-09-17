#include <cstdlib>
#include <stdexcept>

#define MIN_CAPACITY 10
#define	CAP_FACTOR	 2

class		Vector{
	public:
		Vector();
		~Vector();

		void	push_back(int value);
		size_t	size() const;
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
		void	resize();
		void	move(size_t start);
};