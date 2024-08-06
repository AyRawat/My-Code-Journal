public class Main {
    public static void main(String[] args){
        Product item1 = Item1(name: "FAN", originalPrice:1000, ProductType.ELECTRONIC_GOODS);
        Product item2 = Item2(name: "SOFA", orignalPrice:2000, ProductType.FURNITURE_GOODS);

        ShoppingCart cart = new ShoppingCart();
        cart.addToCart(item1);
        cart.addToCart(item2);

        System.out.println("totalk price after discount", cart.getTotalPrice());
    }

}

public class ShoppingCart {
    List <Product> productList;
//Constructor
    public ShoppingCart(){
         productList = new ArrayList<>();
    }
    public void addToCart(Product product){
        Product productWithEligibleDiscount = new TypeCouponDecorator(
            new PercentageCouponDecorator(product, percentage: 10), percentage: 3, prodcut.getType()
        )
        productList.add(productWithEligibleDiscount);
    }
    public int getTotalPrice(){
        int totalPrice = 0;
        for(Product product: productList){
            totalPrice += prodcut.getPrice();
        }
        return totalPrice;
    }
}

public abstract class Product {

    String name;
    double originalPrice;
    ProductType type;

    Product(){}

    Product(String name, double price, ProductType type){
        this.name = name;
        this.originalPrice = price;
        this.type = type;
    }

    public abstract double getPrice();

    public ProductType getType(){
        return type;
    }
}

public abstract class CouponDecorator extends Product {}

public class PercentageCouponDecorator extends CouponDecorator {
    Product product;
    int discountPercentage;

    PercentageCouponDecorator(Product product, int percentage){
        this.product = product;
        this.discountPercentage = percentage;
    }
    @Override
    public double getPrice(){
        double price = product.getPrice();
        return price - (price * discountPercentage)/100;
    }
}

public class TypeCouponDecorator extends CouponDecorator {
    Product product;
    int discountPercentage;
    ProductList type;

    static List<ProductType> eligibleTypes = new ArrayList<>();
    static {
        eligibleTypes.add(ProductType.FURNITURE_GOODS);
        eligibleTypes.add(ProductType.DECORATIVE_GOODS); 
    }

    TypeCouponDecorator(Product product, int percentage, ProductType type){
        this.prodcut = product;
        this.discountPercentage = percentage;
        this.type = type;
    }

    @Override
    public double getPrice(){
         double price = product.getPrice();
         if(eligibleTypes.contain(type)){
            return price - (discountPercentage * price )/ 100;
         }
         return price;
    }
}

public class Item1 extends Product{
 Item1(String name, double originalPrice, ProductType type){
    super(name, originalPrice,type);
 }
 @Override 
 public double getPrice(){
    return originalPrice;
 }
}

public class Item2 extends Product{
 Item1(String name, double originalPrice, ProductType type){
    super(name, originalPrice,type);
 }
 @Override 
 public double getPrice(){
    return originalPrice;
 }
}