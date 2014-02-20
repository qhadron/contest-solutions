/**
	A matrix class
*/

#pragma once

#ifndef _MATRIX_H_
#define _MATRIX_H_

#include <string>
#include <iostream>
#include <cstring>
#include <cmath>
#define PI 3.1415926535
typedef double VEC_TYPE;

namespace JMath {
	class vec4;
	class mat4; 
	template <typename T, size_t M, size_t N>
	class Matrix;
	
	class vec3 {
		VEC_TYPE data[3];
		public:
		vec3() {
			memset(data,0,sizeof(data));
		}
		vec3(VEC_TYPE f) {
			for (size_t i = 0; i < 3; i++)
				data[i]=f;
		}
		vec3(VEC_TYPE x, VEC_TYPE y, VEC_TYPE z) {
			data[0]=x;
			data[1]=y;
			data[2]=z;
		}
		const VEC_TYPE& operator[] (size_t index) const {
			return data[index];
		}
		VEC_TYPE& operator[] (size_t index) {
			return data[index];
		}
		vec3 normalize() {
			vec3 result;
			VEC_TYPE length=sqrt((data[0]*data[0])+(data[1]*data[1])+(data[2]*data[2]));
			result[0]=data[0]/length;
			result[1]=data[1]/length;
			result[2]=data[2]/length;
			return result;
		}
		vec3 operator- (const vec3& other) {
			vec3 result;
			result.data[0]=data[0]-other.data[0];
			result.data[1]=data[1]-other.data[1];
			result.data[2]=data[2]-other.data[2];
			return result;
		}
	};
	
	vec3 normal(vec3 in) {
		return in.normalize();
	}
	
	VEC_TYPE dot(const vec3& lhs, const vec3& rhs) {
		return lhs[0]*rhs[0]+lhs[1]*rhs[1]+lhs[2]*rhs[2];
	}
	
	vec3 cross(const vec3& lhs, const vec3& rhs) {
		vec3 result;
		result[0]=lhs[1]*rhs[2]-lhs[2]*rhs[1];
		result[1]=lhs[0]*rhs[2]-lhs[2]*rhs[0];
		result[3]=lhs[0]*rhs[1]-lhs[1]*rhs[0];
		return result;
	}
	
	class vec4 {
		friend class mat4;
		VEC_TYPE data[4];
		public:
		vec4() {
			memset(data,0,sizeof(data));
		}
		vec4(VEC_TYPE f) {
			for (size_t i = 0; i < 4; i++) {
				data[i]=f;
			}
		}
		
		vec4(VEC_TYPE src[4]) {
			memcpy(data,src,sizeof(src));
		}
		
		vec4(const vec4& src) {
			memcpy(data,src.data,sizeof(src.data));
		}
		
		vec4(VEC_TYPE x, VEC_TYPE y, VEC_TYPE z, VEC_TYPE w) {
			data[0]=x;
			data[1]=y;
			data[2]=z;
			data[3]=w;
		}
		
		VEC_TYPE operator[] (const size_t& index) {
			return data[index];
		}
		
		vec4& operator*= ( VEC_TYPE val) {
			for (size_t i =0 ; i < 4; i++)
				data[i]*=val;
		}
		
		friend vec4 operator* (const vec4& lhs, const mat4& rhs);
		friend vec4 operator* (const mat4& rhs, const vec4& lhs);
		friend std::ostream& operator<< (std::ostream& os, const vec4& m);
	};
	std::ostream& operator<< (std::ostream& os, const vec4& m) {
		for (size_t i = 0; i < 4; i++)
			os << m.data[i] << ((i!=3)?" ":"");
		return os;
	};
	
	class mat4 {
		VEC_TYPE data[4][4];
		public:
			static const size_t M=4,N=4;
			mat4() {
				memset(data,0,sizeof(data));
			}
			mat4(VEC_TYPE f) {
				for (size_t i = 0; i < M; i++) {
					for (size_t j = 0; j < N; j++) {
						data[j][i]=f;
					}
				}
			}
			mat4(VEC_TYPE src[4][4]) {
				for (int i = 0; i < M; i++) {
					memcpy(&data[i],&src[i],sizeof(src[i]));
				}
			}
			mat4(const mat4& src) {
				for (int i = 0; i < M; i++) {
					memcpy(&data[i],&src.data[i],sizeof(src.data[i]));
				}
			}
			template <typename T>
			mat4(const Matrix<T,4,4>& src) {
				for (size_t i = 0; i < M; i++) {
					memcpy(&data[i],&src.data[i],sizeof(src.data[i]));
				}
			}
			
			VEC_TYPE* operator[] (const size_t& index) {
				return data[index];
			}
			
			mat4& operator *= (const mat4& other) {
				mat4 result;
				for (size_t i =0; i < M; i++)
					for (size_t j = 0; j < N; j++) 
						for (size_t k = 0; k < M; k++) 
							result.data[i][j] += (data[i][k] * other.data[k][j]);
				(*this)=result;
				return (*this);
			}
			
			friend vec4 operator* (const vec4& lhs, const mat4& rhs);
			friend vec4 operator* (const mat4& rhs, const vec4& lhs);
			
			friend std::ostream& operator<< (std::ostream& os, const mat4& m);
			friend mat4 perspective(VEC_TYPE fov, VEC_TYPE aspect, VEC_TYPE near, VEC_TYPE far);
	};
	
	mat4 operator* (mat4 lhs, const mat4& rhs) {
		lhs*=rhs;
		return lhs;
	}
	
	vec4 operator* (const vec4& lhs, const mat4& rhs) {
		vec4 result;
		for (size_t i = 0; i < 4; i++) {
			for (size_t j = 0; j <4; j++) {
					result.data[i]+=lhs.data[j]*rhs.data[i][j];
				}
		}
		return result;
	}
	
