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
                allocator_.construct(begin_ + i, value);
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

        /* * * * * * Capacity: * * * * * * * * */

        void reserve(size_type new_cap)
        {
            if (new_cap < capacity_) return ;
            pointer newbegin = allocator_.allocate(new_cap);
            
            try
            {
                for (size_type i = 0; i < size_; ++i){
                    allocator_.construct(newbegin + i, *begin_);
                }
            }
            catch(const std::exception& e)
            {
                // std::cerr << e.what() << '\n';
                allocator_.deallocate(newbegin); // its not correct i think;
            }
            

            for (size_type i = 0; i < size_; ++i){
                allocator_.destroy(begin_ + i);
            }
            allocator_.deallocate(begin_, capacity_);
            begin_ = newbegin;
            capacity_ = new_cap;
        }

        /* * * * * * Modifiers:  * * * * * * * */

    private:
        pointer         begin_;
        size_type       size_;
        size_type       capacity_;
        allocator_type  allocator_; 
};

/* * * * * * Non-member functions:  * * * * * */

}  // namespace ft

#endif