
inherit ROOM;

void create()
{
    set("short", "����");
	set("long", @LONG
������·�����֣�����������1�������ǲݳ�
��������������2��
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "east" : "/wiz/gaoqi/gaibang/caochang.c",
  "west" : "/wiz/gaoqi/gaibang/shulin2.c",
  "north" : "/wiz/gaoqi/gaibang/shulin2.c",
  "south" : "/wiz/gaoqi/gaibang/shulin2.c",
]));	setup();
}
