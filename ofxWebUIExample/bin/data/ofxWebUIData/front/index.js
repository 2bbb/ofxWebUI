function get(v, defaultValue) {
	return (typeof v === "undefined") ? defaultValue : v;
}

function initUI(io) {
	function createSlider(param, $main) {
		var min = get(param.option.min, 0),
			max = get(param.option.max, 1),
			initial = get(param.option.initial, 0.5);
		var $wrapper = $('<div></div>'),
			$ui = $('<div id="' + param.name +'" style="margin: 0 15px; padding: 0; width: 300px; display: inline-block;"></div>'),
			$label = $('<div style="display: inline-block; width: 40px;"><span style="vertical-align: baseline; height: 100%;">' + param.name + '</span></div>'),
			$value = $('<div style="display: inline-block; width: 40px;"><span style="vertical-align: baseline; height: 100%;">' + initial + '</span></div>');
		$wrapper
			.append($label)
			.append($ui)
			.append($value);
		$main.append($wrapper);
		
		var setValue = function(event, ui) {
			$value.html(ui.value);
			io.emit('change', {"name": param.name, "value": ui.value});
		}
		$ui.slider({
			min: min,
			max: max,
			value: initial,
			step: (max - min) / 256.0,
			start: setValue,
			slide: setValue,
			change: setValue,
			stop: setValue
		});
		$label.height($ui.height());
	}

	function createButton(param, $main) {

	}

	function createTextBox(param, $main) {

	}

	function createTextArea(param, $main) {

	}

	function createToggle(param, $main) {

	}

	function createRadioButtons(param, $main) {

	}

	function createSelectOption(param, $main) {

	}

	return (function(UI) {
		UI.addParts = {
			slider:   createSlider,
			button:   createButton,
			text:     createTextBox,
			longText: createTextArea,
			toggle:   createToggle,
			radio:    createRadioButtons,
			select:   createSelectOption
		};
		UI.create = function(parameters, $main) {
			for(var i = 0; i < parameters.length; i++) {
				UI.addParts[parameters[i].type](parameters[i], $main);
			}
		};
		return UI;
	})({io: io});
}