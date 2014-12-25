module.exports = {
	get: function(v, defaultValue) {
		return (typeof v === "undefined") ? defaultValue : v;
	},
	clone: function(o) {
		return JSON.parse(JSON.stringify(o));
	}
};