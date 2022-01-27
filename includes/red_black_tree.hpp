#ifndef RED_BLACK_TREE
# define RED_BLACK_TREE

# include <memory>      // std::allocator<T>
# include <algorithm>   // min max for IsBalanced
# include <iostream>    // std::cout for debug


# define Red    1
# define Black  0

namespace ft {

///////////////////// struct tree_node: ////////////////////////////////////////

template <class T>
struct tree_node {
//    public:
        typedef tree_node<T>*   node_ptr;
        typedef T               value_type;

//    public:
        value_type              value_;
        node_ptr                right_;
        node_ptr                left_;
        node_ptr                parent;
        int                     color;

//    public:
//        tree_node(value_type value)
//                : value_(value),
//                  right_(NULL),
//                  left_(NULL),
//                  parent(NULL),
//                  color(Red) {}
//
//        tree_node(value_type value,
//                  node_ptr right_,
//                  node_ptr left_,
//                  node_ptr parent,
//                  int color)
//                : value_(value),
//                  right_(right_),
//                  left_(left_),
//                  parent(parent),
//                  color(color) {}
};

///////////////////// class red_black_tree: ////////////////////////////////////
template <class T,
        class Compare = std::less<T>,
        class Allocator = std::allocator<T> >
class red_black_tree {

    public:
        ///////////// typedef part 1: //////////////////////////////////////////
        typedef T                                   value_type;
        typedef Compare                             value_comapre;
        typedef Allocator                           allocator_type;
        typedef typename allocator_type::size_type  size_type;

        typedef tree_node<T>                        node;
        typedef typename node::node_ptr             node_ptr;

    public:
        ///////////// Iterators: ///////////////////////////////////////////////
        template<bool IsConst>
        class RedBlackTreeBidirectionalIterator {
        public:
            typedef typename
                ft::conditional<IsConst, const T, T>::type  value_type;
            typedef value_type*                             pointer;
            typedef value_type&                             reference;
            typedef std::ptrdiff_t                          difference_type;
            typedef	std::bidirectional_iterator_tag         iterator_category;

        public:
            RedBlackTreeBidirectionalIterator() : ptr_(NULL), nil_(NULL) {}
            RedBlackTreeBidirectionalIterator(node_ptr ptr) : ptr_(ptr), nil_(NULL) {};
            RedBlackTreeBidirectionalIterator(const RedBlackTreeBidirectionalIterator& other) {
                ptr_ = other.getPtr();
                nil_ = NULL;
            }

            RedBlackTreeBidirectionalIterator& operator=(const RedBlackTreeBidirectionalIterator& other) {
                if (this == &other) return *this;
                ptr_ = other.getPtr();
                return *this;
            }

            // effect:      const_iter = iter,
            // not effect:  iter = const_iter
            operator RedBlackTreeBidirectionalIterator<true>() const {
                return ptr_;
            }

            node_ptr getPtr() const {
                return ptr_;
            }

            /* ********** LegacyInputIterator effects *********************** */
            /* LegacyInputIterator effects: "*iter" ************************* */
            reference operator*() const {
                return ptr_->value_;
            }
            /* LegacyInputIterator effects: "iter->m" *********************** */
            pointer operator->(){
                return &(ptr_->value_);
            }
            /* LegacyInputIterator effects: "++iter" ************************ */
            RedBlackTreeBidirectionalIterator& operator++(){
                if (ptr_->right_ != nil_) {
                    ptr_ = rb_iter_minimum(ptr_->right_);
                    return *this;
                }
                node_ptr x = ptr_;
                node_ptr y = ptr_->parent;
                while (y != nil_ && x == y->right_){
                    x = y;
                    y = y->parent;
                }
                ptr_ = y;
                return *this;
            }
            /* ********** LegacyForwardIterator effects ********************* */
            /* LegacyForwardIterator effects: "iter++" ********************** */
            RedBlackTreeBidirectionalIterator operator++(int){
                RedBlackTreeBidirectionalIterator tmp(*this);
                ptr_++;
                return tmp;
            }
            /* ********** LegacyBidirectionalIterator effects *************** */
            /* LegacyBidirectionalIterator effects: "--iter" **************** */
            RedBlackTreeBidirectionalIterator& operator--(){
                if (ptr_->left_ != nil_) {
                    ptr_ = rb_iter_maximum(ptr_->left_);
                    return *this;
                }
                node_ptr x = ptr_;
                node_ptr y = ptr_->parent;
                while (y != nil_ && x == y->left_){
                    x = y;
                    y = y->parent;
                }
                ptr_ = y;
                return *this;
            }
            /* LegacyBidirectionalIterator effects: "iter--" **************** */
            RedBlackTreeBidirectionalIterator operator--(int){
                RedBlackTreeBidirectionalIterator tmp(*this);
                ptr_--;
                return tmp;
            }

