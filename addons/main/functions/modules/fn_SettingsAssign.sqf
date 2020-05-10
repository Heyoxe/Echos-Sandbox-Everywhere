private _keys = actionKeysNames "User13";
private _second = if !(_keys isEqualTo "") then {
	format ["To open the menu use <t color='#57A0F2'>%1</t><br/>", _keys];
} else {
	""
};
hint parseText format ["<t size='2'>Hi <t color='#57A0F2'>%1</t></t><br/><t align='left'><t size='1.2'>Thank you for downloading <t color='#57A0F2'>ESE</t>!</t><br/>%2<br/>You can change the key in '<t color='#57A0F2'>Options > Controls > Custom Controls > User Action 13</t>'", profileName, _second];