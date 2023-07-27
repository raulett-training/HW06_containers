//
// Created by raulett on 08.07.2023.
//
#include <iostream>
#include <gtest/gtest.h>
#include "My_list.h"
#include "DestructorTracer.h"

//empty Container creation
TEST(My_list, empty_constructor){
    // Arrange
    My_list empty_container = My_list<int>();
    // Act

    // Assert
    ASSERT_EQ(empty_container.arr_size(), 0);
    ASSERT_TRUE(empty_container.is_empty());
}

//single element Container creation
TEST(My_list, single_element_constructor){
    My_list sing_el_list = My_list<int>(4);

    ASSERT_EQ(sing_el_list[0], 4);
    ASSERT_EQ(sing_el_list.arr_size(), 1);
    ASSERT_FALSE(sing_el_list.is_empty());
}

//multiple element Container creation
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

//pushback element to container
TEST(My_list, push_back){
    // Arrange
    My_list list_container = My_list<int>();
    // Act
    list_container.push_back(1, 2, 3, 4, 5, 6, 7, 8, 9, 10);
    // Assert
    ASSERT_FALSE(list_container.is_empty());
    ASSERT_EQ(list_container.arr_size(), 10);
    ASSERT_EQ(list_container[0], 1);
    ASSERT_EQ(list_container[1], 2);
    ASSERT_EQ(list_container[2], 3);
    ASSERT_EQ(list_container[3], 4);
    ASSERT_EQ(list_container[4], 5);
    ASSERT_EQ(list_container[5], 6);
    ASSERT_EQ(list_container[6], 7);
    ASSERT_EQ(list_container[7], 8);
    ASSERT_EQ(list_container[8], 9);
    ASSERT_EQ(list_container[9], 10);
}

//pushback element at start position
TEST(My_list, push_at_start_position){
    // Arrange
    My_list list_container = My_list<int>();
    // Act
    list_container.push_back(1, 2, 3, 4, 5, 6, 7, 8, 9, 10);
    list_container.insert(0, 0);
    // Assert
    ASSERT_EQ(list_container.arr_size(), 11);
    ASSERT_EQ(list_container[0], 0);
    ASSERT_EQ(list_container[10], 10);
}

//insert at middle position
TEST(My_list, push_at_middle_position){
    // Arrange
    My_list list_container = My_list<int>();
    // Act
    list_container.push_back(1, 2, 3, 4, 5, 6, 7, 8, 9, 10);
    list_container.insert(0, 5);
    // Assert
    ASSERT_EQ(list_container.arr_size(), 11);
    ASSERT_EQ(list_container[0], 1);
    ASSERT_EQ(list_container[1], 2);
    ASSERT_EQ(list_container[2], 3);
    ASSERT_EQ(list_container[3], 4);
    ASSERT_EQ(list_container[4], 5);
    ASSERT_EQ(list_container[5], 0);
    ASSERT_EQ(list_container[6], 6);
}

//delete element from the end of container
TEST(My_list, delete_element_from_the_end){
    // Arrange
    My_list list_container = My_list<int>();
    // Act
    list_container.push_back(1, 2, 3, 4, 5, 6, 7, 8, 9, 10);
    list_container.erase(list_container.arr_size()-1);
    // Assert
    ASSERT_EQ(list_container.arr_size(), 9);
    ASSERT_EQ(list_container[0], 1);
    ASSERT_EQ(list_container[8], 9);
}

//delete element from the end of container
TEST(My_list, delete_element_from_the_begining){
    // Arrange
    My_list list_container = My_list<int>();
    // Act
    list_container.push_back(1, 2, 3, 4, 5, 6, 7, 8, 9, 10);
    list_container.erase(0);
    // Assert
    ASSERT_EQ(list_container.arr_size(), 9);
    ASSERT_EQ(list_container[0], 2);
    ASSERT_EQ(list_container[1], 3);
    ASSERT_EQ(list_container[2], 4);
    ASSERT_EQ(list_container[3], 5);
    ASSERT_EQ(list_container[4], 6);
    ASSERT_EQ(list_container[5], 7);
    ASSERT_EQ(list_container[6], 8);
    ASSERT_EQ(list_container[7], 9);
    ASSERT_EQ(list_container[8], 10);
}

//delete element from the middle of container
TEST(My_list, delete_element_from_the_middle){
    // Arrange
    My_list list_container = My_list<int>();
    // Act
    list_container.push_back(1, 2, 3, 4, 5, 6, 7, 8, 9, 10);
    list_container.erase(5);
    // Assert
    ASSERT_EQ(list_container.arr_size(), 9);
    ASSERT_EQ(list_container[0], 1);
    ASSERT_EQ(list_container[1], 2);
    ASSERT_EQ(list_container[2], 3);
    ASSERT_EQ(list_container[3], 4);
    ASSERT_EQ(list_container[4], 5);
    ASSERT_EQ(list_container[5], 7);
    ASSERT_EQ(list_container[6], 8);
    ASSERT_EQ(list_container[7], 9);
    ASSERT_EQ(list_container[8], 10);
}

//get element by index
TEST(My_list, get_by_index){
    // Arrange
    My_list list_container = My_list<int>();
    // Act
    list_container.push_back(1, 2, 3, 4, 5, 6, 7, 8, 9, 10);
    // Assert
    ASSERT_EQ(list_container.arr_size(), 10);
    ASSERT_EQ(list_container[0], 1);
    ASSERT_EQ(list_container[1], 2);
    ASSERT_EQ(list_container[2], 3);
    ASSERT_EQ(list_container[3], 4);
    ASSERT_EQ(list_container[4], 5);
    ASSERT_EQ(list_container[5], 6);
    ASSERT_EQ(list_container[6], 7);
    ASSERT_EQ(list_container[7], 8);
    ASSERT_EQ(list_container[8], 9);
    ASSERT_EQ(list_container[9], 10);
}

