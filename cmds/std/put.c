// put.c
// Find.

#define MAX_INV_LEVEL	2

inherit F_CLEAN_UP;

int do_put(object me, object obj, object dest);
private int query_inv_level(object ob,int n);

int main(object me, string arg)
{
        string target, item;
        object obj, dest, *inv, obj2;
        int i, amount;

        if(!arg)
		return notify_fail("��Ҫ��ʲô�����Ž����\n");

        if( sscanf(arg, "%s in %s", item, target)!=2 )
                return notify_fail("��Ҫ��ʲô�����Ž����\n");

        dest = present(target, me);
        if( !dest || living(dest) ) dest = present(target, environment(me));
        if( !dest || living(dest) )
                return notify_fail("����û������������\n");

	if(!dest->is_container() || dest->is_corpse())
		return notify_fail(sprintf("%s������װ��Ʒ��������\n",dest->name()));

	if(sscanf(item, "%d %s", amount, item)==2)
	{
		if( !objectp(obj = present(item, me)) )
			return notify_fail("������û������������\n");
		if( obj->query("no_get"))
			return notify_fail("�ⶫ�����ܽ������ˡ�\n");
		if( !obj->query_amount() )
			return notify_fail( obj->name() + "���ܱ��ֿ���\n");
		if( amount < 1 )
			return notify_fail("����������������һ����\n");
		if( amount > obj->query_amount() )
			return notify_fail("��û����ô���" + obj->name() + "��\n");
		else if( amount == (int)obj->query_amount() )
			return do_put(me, obj, dest);
		else
		{
			obj2 = new(base_name(obj));
			obj2->set_amount(amount);
#ifdef WIZARD_FLAG
			if(obj->query_wiz_flag())
				obj2->set_flag(1);
#endif
			if(do_put(me, obj2, dest))
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

	if(item=="all")
	{
		inv = all_inventory(me);
		for(i=0; i<sizeof(inv); i++)
			if( inv[i] != dest )
				do_put(me, inv[i], dest);
		write("Ok.\n");
		return 1;
	}

	if(!objectp(obj = present(item, me)))
		return notify_fail("������û������������\n");
	return do_put(me, obj, dest);
}

// modify by find.
int do_put(object me, object obj, object dest)
{
        string pppp,unit;
	int flag = 0;
	int sum;

	if( obj->query("no_drop")
	|| obj->query("no_get")
	|| obj->query("no_put"))
		return notify_fail(sprintf("�㲻���Խ�%s�ŵ�%s���档\n",obj->name(),dest->name()));
	if( obj == dest)
		return notify_fail("�㲻������ô����\n");

	if(query_inv_level(obj,0) > MAX_INV_LEVEL)
		return notify_fail(sprintf("�㲻���Խ�%s�ŵ�%s���档\n",obj->name(),dest->name()));

	switch((string)dest->query("position"))
	{
		case "on" :
			pppp = "����" + dest->name() + "��";
			break;
		case "under" :
			pppp = "����" + dest->name() + "��";
			flag = 1;
			break;
		case "behind" :
			flag = 1;
			pppp = "����" + dest->name() + "����";
			break;
		case "insdie" :
			pppp = "�Ž�" + dest->name() + "����";
			flag = 1;
			break;
		default :
			pppp = "�Ž�" + dest->name() + "����";
			flag = 1;
			break;
	}

	if(flag) // for light_ob. by Find.
	{
		if( obj->is_light_ob() && obj->is_lighting())
			return notify_fail(obj->name()+"���ܷ��ڱ�Ķ������档\n");
	}

	unit = (sum=obj->query_amount())&&(sum==1)?obj->query("base_unit"):obj->query("unit");

	if( obj->move(dest) )
	{
		message_vision( sprintf("$N��һ%s%s%s��\n",
			unit,obj->name(), pppp), me );
		return 1;
	}
	else return 0;
}

private int query_inv_level(object ob,int n)
{
	int i,num;
	object *objs;

	if(!objectp(ob) || !ob->is_container())
		return n;
	if( n > MAX_INV_LEVEL )
		return n;

	objs = filter_array(all_inventory(ob),(: $1->is_container() :));
	if(!objs || !num=sizeof(objs))
		return n;
	n++;
	for(i=0;i<num;i++)
	{
		int nn;

		nn = query_inv_level(objs[i],n);
		n = nn > n?nn:n;
	}

	return n;
}

int help(object me)
{
write(@HELP
ָ���ʽ : put <��Ʒ����> in <ĳ����>
 
���ָ��������㽫ĳ����Ʒ�Ž�һ����������Ȼ��������Ҫӵ��������Ʒ��
 
HELP
    );
    return 1;
}

