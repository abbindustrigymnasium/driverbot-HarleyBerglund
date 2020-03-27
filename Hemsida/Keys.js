
document.addEventListener('keypress', function (event) {
    if (event.defaultPrevented) {
        return;
    }
    var key = event.key || event.keyCode;

    if (key === 'w' || key === 87) {
        POWER = 0;
        output = 1023;
        onMotor();

    }
    if (key === 's' || key === 83) {
        POWER = 1;
        output = 1023;
        onMotor();
    }

    if (key === 'a' || key === 65) {
        output2 = 160;
        onServo();
        document.addEventListener("keyup", keyUP);
    }
    if (key === 'd' || key === 68) {
        output2 = 20;
        onServo();
        document.addEventListener("keyup", keyUP);
    }
})

document.addEventListener('keyup', function (event) {
    if (event.defaultPrevented) {
        return;
    }
    var key = event.key || event.keyCode;

    if (key === 'w' || key === 87) {
        POWER = 0;
        output = 0;
        onMotor();

    }
    if (key === 's' || key === 83) {
        POWER = 1;
        output = 0;
        onMotor();
    }
})

function keyUP() {
    output2 = 90;
    onServo();
}