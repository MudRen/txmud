// Room: /u/w/wangs/a/yu5.c

inherit __DIR__"patroling";

void create()
{
	set("short", "����ǰԺ");
	set("long", @LONG
�����������ǰԺ���൱����Ժ�������˸��ֻ��ݣ�
��紵��������Ϯ�ˡ��������Ը���һ��С·����������ͨ
��Ժ��
LONG
	);
	set("exits", ([ /* sizeof() == 4 */
  "south" : __DIR__"yu21",
  "north" : __DIR__"yu2",
  "west" : __DIR__"yu15",
  "east" : __DIR__"yu6",
]));
        set("objects", ([
        __DIR__"npc/zong2": 1,
]) );

	set("outdoors","feiyu");
	setup();
}

int valid_leave(object me, string dir)
{
	object ob;

        if (dir =="south"
	&& (me->query("gender") == "����")
	&& !wizardp(me) )
        {
		if (objectp(ob = present("lv ling", this_object())) &&  living(ob))
			return notify_fail("��籺ȵ���վס�������ֹ���Խ��룡\n");
	}
	return ::valid_leave(me, dir);
}

