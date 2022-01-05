#ifndef Vector_hpp
# define Vector_hpp

# include <memory> // std::allocator<T>

# include "../includes/ReverseIterator.hpp"

namespace ft {

template<bool B, class T, class U>
struct conditional {

};

template<class T, class U>
struct conditional<true, T, U> {
    typedef T type;
};

template<class T, class U>
struct conditional<false, T, U> {
    typedef U type;
};

template<class T, class Allocator = std::allocator<T> >
class Vector {

    public:
        template<bool IsConst>
        class RandomAccessIterator{
            public:
                typedef typename
                    ft::conditional<IsConst, const T, T>::type  value_type;
                typedef value_type*                             pointer;
                typedef value_type&                             reference;
                typedef std::ptrdiff_t                          difference_type;
                /* ********************************************************** */
                RandomAccessIterator() : ptr_(NULL) {};
                RandomAccessIterator(pointer ptr) : ptr_(ptr) {};
                RandomAccessIterator(const RandomAccessIterator& other) {
                    ptr_ = other.getPtr();
                };
                ~RandomAccessIterator() {};
                RandomAccessIterator& operator=(const RandomAccessIterator& other) {
                    if (this == &other) return *this;
                    ptr_ = other.getPtr();
                    return *this;
                }
                // effect:      const_iter = iter,
                // not effect:  iter = const_iter
                operator RandomAccessIterator<true>() const {
                    return ptr_;
                }
                pointer getPtr() const {
                    return (ptr_);
                }
                /* ********** LegacyInputIterator effects ******************* */
                /* LegacyInputIterator effects: "*iter" ********************* */
                reference operator*() const {
                    return *ptr_;
                }
                /* LegacyInputIterator effects: "iter->m" ******************* */
                pointer operator->(){
                    return ptr_;
                }
                /* LegacyInputIterator effects: "++iter" ******************** */
                RandomAccessIterator& operator++(){
                    ++ptr_;
                    return *this;
                }
                /* ********** LegacyForwardIterator effects ***************** */
                /* LegacyForwardIterator effects: "iter++" ****************** */
                RandomAccessIterator operator++(int){
                    RandomAccessIterator tmp(*this);
                    ptr_++;
                    return tmp;
                }
                /* ********** LegacyBidirectionalIterator effects *********** */
                /* LegacyBidirectionalIterator effects: "--iter" ************ */
                RandomAccessIterator& operator--(){
                    --ptr_;
                    return *this;
                }
                /* LegacyBidirectionalIterator effects: "iter--" ************ */
                RandomAccessIterator operator--(int){
                    RandomAccessIterator tmp(*this);
                    ptr_--;
                    return (tmp);
                }
                /* ********** LegacyRandomAccessIterator effects ************ */
                /* LegacyRandomAccessIterator effects: "iter+=" ************* */
                RandomAccessIterator& operator+=(int n) {
                    ptr_ += n;
                    return *this;
                }
                /* LegacyRandomAccessIterator effects: "iter-=" ************* */
                RandomAccessIterator& operator-=(int n) {
                    ptr_ -= n;
                    return *this;
                }
                /* LegacyRandomAccessIterator effects: "iter + n" *********** */
                RandomAccessIterator operator+(int n) {
                    return ptr_ + n;
                }
                 /* LegacyRandomAccessIterator effects: "iter - n" ********** */
                RandomAccessIterator operator-(int n) {
                    return ptr_ - n;
                }
                /* LegacyRandomAccessIterator effects: "iter[]" ************* */
                reference operator[](int n) {
                    return *(ptr_ + n);
                }

            private:
                pointer ptr_;
        };