        private:
            node_ptr ptr_;
            node_ptr nil_;

            node_ptr rb_iter_maximum(node_ptr x) {
                while(x->right_ != nil_)
                    x = x->right_;
                return x;
            }

            node_ptr rb_iter_minimum(node_ptr x) {
                while(x->left_ != nil_)
                    x = x->left_;
                return x;
            }
        };

        /* LegacyInputIterator effects: iter == iter ************************ */
        template <bool IsConst_l, bool IsConst_r>
        friend bool
        operator==(const RedBlackTreeBidirectionalIterator<IsConst_l>& lhs,
                   const RedBlackTreeBidirectionalIterator<IsConst_r>& rhs) {
            return lhs.getPtr() == rhs.getPtr();
        }
        /* LegacyInputIterator effects: iter != iter ************************ */
        template <bool IsConst_l, bool IsConst_r>
        friend bool
        operator!=(const RedBlackTreeBidirectionalIterator<IsConst_l>& lhs,
                   const RedBlackTreeBidirectionalIterator<IsConst_r>& rhs) {
            return lhs.getPtr() != rhs.getPtr();
        }

    public:
        ///////////// typedef part 2: //////////////////////////////////////////
        typedef RedBlackTreeBidirectionalIterator<false>          iterator;
        typedef RedBlackTreeBidirectionalIterator<true>           const_iterator;
        typedef ReverseIterator<iterator>                         reverse_iterator;
        typedef ReverseIterator<const_iterator>                   const_reverse_iterator;

        ////////////////////////////////////////////////////////////////////////

        explicit red_black_tree(const value_comapre& compare_obj,
                                const allocator_type& allctr_obj)
                : compare_(compare_obj),
                  allocator_(allctr_obj),
                  root_(NULL),
                  nil_(NULL),
                  iter_end_(NULL),
                  iter_rend_(NULL),
                  size_(0) {}

        red_black_tree(const red_black_tree& other)
                : compare_(other.compare_),
                  allocator_(other.allocator_),
                  root_(NULL),
                  nil_(NULL),
                  iter_end_(NULL),
                  iter_rend_(NULL),
                  size_(0) {}

        red_black_tree()
                : compare_(value_comapre()),
                  allocator_(allocator_type()),
                  root_(NULL),
                  nil_(NULL),
                  iter_end_(NULL),
                  iter_rend_(NULL),
                  size_(0) {}

        ~red_black_tree() {
            clear();
        }

        ///////////// RedBlackTree /////////////////////////////////////////////

        void rb_left_rotate(node_ptr x){
            node_ptr y = x->right_; // 1. Обозначаем правого ребенка Y
            x->right_ = y->left_;   // 1. Теперь левый ребенок Y - правый ребенок X
            if (/*y->left_ != nil_*/is_nil(y->left_) == false) { // 1. Если ребенок "левый ребенок Y" не NIL - то меняем у "левый ребенок Y" родителя на Х
                y->left_->parent = x;
            }

            y->parent = x->parent;  // 2. Меняем родителя y на родителя Х
            if (/*x->parent == nil_*/is_nil(x->parent) == true) {// 3. Если X был - root, то переобозначим Y на root
                root_ = y;
            }
            else if (x == x->parent->left_) {// 3. Если X не был - root, то он был либо правым либо левым ребенком. Делаем Y либо правым либо левым ребенком "X.отца"
                x->parent->left_ = y;
            }
            else {
                x->parent->right_ = y;
            }

            y->left_ = x;   // 4. Выставляем Y ребенка, а у Х отца
            x->parent = y;  // 4. Выставляем Y ребенка, а у Х отца
        }


