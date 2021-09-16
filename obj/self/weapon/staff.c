// staff.c
// ������Ʒ (by Find.)
// û�а�ȫ���⵫̫�鷳

#include <mine_def.h>
#include <weapon.h>
#include <self.h>
#include <origin.h>

inherit STAFF;

protected int weapon_attr_flag, require_res;

string query_selling_msg() { return "�������"; }

int query_weapon_attr() { return weapon_attr_flag; }
int set_weapon_attr(int n)
{
	object pob = previous_object();

	if(n < 0)
		return 0;

	if(pob && (file_name(pob) == "/cmds/wiz/call"))
	{
		log_file("set_self",sprintf("(%s) CALL %s(%s) SET_WEAPON_ATTR %n\n",
			geteuid(pob), name(), query("id"), n));
		weapon_attr_flag = n;
		return 1;
	}

	if( ( pob
	&& ( pob->query_wiz_flag()
	|| sscanf(file_name(pob),WIZ_DIR"%*s") ) )
	|| (this_player(1) && wizardp(this_player(1))) )
		return 0;

	weapon_attr_flag = n;
	return 1;
}
int is_self_object() { return 1; }
int is_self_make_weapon() { return 1; }
int query_require_res()
{
	string tmp;

	if( !(tmp = query("material")) || (tmp != BLACK_IRON) )
		return require_res;
	else
		return require_res*10;
}
int set_require_res(int n) { require_res = n; }

void set_weapon_weight()
{
	set_weight(WEAPON_D->query_self_weapon_weight(this_object()));
}

void set_weapon_value()
{
	set("value", WEAPON_D->query_self_weapon_value(this_object()));
}

nomask mixed set(string prop, mixed data)
{
	object pob = previous_object();

	if( origin() == ORIGIN_LOCAL )
		return ::set(prop, data);

	if(pob && (file_name(pob) == "/cmds/wiz/call"))
	{
		log_file("set_self",sprintf("(%s) CALL %s(%s) SET %s : %O\n",
			geteuid(pob), name(), query("id"), prop, data));
		return ::set(prop, data);
	}

	if( ( pob
	&& ( pob->query_wiz_flag()
	|| sscanf(file_name(pob),WIZ_DIR"%*s") ) )
	|| (this_player(1) && wizardp(this_player(1))) )
		return 0;

	return ::set(prop, data);
}

protected void create(class weapon_args arg)
{
	set("unit", "��");
	if( clonep() )
		set_default_object(__FILE__);

	if(arg && classp(arg))
	{
		object ob;

		set_name(arg->name, ({ arg->id }) );
		set("long", arg->desc);
		set("wield_msg", arg->wield_msg);
		set("unwield_msg", arg->unwield_msg);
		set("weapon_mangle", arg->mangle);
		set("material", arg->material);
		weapon_attr_flag = arg->weapon_flag;
		init_staff(arg->damage);
		set_weapon_weight();
		set_weapon_value();
		if(arg->weapon_effect
		&& (file_size(arg->weapon_effect+".c") > 0)
		&& objectp(ob = new(arg->weapon_effect)) )
			shadow(ob);
	}

	else
	{
		set_name("ľ��", ({ "staff" }) );
		set_weight(5000);
		set("long", "����һ�ѿ����൱��ͨ��ľ��");
		set("value", 500);
		set("material", "wood");
		set("wield_msg", "$N��$n�������������С�\n");
		set("unwield_msg", "$N�ɿ������е�$n��\n");
		init_staff(25);
	}

	setup();
}

class weapon_args query_save_args()
{
	class weapon_args tmp;

	tmp = new(class weapon_args);

	tmp->fname = base_name(this_object());
	tmp->name = query("name");
	tmp->id = query("id");
	tmp->desc = query("long");
	tmp->wield_msg = query("wield_msg");
	tmp->unwield_msg = query("unwield_msg");
	tmp->damage = query("weapon_prop/damage");
	tmp->mangle = query("weapon_mangle");
	tmp->material = query("material");
	tmp->weapon_flag = weapon_attr_flag;

	return tmp;
}