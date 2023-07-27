//
// Created by raulett on 07.07.2023.
//
#include <iostream>
#include <gtest/gtest.h>
#include "My_vector.h"

TEST(My_vector, empty_constructor){
    // Arrange
    My_vector empty_vector = My_vector<int>();
    // Act

    // Assert
    ASSERT_EQ(empty_vector.arr_size(), 0);
    ASSERT_TRUE(empty_vector.is_empty());
}

TEST(My_vector, single_element_constructor){
    My_vector sing_el_vector = My_vector<int>(4);

    ASSERT_EQ(sing_el_vector[0], 4);
    ASSERT_EQ(sing_el_vector.arr_size(), 1);
    ASSERT_FALSE(sing_el_vector.is_empty());
}

TEST(My_vector, multiple_element_constructor){
    My_vector multi_el_vector = My_vector<int>(1, 2, 3, 4, 5, 6, 7, 8, 9, 10);

    ASSERT_FALSE(multi_el_vector.is_empty());
    ASSERT_EQ(multi_el_vector.arr_size(), 10);
    ASSERT_EQ(multi_el_vector[0], 1);
    ASSERT_EQ(multi_el_vector[1], 2);
    ASSERT_EQ(multi_el_vector[2], 3);
    ASSERT_EQ(multi_el_vector[3], 4);
    ASSERT_EQ(multi_el_vector[4], 5);
    ASSERT_EQ(multi_el_vector[5], 6);
    ASSERT_EQ(multi_el_vector[6], 7);
    ASSERT_EQ(multi_el_vector[7], 8);
    ASSERT_EQ(multi_el_vector[8], 9);
    ASSERT_EQ(multi_el_vector[9], 10);
}

TEST(My_vector, push_back_and_erase){
    // Arrange
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    My_vector multi_el_vector = My_vector<int>();

    // Act
    for (size_t i=0; i<10; i++){
        multi_el_vector.push_back(arr[i]);
//        std::cout << "element " << std::to_string(i) << " = " << multi_el_vector[i]<<std::endl;
    }

    // Assert
    ASSERT_FALSE(multi_el_vector.is_empty());
    ASSERT_EQ(multi_el_vector.arr_size(), 10);
    for (size_t i=0; i<10; i++){
        ASSERT_EQ(multi_el_vector[i], i+1);
    }

    //Act
    multi_el_vector.erase(0);

    // Assert
    ASSERT_FALSE(multi_el_vector.is_empty());
    ASSERT_EQ(multi_el_vector.arr_size(), 9);
    for (size_t i=0; i<9; i++){
        ASSERT_EQ(multi_el_vector[i], i+2);
    }
}

TEST(My_vector, incert_test){
    // Arrange
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    My_vector multi_el_vector = My_vector<int>();

    // Act
    for (size_t i=0; i<10; i++){
        multi_el_vector.push_back(arr[i]);
    }

    // Assert
    ASSERT_EQ(multi_el_vector.arr_size(), 10);
    ASSERT_EQ(multi_el_vector[0], 1);
    ASSERT_EQ(multi_el_vector[1], 2);
    ASSERT_EQ(multi_el_vector[2], 3);
    ASSERT_EQ(multi_el_vector[3], 4);
    ASSERT_EQ(multi_el_vector[4], 5);
    ASSERT_EQ(multi_el_vector[5], 6);
    ASSERT_EQ(multi_el_vector[6], 7);
    ASSERT_EQ(multi_el_vector[7], 8);
    ASSERT_EQ(multi_el_vector[8], 9);
    ASSERT_EQ(multi_el_vector[9], 10);

    // Act
    multi_el_vector.insert(0, 5);
    ASSERT_EQ(multi_el_vector.arr_size(), 11);
    ASSERT_EQ(multi_el_vector[0], 1);
    ASSERT_EQ(multi_el_vector[1], 2);
    ASSERT_EQ(multi_el_vector[2], 3);
    ASSERT_EQ(multi_el_vector[3], 4);
    ASSERT_EQ(multi_el_vector[4], 5);
    ASSERT_EQ(multi_el_vector[5], 0);
    ASSERT_EQ(multi_el_vector[6], 6);
    ASSERT_EQ(multi_el_vector[7], 7);
    ASSERT_EQ(multi_el_vector[8], 8);
    ASSERT_EQ(multi_el_vector[9], 9);
    ASSERT_EQ(multi_el_vector[10], 10);
}

TEST(My_vector, iterator_test){
    // Arrange
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    My_vector multi_el_vector = My_vector<int>();

    // Act
    for (int i : arr){
        multi_el_vector.push_back(i);
    }

    // Assert
    int i = 1;
    for (auto it = multi_el_vector.begin(); it < multi_el_vector.end(); it.next()){
        ASSERT_EQ(it.get(), i);
        i++;
    }
}

int main(int argc, char** argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
