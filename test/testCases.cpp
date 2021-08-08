#include "../ext/googletest/googletest/include/gtest/gtest.h"
#include "../src/nodes.h"

class TestCaseNodes: public ::testing::Test
{
    protected:
        void SetUp(){
            lst_nd = allocate_list();
            for(int i=0; i<50; i++){
                int node_val = i;
                if(node_val % 2 == 0){
                    lst_nd->push_back(node_val);
                }else{
                    lst_nd->push_front(node_val);
                }
            }
        }
        
        NodesList* lst_nd;

        void TearDown(){
            delete lst_nd;
        }

};

TEST_F(TestCaseNodes, test1)
{   
    lst_nd->push_back(100);
    Node* last_node = lst_nd->last;
    ASSERT_EQ(last_node->get_nd_val(), 100);
}

TEST_F(TestCaseNodes, test2)
{   
    lst_nd->push_back(100);
    Node* last_node = lst_nd->last;
    ASSERT_EQ(last_node->get_nd_val(), 100);
}

TEST_F(TestCaseNodes, test3)
{   
    Node* first_node = lst_nd->first;
    ASSERT_EQ(first_node->get_nd_val(), 49);
}
TEST_F(TestCaseNodes, test4)
{   
    Node* last_node = lst_nd->last;
    ASSERT_EQ(last_node->get_nd_val(), 48);
}

TEST_F(TestCaseNodes, test5)
{
    Node* node = lst_nd->find(5, nullptr);
    ASSERT_EQ(node->get_nd_val(), 5);
}
TEST_F(TestCaseNodes, test6)
{
    lst_nd->push_front(-1);
    lst_nd->push_front(11);
    lst_nd->remove(11);
    ASSERT_EQ(lst_nd->first->get_nd_val(), -1);
}

TEST_F(TestCaseNodes, test7)
{
    lst_nd->push_back(10);
    lst_nd->push_front(-100);
    lst_nd->remove(-100);
    ASSERT_EQ(lst_nd->last->get_nd_val(), 10);
}


TEST_F(TestCaseNodes, test8)
{
    lst_nd->push_back(99);
    Node* node = lst_nd->find(99, nullptr);
    lst_nd->insert_after(99, 77);
    ASSERT_EQ(lst_nd->last->get_nd_val(), 77);
}

TEST_F(TestCaseNodes, test9)
{
    lst_nd->push_front(88);
    Node* node = lst_nd->find(88, nullptr);
    lst_nd->insert_before(88, 77);
    ASSERT_EQ(lst_nd->first->get_nd_val(), 77);
}

//______________________________________TESTS_________________________________________


int main(){
    ::testing::InitGoogleTest();
	return RUN_ALL_TESTS();
}