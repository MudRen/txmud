// caodi4.c

#include <ansi.h>

inherit ROOM;

void create()
{
	set("short", "Ժ�ſ�");
	set("long", @LONG
��ǰ��һƬƧ����СԺ�����ܾ����ĵ�û��һ�㶯����Ժ��
��Χǽ�����ߣ�Ժ�Źص�����ʵʵ�ģ�������һ�������õ�ͭ����
�ű���һ��ľ��(pai)������Ŀ������û��һ˿��Ϣ��
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"caodi3",
]));

        set("item_desc", ([ 
                "ľ��" : HIR"
                        ��
                        ��
                        �
                        ��
                        ��
                        ��
                        ��
                        ��
                      ������\n"NOR,
                "pai" : HIR"
                        ��
                        ��
                        �
                        ��
                        ��
                        ��
                        ��
                        ��
                      ������\n"NOR,
        "door" : "һ�Ƚ����Ĺ��ŵ�Сľ�ţ����������ȥ��(knock)һ�¡�\n",
        "ľ��" : "һ�Ƚ����Ĺ��ŵ�Сľ�ţ����������ȥ��(knock)һ�¡�\n",
]));
        set("outdoors","feiyu");
	setup();
}
void init()
{
        add_action("do_knock","knock");
        add_action("do_push","push");
        add_action("do_break","break");
}

int do_knock(string arg)
{
        object me = this_player();

	if(arg != "door" && arg != "ľ��")
		return notify_fail("��Ҫ��ʲô��\n");

	message_vision("$N��Сľ������������˼��¡�����\n\n",me);
        me->set_temp("mark/louth_knock",1);
        call_out("greeting",8,me);
        return 1;
}

int do_push(string arg)
{
        object me = this_player();

	if(arg != "door" && arg != "ľ��")
		return notify_fail("��Ҫ��ʲô��\n");

	if(!me->query_temp("mark/louth_knock"))
		return notify_fail("��ʹ��������Сľ�ţ�����û���ƶ���\n");

	message_vision("$N�����ƿ���Сľ�š�\n",me);
	set("exits/enter",__DIR__"caodi5");
	me->delete_temp("mark/louth_knock");
	return 1;
}

int do_break(string arg)
{
	object me = this_player();

	if(arg != "door" && arg != "ľ��")
		return notify_fail("�����ʲô��\n");

	message_vision(HIB"$N���һ�������˫����Сľ����ȥ��\n"NOR,me);
	message_vision("Ժ�����Ȼ����һ��ٻӰ������$N��Ц������\n",me);
	write("������һ������ֹ�ô������������\n");
	write(HIR"��Ȼ����һ�����������\n"NOR);
	me-> unconcious();
        return 1;
}

void greeting(object me)
{
	if(!objectp(me) || (environment(me) != this_object()))
		return;

	tell_object(me,"Ժ�����и�����˵���������ɡ�\n");
}
