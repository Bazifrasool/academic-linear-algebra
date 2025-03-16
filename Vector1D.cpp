#include <algorithm>
#include <bits/stdc++.h>
#include <cassert>
#include <vector>
using namespace std;
template <typename T>
class Vector1D{
    protected:
    vector<T> data;
    public:
    T& operator[](unsigned int index){
        return data[index];
    }
    Vector1D(unsigned int size){
        data.resize(size);
    }
    Vector1D(const Vector1D & other){
        data.resize(other.data.size());
        std::copy(other.data.begin(),other.data.end(),data.begin());
        }

    Vector1D()=default;

    Vector1D(unsigned int size,T value){
        data.resize(size);
        for(auto &i : data){
            i=value;
        }
    }
    void display(){
        for(auto i: data){
            cout<<"-"<<i;
        }
        cout<<endl;
    }
    friend Vector1D<T> operator+(const Vector1D<T>& lhs ,const Vector1D<T>& rhs ){
        if(lhs.data.size() != rhs.data.size()){
            assert(lhs.data.size() != rhs.data.size());
        }
        Vector1D<T> result;
        result.data.reserve(lhs.data.size());
        for(auto i = 0 ; i < lhs.data.size();i++){
            result.data.push_back(lhs.data[i]+rhs.data[i]);
        }
        return result;
    }
    friend Vector1D<T> operator*(const Vector1D<T>& lhs ,const Vector1D<T>& rhs ){
        if(lhs.data.size() != rhs.data.size()){
            assert(lhs.data.size() != rhs.data.size());
        }
        Vector1D<T> result;
        result.data.reserve(lhs.data.size());
        for(auto i = 0 ; i < lhs.data.size();i++){
            result.data.push_back(lhs.data[i]*rhs.data[i]);
        }
        return result;
    }
    friend Vector1D<T> operator-(const Vector1D<T>& lhs ,const Vector1D<T>& rhs ){
        if(lhs.data.size() != rhs.data.size()){
            assert(lhs.data.size() != rhs.data.size());
        }
        Vector1D<T> result;
        result.data.reserve(lhs.data.size());
        for(auto i = 0 ; i < lhs.data.size();i++){
            result.data.push_back(lhs.data[i]-rhs.data[i]);
        }
        return result;
    }
    friend Vector1D<T> operator/(const Vector1D<T>& lhs ,const Vector1D<T>& rhs ){
        if(lhs.data.size() != rhs.data.size()){
            assert(lhs.data.size() != rhs.data.size());
        }
        Vector1D<T> result;
        result.data.reserve(lhs.data.size());
        for(auto i = 0 ; i < lhs.data.size();i++){
            assert(rhs.data[i]!=0);
            result.data.push_back(lhs.data[i]/rhs.data[i]);
        }
        return result;
    }
    Vector1D<T>& operator=(const Vector1D<T>& other){
        assert(other.data.size()==this->data.size());
        std::copy(other.data.begin(),other.data.end(),data.begin());
        return *(this);
    }
};
template<typename T>
class Matrix2D : public Vector1D<T>{
    public:
    unsigned int rows,cols;
    Matrix2D<T>(unsigned int rows , unsigned int cols) : Vector1D<T>(rows*cols) , rows(rows), cols(cols){
        cout<<"Matrix Constructed"<<endl;
    }
    Matrix2D<T>(unsigned int rows , unsigned int cols, T value) : Vector1D<T>(rows*cols,value) , rows(rows), cols(cols){
        cout<<"Matrix Constructed with values"<<endl;;
    }
    friend Matrix2D<T> operator+(const Matrix2D<T> & lhs,const Matrix2D<T> & rhs){
        Matrix2D<T> result(lhs.rows,lhs.cols);
         static_cast<Vector1D<T>&>(result) = static_cast<Vector1D<T>>(lhs) + static_cast<Vector1D<T>>(rhs);
        return result;
    }
    class Proxy{
        private:
        vector<T> & refData;
        unsigned int rowIndex;
        unsigned int colIndex;
        public:
        Proxy(vector<T> & refData,unsigned int row_index):refData(refData),rowIndex(row_index){

        }
        T& operator[](unsigned int index){
            return refData[rowIndex+index];
        }
    };
    Proxy operator[](const unsigned int index){
        // calculate the index in linear.
        auto sel_row=rows * index;
        return Proxy(this->data,sel_row);
        
    }
    Matrix2D<T>& operator=(const Matrix2D<T>& other){
        assert(other.data.size()==this->data.size());
        std::copy(other.data.begin(),other.data.end(),this->data.begin());
        return *(this);
    }
};

int main(){
    Vector1D<float> test(10,2.2);
    Vector1D<float> test2(test);
    Vector1D<float> test3(test);
    auto res = test + test2+ test3;
    res.display();
    // res = res+test;
    // res.display();
    Matrix2D<float> f (3,3,12);
    Matrix2D<float> e (3,3,10);
    auto g = e+f;
    g.display();
    g[0][0] = 123;
    g.display();

    return 0;
}