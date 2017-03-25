function toggleById(id, refobj) {
	var obj = document.getElementById(id);
	if (obj.style.display == 'none')
	{
		refobj.innerHTML='[-]';
		obj.style.display = 'block';
	}
	else if (obj.style.display == 'block')
	{
		refobj.innerHTML='[+]';
		obj.style.display = 'none';
	}		
}
