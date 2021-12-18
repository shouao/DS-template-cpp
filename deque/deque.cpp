#include<iostream>
#include<cstdlib>
#include<cstdio>

namespace csa{
template<typename T>
class deque {
  public:
    static const size_t buffer_size = 4;

    class deque_buffer;
	class iterator;
	class const_iterator;

	typedef deque_buffer* buffer_ptr;

	class iterator {
    public:
		/**
		 * TODO add data members
		 *   just add whatever you want.
		 */
        buffer_ptr b_ptr;
        int cur;
        void set_node(buffer_ptr new_node) {
            b_ptr = new_node;
        }

		/**
		 * return a new iterator which pointer n-next elements
		 *   even if there are not enough elements, the behaviour is **undefined**.
		 * as well as operator-
		 */
        iterator(){}
        iterator(buffer_ptr _b_ptr, int _cur): b_ptr(_b_ptr), cur(_cur) {}
        iterator(const const_iterator &other): b_ptr(other.b_ptr), cur(other.cur) {}
        iterator(const iterator &other): b_ptr(other.b_ptr), cur(other.cur) {}
        iterator operator+=(const int &n) {
			//TODO
			int offset = n + cur;
			if (offset >= 0 && offset < buffer_size) {
                cur += n;
			} else {
                if (offset > 0) {
                    int buffer_offset = offset / buffer_size;
                    set_node(b_ptr + buffer_offset);
                    cur = offset - buffer_offset * buffer_size;
                } else {
                    int buffer_offset = -((-offset + 3) / buffer_size);
                    set_node(b_ptr + buffer_offset);
                    cur = offset - buffer_offset * buffer_size;
                }
			}
			return *this;
		}
		iterator operator-=(const int &n) {
			//TODO
			return (*this) += (-n);
		}
		iterator operator+(const int &n) const {
			//TODO
			return iterator(*this) += n;
		}
		iterator operator-(const int &n) const {
			//TODO
            return iterator(*this) -= n;
		}
		// return th distance between two iterator,
		// if these two iterators points to different vectors, throw invaild_iterator.
		int operator-(const iterator &rhs) const {
			//TODO
			return (b_ptr - rhs.b_ptr) * buffer_size + (cur - b_ptr -> begin_ptr) - (rhs.cur - b_ptr -> begin_ptr);
		}
		/**
		 * TODO iter++
		 */
		iterator operator++(T) {
		    iterator tmp = *this;
		    (*this) += 1;
            return tmp;
		}
		/**
		 * TODO ++iter
		 */
		iterator& operator++() {
            (*this) += 1;
            return (*this);
		}
		/**
		 * TODO iter--
		 */
		iterator operator--(T) {
		    iterator tmp = *this;
            (*this) -= 1;
            return tmp;
		}
		/**
		 * TODO --iter
		 */
		iterator& operator--() {
            (*this) -= 1;
            return (*this);
		}
		/**
		 * TODO *it
		 */
		T& operator*() const {
            return b_ptr -> data[cur];
		}
		/**
		 * TODO it->field
		 */
		T* operator->() const noexcept {
            return &(b_ptr -> data[cur]);
		}
		/**
		 * a operator to check whether two iterators are same (pointing to the same memory).
		 */
		bool operator==(const iterator &rhs) const {
            return b_ptr == rhs.bptr && cur == rhs.cur;
		}
		bool operator==(const const_iterator &rhs) const {
            return b_ptr == rhs.bptr && cur == rhs.cur;
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
        int cur;
        void set_node(buffer_ptr new_node) {
            b_ptr = new_node;
        }
	public:
		/**
		 * return a new iterator which pointer n-next elements
		 *   even if there are not enough elements, the behaviour is **undefined**.
		 * as well as operator-
		 */
        const_iterator(){}
        const_iterator(buffer_ptr _b_ptr, int _cur): b_ptr(_b_ptr), cur(_cur) {}
        const_iterator(const const_iterator &other): b_ptr(other.b_ptr), cur(other.cur) {}
        const_iterator(const iterator &other): b_ptr(other.b_ptr), cur(other.cur) {}
        const_iterator operator+=(const int &n) {
			//TODO
			int offset = n + cur - b_ptr -> begin_ptr;
			if (offset >= 0 && offset < buffer_size) {
                cur += n;

			} else {
                int buffer_offset =
                    offset > 0 ? offset / buffer_size
                        : -((-offset - 1) / buffer_size) - 1;
                set_node(b_ptr + buffer_offset);
                cur = b_ptr -> begin_ptr + offset - buffer_offset * buffer_size;
			}
			return *this;
		}
		const_iterator operator-=(const int &n) {
			//TODO
			return (*this) += (-n);
		}
		const_iterator operator+(const int &n) const {
			//TODO
			return iterator(*this) += n;
		}
		const_iterator operator-(const int &n) const {
			//TODO
            return iterator(*this) -= n;
		}
		// return th distance between two iterator,
		// if these two iterators points to different vectors, throw invaild_iterator.
		int operator-(const iterator &rhs) const {
			//TODO
			return (b_ptr - rhs.b_ptr) * buffer_size + (cur - b_ptr -> begin_ptr) - (rhs.cur - b_ptr -> begin_ptr);
		}
		/**
		 * TODO iter++
		 */
		const_iterator operator++(T) {
		    const_iterator tmp = *this;
		    (*this) += 1;
            return tmp;
		}
		/**
		 * TODO ++iter
		 */
		const_iterator& operator++() {
            (*this) += 1;
            return (*this);
		}
		/**
		 * TODO iter--
		 */
		const_iterator operator--(T) {
		    const_iterator tmp = *this;
            (*this) -= 1;
            return tmp;
		}
		/**
		 * TODO --iter
		 */
		const_iterator& operator--() {
            (*this) -= 1;
            return (*this);
		}
		/**
		 * TODO *it
		 */
		T operator*() const {
            return b_ptr -> data[cur];
		}
		/**
		 * TODO it->field
		 */
		T* operator->() const noexcept {
            return &(b_ptr -> data[cur]);
		}
		/**
		 * a operator to check whether two iterators are same (pointing to the same memory).
		 */
		bool operator==(const iterator &rhs) const {
            return b_ptr == rhs.bptr && cur == rhs.cur;
		}
		bool operator==(const const_iterator &rhs) const {
            return b_ptr == rhs.bptr && cur == rhs.cur;
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
              int begin_ptr;
              int end_ptr;
              deque_buffer(int _begin_ptr = 0, int _end_ptr = 0):begin_ptr(_begin_ptr), end_ptr(_end_ptr){
                  data = new T[buffer_size];
              }
              deque_buffer(deque_buffer& other):begin_ptr(other.begin_ptr), end_ptr(other.end_ptr) {
                    data = new T[buffer_size];
                    for (int i = begin_ptr; i != end_ptr; ++i) {
                        data[i] = T(other.data[i]);
                    }
              }
              deque_buffer &operator=(const deque_buffer &other) {
                    if (this == &other) {
                        return (*this);
                    }
                    delete[] data;
                    begin_ptr = other.begin_ptr;
                    end_ptr = other.end_ptr;
                    data = new T[buffer_size];
                    for (int i = begin_ptr; i != end_ptr; ++i) {
                        data[i] = T(other.data[i]);
                    }
              }
              ~deque_buffer(){
                  delete[] data;
              }
              void push_back(const T& x) {
                 data[end_ptr++] = x;
              }
              void pop_back() {
                --end_ptr;
                destroy(data[end_ptr]);
              }
              void push_front(const T& x) {
                 data[--begin_ptr] = x;
              }
              void pop_front() {
                destroy(data[begin_ptr]);
                ++begin_ptr;
              }
    };
	buffer_ptr buffer;
	size_t buffer_num;
    size_t _size;
    iterator start;
    iterator finish;

	/**
	 * TODO Constructors
	 */
	deque():_size(0), buffer_num(3){
        buffer = new deque_buffer[buffer_num];
        buffer[0] = deque_buffer(buffer_size, buffer_size);
        buffer[1] = deque_buffer(buffer_size / 2, buffer_size / 2);
        buffer[2] = deque_buffer(0, 0);
        start = iterator(buffer + 1, (buffer + 1) -> begin_ptr);
        finish = start;
	}
	deque(const deque &other):_size(other._size), buffer_num(other.buffer_num) {
        buffer_num = other.buffer_num;
        _size = other._size;
        buffer = new deque_buffer[buffer_num];
        for (int i = 0; i < buffer_num; ++i) {
            buffer[i] = deque_buffer(other.buffer[i]);
        }
        start = iterator(buffer + other.start - other.buffer, other.start.cur);
        finish = start + _size;
	}
	/**
	 * TODO Deconstructor
	 */
	~deque() {
        delete[] buffer;
	}
	/**
	 * TODO assignment operator
	 */
	deque &operator=(const deque &other) {
        if (this == &other) {
            return (*this);
        }
        delete[] buffer;
        buffer_num = other.buffer_num;
        _size = other._size;
        buffer = new deque_buffer[buffer_num];
        for (int i = 0; i < buffer_num; ++i) {
            buffer[i] = deque_buffer(other.buffer[i]);
        }
        start = iterator(buffer + other.start - other.buffer, other.start.cur);
        finish = start + _size;
	}
	/**
	 * access specified element with bounds checking
	 * throw index_out_of_bound if out of bound.
	 */
	T & at(const size_t &pos) throw(const std::string) {
        if (pos < 0 || pos >= _size) {
            throw "index_out_of_bound";
        }
        return *(start + pos);
	}
	const T & at(const size_t &pos) const {
        return at(pos);
	}
	T & operator[](const size_t &pos) {
        return *(start + pos);
	}
	const T & operator[](const size_t &pos) const {
        return *(start + pos);
	}
	/**
	 * access the first element
	 * throw container_is_empty when the container is empty.
	 */
	const T & front() const {
        return *start;
	}
	/**
	 * access the last element
	 * throw container_is_empty when the container is empty.
	 */
	const T & back() const {
        return *(finish - 1);
	}
	/**
	 * returns an iterator to the beginning.
	 */
	iterator begin() {
        return start;
	}
	const_iterator cbegin() const {
        return const_iterator(start);
	}
	/**
	 * returns an iterator to the end.
	 */
	iterator end() {
        return finish;
	}
	const_iterator cend() const {
        return const_iterator(finish);
	}
	/**
	 * checks whether the container is empty.
	 */
	bool empty() const {
        return _size == 0;
	}
	/**
	 * returns the number of elements
	 */
	size_t size() const {
        return _size;
	}
	/**
	 * clears the contents
	 */
	void clear() {
        delete[] buffer;
        _size = 0;
        buffer_num = 1;
        buffer = new deque_buffer;
        start = iterator(buffer, buffer -> begin_ptr);
        finish = iterator(buffer, buffer -> end_ptr);
	}
	/**
	 * inserts elements at the specified locat on in the container.
	 * inserts value before pos
	 * returns an iterator pointing to the inserted value
	 *     throw if the iterator is invalid or it point to a wrong place.
	 */

	void push_back(const T &value) {
        finish.b_ptr -> push_back(value);
        ++finish;
        ++_size;
        if (finish.b_ptr - buffer == buffer_num - 1) {
            buffer_ptr new_buffer = new deque_buffer[buffer_num * 3];

            for (int i = 0; i < buffer_num; ++i) {
                new_buffer[i] = deque_buffer(buffer_size, buffer_size);
                new_buffer[i + buffer_num] = deque_buffer(buffer[i]);
                new_buffer[i + 2 * buffer_num] = deque_buffer(0, 0);
            }

            start.b_ptr = start.b_ptr - buffer + buffer_num + new_buffer;
            finish.b_ptr = finish.b_ptr - buffer + buffer_num + new_buffer;

            delete[] buffer;
            buffer = new_buffer;
            buffer_num *= 3;
        }

	}
	/**
	 * removes the last element
	 *     throw when the container is empty.
	 */
	void pop_back() {
	    finish.b_ptr -> pop_back();
        --_size;
        --finish;
	}
	/**
	 * inserts an element to the beginning.
	 */
	void push_front(const T &value) {
	    --start;
        ++_size;
        start.b_ptr -> push_front(value);
        if (start.b_ptr == buffer) {
            buffer_ptr new_buffer = new deque_buffer[buffer_num * 3];

            for (int i = 0; i < buffer_num; ++i) {
                new_buffer[i] = deque_buffer(buffer_size, buffer_size);
                new_buffer[i + buffer_num] = deque_buffer(buffer[i]);
                new_buffer[i + 2 * buffer_num] = deque_buffer(0, 0);
            }

            delete[] buffer;
            start.b_ptr = start.b_ptr - buffer + buffer_num + new_buffer;
            finish.b_ptr = finish.b_ptr - buffer + buffer_num + new_buffer;
            buffer = new_buffer;
            buffer_num *= 3;
        }

	}
	/**
	 * removes the first element.
	 *     throw when the container is empty.
	 */
	void pop_front() {
        start.b_ptr -> pop_front();
        --_size;
        ++start;
	}
	/**
	 * removes specified element at pos.
	 * removes the element at pos.
	 * returns an iterator pointing to the following element, if pos pointing to the last element, end() will be returned.
	 * throw if the container is empty, the iterator is invalid or it points to a wrong place.
	 */
	iterator erase(iterator pos) {
	    if (pos - start < finish - pos) {
            for (iterator it = pos; it != start + 1; --it) {
                swap(*it, *(it - 1));
            }
            pop_front();
	    } else{
            for (iterator it = pos; it != finish - 1; ++it) {
                swap(*it, *(it + 1));
            }
            pop_back();
	    }
	}
	/**
	 * adds an element to the end
	 */
	iterator insert(iterator pos, const T &value) {
        if (pos - start < finish - pos) {
            push_front(value);
            for (iterator it = start; it != pos; --it) {
                swap(*it, *(it + 1));
            }
	    } else{
	        push_back(value);
            for (iterator it = finish; it != pos; ++it) {
                swap(*it, *(it - 1));
            }
	    }
	}

};
}
int main() {
    csa::deque<int>q;
    for (int i = 0; i < 15; ++i) {
        q.push_front(i);
        q.push_back(i);
    }
    for (int i = 0; i < 30; ++i) {
        printf("%d\n", q[i]);
    }
    return 0;
}
