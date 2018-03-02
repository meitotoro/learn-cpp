#include "animal.h"

int main3() {
	string cat_name1 = "mimi";
	string cat_name2 = "meow";
	string dog_name1 = "wangcai";
	string dog_name2 = "shuaishuai";
	string dog_name3 = "xiaobai";
	Zoo zoo1;
	Zoo zoo2;
	Animal* animal=Cat::create(cat_name1);
	zoo1.insert(animal);
	animal = Cat::create(cat_name2);
	zoo1.insert(animal);
	animal = Dog::create(dog_name1);
	zoo1.insert(animal);
	animal = Dog::create(dog_name2);
	zoo1.insert(animal);
	animal = Dog::create(dog_name3);
	zoo1.insert(animal);
	cout << zoo1;
	zoo1.move("mimi", &zoo2);
	cout << zoo1;
	cout << zoo2;

	return 0;
}