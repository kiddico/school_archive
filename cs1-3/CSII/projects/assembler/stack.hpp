#ifndef LABSTACK_HPP
#define LABSTACK_HPP
#include <iostream>
#include <new>
#include <cassert>
template <typename T>
	class node{
		public:
			T data;
			node<T> *next;
			node():next(0){};
			node(const T& x):data(x),next(0){};
	};

template <typename T>
	class Stack{
		private:
			node <T> *TOS;
		public:
			Stack():TOS(0){};
			~Stack();
			Stack(const Stack<T>&);
			void swap(Stack<T>&);
			Stack<T> operator=(Stack<T> RHS){swap(RHS);return *this;}
			bool isEmpty()const{return TOS==0;}
			bool isFull()const;
			T pop();
			void push(const T&);
	};
	template <typename T>
		Stack<T>::~Stack(){
			while(TOS!=0){
				node<T> *temp=TOS;
				TOS=TOS->next;
				delete temp;
			}
		}
	
	template <typename T>
		Stack<T>::Stack(const Stack<T>& actual){
			node<T> *bottom=0;
			node <T> *temp=actual.TOS;
			TOS=0;
			while(temp!=0){
				if(bottom==0){
					TOS=new node<T>(temp->data);
					bottom->TOS;
				}
				else{
					bottom->next=new node<T> (temp->data);
					bottom=bottom->next;
				}
				temp=temp->next;
			}
		}
	template <typename T>
		void Stack<T>::swap(Stack<T>& x){
			node<T> *temp=x.TOS;
			x.TOS=TOS;
			TOS=temp;
		}
	template <typename T>
		bool Stack<T>::isFull()const{
			node<T> *temp=new (std::nothrow) node<T>();
			if(temp==0)
				return true;
			delete temp;
			return false;
		}	
	template <typename T>
		T Stack<T>::pop(){
			assert(TOS!=0);
			T result=TOS->data;
			node<T> *tmp=TOS;
			TOS=TOS->next;
			delete tmp;
			return result;
		}
	template <typename T>
		void Stack<T>::push(const T& x){
			assert(!isFull());
			node<T> *tmp=new node <T> (x);
			tmp->next=TOS;
			TOS=tmp;
		}
#endif
