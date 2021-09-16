// xiaopu.c

#include <ansi.h>

inherit ITEM;

int is_feiyu_xiaopu() { return 1; }

void create()
{
        set_name(HIM"��ܲ������"NOR, ({ "xiao pu","pu" }) );
        set_weight(200);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "����һ���ܾɵ����ף�����ķ��źܹ֣���
���Ӻ��ѿ�(kan)����\n");
        }
}

void init()
{
        add_action("do_du","kan");
}

int do_du(string arg)
{
        object me = this_player();

	if (!arg || (!id(arg) && (arg != "��ܲ������") && (arg != "����")) )
		return notify_fail("��Ҫ��ʲô��\n");

	if (me->query("sen") < 25 )
		return notify_fail("��̫���ˣ�������Ϣһ�°ɡ�\n");

	if (me->query_temp("mark/louth_xiao") > 8)
		return notify_fail("����Ȿ�����Ѿ����ĺ����ˣ������Ͽ촵��һ����\n");

	message_vision("$N��ʼ������ܲ�����ס���������\n\n\n",me);
	me->start_busy(10);
	call_out("greeting",8,me);
	return 1;
}

void greeting(object me)
{
	if(!me)
		return;

	message_vision("$N����һ�����ף���������������һ�����˽⡣\n",me);
        me->receive_damage("sen",25,"tire");
	me->add_temp("mark/louth_xiao",1);
	me->stop_busy();
}       
