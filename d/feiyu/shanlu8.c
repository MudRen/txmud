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
  "west" : __DIR__"shanlu6",
  "south" : __DIR__"shanlu9",
]));
        set("objects", ([ /* sizeof() == 4 */
  __DIR__"npc/hufa3" : 1,
]));
        setup();
}

int valid_leave(object me, string dir)
{
	object ob;

        if(dir =="south"
	&& (me->query("gender") == "����")
	&& !wizardp(me) )
        {
		if(objectp(ob = present("zhang kuyu", this_object())) && living(ob))
                return notify_fail("�ſ�����һ����վס�������ֹ���Խ��룡\n");
        }
	return ::valid_leave(me, dir);
}
