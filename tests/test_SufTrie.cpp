#include <gtest/gtest.h>
#include "../code/SufTrie.h"

#include <iostream>
#include <string>

using namespace std;

class test_SufTrie : public ::testing::Test {
protected:
// 	// This function runs only once before any TEST_F function
	static void SetUpTestCase(){
	}

// 	// This function runs after all TEST_F functions have been executed
	static void TearDownTestCase(){
	}
    
// 	// this function runs before every TEST_F function
	void SetUp() override {
    }

// 	// this function runs after every TEST_F function
	void TearDown() override {
	}
};

TEST_F(test_SufTrie, TestInitialization){
    SufTrie myTri;
	shared_ptr<sufTrie> root= myTri.CreateNode();
	ASSERT_TRUE(root); // expect root to have pointer
}

TEST_F(test_SufTrie, TestBuildSufTrie){
    SufTrie myTri;
	shared_ptr<sufTrie> root= myTri.CreateNode();
    vector<string> str;
	
	str.insert(str.end(),{"aabba", "abaaabb", "aababba"});
    for(int i = 0; i<str.size(); i++){
		myTri.suffixTrie(str[i]);
	}
	myTri.nodeEmpty(root);
	ASSERT_FALSE(myTri.nodeEmpty(root));//indicates root has children	

	ASSERT_TRUE(myTri.searchSub(str[0]));
	ASSERT_TRUE(myTri.searchSub(str[1]));
	ASSERT_TRUE(myTri.searchSub(str[2]));

	string str1 = "cceaab";
	ASSERT_FALSE(myTri.searchSub(str1));//expected not in trie
	string str2 = "cceaab";
	myTri.suffixTrie(str2);
	ASSERT_TRUE(myTri.searchSub(str2));//expected to in trie, after insert
}

TEST_F(test_SufTrie, TestDeleteWord){
    SufTrie myTri;
    shared_ptr<sufTrie> root= myTri.CreateNode();
    vector<string> wordSet;
	
	wordSet.insert(wordSet.end(),{"Ford", "BMW", "Tesla", "Subaru"});
    for(int i = 0; i<wordSet.size(); i++){
		myTri.suffixTrie(wordSet[i]);
	}
	
	string word1 = "BMW";
	ASSERT_TRUE(myTri.searchSub(word1));//locates string in Trie, before deletion
	myTri.delString(word1);
	ASSERT_FALSE(myTri.searchSub(word1));//returns as removed from Trie, after deletion

	string word2 = "Mercedes";
	ASSERT_FALSE(myTri.delString(word2));//expect false, word doesn't exist in Trie	

	string word3 = "Tesla";
	ASSERT_TRUE(myTri.delString(word3));
}

// TEST_F(test_SufTrie, TestName){
//     Class obj;
	
// 	ASSERT_TRUE();
// 	ASSERT_FALSE();
// 	ASSERT_EQ( , );
// }