        void rb_right_rotate(node_ptr x){
            node_ptr y = x->left_;

            x->left_ = y->right_;
            if(/*y->right_ != nil_*/ is_nil(y->right_) == false) {
                y->right_->parent = x;
            }
            y->parent = x->parent;
            if(/*x->parent == nil_*/is_nil(x->parent) == true) { //x is root
                root_ = y;
            }
            else if(x == x->parent->right_) { //x is left_ child
                x->parent->right_ = y;
            }
            else { //x is right_ child
                x->parent->left_ = y;
            }
            y->right_ = x;
            x->parent = y;
        }

        void rb_insertion_fixup(node_ptr z){
            while(z != NULL && z->parent != NULL && z->parent->color == Red) {
                if(z->parent == z->parent->parent->left_) { //1. z.parent is the left_ child
                    node_ptr y = z->parent->parent->right_; //   Y = uncle of z


                    if(y!= NULL && y->color == Red) { //case 1: (if uncle RED)
                        z->parent->color = Black;
                        y->color = Black;
                        z->parent->parent->color = Red;
                        z = z->parent->parent; // z is a grandparent now
                        std::cout << "here-i-11\n";
                    }
                    else { //case2 or case3
                        if (z == z->parent->right_) { //case2: (if z is right_ child) - make it left_ child
                            z = z->parent; //marked z.parent as new z
                            rb_left_rotate(z);
                        }
                        //case3: (if z is left_ child)
                        z->parent->color = Black; //made parent black
                        z->parent->parent->color = Red; //made parent red
                        rb_right_rotate(z->parent->parent);
                        std::cout << "here-i-12\n";
                    }
                }
                else if (/*z->parent->parent != NULL &&*/ z->parent == z->parent->parent->right_) { //z.parent is the right_ child
                    node_ptr y = z->parent->parent->left_; //uncle of z

                    if (y != NULL && y->color == Red) {
                        z->parent->color = Black;
                        y->color = Black;
                        z->parent->parent->color = Red;
                        z = z->parent->parent;
                        std::cout << "here-i-21\n";
                    }
                    else {
                        std::cout << "here-i-22\n";
                        if (z == z->parent->left_) {
                            z = z->parent; //marked z.parent as new z
                            rb_right_rotate(z);
                        }
                        z->parent->color = Black; //made parent black
                        z->parent->parent->color = Red; //made parent red
                        rb_left_rotate(z->parent->parent);
                    }
                }
            }
            root_->color = Black;
        }

        void rb_insert(node_ptr z){
            // 1. Итерируемся от root.
            //    tmp - итератор.
            //    Y после итераций окажется родителем новой ноды Z.
            //    Для этого мы сохраняем итеративный шаг,
            //    каждый раз опускаясь ниже, чтоб не потерять его
            node_ptr  temp = root_;
            node_ptr  y = nil_;

            while(/*temp != nil_*/is_nil(temp) == false) {
                y = temp;
                if(z->value_ < temp->value_)
                    temp = temp->left_;
                else
                    temp = temp->right_;
            }
            z->parent = y;
            // 2. Если Дерево было пустым. То новый узел Z - root
            if(/*y == nil_*/is_nil(y) == true) {
                root_ = z;
            }
            // 3. Если нет, определяем станет Z правым или левым ребенком
            else if(z->value_ < y->value_)
                y->left_ = z;
            else
                y->right_ = z;
            // И зануляем его детей.
            z->right_ = nil_;
            z->left_ = nil_;

            rb_insertion_fixup(z);
        }

        void rb_transplant(node_ptr u, node_ptr v) {
            // 1. Является U ли корнем?
            //    - если да, то V - корень
            if(/*u->parent == nil_*/is_nil(u->parent) == true)
                root_ = v;
            // 2. Если U левый сын ...
            else if(u == u->parent->left_)
                u->parent->left_ = v;
            // 3. Если U правый сын ...
            else
                u->parent->right_ = v;
            if (v == NULL || u == NULL) return;
            v->parent = u->parent;
        }

        node_ptr rb_maximum(node_ptr x) {
            while(/*x->right_ != nil_*/is_nil(x->right_) == false)
                x = x->right_;
            return x;
        }

        node_ptr rb_minimum(node_ptr x) {
            // Мин элемент - элемент без левого потомка в заданном поддерев
            // (если говорить про удаление - то рассматриваем правое поддерево)
            while(/*x->left_ != nil_*/is_nil(x->left_) == false)
                x = x->left_;
            return x;
        }

