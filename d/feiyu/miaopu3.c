// Room: /d/feiyu/miaopu3.c

inherit __DIR__"miaopu";

void create()
{
	set("short", "��ҩ����[3]");
	set("long", @LONG
����������������ҩ�����ԣ�����Ϊ���»���Ӱ�죬ÿһ
�����Զ���ľ�����������
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"miaopu4",
  "east" : __DIR__"miaopu2",
]));

	set("outdoors","feiyu");
	setup();
}
