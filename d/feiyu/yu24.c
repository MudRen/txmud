// Room: /u/w/wangs/a/yu24.c

inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
�������������ϣ������������ߣ�һ�ɸ������󡣱���
��ɽС��Ӧ�о��У��Ե�ʮ��������
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
  "southeast" : __DIR__"yu25",
  "northwest" : __DIR__"yu23",
]));
        set("objects", ([ /* sizeof() == 4 */
  __DIR__"npc/wuhuixun" : 1,
]));

	setup();
	replace_program(ROOM);
}
