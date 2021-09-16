// give.c
// Modified by Find.

inherit F_CLEAN_UP;

int do_give(object me, object obj, object who);

int main(object me, string arg)
{
	string target, item;
	object obj, who, *inv, obj2;
	int i, amount;

	if(!arg) return notify_fail("��Ҫ��˭ʲô������\n");

	if( sscanf(arg, "%s to %s", item, target)==2
	|| sscanf(arg, "%s %s", target, item)==2 );
	else return notify_fail("��Ҫ��˭ʲô������\n");

	if(!objectp(who = present(target, environment(me))) || !living(who))
		return notify_fail("����û������ˡ�\n");
        if( who->query("env/no_accept") && userp(me) )
                return notify_fail(who->name()+"���ڲ�������κ��˵Ķ�����\n");

        if(item=="all")
	{
		int flag;
                inv = all_inventory(me);
                for(i=0; i<sizeof(inv); i++)
		{
			if(do_give(me, inv[i], who))
				flag++;
                }
		if(!flag)
			return notify_fail("������û��ʲô���Ը��˵Ķ�����\n");
		if(me->is_fighting())
			me->start_busy(flag>1?2:1);
                write("Ok.\n");
                return 1;
        }


	if(sscanf(item, "%d %s", amount, item)==2) {
		if( !objectp(obj = present(item, me)) )	
			return notify_fail("������û������������\n");
		if( obj->query("no_drop") && (!wizardp(me)) )
			return notify_fail("�����������������ˡ�\n");
		if( !obj->query_amount() )	
			return notify_fail( obj->name() + "���ܱ��ֿ����ˡ�\n");
		if( amount < 1 )
			return notify_fail("����������������һ����\n");
		if( amount > obj->query_amount() ) 
			return notify_fail("��û����ô���" + obj->name() + "��\n");
#ifdef WIZARD_FLAG
		if(obj->query_wiz_flag() && userp(who) && !wizardp(who))
			return notify_fail("��ʦ��Ʒ���ܽ������ʹ�á�\n");
#endif
		else if( amount == (int)obj->query_amount() )
			return do_give(me, obj, who);
		else {
			obj2 = new(base_name(obj));
			obj2->set_amount(amount);
#ifdef WIZARD_FLAG
			if(obj->query_wiz_flag())
				obj2->set_flag(1);
#endif
                        if(do_give(me, obj2, who))
			{
                                obj->set_amount( (int)obj->query_amount() - amount );
				if(me->is_fighting())
					me->start_busy(1);
                                return 1;
			}
                        else
			{
				destruct(obj2);
				return 0;
			}
		}
	}

	if(!objectp(obj = present(item, me)))
		return notify_fail("������û������������\n");
	if(do_give(me, obj, who))
	{
		if(me->is_fighting())
			me->start_busy(1);
		return 1;
	}
	else
		return 0;
}

int do_give(object me, object obj, object who)
{
        mixed no_give;
	object *obs;

        if(who == me)   return notify_fail("��������Լ��Ķ������ø��ˡ�\n");

        if( no_give = obj->query("no_give") )
                return notify_fail( stringp(no_give) ? no_give : "�����������������ˡ�\n");

        else if( obj->query("no_drop") )
                return notify_fail("�����������������ˡ�\n");

	if(obj->is_container())
	{
		obs = filter_array(deep_inventory(obj),(: $1->query("no_give") || $1->query("no_drop") :));
		if(sizeof(obs))
			return notify_fail("�����������������ˡ�\n");
	}

#ifdef WIZARD_FLAG
	if(obj->query_wiz_flag() && userp(who) && !wizardp(who))
		return notify_fail("��ʦ��Ʒ���ܽ������ʹ�á�\n");
#endif

	notify_fail(sprintf("�������Է�������������%s��%s��\n",
		who->query("gender")=="Ů��"?"��":"��",obj->name())); // by Find.
	if( !userp(who) && !who->accept_object(me, obj) )
		return 0;

	if( !userp(who) && obj->value() ) {
		message_vision("$N�ó�" + obj->short() + "��$n��\n", me, who);
		destruct(obj);
		return 1;
	} else if( obj->move(who) ) {
		printf("���%sһ%s%s��\n", who->name(), obj->query("unit"),
			obj->name());
		message("vision", sprintf("%s����һ%s%s��\n", me->name(),
			obj->query("unit"), obj->name()), who );
		message("vision", sprintf("%s��%sһ%s%s��\n", me->name(), who->name(),
			obj->query("unit"), obj->name()), environment(me), ({me, who}) );
		me->save();
		return 1;
	}
	else return 0;
}
int help(object me)
{
write(@HELP
ָ���ʽ : give <��Ʒ����> to <ĳ��>
      �� : give <ĳ��> <��Ʒ����>
 
���ָ��������㽫ĳ����Ʒ������, ��Ȼ, ������Ҫӵ��������Ʒ.
 
HELP
    );
    return 1;
}
