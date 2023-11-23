// Observer 패턴 - 옵저버 인터페이스
class Observer {
    update(status) {
      throw new Error("update 메서드를 구현해야 합니다.");
    }
  }
  
  // Observer 패턴 - 주문 옵저버 클래스
  class OrderObserver extends Observer {
    update(status) {
      console.log('주문 상태 변경 알림:', status);
    }
  }
  
  // 배달 전략 인터페이스
  class RestaurantDiscount {
    deliver(order) {
      throw new Error("deliver 메서드를 구현해야 합니다.");
    }
  
    applyDiscount(amount) {
      throw new Error("applyDiscount 메서드를 구현해야 합니다.");
    }
  }
  
  // 음식점 A의 배달 전략
  class RestaurantA extends RestaurantDiscount {
    deliver(order) {
      console.log(`음식점 A에서 주문을 배달합니다. 주문 정보: ${order}`);
      // 음식점 A의 배달 처리 로직
    }
  
    applyDiscount(amount) {
      const discountRate = 0.1; // 10% 할인
      const discountedAmount = amount - amount * discountRate;
      return discountedAmount;
    }
  }
  
  // 음식점 B의 배달 전략
  class RestaurantB extends RestaurantDiscount {
    deliver(order) {
      console.log(`음식점 B에서 주문을 배달합니다. 주문 정보: ${order}`);
      // 음식점 B의 배달 처리 로직
    }
  
    applyDiscount(amount) {
      const discountRate = 0.2; // 20% 할인
      const discountedAmount = amount - amount * discountRate;
      return discountedAmount;
    }
  }
  
  // 음식점 C의 배달 전략
  class RestaurantC extends RestaurantDiscount {
    deliver(order) {
      console.log(`음식점 C에서 주문을 배달합니다. 주문 정보: ${order}`);
      // 음식점 C의 배달 처리 로직
    }
  
    applyDiscount(amount) {
      const discountRate = 0.15; // 15% 할인
      const discountedAmount = amount - amount * discountRate;
      return discountedAmount;
    }
  }
  
  // 배달료 계산 전략 인터페이스
  class DeliveryFee {
    calculate(amount) {
      throw new Error("calculate 메서드를 구현해야 합니다.");
    }
  }
  
  // 일반 배달료 계산 전략
  class RegularDelivery extends DeliveryFee {
    calculate(amount) {
      return amount * 0.1;
    }
  }
  
  // 익스프레스 배달료 계산 전략
  class ExpressDelivery extends DeliveryFee {
    calculate(amount) {
      return amount * 0.2 + 5;
    }
  }
  
  // Facade 패턴 - 배달 서비스 클래스
  class DeliveryApp {
    constructor() {
      this.deliveryDiscount = null;
      this.deliveryFee = null;
      this.observers = [];
    }
  
    setDeliveryDiscount(discount) {
      this.deliveryDiscount = discount;
    }
  
    setDeliveryFee(fee) {
      this.deliveryFee = fee;
    }
  
    addObserver(observer) {
      this.observers.push(observer);
    }
  
    removeObserver(observer) {
      const index = this.observers.indexOf(observer);
      if (index > -1) {
        this.observers.splice(index, 1);
      }
    }
  
    placeOrder(order, orderAmount) {
      if (!this.deliveryDiscount || !this.deliveryFee) {
        throw new Error("배달 전략과 배달료 전략을 설정해야 합니다.");
      }
  
      this.deliveryDiscount.deliver(order);
      const fee = this.deliveryFee.calculate(orderAmount);
      const discountedAmount = this.deliveryDiscount.applyDiscount(orderAmount);
  
      // 주문 완료 후 옵저버에게 알림
      this.notifyObservers("주문 완료");
      this.notifyObservers("요청하신 주문이 완료되었습니다. 예상 배달 시간은 50분입니다.");
      this.notifyObservers("배달이 완료되었습니다. 맛있게 드세요~");
      console.log(`주문 금액: $${orderAmount}, 할인 적용 후 금액: $${discountedAmount}, 배달료: $${fee} 총 주문금액 (배달료+ 할인금액) =$${discountedAmount+fee}`);
    }
  
    notifyObservers(status) {
      for (const observer of this.observers) {
        observer.update(status);
      }
    }
  }
  
  
  class Client {
    constructor() {
      this.deliveryApp = new DeliveryApp();
      this.order = null;
    }
  
    selectOrder(menu, orderAmount) {
      this.order = menu;
  
      if (!this.order) {
        throw new Error("주문할 메뉴를 선택해야 합니다.");
      }
  
      console.log(`주문: ${this.order}, 주문 금액: $${orderAmount}`);
      this.deliveryApp.placeOrder(this.order, orderAmount);
    }
  
    setDeliveryDiscount(discount) {
      this.deliveryApp.setDeliveryDiscount(discount);
    }
  
    setDeliveryFee(fee) {
      this.deliveryApp.setDeliveryFee(fee);
    }
  
    addObserver(observer) {
      this.deliveryApp.addObserver(observer);
    }
  
    removeObserver(observer) {
      this.deliveryApp.removeObserver(observer);
    }
  }
  
  // 클라이언트 코드
  const client = new Client();
  
  // 배달 전략과 배달료 전략 설정
  const deliveryA = new RestaurantA();
  const deliveryFeeRegular = new RegularDelivery();
  
  client.setDeliveryDiscount(deliveryA);
  client.setDeliveryFee(deliveryFeeRegular);
  
  // 옵저버 등록
  const orderObserver = new OrderObserver();
  client.addObserver(orderObserver);
  // 주문하기
  client.selectOrder("김치찌개", 100);
  
  // 옵저버 해제
  client.removeObserver(orderObserver);
  
