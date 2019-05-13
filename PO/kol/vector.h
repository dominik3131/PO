#ifndef vec_H
#define vec_H
#include <string.h>
using namespace std;
class Vect
{
	public:
		void setElement(int indeks, double liczba){
			while(indeks>=this->sizeOfVec) throw outOfRange();
			
			data[indeks]=liczba;		
		}

		int getSize(){
			return this->sizeOfVec;		
		}

		double getAverage(){
			double sum=0;
			for(int i=0;i<sizeOfVec;i++){
				sum+=data[i];
			}
			if(sum!=0) return sum/sizeOfVec;
			else	return 0;
		}
		double getMin(){
			double min=data[0];
			for(int i=1;i<sizeOfVec;i++){
				if(data[i]<min)	min=data[i];
			}
			return min;
		}
		
		Vect(int x){
			data = new double[x];
			sizeOfVec=x;
		}

		~Vect(){
			delete[] this->data;
		}

		Vect operator+ (const Vect& v){
			Vect vCopy(this->sizeOfVec+v.sizeOfVec);

			memcpy( vCopy.data, this->data, this->sizeOfVec * sizeof(double) );
			memcpy( vCopy.data+this->sizeOfVec, v.data, v.sizeOfVec * sizeof(double) );
  
			return vCopy;
		}
		
		Vect operator= (const Vect& v){
			double* vCopy=new double[v.sizeOfVec];		
			memcpy( vCopy, v.data, v.sizeOfVec * sizeof(double) );
    			this->sizeOfVec=v.sizeOfVec;
    			delete [] this->data;
    			this->data = vCopy;
			return *this;
		}
		friend ostream& operator<<( ostream& out, const Vect & vec ){
    			out<<"[";
			for(int i=0;i<vec.sizeOfVec;i++){
				out<<vec.data[i]<<" ";
			}
			out<<"]";
			return out;
		};

		class outOfRange{};
	private:
		int sizeOfVec;
		double* data;
		
};
#endif
