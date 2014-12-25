module.exports = {
	get: function(v, defaultValue) {
		return (typeof v === "undefined") ? defaultValue : v;
	},
	createHTML: function(appName, parameters) {
		appName = appName || 'ofxWebUI';
		var html = 
'<!DOCTYPE html>\
<html>\
	<head>\
		<title>' + appName + '</title>\
		<link href="./index.css" rel="stylesheet" type="text/css">\
		<link href="./jquery-ui.css" rel="stylesheet" type="text/css">\
		<script type="text/javascript" src="./jquery.js"></script>\
		<script type="text/javascript" src="./jquery-ui.js"></script>\
		<script type="text/javascript" src="./socket.io/socket.io.js"></script>\
		<script type="text/javascript" src="./index.js"></script>\
		<script type="text/javascript" src="./parameters.js"></script>\
		<script type="text/javascript">\
			jQuery(function($) {\
				var socket = io(),\
					UI = initUI(socket);\
				UI.create(parameters, $("#main"));\
			});\
		</script>\
	</head>\
<body>\
	<h1>' + appName + '</h1>\
	<div id="main"></div>\
</body>\
</html>';
		return html;
	}
};