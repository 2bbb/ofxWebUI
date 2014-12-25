module.exports = {
	get: function(v, defaultValue) {
		return (typeof v === "undefined") ? defaultValue : v;
	}
};