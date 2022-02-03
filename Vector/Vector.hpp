#ifndef _FT_VECTOR_
# define _FT_VECTOR_

# include <memory> // std::allocator<T>

# include "../includes/ReverseIterator.hpp"
# include "../includes/conditional.hpp"
# include "../includes/lexicographical_compare.hpp"
# include "../includes/equal.hpp"
# include "../includes/enable_if.hpp"

namespace ft {

///////////////////// Class Vector: ////////////////////////////////////////////
template<class T, class Allocator = std::allocator<T> >
class vector {

    public:
        ///////////// Typedef part 1 (without iterators): //////////////////////
        typedef Allocator                           allocator_type;
        typedef T                                   value_type;
        typedef typename Allocator::pointer         pointer;
        typedef typename Allocator::const_pointer   const_pointer;
        typedef typename Allocator::reference       reference;
        typedef typename Allocator::const_reference const_reference;
        typedef typename Allocator::size_type       size_type;
        typedef typename Allocator::difference_type difference_type;

    public:
        ///////////// Iterators: ///////////////////////////////////////////////
        template<bool IsConst>
        class RandomAccessIterator{
            public:
                typedef typename
                   ft::conditional<IsConst, const T, T>::type value_type;
                typedef value_type*                           pointer;
                typedef value_type&                           reference;
                typedef std::ptrdiff_t                        difference_type;
                typedef	std::random_access_iterator_tag       iterator_category;
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
                    return ptr_;
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
                    return tmp;
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
        ///////////// Typedef part 2 (iterators): //////////////////////////////
        typedef RandomAccessIterator<false>         iterator;
        typedef RandomAccessIterator<true>          const_iterator;
        typedef ReverseIterator<iterator>           reverse_iterator;
        typedef ReverseIterator<const_iterator>     const_reverse_iterator;

        ///////////// Constructor(s) / Destructor / Operator=: /////////////////
        explicit vector(const allocator_type& allctr_obj = allocator_type())
                            : begin_(NULL),
                            size_(0),
                            capacity_(0),
                            allocator_(allctr_obj) {}

        explicit vector(size_type count,
                        const value_type& value = value_type(),
                        const allocator_type& allctr_obj = allocator_type())
                            : size_(count),
                            capacity_(count),
                            allocator_(allctr_obj){
            try {
                begin_ = allocator_.allocate(count);
            } catch (std::exception ex) {
                allocator_.deallocate(begin_, capacity_);
                capacity_ = 0;
                size_ = 0;
                begin_ = NULL;
                throw ;
            }
            for (size_type i = 0; i < size_; ++i){
                allocator_.construct(begin_ + i, value);
            }
        }

        template <class InputIt>
        vector(InputIt first,
               InputIt last,
               const allocator_type& allctr_obj = allocator_type(),
               typename ft::enable_if<!ft::is_integral<InputIt>::value, bool>::type* = 0)
                    : allocator_(allctr_obj) {
            // if (first > last) throw;
            size_ = static_cast<size_type>(last - first);
            try {
                begin_ = allocator_.allocate(size_);
            } catch (std::exception ex) {
                allocator_.deallocate(begin_, capacity_);
                capacity_ = 0;
                size_ = 0;
                begin_ = NULL;
                throw ;
            }
            capacity_ = size_;
            for (size_type i = 0; i < size_; ++i){
                allocator_.construct(begin_ + i, *(first + i));
            }
        }

        vector(const vector& other){
            this->allocator_ = other.allocator_;
            this->begin_ = allocator_.allocate(other.capacity_);
            this->capacity_ = other.capacity_;
            for (size_type i = 0; i < other.size_; ++i){
                allocator_.construct(begin_ + i, *(other.begin_ + i));
            }
            this->size_ = other.size_;
        }

        vector& operator=(const vector& other) {
            if (this == &other) return *this;
            this->~vector();
            this->allocator_ = other.allocator_;
            this->begin_ = allocator_.allocate(other.capacity_);
            this->capacity_ = other.capacity_;
            for (size_type i = 0; i < other.size_; ++i){
                allocator_.construct(begin_ + i, *(other.begin_ + i));
            }
            this->size_ = other.size_;
            return *this;
        }

        ~vector(){
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
                    typename ft::enable_if<!ft::is_integral<InputIt>::value, bool>::type* = 0) {
            difference_type count = last - first;
            this->clear();
            this->reserve(count);
            for (size_type i = 0; i < static_cast<size_type>(count); ++i){
                allocator_.construct(begin_ + i, *(first + i));
            }
            size_ = count;
        }

        allocator_type get_allocator() const{
            return this->allocator_;
        }

        ///////////// Element access: //////////////////////////////////////////
        reference at(size_type pos){
            if (pos >= size_){
                throw std::out_of_range("vector");
            }
            return *(begin_ + pos);
        }

        const_reference at(size_type pos) const{
            if (pos > size_){
                throw std::out_of_range("vector");
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

        ///////////// Iterators: ///////////////////////////////////////////////
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
                return const_reverse_iterator(iterator(begin_));
            }
            return const_reverse_iterator(iterator(begin_ - 1));
        }

        ///////////// Capacity: ////////////////////////////////////////////////
        bool empty() const{
            return size_ == 0;
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
                allocator_.construct(newbegin + i, *(begin_ + i));
            }
            for (size_type i = 0; i < size_; ++i){
                allocator_.destroy(begin_ + i);
            }
            allocator_.deallocate(begin_, capacity_);
            begin_ = newbegin;
            capacity_ = new_cap;
        }