        /* LegacyInputIterator effects: iter == iter ************************ */
        template <bool IsConst_l, bool IsConst_r>
        friend bool
                        operator==(const RandomAccessIterator<IsConst_l>& lhs,
                                   const RandomAccessIterator<IsConst_r>& rhs) {
            return lhs.getPtr() == rhs.getPtr();
        }
        /* LegacyInputIterator effects: iter != iter ************************ */
        template <bool IsConst_l, bool IsConst_r>
        friend bool
                        operator!=(const RandomAccessIterator<IsConst_l>& lhs,
                                   const RandomAccessIterator<IsConst_r>& rhs) {
            return lhs.getPtr() != rhs.getPtr();
        }
        /* LegacyRandomAccessIterator effects: "iter - iter" **************** */
        template <bool IsConst_l, bool IsConst_r>
        friend typename RandomAccessIterator<IsConst_l>::difference_type
                        operator-(const RandomAccessIterator<IsConst_l>& lhs,
                                  const RandomAccessIterator<IsConst_r>& rhs) {
            return lhs.getPtr() - rhs.getPtr();
        }
        /* LegacyRandomAccessIterator effects: "n + iter" ******************* */
        template <bool IsConst>
        friend RandomAccessIterator<IsConst>
                        operator+(int n,
                                  const RandomAccessIterator<IsConst>& rhs) {
            return n + rhs.getPtr();
        }
        /* LegacyRandomAccessIterator effects: "iter > iter" **************** */
        template <bool IsConst_l, bool IsConst_r>
        friend bool
                        operator>(const RandomAccessIterator<IsConst_l>& lhs,
                                  const RandomAccessIterator<IsConst_r>& rhs) {
            return lhs.getPtr() > rhs.getPtr();
        }
        /* LegacyRandomAccessIterator effects: "iter < iter" **************** */
        template <bool IsConst_l, bool IsConst_r>
        friend bool
                        operator<(const RandomAccessIterator<IsConst_l>& lhs,
                                  const RandomAccessIterator<IsConst_r>& rhs) {
            return lhs.getPtr() < rhs.getPtr();
        }
        /* LegacyRandomAccessIterator effects: "iter >= iter" *************** */
        template <bool IsConst_l, bool IsConst_r>
        friend bool
                        operator>=(const RandomAccessIterator<IsConst_l>& lhs,
                                   const RandomAccessIterator<IsConst_r>& rhs) {
            return lhs.getPtr() >= rhs.getPtr();
        }
        /* LegacyRandomAccessIterator effects: "iter <= iter" *************** */
        template <bool IsConst_l, bool IsConst_r>
        friend bool
                        operator<=(const RandomAccessIterator<IsConst_l>& lhs,
                                   const RandomAccessIterator<IsConst_r>& rhs) {
            return lhs.getPtr() <= rhs.getPtr();
        }

    public:
        typedef Allocator                           allocator_type;
        typedef T                                   value_type;
        typedef typename Allocator::pointer         pointer;
        typedef typename Allocator::const_pointer   const_pointer;
        typedef typename Allocator::reference       reference;
        typedef typename Allocator::const_reference const_reference;
        typedef typename Allocator::size_type       size_type;
        typedef typename Allocator::difference_type difference_type;

        typedef RandomAccessIterator<false>         iterator;
        typedef RandomAccessIterator<true>          const_iterator;
        typedef ReverseIterator<iterator>           reverse_iterator;
        typedef ReverseIterator<const_iterator>     const_reverse_iterator;

        /* * * * * * * * * * * * * * * * * * * */
        explicit Vector(const allocator_type& allctr_obj = allocator_type())
                            : begin_(NULL),
                            size_(0),
                            capacity_(0),
                            allocator_(allctr_obj) {}

        explicit Vector(size_type count,
                        const value_type& value = value_type(),
                        const allocator_type& allctr_obj = allocator_type())
                            : size_(count),
                            capacity_(count),
                            allocator_(allctr_obj){
            begin_ = allocator_.allocate(count);
            for (size_type i = 0; i < size_; ++i){
                allocator_.construct(begin_ + i, value); // FIXME: try catch
            }
        }

        template <class InputIt>
        Vector(InputIt first,
               InputIt last,
               const allocator_type& allctr_obj = allocator_type(),
               typename std::enable_if<!std::is_integral<InputIt>::value, bool>::type* = 0)
                    : allocator_(allctr_obj) {
            if (first > last) throw; // FIXME: my_exception
            size_ = static_cast<size_type>(last - first);
            begin_ = allocator_.allocate(size_);
            capacity_ = size_;
            for (size_type i = 0; i < size_; ++i){
                allocator_.construct(begin_ + i, *(first + i));
            }
        }

        Vector(const Vector& other){
            this->allocator_ = other.allocator_;
            this->begin_ = allocator_.allocate(other.capacity_);
            this->capacity_ = other.capacity_;
            for (size_type i = 0; i < other.size_; ++i){
                allocator_.construct(begin_ + i, *(other.begin_ + i)); // FIXME: try catch
            }
            this->size_ = other.size_;
        }

        Vector& operator=(const Vector& other) {
            if (this == &other) return *this;
            this->~Vector();
            this->allocator_ = other.allocator_;
            this->begin_ = allocator_.allocate(other.capacity_);
            this->capacity_ = other.capacity_;
            for (size_type i = 0; i < other.size_; ++i){
                allocator_.construct(begin_ + i, *(other.begin_ + i)); // FIXME: try catch
            }
            this->size_ = other.size_;
            return *this;
        }

        ~Vector(){
            if (begin_ == NULL) return;
            for (size_type i = 0; i < size_; ++i){
                allocator_.destroy(begin_ + i);
            }
            allocator_.deallocate(begin_, capacity_);
            capacity_ = 0;
            size_ = 0;
            begin_ = NULL;
        }

        void assign(size_type count, const value_type& value) {
            this->clear();
            this->reserve(count);
            for (size_type i = 0; i < count; ++i){
                allocator_.construct(begin_ + i, value);
            }
            size_ = count;
        }

