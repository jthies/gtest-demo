#pragma once

#include <memory>
#include <iostream>

template<typename T>
class Vector
{
public:
  // constructor that allocates n elements
  Vector(int n): length_(n), data_(new T[n]) {}
  // initializer-list constructor
    Vector(const std::initializer_list<double>& list) : Vector(list.size()) {
        std::uninitialized_copy(list.begin(), list.end(), &data_[0]);
    }

  // destructor
  ~Vector() {}

  Vector(Vector&&)=default;
  Vector(Vector const&)=delete;
  Vector& operator=(Vector&&)=default;
  Vector& operator=(Vector const&)=delete;

  // element access (const)
  const T& operator[](int i) const {return data_[i];}

  // element access (non-const)
  T& operator[](int i) {return data_[i];}

  int length() const {return length_;}

  // note: there's a bug here related to the return type
  template<typename S>
  Vector<T> operator+(const Vector<S>& other)
  {
    if (length()!=other.length()) throw std::logic_error("operator+: Vector length mismatch");
    Vector<T> result(length_);
    for (int i=0; i<length_; i++) result[i]=(*this)[i]+other[i];
    return result;
  }

  Vector operator-(const Vector& other)
  {
    // oops, forgot the length check
    Vector<T> result(length_);
    for (int i=0; i<length_; i++) result[i]=(*this)[i]+other[i];
    return result;
  }

private:
  // array to store the elements of the Vector
  std::unique_ptr<T[]> data_;
  // length of the Vector
  int length_;
};

template<typename T>
std::ostream& operator<<(std::ostream& os, const Vector<T>& v)
{
  os << "[ ";
  for (int i=0; i<v.length(); i++) os << v[i] << " ";
  os << "]";
  return os;
}

