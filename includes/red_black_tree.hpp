#ifndef RED_BLACK_TREE
# define RED_BLACK_TREE

# include <memory>      // std::allocator<T>
# include <algorithm>   // min max for IsBalanced
# include <iostream>    // std::cout for debug

# define RED    true
# define BLACK  false

namespace ft {

///////////////////// struct node: ////////////////////////////////////////
template <class T>
struct node {
        typedef node<T>*    node_ptr;
        typedef T           value_type;

        value_type          value;
        node_ptr            right;
        node_ptr            left;
        node_ptr            parent;
        bool                color;
        bool                is_end_rend;
};

///////////////////// class red_black_tree: ////////////////////////////////////
template <class T,
        class Compare = std::less<T>,
        class Allocator = std::allocator<T> >
class red_black_tree {

    public:
        ///////////// typedef part 1 (without iterators): //////////////////////
        typedef T                                   value_type;
        typedef Compare                             value_comapre;
        typedef Allocator                           allocator_type;
        typedef typename allocator_type::size_type  size_type;
        typedef node<T>                             node;
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
                return ptr_->value;
            }
            /* LegacyInputIterator effects: "iter->m" *********************** */
            pointer operator->(){
                return &(ptr_->value);
            }
            /* LegacyInputIterator effects: "++iter" ************************ */
            RedBlackTreeBidirectionalIterator& operator++(){
                if (ptr_->right != nil_) {
                    ptr_ = rb_iter_minimum(ptr_->right);
                    return *this;
                }
                node_ptr x = ptr_;
                node_ptr y = ptr_->parent;
                while (y != nil_ && x == y->right){
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
                ++(*this);
                return tmp;
            }
            /* ********** LegacyBidirectionalIterator effects *************** */
            /* LegacyBidirectionalIterator effects: "--iter" **************** */
            RedBlackTreeBidirectionalIterator& operator--(){
                if (ptr_->left != nil_) {
                    ptr_ = rb_iter_maximum(ptr_->left);
                    return *this;
                }
                node_ptr x = ptr_;
                node_ptr y = ptr_->parent;
                while (y != nil_ && x == y->left){
                    x = y;
                    y = y->parent;
                }
                ptr_ = y;
                return *this;
            }
            /* LegacyBidirectionalIterator effects: "iter--" **************** */
            RedBlackTreeBidirectionalIterator operator--(int){
                RedBlackTreeBidirectionalIterator tmp(*this);
                --(*this);
                return tmp;
            }

        private:
            node_ptr ptr_;
            node_ptr nil_;

        private:
            node_ptr rb_iter_maximum(node_ptr x) {
                while(is_nil(x->right) == false)
                    x = x->right;
                return x;
            }

            node_ptr rb_iter_minimum(node_ptr x) {
                while(is_nil(x->left) == false)
                    x = x->left;
                return x;
            }

            bool is_nil(node_ptr n) {
                return n == nil_ || n->is_end_rend == true;
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
        ///////////// typedef part 2 (iterators): //////////////////////////////
        typedef RedBlackTreeBidirectionalIterator<false>          iterator;
        typedef RedBlackTreeBidirectionalIterator<true>           const_iterator;
        typedef ReverseIterator<iterator>                         reverse_iterator;
        typedef ReverseIterator<const_iterator>                   const_reverse_iterator;

        ///////////// constructor(s)/destructor/operator=: /////////////////////
        explicit red_black_tree(const value_comapre& compare_obj,
                                const allocator_type& allctr_obj)
                : compare_(compare_obj),
                  allocator_(allctr_obj),
                  root_(NULL),
                  nil_(NULL),
                  size_(0) {
            end_allocated_ = reinterpret_cast<node_ptr>(allocator_.allocate(sizeof(node)));
            end_allocated_->is_end_rend = true;
            end_allocated_->color = BLACK;
            allocator_.construct(&(end_allocated_->value), value_type());
            end_allocated_->right = nil_;
            end_allocated_->left = nil_;

            rend_allocated_ = reinterpret_cast<node_ptr>(allocator_.allocate(sizeof(node)));
            rend_allocated_->is_end_rend = true;
            rend_allocated_->color = BLACK;
            allocator_.construct(&(rend_allocated_->value), value_type());
            rend_allocated_->right = nil_;
            rend_allocated_->left = nil_;
        }

        red_black_tree(const red_black_tree& other)
                : compare_(other.compare_),
                  allocator_(other.allocator_),
                  root_(NULL),
                  nil_(NULL),
                  size_(0) {
            end_allocated_ = reinterpret_cast<node_ptr>(allocator_.allocate(sizeof(node)));
            end_allocated_->is_end_rend = true;
            end_allocated_->color = BLACK;
            allocator_.construct(&(end_allocated_->value), value_type());
            end_allocated_->right = nil_;
            end_allocated_->left = nil_;

            rend_allocated_ = reinterpret_cast<node_ptr>(allocator_.allocate(sizeof(node)));
            rend_allocated_->is_end_rend = true;
            rend_allocated_->color = BLACK;
            allocator_.construct(&(rend_allocated_->value), value_type());
            rend_allocated_->right = nil_;
            rend_allocated_->left = nil_;
        }

        red_black_tree()
                : compare_(value_comapre()),
                  allocator_(allocator_type()),
                  root_(NULL),
                  nil_(NULL),
                  size_(0) {
            end_allocated_ = reinterpret_cast<node_ptr>(allocator_.allocate(sizeof(node)));
            end_allocated_->is_end_rend = true;
            end_allocated_->color = BLACK;
            allocator_.construct(&(end_allocated_->value), value_type());
            end_allocated_->right = nil_;
            end_allocated_->left = nil_;

            rend_allocated_ = reinterpret_cast<node_ptr>(allocator_.allocate(sizeof(node)));
            rend_allocated_->is_end_rend = true;
            rend_allocated_->color = BLACK;
            allocator_.construct(&(rend_allocated_->value), value_type());
            rend_allocated_->right = nil_;
            rend_allocated_->left = nil_;
        }

        ~red_black_tree() {
            clear();
            delete_end_rend();
        }

        ///////////// RedBlackTree /////////////////////////////////////////////
        void rb_left_rotate(node_ptr x){
            node_ptr y = x->right; // 1. Обозначаем правого ребенка Y
            x->right = y->left;   // 1. Теперь левый ребенок Y - правый ребенок X
            if (is_nil(y->left) == false) { // 1. Если ребенок "левый ребенок Y" не NIL - то меняем у "левый ребенок Y" родителя на Х
                y->left->parent = x;
            }

            y->parent = x->parent;  // 2. Меняем родителя y на родителя Х
            if (is_nil(x->parent) == true) {// 3. Если X был - root, то переобозначим Y на root
                root_ = y;
            }
            else if (x == x->parent->left) {// 3. Если X не был - root, то он был либо правым либо левым ребенком. Делаем Y либо правым либо левым ребенком "X.отца"
                x->parent->left = y;
            }
            else {
                x->parent->right = y;
            }

            y->left = x;   // 4. Выставляем Y ребенка, а у Х отца
            x->parent = y;  // 4. Выставляем Y ребенка, а у Х отца
        }


        void rb_right_rotate(node_ptr x){
            node_ptr y = x->left;

            x->left = y->right;
            if(is_nil(y->right) == false) {
                y->right->parent = x;
            }
            y->parent = x->parent;
            if(is_nil(x->parent) == true) {
                root_ = y;
            }
            else if(x == x->parent->right) {
                x->parent->right = y;
            }
            else {
                x->parent->left = y;
            }
            y->right = x;
            x->parent = y;
        }

        void rb_insertion_fixup(node_ptr z){
            while(z != NULL && z->parent != NULL && z->parent->color == RED) {
                if(z->parent == z->parent->parent->left) { //1. z.parent is the left child
                    node_ptr y = z->parent->parent->right; //   Y = uncle of z


                    if(y!= NULL && y->color == RED) { //case 1: (if uncle RED)
                        // std::cout << "rb_insert-fixup-11" << std::endl;
                        z->parent->color = BLACK;
                        y->color = BLACK;
                        z->parent->parent->color = RED;
                        z = z->parent->parent; // z is a grandparent now
                    }
                    else {
                        if (z == z->parent->right) { //case2: (if z is right child) - make it left child
                            // std::cout << "rb_insert-fixup-12" << std::endl;
                            z = z->parent; //marked z.parent as new z
                            rb_left_rotate(z);
                        }
                        //case3: (if z is left child)
                        // std::cout << "rb_insert-fixup-13" << std::endl;
                        z->parent->color = BLACK; //made parent black
                        z->parent->parent->color = RED; //made parent red
                        rb_right_rotate(z->parent->parent);
                    }
                }
                else if (z->parent == z->parent->parent->right) { //z.parent is the right child
                    node_ptr y = z->parent->parent->left; //uncle of z

                    if (y != NULL && y->color == RED) {
                        // std::cout << "rb_insert-fixup-21" << std::endl;
                        z->parent->color = BLACK;
                        y->color = BLACK;
                        z->parent->parent->color = RED;
                        z = z->parent->parent;
                    }
                    else {
                        if (z == z->parent->left) {
                            // std::cout << "rb_insert-fixup-22" << std::endl;
                            z = z->parent; //marked z.parent as new z
                            rb_right_rotate(z);
                        }
                        // std::cout << "rb_insert-fixup-23" << std::endl;
                        z->parent->color = BLACK; //made parent black
                        z->parent->parent->color = RED; //made parent red
                        rb_left_rotate(z->parent->parent);
                    }
                }
            }
            root_->color = BLACK;
        }

        void rb_insert(node_ptr z){
            // 1. Итерируемся от root.
            //    tmp - итератор.
            //    Y после итераций окажется родителем новой ноды Z.
            //    Для этого мы сохраняем итеративный шаг,
            //    каждый раз опускаясь ниже, чтоб не потерять его
            node_ptr  temp = root_;
            node_ptr  y = nil_;

            while(is_nil(temp) == false) {
                y = temp;
                if(z->value < temp->value)
                    temp = temp->left;
                else
                    temp = temp->right;
            }
            z->parent = y;
            // 2. Если Дерево было пустым. То новый узел Z - root
            if(is_nil(y) == true) {
                // std::cout << "rb_insert-1" << std::endl;
                root_ = z;
            }
            // 3. Если нет, определяем станет Z правым или левым ребенком
            else if(z->value < y->value) {
                // std::cout << "rb_insert-2" << std::endl;
                y->left = z;
            } else {
                // std::cout << "rb_insert-3" << std::endl;
                y->right = z;
            }
            // И зануляем его детей.
            z->right = nil_;
            z->left = nil_;

            rb_insertion_fixup(z);
        }

        void rb_transplant(node_ptr u, node_ptr v) {
            // 1. Является U ли корнем?
            //    - если да, то V - корень
            if(is_nil(u->parent) == true)
                root_ = v;
            // 2. Если U левый сын ...
            else if(u == u->parent->left)
                u->parent->left = v;
            // 3. Если U правый сын ...
            else
                u->parent->right = v;
            if (v == NULL || u == NULL) return;
            v->parent = u->parent;
        }

        node_ptr rb_maximum(node_ptr x) {
            while(is_nil(x->right) == false)
                x = x->right;
            return x;
        }

        node_ptr rb_minimum(node_ptr x) {
            while(is_nil(x->left) == false)
                x = x->left;
            return x;
        }

        node_ptr rb_maximum(node_ptr x) const {
            while(is_nil(x->right) == false)
                x = x->right;
            return x;
        }

        node_ptr rb_minimum(node_ptr x) const {
            while(is_nil(x->left) == false)
                x = x->left;
            return x;
        }

        void rb_delete_fixup(node_ptr x) {
            while(x != root_ && x != NULL && x->color == BLACK) {
                if (x == x->parent->left) {
                    node_ptr w = x->parent->right;
                    if (w->color == RED) {
                        // std::cout << "delete-case-11\n";
                        w->color = BLACK;
                        x->parent->color = RED;
                        rb_left_rotate(x->parent);
                        w = x->parent->right;
                    }
                    if(w->left->color == BLACK && w->right->color == BLACK) {
                        // std::cout << "delete-case-12\n";
                        w->color = RED;
                        x = x->parent;
                    }
                    else {
                        if (w->right->color == BLACK) {
                            w->left->color = BLACK;
                            w->color = RED;
                            rb_right_rotate(w);
                            w = x->parent->right;
                        }
                        // std::cout << "delete-case-13\n";
                        w->color = x->parent->color;
                        x->parent->color = BLACK;
                        w->right->color = BLACK;
                        rb_left_rotate(x->parent);
                        x = root_;
                    }
                }
                else {
                    node_ptr w = x->parent->left;
                    if (w->color == RED) {
                        // std::cout << "delete-case-21\n";
                        w->color = BLACK;
                        x->parent->color = RED;
                        rb_right_rotate(x->parent);
                        w = x->parent->left;
                    }
                    if (w->right->color == BLACK && w->left->color == BLACK) {
                        // std::cout << "delete-case-22\n";
                        w->color = RED;
                        x = x->parent;
                    }
                    else {
                        if(w->left->color == BLACK) {
                            w->right->color = BLACK;
                            w->color = RED;
                            rb_left_rotate(w);
                            w = x->parent->left;
                        }
                        // std::cout << "delete-case-23\n";
                        w->color = x->parent->color;
                        x->parent->color = BLACK;
                        w->left->color = BLACK;
                        rb_right_rotate(x->parent);
                        x = root_;
                    }
                }
            }
            if (x == NULL) return;
            x->color = BLACK;
        }

        void rb_delete(node_ptr z){
            node_ptr y = z;
            node_ptr x;
            bool y_orignal_color = y->color;

            bool is_allocated = false;

            // 1. У Z левый ребенка-NIL?
            //    - Case 1. no children or only right
            //    - Значит он имеет правого ребенка/не имеет детей.
            //    - Тогда просто Z заменяем его правым ребенком, (сохранив его)
            if (is_nil(z->left) == true) {
                // std::cout << "rb_delete-1" << std::endl;
                x = z->right;
                rb_transplant(z, z->right);
            }
            // 2. У Z левый ребенка !=NIL, но правый ребенок - NILL?
            //    - Case 2. only left child
            //    - Если да, тогда просто Z заменяем его левым ребенком, (сохранив его)
            else if(is_nil(z->right) == true) {
                // std::cout << "rb_delete-2" << std::endl;
                x = z->left;
                rb_transplant(z, z->left);
            }
            // 3. У Z есть оба ребенка != NIL
            //    - Case 3. both children
            //    - Находим минимальный элемент справа (Y)
            //    - Минимальный элемент встанет на место Z. Но не сразу
            else {
                // 3.1 Пусть Y - это минимальный такой элемент справа от Z
                //     Сохраняем его правого ребенка и цвет.
                y = rb_minimum(z->right);
                y_orignal_color = y->color;
                x = y->right; //x = (y->right == NULL) ? y : y->right; // +
                if (x == NULL) { // случай когда y->right = NULL. И Y - ребенок Z. Тогда в 3.2 нам нужен непустой x
                    x = reinterpret_cast<node_ptr>(allocator_.allocate(sizeof(node)));
                    allocator_.construct(&(x->value), value_type());
                    x->is_end_rend = false;
                    is_allocated = true;
                }
                // 3.2 Если Y - ребенок Z
                if (y->parent == z) {
                    // std::cout << "rb_delete-3" << std::endl;
                    x->parent = y;//+
                }
                // 3.3 Если Y - не ребенок Z
                //     - Вытаскиваем Y и на его место вставляем y->right
                //     - Делаем копию правого поддерева Z с узлом Y
                //     - Делаем копию правого поддерева Z с узлом Y
                else {
                    // std::cout << "rb_delete-4" << std::endl;
                    rb_transplant(y, y->right);
                    y->right = z->right;
                    y->right->parent = y;
                }
                // Меняем два дерева Z и Y местами
                rb_transplant(z, y);
                y->left = z->left;
                y->left->parent = y;
                y->color = z->color;
            }
            // rb_delete_fixup - если у заменяемого элемента цвет был черный,
            //                   то придется менять цвет у него и его ребенка.
            // if (y_orignal_color == BLACK)
            //     rb_delete_fixup(x);
            allocator_.destroy(&z->value);
            allocator_.deallocate(reinterpret_cast<value_type *>(z), 1);
            if (is_allocated == true) {
                allocator_.destroy(&x->value);
                allocator_.deallocate(reinterpret_cast<value_type *>(x), 1);
            }
            z = NULL;
        }

        void inorder(node_ptr n) {
            if(is_nil(n) == false) {
                inorder(n->left);
                std::cout << "value = " << n->value << std::endl;
                inorder(n->right);
            }
        }

        bool is_nil(node_ptr n) {
            return n == nil_ || n->is_end_rend == true;
        }

        bool is_nil(node_ptr n) const {
            return n == nil_ || n->is_end_rend == true;
        }

        ///////////// Wrappers over RedBlackTree ///////////////////////////////
        node_ptr link_end_value() {
            if (root_ == NULL) return root_;
            node_ptr x = rb_maximum(root_);
            node_ptr end_ptr = x->right;
            if (end_ptr != NULL) return end_ptr;

            end_ptr =  end_allocated_;
            end_ptr->parent = x;
            x->right = end_ptr;
            return end_ptr;
        }

        node_ptr link_end_value() const {
            if (root_ == NULL) return root_;
            node_ptr x = rb_maximum(root_);
            node_ptr end_ptr = x->right;
            if (end_ptr != NULL) return end_ptr;

            end_ptr =  end_allocated_;
            end_ptr->parent = x;
            x->right = end_ptr;
            return end_ptr;
        }

        void unlink_end_value() {
            if (root_ == NULL) return;
            node_ptr x = rb_maximum(root_);
            node_ptr end_ptr = x->right;
            if (end_ptr == NULL) return;

            end_ptr->parent = NULL;
            end_ptr->left = NULL;
            end_ptr->right = NULL;
            x->right = nil_;
            end_ptr = NULL;
        }

        node_ptr link_rend_value() {
            if (root_ == NULL) return root_;
            node_ptr x = rb_minimum(root_);
            node_ptr rend_ptr = x->left;
            if (rend_ptr != NULL) return rend_ptr;

            rend_ptr =  rend_allocated_;
            rend_ptr->parent = x;
            x->left = rend_ptr;
            return rend_ptr;
        }

        node_ptr link_rend_value() const {
            if (root_ == NULL) return root_;
            node_ptr x = rb_minimum(root_);
            node_ptr rend_ptr = x->left;
            if (rend_ptr != NULL) return rend_ptr;

            rend_ptr =  rend_allocated_;
            rend_ptr->parent = x;
            x->left = rend_ptr;
            return rend_ptr;
        }

        void unlink_rend_value() {
            if (root_ == NULL) return;
            node_ptr x = rb_minimum(root_);
            node_ptr rend_ptr = x->left;
            if (rend_ptr == NULL) return;

            rend_ptr->parent = NULL;
            rend_ptr->left = NULL;
            rend_ptr->right = NULL;
            x->left = nil_;
            rend_ptr = NULL;
        }

        void insert(const value_type& value) {
            node_ptr z = reinterpret_cast<node_ptr>(allocator_.allocate(sizeof(node)));
            z->color = RED;
            z->is_end_rend = false;
            allocator_.construct(&(z->value), value);
            unlink_end_value();
            unlink_rend_value();
            rb_insert(z);
            size_++;
            link_end_value();
            link_rend_value();
        }

        template<class InputIterator>
        void insert(InputIterator first, InputIterator last) {
            for (; first != last; ++first)
                insert(*first);
        }

        void erase(const value_type &value) {
            if (root_ == NULL) return ;
            node_ptr z = root_;

            unlink_end_value();
            unlink_rend_value();
            while (z != NULL && z->value != value)
            {
                if (z->value < value)
                    z = z->right;
                else
                    z = z->left;
            }
            rb_delete(z);
            size_--;
            link_end_value();
            link_rend_value();
        }

        template<class InputIterator>
        void erase(InputIterator it) {
            if (root_ == NULL) return ;
            node_ptr z = root_;
            value_type value = *it;

            unlink_end_value();
            unlink_rend_value();
            while (z != NULL && z->value != value)
            {
                if (z->value < value)
                    z = z->right;
                else
                    z = z->left;
            }
            rb_delete(z);
            size_--;
            link_end_value();
            link_rend_value();
        }

        void clear_node(node_ptr z) {
            if (z == NULL || is_nil(z) == true) return;
            clear_node(z->left);
            clear_node(z->right);
            z->parent = NULL;
            z->right = NULL;
            z->left = NULL;
            allocator_.destroy(&z->value);
            allocator_.deallocate(reinterpret_cast<value_type *>(z), 1);
            z = NULL;
        }

        void clear() {
            unlink_end_value();
            unlink_rend_value();
            clear_node(root_);
            root_ = NULL; // FIXME: why needed?
            size_ = 0;
        }

        void delete_end_rend(){
            if (end_allocated_ != NULL) {
                allocator_.destroy(&end_allocated_->value);
                allocator_.deallocate(reinterpret_cast<value_type *>(end_allocated_), 1);
                end_allocated_ = NULL;
            }
            if (rend_allocated_ != NULL) {
                allocator_.destroy(&rend_allocated_->value);
                allocator_.deallocate(reinterpret_cast<value_type *>(rend_allocated_), 1);
                rend_allocated_ = NULL;
            }
        }

        void print_sorted_tree(){
            unlink_end_value();
            unlink_rend_value();
            inorder(root_);
        }

        ///////////// Key methods / Map Lookup /////////////////////////////////
        template <class Key>
        iterator get_upper_bound(const Key &key, node_ptr root, node_ptr result) {
            while (root != NULL) {
                if (compare_(key, root->value.first) == true) {
                    result = root;
                    root = root->left;
                }
                else {
                    root = root->right;
                }
            }
            return (iterator)(result);
        }

        template <class Key>
        iterator get_lower_bound(const Key &key, node_ptr root, node_ptr result) {
            while (root != NULL) {
                if (compare_(root->value.first, key) == false) {
                    result = root;
                    root = root->left;
                }
                else {
                    root = root->right;
                }
            }
            return (iterator)(result);
        }

        template <class Key>
        const_iterator get_upper_bound(const Key &key, node_ptr root, node_ptr result) const {
            while (root != NULL) {
                if (compare_(key, root->value.first) == true) {
                    result = root;
                    root = root->left;
                }
                else {
                    root = root->right;
                }
            }
            return (iterator)(result);
        }

        template <class Key>
        const_iterator get_lower_bound(const Key &key, node_ptr root, node_ptr result) const {
            while (root != NULL) {
                if (compare_(root->value.first, key) == false) {
                    result = root;
                    root = root->left;
                }
                else {
                    root = root->right;
                }
            }
            return (iterator)(result);
        }

        template<class Key>
        iterator upper_bound(const Key& key) {
            return get_upper_bound(key, root_, link_end_value());
        }

        template<class Key>
        iterator lower_bound(const Key& key) {
            return get_lower_bound(key, root_, link_end_value());
        }

        template<class Key>
        const_iterator upper_bound(const Key& key) const {
            return get_upper_bound(key, root_, link_end_value());
        }

        template<class Key>
        const_iterator lower_bound(const Key& key) const {
            return get_lower_bound(key, root_, link_end_value());
        }

        template <class Key>
        iterator find(const Key &key) {
            iterator p = get_lower_bound(key, root_, link_end_value());
            if (p != end() && compare_(key, (*p).first) == false) {
                return p;
            }
            return end();
        }

        template <class Key>
        size_type count(const Key &key) const {
            node_ptr r = root_;
            while (r != NULL) {
                if (compare_(key, r->value.first)) {
                    r = r->left;
                }
                else if (compare_(r->value.first, key)) {
                    r = r->right;
                }
                else return 1;
            }
            return 0;
        }

        template <class Key>
        pair<iterator, iterator> equal_range(const Key& key) {
            node_ptr res = link_end_value();
            node_ptr rt = root_;
            while (rt != NULL) {
                if (compare_(key, rt->value.first)) {
                    res = rt;
                    rt = rt->left;
                }
                else if (compare_(rt->value.first, key)) {
                    rt = rt->right;
                }
                else {
                    return pair<iterator, iterator>(iterator(rt),
                                                    iterator(rt->right != NULL ? rb_minimum(rt->right) : res));
                }
            }
            return pair<iterator, iterator>(iterator(res), iterator(res));
        }

        template <class Key>
        pair<iterator, iterator> equal_range(const Key& key) const {
            node_ptr res = link_end_value();
            node_ptr rt = root_;
            while (rt != NULL) {
                if (compare_(key, rt->value.first)) {
                    res = rt;
                    rt = rt->left;
                }
                else if (compare_(rt->value.first, key)) {
                    rt = rt->right;
                }
                else {
                    return pair<const_iterator, const_iterator>(const_iterator(rt),
                                                                const_iterator(rt->right != NULL ? rb_minimum(rt->right) : res));
                }
            }
            return pair<const_iterator, const_iterator>(const_iterator(res),
                                                        const_iterator(res));
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

        void swap(red_black_tree& other) {
            std::swap(this->compare_, other.compare_);
            std::swap(this->allocator_, other.allocator_);
            std::swap(this->root_, other.root_);
            std::swap(this->nil_, other.nil_);
            std::swap(this->size_, other.size_);
            std::swap(this->end_allocated_, other.end_allocated_);
            std::swap(this->rend_allocated_, other.rend_allocated_);
        }

        ///////////// Iterators: ///////////////////////////////////////////////
        iterator begin() {
            return iterator( size_ == 0 ? root_ : rb_minimum(root_) );
        }

        iterator end() {
            return iterator(link_end_value());
        }

        const_iterator begin() const {
            return iterator( size_ == 0 ? root_ : rb_minimum(root_) );
        }

        const_iterator end() const {
            return const_iterator(link_end_value());
        }

        reverse_iterator rbegin() {
            return iterator( size_ == 0 ? root_ : rb_maximum(root_) );
        }

        reverse_iterator rend() {
            return reverse_iterator(link_rend_value());
        }

        const_reverse_iterator rbegin() const {
            return iterator( size_ == 0 ? root_ : rb_maximum(root_) );
        }

        const_reverse_iterator rend() const {
            return const_reverse_iterator(link_rend_value());
        }

        ///////////// isBalanced ///////////////////////////////////////////////
        // Returns true if the Binary tree is balanced like a RED-BLACK tree.
        // This function also sets value in maxh and minh (passed by reference).
        // "maxh" and "minh" are set as maximum and minimum heights of root.
        bool isBalancedUtil(node_ptr root, int &maxh, int &minh) {
            // Base case
            if (root == NULL) {
                maxh = minh = 0;
                return true;
            }

            int lmxh, lmnh; // To store max and min heights of left subtree
            int rmxh, rmnh; // To store max and min heights of right subtree

            // Check if left subtree is balanced, also set lmxh and lmnh
            if (isBalancedUtil(root->left, lmxh, lmnh) == false)
                return false;

            // Check if right subtree is balanced, also set rmxh and rmnh
            if (isBalancedUtil(root->right, rmxh, rmnh) == false)
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
            unlink_end_value();
            unlink_rend_value();
            int maxh, minh;
            return isBalancedUtil(root_, maxh, minh);
        }

        ////////////// operator==,!=,<,<=,>,>=: ////////////////////////////////
        friend
        bool operator==(const red_black_tree& lhs, const red_black_tree& rhs){
            return (lhs.size() == rhs.size() && std::equal(lhs.begin(), lhs.end(), rhs.begin()));
        }

        friend
        bool operator<(const red_black_tree& lhs,  const red_black_tree& rhs){
            return (std::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end()));
        }

        friend
        bool operator>(const red_black_tree& lhs,  const red_black_tree& rhs){
            return (lhs < rhs);
        }

    private:
        ///////////// data fields: /////////////////////////////////////////////
        value_comapre       compare_;
        allocator_type      allocator_;
        node_ptr            root_;
        node_ptr            nil_;
        size_type           size_;
        node_ptr            end_allocated_;
        node_ptr            rend_allocated_;
    };

///////////////////// end of class red_black_tree //////////////////////////////

}  // namespace ft

#endif