        void rb_delete_fixup(node_ptr x) {
            while(x != root_ && x != NULL && x->color == Black) {
                if (x == x->parent->left_) {
                    node_ptr w = x->parent->right_;
                    if (w->color == Red) {
                        std::cout << "here11\n";
                        w->color = Black;
                        x->parent->color = Red;
                        rb_left_rotate(x->parent);
                        w = x->parent->right_;
                    }
                    if(w->left_->color == Black && w->right_->color == Black) {
                        std::cout << "here12\n";
                        w->color = Red;
                        x = x->parent;
                    }
                    else {
                        if (w->right_->color == Black) {
                            w->left_->color = Black;
                            w->color = Red;
                            rb_right_rotate(w);
                            w = x->parent->right_;
                        }
                        std::cout << "here13\n";
                        w->color = x->parent->color;
                        x->parent->color = Black;
                        w->right_->color = Black;
                        rb_left_rotate(x->parent);
                        x = root_;
                    }
                }
                else {
                    node_ptr w = x->parent->left_;
                    if (w->color == Red) {
                        std::cout << "here21\n";
                        w->color = Black;
                        x->parent->color = Red;
                        rb_right_rotate(x->parent);
                        w = x->parent->left_;
                    }
                    if (w->right_->color == Black && w->left_->color == Black) {
                        std::cout << "here22\n";
                        w->color = Red;
                        x = x->parent;
                    }
                    else {
                        if(w->left_->color == Black) {
                            w->right_->color = Black;
                            w->color = Red;
                            rb_left_rotate(w);
                            w = x->parent->left_;
                        }
                        std::cout << "here23\n";
                        w->color = x->parent->color;
                        x->parent->color = Black;
                        w->left_->color = Black;
                        rb_right_rotate(x->parent);
                        x = root_;
                    }
                }
            }
            if (x == NULL) return;
            x->color = Black;
        }

        void rb_delete(node_ptr z){
            node_ptr y = z;
            node_ptr x;
            int y_orignal_color = y->color;

            // 1. У Z левый ребенка-NIL?
            //    - Case 1. no children or only right
            //    - Значит он имеет правого ребенка/не имеет детей.
            //    - Тогда просто Z заменяем его правым ребенком, (сохранив его)
            if (/*z->left_ == nil_*/is_nil(z->left_) == true) {
                x = z->right_;
                rb_transplant(z, z->right_);
            }
            // 2. У Z левый ребенка !=NIL, но правый ребенок - NILL?
            //    - Case 2. only left child
            //    - Если да, тогда просто Z заменяем его левым ребенком, (сохранив его)
            else if(/*z->right_ == nil_*/is_nil(z->right_) == true) {
                x = z->left_;
                rb_transplant(z, z->left_);
            }
            // 3. У Z есть оба ребенка != NIL
            //    - Case 3. both children
            //    - Находим минимальный элемент справа (Y)
            //    - Минимальный элемент встанет на место Z. Но не сразу
            else {
                // 3.1 Пусть Y - это минимальный такой элемент справа от Z
                //     Сохраняем его правого ребенка и цвет.
                y = rb_minimum(z->right_);
                y_orignal_color = y->color;
                x = y->right_; //x = (y->right_ == NULL) ? y : y->right_; // +
                // 3.2 Если Y - ребенок Z
                if (x != NULL && y->parent == z) {
                    x->parent = y;//+
                    // y->parent = y;//+
                }
                // 3.3 Если Y - не ребенок Z
                //     - Вытаскиваем Y и на его место вставляем y->right_
                //     - Делаем копию правого поддерева Z с узлом Y
                //     - Делаем копию правого поддерева Z с узлом Y
                else {
                    rb_transplant(y, y->right_);
                    y->right_ = z->right_;
                    y->right_->parent = y;
                }
                // Меняем два дерева Z и Y местами
                rb_transplant(z, y);
                y->left_ = z->left_;
                y->left_->parent = y;
                y->color = z->color;
            }
            // rb_delete_fixup - если у заменяемого элемента цвет был черный,
            //                   то придется менять цвет у него и его ребенка.
            if (y_orignal_color == Black)
                rb_delete_fixup(x);
            allocator_.destroy(&z->value_);
            allocator_.deallocate(reinterpret_cast<value_type *>(z), 1);
            z = NULL;
        }

