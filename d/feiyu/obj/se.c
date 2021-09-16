// se.c

#include <ansi.h>
inherit ITEM;

private int xian = 3;
private int have = 0;

string get_long_desc();

void create()
{
	set_name("����", ({ "gu qin","qin"}) );
	set_weight(3000);
	if( clonep() )
		set_default_object(__FILE__);
        else
	{
		set("no_get", 1);
		set("unit", "��");
		set("long", (: get_long_desc :));
		set("value", 1);
	}
}

string get_long_desc()
{
	return sprintf("��ѹ��ٱ����ε������������ϡ�\n%s",
		xian?sprintf("���Ϸ���%s�����ҡ�\n",chinese_number(xian)):"");
}
/*
void init()
{
	add_action("do_play","play");
	add_action("do_shang","shang");
}
*/
int do_shang(string arg)
{
	object me = this_player();

	if (arg != "����" && arg !="qin xian")
		return notify_fail("��Ҫ��ʲô��\n");

	if(have)
		return notify_fail("�����Ѿ��Ϻ��ˡ�\n");

	if(!xian)
		return notify_fail("�����ϵ����Ҷ����������ˡ�\n");

	if(me->query_temp("louth_playqin"))
		return notify_fail("�㶼�Ѿ����Ϲ�һ�������ˣ������˷��ˡ�\n");

	message_vision("$N���������ϵ����ң���ϸ���ϵ������ϡ�\n",me);
	have = 1;
        xian--;
        return 1;
}

int do_play(string arg)
{
        object me = this_player();

	if( !id(arg) && (arg != "����") )
		return notify_fail("��Ҫ��ʲô��\n");

	if(!have)
		return notify_fail("�������벦Ū��Ū���٣��ŷ�������û�����ҡ�\n");

        message_vision(HIM"$N�������̲��һ�׹ŴӾ��У�������Ϻ��������ڡ�\n"NOR,me);
	me->start_busy(7);
	call_out("qin1",6,me);
	return 1;
}

void qin1(object me)
{
	if(!objectp(me) || (environment(me) != this_object()))
		return;

	tell_object(me,HIB"ʱ��������ת���������ս�������ĳ��档\n\n");
        call_out("qin2",4,me);
}

void qin2(object me)
{
	if(!objectp(me) || (environment(me) != this_object()))
		return;

	tell_object(me,HIB"ʱ���������������˺������졣\n\n"NOR);
        call_out("qin3",4,me);
}

void qin3(object me)
{
        object ob;

	if(!objectp(me) || (environment(me) != this_object()))
		return;

        tell_object(me,HIR"
ͻȻ����һת���ʮ�ֵİ�Թ����·𿴼�ս����ʬ��
��Ұ���������˺�������Ѱ���Լ������ˣ�����ĺ���
��ʲô����һ�£������ָһ����ֻ����һ�����ġ���
һ�����Ҷ��ˣ�����Ϊһͣ��Ҳ�ջ������ҵ�˼������
������һ˿��Ī�����˸С�\n\n\n"NOR);

	have = 0;
	me->set_temp("louth_playqin",1);
	me->stop_busy();

        ob = new("../npc/yman");
        ob->move(environment());
}
