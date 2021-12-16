#include<iostream>
#include<cstdlib>
template<typename T>
class deque {
  public:
    static const size_t buffer_size = 1024;
    class deque_buffer;
	typedef deque_buffer* buffer_ptr;
	class const_iterator;
	class iterator {
    private:
		/**
		 * TODO add data members
		 *   just add whatever you want.
		 */
        buffer_ptr b_ptr;
        T* e_ptr;
	public:
		/**
		 * return a new iterator which pointer n-next elements
		 *   even if there are not enough elements, the behaviour is **undefined**.
		 * as well as operator-
		 */
        iterator(buffer_ptr __b_ptr, T* __e_ptr):b_ptr(__b_ptr), e_ptr(__e_ptr) {}
        iterator(const const_iterator &other):b_ptr(other.b_ptr), e_ptr(other.e_ptr) {}
        iterator(const iterator &other):b_ptr(other.b_ptr), e_ptr(other.e_ptr) {}
		iterator operator+(const int &n) const {
			//TODO
            b_ptr += n / buffer_size;
            e_ptr += n % buffer_size;
            if (e_ptr >= buffer_size) {
                ++b_ptr;
                e_ptr -= buffer_size;
            }
		}
		iterator operator-(const int &n) const {
			//TODO
            b_ptr -= n / buffer_size;
            e_ptr -= n % buffer_size;
            if (e_ptr < 0) {
                --b_ptr;
                e_ptr += buffer_size;
            }
		}
		// return th distance between two iterator,
		// if these two iterators points to different vectors, throw invaild_iterator.
		int operator-(const iterator &rhs) const {
			//TODO
			return (rhs.b_ptr - b_ptr)*buffer_size + rhs.e_ptr - e_ptr;
		}
		iterator operator+=(const int &n) {
			//TODO
			iterator result = *this;
			*this = (*this) + n;
			return result;
		}
		iterator operator-=(const int &n) {
			//TODO
			iterator result = *this;
			*this = (*this) - n;
			return result;
		}
		/**
		 * TODO iter++
		 */
		iterator operator++(int) {
		    (*this) = (*this) + 1;
            return (*this);
		}
		/**
		 * TODO ++iter
		 */
		iterator& operator++() {
            return (*this) + 1;
		}
		/**
		 * TODO iter--
		 */
		iterator operator--(int) {
            (*this) = (*this) - 1;
            return (*this);
		}
		/**
		 * TODO --iter
		 */
		iterator& operator--() {
            return (*this) - 1;
		}
		/**
		 * TODO *it
		 */
		T& operator*() const {
            return *(e_ptr);
		}
		/**
		 * TODO it->field
		 */
		T* operator->() const noexcept {
            return e_ptr;
		}
		/**
		 * a operator to check whether two iterators are same (pointing to the same memory).
		 */
		bool operator==(const iterator &rhs) const {
            return e_ptr == rhs.eptr && b_ptr == rhs.b_ptr;
		}
		bool operator==(const const_iterator &rhs) const {
            return e_ptr == rhs.eptr && b_ptr == rhs.b_ptr;
		}
		/**
		 * some other operator for iterator.
		 */
		bool operator!=(const iterator &rhs) const {
            return !(*this == rhs);
		}
		bool operator!=(const const_iterator &rhs) const {
            return !(*this == rhs);
		}
	};
	class const_iterator {
		// it should has similar member method as iterator.
		//  and it should be able to construct from an iterator.
		private:
		/**
		 * TODO add data members
		 *   just add whatever you want.
		 */
        buffer_ptr b_ptr;
        T* e_ptr;
	public:
		/**
		 * return a new iterator which pointer n-next elements
		 *   even if there are not enough elements, the behaviour is **undefined**.
		 * as well as operator-
		 */
        const_iterator(buffer_ptr __b_ptr, T* __e_ptr):b_ptr(__b_ptr), e_ptr(__e_ptr) {}
        const_iterator(const const_iterator &other):b_ptr(other.b_ptr), e_ptr(other.e_ptr) {}
        const_iterator(const iterator &other):b_ptr(other.b_ptr), e_ptr(other.e_ptr) {}

