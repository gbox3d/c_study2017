'use strict';
var http = require('http');
var port = process.env.PORT || 1337;
var fs = require('fs');

http.createServer(function (req, res) {

    //res.writeHead(200, { 'Content-Type': 'text/plain' });
    //res.end('Hello World\n');
    fs.readFile('./index.html', function (error, data) {
        res.writeHead(200, { 'Content-Type': 'text/html' });
        res.end(data);
    });

    console.log(req.url);
    if (req.url == '/program.wasm') {
        fs.readFile('./program.wasm', function (error, data) {
            res.writeHead(200, { 'Content-Type': 'text/plain' });
            res.end(data);
        });

    }





}).listen(port);

console.log('server start');