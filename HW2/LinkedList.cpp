/**
 * LinkedList.cpp
 * Created by Stephen on 2/12/2021.
 * Uses catch 2 to test linked list styles.
 */

#define CATCH_CONFIG_MAIN

#include "catch.hpp"

#include <iostream>

// Create a struct object to act as our node for the linked list.
struct Value {
	int data;
	Value *next;

	// Add a constructor to our value struct
	explicit Value(int val) : data(val), next(nullptr) {}
};

// Store the first value of the linked list.
struct Value *front = nullptr;

// Store the last value of the linked list
struct Value *end = nullptr;

/**
 * Adds a value to the end of our linked list.
 * @param val The value to append to the end of our linked list.
 */
void append(int val) {

	// Create a new value node
	Value *newValue = new Value(val);

	// Check if the front is null.
	if (front == nullptr) {

		// Since the front is null, it means we are at the start of our linked list.
		// Simply set the front and end to our new value.
		front = newValue;
		end = newValue;
		return;
	}

	// Set the next value of our linked list to be that of our new value pointer.
	end->next = newValue;

	// Reset the end to our new value as well.
	end = newValue;
}

/**
 * Removes the first entry of our linked list.
 */
void pop() {

	// Make sure there is an item to return
	if (front == nullptr) {

		// Just return since it was empty.
		return;
	}

	// Store the previous front.
	Value *prevFront = front;

	// Set the new front to be the pointer to the next value.
	front = front->next;

	// Check if the front is now null.
	if (front == nullptr) {

		// Set the end to also be null.
		end = nullptr;
	}

	// Free up the resources from the previous front.
	delete (prevFront);
}

/**
 * Inserts a value into the front of our linked list.
 * @param val The value to be inserted to the front of our list.
 */
void insert(int val) {

	// Create a new value node.
	Value *newValue = new Value(val);

	// Store the previous front.
	Value *prevFront = front;

	// Set the new front to our new value.
	front = newValue;

	// Check if the end is null.
	if (end == nullptr) {
		// Set the end pointer to our current front.
		end = front;
	}

	// Set the next value to our previous front.
	front->next = prevFront;
}

Value* find(int val) {

	// Check that we have values to search.
	if (front == nullptr) {
		return nullptr;
	}

	// Create a variable to store our current entry in our linked list. Start at the front of our linked list.
	Value* entry = front;
	do {

		// Check if the entry's value matches our value. If it does, return the value entry (pointer).
		if (entry->data == val) {
			return entry;
		} else {

			// Since the entry wasn't found, move to the next one.
			entry = entry->next;
		}
	} while (entry != nullptr);

	// If we made it to this point simply return a null pointer.
	return nullptr;
}

TEST_CASE("Queue test") {
	// Test the expanding queue
	append(0);
	REQUIRE(front->data == 0);
	REQUIRE(end->data == 0);
	append(1);
	REQUIRE(front->data == 0);
	REQUIRE(end->data == 1);
	append(2);
	REQUIRE(front->data == 0);
	REQUIRE(end->data == 2);

	// Test shrinking queue
	pop();
	REQUIRE(front->data == 1);
	REQUIRE(end->data == 2);
	pop();
	REQUIRE(front->data == 2);
	REQUIRE(end->data == 2);
	pop();
	REQUIRE(front == nullptr);
	REQUIRE(end == nullptr);
}

TEST_CASE("Stack test") {
	// Test the expanding stack
	insert(0);
	REQUIRE(front->data == 0);
	REQUIRE(end->data == 0);
	insert(1);
	REQUIRE(front->data == 1);
	REQUIRE(end->data == 0);
	insert(2);
	REQUIRE(front->data == 2);
	REQUIRE(end->data == 0);

	// Test shrinking stack
	pop();
	REQUIRE(front->data == 1);
	REQUIRE(end->data == 0);
	pop();
	REQUIRE(front->data == 0);
	REQUIRE(end->data == 0);
	pop();
	REQUIRE(front == nullptr);
	REQUIRE(end == nullptr);
}

TEST_CASE("Insert and Find") {
	// Test the find function first.
	REQUIRE(find(0) == nullptr);
	insert(0);
	REQUIRE(find(0) != nullptr);
	REQUIRE(find(1) == nullptr);
	pop();
	REQUIRE(find(0) == nullptr);
}

TEST_CASE("Print") {
	// TODO
}