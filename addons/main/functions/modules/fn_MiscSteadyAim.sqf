private _coef = getCustomAimCoef player;
if (_coef > 0) then {
	player setCustomAimCoef 0;
	player setVariable ["ESE_Main_var_CustomAimCoef", _coef];
} else {
	private _oldCoef = player getVariable ["ESE_Main_var_CustomAimCoef", 1];
	player setCustomAimCoef _oldCoef;
};