// Room: /u/w/wangs/a/yu29.c

inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
�������������ϣ������������ߣ�һ�ɸ������󡣱���
��ɽС��Ӧ�о��У��Ե�ʮ����������������ͨ�����ϱ�һ
�����ң���֪��ʲô���ڡ�
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"yu30",
  "west" : __DIR__"yu28",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
