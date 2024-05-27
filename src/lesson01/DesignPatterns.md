



Design patterns:
 - Organize a large code base into classes. How?


Singleton:
 - Single global object
 - private constructor
 - create instance static function
 - For eg. 
 - Stateless objects
 
```
 class ServerConfig {
    private static ServerConfig serverConfig;

    private int port;
    private String hostname;

    private ServerConfig() {
        // Load port and hostname from config file
    }

    public static ServerConfig getInstance() {
        if (this.serverConfig == null) {
            this.serverConfig = new ServerConfig();
        }

        return this.serverConfig;
    }

}
```


Decorator:
 - Wrap an existing object with additional functionality

```

public interface Car {
	public void assemble();
}

public class BasicCar implements Car {

	@Override
	public void assemble() {
		System.out.print("Basic Car.");
	}

}

public class PaintedCar implements Car {

    private BasicCar basicCar;

    public PaintedCar() {
        this.basicCar = new BasicCar();
    }

	@Override
	public void assemble() {
        this.basicCar.assemble()
        //paint the car
    }
}

```

Strategy:
 - Client can choose implementation based on requirement.

```
public interface PaymentStrategy {
	public void pay(int amount);
}

public class CreditCardPaymentStrategy implements PaymentStrategy {
    private String cardNumber;
    private String cvv;

    public void pay(int amount) {
        PaymentProvider pp = connectToCreditCardPaymentProvider();
        pp.pay(cardNumber, cvv);
        
    }
}

public class NetBankingPaymentStrategy implements PaymentStrategy {
    private String accoutNumber;
    private String pwd;

    public void pay(int amount) {
        PaymentProvider pp = connectToNetBankingPaymentProvider();
        pp.pay(accoutNumber, pwd);
        
    }
}

class Main {
    public static void main(String[] args) {
        PaymentStrategy ps = new NetBankingPaymentStrategy();
        ps.pay(100)
    }
}

```


```
Employee emp = new Employee()

class Employee {
    private String name;
    private int age;
}

class EmployeeOpertionsService {

    public Employee getEmployee(int id) {

    }

    public Employee createNewEmployee() {

    }
}

```
