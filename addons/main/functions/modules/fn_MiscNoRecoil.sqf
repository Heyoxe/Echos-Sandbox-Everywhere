private _coef = unitRecoilCoefficient player;
if (_coef > 0) then {
	player setUnitRecoilCoefficient 0;
	player setVariable ["ESE_Main_var_UnitRecoilCoefficient", _coef];
} else {
	private _oldCoef = player getVariable ["ESE_Main_var_UnitRecoilCoefficient", 1];
	player setUnitRecoilCoefficient _oldCoef;
};