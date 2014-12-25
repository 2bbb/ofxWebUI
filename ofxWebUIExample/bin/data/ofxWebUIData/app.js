var PATH = process.cwd() + "/../../../data/ofxWebUIData/",
	MODULE_PATH = PATH + "node_modules/";
global.module.paths.push(MODULE_PATH);

var utils = require(PATH + 'utils.js'),
	config = require(PATH + 'generated/config.js'),
	parameters = require(PATH + 'generated/parameters.js').data;

var app = require('express')(),
	http = require('http').Server(app),
	io = require('socket.io')(http),
	fs = require('fs'),
	mime = require('mime');

var values = {};

for(var i = 0; i < parameters.length; i++) {
	var param = parameters[i];
	values[param.name] = utils.get(param.initial, 0);
}

io.on('connection', function(socket) {
	console.log("ofxWebUI: ", "connection");
	socket.on('change', function(data) {
		values[data.name] = data.value;
	});
});

function loadAndWriteResponse(filePath, res) {
	fs.readFile(filePath, function(err, data) {
		if(err) {
			console.log(err);
			res.writeHead(404);
			res.end();
		} else {
			type = mime.lookup(filePath);
			res.writeHead(200, {'Content-Type': type});
			res.write(data);
			res.end();
		}
	});
}

app.get('/', function (req, res) {
	res.writeHead(200, {'Content-Type': 'text/html; charset=utf-8'});
	res.write(utils.createHTML(config.appName, parameters));
	res.end();
});

app.get('/index.html', function (req, res) {
	res.writeHead(200, {'Content-Type': 'text/html'});
	res.write(utils.createHTML(config.appName, parameters, values));
	res.end();
});

app.get('/:other', function (req, res) {
	if(req.params.other == "parameters.js") {
		res.writeHead(200, {'Content-Type': 'application/javascript'});
		res.write('parameters = ' + JSON.stringify(parameters) + ";");
		res.end();
	} else {
		loadAndWriteResponse(PATH + 'front/' + req.params.other, res);
	}
});

app.get('/images/:image', function (req, res) {
	loadAndWriteResponse(PATH + 'front/images/' + req.params.image, res);
});

http.listen(config.port || 8000, function() {
	console.log("==== ofxWebUI: " + config.appName + " started. ====");
});