/**
 * @mainpage Documentation circular Queues
 * 
 * @section Introduction
 * This project from structur data
 * this project use structur data queues, implements circular arrays.
 * 
 * @section Operations
 * - en queues for insert elements into queues
 * - de queues for insert elements from queues
 * - show data
 * 
 * @section How to use
 * 1. Insert
 * 2. Delete
 * 3. Display
 * 4. Exit
 * 
 * @author yProfil
 * - Nama   : Rafky Ferdiansyah
 * - NIM    : 20240140247
 * - Kelas  : TI E
 * 
 * @brief 
 * @version 0.1
 * @date 2025-06-23
 * 
 * @copyright Gibran@umy.ac.id (c) 2025
 * 
 */

#include <iostream>
using namespace std;

/**
 * @class Queues
 * @brief This class is for operation queues
 * 
 */
class Queues {
private:
    int FRONT; /// private variable front for indicate first element
    int REAR; /// private variable rear forr indicate the last element
    int max = 5; /// private variable max for maximum capacity of element
    int queue_array[5]; /// private variable queue_array to store elements

public:
    /**
     * @brief Construct a new Queues object
     * set default queues null
     * with front = -1 and rear = -1
     */
    Queues() {
        FRONT = -1;
        REAR = -1;
    }

    /**
     * @brief method for entering data into a queue
     * This procedur print a message to the screen from the user
     */
    void insert() { /// This function is for insert a number into queue
        int num; /// Variable to store numeric input from the user
        cout << "Enter a number: ";
        cin >> num;
        cout << endl;

        // Cek apakah antrian penuh
        if ((FRONT == 0 && REAR == max - 1) || (FRONT == REAR + 1)) {
            cout << "\nQueue overflow\n";
            return;
        }

        // Cek apakah antrian kosong
        if (FRONT == -1) {
            FRONT = 0;
            REAR = 0;
        }
        else {
            // Jika REAR berada di posisi terakhir array, kembali ke awal array
            if (REAR == max - 1)
                REAR = 0;
            else
                REAR = REAR + 1;
        }
        queue_array [REAR] = num;
    }

    /**
     * @brief Method for delete front element from the queue
     * Delete and displays the element at the front if not empty
     */
    void remove() { /// 
        // Cek apakah antrian kosong
        if (FRONT == -1) {
            cout << "Queue underflow\n";
            return;
        }
        cout << "\nThe element deleted from the queue is: " << queue_array[FRONT] << "\n";

        // Cek jika antrian hanya memiliki satu elemen
        if (FRONT == REAR) {
            FRONT = -1;
            REAR = -1;
        }
        else {
            // Jika elemen yang dihapus berada di posisi terakhir array, kembali ke awal array
            if (FRONT == max - 1)
                FRONT = 0;
            else
                FRONT = FRONT + 1;
        }
    }

    /**
     * @brief Method for display all elements in the queue
     * Display data from front to rear according to queue order
     */
    void display() { /// Display the contents of the queue without changing the original value of front
        int FRONT_position = FRONT; /// The proccess of tracking queue elements
        int REAR_position = REAR; /// Copy of the rear position of the queue for the element tracing proccess

        // Cek apakah antrian kosong
        if (FRONT == -1) {
            cout << "Queue is empty\n";
            return;
        }

        cout << "\nElements in the queue are...\n";

        // Jika FRONT_position <= REAR_position, iterasi dari FRONT hingga REAR
        if (FRONT_position <= REAR_position) {
            while (FRONT_position <= REAR_position) {
                cout << queue_array[FRONT_position] << " ";
                FRONT_position++;
            }
            cout << endl;
        }
        else {
            // Jika FRONT_position > REAR_position, iterasi dari FRONT hingga akhir array
            while (FRONT_position <= max - 1) {
                cout << queue_array[FRONT_position] << " ";
                FRONT_position++;
            }

            FRONT_position = 0;

            // Iterasi dari awal array hingga REAR
            while (FRONT_position <= REAR_position) {
                cout << queue_array[FRONT_position] << " ";
                FRONT_position++;
            }
            cout << endl;
        }
    }
};

/**
 * @brief The main function for running queue operations
 * 
 * @return int
 */
int main()
{
    Queues q;
    char ch;

    while (true)
    {
        try
        {
            cout << "Menu" << endl;
            cout << "1. Implement insert operation" << endl;
            cout << "2. Implement delete operation" << endl;
            cout << "3. Display values" << endl;
            cout << "4. Exit" << endl;
            cout << "Enter yout choice (1-4): ";
            cin >> ch;
            cout << endl;

            switch(ch)
            {
            case '1':
            {

                q.insert();
                break;
            }
            case '2':
            {
                q.remove();
                break;
            }
            case '3':
            {
                q.display();
                break;
            }
            case '4':
            {
                return 0;
            }
            default:
            {
                cout << "Invalid option!!" << endl;
                break;
            }
            }
        }
        catch (exception &e)
        {
            cout << "Check for the values entered." << endl;
        }
    }
}