// dongxiangfang.c ���᷿
// by dicky

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short","���᷿");
        set("long",@LONG
����Ҳ��̤ѩɽׯ���ʷ����ڣ�����ÿ��Ǯ�Ƴ������Ŀ�������
����������һЩ��ɫ�Ĺ��ӣ���֪����Щʲô��������table���϶���С
ɽһ�����ʲ����ܼ�̤ѩ��������æµ��д��ʲô�� ̤ѩɽׯ�ĵ��ӿ�
���������쵽��ͬ��нˮ������
LONG	);

	set("exits",([
		"north" : __DIR__"dongting",
	]));
	set("item_desc", ([
		"table" : "�������ҵĶ����ʲ�(zhang bu)��\n",
	]));
		
	set("book_count",1);

	setup();
}
void init()
{
	add_action("do_move","move");
}

int do_move(string arg)
{
	object ob;
	object me= this_player();
	object where=environment(me);
	if (arg!="zhang bu" && arg!="bu") return 0;
	if (!where->query("book_count"))
		return notify_fail("�ʲ��Ѿ����˷������߰��㡣\n");
	ob = new(__DIR__"obj/unarmed-book");
	ob->move(where);
	message_vision("ֻ������ž����һ����һ�������������\n",me);
	set("book_count",0);
	return 1;
}