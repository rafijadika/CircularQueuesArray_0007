#include <iostream>
using namespace std;

class queues {
	int FRONT, REAR, max = 5;
	int queue_array[5];

public:
	queues() {
		FRONT = -1;
		REAR = -1;
	}

	void insert() {
		int num;
		cout << "Enter a  number: ";
		cin >> num;
		cout << endl;

		if ((FRONT == 0 && REAR == max - 1) || (FRONT == REAR + 1)) {
			cout << "\nQueue overflow\n";
			return;
		}

		if (FRONT == -1) {
			FRONT = 0;
			REAR = 0;
		}
		else {
			if (REAR == max - 1)
				REAR = 0;
			else
				REAR = REAR + 1;
		}
		queue_array[REAR] = num;
	}

	void remove() {
		if (FRONT == -1) {
			cout << "Queue underflow\n";
			return;
		}
		cout << "\nThe element deleted from the queue is: " << queue_array[FRONT] << "\n";

		if (FRONT == REAR) {
			FRONT = -1;
			REAR = -1;
		}
		else {
			if (FRONT == max - 1)
				FRONT = 0;
			else
				FRONT = FRONT + 1;
		}
	}

	void display() {
		int FRONT_posisition = FRONT;
		int REAR_posisition = REAR;

		if (FRONT == -1) {
			cout << "Queue is empty\n";
			return;
		}

		cout << "\nElemenets in the queue are...\n";

		if (FRONT_posisition <= REAR_posisition) {
			while (FRONT_posisition <= REAR_posisition) {
				cout << queue_array[FRONT_posisition] << "   ";
				FRONT_posisition++;
			}
			cout << endl;
		}
		else {
			while (FRONT_posisition <= REAR_posisition) {
				cout << queue_array[FRONT_posisition] << "   ";
				FRONT_posisition++;
			}

			FRONT_posisition = 0;

			while (FRONT_posisition <= REAR_posisition) {
				cout << queue_array[FRONT_posisition] << "   ";
				FRONT_posisition++;
			}
			cout << endl;
		}
	}
}; 

int main() {
	queues q;
	char ch;

	while (true) {
		try {
			cout << "Menu" << endl;
			cout << "1. Implement insert operation" << endl;
			cout << "2. Implement delete operation" << endl;
			cout << "3. Display values" << endl;
			cout << "4. Exit" << endl;
			cout << "Enter your choice (1-4): " << endl;
			cin >> ch;
			cout << endl;

			switch (ch) {
			case '1': {
				q.insert();
				break;
			}
			case '2': {
				q.remove();
				break;
			}
			case '3': {
				q.display();
				break;
			}
			case '4': {
				return 0;
			}
			default: {
				cout << "invalid option!!" << endl;
				break;
			}

			}
		}
		catch (exception& e) {
			cout << "Check for the values entered." << endl;
		}
	}

	return 0; 

}

