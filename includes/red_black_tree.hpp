#ifndef RED_BLACK_TREE
# define RED_BLACK_TREE

# include <memory> // std::allocator<T>


# define Red    1
# define Black  0

namespace ft {

template <class T>
class tree_node {
    public:
        typedef tree_node<T>*   node_ptr;
        typedef T               value_type;

    public:
        value_type              value_;
        node_ptr                right_;
        node_ptr                left_;
        node_ptr                parent;
        int                     color;

    public:
        tree_node(value_type value) 
                        : value_(value),
                        right_(NULL),
                        left_(NULL),
                        parent(NULL),
                        color(Red) {}

        tree_node(value_type value,
                      node_ptr right_,
                      node_ptr left_,
                      node_ptr parent,
                      int color) 
                        : value_(value),
                        right_(right_),
                        left_(left_),
                        parent(parent),
                        color(color) {}
};


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


        explicit red_black_tree(const value_comapre& compare_obj,
                        const allocator_type& allctr_obj)
                        : compare_(compare_obj), 
                        allocator_(allctr_obj),
                        root_(NULL),
                        nil_(NULL),
                        size_(0) {}
        
        red_black_tree(const red_black_tree& other)
                            : compare_(value_comapre()), 
                            allocator_(allocator_type()),
                            root_(NULL),
                            nil_(NULL),
                            size_(0) {}

        red_black_tree() {};

        ~red_black_tree() {
            // FIXME
        }


        // void left__rotate(red_black_tree *t, node_ptr x)
        // void right__rotate(red_black_tree *t, node_ptr x)

        // void insertion_fixup(red_black_tree *t, node_ptr z)
        // void insert(red_black_tree *t, node_ptr z)
        
        // void rb_transplant(red_black_tree *t, node_ptr u, node_ptr v)
        // node_ptr minimum(red_black_tree *t, node_ptr x)
        // void rb_delete_fixup(red_black_tree *t, node_ptr x)
        // void rb_delete(red_black_tree *t, node_ptr z)


        void left__rotate(node_ptr x){

            // 1. Обозначаем правого ребенка Y
            node_ptr y = x->right_;
            // 1. Теперь левый ребенок Y - правый ребенок X
            x->right_ = y->left_;
            // 1. Если ребенок "левый ребенок Y" не NIL - то меняем у "левый ребенок Y" родителя на Х
            if (y->left_ != nil_) {
                y->left_->parent = x;
            }

            // 2. Меняем родителя y на родителя Х
            y->parent = x->parent;
            // 3. Если X был - root, то переобозначим Y на root
            if (x->parent == nil_) {
                root_ = y;
            }
            // 3. Если X не был - root, то он был либо правым либо левым ребенком. Делаем Y либо правым либо левым ребенком "X.отца"
            else if (x == x->parent->left_) {
                x->parent->left_ = y;
            }
            else {
                x->parent->right_ = y;
            }

            // 4. Выставляем Y ребенка, а у Х отца 
            y->left_ = x;
            x->parent = y;
        }


        void right__rotate(node_ptr x){
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

        void insertion_fixup(node_ptr z){
            while(z->parent != NULL && z->parent->color == Red) {
                if(z->parent->parent != NULL && z->parent == z->parent->parent->left_) { //1. z.parent is the left_ child
                    node_ptr y = z->parent->parent->right_; //   Y = uncle of z


                    if(y != NULL && y->color == Red) { //case 1: (if uncle RED)
                        z->parent->color = Black;
                        y->color = Black;
                        z->parent->parent->color = Red;
                        z = z->parent->parent; // z is a grandparent now
                    }
                    else { //case2 or case3
                        if (z == z->parent->right_) { //case2: (if z is right_ child) - make it left_ child
                            z = z->parent; //marked z.parent as new z
                            left__rotate(z);
                        }
                        //case3: (if z is left_ child)
                        z->parent->color = Black; //made parent black
                        z->parent->parent->color = Red; //made parent red
                        right__rotate(z->parent->parent);
                    }
                }
                else if (z->parent->parent != NULL && z->parent == z->parent->parent->right_) { //z.parent is the right_ child
                    node_ptr y = z->parent->parent->left_; //uncle of z

                    if (y != NULL && y->color == Red) {
                        z->parent->color = Black;
                        y->color = Black;
                        z->parent->parent->color = Red;
                        z = z->parent->parent;
                    }
                    else {
                        if (z == z->parent->left_) {
                            z = z->parent; //marked z.parent as new z
                            right__rotate(z);
                        }
                        z->parent->color = Black; //made parent black
                        z->parent->parent->color = Red; //made parent red
                        left__rotate(z->parent->parent);
                    }
                }
            }
            root_->color = Black;
        }

        void insert(const value_type& value){

            node_ptr z = reinterpret_cast<node_ptr>(allocator_.allocate(sizeof(node)));
            // z->parent_ = NULL;
            // allocator_.construct(&z, node(value));
            allocator_.construct(&(z->value_), value);

            // 1. Иттерируемся от root. tmp - счетчик. 
            //    Y после итераций окажется родителем новой ноды Z. 
            //    Для этого мы сохраняем итеративынй шаг каждый раз опускаясь ниже, что не потерять его
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

            // 3. Если нет, определеяем станет Z правым или левым ребенком
            else if(z->value_ < y->value_) //data of child is less than its parent, left_ child
                y->left_ = z;
            else
                y->right_ = z;

            // зануляем его детей.
            z->right_ = nil_;
            z->left_ = nil_;

            insertion_fixup(z);
        }


        void inorder(node_ptr n) {
            if( n != nil_) {
                inorder(n->left_);
                std::cout << "value = " << n->value_ << std::endl;
                inorder(n->right_);
            }
        }


    public:
        value_comapre       compare_;
		allocator_type      allocator_;
		node_ptr            root_;
        node_ptr            nil_;
		size_type           size_;
};

}  // namespace ft

#endif
