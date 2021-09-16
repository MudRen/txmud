// yxiao.c

#include <ansi.h>
inherit ITEM;

void create()
{
        set_name(HIW"������"NOR, ({ "white flute","flute" }) );
        set_weight(200);
        if( clonep() )
	set_default_object(__FILE__);
	else
	{
                set("unit", "��");
		set("long", "��������������ֱ����ĸо��������ϵȺ����Ƴɵġ�
��������Ŵ�(chui)�����ӡ�\n");
		set("value", 1);
        }
}

void init()
{
	add_action("do_chui",({ "chui","��" }));
}

int do_chui(string arg)
{
        object me = this_player(),ob;

        if ( !arg || (!id(arg) && (arg != "������")) )
		return notify_fail("��Ҫ��ʲô��\n");

	if (me->query("sen") < 60)
		return notify_fail("�㾫�񲻺ã�Ъһ���ٴ��ɡ�\n");

	if(me->query_temp("mark/louth_xiao") < 8 )
        {
		message_vision("$N���������������ʹ���Ĵ��˴����������߰���Ĳ��ɸ�������\n\n",me);
		me->receive_damage("sen",60,"tire");
		return 1;
        }

	if(objectp(ob=present("xiao pu",me)) && ob->is_feiyu_xiaopu())
	{
        	message_vision(WHT"$N�����������ڴ�������Ĵ�����������һ������ܲ�ġ���
������Ȼ���ˣ��������Լ��������ˣ���$N��������������
Զ���������ֿɼ�ȴ���޷�������ץס����$N��˼��������
�ˣ�����Ҳ���ˡ�����\n\n"NOR,me);

		me->receive_damage("sen",60,"tire");   
		call_out("greeting",10,me);
		me->start_busy(20);
	}

	else
	{
		message_vision("$N����������������봵һ������ܲ�ġ����������Ǵ����á�\n\n",me);
		me->receive_damage("sen",60,"tire");
	}

        return 1;
}

void greeting(object me)
{
	object ob,pu;

	if(!me || !environment(me))
		return;

        message_vision (HIM"\n����������ͣ�ˣ����Ӿ������˸е����£������������Լ�
���������ͺ�������$N������������һ���ᣬ����Ľ���Ʈ
����Ҳ����ˡ�����\n\n"NOR,me);

	if( objectp(ob = present("huan er",environment(me)))
	&& ob->query_is_feiyu_huaner()
	&& objectp(pu=present("xiao pu",me))
	&& pu->is_feiyu_xiaopu() )
	{
		message_vision("$N������$n˵����лл���ˣ��Һþ�û������ô�����������ˡ�
���׺����Ҿ��������ˣ��Ժ�������������Ҵ������ڶ���ʶ
�ַ��滹�¹����칦���Ժ������ⷽ�������������ҡ�\n",ob,me);
		this_object()->move(ob);
		pu->move(ob);
		ob->start_call();
		me->set("mark/louth_huaner",1);
	}
        me->stop_busy();
}
