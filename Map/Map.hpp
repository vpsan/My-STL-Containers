#ifndef Map_hpp
# define Map_hpp

# include <memory> // std::allocator<T>

# include "../includes/pair.hpp"
# include "../includes/conditional.hpp"
# include "../includes/ReverseIterator.hpp"

# include "../includes/red_black_tree.hpp"

namespace ft {

template <class Key,
          class T,
          class Compare = std::less<Key>,
          class Allocator = std::allocator< ft::pair<const Key, T> > >
class map {
    public:
        ///////////// Typedef: /////////////////////////////////////////////////
        typedef Key                                             key_type;
        typedef T                                               mapped_type;
        typedef typename ft::pair<const Key, T>                 value_type;

        typedef Compare                                         key_compare;

        typedef Allocator                                       allocator_type;
        typedef typename Allocator::pointer                     pointer;
        typedef typename Allocator::const_pointer               const_pointer;
        typedef typename Allocator::reference                   reference;
        typedef typename Allocator::const_reference             const_reference;
        typedef typename Allocator::size_type                   size_type;
        typedef typename Allocator::difference_type             difference_type;

        typedef red_black_tree<value_type,
                               key_compare,
                               allocator_type>                  red_black_tree;

        typedef typename red_black_tree::iterator               iterator;
        typedef typename red_black_tree::const_iterator         const_iterator;
        typedef typename red_black_tree::reverse_iterator       reverse_iterator;
        typedef typename red_black_tree::const_reverse_iterator const_reverse_iterator;

        ////////////////////////////////////////////////////////////////////////

        explicit map(const key_compare& compare_obj = key_compare(),
                     const allocator_type& allctr_obj = Allocator())
                        : rb_tree_(compare_obj, allctr_obj) {}

         template<class InputIt>
         map(InputIt first,
             InputIt last,
             const key_compare& compare_obj = key_compare(),
             const allocator_type& allctr_obj = Allocator())
                 : rb_tree_(compare_obj, allctr_obj)  {
            rb_tree_.insert(first, last);
        }

        // map(const map& other) : /* FIXME */ {
        //     /* FIXME */
        // }

        ~map() {
            rb_tree_.clear();
        }

//        map& operator=(const map& other) {
//            if (this == &other) return *this;
//            rb_tree_.clear();
//            this = rb_tree_(other);
//            insert(other.begin(), other.end());
//            return *this;
//        }

        allocator_type get_allocator() const {
            return rb_tree_.get_allocator();
        }

        ///////////// Element access: //////////////////////////////////////////

        ///////////// Iterators: ///////////////////////////////////////////////

        iterator begin() {
            return rb_tree_.begin();
        }

        iterator end() {
            return rb_tree_.end();
        }

        const_iterator begin() const {
            return rb_tree_.begin();
        }

        const_iterator end() const {
            return rb_tree_.end();
        }

        reverse_iterator rbegin() {
            return rb_tree_.rbegin();
        }

        reverse_iterator rend() {
            return rb_tree_.rend();
        }

        const_reverse_iterator rbegin() const {
            return rb_tree_.rbegin();
        }

        const_reverse_iterator rend() const {
            return rb_tree_.rend();
        }

        ///////////// Capacity: ////////////////////////////////////////////////

        bool empty() const {
            return rb_tree_.empty();
        }

        size_type size() const {
            return rb_tree_.size();
        }

        size_type max_size() const {
            return rb_tree_.max_size();
        }

        ////////////////// Modifiers: //////////////////////////////////////////

        void clear() {
            rb_tree_.clear();
        }

        pair<iterator,bool> insert (const value_type& value)
        {
            iterator i = find(value.first);
            bool is_exist = false;

            if (i == end())
            {
                rb_tree_.insert(value);
                is_exist = true;
            }
            return pair<iterator, bool>(find(value.first), is_exist);
        }

        size_type erase(const key_type& key)
        {
            iterator position = find(key);
            if (position == end())
                return 0;
            rb_tree_.erase(position);
            return 1;
        }

        ////////////////// Lookup: /////////////////////////////////////////////

        iterator find (const key_type& key) {
            return rb_tree_.find(key);
        }

        ////////////////// Observers: //////////////////////////////////////////

    private:
        red_black_tree rb_tree_;
};

////////////////// Non-member functions: ///////////////////////////////////////

}  // namespace ft

#endif