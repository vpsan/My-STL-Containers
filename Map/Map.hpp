#ifndef _FT_MAP_
# define _FT_MAP_

# include <memory> // std::allocator<T>

# include "../includes/pair.hpp"
# include "../includes/conditional.hpp"
# include "../includes/RedBlackTree.hpp"
# include "../includes/ReverseIterator.hpp"

namespace ft {

///////////////////// Class map: ///////////////////////////////////////////////
template <class Key,
          class T,
          class Compare = std::less<Key>,
          class Allocator = std::allocator< ft::pair<const Key, T> > >
class map {

    public:
        ///////////// Typedef: /////////////////////////////////////////////////
        typedef Key                                   key_type;
        typedef T                                     mapped_type;
        typedef typename ft::pair<const Key, T>       value_type;

        typedef Compare                               key_compare;
        typedef Allocator                             allocator_type;
        typedef typename Allocator::pointer           pointer;
        typedef typename Allocator::const_pointer     const_pointer;
        typedef typename Allocator::reference         reference;
        typedef typename Allocator::const_reference   const_reference;
        typedef typename Allocator::size_type         size_type;
        typedef typename Allocator::difference_type   difference_type;

    private:
        typedef RedBlackTree<value_type,
                               key_compare,
                               allocator_type>        RedBlackTree_type;

    public:
        typedef typename
            RedBlackTree_type::iterator               iterator;
        typedef typename
            RedBlackTree_type::const_iterator         const_iterator;
        typedef typename
            RedBlackTree_type::reverse_iterator       reverse_iterator;
        typedef typename
            RedBlackTree_type::const_reverse_iterator const_reverse_iterator;

    private:
        ///////////// value_compare: ///////////////////////////////////////////
        class value_compare {
            public:
                value_compare(const key_compare& cmpr) : vc_compare_(cmpr) {}

                bool operator()(const value_type& obj1,
                                const value_type& obj2) const {
                    return (vc_compare_(obj1.first, obj2.first));
                }
            private:
                key_compare vc_compare_;

        };

    public:
        ///////////// Constructor(s) / Destructor / Operator=: /////////////////
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

         map(const map& other) : rb_tree_(other.rb_tree_) {
             rb_tree_.insert(other.begin(), other.end());
        }

        ~map() {
            rb_tree_.clear();
            rb_tree_.deallocate_end_rend();
        }

        map& operator=(const map& other) {
            if (this == &other) return *this;
            rb_tree_.clear();
            this = rb_tree_(other);
            insert(other.begin(), other.end());
            return *this;
        }

        allocator_type get_allocator() const {
            return rb_tree_.get_allocator();
        }

        ///////////// Element access: //////////////////////////////////////////
        mapped_type& operator[](const key_type& key) {
            iterator iter = find(key);
            if (iter == rb_tree_.end()) {
                insert(value_type(key, mapped_type()));
                iter = find(key);
            }
            return iter->second;
        }

        mapped_type& at(const Key &key) {
            iterator iter = find(key);
            if (iter == rb_tree_.end()) {
                throw std::out_of_range("map::at:  key not found");
            }
            return iter->second;
        }

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

        ///////////// Modifiers: ///////////////////////////////////////////////
        void clear() {
            rb_tree_.clear();
        }

        pair<iterator,bool> insert(const value_type& value) {
            iterator i = find(value.first);
            bool is_exist = false;

            if (i == end()) {
                rb_tree_.insert(value);
                is_exist = true;
            }
            return pair<iterator, bool>(find(value.first), is_exist);
        }

        iterator insert(iterator position, const value_type& value) {
            (void)position;
            insert(value);
            return find(value.first);
        }

        template <class InputIterator>
        void insert(InputIterator first, InputIterator last) {
            for (; first != last; ++first)
                insert(*first);
        }

        size_type erase(const key_type& key) {
            iterator iter = find(key);
            if (iter == end()) return 0;
            rb_tree_.erase(iter);
            return 1;
        }

        void erase(iterator position) {
            rb_tree_.erase(position);
        }

        void erase(iterator first, iterator last) {
            iterator tmp;
            while (first != last) {
                tmp = first;
                ++first;
                rb_tree_.erase(tmp);
            }
        }

        void swap(map& other) {
            rb_tree_.swap(other.rb_tree_);
        }

        ///////////// Key methods / Lookup: ////////////////////////////////////
        iterator find(const key_type& key) {
            return rb_tree_.find(key);
        }

        iterator lower_bound(const key_type& key) {
            return rb_tree_.lower_bound(key);
        }

        const_iterator lower_bound(const key_type& key) const {
            rb_tree_.lower_bound(key);
        }

        iterator upper_bound(const key_type& key) {
            return rb_tree_.upper_bound(key);
        }

        const_iterator upper_bound(const key_type& key) const {
            return rb_tree_.upper_bound(key);
        }

        size_type count(const key_type& key) const {
            return rb_tree_.count(key);
        }

        pair<iterator,iterator> equal_range(const key_type& key) {
            return rb_tree_.equal_range(key);
        }

        pair<const_iterator,const_iterator> equal_range(const key_type& key) const {
            return rb_tree_.equal_range(key);
        }

        ///////////// Observers: ///////////////////////////////////////////////
        key_compare key_comp() const {
            return rb_tree_.get_value_compare();
        }

        value_compare value_comp() const {
            return value_compare(rb_tree_.get_value_compare());
        }

        ///////////// Operator==,!=,<,<=,>,>=: /////////////////////////////////
        friend bool operator==(const map& lhs, const map& rhs) {
            return (lhs.rb_tree_ == rhs.rb_tree_);
        }

        friend bool operator!=(const map& lhs, const map& rhs) {
            return !(lhs == rhs);
        }

        friend bool operator<(const map& lhs, const map& rhs) {
            return (lhs.rb_tree_ < rhs.rb_tree_);
        }

        friend bool operator>(const map& lhs, const map& rhs) {
            return (rhs < lhs);
        }

        friend bool operator<=(const map& lhs, const map& rhs) {
            return !(lhs > rhs);
        }

        friend bool operator>=(const map& lhs, const map& rhs) {
            return !(lhs < rhs);
        }

    private:
        ///////////// Data fields: /////////////////////////////////////////////
        RedBlackTree_type rb_tree_;
};

}  // namespace ft

#endif // _FT_MAP_