	vec4 operator* (const mat4& rhs, const vec4& lhs) {
		vec4 result;
		for (size_t i = 0; i < 4; i++) {
			for (size_t j = 0; j <4; j++) {
					result.data[i]+=lhs.data[j]*rhs.data[i][j];
				}
		}
		return result;
	}
	
	mat4 perspective(VEC_TYPE fov, VEC_TYPE aspect, VEC_TYPE near, VEC_TYPE far) {
		mat4 m;
		VEC_TYPE angle = (fov/180.0f)* PI;
		VEC_TYPE f = 1.0 / tan (angle * 0.5);
		
		m[0][0] = f / aspect;
		m[1][1] = f;
		m[2][2] = (far + near) / (near - far);
		m[2][3] = -1.0;
		m[3][2] = (2.0 * far*near) / (near - far);
		return m;
	}
	
	mat4 identity() {
		mat4 result;
		for (size_t i = 0; i < 4; i++)
			result[i][i]=1;
		return result;
	}
	
	mat4 translate(VEC_TYPE x, VEC_TYPE y, VEC_TYPE z) {
		mat4 result=identity();
		result[0][3]=x;
		result[1][3]=y;
		result[2][3]=z;
		return result;
	}
	
	mat4 scale(VEC_TYPE x, VEC_TYPE y, VEC_TYPE z) {
		mat4 result;
		result[0][0]=x;
		result[1][1]=y;
		result[2][2]=z;
		result[3][3]=1;
		return result;
	}
	
	mat4 rotx(VEC_TYPE angle) {
		mat4 mat;
		VEC_TYPE s=sin(angle),c=cos(angle);
		mat[0][0]=1;
		mat[1][1]=c;
		mat[1][2]=-s;
		mat[2][1]=s;
		mat[2][2]=c;
		mat[3][3]=1;
		return mat;
	}
	
	mat4 roty(VEC_TYPE angle) {
		mat4 mat;
		VEC_TYPE s=sin(angle),c=cos(angle);
		mat[0][0]=c;
		mat[0][2]=s;
		mat[1][1]=1;
		mat[0][2]=-s;
		mat[0][2]=c;
		mat[3][3]=1;
		return mat;
	}
	
	mat4 rotz(VEC_TYPE angle) {
		mat4 mat;
		VEC_TYPE s=sin(angle),c=cos(angle);
		mat[0][0]=c;
		mat[0][1]=-s;
		mat[1][0]=s;
		mat[1][1]=c;
		mat[2][2]=1;
		mat[3][3]=1;
		return mat;
	}
	
	mat4 rotate(VEC_TYPE theta, VEC_TYPE phi, VEC_TYPE psi) {
		VEC_TYPE A=cos(theta),C=cos(phi),E=cos(psi);
		VEC_TYPE B=sin(theta),D=sin(phi),F=sin(psi);
		VEC_TYPE AD = A*D, BD = B*D;
		mat4 mat;
		mat[0][0]  =   C * E;
		mat[0][1]  =  -C * F;
		mat[0][2]  =   D;
		mat[1][1]  =  BD * E + A * F;
		mat[1][2]  = -BD * F + A * E;
		mat[1][3]  =  -B * C;
		mat[2][0]  = -AD * E + B * F;
		mat[2][1]  =  AD * F + B * E;
		mat[2][3] =   A * C;
		mat[3][3] =  1;
		return mat;
	}
	
	mat4 rotate(vec4 angles) {
		VEC_TYPE A=cos(angles[0]),C=cos(angles[1]),E=cos(angles[2]);
		VEC_TYPE B=sin(angles[0]),D=sin(angles[1]),F=sin(angles[2]);
		VEC_TYPE AD = A*D, BD = B*D;
		mat4 mat;
		mat[0][0]  =   C * E;
		mat[0][1]  =  -C * F;
		mat[0][2]  =   D;
		mat[1][1]  =  BD * E + A * F;
		mat[1][2]  = -BD * F + A * E;
		mat[1][3]  =  -B * C;
		mat[2][0]  = -AD * E + B * F;
		mat[2][1]  =  AD * F + B * E;
		mat[2][3] =   A * C;
		mat[3][3] =  1;
		return mat;
	}
	
	mat4 model(const mat4& scale, const mat4& rot, const mat4& trans) {
		return ((scale*rot)*trans);
	}
	
	mat4 lookAt(vec3 pos, vec3 target, vec3 up) {
		vec3 zaxis = normal(pos-target);
		vec3 xaxis = normal(cross(up,zaxis));
		vec3 yaxis = cross(zaxis,xaxis);
		mat4 result;
		result[0][0]=xaxis[0];
		result[0][1]=yaxis[0];
		result[0][2]=zaxis[0];
		
		result[1][0]=xaxis[1];
		result[1][1]=yaxis[1];
		result[1][2]=zaxis[1];
		
		result[2][0]=xaxis[2];
		result[2][1]=yaxis[2];
		result[2][2]=zaxis[2];
		
		result[3][0]=-dot(xaxis,pos);
		result[3][1]=-dot(yaxis,pos);
		result[3][2]=-dot(zaxis,pos);
		result[3][3]=1;
		return result;
		
	}
	
	template < typename T , size_t M, size_t N>
	class Matrix {
		T data[M][N];
		template < typename, size_t, size_t> friend class Matrix;
		friend class mat4;
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
			
			T** getdata() {
				return data;
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
	ostream& operator<< (ostream& os, const mat4& m) {
		for (size_t i = 0 ; i < 4; i++) {
			for (size_t j = 0; j <4; j++) {
				os << (double)m.data[i][j] <<  ((j!=(3))?"\t":(i!=(3))?"\n":"") ;
			}
		}
		return os;
	}
	
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