        template<class InputIt>
        void assign(InputIt first,
                    InputIt last,
                    typename std::enable_if<!std::is_integral<InputIt>::value, bool>::type* = 0) {
            difference_type count = last - first;
            this->clear();
            this->reserve(count);
            for (size_type i = 0; i < count; ++i){
                allocator_.construct(begin_ + i, *(first + i));
            }
            size_ = count;
        }

        allocator_type get_allocator() const{
            return allocator_;
        }

        /* * * * * * Element access: * * * * * */
        reference at(size_type pos){
            if (pos > size_){
                throw std::out_of_range("std::out_of_range: vector");
            }
            return *(begin_ + pos);
        }

        const_reference at(size_type pos) const{
            if (pos > size_){
                throw std::out_of_range("std::out_of_range: vector");
            }
            return *(begin_ + pos);
        }

        reference operator[](size_type pos){
            return *(begin_ + pos);
        }

        const_reference operator[](size_type pos) const{
            return *(begin_ + pos);
        }

        reference front(){
            return *begin_;
        }

        const_reference front() const{
            return *begin_;
        }

        reference back(){
            return *(begin_ + size_ - 1);
        }

        const_reference back() const{
            return *(begin_ + size_ - 1);
        }

        /* * * * * * Iterators:* * * * * * * * */
        iterator begin(){
            return iterator(begin_);
        }

        iterator end(){
            return iterator(begin_ + size_);
        }

        const_iterator begin() const {
            return const_iterator(begin_);
        }

        const_iterator end() const {
            return const_iterator(begin_ + size_);
        }

        reverse_iterator rbegin() {
            if (size_ == 0) {
                return reverse_iterator(iterator(begin_));
            }
            return reverse_iterator(iterator(begin_ + size_ - 1));
        }

        reverse_iterator rend() {
            if (size_ == 0) {
                return reverse_iterator(iterator(begin_));
            }
            return reverse_iterator(iterator(begin_ - 1));
        }

        const_reverse_iterator rbegin() const {
            if (size_ == 0) {
                return const_reverse_iterator(begin_);
            }
            return const_reverse_iterator(begin_ + size_ - 1);
        }

        const_reverse_iterator rend() const {
            if (size_ == 0) {
                return reverse_iterator(iterator(begin_));
            }
            return reverse_iterator(iterator(begin_ - 1));
        }

        /* * * * * * Capacity: * * * * * * * * */
        bool empty() const{
            return (size_ == 0 ? true : false);
        }

        size_type size() const{
            return size_;
        }

        size_type max_size() const{
            return allocator_.max_size();
        }

        size_type capacity() const{
            return capacity_;
        }

        void reserve(size_type new_cap){
            if (new_cap <= capacity_) return;
            pointer newbegin = allocator_.allocate(new_cap);
            for (size_type i = 0; i < size_; ++i){
                allocator_.construct(newbegin + i, *begin_); // FIXME: try catch
            }
            for (size_type i = 0; i < size_; ++i){
                allocator_.destroy(begin_ + i);
            }
            allocator_.deallocate(begin_, capacity_);
            begin_ = newbegin;
            capacity_ = new_cap;
        }

        /* * * * * * Modifiers:  * * * * * * * */
        void resize(size_type count, value_type value = value_type()){
            if (count > size_){
                if (count > capacity_) {
                    reserve(capacity_ * 2 > count ? capacity_ * 2 : count);
                }
                for (size_type i = size_; i < count; ++i){
                    allocator_.construct(begin_ + i, value); // FIXME: try catch
                }
                size_ = count;
            }
            if (count < size_){
                for (size_type i = count; i < size_; ++i){
                    allocator_.destroy(begin_ + i);
                }
                size_ = count;
            }
        }

        void push_back(const T& value){
            if (capacity_ == size_){
                reserve(capacity_ == 0 ? 1 : 2 * size_);
            }
            allocator_.construct(begin_ + size_, value); // FIXME: try catch
            size_++;
        }

        void pop_back(){
            allocator_.destroy(begin_ + (size_ - 1));
            size_--;
        }

        void clear(){
            if (begin_ == NULL) return;
            for (size_type i = 0; i < size_; ++i){
                allocator_.destroy(begin_ + i);
            }
            size_ = 0;
        }

        void swap(Vector& other){
            std::swap(this->begin_, other.begin_);
            std::swap(this->size_, other.size_);
            std::swap(this->capacity_, other.capacity_);
            std::swap(this->allocator_, other.allocator_);
        }

        iterator insert(iterator pos, const value_type& value) {
            if (pos < begin() || pos >= end()) throw; // FIXME: my_exception
            difference_type start = pos - begin();
            insert(pos, 1, value);
            return iterator(begin_ + start);
        }

