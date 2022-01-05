#ifndef Stack_hpp
# define Stack_hpp

# include <vector>

namespace ft {

template<class T, class Container = std::vector<T> >
class stack
{
    public:
        typedef          Container                  container_type;
        typedef          T                          value_type;
        typedef typename Container::size_type       size_type;
        typedef typename Container::reference       reference;
        typedef typename Container::const_reference const_reference;

        explicit stack(const container_type& cntnr_obj = container_type()) : container_(cntnr_obj) {}
        stack(const stack& other) { this->operator=(other); }
        stack& operator=(const stack& other)
        {
            if (this == &other)
                return *this;
            this->container_(other.container_);
            return *this;
        }
        ~stack() {}

        /* * * * * * Element access: * * * * * */
        reference       top() { return container_.back(); }
        const_reference top() const { return container_.back(); }

        /* * * * * * Capacity: * * * * * * * * */
        bool        empty() const { return container_.empty(); }
        size_type   size() const { return container_.size(); }

        /* * * * * * Modifiers:  * * * * * * * */
        void        push(const value_type& value) { container_.push_back(value); }
        void        pop() { container_.pop_back(); }

    protected:
        Container container_;
};

/* * * * * * Non-member functions:  * * * * * */
template<class T, class Container>
bool operator==(const ft::stack<T, Container>& lhs,
                const ft::stack<T, Container>& rhs){
        return &lhs.container_ == &rhs.container_;
}

template<class T, class Container>
bool operator!=(const ft::stack<T, Container>& lhs,
                const ft::stack<T, Container>& rhs){
    return &lhs.container_ != &rhs.container_;
}

template<class T, class Container>
bool operator<(const ft::stack<T, Container>& lhs,
               const ft::stack<T, Container>& rhs){
    return &lhs.container_ < &rhs.container_;
}

template<class T, class Container>
bool operator<=(const ft::stack<T, Container>& lhs,
                const ft::stack<T, Container>& rhs){
    return &lhs.container_ <= &rhs.container_;
}

template<class T, class Container>
bool operator>(const ft::stack<T, Container>& lhs,
               const ft::stack<T, Container>& rhs){
    return &lhs.container_ > &rhs.container_;
}

template<class T, class Container>
bool operator>=(const ft::stack<T, Container>& lhs,
                const ft::stack<T, Container>& rhs){
    return &lhs.container_ >= &rhs.container_;
}

}  // namespace ft

#endif