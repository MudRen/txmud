// Room: /u/w/wangs/a/yu26.c

inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
�������������ϣ������������ߣ�һ�ɸ������󡣱���
��ɽС��Ӧ�о��У��Ե�ʮ��������
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "northwest" : __DIR__"yu25",
  "east" : __DIR__"yu27",
]));
        set("objects", ([
        __DIR__"npc/qianhuimin": 1,
                        ]) );

	setup();
	replace_program(ROOM);
}
