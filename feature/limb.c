// limbs.c
// for user limbs
// by Find.

protected nosave string *human_limbs = ({
"ͷ��",	"����",	"�ؿ�",	"����",	"���",	"�Ҽ�",	"���",
"�ұ�",	"����",	"����",	"����",	"С��",	"����",	"����",
"���",	"�ҽ�",
});

protected mapping current_damage = ([]);

// ��λ����
int receive_limbs_wound(string limb, int damage)
{
	if(!stringp(limb)
	|| (member_array(limb,human_limbs) == -1)
	|| !intp(damage)
	|| (damage <= 0))
		return 0;

	if(!current_damage)
		current_damage = ([]);

	if(undefinedp(current_damage[limb]))
		current_damage += ([ limb : damage ]);
	else
		current_damage[limb] += damage;
	return 1;
}

int receive_limb_curing(string limb, int heal)
{
	if(!current_damage)
		current_damage = ([]);

	if(!stringp(limb)
	|| (member_array(limb,human_limbs) == -1)
	|| !intp(heal)
	|| (heal <= 0)
	|| undefinedp(current_damage[limb]) )
		return 0;

	if(current_damage[limb] <= heal)
	{
		map_delete(current_damage, limb);
		tell_object(this_object(),sprintf("\n��%s�ϵ��˿������������ˡ�\n\n",limb));
	}
	else
		current_damage[limb] -= heal;
}

int query_limb_wound(string limb)
{
	if(!current_damage)
		current_damage = ([]);

	if(!stringp(limb)
	|| (member_array(limb,human_limbs) == -1)
	|| undefinedp(current_damage[limb]) )
		return 0;

	return current_damage[limb];
}

// ��������
void update_all_limb_damage()
{
	string *ls;

	if(!sizeof(current_damage))
		return 0;

	ls = keys(current_damage);

	foreach(string l in ls)
	{
		if((--current_damage[l]) <= 0)
		{
			map_delete(current_damage, l);
			tell_object(this_object(),sprintf("\n��%s�ϵ��˿������������ˡ�\n\n",l));
		}
	}
}
