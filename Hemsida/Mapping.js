function adjust(value, r0, r1, r2, r3) {
    var mag = Math.abs(value - r0), sgn = value < 0 ? -1 : 1;
    return sgn * mag * (r3 - r2) / (r1 - r0);
  }

function map(value, r0, r1, r2, r3){
  return (value - r0) * (r3 - r2) / (r1 - r0) + r2;

}