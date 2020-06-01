window.onload = function startConnect() {
    // Generate a random client ID
    clientID = "clientID_" + parseInt(Math.random() * 100);

    // Fetch the hostname/IP address and port number from the form
    host = "maqiatto.com";
    port = 8883;

    // Initialize new Paho client connection
    client = new Paho.MQTT.Client(host, Number(port), clientID);
    // Set callback handlers
    client.onConnectionLost = onConnectionLost;
    client.onMessageArrived = onMessageArrived;

    client.connect({
        userName: "harley@berglun.se", //MQTT credentials
        password: "HEJHEJ",
        onSuccess: onConnect,
    });
    hideDIV(); //hiding the joystick on page load

}


// Called when the client connects
//Centers the servo and stops the motor if it is on
function onConnect() {
    onMotor(output = 0);
    onServo(output2 = 90)
}

function onMotor() {
    let power = this.POWER; //Fetching POWER and sets the variable to power. This is the direction of the motor
    let strength = this.output; //Fetching output and sets the variable to strength. This is the motor speed
    let mess2 = `(${power},${strength})`; //Takes the int inputs and puts them between parentheses like (1,1024) and turns it into a sting
    message = new Paho.MQTT.Message(mess2); //Creating the message 
    message.destinationName = "harley@berglun.se/motor"; //Where the message will be sent to 
    client.send(message); //Sending the message
}

function onServo() {
    let servo = this.output2; //Fetching output2 and sets the variable to servo. This is the stearing angle
    let mess1 = `(${servo})`; //Takes the int input and puts it between parentheses like (90) and turns it into a sting
    message = new Paho.MQTT.Message(mess1); //Creating the message 
    message.destinationName = "harley@berglun.se/servo"; //Where the message will be sent to 
    client.send(message); //Sending the message
}

function onLampa() {
    let LampValue = this.lampVal;  //Fetching lampVal and sets the variable to LampValue. This is the led strip
    let LampMessage = `(${LampValue})`; //Takes the int input and puts it between parentheses like (1000) and turns it into a sting
    message = new Paho.MQTT.Message(LampMessage); //Creating the message 
    message.destinationName = "harley@berglun.se/lampa"; //Where the message will be sent to
    client.send(message); //Sending the message
}

// Called when the client loses its connection
function onConnectionLost(responseObject) {
    if (responseObject.errorCode !== 0) {
        document.getElementById("messages").innerHTML += '<span>ERROR: ' + +responseObject.errorMessage +
            '</span><br/>';
        onMotor(POWER = 1, output = 0);
    }
}

// Called when a message arrives
function onMessageArrived(message) {
    console.log("onMessageArrived: " + message.payloadString);
    document.getElementById("messages").innerHTML += '<span>Topic: ' + message.destinationName + '  | ' +
        message.payloadString + '</span><br/>';
}

// Called when the disconnection button is pressed
function startDisconnect() {
    client.disconnect();
    window.location.reload();
}