// Room: /u/w/wangs/a/yu27.c

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
  "west" : __DIR__"yu26",
  "east" : __DIR__"yu28",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
