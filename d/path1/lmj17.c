// Room: /d/path1/lmj17.c

inherit ROOM;

void create()
{
	set("short", "ɽ·");
	set("long", @LONG
����һ��ɽ�ߵ�С�������򱱾͵��˻���ɽ�¡�һֻͺӥ��
��ͷ���ɹ��������ﲻ��ӿ��һ˿������
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 2 */
  "southdown" : __DIR__"lmj16",
  "northup" : __DIR__"py2",
]));
	set("outdoors", "path1");
	setup();
	replace_program(ROOM);
}
