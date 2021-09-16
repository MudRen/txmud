// feature/flag_ob.c
// create by Find.
// This is for objects that from wizards is been marked "wiz_lable".

static int wiz_flag=0;

nomask int query_wiz_flag() {return wiz_flag;}

nomask void set_flag(int flag)
{
	object *inv;
	int i;

	if(userp(this_object()))
		return;
	if(!intp(flag))
		return;
	if(flag != 1)
		return;
	wiz_flag = flag;

	inv = all_inventory(this_object());
	if(sizeof(inv))
		for(i=0;i<sizeof(inv);i++)
		{
			inv[i]->set_flag(1);
		}
}
