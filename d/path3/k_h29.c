// Room: /d/path3/k_h29.c

inherit ROOM;

void create()
{
	set("short", "����·");
	set("long", @LONG
����һ������·�����ϵ����ֺͱ����ı����Բ�ͬ�����и�
¶��һ����������������ʪ��·�Ϻ����г��������治Զ����
�����Ķɿ��ˡ�
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"k_h30",
  "north" : __DIR__"k_h28",
]));
	set("no_clean_up", 0);
	set("outdoors", "path3");
	setup();
	replace_program(ROOM);
}
