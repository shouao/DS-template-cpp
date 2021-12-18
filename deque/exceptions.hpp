#ifndef SJTU_EXCEPTIONS_HPP
#define SJTU_EXCEPTIONS_HPP

#include <cstddef>
#include <cstring>
#include <string>

namespace sjtu {

class exception {
protected:
	const std::string message = "";
public:
	exception(const std::string _message = ""):message(_message) {}
	exception(const exception &other) : message(other.message) {}
	virtual std::string what() {
		return message;
	}
};

/**
 * TODO
 * Please complete them.
 */
class index_out_of_bound : public exception {
	index_out_of_bound() : exception("index_out_of_bound") {}
	index_out_of_bound(const index_out_of_bound &other) : exception(other.message) {}
};

class runtime_error : public exception {
	/* __________________________ */
	runtime_error() : exception("runtime_error"){}
	runtime_error(const runtime_error &other) : exception(other.message) {}
};

class invalid_iterator : public exception {
	/* __________________________ */
	invalid_iterator() : exception("invalid_iterator"){}
	invalid_iterator(const invalid_iterator &other) : exception(other.message) {}
};

class container_is_empty : public exception {
	/* __________________________ */
	container_is_empty() : exception("invalid_iterator") {}
	container_is_empty(const container_is_empty &other) : exception(other.message) {}
};
}

#endif
