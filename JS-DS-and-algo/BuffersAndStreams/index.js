const buffer = Buffer.from("AYUSH", "utf-8");

console.log(buffer.toJSON());
console.log(buffer);
console.log(buffer.toString());
buffer.write("SOME LARgE VALue");
console.log(buffer.toString());

// { type: 'Buffer', data: [ 65, 89, 85, 83, 72 ] }
// <Buffer 41 59 55 53 48>
// AYUSH
// SOME  -> you do not have unlimited memory in buffer
