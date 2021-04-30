#include <stdexcept>
#include <list>
#include <random>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

// uses a vector to creat a Binar Heap
class BinHeap{
    private:
        vector<int> heapvector;
        int currentSize;

    public:
        BinHeap(vector<int> heapvector){
            this->heapvector = heapvector;
            this->currentSize = 0;
        }
        int min() {return heapvector.at(0);};
        void percUp(int i){
            while ((i / 2) > 0){
                if (this->heapvector[i] < this->heapvector[i/2]){
                    int tmp = this->heapvector[i/2];
                    this->heapvector[i/2] = this->heapvector[i];
                    this->heapvector[i] = tmp;
                }
                i = i/2;
            }
        }
        void insert(int k){
            this->heapvector.push_back(k);
            this->currentSize = this->currentSize + 1;
            this->percUp(this->currentSize);
        }
        void percDown(int i){
            while ((i*2) <= this->currentSize){
                int mc = this->minChild(i);
                if (this->heapvector[i] > this->heapvector[mc]){
                    int tmp = this->heapvector[i];
                    this->heapvector[i] = this->heapvector[mc];
                    this->heapvector[mc] = tmp;
                }
                i = mc;
            }
        }
        int delMin(){
            if (this->currentSize > 1){
                int retval = this->heapvector[1];
                this->heapvector[1] = this->heapvector[this->currentSize];
                this->currentSize = this->currentSize - 1;
                this->heapvector.pop_back();
                this->percDown(1);
                return retval;
            }
            else{
                int retval = this->heapvector[0];
                this->heapvector[1] = this->heapvector[this->currentSize];
                this->currentSize = this->currentSize - 1;
                this->heapvector.pop_back();
                this->percDown(1);
                return retval;
            }
        }
        void buildheap(vector<int> avector){
            int i = avector.size() / 2;
            this->currentSize = avector.size();
            this->heapvector = avector;
            while (i > 0){
                this->percDown(i);
                i = i - 1;
            }
        }
        int minChild(int i){
            if (((i*2)+1) > this->currentSize){
                return i * 2;
            }
            else{
                if (this->heapvector[i*2] < this->heapvector[(i*2)+1]){
                    return i * 2;
                }
                else{
                    return (i * 2) + 1;
                }
            }
        }
};


int main(){
    int arr[] = {100000,1000002,133245};
    vector<int> a(arr,arr+(sizeof(arr)/ sizeof(arr[0])));

    vector<int> vec;
    vec.push_back(0);

    BinHeap *h = new BinHeap(vec);
    // h->buildheap(a);

	srand(time(NULL));
	int input[10];
	for(int i = 0; i < 10; i++){
	  input[i] = rand()%1000;
	  cout << "insert " << input[i] << endl;	  
	  h->insert(input[i]);
	  cout << "finished insert" << endl << endl;
	}
	std::sort(input,input+10);
	cout << "Expected Output:" << endl;
	for(int i = 0; i < 10; i++){
	  cout << input[i] << ' ';
	}
	cout << endl;
	cout << "Your Output:" << endl;
	for(int i = 0; i < 10; i++){
	  if(h->min() != input[i]){
	    cout << h->min() << " out of order removal" << endl;
	  }
	  int n = h->delMin();

	  cout << n << ' ';
	}
	cout << "finished" << endl;


    return 0;
}
