#pragma once
class Node {
public:
	Node(float a):_data(a){
		_p = nullptr;
		_head->_data = a;
		_head->_p = nullptr;
		_next = nullptr;
		_final = _head;
	}
	void Insert(Node& i) {
		_final = &i;
		*_next = i;
		i._next = nullptr;
		*_p = i._data;
		i._p = nullptr;
	}
	void Delete_node(float a) {
		Node fore = *_head;
		Node node= *_head;
		float h_data= _head->_data;
		float *p = _head->_p;
		while (h_data != a){
			fore = node;
			node = *(node._next);
			h_data = node._data;
			p = node._p;
			
		}
		Node next = *(node._next);
		delete fore._next;
		fore._next = &next;
		*(fore._p) = next._data;		
	}
	void Delete_node(Node& i) {
		Node fore = *_head;
		Node node = *_head;
		while (node._next != i._next) {
			fore = node;
			node = *(node._next);
		}
		Node next = *(node._next);
		delete fore._next;
		fore._next = &next;
		*(fore._p) = next._data;
	}
	
private:
	Node * _head;
	Node *_final;
	Node* _next;
	float _data;
	float* _p;


};