        void insert( iterator pos, size_type count, const T& value ) {
            if (pos < begin() || pos >= end()) return;
            difference_type start = pos - begin();
            if (size_ + count > capacity_) {
                if (capacity_ <= size_) {
                    reserve(capacity_ == 0 ? 1 : 2 * size_);
                }
                reserve(size_ + count);
            }
            for (size_type i = 0; i < count; ++i) {
                allocator_.construct(begin_ + size_ + i, value);
            }
            for (int i = size_ - 1; i >= start && i >= 0; --i){
                begin_[i + count] = begin_[i];
            }
            for (size_type i = start ; i < start + count ; ++i) {
                begin_[i] = value;
            }
            size_ += count;
        }

        template<class InputIt>
        void insert(iterator pos,
                    InputIt first,
                    InputIt last,
                    typename std::enable_if<!std::is_integral<InputIt>::value, bool>::type* = 0) {
            if (pos < begin() || pos >= end()) return;
            difference_type start = pos - begin();
            difference_type count = last - first;
            if (count < 0) return;
            if (size_ + count > capacity_){
                if (capacity_ <= size_) {
                    reserve(capacity_ == 0 ? 1 : 2 * size_);
                }
                reserve(size_ + count);
            }
            for (size_type i = 0; i < count; ++i){
                allocator_.construct(begin_ + size_ + i, *(first + i));
            }
            for (int i = size_ - 1; i >= start && i >= 0; --i){
                begin_[i + count] = begin_[i];
            }
            for (size_type i = start ; i < start + count ; ++i) {
                begin_[i] = *(first + i);
            }
            size_ += count;
            return;
        }

        iterator erase(iterator pos) {
            if (pos < begin() || pos >= end()) throw; // FIXME: my_exception
            difference_type start = pos - begin();
            Vector tmp(++pos, end());
            for (size_type i = size_; i > start; --i){
                pop_back();
            }
            for (iterator iter = tmp.begin(); iter != tmp.end(); ++iter){
                push_back(*iter);
            }
            return iterator(begin_ + start);
        }

        iterator erase(iterator first, iterator last) {
            difference_type count = last - first;
            if (count < 0) throw; // FIXME: my_exception
            difference_type start = begin() - first;
            Vector tmp1(begin() + start, begin() + count);
            Vector tmp2(begin() + count, end());

            for (size_type i = size_; i > start; --i){
                pop_back();
            }
            for (iterator iter = tmp1.begin(); iter != tmp1.end(); ++iter){
                push_back(*iter);
            }
            for (iterator iter = tmp2.begin(); iter != tmp2.end(); ++iter){
                push_back(*iter);
            }
            return iterator(begin_ + start);
        }

        /* * * * * * Non-member functions:  * * * * * */
        friend std::ostream& operator<<(std::ostream& os, const Vector<T, Allocator>& v){
            os << "\033[34m";
            os << "size = " << v.size_ << std::endl;
            os << "capacity_ = " << v.capacity_ << std::endl;
            for (size_t i = 0; i < v.size_; ++i){
                std::cout << "arr[" << i << "] = " << *(v.begin_ + i) << std::endl;
            }
            os << "\033[0m";
            return os;
        }

    private:
        pointer         begin_;
        size_type       size_;
        size_type       capacity_;
        allocator_type  allocator_;
};

/* * * * * * Non-member functions:  * * * * * */

template<class T, class Allocator>
bool operator==(const std::vector<T,Allocator>& lhs,
                const std::vector<T,Allocator>& rhs){
    return (lhs.size() == rhs.size()
            && std::equal( lhs.begin(), lhs.end(), rhs.begin() ));
}

template<class T, class Allocator>
bool operator!=(const std::vector<T,Allocator>& lhs,
                const std::vector<T,Allocator>& rhs){
    return !(lhs == rhs);
}

template<class T, class Allocator>
bool operator<(const std::vector<T,Allocator>& lhs,
               const std::vector<T,Allocator>& rhs){
    return std::lexicographical_compare(lhs.begin(), lhs.end(),
                                        rhs.begin(), rhs.end());
}

template<class T, class Allocator>
bool operator<=(const std::vector<T,Allocator>& lhs,
                const std::vector<T,Allocator>& rhs){
    return !(lhs > rhs);
}

template<class T, class Allocator>
bool operator>(const std::vector<T,Allocator>& lhs,
               const std::vector<T,Allocator>& rhs){
    return !std::lexicographical_compare(lhs.begin(), lhs.end(),
                                         rhs.begin(), rhs.end());
}

template<class T, class Allocator>
bool operator>=(const std::vector<T,Allocator>& lhs,
                const std::vector<T,Allocator>& rhs){
    return !(lhs < rhs);
}

}  // namespace ft

#endif