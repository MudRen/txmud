// Room: /d/path3/k_h30.c

inherit ROOM;

void create()
{
	set("short", "����·");
	set("long", @LONG
���ߵ����ֻ��������ľ�Եø������£��·�ոս��ܹ�
��ˮ��ϴ�񡣵��ϵĻ���Ҳ����ʮ�ֽ��ޣ����ϵķ羰��ȷ����
��ͬ��
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"k_h31",
  "north" : __DIR__"k_h29",
]));
	set("no_clean_up", 0);
	set("outdoors", "path3");
	setup();
	replace_program(ROOM);
}
