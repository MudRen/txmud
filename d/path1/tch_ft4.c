// Room: /d/path1/tch_ft4.c

inherit ROOM;

void create()
{
	set("short", "�������");
	set("long", @LONG
����һ��������·��·�ı�����һ������ɽ����������ƬƬ
�����֡�����������㲻���е��������⡣һ��С·�������Ѷ�
ȥͨ��һƬ���֡�
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 3 */
  "south" : __DIR__"lu_cross5",
  "northeast" : __DIR__"tch_ft5",
  "northwest" : __DIR__"tch_ft3",
]));
	set("outdoors", "path1");
	setup();
	replace_program(ROOM);
}
