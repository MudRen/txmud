// Room: /d/path1/tch_ft5.c

inherit ROOM;

void create()
{
	set("short", "ɽ·");
	set("long", @LONG
����һ��ɽ�Դ�·��·�ı�����һ������ɽ����������ƬƬ
�����֡�����������㲻���е��������⡣
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 2 */
  "southwest" : __DIR__"tch_ft4",
  "northeast" : __DIR__"tch_ft6",
]));
	set("outdoors", "path1");
	setup();
	replace_program(ROOM);
}
