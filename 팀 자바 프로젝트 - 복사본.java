import java.util.*;

    public class Test {
        public static void order() {
            Order order = new Order();
            order.getMenu(); //메뉴메소드를 부른다.
            String name = order.getOrder();// 메뉴를 입력받아서 name에 저장한다.
        }

        public static void getAmericano() {
            CoffeeRobot CoffeeRobot = new Americano();
            System.out.println("샷을 2번 추가한 경우");
            CoffeeRobot = new Shot(CoffeeRobot); //CoffeeRobot 필드에 Shot 인스턴스 저장
            CoffeeRobot = new Shot(CoffeeRobot);
            Recipe recipe = new Americano();
            recipe.makeRecipe(); //레시피대로 음료를 만든다
            System.out.println("메뉴 : " + CoffeeRobot.getDrinkName()); //아메리카노 +샷 +샷
            System.out.println("가격 : " + CoffeeRobot.cost()); //총 합계 가격
            System.out.println("------------------------------------");
        }

        public static void getCaffeLatte() {
            CoffeeRobot CoffeeRobot1 = new CaffeLatte();
            System.out.println("크림을 추가한 경우");
            CoffeeRobot1 = new Cream(CoffeeRobot1); //CoffeeRobot1 필드에 Cream 인스턴스 저장
            Recipe recipe = new CaffeLatte();
            recipe.makeRecipe(); //레시피대로 음료 만든다
            System.out.println("메뉴 : " + CoffeeRobot1.getDrinkName()); //카페라떼 +크림
            System.out.println("가격 : " + CoffeeRobot1.cost()); //총합계
            System.out.println("------------------------------------");
        }

        public static void getCafeMocha() {
            CoffeeRobot CoffeeRobot2 = new CafeMocha();
            System.out.println("크림과 샷을 추가한 경우");
            CoffeeRobot2 = new Cream(CoffeeRobot2); //CoffeeRobot2 필드에 Cream 인스턴스 저장
            CoffeeRobot2 = new Shot(CoffeeRobot2); // CoffeeRobot2 필드에 Shot 인스턴스 저장
            Recipe recipe = new CafeMocha();
            recipe.makeRecipe(); //레시피대로 만든다
            System.out.println("메뉴 : " + CoffeeRobot2.getDrinkName()); //카페모카 +크림 +샷
            System.out.println("가격 : " + CoffeeRobot2.cost()); //총합계
            System.out.println("------------------------------------");
        }

        public static void getEspresso() {
            CoffeeRobot CoffeeRobot3 = new Espresso();
            Recipe recipe = new Espresso();
            recipe.makeRecipe(); //레시피대로 만든다
            System.out.println("메뉴 : " + CoffeeRobot3.getDrinkName()); //에스프레소
            System.out.println("가격 : " + CoffeeRobot3.cost()); //총합계
            System.out.println("------------------------------------");
        }

        public static void pay() {
            Order order = new Order();
            int paymethod = order.getPayMethod();// 돈을 받는 방법을 정해서 paymethod에 저장한다.
            int money = order.getMoney();//주문한 금액을 입력한다.
            PaymentMethod payment1 = new PaymentMethod();
            PaymentMethod payment2 = new PaymentMethod();
            PaymentMethod payment3 = new PaymentMethod();
            payment1.setPayment(new CreditCardPayment());  //  payment1에서 setPayment 메소드 호출
            payment2.setPayment(new CashPayment()); //payment2에서  setPayment 메소드 호출
            payment3.setPayment(new GifticonPayment()); //payment3에서 setPayment 메소드 호출
            if (paymethod == 1) {// 카드 결제 일 경우
                payment1.change(money);//change메소드에서 money매개변수를 넣는다.
            }
            else if (paymethod == 2) {  //현금결제 경우
                payment2.change(money);//change 메소드에서 money매개변수를 넣는다.
            }
            else if (paymethod == 3) {  //기프티콘 결제 경우
                payment3.change(money); //change 메소드에서 money매개변수를 넣는다.
            }
        }
        public static void main(String[] args) {
            order();
            getAmericano();
            getCaffeLatte();
            getCafeMocha();
            getEspresso();
            pay();
        }
    }

    class Order { //Order 클래스
        String getOrder() { //주문을 받는 메소드
            Scanner scan = new Scanner(System.in);
            System.out.println("원하시는 음료를 입력해주세요");
            String name = scan.nextLine();
            return name;
        }

        int getMoney() { // 금액을 받는 메소드
            Scanner scan = new Scanner(System.in);
            System.out.println("금액을 입력해주세요");
            int money = scan.nextInt();
            return money;
        }

        int getPayMethod() { //결제방식 선택하는 메소드
            Scanner scan = new Scanner(System.in);
            System.out.println("결제방식을 선택해주세요(1:카드,2:현금,3:기프티콘)");
            int paymethod = scan.nextInt();
            return paymethod;
        }

        void getMenu() { //메뉴 메소드
            System.out.println("카페라떼,3500원");
            System.out.println("아메리카노,2500원");
            System.out.println("카페모카,4000원");
            System.out.println("에스프레소,2000원");
            System.out.println("----추가 옵션------");
            System.out.println("샷 추가:400원");
            System.out.println("크림 추가:500원");
        }
    }

    //전략패턴//
    class PaymentMethod { //PaymentMethod 클래스
        private Payment payment;

        public void setPayment(Payment payment) { //결제 방식을 바꿔주는 메소드

            this.payment = payment;
        } //원하는 결제방식으로 바꾼다

        public void change(int money) { //money를 받아온다

            payment.pay(money);
        }

    }

    interface Payment { //결제 방식이 모여있는 인터페이스
        void pay(int cost); //돈을 받아서 결제하는 메소드
    }

    class CreditCardPayment implements Payment { //카드 결제
        @Override
        public void pay(int won) {

            System.out.println(won + "원 카드결제가 되었습니다");
        }

    }

    class CashPayment implements Payment { //현금결제
        @Override
        public void pay(int won) {

            System.out.println(won + "원 현금결제가 되었습니다");
        }
    }

    class GifticonPayment implements Payment { //기프티콘 결제
        @Override
        public void pay(int won) {

            System.out.println(won + "원 기프티콘결제가 되었습니다");
        }
    }

    abstract class CoffeeRobot { //커피로봇 추상 클래스

        String drinkName = "no title";

        public abstract int cost(); //음료값

        public String getDrinkName() { //음료이름 메소드

            return drinkName; //음료이름 반환
        }

    }

    //템플릿 메소드 패턴//
    abstract class Recipe extends CoffeeRobot { //레시피 추상 메소드

        public final void makeRecipe() { //레시피대로 음료를 만든다
            switchOn();
            grinderOn();
            putCoffeeBeans();
            brewCoffeeShot();
            putIngredients();
            mixCoffee();
            closeLid();
            giveMenu();
            end();
        }
        //공통메소드
        private void switchOn() {
            System.out.println("Turn on the Coffee grinder switch");
        }

        private void grinderOn() {
            System.out.println("Put grinder Coffee beans");
        }

        private void putCoffeeBeans() {
            System.out.println("Put the ground Coffee beans in a Coffee puck and stick them in the machine");
        }

        private void brewCoffeeShot() {
            System.out.println("Press the 1 shot button on the machine and lower the shot");
        }

        private void mixCoffee() {
            System.out.println("Mix it well with a spoon");
        }

        private void closeLid() {
            System.out.println("Close the lid well so that the drink doesn't leak");
        }
        private void end() {
            System.out.println("------------------------------------");
        }
        //추상메소드
        abstract void putIngredients();

        abstract void giveMenu();

    }

    //데코레이터 패턴//
    abstract class Options extends CoffeeRobot { //옵션 추상 클래스(크림, 샷)
        public abstract String getDrinkName();
    }

    class Cream extends Options { //크림 클래스
        CoffeeRobot CoffeeRobot;

        public Cream(CoffeeRobot CoffeeRobot) { //생성자
            super();
            this.CoffeeRobot = CoffeeRobot;
        }

        @Override
        public String getDrinkName() { //크림을 추가한다

            return CoffeeRobot.getDrinkName() + ",크림";
        }

        @Override
        public int cost() { //음료값에서 크림 값을 추가한다

            return CoffeeRobot.cost() + 500;
        }

    }

    class Shot extends Options { //샷 클래스

        CoffeeRobot CoffeeRobot;

        public Shot(CoffeeRobot CoffeeRobot) { //생성자
            super();
            this.CoffeeRobot = CoffeeRobot;
        }

        @Override
        public String getDrinkName() { //샷을 추가한다

            return CoffeeRobot.getDrinkName() + ",샷";
        }

        @Override
        public int cost() { //음료값에서 샷 값을 추가한다

            return CoffeeRobot.cost() + 400;
        }
    }

    class Americano extends Recipe { //아메리카노 클래스

        public Americano() { //생성자
            super();
            drinkName = "아메리카노"; //음료이름 선언
        }

        @Override
        public int cost() { //아메리카노 값

            return 3000;
        }

        void putIngredients() { // 얼음과 200ml 물을 넣는다
            System.out.println("Put a cup full of ice and add 200ml of water and put a shot on top");
        }

        void giveMenu() { //아메리카노 음료를 준다

            System.out.println("차가운 아메리카노 한 잔 나왔습니다! 맛있게 드세용~");
        }

    }

    class CaffeLatte extends Recipe { //카페라떼 클래스

        public CaffeLatte() { //생성자
            super();
            drinkName = "카페라떼"; //음료이름 선언

        }

        @Override
        public int cost() { //카페라떼 값

            return 3500;
        }

        void putIngredients() { //얼음과 우유를 넣는다
            System.out.println("Put a cup full of ice and add 200ml of milk and put a shot on top");
        }

        void giveMenu() { //카페라떼 음료가 나온다

            System.out.println("차가운 카페라떼 한 잔 나왔습니다! 맛있게 드세용~");
        }

    }

    class CafeMocha extends Recipe { //카페모카 클래스

        public CafeMocha() { //생성자
            super();
            drinkName = "카페모카"; //음료이름 선언

        }

        @Override
        public int cost() {  //카페모카 값

            return 4000;
        }

        void putIngredients() { //얼음과 우유를 넣고 그 위에 초코파우더를 뿌린다.
            System.out.println("Put a cup full of ice and add 200ml of milk and put a shot on top then sprinkle chocolate powder");
        }

        void giveMenu() { //카페모카 음료가 나온다.
            System.out.println("차가운 카페모카 한 잔 나왔습니다! 맛있게 드세용~");
        }

    }

    class Espresso extends Recipe { //에스프레소 클래스

        public Espresso() { //생성자
            super();
            drinkName = "에스프레소"; //음료 선언
        }

        @Override
        public int cost() { //에스프레소 값
            return 2500;
        }

        void putIngredients() { //얼음과 170ml 물을 넣는다
            System.out.println("Fill the cup with ice, add 170ml of water and pour the shot on top");
        }

        void giveMenu() { //에스프레소 음료가 나온다

            System.out.println("차가운 에스프레소 한 잔 나왔습니다! 맛있게 드세용~");
        }
    }


