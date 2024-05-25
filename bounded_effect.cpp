#include <iostream>
#include <queue>
#include <thread>
#include <semaphore.h>

using namespace std;

queue<int> buffer;
sem_t emptySlots;
sem_t fullSlots;
bool done = false;  // Flag to indicate when production is done

void producer() {
   for (int i = 1; i <= 5; ++i) {
      sem_wait(&emptySlots);
      buffer.push(i);
      cout << "Produced: " << i << endl;
      sem_post(&fullSlots);
      this_thread::sleep_for(chrono::milliseconds(500));
   }
   // Signal that production is done
   done = true;
   // Wake up the consumer if it is waiting
   sem_post(&fullSlots);
}

void consumer() {
   while (true) {
      sem_wait(&fullSlots);
      if (done && buffer.empty()) {
         // If production is done and buffer is empty, exit loop
         break;
      }
      if (!buffer.empty()) {
         int data = buffer.front();
         buffer.pop();
         cout << "Consumed: " << data << endl;
         sem_post(&emptySlots);
         this_thread::sleep_for(chrono::milliseconds(1000));
      } else {
         // If the buffer is empty but production is not done, release the slot
         sem_post(&fullSlots);
      }
   }
}

int main() {
   // Max 5 empty slots
   sem_init(&emptySlots, 0, 5);
   // Initially, no full slots in the buffer
   sem_init(&fullSlots, 0, 0);

   thread producerThread(producer);
   thread consumerThread(consumer);

   producerThread.join();
   consumerThread.join();

   sem_destroy(&emptySlots);
   sem_destroy(&fullSlots);

   return 0;
}
