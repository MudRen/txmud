// Room: /wiz/louth/a/shanlu9.c

inherit ROOM;

void create()
{
	set("short", "ɽ·");
	set("long", @LONG
������һ�����ѵ�С����С���������ǰ���˸ߵ��Ӳݣ�
����Ը��ܵ�������΢������വ����
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "east" : __DIR__"yu1",
  "north" : __DIR__"shanlu8",
]));
        set("objects", ([ /* sizeof() == 4 */
  __DIR__"npc/hufa2" : 1,
]));
	setup();
}

int valid_leave(object me, string dir)
{
	object ob;

        if(dir =="east"
	&& (me->query("gender") == "����")
	&& !wizardp(me) )
        {
		if(objectp(ob = present("zhang piaoxue", this_object())) && living(ob))
                return notify_fail("��Ʈѩ���һ����վס�������ֹ���Խ��룡\n");
        }
	return ::valid_leave(me, dir);
}

