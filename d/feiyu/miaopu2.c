// Room: /d/feiyu/miaopu2.c

inherit __DIR__"miaopu";

void create()
{
	set("short", "��ҩ����[2]");
	set("long", @LONG
����������������ҩ�����ԣ�����Ϊ���»���Ӱ�죬ÿһ
�����Զ���ľ�����������
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
  "west" : __DIR__"miaopu3",
  "south" : __DIR__"miaopu5",
  "east" : __DIR__"miaopu1",
  "north" : __DIR__"yu96",
]));

	set("outdoors","feiyu");
	setup();
}