        void inorder(node_ptr n) {
            // delete_iter_end();
            // delete_iter_rend();
            if( /*n != nil_*/ is_nil(n) == false) {
                inorder(n->left_);
                std::cout << "value = " << n->value_ << std::endl;
                inorder(n->right_);
            }
            // iter_end_ = init_iter_end();
            // iter_rend_ = init_iter_rend();
        }

        bool is_nil(node_ptr n) {
            return n == nil_ || n == iter_end_ || n == iter_rend_;
        }

        ///////////// Wrappers over RedBlackTree ///////////////////////////////

        node_ptr init_iter_end() {
            if (iter_end_ != NULL) return iter_end_;
            iter_end_ = reinterpret_cast<node_ptr>(allocator_.allocate(sizeof(node)));
            iter_end_->color = Black;
            allocator_.construct(&(iter_end_->value_), value_type());
            iter_end_->right_ = nil_;
            iter_end_->left_ = nil_;
            node_ptr x;
            if (root_ == NULL){
                x = root_;
            } else {
                x =  rb_maximum(root_);
            }
            iter_end_->parent = x;
            x->right_ = iter_end_;
            return iter_end_;
        }

        void delete_iter_end() {
            if (iter_end_ == NULL) return;
            node_ptr x;
            if (root_ == NULL) {
                x = root_;
            } else {
                x = rb_maximum(root_);
            }

            iter_end_->parent = NULL;
            iter_end_->left_ = NULL;
            iter_end_->right_ = NULL;
            x->right_ = nil_;
            allocator_.destroy(&iter_end_->value_);
            allocator_.deallocate(reinterpret_cast<value_type *>(iter_end_), 1);
            iter_end_ = NULL;
        }

        node_ptr init_iter_rend() {
            if (iter_rend_ != NULL) return iter_rend_;
            iter_rend_ = reinterpret_cast<node_ptr>(allocator_.allocate(sizeof(node)));
            iter_rend_->color = Black;
            allocator_.construct(&(iter_rend_->value_), value_type());
            iter_rend_->right_ = nil_;
            iter_rend_->left_ = nil_;

            node_ptr x;
            if (root_ == NULL) {
                x = root_;
            } else {
                x = rb_minimum(root_);
            }

            iter_rend_->parent = x;
            x->left_ = iter_rend_;
            return iter_rend_;
        }

        void delete_iter_rend() {
            if (iter_rend_ == NULL) return;
            node_ptr x;
            if (root_ == NULL) {
                x = root_;
            } else {
                x = rb_minimum(root_);
            }

            iter_rend_->parent = NULL;
            iter_rend_->left_ = NULL;
            iter_rend_->right_ = NULL;
            x->left_ = nil_;
            allocator_.destroy(&iter_rend_->value_);
            allocator_.deallocate(reinterpret_cast<value_type *>(iter_rend_), 1);
            iter_rend_ = NULL;
        }

        void insert(const value_type& value) {
            node_ptr z = reinterpret_cast<node_ptr>(allocator_.allocate(sizeof(node)));
            z->color = Red;
            allocator_.construct(&(z->value_), value);
            delete_iter_end();
            delete_iter_rend();
            rb_insert(z);
            size_++;
            iter_end_ = init_iter_end();
            iter_rend_ = init_iter_rend();
        }

        void insert(iterator first, iterator last) {
            for (; first != last; ++first)
                insert(*first); // FIXME: if it = end() then *it is not defined
        }

        void erase(const value_type &value) {
            if (root_ == NULL) return ;
            node_ptr z = root_;

            delete_iter_end();
            delete_iter_rend();
            while (z != NULL && z->value_ != value)
            {
                if (z->value_ < value)
                    z = z->right_;
                else
                    z = z->left_;
            }
//            if (z == NULL) {
//                return;
//                iter_end_ = init_iter_end();
//                iter_rend_ = init_iter_rend();
//            }
            rb_delete(z);
            size_--;
            iter_end_ = init_iter_end();
            iter_rend_ = init_iter_rend();
        }

        void erase(iterator it) {
            if (root_ == NULL) return ;
            node_ptr z = root_;
            value_type value = *it; // FIXME: if it = end() then *it is not defined

            delete_iter_end();
            delete_iter_rend();
            while (z != NULL && z->value_ != value)
            {
                if (z->value_ < value)
                    z = z->right_;
                else
                    z = z->left_;
            }
//            if (z == NULL) {
//                return;
//                iter_end_ = init_iter_end();
//                iter_rend_ = init_iter_rend();
//            }
            rb_delete(z);
            size_--;
            iter_end_ = init_iter_end();
            iter_rend_ = init_iter_rend();
        }

