// liquid.c
// Modified by Find.

#include <dbase.h>
#include <name.h>

protected nosave int decay_lasting = 35;

protected void set_decay_lasting(int n)
{
	if( (n > 0) && (n < decay_lasting) )
		return;

	decay_lasting = n;
}

nomask int is_liquid() { return 1; }

void init()
{
	if(environment() == this_player())
	{
		add_action("do_drink", "drink");
		add_action("do_fill", "fill");
		if( (decay_lasting > 0) && query("liquid/remaining") )
		{
			remove_call_out("decay");
			call_out("decay",decay_lasting);
		}
	}
}

protected void decay()
{
        if( query("liquid/remaining") )
        {
                add("liquid/remaining", -1);
                if( !query("liquid/remaining") )
                        message_vision( "$N���" + query("liquid/name") + "�����������ˡ�\n",this_object());
                else call_out("decay",decay_lasting);
        }

}

string extra_long()
{
        int amount, max;
        string str;

        if( amount = query("liquid/remaining") ) {
                max = query("max_liquid");
                if( amount == max )
                        str = "����װ����" + query("liquid/name") + "��\n";
                else if( amount > max/2 )
                    str = "����װ���ߡ��˷�����" + query("liquid/name") +"��\n";
                else if( amount >= max/3 )
                    str = "����װ���塢��������" + query("liquid/name") +"��\n";
                else if( amount > max/4 )
                    str = "����װ�������" + query("liquid/name") + "��\n";
                return str;
        }
        else return 0;
}

int do_drink(string arg)
{
	int apply;
	object me = this_player();
	string cnd;

        if( !arg || !this_object()->id(arg) ) return 0;
        if( me->is_busy() )
                return notify_fail(BUSY_MESSAGE);
        if( !query("liquid/remaining") )
                return notify_fail( name() + (query("liquid/name") ? 
			"�Ѿ����ȵ�һ��Ҳ��ʣ�ˡ�\n":"�ǿյġ�\n"));
        if((int)me->query("water") >= (int)me->max_water_capacity())
                return notify_fail("���Ѿ���̫���ˣ���Ҳ�಻��һ��ˮ�ˡ�\n");

        add("liquid/remaining", -1);

        message_vision("$N����" + name() + "������غ��˼���" +query("liquid/name")
                        + "��\n", me);

	apply = this_object()->query("liquid/drunk_apply");
	if(!apply)
		apply = 10;
	me->add("water", apply);

        if( me->is_fighting() ) me->start_busy(1);

        if( !query("liquid/remaining") )
                write("���Ѿ���"+name()+"���"+query("liquid/name")+"�ȵ�һ��Ҳ��ʣ�ˡ�\n");

	// �ж��Ĵ���
	if( stringp(cnd = query("liquid/apply_condition")) )
		me->apply_condition(cnd, query("liquid/condition_count"));
        return 1;
}

int do_fill(string arg)
{
	int time;
	object me = this_player(), env;
	string cnd;

        if( !arg || !this_object()->id(arg) )
		return 0;

	if( me->is_busy() )
		return notify_fail(BUSY_MESSAGE);

	if( !(env = environment(me)) || !env->query("resource/water") )
                return notify_fail("����û�еط�����װˮ��\n");

        if( query("liquid/remaining") )
                message_vision("$N��" + name() + "��ʣ�µ�" + 
                        query("liquid/name") + "������\n", me);
        message_vision("$N��" + name() + "װ����ˮ��\n", me);

        if( me->is_fighting() )
		me->start_busy(2);

	delete("liquid/apply_condition");
        set("liquid/name", "��ˮ");
        set("liquid/remaining", query("max_liquid"));

	// �¶�
	if(stringp(cnd = env->query("resource/condition")))
	{
		int cnt;
		time = env->query("resource/time");
		if( (time < 0) || (time() > time) )	// �Ƿ��ʱ��
		{
			set("liquid/apply_condition", cnd);
			cnt = env->query("resource/count");
			if(cnt < 3)
				cnt = 3;
			set("liquid/condition_count", cnt);
		}
		else
			env->delete("resource/condition");
	}

	remove_call_out("decay");
	if(decay_lasting > 0)
		call_out("decay",decay_lasting);

	return 1;
}

void stop_decay()
{
	if(find_call_out("decay"))
		remove_call_out("decay");
}