        ///////////// Modifiers: ///////////////////////////////////////////////
        void resize(size_type count, value_type value = value_type()){
            if (count > size_){
                if (count > capacity_) {
                    reserve(capacity_ * 2 > count ? capacity_ * 2 : count);
                }
                for (size_type i = size_; i < count; ++i){
                    allocator_.construct(begin_ + i, value);
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
            allocator_.construct(begin_ + size_, value);
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

        void swap(vector& other){
            std::swap(this->begin_, other.begin_);
            std::swap(this->size_, other.size_);
            std::swap(this->capacity_, other.capacity_);
            std::swap(this->allocator_, other.allocator_);
        }

        iterator insert(iterator pos, const value_type& value) {
            // if (pos < begin() || pos > end()) throw;
            difference_type start = pos - begin();
            insert(pos, 1, value);
            return iterator(begin_ + start);
        }

        void insert(iterator pos, size_type count, const T& value) {
            if (pos < begin() || pos > end()) return;
            difference_type start = pos - begin();
            if (size_ + count > capacity_) {
                if (capacity_ <= size_) {
                    reserve(capacity_ == 0 ? 1 : 2 * size_);
                }
                reserve(size_ + count);
            }
            for (size_type i = 0; i < static_cast<size_type>(count); ++i) {
                allocator_.construct(begin_ + size_ + i, value);
            }
            for (int i = size_ - 1; i >= static_cast<int>(start) && i >= 0; --i){
                begin_[i + count] = begin_[i];
            }
            for (size_type i = start ; i < static_cast<size_type>(start + count) ; ++i) {
                begin_[i] = value;
            }
            size_ += count;
        }

        template<class InputIt>
        void insert(iterator pos,
                    InputIt first,
                    InputIt last,
                    typename ft::enable_if<!ft::is_integral<InputIt>::value, bool>::type* = 0) {
            if (pos < begin() || pos > end()) return;
            difference_type start = pos - begin();
            difference_type count = last - first;
            if (count < 0) return;
            if (size_ + count > capacity_){
                if (capacity_ <= size_) {
                    reserve(capacity_ == 0 ? 1 : 2 * size_);
                }
                reserve(size_ + count);
            }
            for (size_type i = 0; i < static_cast<size_type>(count); ++i){
                allocator_.construct(begin_ + size_ + i, *(first + i));
            }
            for (int i = size_ - 1; i >= static_cast<int>(start) && i >= 0; --i){
                begin_[i + count] = begin_[i];
            }
            for (size_type i = start ; i < static_cast<size_type>(start + count) ; ++i) {
                begin_[i] = *first++;
            }
            size_ += count;
        }

        iterator erase(iterator pos) {
            // if (pos < begin() || pos > end()) throw;
            difference_type start = pos - begin();
            vector tmp(++pos, end());
            for (size_type i = size_; i > static_cast<size_type>(start); --i){
                pop_back();
            }
            for (iterator iter = tmp.begin(); iter != tmp.end(); ++iter){
                push_back(*iter);
            }
            return iterator(begin_ + start);
        }

        iterator erase(iterator first, iterator last) {
            // if (first > last) throw;
            for (iterator iter = first; iter != last; ++iter){
                erase(first);
            }
            return first;
        }

        // friend std::ostream& operator<<(std::ostream& os, const vector<T, Allocator>& v){
        //     os << "\033[34m";
        //     os << "size = " << v.size_ << std::endl;
        //     os << "capacity_ = " << v.capacity_ << std::endl;
        //     for (size_t i = 0; i < v.size_; ++i){
        //         std::cout << "arr[" << i << "] = " << *(v.begin_ + i) << std::endl;
        //     }
        //     os << "\033[0m";
        //     return os;
        // }

    private:
        ///////////// Data fields: /////////////////////////////////////////////
        pointer         begin_;
        size_type       size_;
        size_type       capacity_;
        allocator_type  allocator_;
};

////////////////// Non-member functions: ///////////////////////////////////////
template<class T, class Allocator>
bool operator==(const ft::vector<T,Allocator>& lhs,
                const ft::vector<T,Allocator>& rhs){
    return (lhs.size() == rhs.size()
            && ft::equal( lhs.begin(), lhs.end(), rhs.begin() ));
}

template<class T, class Allocator>
bool operator!=(const ft::vector<T,Allocator>& lhs,
                const ft::vector<T,Allocator>& rhs){
    return !(lhs == rhs);
}

template<class T, class Allocator>
bool operator<(const ft::vector<T,Allocator>& lhs,
               const ft::vector<T,Allocator>& rhs){
    return ft::lexicographical_compare(lhs.begin(), lhs.end(),
                                        rhs.begin(), rhs.end());
}

template<class T, class Allocator>
bool operator<=(const ft::vector<T,Allocator>& lhs,
                const ft::vector<T,Allocator>& rhs){
    return !(lhs > rhs);
}

template<class T, class Allocator>
bool operator>(const ft::vector<T,Allocator>& lhs,
               const ft::vector<T,Allocator>& rhs){
    return !ft::lexicographical_compare(lhs.begin(), lhs.end(),
                                         rhs.begin(), rhs.end());
}

template<class T, class Allocator>
bool operator>=(const ft::vector<T,Allocator>& lhs,
                const ft::vector<T,Allocator>& rhs){
    return !(lhs < rhs);
}

}  // namespace ft

#endif // _FT_VECTOR_