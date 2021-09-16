// /feature/self.c
// by Find.

// ������Ʒ��

#include <self.h>

protected class weapon_args *my_load_weapon;

protected void refresh_my_load_weapon();
protected void load_my_weapons();

void refresh_all_my_ob()
{
	if(!userp(this_object()) || !environment())
		return;

	refresh_my_load_weapon();
}

void load_all_my_ob()
{
	if(!previous_object()
	|| (geteuid(previous_object()) != ROOT_UID) )
		return;

	load_my_weapons();
}

protected void refresh_my_load_weapon()
{
	object *inv;

	my_load_weapon = ({});

	if(!sizeof(inv = filter_array(all_inventory(this_object()),
		(: $1->is_self_make_weapon() :))) )
		return;

	foreach(object tmp in inv)
	{
		class weapon_args one;
		object ob;

		if(!sscanf(file_name(tmp), SELF_DIR"%*s"))
			continue;

		one = new(class weapon_args);
		one->fname = base_name(tmp);
		one->name = tmp->query("name");
		one->id = tmp->query("id");
		one->desc = tmp->query("long");
		one->wield_msg = tmp->query("wield_msg");
		one->unwield_msg = tmp->query("unwield_msg");
		one->damage = tmp->query("weapon_prop/damage");
		one->mangle = tmp->query("weapon_mangle");
		one->material = tmp->query("material");
		if(objectp(ob = query_shadowed()))
			one->weapon_effect = base_name(ob);
		my_load_weapon += ({ one });
	}
}

protected void load_my_weapons()
{
	if(!arrayp(my_load_weapon) || !sizeof(my_load_weapon))
		return;

	foreach(class weapon_args tmp in my_load_weapon)
	{
		object ob;

		if(!objectp(ob = new(tmp->fname, tmp)))
			continue;

		if(!ob->move(this_object()))
		{
			log_file("self_load", sprintf("[%s]:\n%O\n", this_object()->query("id"),tmp));
			tell_object(this_object(), sprintf("���[%s]�޷�װ�룬��ʧ�ˡ�\n", ob->name()));
			destruct(ob);
		}
	}

	my_load_weapon = 0;
}
