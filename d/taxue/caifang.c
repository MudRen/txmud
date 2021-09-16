// caifang.c
// by dicky

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short","��");
        set("long",@LONG
������̤ѩɽׯ�Ĳ񷿣����￴��ȥҪ�ȱ��˵Ĳ񷿸ɾ����ˣ�����
����̤ѩɽׯ�ĵ��Ӿ����������æ��Ե�ʡ����������һ�Ѳ񣬲��º�
����ʲô������
LONG);

	set("exits",([
                "east" : __DIR__"shilu2",
	]));
	set("book_count",1);
	set("chai_moved",1);
	setup();
}

void init()
{
	add_action("do_move","move");
	add_action("do_pull","pull");
	add_action("do_pi","pi");
}

int do_move(string arg)
{
	object ob=this_player();
	object where=environment(ob);
	if (arg!="chai") return 0;
	if (!where->query("chai_moved"))
                return notify_fail("���Ѿ����ƿ��ˡ�\n");
	set("chai_moved",0);
        return notify_fail("�����ƿ���,������һ�����塣\n");
}

int do_pull(string arg)
{
	object ob,me=this_player();
	object where;
        where=environment(me);
	if (arg!="tieban") return 0;
	if( where->query("chai_moved") )
                return notify_fail("����Χû���ⶫ����\n");
        if((int)me->query_str()<22)
        	return notify_fail("������̫С,û���������塣\n");
        message_vision("$Nʹ�����̵���������������������\n",me);
        if (!(where->query("book_count")))
              return notify_fail("����ʲô��û�С�\n");
        ob=new(__DIR__"obj/sword-book");
        ob->move(me);
        message_vision(HIG"$N������һ���飡\n"NOR,me);
        where->set("book_count",0);
        return 1;
}

int do_pi(string arg)
{
	object me = this_player();

	if (arg != "chai" && arg != "mutou")
		return notify_fail("��Ҫ��ʲô��\n");

	if (!present("sword", me))
		return notify_fail("��������������������ѽ��\n");

	if (me->is_busy() || me->is_fighting())
		return notify_fail("����æ���ģ�\n");

	if ((int)me->query_skill("sword", 1) > 31)
		return notify_fail("���ý�����ľ�񣬵����Ѿ��޷������Ļ��������ˡ�\n");

        if ( (int)me->query("kee")<20) 
	{
		me->receive_damage("kee", 10);
		write("��̫���ˣ��Ѿ��޷��������еĳ�����\n");              
        return 1;
	}

        me->receive_damage("kee", random(20));
        message_vision("$N�����������Ų�\n", me);  
        write("��Ŭ�������Ų�������Ĺ�������Ļ��������ֽ���һ����\n");
		me->improve_skill("sword", me->query("int"));       
	return 1;
}	
