#ifndef REVERSEITERATOR_HPP
# define REVERSEITERATOR_HPP

namespace ft {

template <class Iterator>
class ReverseIterator {

    public:
        typedef std::ptrdiff_t                          difference_type;
        /* ********************************************************** */
        ReverseIterator() : iter_() {};
        ReverseIterator(Iterator iter) : iter_(iter) {};
        template <class B> ReverseIterator(const ReverseIterator<B>& other) {
            iter_ = other.getIter();
        };
        ~ReverseIterator() {};
        ReverseIterator& operator=(const ReverseIterator& other) {
            if (this == &other) return *this;
            iter_ = other.getIter();
            return *this;
        }
        Iterator getIter() const {
            return (iter_);
        }
        /* ********** LegacyInputIterator effects ******************* */
        /* LegacyInputIterator effects: "*iter" ********************* */
        typename Iterator::reference operator*() const {
            return *iter_;
        }
        /* LegacyInputIterator effects: "iter->m" ******************* */
        typename Iterator::pointer operator->(){
            return iter_;
        }
        /* LegacyInputIterator effects: "++iter" ******************** */
        ReverseIterator& operator++(){
            --iter_;
            return *this;
        }
        /* ********** LegacyForwardIterator effects ***************** */
        /* LegacyForwardIterator effects: "iter++" ****************** */
        ReverseIterator operator++(int){
            ReverseIterator tmp(*this);
            iter_--;
            return tmp;
        }
        /* ********** LegacyBidirectionalIterator effects *********** */
        /* LegacyBidirectionalIterator effects: "--iter" ************ */
        ReverseIterator& operator--(){
            ++iter_;
            return *this;
        }
        /* LegacyBidirectionalIterator effects: "iter--" ************ */
        ReverseIterator operator--(int){
            ReverseIterator tmp(*this);
            iter_++;
            return (tmp);
        }
        /* ********** LegacyRandomAccessIterator effects ************ */
        /* LegacyRandomAccessIterator effects: "iter+=" ************* */
        ReverseIterator& operator+=(int n) {
            iter_ -= n;
            return *this;
        }
        /* LegacyRandomAccessIterator effects: "iter-=" ************* */
        ReverseIterator& operator-=(int n) {
            iter_ += n;
            return *this;
        }
        /* LegacyRandomAccessIterator effects: "iter + n" *********** */
        ReverseIterator operator+(int n) {
            return iter_ - n;
        }
        /* LegacyRandomAccessIterator effects: "iter - n" ********** */
        ReverseIterator operator-(int n) {
            return iter_ + n;
        }
        /* LegacyRandomAccessIterator effects: "iter[]" ************* */
        typename Iterator::reference operator[](int n) {
            return *(iter_ - n);
        }

    private:
        Iterator iter_;
};

/* LegacyInputIterator effects: iter == iter ************************ */
template <class Iterator>
 bool
operator==(const ReverseIterator<Iterator>& lhs,
           const ReverseIterator<Iterator>& rhs) {
    return lhs.getIter() == rhs.getIter();
}
/* LegacyInputIterator effects: iter != iter ************************ */
template <class Iterator>
 bool
operator!=(const ReverseIterator<Iterator>& lhs,
           const ReverseIterator<Iterator>& rhs) {
    return lhs.getIter() != rhs.getIter();
}
/* LegacyRandomAccessIterator effects: "iter - iter" **************** */
template <class Iterator>
 typename ReverseIterator<Iterator>::difference_type
operator-(const ReverseIterator<Iterator>& lhs,
          const ReverseIterator<Iterator>& rhs) {
    return lhs.getIter() - rhs.getIter();
}
/* LegacyRandomAccessIterator effects: "n + iter" ******************* */
template <class Iterator>
 ReverseIterator<Iterator>
operator+(int n,
          const ReverseIterator<Iterator>& rhs) {
    return n + rhs.getIter();
}
/* LegacyRandomAccessIterator effects: "iter > iter" **************** */
template <class Iterator>
 bool
operator>(const ReverseIterator<Iterator>& lhs,
          const ReverseIterator<Iterator>& rhs) {
    return lhs.getIter() < rhs.getIter();
}
/* LegacyRandomAccessIterator effects: "iter < iter" **************** */
template <class Iterator>
 bool
operator<(const ReverseIterator<Iterator>& lhs,
          const ReverseIterator<Iterator>& rhs) {
    return lhs.getIter() > rhs.getIter();
}
/* LegacyRandomAccessIterator effects: "iter >= iter" *************** */
template <class Iterator>
 bool
operator>=(const ReverseIterator<Iterator>& lhs,
           const ReverseIterator<Iterator>& rhs) {
    return lhs.getIter() <= rhs.getIter();
}
/* LegacyRandomAccessIterator effects: "iter <= iter" *************** */
template <class Iterator>
 bool
operator<=(const ReverseIterator<Iterator>& lhs,
           const ReverseIterator<Iterator>& rhs) {
    return lhs.getIter() >= rhs.getIter();
}

} // namespace ft

#endif // REVERSEITERATOR_HPP