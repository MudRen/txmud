// Room: /d/feiyu/miaopu9.c

inherit __DIR__"miaopu";

void create()
{
	set("short", "��ҩ����[9]");
	set("long", @LONG
����������������ҩ�����ԣ�����Ϊ���»���Ӱ�죬ÿһ
�����Զ���ľ�����������
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "east" : __DIR__"miaopu8",
  "north" : __DIR__"miaopu4",
]));

	set("outdoors","feiyu");
	setup();
}
