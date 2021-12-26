#ifndef Vector_hpp
# define Vector_hpp

# include <memory> // std::allocator<T>

namespace ft {

template<class T, class Allocator = std::allocator<T> >
class Vector
{
    public:
        typedef Allocator                           allocator_type;
        typedef typename Allocator::value_type      value_type;
        typedef typename Allocator::pointer         pointer;
        typedef typename Allocator::const_pointer   const_pointer;
        typedef typename Allocator::reference       reference;
        typedef typename Allocator::const_reference const_reference;
        typedef typename Allocator::size_type       size_type;
        // typedef typename Allocator::difference_type difference_type;

        // typedef RandomAccessIterator<value_type>        iterator;
        // typedef RandomAccessIterator<const value_type>  const_iterator;
        // typedef ReverseIterator<iterator>               reverse_iterator;
        // typedef ReverseIterator<const_iterator>         const_reverse_iterator;
        typedef typename std::vector<value_type>::iterator               iterator;
        typedef typename std::vector<value_type>::const_iterator         const_iterator;
        typedef typename std::vector<value_type>::reverse_iterator       reverse_iterator;
        typedef typename std::vector<value_type>::const_reverse_iterator const_reverse_iterator;

        /* * * * * * * * * * * * * * * * * * * */
        explicit Vector(const allocator_type& allctr_obj = allocator_type())
            : begin_(NULL), size_(), capacity_(0), allocator_(allctr_obj)
        {
            
        }

        explicit Vector(size_type count,
                        const value_type& value = value_type(),
                        const allocator_type& allctr_obj = allocator_type())
            : size_(count), capacity_(count), allocator_(allctr_obj) 
        {
            begin_ = allocator_.allocate(count);
            for (size_type i = 0; i < size_; ++i){
                allocator_.construct(begin_ + i, value); // FIXME: try catch
            }
        }

        ~Vector()
        {
            if (begin_ == NULL) return ;
            for (size_type i = 0; i < size_; ++i){
                allocator_.destroy(begin_ + i);
            }
            allocator_.deallocate(begin_, capacity_);
            capacity_ = 0;
            size_ = 0;
            begin_ = NULL;
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

        void reserve(size_type new_cap)
        {
            if (new_cap <= capacity_) return ;
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

        void resize(size_type count, value_type value = value_type())
        {
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

        void push_back(const T& value)
        {
            if (capacity_ == size_){
                reserve(capacity_ == 0 ? 1 : 2 * size_);
            }
            allocator_.construct(begin_ + size_, value); // FIXME: try catch
            size_++;
        }

        void pop_back()
        {
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

        /* * * * * * Non-member functions:  * * * * * */
        friend std::ostream& operator<<(std::ostream& os, const Vector<T, Allocator>& v)
        {
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

}  // namespace ft

#endif