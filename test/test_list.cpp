//
// Created by raulett on 08.07.2023.
//
#include <iostream>
#include <gtest/gtest.h>
#include "My_list.h"

TEST(My_list, empty_constructor){
    // Arrange
    My_list empty_container = My_list<int>();
    // Act

    // Assert
    ASSERT_EQ(empty_container.arr_size(), 0);
    ASSERT_TRUE(empty_container.is_empty());
}

TEST(My_list, single_element_constructor){
    My_list sing_el_list = My_list<int>(4);

    ASSERT_EQ(sing_el_list[0], 4);
    ASSERT_EQ(sing_el_list.arr_size(), 1);
    ASSERT_FALSE(sing_el_list.is_empty());
}

TEST(My_list, multiple_element_constructor){
    My_list multi_el_list = My_list<int>();

    multi_el_list.push_back(1, 2, 3, 4, 5, 6, 7, 8, 9, 10);

    ASSERT_FALSE(multi_el_list.is_empty());
    ASSERT_EQ(multi_el_list.arr_size(), 10);
    ASSERT_EQ(multi_el_list[0], 1);
    ASSERT_EQ(multi_el_list[1], 2);
    ASSERT_EQ(multi_el_list[2], 3);
    ASSERT_EQ(multi_el_list[3], 4);
    ASSERT_EQ(multi_el_list[4], 5);
    ASSERT_EQ(multi_el_list[5], 6);
    ASSERT_EQ(multi_el_list[6], 7);
    ASSERT_EQ(multi_el_list[7], 8);
    ASSERT_EQ(multi_el_list[8], 9);
    ASSERT_EQ(multi_el_list[9], 10);
}

TEST(My_list, iterator){
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    My_list multi_el_list = My_list<int>();

    // Act
    for (int i : arr){
        multi_el_list.push_back(i);
    }

    // Assert
    int i = 1;
    auto it = multi_el_list.begin();
    ASSERT_EQ(multi_el_list.arr_size(), 10);
    while (it.has_next()){
        ASSERT_EQ(it.get(), i);
        i++;
        it.next();
    }



}

int main(int argc, char** argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}