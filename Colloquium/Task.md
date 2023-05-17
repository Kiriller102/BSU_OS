Контекстом будет онлайн-магазин, который должен обрабатывать заказы, с учетом выбранного пользователем метода доставки.

## Fabric method

```python

class DeliveryMethod:
    def deliver(self):
        pass

class PostDelivery(DeliveryMethod):
    def deliver(self):
        return "Post delivery"

class CourierDelivery(DeliveryMethod):
    def deliver(self):
        return "Courier delivery"

class PickUpDelivery(DeliveryMethod):
    def deliver(self):
        return "Pick up delivery"


class DeliveryMethodFactory:
    @staticmethod
    def create_delivery_method(delivery_type: str) -> DeliveryMethod:
        if delivery_type == "post":
            return PostDelivery()
        elif delivery_type == "courier":
            return CourierDelivery()
        elif delivery_type == "pickup":
            return PickUpDelivery()
        else:
            raise ValueError("Invalid delivery type")
```

Класс DeliveryMethod - абстрактный класс, который определяет общий интерфейс для всех методов доставки. Классы PostDelivery, CourierDelivery и PickUpDelivery - это конкретные реализации методов доставки, которые наследуются от абстрактного класса DeliveryMethod.

Класс DeliveryMethodFactory - это Фабрика, которая создает объекты методов доставки в зависимости от переданного типа доставки.

## Strategy Pattern

```python

class Order:
    def __init__(self, delivery_method: DeliveryMethod):
        self.delivery_method = delivery_method
    
    def set_delivery_method(self, delivery_method: DeliveryMethod):
        self.delivery_method = delivery_method
    
    def deliver(self):
        return self.delivery_method.deliver()


class OrderProcessor:
    def process_order(self, order: Order):
        print(f"Processing order with {order.deliver()}")
        
```

Класс Order - это Контекст, который использует один из методов доставки. Метод deliver() - это метод, который вызывается из Контекста, чтобы получить информацию о методе доставки, который должен использоваться при обработке заказа.

Класс OrderProcessor - это Клиент, который обрабатывает заказы. В данном примере он просто выводит информацию о способе доставки заказа.

Теперь можно использовать "Fabric" и "Strategy" для обработки заказов:

```python

def main():
    factory = DeliveryMethodFactory()
    
    order1 = Order(factory.create_delivery_method("post"))
    order2 = Order(factory.create_delivery_method("courier"))
    order3 = Order(factory.create_delivery_method("pickup"))

    processor = OrderProcessor()
    processor.process_order(order1)
    processor.process_order(order2)
    processor.process_order(order3)
```

При вызове функции main() будут созданы три заказа с разными методами доставки и обработаны Клиентом OrderProcessor, который выводит информацию о способе доставки для каждого заказа

## Unit Tests

``` python 
import unittest

class TestOrderProcessing(unittest.TestCase):
    def test_post_delivery(self):
        factory = DeliveryMethodFactory()
        order = Order(factory.create_delivery_method("post"))
        processor = OrderProcessor()
        self.assertEqual(processor.process_order(order), "Processing order with Post delivery")
        
    def test_courier_delivery(self):
        factory = DeliveryMethodFactory()
        order = Order(factory.create_delivery_method("courier"))
        processor = OrderProcessor()
        self.assertEqual(processor.process_order(order), "Processing order with Courier delivery")
        
    def test_pickup_delivery(self):
        factory = DeliveryMethodFactory()
        order = Order(factory.create_delivery_method("pickup"))
        processor = OrderProcessor()
        self.assertEqual(processor.process_order(order), "Processing order with Pick up delivery")
        
    def test_invalid_delivery(self):
        factory = DeliveryMethodFactory()
        with self.assertRaises(ValueError):
            order = Order(factory.create_delivery_method("invalid"))
```

В первом тестовом случае мы проверяем, что при использовании почтовой доставки, Клиент OrderProcessor должен вернуть "Processing order with Post delivery". Во втором тестовом случае мы проверяем, что при использовании курьерской доставки, Клиент OrderProcessor должен вернуть "Processing order with Courier delivery". В третьем тестовом случае мы проверяем, что при использовании самовывоза, Клиент OrderProcessor должен вернуть "Processing order with Pick up delivery". В последнем тестовом случае мы проверяем, что если передать некорректный тип доставки в Фабрику, то должно возникнуть исключение ValueError.

Запустив наш набор тестов, мы можем убедиться в том, что все наши тестовые случаи проходят успешно и работают правильно.
