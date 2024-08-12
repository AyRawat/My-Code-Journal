const PizzaShop = require("./pizza-shop");
const DrinkMachine = require("./drink-machine");
const drinkMachine = new DrinkMachine();
const pizzaShop = new PizzaShop();
// 1.
const EventEmitter = require("events");
const emitter = new EventEmitter();

emitter.on("order-pizza", (size, topping) => {
  console.log(`A pizza has been ordered Baking a ${size} and ${topping}`);
});

emitter.emit("order-pizza", "large", "mushroom");

// 2. -> ordering a pizza by emitting events from a class

pizzaShop.on("order", (size, topping) => {
  console.log(`Order received! Baking a ${size} pizza with ${topping}`);
  drinkMachine.serveDrink(size);
});

pizzaShop.order("large", "mushrooms");
