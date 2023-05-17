# Design Patterns Example: Delivery Methods in an Online Store

This project demonstrates the implementation of two design patterns: Factory Method and Strategy. The context for these patterns is an online store that processes orders, taking into account the selected delivery method.

## Factory Method Pattern

The Factory Method pattern is used to create different delivery method objects based on user input.

### Classes

- `DeliveryMethod` (abstract class): Defines the common interface for all delivery methods.
- `PostDelivery`, `CourierDelivery`, `PickUpDelivery` (concrete classes): Implement specific delivery methods by inheriting from `DeliveryMethod`.
- `DeliveryMethodFactory`: Creates delivery method objects based on the provided delivery type.

## Strategy Pattern

The Strategy pattern is used to select and execute the appropriate delivery method for an order.

### Classes

- `Order`: Represents an order with a selected delivery method. It utilizes the chosen delivery method to process the order.
- `OrderProcessor`: Handles the order processing logic. It prints information about the selected delivery method.

## Usage

To use the example and observe the patterns in action, follow these steps:

1. Create instances of `Order` with different delivery methods, obtained from the `DeliveryMethodFactory`.
2. Instantiate `OrderProcessor`.
3. Process each order using `OrderProcessor`.

## Unit Tests

Unit tests have been implemented to verify the functionality of the system.

- `TestOrderProcessing`: Contains test cases to validate the behavior of the `OrderProcessor`.

Please refer to the code files for more detailed information about the implementation.

## Running the Tests

To run the unit tests and ensure the correctness of the code, execute the test script.

```shell
python -m unittest
```

Make sure you have the necessary dependencies installed before running the tests.

---
*Note: This is a simplified example for educational purposes and may not cover all possible scenarios or production-level considerations.*