#include<iostream>
using namespace std;
class Heap{
 public:
	int *hArr;
	int cSize;
	int mSize;
	//constructor
	Heap(int mSize){
		hArr=new int[mSize];
		this->mSize=mSize;
		cSize=-1;
	}
	int parent(int i){
		return (i-1)/2;
	}
	int leftchild(int i){
		return 2*i+1;
	}
	int rightchild(int i){
		return 2*i+2;
	}
	void insert(int value){
		cSize++;
		//if it is the first element
		if(cSize==0) hArr[0]=value;
		else{
			hArr[cSize]=value;
			//a function htat checks ht eproperty of hte heap
			prop_compare(cSize);
		}
	}
	//prop_compare function that checks the property and set into ht eproperty
	void prop_compare(int i){
		//stoping condition
		if(hArr[parent(i)]<=hArr[i]|| i==0) return;
		else{
			swap(hArr[parent(i)],hArr[i]);
			prop_compare(parent(i));
		}
	}
	//swap function that swaps the two values
	void swap(int &a,int &b){
		int t=a;a=b;b=t;
	}
	//get_min function that returns the minimum value
	int get_min(){
		return hArr[0];
	}
	//Delete function that dletes at particular position
	int Delete(int i){
		//if this position is not avialable
		if(i>cSize || i<0) cout<<"This position is not avialable"<<endl;
		//first swap the given value with the last one
		else{
			int a=hArr[i];
			swap(hArr[cSize],hArr[i]);
			cSize--;
			MinHeapify(i);
			return a;
		}
	}
	//MinHeapify function that 
	void MinHeapify(int i){
		//stoping condition
		//stoping condition
			if(i>cSize) return;
			else if(hArr[i]<hArr[2*i+1] and hArr[i]<hArr[2*i+2]) return;
			else if(2*i+1>cSize) return;
			else if(2*i+2>cSize and 2*i+1<=cSize) swap(hArr[i],hArr[2*i+1]); 
			//compare with the children and replace accordingly
			else if(hArr[2*i+1]>hArr[2*i+2]) {
				swap(hArr[2*i+2],hArr[i]);
				MinHeapify(2*i+2);
			}
			else {
				swap(hArr[2*i+1],hArr[i]);
				MinHeapify(2*i+1);
			}
		
	}
	//extractmin function extracts the minimum
	int extractmin(){
		return Delete(0);
	}
	void decreaseKey(int i,int new_value){
		//if the given value is greater than the older value
		if(hArr[i]<new_value) cout<<"The given value is greater than the older value."<<endl;
		else{
			hArr[i]=new_value;
			prop_compare(i);
		}
	}
	//destructor
	~Heap(){
		delete hArr;
	}
	void display(){
		for(int i=0;i<=cSize;i++){
			cout<<hArr[i]<<"->";
			//cout<<"("<<i<<","<<hArr[i]<<")"<<endl;
		}
		cout<<"NULL"<<endl;
	}
};
	//define main
int main(){
	Heap h(15);
	for(int i=10;i>0;i--){
		h.insert(i);	
	}
	h.display();
	h.extractmin();
	cout<<"After deleteting the root."<<endl;
	h.display();
	h.Delete(5);
	cout<<"After deleting the element in the 6th position."<<endl;
	h.display();
	cout<<"After decreasing the element in the 6th position."<<endl;
	h.decreaseKey(5,1);
	h.display();
	return 0;
}		
























