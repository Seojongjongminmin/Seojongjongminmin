// 부모 객체 생성자
function Coffee() {
  this.name = "Coffee";
}

// 부모 객체 메서드
Coffee.prototype.brew = function() {
  console.log("Brewing " + this.name);
};

// 자식 객체 생성자 - Americano
function Americano() {
  this.name = "Americano";
}

// 자식 객체의 프로토타입을 부모 객체로 설정
Americano.prototype = new Coffee();

// 자식 객체 생성자 - CafeLatte
function CafeLatte() {
  this.name = "Cafe Latte";
}

// 자식 객체의 프로토타입을 부모 객체로 설정
CafeLatte.prototype = new Coffee();

// 자식 객체 생성자 - CaramelMacchiato
function CaramelMacchiato() {
  this.name = "Caramel Macchiato";
}

// 자식 객체의 프로토타입을 부모 객체로 설정
CaramelMacchiato.prototype = new Coffee();

// 자식 객체 생성
var americano = new Americano();
var cafeLatte = new CafeLatte();
var caramelMacchiato = new CaramelMacchiato();

// 주문한 커피들을 각각 내린다
americano.brew(); 
cafeLatte.brew(); 
caramelMacchiato.brew(); 
