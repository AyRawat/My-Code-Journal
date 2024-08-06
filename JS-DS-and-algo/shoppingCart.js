class Product {
  constructor(name, originalPrice, type) {
    this.name = name;
    this.originalPrice = originalPrice;
    this.type = type;
  }

  getPrice() {
    return this.originalPrice;
  }

  getType() {
    return this.type;
  }
}

class PercentageCouponDecorator extends Product {
  constructor(product, percentage) {
    super(product.name, product.originalPrice, product.type);
    this.product = product;
    this.discountPercentage = percentage;
  }

  getPrice() {
    let price = this.product.getPrice();
    return price - (price * this.discountPercentage) / 100;
  }
}

class TypeCouponDecorator extends Product {
  constructor(product, percentage, type) {
    super(product.name, product.originalPrice, product.type);
    this.product = product;
    this.discountPercentage = percentage;
    this.type = type;
  }

  static eligibleTypes = ["FURNITURE_GOODS", "DECORATIVE_GOODS"];

  getPrice() {
    let price = this.product.getPrice();
    if (TypeCouponDecorator.eligibleTypes.includes(this.type)) {
      return price - (this.discountPercentage * price) / 100;
    }
    return price;
  }
}

class ShoppingCart {
  constructor() {
    this.productList = [];
  }

  addToCart(product) {
    let productWithEligibleDiscount = new TypeCouponDecorator(
      new PercentageCouponDecorator(product, 10),
      3,
      product.getType()
    );
    this.productList.push(productWithEligibleDiscount);
  }

  getTotalPrice() {
    return this.productList.reduce(
      (total, product) => total + product.getPrice(),
      0
    );
  }
}

class Item1 extends Product {
  constructor(name, originalPrice, type) {
    super(name, originalPrice, type);
  }
}

class Item2 extends Product {
  constructor(name, originalPrice, type) {
    super(name, originalPrice, type);
  }
}

// Main
const item1 = new Item1("FAN", 1000, "ELECTRONIC_GOODS");
const item2 = new Item2("SOFA", 2000, "FURNITURE_GOODS");

const cart = new ShoppingCart();
cart.addToCart(item1);
cart.addToCart(item2);

console.log("Total price after discount:", cart.getTotalPrice());
