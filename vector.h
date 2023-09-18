#include <iostream>
template<class T>
class vector{
private:
int size;
int capacity;
T* arr;
public:
vector();
vector(int size);
vector(int size,T el);
~vector();
vector(const T& el);
T at(int index);
int get_size();
int get_capacity();
void push_back(T el);
void pop_back();
T front();
T back();
void sort();
void insert(int index, T a);
bool empty();
void print();
std::ostream operator<<(std::ostream& os);
};
template <class T>
vector<T>::vector()
{
  size = 0;
  capacity = 1;
  arr = new T[capacity];
}
template <class T>
vector<T>::vector(int size){
  size=size;
  capacity=2*size;
  arr=new T[capacity];
  for(int i=0;i<size;++i){
    arr[i]=0;
  }
}
template <class T>
vector<T>::vector(int size,T el){
  size=size;
  capacity=2*size;
  arr=new T[capacity];
  for(int i=0;i<size;++i){
    arr[i]=el;
   }
}
template <class T>
vector<T>::~vector(){
  delete[] arr;
}
template <class T>
vector<T>::vector(const T& el){
  size=el.size;
  capacity=el.capacity;
   for(int i=0;i<size;++i){
     arr[i]=el.arr[i];
   }
}
template<class T>
T vector<T>::at(int index){
  return arr[index];
}
template<class T>
int vector<T>::get_size(){
  return size;
};
template<class T>
int vector<T>::get_capacity(){
  return capacity;
};
template<class T>
void vector<T>::push_back(T el){
  if(size==capacity){
    T* ARR = new T[2*capacity];
    for (int i=0;i<size;++i){
      ARR[i]=arr[i];
    }
    delete []arr;
    capacity=2*capacity;
    arr=ARR;
  }
  arr[size]=el;
  size++;
}
template<class T>
void vector<T>::pop_back(){
  if(!empty()){
    delete arr[size-1];
    size--;
  }
}
template<class T>
T vector<T>::front(){
  if(!empty()){
   return arr[0];
  }
  return T();
}
template<class T>
T vector<T>::back(){
  if(!empty()){
    return arr[size-1];
  }
  return T();
}
template<class T>
void vector<T>::sort(){
  T temp;
    for(int i=0;i<size-1;++i){
         for(int j=i+1;j<size;++j){
          if(arr[i]>arr[j]){
            temp=arr[j];
            arr[j]=arr[i];
            arr[i]=temp;
        }
    }
  }  
} 
template<class T>
void vector<T>::insert(int index,T el){
  if(index>=0 && index<=size){
    if(size==capacity){
      capacity=(capacity==0)?1:capacity*2;
      T* newarr=new T[capacity];
      for(int i=0;i<index;++i){
        newarr[i]=arr[i];
      }
      newarr[index]=el;
      for(int i=index;i<size;++i){
        newarr[i+1]=arr[i];
      }
      size++;
      delete[] arr;
      arr=newarr;
    }
    else{
      for(int i=size;i>index;--i){
        arr[i]=arr[i-1];
      }
      arr[index]=el;
      size++;
    }
  }
}
template<class T>
bool vector<T>::empty(){
    if (size==0)
        return true;
        return false;
    }
template<class T>
void vector<T>::print(){
  for (int i=0;i<size;++i){
    std::cout<<arr[i]<<" ";
  }
}
template<class T>
 std::ostream vector<T>::operator<<(std::ostream& os){
  for(int i=0;i<size;++i){
    os<<arr[i];
  }
}
