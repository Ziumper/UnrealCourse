#include <iostream>
#include <thread>
#include <mutex>
#include <vector>
#include <random>
#include <condition_variable>

using namespace std;


/**
Napisz program, który implementuje wzorzec producent-konsument. 
Jeden wątek (producent) generuje losowe liczby i umieszcza je w  buforze (Vector), 
podczas gdy inny wątek (konsument) pobiera liczby z bufora i je wypisuje na konsolę. Unikaj aktywnego czekania.
**/

vector<int> numbers;
mutex mtx;
int index = -1;
int boundSize = 100;
condition_variable cv;


//creation of semaphore
void SetIndexIntoSemaphore(int s_index)
{
    lock_guard<mutex>lock(mtx);
    index = s_index;
}

int GetIndexFromSemaphore()
{
    lock_guard<mutex>lock(mtx);
    return index;
}

/**
* Producing numbers between 0 to 100
**/
void ProduceNumbers()
{
    numbers.reserve(boundSize);
    numbers.resize(boundSize);
    cout << "Entering the producer" << endl;
    srand((unsigned int)time(NULL)); // get current time
    for (int i = 0; i < boundSize; i++)
    {
        int number = rand() % 100;
        cout << "Producing number: " << number << endl;
        numbers[i] = number;
        SetIndexIntoSemaphore(i);
    }
   
    std::cout << "Producer finished the job!!\n";
}

void ConsumeNumbers()
{
    cout << "Entering the consumer" << endl;
    int consumerIndex = -1;
    int producedIndex = GetIndexFromSemaphore();
    while (consumerIndex < producedIndex || producedIndex == -1)
    {
        //here consumer index is lower then produced index so we can consume the number
        bool canConsume = consumerIndex + 1 <= producedIndex;
        if (canConsume) 
        {
            consumerIndex++;
            cout << "Consumer index: " << consumerIndex << " Producer index: " << producedIndex << endl;
            cout << "Consuming the number: " << numbers[consumerIndex] << endl;
        }
         
        if (producedIndex == consumerIndex)
        {
            producedIndex = GetIndexFromSemaphore();
        }
    };
   
    cout << "Consumer finished the job" << endl;
}

int main()
{
    thread producerThread(ProduceNumbers);
    thread consumerThread(ConsumeNumbers);
    producerThread.join();
    consumerThread.join();
    
}
