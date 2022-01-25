#ifndef RED_BLACK_TREE
# define RED_BLACK_TREE

# include <memory> // std::allocator<T>
# include <algorithm> // min max
# include <iostream> // std::cout debug


# define Red    1
# define Black  0

namespace ft {

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

//template <class T, class U_node_ptr>
//class RedBlackTreeBidirectionalIterator {
//    public:
//        typedef T                                     value_type;
//        typedef value_type*                           pointer;
//        typedef value_type&                           reference;
//        typedef U_node_ptr                            node_ptr;
//        typedef std::ptrdiff_t                        difference_type;
//        typedef	std::bidirectional_iterator_tag       iterator_category;
//    public:
//        RedBlackTreeBidirectionalIterator() : ptr_(NULL) {};
//        // RedBlackTreeBidirectionalIterator(pointer ptr) : ptr_(ptr) {};
//        RedBlackTreeBidirectionalIterator(const RedBlackTreeBidirectionalIterator& other) {
//            ptr_ = other.getPtr();
//        }
//
//        /* ********** LegacyInputIterator effects ******************* */
//        /* LegacyInputIterator effects: "*iter" ********************* */
//        reference operator*() const {
//            return ptr_->value_;
//        }
//        /* LegacyInputIterator effects: "iter->m" ******************* */
//        pointer operator->(){
//            return &(ptr_->value_);
//        }
//        /* LegacyInputIterator effects: "++iter" ******************** */
//        RedBlackTreeBidirectionalIterator& operator++(){
//            ++ptr_;
//            return *this;
//        }
//
//        pointer getPtr() const {
//            return ptr_;
//        }
//
//    private:
//        node_ptr ptr_;
//};


    template <class T,
            class Compare = std::less<T>,
            class Allocator = std::allocator<T> >
    class red_black_tree {
    public:
        typedef T                                   value_type;
        typedef Compare                             value_comapre;
        typedef Allocator                           allocator_type;
        typedef typename allocator_type::size_type  size_type;

        typedef tree_node<T>                        node;
        typedef typename node::node_ptr             node_ptr;
    public:

        ////////////////////////////////////////////////////////////////////////////
        //////////////////////////////////////////////////////////////////////////// start
        ////////////////////////////////////////////////////////////////////////////

//        class RedBlackTreeBidirectionalIterator {
//        public:
//            typedef value_type*                           pointer;
//            typedef value_type&                           reference;
//            typedef std::ptrdiff_t                        difference_type;
//            typedef	std::bidirectional_iterator_tag       iterator_category;
//        public:
//            RedBlackTreeBidirectionalIterator(node_ptr nil = NULL) : ptr_(NULL), nil_in_iter_(nil) {}
//            RedBlackTreeBidirectionalIterator(pointer ptr, node_ptr rb_nil) : ptr_(ptr), nil_in_iter_(rb_nil) {};
//            RedBlackTreeBidirectionalIterator(const RedBlackTreeBidirectionalIterator& other) {
//                ptr_ = other.getPtr();
//                nil_in_iter_ = other.getNil();
//            }
//
//            /* ********** LegacyInputIterator effects ******************* */
//            /* LegacyInputIterator effects: "*iter" ********************* */
//            reference operator*() const {
//                return ptr_->value_;
//            }
//            /* LegacyInputIterator effects: "iter->m" ******************* */
//            pointer operator->(){
//                return &(ptr_->value_);
//            }
//            /* LegacyInputIterator effects: "++iter" ******************** */
//            RedBlackTreeBidirectionalIterator& operator++(){
//                if (ptr_->right_ != nil_in_iter_) {
//                    ptr_ = rb_iter_minimum(ptr_);
//                    return *this;
//                }
//                node_ptr x = ptr_;
//                node_ptr y = ptr_->parent;
//                while (y != nil_in_iter_ && x == y->right_){
//                    x = y;
//                    y = y->parent;
//                }
//                ptr_ = y;
//                return *this;
//            }
//
//            RedBlackTreeBidirectionalIterator& operator--(){
//                if (ptr_->left_ != nil_in_iter_) {
//                    ptr_ = rb_iter_maximum(ptr_);
//                    return *this;
//                }
//                node_ptr x = ptr_;
//                node_ptr y = ptr_->parent;
//                while (y != nil_in_iter_ && x == y->left_){
//                    x = y;
//                    y = y->parent;
//                }
//                ptr_ = y;
//                return *this;
//            }
//
//            pointer getPtr() const {
//                return ptr_;
//            }
//
//            pointer getNil() const {
//                return nil_in_iter_;
//            }
//
//        private:
//            node_ptr ptr_;
//            node_ptr nil_in_iter_;
//
//            node_ptr rb_iter_maximum(node_ptr x) {
//                while(x->right_ != nil_in_iter_)
//                    x = x->right_;
//                return x;
//            }
//
//            node_ptr rb_iter_minimum(node_ptr x) {
//                while(x->left_ != nil_in_iter_)
//                    x = x->left_;
//                return x;
//            }
//        };
        ////////////////////////////////////////////////////////////////////////////
        //////////////////////////////////////////////////////////////////////////// end
        ////////////////////////////////////////////////////////////////////////////


//        explicit red_black_tree(const value_comapre& compare_obj,
//                                const allocator_type& allctr_obj)
//                : compare_(compare_obj),
//                  allocator_(allctr_obj),
//                  root_(NULL),
//                  nil_(NULL),
//                  size_(0) {}

//        red_black_tree(const red_black_tree& other)
//                : compare_(value_comapre()),
//                  allocator_(allocator_type()),
//                  root_(NULL),
//                  nil_(NULL),
//                  size_(0) {}

//        red_black_tree()
//                : compare_(value_comapre()),
//                allocator_(allocator_type()),
//                size_(0) {
//            this->nil_ = NULL;//reinterpret_cast<node_ptr>(allocator_.allocate(sizeof(node)));
//            nil_->left_ = NULL;
//            nil_->right_ = NULL;
//            nil_->parent = NULL;
//            nil_->color = Black;
//            nil_->value_ = value_type();// FIXME default(value_type). Not shure that defualt is ok for all types
//            root_ = nil_;
//        }