		const_iterator operator+(const int &n) const {
			//TODO
            b_ptr += n / buffer_size;
            e_ptr += n % buffer_size;
            if (e_ptr >= buffer_size) {
                ++b_ptr;
                e_ptr -= buffer_size;
            }
		}
		const_iterator operator-(const int &n) const {
			//TODO
            b_ptr -= n / buffer_size;
            e_ptr -= n % buffer_size;
            if (e_ptr < 0) {
                --b_ptr;
                e_ptr += buffer_size;
            }
		}
		// return th distance between two iterator,
		// if these two iterators points to different vectors, throw invaild_iterator.
		int operator-(const const_iterator &rhs) const {
			//TODO
			return (rhs.b_ptr - b_ptr)*buffer_size + rhs.e_ptr - e_ptr;
		}
		const_iterator operator+=(const int &n) {
			//TODO
			const_iterator result = *this;
			*this = (*this) + n;
			return result;
		}
		const_iterator operator-=(const int &n) {
			//TODO
			const_iterator result = *this;
			*this = (*this) - n;
			return result;
		}
		/**
		 * TODO iter++
		 */
		const_iterator operator++(int) {
		    (*this) = (*this) + 1;
            return (*this);
		}
		/**
		 * TODO ++iter
		 */
		const_iterator& operator++() {
            return (*this) + 1;
		}
		/**
		 * TODO iter--
		 */
		const_iterator operator--(int) {
            (*this) = (*this) - 1;
            return (*this);
		}
		/**
		 * TODO --iter
		 */
		const_iterator& operator--() {
            return (*this) - 1;
		}
		/**
		 * TODO *it
		 */
		T& operator*() const {
            return *(e_ptr);
		}
		/**
		 * TODO it->field
		 */
		T* operator->() const noexcept {
            return e_ptr;
		}
		/**
		 * a operator to check whether two iterators are same (pointing to the same memory).
		 */
		bool operator==(const iterator &rhs) const {
            return e_ptr == rhs.eptr && b_ptr == rhs.b_ptr;
		}
		bool operator==(const const_iterator &rhs) const {
            return e_ptr == rhs.eptr && b_ptr == rhs.b_ptr;
		}
		/**
		 * some other operator for iterator.
		 */
		bool operator!=(const iterator &rhs) const {
            return !(*this == rhs);
		}
		bool operator!=(const const_iterator &rhs) const {
            return !(*this == rhs);
		}
	};
	class deque_buffer{
	    public:
          T* data;
          int ptr;
          deque_buffer(int _ptr = 0):ptr(_ptr){
              data = (T*)malloc(buffer_size * sizeof(T));
          }
          deque_buffer(deque_buffer& other) {
              memcpy(data, other.data, sizeof(T) * buffer_size);
          }
          ~deque_buffer(){
              free(data);
          }
          bool push_back(const T& x) {
             data[ptr++] = x;
             return (ptr == buffer_size);
          }
          bool pop_back() {
            --ptr;
            return (ptr == -1);
          }
          bool push_front(const T& x) {
             data[--ptr] = x;
             return (ptr == 0);
          }
          bool pop_front() {
            ++ptr;
            return (ptr == buffer_size);
          }
	};

	buffer_ptr buffer_head;
    buffer_ptr buffer_tail;
    size_t  buffer_num;

	/**
	 * TODO Constructors
	 */
	deque():buffer_num(0), buffer_head(0), buffer_tail(0)  {}
	deque(const deque &other) {
        buffer_num = other.buffer_num;
        buffer_head = (buffer_ptr)malloc(buffer_num * sizeof(T*));
        buffer_tail = buffer_head + buffer_num;
        for (buffer_ptr ptr1 = buffer_head, ptr2 = other.buffer_head; ptr1 != buffer_tail; ++ptr1, ++ptr2) {
            ptr1 = new deque_buffer(*ptr2);
        }
	}
	/**
	 * TODO Deconstructor
	 */
	~deque() {
        for (buffer_ptr ptr = buffer_head; ptr != buffer_tail; ++ptr) {
            delete ptr;
        }
	}
	/**
	 * TODO assignment operator
	 */
	deque &operator=(const deque &other) {}
	/**
	 * access specified element with bounds checking
	 * throw index_out_of_bound if out of bound.
	 */
	T & at(const size_t &pos) {}
	const T & at(const size_t &pos) const {}
	T & operator[](const size_t &pos) {}
	const T & operator[](const size_t &pos) const {}
	/**
	 * access the first element
	 * throw container_is_empty when the container is empty.
	 */
	const T & front() const {}
	/**
	 * access the last element
	 * throw container_is_empty when the container is empty.
	 */
	const T & back() const {}
	/**
	 * returns an iterator to the beginning.
	 */
	iterator begin() {}
	const_iterator cbegin() const {}
	/**
	 * returns an iterator to the end.
	 */
	iterator end() {}
	const_iterator cend() const {}
	/**
	 * checks whether the container is empty.
	 */
	bool empty() const {}
	/**
	 * returns the number of elements
	 */
	size_t size() const {}
	/**
	 * clears the contents
	 */
	void clear() {}
	/**
	 * inserts elements at the specified locat on in the container.
	 * inserts value before pos
	 * returns an iterator pointing to the inserted value
	 *     throw if the iterator is invalid or it point to a wrong place.
	 */
	iterator insert(iterator pos, const T &value) {}
	/**
	 * removes specified element at pos.
	 * removes the element at pos.
	 * returns an iterator pointing to the following element, if pos pointing to the last element, end() will be returned.
	 * throw if the container is empty, the iterator is invalid or it points to a wrong place.
	 */
	iterator erase(iterator pos) {}
	/**
	 * adds an element to the end
	 */
	void push_back(const T &value) {}
	/**
	 * removes the last element
	 *     throw when the container is empty.
	 */
	void pop_back() {}
	/**
	 * inserts an element to the beginning.
	 */
	void push_front(const T &value) {}
	/**
	 * removes the first element.
	 *     throw when the container is empty.
	 */
	void pop_front() {}

};
int main() {

    return 0;
}
