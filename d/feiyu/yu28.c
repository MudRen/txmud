// Room: /u/w/wangs/a/yu28.c

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
  "west" : __DIR__"yu27",
  "east" : __DIR__"yu29",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
