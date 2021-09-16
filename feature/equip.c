// equip.c
// Modified by Find.

#include <dbase.h>
#include <weapon.h>
#include <mangle.h>

int wear()
{
	object owner,weapon;
	mapping armor_prop, applied_prop;
	string *apply, type;

	// Only character object can wear armors.
	if( !objectp(owner = environment()) || !owner->is_character() ) return 0;

	// If already worn, just recognize it.
	if( query("equipped") ) return 1;

	// Check if we have "armor_prop" defined.
	if( !mapp(armor_prop = query("armor_prop")) )
		return notify_fail("��ֻ�ܴ����ɵ������ߵĶ�����\n");

#ifdef WIZARD_FLAG
	if(this_object()->query_wiz_flag() && userp(owner) && !wizardp(owner))
		return notify_fail(this_object()->name()+"����ʦ��Ʒ���㲻�ܴ�����\n");
#endif

	type = query("armor_type");
	if( owner->query_temp("armor/" + type) )
		return notify_fail("���Ѿ�������ͬ���͵Ļ����ˡ�\n");

	if( type == "shield"
	&& weapon = owner->query_temp("weapon") ) /*����Ҫ��һֻ�����õ�. by Find.*/
	{
		if(weapon->query("flag") & TWO_HANDED) /*����һ��˫�ֱ���*/
			return notify_fail("�����ճ�һֻ��������װ��"+this_object()->name()+"��\n");
		if(owner->query_temp("secondary_weapon"))
			return notify_fail("�����ճ�һֻ��������װ��"+this_object()->name()+"��\n");
	}

	owner->set_temp("armor/" + type, this_object());
	apply = keys(armor_prop);
	applied_prop = owner->query_temp("apply");
	if( !mapp(applied_prop) ) applied_prop = ([]);
	for(int i = 0; i<sizeof(apply); i++)
		if( undefinedp(applied_prop[apply[i]]) )
			applied_prop[apply[i]] = armor_prop[apply[i]];
		else
			applied_prop[apply[i]] += armor_prop[apply[i]];
	owner->set_temp("apply", applied_prop);
	set("equipped", "worn");
	return 1;
}

int wield(int left)
{
	object owner, old_weapon;
	mapping weapon_prop;
	string *apply;
	int flag;

	// Only character object can wear armors.
	if( !objectp(owner = environment()) || !owner->is_character() ) return 0;

	// If already wielded, just recognize it.
	if( query("equipped") ) return 1;

	if( ((int)this_object()->query("weapon_mangle")) >= W_MAX_MANGLE)
		return notify_fail(this_object()->query("name")+"�Ѿ��������ˡ�\n");

	if(!this_object()->is_weapon())
		return notify_fail("��ֻ��װ���ɵ��������Ķ�����\n");
	// Check if we have "weapon_prop" defined.
	if( !mapp(weapon_prop = query("weapon_prop")) )
		return notify_fail("��ֻ��װ���ɵ��������Ķ�����\n");

#ifdef WIZARD_FLAG
	if(this_object()->query_wiz_flag() && userp(owner) && !wizardp(owner))
		return notify_fail(this_object()->name()+"����ʦ��Ʒ���㲻��װ����\n");
#endif

	flag = query("flag");

	if(left) /* ָ��������װ�������֡�*/
	{
		if(!(flag & SECONDARY))
			return 0;
		if(owner->query_temp("secondary_weapon"))
			return 0;
		owner->set_temp("secondary_weapon", this_object());
	}

	else if( flag & TWO_HANDED )
	/* ˫�ֱ���������ճ�˫�ֲ���װ����shield ��Ҫ��һֻ���õģ�
	   wear() ��������Ӧ���޸ġ����� shield ��Ҫ����һ��������
	   shield Ҫ��ʲô�̶Ȳź����أ���ǣ�浽 combatd ��Ĺ���
	   apply/armor ���㷨��Mudlib ԭֻ�� secondary_weapon �ĸ��
	   ���۴��书���������з��ȸ��������ʵ�ʵ����壬Ҫ��������
	   ���̺ƴ�
	*/
	{
		if( owner->query_temp("weapon")
		|| owner->query_temp("secondary_weapon")
		|| owner->query_temp("armor/shield") )
			return notify_fail("�����ճ�˫�ֲ���װ��˫��������\n");
		owner->set_temp("weapon", this_object());
	}

	else
	{
		// If we are are using any weapon?
		if( !(old_weapon = owner->query_temp("weapon")) )
		{
			if( owner->query_temp("secondary_weapon")
			&& owner->query_temp("armor/shield") )
				return notify_fail("�����ճ�һֻ����ʹ��������\n");
			else
				owner->set_temp("weapon", this_object());
		}

		// If we still have a free hand?
		else if( !owner->query_temp("secondary_weapon")
			&& !owner->query_temp("armor/shield") )
		{

			// If we can wield this as secondary weapon?
			if(flag & SECONDARY
			/* add by Find. ͬʱԭ������������˫�ֱ���.*/
			&& !(old_weapon->query("flag") & TWO_HANDED) )
				owner->set_temp("secondary_weapon", this_object());

			// If we can switch our old weapon to secondary weapon ?
			/* �ܷ�����ֱ�����������ȥ��*/
			else if( (int)old_weapon->query("flag") & SECONDARY )
			{
				old_weapon->unequip();
				owner->set_temp("weapon", this_object());
				old_weapon->wield();
				message_vision("$N�����ֵ�$n�������֡�\n", owner, old_weapon);
			}
			// We need unwield our old weapon before we can use this one.
			else
				return notify_fail("������ȷ�����Ŀǰװ����������\n");

		// We have both hands wearing something.
		}
		else
			return notify_fail("�����ճ�һֻ����ʹ��������\n");
	}

	apply = keys(weapon_prop);
	for(int i = 0; i<sizeof(apply); i++)
		owner->add_temp("apply/" + apply[i], weapon_prop[apply[i]]);

	owner->reset_action();
	set("equipped", "wielded");
	return 1;
}

int unequip()
{
	object owner;
	mapping prop, applied_prop;
	string *apply, equipped;

	if( !objectp(owner = environment()) || !owner->is_character() ) return 0;

	if( !stringp(equipped = query("equipped")) )
		return notify_fail("��Ŀǰ��û��װ������������\n");

	if( equipped=="wielded" ) {
		if( (object)owner->query_temp("weapon") == this_object() )
			owner->delete_temp("weapon");
		else if( (object)owner->query_temp("secondary_weapon") == this_object() )
			owner->delete_temp("secondary_weapon");
		prop = query("weapon_prop");
		owner->reset_action();
	} else if( equipped=="worn" ) {
		owner->delete_temp("armor/" + query("armor_type") );
		prop = query("armor_prop");
	}

	apply = keys(prop);
	applied_prop = owner->query_temp("apply");
	for(int i = 0; i<sizeof(apply); i++)
		// To support array apply, we cannot add_temp() here.
		applied_prop[apply[i]] -= prop[apply[i]];

	delete("equipped");
	return 1;
}
