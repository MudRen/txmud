// Room: /u/w/wangs/a/yu55.c

inherit ROOM;

void create()
{
	set("short", "÷�ָ�");
	set("long", @LONG
���ڵ����ʡ���������ƺ���黭��ȡ����÷����������
�粴���Ѷ������ǰ��ֲ�����֦÷���Է�������Ϊ���顢
�滭֮����
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "southwest" : __DIR__"yu54",
  "up" : __DIR__"yu56",
]));

	set("outdoors","feiyu");

	setup();
}
/*
int valid_leave(object me, string dir)
{
	if( dir =="up"
	&& !wizardp(me)
	&& ((me->query("combat_exp") < 1500000)
	|| (me->query("class") != "rain")) )
	{
		if(objectp(present("zhang suifeng", environment(me))))
			return notify_fail("��稱������㲻�ܽ���÷�ָ�\n");
	}
	return ::valid_leave(me, dir);
}
*/
