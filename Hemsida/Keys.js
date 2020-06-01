//Different if cases, which controlles the car with the computor keys

document.addEventListener('keypress', function (event) {
    if (event.defaultPrevented) {
        return;
    }
    var key = event.key || event.keyCode;

    if (key === 'w' || key === 87) {
        onMotor(POWER = 0, output = 1023); //When key w is pressed: runns the onMotor funtion with the values
    }
    if (key === 's' || key === 83) {
        onMotor(POWER = 1, output = 1023); //When key s is pressed: runns the onMotor funtion with the values 
    }

    if (key === 'a' || key === 65) {
        onServo(output2 = 160); //When key is pressed it sends 160 to the onServo function, which makes the car turn left
        document.addEventListener("keyup", keyUP); //Recenters the servo when keyup
    }
    if (key === 'd' || key === 68) {
        onServo(output2 = 20); //When key is pressed it sends 20 to the onServo function, which makes the car turn right
        document.addEventListener("keyup", keyUP); //Recenters the servo when keyup
    }
    if (key === 'o' || key === 79) {
        onMotor(POWER = 1, output = 0); //Emergency break
    }

    if (key === 'p' || key === 80) {
        onLampa(lampVal = 1); //turns on the led strip
    }
    if (key === 'å' || key === 221) {
        onLampa(lampVal = 0); //turns off the led strip
    }


})

document.addEventListener('keyup', function (event) {
    if (event.defaultPrevented) {
        return;
    }
    var key = event.key || event.keyCode;

    if (key === 'w' || key === 87) {
        onMotor(POWER = 0, output = 0); //When keyup: the motor stops

    }
    if (key === 's' || key === 83) {
        onMotor(POWER = 1, output = 0); //When keyup: the motor stops
    }
})

function keyUP() {
    onServo(output2 = 90); //Sets the servo to 90 degrees, which is the center of the stearing
}