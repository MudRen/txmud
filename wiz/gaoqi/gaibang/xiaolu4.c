
inherit ROOM;

void create()
{
    set("short", "�ҵĹ�����");
	set("long", @LONG
����һ���շ��䡣
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "west" : "/d/xueting/inn",
]));	setup();
}
