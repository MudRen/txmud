// Room: /d/path1/tch_ft3.c

inherit ROOM;

void create()
{
	set("short", "�������");
	set("long", @LONG
����һ�����������·�ı�����һ������ɽ����������ƬƬ
�����֡�����������㲻���е��������⡣
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"tch_ft2",
  "southeast" : __DIR__"tch_ft4",
]));
	set("outdoors", "path1");
	setup();
	replace_program(ROOM);
}
