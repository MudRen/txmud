// Room: /u/w/wangs/a/yu81.c

inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
�����ڳ�����ֻ���������ߣ���������������紵��ľ��
�������󣬿����������ɹ�Ȼ������
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "southwest" : __DIR__"yu82",
  "east" : __DIR__"yu80",
]));
        set("objects", ([
        __DIR__"npc/zhouguyan": 1,
                        ]) );

	setup();
	replace_program(ROOM);
}
