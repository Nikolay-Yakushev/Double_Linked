#include "./nodes.h"


const int Node::get_nd_val(){
    return value;
}

Node* Node::get_prev(){
    return prev;
}

Node* Node::get_next(){
    return next;
}

void  Node::set_next(Node* nd){
    this->next=nd;
}

void Node::set_prev(Node* nd){
    this->prev=nd;
}





Node* NodesList::find(int val, Node* nd=nullptr){
    Node* node_found=nullptr;
    if(nd==nullptr){
        // нашли ноду с первого раза
        if(first->get_nd_val()==val){
            node_found = first;
        }else if(last->get_nd_val()==val){
             node_found = last;
        }else{
            //не нашли и вызываем еще раз
            nd = first->get_next();
            if(nd!=nullptr){
                node_found = find(val, nd);
            }
        }
    }else{
        if(nd->get_nd_val()==val){
            node_found = nd; 
        }else{
            //end of a list_nodes
            nd = nd->get_next();
            if(nd!=nullptr){
                node_found = find(val, nd);
            }
            
        }
    }
    return node_found;
}

void NodesList::remove(int val){
    Node* nd = find(val);
        if (nd==nullptr){
            std::cout<<"nothing to remove";
        }else{
            Node* left_con_nd = nd->get_prev();
            Node* right_con_nd = nd->get_next();

            if(left_con_nd!=nullptr && right_con_nd!=nullptr){
                left_con_nd->set_next(right_con_nd);
                right_con_nd->set_prev(left_con_nd);

                delete nd;
            }else{
                if(left_con_nd==nullptr){
                   first=right_con_nd;
                   delete nd; 
                }else{
                    last=left_con_nd;
                    delete nd;
                }
            }
        }

    }
void NodesList::push_front(int val){
    if(first==nullptr){
        //первая нода
        Node* node_p =new Node(val);
        node_p -> set_prev(nullptr);
        node_p -> set_next(nullptr);
        first = node_p;
        last = node_p;
    }else{
        // в начало списка
        // инициализируем новую ноду 
        Node* node_p = new Node(val);;
        // привязываем предыдущую ноду к той,
        // которой была первой в списке
        
        node_p -> set_next(first);
       
        // первая нода связана с пустотой (пустым указателем=nullptr)
        node_p -> set_prev(nullptr);
        // первая нода теперь со значеним val 
        first=node_p;
    }
}

void NodesList::push_back(int val){
    if(first==nullptr){
        //первая нода
        Node* node_p = new Node(val);
        node_p -> set_next(nullptr);
        node_p-> set_prev(nullptr);
        first = node_p;
        last = node_p;
    }else{
        // в конец списка
        // инициализируем новую ноду 
        Node* node_p = new Node(val);
        // привязываем предыдущую ноду к той,
        // которой была последней в списке
        node_p -> set_prev(last);
        node_p -> set_next(nullptr);
        // последняя нода связана с пустотой (пустым указателем=nullptr)
        
        // последняя нода теперь со значеним val 
        last = node_p;
        
    }
    
}

void NodesList::insert_after(int val_node, int val){
    Node* nd = find(val_node);
    if(nd!=nullptr){
        Node* new_node = new Node(val); // 77
        Node* old_next = nd->get_next(); // nullptr

        new_node->set_prev(nd);
        nd->set_next(new_node);
        if(old_next==nullptr){
            last=new_node;
            new_node->set_next(nullptr);
        }else{
            new_node->set_next(old_next);
        }
    }
}

void NodesList::insert_before(int val_node, int val)
{
    Node* nd = find(val_node);
    if(nd!=nullptr){
        Node* new_node = new Node(val);
        Node* old_prev = nd->get_prev();

        new_node->set_next(nd);
        nd->set_prev(new_node);
        if(old_prev==nullptr){
            first=new_node;
            new_node->set_prev(nullptr);
        }else{
            new_node->set_prev(old_prev);
        }
    }
}

NodesList* allocate_list(){
    NodesList* lst_t = new NodesList(); 
    lst_t->first=nullptr;
    lst_t->last=nullptr;
    return lst_t;
}

std::ostream& operator<<(std::ostream& os, Node* node){
    int val = node->value;
    os<<"value of a node "<<val;
    return os;
}
