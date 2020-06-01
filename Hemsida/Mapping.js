function map(value, r0, r1, r2, r3){
  return (value - r0) * (r3 - r2) / (r1 - r0) + r2;           //A function that can be used to change a range. Works like this : map(value, fromLow, fromHigh, toLow, toHigh)

}