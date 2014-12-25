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
	values[param.name] = utils.get(param.option.initial, 0);
}

io.on('connection', function(socket) {
	console.log("ofxWebUI: ", "connected");
	socket.on('change', function(data) {
		values[data.name] = data.value;
	});
	socket.on('disconnect', function() {
		console.log('disconnected');
	});
});

function remove(name) {
	delete values[name];
	console.log(name + " removed");
	io.sockets.emit('remove', {name: name});
}

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
	fs.readFile(PATH + 'front/index.html', 'utf-8', function(err, data) {
		if(err) {
			console.log(err);
			res.writeHead(404);
			res.end();
		} else {
			var html = data.split('##APP_NAME##').join(config.appName || 'ofxWebUI');
			res.writeHead(200, {'Content-Type': 'text/html; charset=utf-8'});
			res.write(html);
			res.end();
		}
	});
});

app.get('/:other', function (req, res) {
	if(req.params.other == "parameters.js") {
		var _parameters = utils.clone(parameters);
		for(var i = 0; i < _parameters.length; i++) {
			_parameters[i].option.initial = values[_parameters[i].name];
		}
		res.writeHead(200, {'Content-Type': 'application/javascript'});
		res.write('parameters = ' + JSON.stringify(_parameters) + ";");
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