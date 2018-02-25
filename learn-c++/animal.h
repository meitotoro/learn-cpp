#pragma once
#include <string>
#include <iostream>
#include <map>
#include <ostream>

using std::string;//有颜色的代表类或结构体
using std::cout;//没有颜色的是对象
using std::endl;
using std::map;
using std::ostream;

class Animal {
public:
	Animal(string str) :_name(str) {

	}
	string get_name() {
		return _name;
	}
	virtual string speak() = 0;
private:
	string _name;
};
class Cat :public Animal {
private:
	Cat(string str) :Animal(str) {}
public:	
	string speak() {
		return "meow~ ";
	}
	static Cat* create(string name) {
		Cat* cat = new Cat(name);
		return cat;
	}
};
class Dog :public Animal {
private:
	Dog(string str) :Animal(str) {}
public:	
	string speak() {
		return "wong~ ";
	}
	static Dog* create(string name) {
		Dog* dog = new Dog(name);
		return dog;
	}
};
class Zoo {
public:
	Zoo() {

	}
	bool insert(Animal* animal) {
		string name = animal->get_name();
		auto insert = _map.insert(std::make_pair(name, animal));
		return insert.second;
	}
	Animal* find(string name) {
		auto search = _map.find(name);
		if (search != _map.end()) {
			Animal* animal = search->second;
			return animal;
		}
		else {
			return nullptr;
		}
	}
	Animal* del(string name) {
		Animal* animal = find(name);
		if (animal) {
			_map.erase(name);
			return animal;
		}
		else {
			return nullptr;
		}
	}
	bool move(string name, Zoo* to) {
		Animal* ani = find(name);
		if (ani == nullptr) return false;
		bool success = to->insert(ani);
		if (success) {
			del(name);
		}
		return success;

	}
	friend ostream& operator<<(ostream& os,const Zoo& zoo) {
		for (auto pair : zoo._map) {
			os << pair.second->speak() << " ";
		}
		os << endl;
		return os;
	}
private:
	map<string, Animal*> _map;
};