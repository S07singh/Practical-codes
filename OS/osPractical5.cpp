#include <iostream>
using namespace std;

struct Semaphore {
    int mutex;  // Used as a binary semaphore (0 or 1)
    int rcount; // Number of readers currently reading
    int rwait;  // Number of waiting readers
    bool wrt;   // Flag indicating if a writer is active
};

// Add a reader to the system
void addreader(Semaphore *s) {
    if (s->wrt || s->mutex == 0) { // Check if writing or no mutex available
        cout << "Sorry, File is open in Write mode.\nNew Reader added to queue." << endl;
        s->rwait++; // Increment the waiting readers count
    } else {
        cout << "Reader Process added." << endl;
        s->rcount++; // Increment the count of active readers
        s->mutex--;  // Decrement the mutex as a reader occupies it
    }
}

// Add a writer to the system
void addwriter(Semaphore *s) {
    if (s->mutex == 1 && !s->wrt) { // Check if no writer is active and mutex is available
        s->mutex--; // Acquire the mutex
        s->wrt = true; // Mark writer as active
        cout << "Writer Process added." << endl;
    } else if (s->wrt) {
        cout << "Sorry, Writer already operational." << endl;
    } else {
        cout << "Sorry, File open in Read mode." << endl;
    }
}

// Remove a reader from the system
void removereader(Semaphore *s) {
    if (s->rcount == 0) {
        cout << "No readers to remove" << endl;
    } else {
        cout << "Reader removed" << endl;
        s->rcount--; // Decrement the count of active readers
        s->mutex++;  // Release the mutex
        
        // Handle waiting readers
        if (s->rwait > 0) {
            s->mutex -= s->rwait; // Allocate mutex to waiting readers
            s->rcount = s->rwait; // Update active readers count
            s->rwait = 0; // Reset waiting readers count
            cout << "Waiting Readers Added: " << s->rcount << endl;
        }
    }
}

// Remove a writer from the system
void removewriter(Semaphore *s) {
    if (!s->wrt) {
        cout << "No Writer to Remove" << endl;
    } else {
        cout << "Writer Removed" << endl;
        s->mutex++; // Release the mutex
        s->wrt = false; // Mark writer as inactive
        
        // Handle waiting readers
        if (s->rwait > 0) {
            s->mutex -= s->rwait; // Allocate mutex to waiting readers
            s->rcount = s->rwait; // Update active readers count
            s->rwait = 0; // Reset waiting readers count
            cout << "Waiting Readers Added: " << s->rcount << endl;
        }
    }
}

int main() {
    Semaphore S1 = {1, 0, 0, false}; // Initialize semaphore

    while (true) {
        cout << "Options" << endl;
        cout << "1. Add Reader." << endl;
        cout << "2. Add Writer." << endl;
        cout << "3. Remove Reader" << endl;
        cout << "4. Remove Writer" << endl;
        cout << "5. Exit" << endl;
        cout << "Choice: ";
        
        int choice;
        cin >> choice;
        
        switch (choice) {
            case 1:
                addreader(&S1);
                break;
            case 2:
                addwriter(&S1);
                break;
            case 3:
                removereader(&S1);
                break;
            case 4:
                removewriter(&S1);
                break;
            case 5:
                cout << "\n\tGoodbye!" << endl;
                return 0; // Exit the program
            default:
                cout << "\nInvalid Entry!" << endl;
        }
    }

    return 0;
}


