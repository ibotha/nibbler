#pragma once

#include <exception>
#include <string>

class Exceptions
{
	public:
	Exceptions(void);
	Exceptions(const Exceptions&);
	~Exceptions(void);
	Exceptions &operator=(const Exceptions&);
	class LibraryNotFound : public std::exception
	{
		public:
			LibraryNotFound(void);
			LibraryNotFound(std::string);
			LibraryNotFound(const LibraryNotFound&);
			virtual ~LibraryNotFound(void) throw();
			LibraryNotFound  &operator= (const LibraryNotFound&);
			virtual const char    *what() const throw();
		private:
			std::string reason;
	};
};
