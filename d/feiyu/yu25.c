// Room: /u/w/wangs/a/yu25.c

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
  "southeast" : __DIR__"yu26",
  "northwest" : __DIR__"yu24",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