        void clear_node(node_ptr z) {
            if (z == NULL || is_nil(z) == true) return;
            clear_node(z->left_);
            clear_node(z->right_);
            z->parent = NULL;
            z->right_ = NULL;
            z->left_ = NULL;
            allocator_.destroy(&z->value_);
            allocator_.deallocate(reinterpret_cast<value_type *>(z), 1);
            z = NULL;
        }

        void clear() {
            clear_node(root_);
        }

        void print_sorted_tree(){
            delete_iter_end();
            delete_iter_rend();
            inorder(root_);
            // iter_end_ = init_iter_end();
            // iter_rend_ = init_iter_rend();
        }

        ///////////// Trivial helpers //////////////////////////////////////////

        size_type size() const {
            return size_;
        }

        bool empty() const {
            return size_ == 0;
        }

        size_type max_size() const {
            return allocator_.max_size();
        }

        value_comapre get_value_compare() const {
            return compare_;
        }

        allocator_type get_allocator() const {
            return allocator_;
        }

        ///////////// isBalanced ///////////////////////////////////////////////

        // Returns true if the Binary tree is balanced like a Red-Black tree.
        // This function also sets value in maxh and minh (passed by reference).
        // "maxh" and "minh" are set as maximum and minimum heights of root.
        bool isBalancedUtil(node_ptr root, int &maxh, int &minh) {
            // Base case
            if (root == NULL)
            {
                maxh = minh = 0;
                return true;
            }

            int lmxh, lmnh; // To store max and min heights of left subtree
            int rmxh, rmnh; // To store max and min heights of right subtree

            // Check if left subtree is balanced, also set lmxh and lmnh
            if (isBalancedUtil(root->left_, lmxh, lmnh) == false)
                return false;

            // Check if right subtree is balanced, also set rmxh and rmnh
            if (isBalancedUtil(root->right_, rmxh, rmnh) == false)
                return false;

            // Set the max and min heights of this node for the parent call
            maxh = std::max(lmxh, rmxh) + 1;
            minh = std::min(lmnh, rmnh) + 1;

            // See if this node is balanced
            if (maxh <= 2*minh)
                return true;

            return false;
        }

        // A wrapper over isBalancedUtil()
        bool isBalanced() {
            delete_iter_end();
            delete_iter_rend();
            int maxh, minh;
            return isBalancedUtil(root_, maxh, minh);
        }

        ///////////// Iterators: ///////////////////////////////////////////////

        iterator begin() {
            return iterator( size_ == 0 ? root_ : rb_minimum(root_) );
        }
        iterator end() {
            if (iter_end_ == NULL) {
                iter_end_ = init_iter_end();
                return iterator(iter_end_);
            }
            else {
                return iterator(iter_end_);
            }
        }

        const_iterator begin() const {
            return iterator( size_ == 0 ? root_ : rb_minimum(root_) );
        }
        const_iterator end() const {
            if (iter_end_ == NULL) {
                iter_end_ = init_iter_end();
                return const_iterator(iter_end_);
            }
            else {
                return const_iterator(iter_end_);
            }
        }

        reverse_iterator rbegin() {
            return iterator( size_ == 0 ? root_ : rb_maximum(root_) );
        }

        reverse_iterator rend() {
            if (iter_rend_ == NULL) {
                iter_rend_ = init_iter_rend();
                return reverse_iterator(iterator(iter_rend_));;
            }
            else {
                return reverse_iterator(iterator(iter_rend_));;
            }
        }

        const_reverse_iterator rbegin() const {
            return iterator( size_ == 0 ? root_ : rb_maximum(root_) );
        }

        const_reverse_iterator rend() const {
            if (iter_rend_ == NULL) {
                iter_rend_ = init_iter_rend();
                return const_reverse_iterator(iterator(iter_rend_));;
            }
            else {
                return const_reverse_iterator(iterator(iter_rend_));;
            }
        }

    private:
        value_comapre       compare_;
        allocator_type      allocator_;
        node_ptr            root_;
        node_ptr            nil_;
        node_ptr            iter_end_;
        node_ptr            iter_rend_;
        size_type           size_;
    };

}  // namespace ft

#endif
