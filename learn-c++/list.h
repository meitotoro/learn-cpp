#pragma once
class Node {
public:
	Node(float a=0) :_data(a) {
		_next = nullptr;
	}
	Node*& get_next() {
		return _next;
	}
	float get_data() {
		return _data;
	}
private:
	float _data;
	Node *_next;
};
class List {
public:
	List(){
		_head.get_next() = nullptr;
		_final = &_head;
	}
	void Insert(float f) {
		Node* node = new Node(f);
		_final->get_next()=node;
		node->get_next() = nullptr;
	}
	void Delete_node(float a) {
		Node *fore = &_head;
		Node *node= &_head;
		float h_data= fore->get_data();
		while (node && h_data != a){
			fore = node;
			node = node->get_next();
			h_data = node->get_data();			
		}
		if (node == nullptr) { return; }
		Node* next = node->get_next();
		delete fore->get_next();
		fore->get_next() = next;
	}
	void Delete_node(Node* i) {
		if (i = nullptr) return;
		Node* fore = &_head;
		Node* node = &_head;
		while (node&&node != i) {
			fore = node;
			node = node->get_next();
		}
		if (node = nullptr) return;
		Node* next = node->get_next();
		delete fore->get_next();
		fore->get_next() = next;
	}
	~List() {
		Node *node = &_head;
		while (node != nullptr) {
			auto next = node->get_next();
			delete node;
			node = next;
		}
	}
	
private:
	Node _head;
	Node *_final;
};