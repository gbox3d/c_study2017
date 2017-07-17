﻿const dgram = require("dgram");
const udp_socket = dgram.createSocket("udp4");

udp_socket.on("message", function (msg, rinfo) {
    console.log(rinfo.address + ":" + rinfo.port + ":" + msg);

    strMsg = "nice to meet u " + msg;

    udp_socket.send(Buffer(strMsg), 0, strMsg.length, rinfo.port, rinfo.address);
});

udp_socket.bind(3333);
console.log('server binding at 3333')