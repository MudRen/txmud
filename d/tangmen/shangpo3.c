// Room: /d/tangmen/shangpo3.c

inherit ROOM;

void create()
{
	set("short", "��ɽС·");
	set("long", @LONG
����һ�����͵���ɽС·�����Զ��Ǵ��̵ľ�����������ϡ
�ɵĻ�����Сʯ�ӣ�һ��С��׼ˤ������
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "northup" : __DIR__"shangpo4",
  "southdown" : __DIR__"shangpo2",
]));

	set("outdoors", "tangmen");
	setup();
}

int valid_leave(object me, string dir)
{
	int sk;

	if(!userp(me) || (dir != "northup"))
		return ::valid_leave(me, dir);

	sk = me->query_skill("dodge", 1);

	if(random(40) > sk)
	{
		me->receive_damage("kee", 25, "trip");
		return notify_fail("��һ��������ˤ�˸���������\n");
	}

	return ::valid_leave(me, dir);
}
