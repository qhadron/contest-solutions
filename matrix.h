/**
	A matrix class
*/

#pragma once

#ifndef _MATRIX_H_
#define _MATRIX_H_

#include <string>
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <exception>

namespace JMath {
	template < typename T , size_t M, size_t N>
	class Matrix {
		T data[M][N];
		template < typename, size_t, size_t> friend class Matrix;
		public:
			const size_t R=M, C=N;
		
			Matrix () {
				memset(data,0,sizeof(data));
			}
			
			Matrix (const Matrix& src) {
				for (int i = 0; i < M; i++) {
					memcpy(&data[i],&src.data[i],sizeof(src.data[i]));
				}
			}	
			
			Matrix (const T src[M][N] ) {
				for (int i = 0; i < M; i++) {
					for (int j = 0; j < N; j++) {
						data[i][j]=src[i][j];
					}
				}
			}			
			
			void rand(unsigned int seed) {
				for (int i = 0; i < M; i++) {
					for (int j = 0; j < N; j++) {
						data[i][j]=std::rand(seed);
					}
				}
			}
			
			void rand() {
				for (int i = 0; i < M; i++) {
					for (int j = 0; j < N; j++) {
						data[i][j]=std::rand();
					}
				}
			}
			
			Matrix getIdentity() {
				#define MIN ((M<N)?M:N)
				Matrix<T,MIN,MIN> m;
				for (int i = 0; i < MIN; i++) {
					m[i][i]=1;
				}
				return m;
				#undef MIN
			}
			
			//swaw rows a,j
			void swap(size_t i, size_t j) {
				std::swap(data[i],data[j]);
			}
			
			Matrix<T,N,M> transpose() {
				Matrix<T,N,M>  A;
				for (int i = 0; i < M; i++)
					for (int j = 0; j < N; j++)
						A[j][i] = data[i][j];
				return A;
			}
			
			T* operator[] (size_t M) {
				return data[M];
			}

			Matrix& operator+= (const Matrix& other) {
				for (size_t i = 0; i < M; i++)
					for (size_t j = 0; j < N; j++)
						this->data[i][j]+=other.data[i][j];
				return *this;
			}
			
			Matrix operator+ (Matrix other) {
				return (other+=(*this));
			}
			
			Matrix& operator-= (const Matrix& other) {
				for (size_t i = 0; i < M; i++)
					for (size_t j = 0; j < N; j++)
						this->data[i][j]-=other.data[i][j];
				return *this;
			}
			
			Matrix operator- (Matrix other) {
				return (other-=(*this));
			}
			
			Matrix& operator*= (T num) {
				for (size_t i =0; i < M; i++)
					for (size_t j = 0; j < N; j++) 
						data[i][j]*=num;
				return *this;
			}
			
			Matrix operator* (T num) {
				Matrix temp = (*this);
				for (size_t i =0; i < M; i++)
					for (size_t j = 0; j < N; j++) 
						temp.data[i][j]*=num;
				return temp;
			}
			
			bool operator== (const Matrix& other) {
				for (int i = 0; i < M; i++)
					for (int j = 0; j < N; j++)
						if (data[i][j]!=other.data[i][j])
							return false;
				return true;
			}
			
			bool operator!= (const Matrix& other) {
				return (!((*this)==other));
			}
			
			template <typename T, size_t m, size_t n>
			Matrix<T,M,n> operator* (const Matrix<T,m,n>& other) {
				if (N!=m) return NULL;
				Matrix<T,M,n> C;
				for (int i = 0; i < M; i++)
					for (int j = 0; j < n; j++)
						for (int k = 0; k < N; k++)
							C.data[i][j] += (data[i][k] * other.data[k][j]);
				return C;
			}
			
			template < class T, size_t M, size_t N >
			friend std::ostream& operator<< (std::ostream& os, const Matrix<T,M,N>& m);
			
			T get(size_t i, size_t j) {
				return data[i][j];
			}
			
			T& at(size_t i, size_t j) {
				return data[i][j];
			}
			
			void set(size_t i, size_t j, T& val) {
				data[i][j] = val;
				return;
			}
			
	};

	template <class T, size_t N>
    Matrix<T,N,N> getIdentityMatrix() {
        Matrix<T,N,N> I;
        for (int i = 0; i < N; i++)
            I[i][i] = 1;
        return I;
    }
	
	using std::ostream;
	template < class T, size_t M, size_t N >
	ostream& operator<< (ostream& os, const JMath::Matrix<T,M,N>& m) {
		for (int i = 0; i < M; i++) {
			for (int j = 0; j < N; j++) {
				os << m.data[i][j] <<  ((j!=(N-1))?"\t":(i!=(M-1))?"\n":"") ;
			}
		}
		return os;
	}

}

#endif