        red_black_tree()
                : compare_(value_comapre()),
                  allocator_(allocator_type()),
                  root_(NULL),
                  nil_(NULL),
                  size_(0) {}

        ~red_black_tree() {
            // FIXME
        }


        // void rb_left_rotate(red_black_tree *t, node_ptr x)
        // void rb_right_rotate(red_black_tree *t, node_ptr x)

        // void rb_insertion_fixup(red_black_tree *t, node_ptr z)
        // void rb_insert(red_black_tree *t, node_ptr z)

        // void rb_transplant(red_black_tree *t, node_ptr u, node_ptr v)
        // node_ptr rb_minimum(red_black_tree *t, node_ptr x)
        // void rb_delete_fixup(red_black_tree *t, node_ptr x)
        // void rb_delete(red_black_tree *t, node_ptr z)


        void rb_left_rotate(node_ptr x){
            node_ptr y = x->right_; // 1. Обозначаем правого ребенка Y
            x->right_ = y->left_;   // 1. Теперь левый ребенок Y - правый ребенок X
            if (y->left_ != nil_) { // 1. Если ребенок "левый ребенок Y" не NIL - то меняем у "левый ребенок Y" родителя на Х
                y->left_->parent = x;
            }

            y->parent = x->parent;  // 2. Меняем родителя y на родителя Х
            if (x->parent == nil_) {// 3. Если X был - root, то переобозначим Y на root
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
            if(y->right_ != nil_) {
                y->right_->parent = x;
            }
            y->parent = x->parent;
            if(x->parent == nil_) { //x is root
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

            while(temp != nil_) {
                y = temp;
                if(z->value_ < temp->value_)
                    temp = temp->left_;
                else
                    temp = temp->right_;
            }
            z->parent = y;
            // 2. Если Дерево было пустым. То новый узел Z - root
            if(y == nil_) {
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

        void insert(const value_type& value) {
            node_ptr z = reinterpret_cast<node_ptr>(allocator_.allocate(sizeof(node)));
            z->color = Red;
            allocator_.construct(&(z->value_), value);

            rb_insert(z);
        }

        void rb_transplant(node_ptr u, node_ptr v) {
            // 1. Является U ли корнем?
            //    - если да, то V - корень
            if(u->parent == nil_)
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
            while(x->right_ != nil_)
                x = x->right_;
            return x;
        }

        node_ptr rb_minimum(node_ptr x) {
            // Мин элемент - элемент без левого потомка в заданном поддерев
            // (если говорить про удаление - то рассматриваем правое поддерево)
            while(x->left_ != nil_)
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
            if (z->left_ == nil_) {
                x = z->right_;
                rb_transplant(z, z->right_);
            }
            // 2. У Z левый ребенка !=NIL, но правый ребенок - NILL?
            //    - Case 2. only left child
            //    - Если да, тогда просто Z заменяем его левым ребенком, (сохранив его)
            else if(z->right_ == nil_) {
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
                if (/*x != NULL &&*/ y->parent == z) {
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
        }

        void erase(const value_type &value)
        {
            node_ptr p = root_;

            while (p && p->value_ != value)
            {
                if (p->value_ < value)
                    p = p->right_;
                else
                    p = p->left_;
            }
            if (!p)
                return;
            rb_delete(p);
        }

        void inorder(node_ptr n) {
            if( n != nil_) {
                inorder(n->left_);
                std::cout << "value = " << n->value_ << std::endl;
                inorder(n->right_);
            }
        }

        ////////////////////////////////////////////////////////////////////////////
        //////// isBalanced ////////////////////////////////////////////////////////
        ////////////////////////////////////////////////////////////////////////////

        // Returns returns tree if the Binary tree is balanced like a Red-Black
        // tree. This function also sets value in maxh and minh (passed by
        // reference). maxh and minh are set as maximum and minimum heights of root.
        bool isBalancedUtil(node_ptr root, int &maxh, int &minh)
        {
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
        bool isBalanced(node_ptr root)
        {
            int maxh, minh;
            return isBalancedUtil(root, maxh, minh);
        }
        ////////////////////////////////////////////////////////////////////////////
        ////////////////////////////////////////////////////////////////////////////

    public:
        value_comapre       compare_;
        allocator_type      allocator_;
        node_ptr            root_;
        node_ptr            nil_;
        size_type           size_;
    };

}  // namespace ft

#endif
