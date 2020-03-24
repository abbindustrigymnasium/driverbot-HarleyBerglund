window.onload = function startConnect() {
    // Generate a random client ID
    clientID = "clientID_" + parseInt(Math.random() * 100);

    // Fetch the hostname/IP address and port number from the form
    host = "maqiatto.com";
    port = 8883;

    '</span><br/>';

    '</span><br/>';
    // Initialize new Paho client connection
    client = new Paho.MQTT.Client(host, Number(port), clientID);
    // Set callback handlers
    client.onConnectionLost = onConnectionLost;
    client.onMessageArrived = onMessageArrived;

    client.connect({
        userName: "harley@berglun.se",
        password: "HEJHEJ",
        onSuccess: onConnect,
        onFailure: onFail,
    });
}

function onFail() {
    //document.getElementById("messages").innerHTML += '<span>ERROR: Connection to: ' + host + ' on port: ' +
    port + ' failed.</span><br/>'
}


// Called when the client connects
function onConnect() {
    startServo = "90";
    mess3 = `(${startServo})`;
    message = new Paho.MQTT.Message(mess3);
    message.destinationName = "harley@berglun.se/servo";
    client.send(message);

    startMotor = "0";
    mess4 = `(${startMotor},${startMotor})`;
    message = new Paho.MQTT.Message(mess4);
    message.destinationName = "harley@berglun.se/motor";
    client.send(message);
}

function onMotor() {
    let power = this.POWER;
    let strength = this.output;
    let mess2 = `(${power},${strength})`;

    //console.log(mess2);
    //message = new Paho.MQTT.Message(mess2);


    message = new Paho.MQTT.Message(mess2);
    message.destinationName = "harley@berglun.se/motor";
    client.send(message);
}

function onServo() {
    let servo = this.output2;
    let mess1 = `(${servo})`;

    //console.log(mess1);
    //message = new Paho.MQTT.Message(mess2);


    message = new Paho.MQTT.Message(mess1);
    message.destinationName = "harley@berglun.se/servo";
    client.send(message);
}


// Called when the client loses its connection
function onConnectionLost(responseObject) {
    //document.getElementById("messages").innerHTML += '<span>ERROR: Connection lost</span><br/>';
    if (responseObject.errorCode !== 0) {
        document.getElementById("messages").innerHTML += '<span>ERROR: ' + +responseObject.errorMessage +
            '</span><br/>';
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
    // document.getElementById("messages").innerHTML += '<span>Disconnected</span><br/>';
}