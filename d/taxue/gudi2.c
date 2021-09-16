// gudi.c
// by dicky

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short","ɽ�ȵ�");
        set("long",@LONG
�������ͱ�����Ĺȵף���������ϡ�١����ܿ���ȥ�߲����ʣ���ʯ
��ᾡ�һ����Ȫ(quan)�����Ĵ��ͱڵķ�϶����������������"���˶���"
����������ֻ����(houzi)��ɽ��������Ծ��ż��ͣ������һ�߳���ɽ����
һ�����´��������ⲻ��֮�͡�
LONG);

	set("outdoors","taxue");

	set("item_desc", ([
		"quan" : "һ���Ȫ��Ө͸�������̲�ס��ȥ��(he)���ڡ�\n",
		"houzi" : "��ֻɽ����һ�߳���Ұ����һ�ߴ��������ⲻ��֮�͡�\n",
	]));

	set("exits",([
                "west" : __DIR__"gudi",
                "enter" : __DIR__"gudi3",
	]));

	setup();
}

void init()
{
	if (!this_player()->query_temp("taxue/gudi_za"))
	        this_player()->set_temp("taxue/gudi_za",1);

	add_action("do_he", "he");
	add_action("do_za", "za");
}

int do_he(string arg)
{
	object me = this_player();

	if (arg == "quan") {
		if (me->query("water") < me->query("str")*10+100) {
		message_vision(HIC"$N����һ����Ȫ�������غ���һ�ڡ�\n"NOR, me);
		me->add("water", 50, me);
		return 1;
		}
	return notify_fail("���̫���ˣ����³�����\n");  
	} 
      return notify_fail("��Ҫ��ʲô��\n");
}

int do_za(string arg)
{
	object me = this_player();

	if (present("ye guo", me))
		return notify_fail("�����ϲ�����Ұ��ô����ȥƭ���ӵĶ�����ѽ��\n"); 

	if (arg == "houzi"){
	message_vision(HIC"$N������ϵ�ʯ�飬�����������ҹ�ȥ��\n\n"NOR, me);
	message_vision(HIC"�������϶�$N���������죬�������ϵ�" HIR "Ұ��" HIC "��$P�ҹ�����\n$Pһʽ��������·����˳�ְ����������С�\n\n"NOR,me);
	me->add_temp("taxue/gudi_za",1);
	new(__DIR__"obj/yeguo")->move(me);
	return 1;
	} 
	return notify_fail("��Ҫ��˭��\n");
}