// Room: /wiz/louth/a/caodi3.c

inherit ROOM;

void create()
{
	set("short", "�ݵ�");
	set("long", @LONG
����һƬ����Ĳݵأ�ϡ��ĳ��ż���С����ż����������
С������У�ʹ�˸��ܵ�һ�־��׵����ա�
LONG
);
	set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"caodi2",
  "north" : __DIR__"caodi4",
]));
        set("objects", ([ /* sizeof() == 4 */
  __DIR__"npc/hufa1" : 1,
]));
	set("outdoors","feiyu");
	setup();
}

int valid_leave(object me, string dir)
{
	if(dir =="north" && me->query("class") != "rain" )
        {
                if(objectp(present("zhang suifeng", environment(me))) && !wizardp(me))
			return notify_fail("�����������ﲻ����Ӧ��ȥ�ĵط���\n");
	}
	return ::valid_leave(me, dir);
}
