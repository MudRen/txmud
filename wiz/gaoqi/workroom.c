
inherit ROOM;

void create()
{
    set("short", "�ҵĹ�����");
	set("long", @LONG
����һ���շ��䡣
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
"down" : "/wiz/gaoqi/gaibang/caochang",
]));	setup();
}