//get container size
TEST(My_list, get_size){
    // Arrange
    My_list list_container = My_list<int>();
    // Act
    list_container.push_back(1, 2, 3, 4, 5, 6, 7, 8, 9, 10);
    // Assert
    ASSERT_EQ(list_container.arr_size(), 10);
}

//test container copy
TEST(My_list, container_copy){
    // Arrange
    My_list list_container = My_list<int>();
    // Act
    list_container.push_back(1, 2, 3, 4, 5, 6, 7, 8, 9, 10);
    ASSERT_EQ(list_container.arr_size(), 10);
    ASSERT_EQ(list_container[0], 1);
    ASSERT_EQ(list_container[1], 2);
    ASSERT_EQ(list_container[2], 3);
    ASSERT_EQ(list_container[3], 4);
    ASSERT_EQ(list_container[4], 5);
    ASSERT_EQ(list_container[5], 6);
    ASSERT_EQ(list_container[6], 7);
    ASSERT_EQ(list_container[7], 8);
    ASSERT_EQ(list_container[8], 9);
    ASSERT_EQ(list_container[9], 10);
    My_list copy_list_container = My_list(list_container);
    // Assert
    ASSERT_EQ(list_container.arr_size(), 10);
    ASSERT_EQ(list_container[0], 1);
    ASSERT_EQ(list_container[1], 2);
    ASSERT_EQ(list_container[2], 3);
    ASSERT_EQ(list_container[3], 4);
    ASSERT_EQ(list_container[4], 5);
    ASSERT_EQ(list_container[5], 6);
    ASSERT_EQ(list_container[6], 7);
    ASSERT_EQ(list_container[7], 8);
    ASSERT_EQ(list_container[8], 9);
    ASSERT_EQ(list_container[9], 10);

    ASSERT_EQ(copy_list_container.arr_size(), 10);
    ASSERT_EQ(copy_list_container[0], 1);
    ASSERT_EQ(copy_list_container[1], 2);
    ASSERT_EQ(copy_list_container[2], 3);
    ASSERT_EQ(copy_list_container[3], 4);
    ASSERT_EQ(copy_list_container[4], 5);
    ASSERT_EQ(copy_list_container[5], 6);
    ASSERT_EQ(copy_list_container[6], 7);
    ASSERT_EQ(copy_list_container[7], 8);
    ASSERT_EQ(copy_list_container[8], 9);
    ASSERT_EQ(copy_list_container[9], 10);
}

//container move test
TEST(My_list, container_move) {
    // Arrange
    My_list list_container = My_list<int>();
    // Act
    list_container.push_back(1, 2, 3, 4, 5, 6, 7, 8, 9, 10);
    ASSERT_EQ(list_container.arr_size(), 10);
    ASSERT_EQ(list_container[0], 1);
    ASSERT_EQ(list_container[1], 2);
    ASSERT_EQ(list_container[2], 3);
    ASSERT_EQ(list_container[3], 4);
    ASSERT_EQ(list_container[4], 5);
    ASSERT_EQ(list_container[5], 6);
    ASSERT_EQ(list_container[6], 7);
    ASSERT_EQ(list_container[7], 8);
    ASSERT_EQ(list_container[8], 9);
    ASSERT_EQ(list_container[9], 10);

    My_list move_list_container = My_list(std::move(list_container));
    ASSERT_EQ(move_list_container.arr_size(), 10);
    ASSERT_EQ(move_list_container[0], 1);
    ASSERT_EQ(move_list_container[1], 2);
    ASSERT_EQ(move_list_container[2], 3);
    ASSERT_EQ(move_list_container[3], 4);
    ASSERT_EQ(move_list_container[4], 5);
    ASSERT_EQ(move_list_container[5], 6);
    ASSERT_EQ(move_list_container[6], 7);
    ASSERT_EQ(move_list_container[7], 8);
    ASSERT_EQ(move_list_container[8], 9);
    ASSERT_EQ(move_list_container[9], 10);
}



TEST(My_list, destructor_test){
    DestructorTracer::constructor_count = 0;
    DestructorTracer::destructor_count = 0;
    {
        My_list my_tracer_list = My_list<DestructorTracer>();
        for(int i = 0; i < 10; i++){
            my_tracer_list.push_back(DestructorTracer{});
        }
//Вот в этом месте constructor_count == 20 - Это я более-менее понимаю почему, потому, что
// в my_tracer_list.push_back(DestructorTracer{}); создается объект DestructorTracer И его копия добавляется в
// my_tracer_list, а потом оригинал уничтожается и счетчик destructor_count инкриментится.
//Но в то же время в этом месте destructor_count тоже == 20. Почему так? Почему деструктор вызвался столько же раз,
// сколько и конструктор?
        ASSERT_EQ(DestructorTracer::constructor_count, 20);
        ASSERT_EQ(DestructorTracer::destructor_count, 20);
    }
//    А вот тут destructor_count == 30 а constructor_count==20, что вообще мне не понятно. Как это объяснить?
//    Можете подсказать?
    ASSERT_EQ(DestructorTracer::destructor_count, 30);
    ASSERT_EQ(DestructorTracer::constructor_count, 20);
}

//container iterator test
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