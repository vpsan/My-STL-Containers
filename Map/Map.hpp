#ifndef Map_hpp
# define Map_hpp

# include <memory> // std::allocator<T>

# include "../includes/pair.hpp"
# include "../includes/conditional.hpp"
# include "../includes/ReverseIterator.hpp"

namespace ft {

template <class Key,
          class T,
          class Compare = std::less<Key>,
          class Allocator = std::allocator< ft::pair<const Key, T> > >
class map {
    public:
        typedef Key                                 key_type;
        typedef T                                   mapped_type;
        typedef typename ft::pair<const Key, T>     value_type;

        typedef Compare                             key_compare;

        typedef Allocator                           allocator_type;
        typedef typename Allocator::pointer         pointer;
        typedef typename Allocator::const_pointer   const_pointer;
        typedef typename Allocator::reference       reference;
        typedef typename Allocator::const_reference const_reference;
        typedef typename Allocator::size_type       size_type;
        typedef typename Allocator::difference_type difference_type;

        // typedef BidirectionalIterator<false>        iterator;
        // typedef BidirectionalIterator<true>         const_iterator;
        // typedef ReverseIterator<iterator>           reverse_iterator;
        // typedef ReverseIterator<const_iterator>     const_reverse_iterator;

        ////////////////////////////////////////////////////////////////////////

        // explicit map(const key_compare& compare_obj = key_compare(),
        //              const allocator_type& allctr_obj = Allocator())
        //                 : /* FIXME */  {}

        // template<class InputIt>
        // map(InputIt first,
        //     InputIt last,
        //     const key_compare& compare_obj = key_compare(),
        //     const allocator_type& allctr_obj = Allocator())
        //         : /* FIXME */  {}

        // map(const map& other) : /* FIXME */ {
        //     /* FIXME */
        // }

        // ~map() {}

        ///////////// Element access: //////////////////////////////////////////

        ///////////// Iterators: ///////////////////////////////////////////////

        ///////////// Capacity: ////////////////////////////////////////////////

        ////////////////// Modifiers: //////////////////////////////////////////

        ////////////////// Observers: //////////////////////////////////////////

    private:

};

////////////////// Non-member functions: ///////////////////////////////////////

}  // namespace ft

#endif