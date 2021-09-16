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
		return notify_fail("你只能穿戴可当作护具的东西。\n");

#ifdef WIZARD_FLAG
	if(this_object()->query_wiz_flag() && userp(owner) && !wizardp(owner))
		return notify_fail(this_object()->name()+"是巫师物品，你不能穿戴。\n");
#endif

	type = query("armor_type");
	if( owner->query_temp("armor/" + type) )
		return notify_fail("你已经穿戴了同类型的护具了。\n");

	if( type == "shield"
	&& weapon = owner->query_temp("weapon") ) /*盾是要用一只手来拿的. by Find.*/
	{
		if(weapon->query("flag") & TWO_HANDED) /*拿了一件双手兵器*/
			return notify_fail("你必须空出一只手来才能装备"+this_object()->name()+"。\n");
		if(owner->query_temp("secondary_weapon"))
			return notify_fail("你必须空出一只手来才能装备"+this_object()->name()+"。\n");
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
		return notify_fail(this_object()->query("name")+"已经不能用了。\n");

	if(!this_object()->is_weapon())
		return notify_fail("你只能装备可当作武器的东西。\n");
	// Check if we have "weapon_prop" defined.
	if( !mapp(weapon_prop = query("weapon_prop")) )
		return notify_fail("你只能装备可当作武器的东西。\n");

#ifdef WIZARD_FLAG
	if(this_object()->query_wiz_flag() && userp(owner) && !wizardp(owner))
		return notify_fail(this_object()->name()+"是巫师物品，你不能装备。\n");
#endif

	flag = query("flag");

	if(left) /* 指定将兵器装备于左手。*/
	{
		if(!(flag & SECONDARY))
			return 0;
		if(owner->query_temp("secondary_weapon"))
			return 0;
		owner->set_temp("secondary_weapon", this_object());
	}

	else if( flag & TWO_HANDED )
	/* 双手兵器，必须空出双手才能装备。shield 是要用一只手拿的，
	   wear() 部分作相应的修改。但拿 shield 就要牺牲一个兵器，
	   shield 要到什么程度才合算呢？这牵涉到 combatd 里的关于
	   apply/armor 的算法。Mudlib 原只有 secondary_weapon 的概念，
	   无论从武功、攻防、招法等各方面均无实际的意义，要加上真是
	   工程浩大。
	*/
	{
		if( owner->query_temp("weapon")
		|| owner->query_temp("secondary_weapon")
		|| owner->query_temp("armor/shield") )
			return notify_fail("你必须空出双手才能装备双手武器。\n");
		owner->set_temp("weapon", this_object());
	}

	else
	{
		// If we are are using any weapon?
		if( !(old_weapon = owner->query_temp("weapon")) )
		{
			if( owner->query_temp("secondary_weapon")
			&& owner->query_temp("armor/shield") )
				return notify_fail("你必须空出一只手来使用武器。\n");
			else
				owner->set_temp("weapon", this_object());
		}

		// If we still have a free hand?
		else if( !owner->query_temp("secondary_weapon")
			&& !owner->query_temp("armor/shield") )
		{

			// If we can wield this as secondary weapon?
			if(flag & SECONDARY
			/* add by Find. 同时原兵器还不能是双手兵器.*/
			&& !(old_weapon->query("flag") & TWO_HANDED) )
				owner->set_temp("secondary_weapon", this_object());

			// If we can switch our old weapon to secondary weapon ?
			/* 能否把右手兵器换到左手去？*/
			else if( (int)old_weapon->query("flag") & SECONDARY )
			{
				old_weapon->unequip();
				owner->set_temp("weapon", this_object());
				old_weapon->wield();
				message_vision("$N将右手的$n换到左手。\n", owner, old_weapon);
			}
			// We need unwield our old weapon before we can use this one.
			else
				return notify_fail("你必须先放下你目前装备的武器。\n");

		// We have both hands wearing something.
		}
		else
			return notify_fail("你必须空出一只手来使用武器。\n");
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
		return notify_fail("你目前并没有装备这样东西。\n");

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
